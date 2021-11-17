#include<iostream>
#include "../include/File.hpp"
#include "../include/Player.hpp"
#include "../include/Forca.hpp"
using namespace std;

int main(int argc, char *argv[]){
  
  //criando objeto do jogador e objetos dos arquivos
  File f_scores;
  File f_words;

  //atribuindo os parametros passados no mais para uma variavel string que sera usada como paths
  std::string pathWordsFile = argv[1];
  std::string pathScoreFile = argv[2];
  //carregando os arquivos e os transformando cada um em um vector de strings
  std::vector<std::string> s_file_words = f_words.loadFile(pathWordsFile);
  std::vector<std::string> s_file_scores = f_scores.loadFile(pathScoreFile);
  //validando os arquivos 
  std::cout<<">>> Lendo arquivo de palavras ["<<pathWordsFile<<"] e scores ["<<pathScoreFile<<"], por favor aguarde.."<<std::endl;
  
  bool fscores_is_valid = f_scores.validateScoresFile(s_file_scores);
  bool fwords_is_valid= f_words.validateWordsFile(s_file_words);

  if(fwords_is_valid && fscores_is_valid)
  {
    std::cout<<"--------------------------------------------------------------------"<<std::endl;
    std::cout<<">>> Arquivos OK!"<<std::endl;
    std::cout<<"--------------------------------------------------------------------"<<std::endl;
    std::cout<<"Bem-vindx ao Jogo da Forca!"<<endl;
  }
  else
  {
    std::cout<<">>> Arquivos inválidos!"<<std::endl;
    return 0;
  }

  bool loop = true;

  Player player;

  std::cout<<"Por favor, registre eu nome aqui: ";
  std::string name;
  std::cin>>name;

  player.setName(name);

  int player_score= 0;

  std::vector<std::string> player_words = {""};

  while(loop == true)
  {
    std::cout<<"Por favor, escolha uma das opções abaixo: "<<std::endl;
    std::cout<<"1 -> Iniciar Jogo"<<std::endl;
    std::cout<<"2 -> Ver scores anteriores"<<std::endl;
    std::cout<<"3 -> Sair do jogo"<<std::endl;
    std::cout<<"Sua escolha: ";
    int cmd;
    std::cin>>cmd;

    bool start = cmd == 1;
    bool old_scores = cmd == 2;
    bool exit = cmd == 3;

    if(old_scores)
    {
      f_scores.getScores();
    }
    else if(start)
    {
      std::vector< std::pair<std::string, int> > palavras = f_words.generate_pairs(s_file_words);

      Forca forca(palavras);

      std::cout<< "Vamos iniciar o jogo!\nPor favor, escolha o nível de dificuldade: "<<std::endl;
      std::cout<<"1 -> Fácil"<<std::endl;
      std::cout<<"2 -> Médio"<<std::endl;
      std::cout<<"3 -> Difícil"<<std::endl;
      std::cout<<"Sua escolha: ";
      int d;
      std::cin >> d;
      forca.setLevel(d);
      player.setLevel(d);

      bool nao_ganhou = true;
      bool nao_enforcou = true;
      bool nao_desistiu = true;

      int indx = 1;

      std::string palavra_atual = forca.get_palavra_atual(indx);
      forca.set_palavra_atual(palavra_atual);
      while(nao_enforcou && nao_desistiu && nao_ganhou)
      { 
        int t = forca.status_tentativas();
        forca.verify_n_draw(t);

        nao_ganhou = forca.nao_ganhou();
        nao_enforcou = forca.nao_enforcou();

        if(nao_enforcou == false)
        { 
          std::cout<<indx<<std::endl;
          player.setScore(indx);
          player.setWords(player_words);
          break;
        }

        if(nao_ganhou == false)
        {
          player_words.push_back(palavra_atual);
          nao_desistiu = forca.nao_desistiu();

          if(nao_desistiu)
          {
            nao_ganhou = forca.update_n_ganou();
            nao_enforcou = forca.update_n_enforcou();
            nao_desistiu = forca.update_n_desistiu();
            int new_t = forca.status_tentativas();
            forca.verify_n_draw(new_t);
            indx++;
            std::string proxima_palavra = forca.get_palavra_atual(indx);
            palavra_atual = proxima_palavra;
            forca.set_palavra_atual(palavra_atual);
            std::cout<<"Vamos para a próxima palavra então!"<<std::endl;
          }
          else
          { 
            player.setScore(indx);
            player.setWords(player_words);
            loop == false;
            nao_desistiu==false;
            break;
          }
        }

        forca.status_palavra();
        char chute;
        std::cout<<"\nInsira seu chute: ";
        std::cin >> chute;
        forca.set_chute(chute);
        bool acerto = forca.verifica_palavra();
        if(acerto == false)
        {
          std::cout<<"Você errou! :("<<std::endl;
          forca.update_tentativas(); 
        }

      }
      
    }
    else if(exit)
    {
      std::cout << "Fim de jogo."<<std::endl;
      return 0;
    }
    else
    {
      std::cout << "Ops! Comando inválido..."<<std::endl;
    }
  }

  std::cout<<"Fim de jogo"<<std::endl;

  return 0;
}