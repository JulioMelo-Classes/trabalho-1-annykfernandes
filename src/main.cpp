#include <iostream>
#include <vector>
#include <string>

using namespace std;

using String = std::string;

bool verificaPalavra(char letra, string palavra)
{
  for(int i = 0; i<palavra.size(); i++)
  {
    if( letra == palavra[i])
    {
      return true;
    }
  }
  return false;
}


int geraNivel()
{
  int nivel;
  cout<<"SELECIONE UM NÍVEL:"<<endl;
  cout<<"Digite [1] para -> FÁCIL"<<endl;
  cout<<"Digite [2] para -> MÉDIO"<<endl;
  cout<<"Digite [3] para -> DIFÍCIL"<<endl;
//fazer virificação aqui da entrada
  cin >> nivel;
  return nivel;
}

string geraPalavra(int nivel)
{
  bool facil = nivel == 1;
  bool medio = nivel == 2;
  bool dificil = nivel == 3;
  string palavra;
  if(facil)
  {
    palavra = "LUFFY";
  }
  else if(medio)
  {
    palavra = "JINBE";
  }
  else if(dificil)
  {
    palavra = "SHIRAHOSHI";
  }
  cout<<palavra<<endl;
  return palavra;
}

int validaChuteErrado(int t)
{
  if(t==5)
  {
     cout<<"  _______"<<endl;
     cout<<" |/      |" <<endl;     
     cout<<" |      (_)" <<endl;     
     cout<<" |" <<endl;     
     cout<<" |" <<endl;     
     cout<<" |" <<endl;     
     cout<<" |" <<endl;     
     cout<<" |" <<endl;     
     cout<<"_|__________ \n" <<endl;  
  }
  if(t==4)
  {
     cout<<"  _______"<<endl;
     cout<<" |/      |" <<endl;     
     cout<<" |      (_)" <<endl;     
     cout<<" |       |" <<endl;     
     cout<<" |       |" <<endl;     
     cout<<" |" <<endl;     
     cout<<" |" <<endl;     
     cout<<" |" <<endl;     
     cout<<"_|__________ \n" <<endl;   
  }
  if(t==3)
  {
     cout<<"  _______"<<endl;
     cout<<" |/      |" <<endl;     
     cout<<" |      (_)" <<endl;     
     cout<<" |      /|" <<endl;     
     cout<<" |       |" <<endl;     
     cout<<" |" <<endl;     
     cout<<" |" <<endl;     
     cout<<" |" <<endl;     
     cout<<"_|__________ \n" <<endl;   
  }
  if(t==2)
  {
     cout<<"  _______"<<endl;
     cout<<" |/      |" <<endl;     
     cout<<" |      (_)" <<endl;     
     cout<<" |      /|\\" <<endl;     
     cout<<" |       |" <<endl;     
     cout<<" |" <<endl;     
     cout<<" |" <<endl;     
     cout<<" |" <<endl;     
     cout<<"_|__________ \n" <<endl;  
  }
  if(t==1)
  {
     cout<<"  _______"<<endl;
     cout<<" |/      |" <<endl;     
     cout<<" |      (_)" <<endl;     
     cout<<" |      /|\\" <<endl;     
     cout<<" |       |" <<endl;     
     cout<<" |      / "<<endl;     
     cout<<" |" <<endl;     
     cout<<" |" <<endl;     
     cout<<"_|__________ \n" <<endl;  
  }
  if(t==0)
  {
     cout<<"  _______"<<endl;
     cout<<" |/      |" <<endl;     
     cout<<" |      (_)" <<endl;     
     cout<<" |      /|\\" <<endl;     
     cout<<" |       |" <<endl;     
     cout<<" |      / \\"<<endl;     
     cout<<" |" <<endl;     
     cout<<" |" <<endl;     
     cout<<"_|__________ \n" <<endl;  
  }
  
  return 0;
}

int game(string palavra)
{ 
  
  int tentativa = 6;
  int score = 0;
  bool nao_ganhou = true;
  bool nao_enforcou = tentativa <= 6;

  while(nao_ganhou && nao_enforcou)
  {
    char hint;
    cin >> hint;
    bool acerto = verificaPalavra(hint, palavra);
    if(acerto)
    {
      score++;
      validaChuteCorreto(palavra, hint);
    }
    else
    {
      score--;
      tentativa--;
      validaChuteErrado(tentativa);
    }
    
  }
  return 0;
}




int main(){
  
  cout<<"------------------------------------"<<endl;
  cout<<"---- BEM-VINDX AO JOGO DA FORCA ----"<<endl;
  cout<<"------------------------------------"<<endl;
  

   cout<<"  _______"<<endl;
   cout<<" |/      |" <<endl;     
   cout<<" | " <<endl;     
   cout<<" |" <<endl;     
   cout<<" |" <<endl;     
   cout<<" |" <<endl;     
   cout<<" |" <<endl;     
   cout<<" |" <<endl;     
   cout<<"_|__________ \n" <<endl;     

  bool loop = true;

  while(loop == true)
  {
    cout<<"SELECIONE UMA OPÇÃO:"<<endl;
    cout<<"Digite [1] para -> INICIAR"<<endl;
    cout<<"Digite [2] para -> VER SCORES ANTERIORES"<<endl;
    cout<<"Digite [3] para -> SAIR DO JOGO"<<endl;

    int comando;
    cin >> comando;

    bool iniciar = comando == 1;
    bool scores = comando == 2;
    bool sair = comando == 3;

    if(scores)
    {
      cout << " ..." << endl;
      // puxa uma lista de scores e imprime
      //mostra menu
    }
    else if(iniciar)
    {
      cout << "-------------------------------"<<endl;
      cout << "------- Vamos começar! --------"<<endl;
      cout << "-------------------------------"<<endl;
      int nivel = geraNivel();
      string palavra = geraPalavra(nivel);
      game(palavra);
      //mostra menu
    }
    else if(sair)
    {
      cout << "Fim de jogo."<<endl;
      return 0;
    }
    else
    {
      cout << "Ops! Comando inválido.."<<endl;
    }
  }
    

    return 0;
}
