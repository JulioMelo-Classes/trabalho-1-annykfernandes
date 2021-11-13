#include<iostream>
#include "../include/File.hpp"
#include "../include/Player.hpp"
#include "../include/Forca.hpp"
using namespace std;

int main(int argc, char *argv[]){
  
  std::string name = "fulaninho de tal";
  
  //criando objeto do jogador e objetos dos arquivos
  Player player;
  File f_scores;
  File f_words;

  //atribuindo os parametros passados no mais para uma variavel string que sera usada como paths
  std::string pathWordsFile = argv[1];
  std::string pathScoreFile = argv[2];
  //carregando os arquivos e os transformando cada um em um vector de strings
  std::vector s_file_words = f_words.loadFile(pathWordsFile);
  std::vector s_file_scores = f_scores.loadFile(pathScoreFile);
  //validando os arquivos 
  std::cout<<">>> Lendo arquivo de palavras ["<<pathWordsFile<<"] e scores ["<<pathScoreFile<<"], por favor aguarde.."<<std::endl;
  
  bool fwords_is_valid = f_words.validateWordsFile(s_file_words);
  bool fscores_is_valid = f_words.validateWordsFile(s_file_scores);

  if(fwords_is_valid || fscores_is_valid)
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

  while(loop)
  {
    std::cout<<"Por favor, escolha uma das opções abaixo: "<<std::endl;
    std::cout<<"1 -> Iniciar Jogo"<<std::endl;
    std::cout<<"2 -> Ver scores anteriores"<<std::endl;
    std::cout<<"3 -> Sair do jogo"<<std::endl;
    std::cout<<"Sua escolha: ";
    int cmd;
    std::cin>>cmd;

    bool start = cmd == 1;
    bool scores = cmd == 2;
    bool exit = cmd == 3;

    if(scores)
    {
      f_scores.getScores();
    }
    else if(start)
    {
      std::cout << "Vamos iniciar o jogo!\nPor favor, escolha o nível de dificuldade: "<<std::endl;
      std::cout<<"1 -> Fácil"<<std::endl;
      std::cout<<"2 -> Médio"<<std::endl;
      std::cout<<"3 -> Difícil"<<std::endl;
      std::cout<<"Sua escolha: ";
      int d;
      std::cin >> d;
      Forca forca;
      forca.setLevel(d);

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

  return 0;
}
