#include "../include/Forca.hpp"
 
enum Level{
    EASY, MEDIUM, HARD
};

map<char, bool> chutou;

char chute;

int indx;

std::vector< std::pair<std::string, int> > pairs; 

Level lvl; 

std::string palavra_atual; 

int tentativas_restantes; 

bool n_ganhou = true;

bool n_enforcou = true;

bool n_desistiu = true;

std::vector< std::pair<std::string, int> > pairs_easy;

std::vector< std::pair<std::string, int> > pairs_medium;

std::vector< std::pair<std::string, int> > pairs_hard;

std::vector< std::pair<std::string, int> > game_on_words;


Forca::Forca(std::vector< std::pair<std::string, int> > p)
{
    index_pair = 0;
    n_ganhou = true;
    n_enforcou = true;
    n_desistiu = true;
    tentativas_restantes = 6;
    pairs = p;
}


void Forca::setLevel(int d)
{
    if(d == 1)
    {
        lvl = Level::EASY;
        std::cout<<"Escolheu fácil izi pizi lemon squizi, bora lá!"<<std::endl;
    }
    else if(d == 2)
    {
        lvl = Level::MEDIUM;
        std::cout<<"Escolheu medio, bora lá!"<<std::endl;
    }
    else if(d == 3)
    {
        lvl = Level::HARD;
        std::cout<<"Eita, escolheu dificil, bora lá!"<<std::endl;
    }

    for(int i = 1; i < pairs.size(); i++)
    {
        if(pairs[i].second > 20000)
        {
            pairs_easy.push_back(pairs[i]);
            // std::cout<<"gerou pares de faceis"<<std::endl;
        }
        else if (pairs[i].second > 15000)
        {
            pairs_medium.push_back(pairs[i]);
            // std::cout<<"gerou pares de medios"<<std::endl;
        }
        else
        {
            pairs_hard.push_back(pairs[i]);
            // std::cout<<"gerou pares de dificeis"<<std::endl;
        }
    }

    if(lvl == Level::EASY)
    {
        game_on_words = pairs_easy;
        std::cout<<"ok, pares faceis preparados"<<std::endl;
    }
    else if(lvl == Level::MEDIUM)
    {
        game_on_words = pairs_medium;
        std::cout<<"ok, pares medios preparados"<<std::endl;
    }
    else if(lvl == Level::HARD)
    {
        game_on_words = pairs_hard;
        std::cout<<"ok, pares dificeis preparados"<<std::endl;
    }
}

void Forca::shuffle_words()
{
    auto rng = std::default_random_engine {};
    std::shuffle(std::begin(game_on_words), std::end(game_on_words), rng);
}


void Forca::status_palavra()
{   
    for(char chute : palavra_atual)
    {
      if(chutou[chute])
      {
        cout << chute << " ";
      }
      else
      {
        cout << "_ ";
      }
    }
}


void Forca::reset_status_palavra()
{
    chutou.clear();
}


void Forca::set_chute(char c)
{
    chute = c;
}


void Forca::set_palavra_atual(std::string s_pa)
{
    palavra_atual = s_pa;
}


bool Forca::verifica_palavra()
{
    for(int i = 0; i<palavra_atual.size(); i++)
    {
        if( chute == palavra_atual[i])
        {
            cout<<"Você acertou! :D"<<endl;
            chutou[chute] = true;
            return true;
        }
    }
    return false;
}


std::string Forca::get_palavra_atual(int index)
{   
    indx = index;
    std::string p_a = game_on_words[indx].first;
    return p_a;
}


void Forca::update_tentativas()
{   
    tentativas_restantes--;
    std::cout<<"atualizando tentativas, agora restam: "<<tentativas_restantes<<std::endl;
}


int Forca::status_tentativas()
{
    return tentativas_restantes;
}


void Forca::reset_tentativas()
{
    tentativas_restantes = 6;
}


int Forca::get_tentativas_restantes()
{   
    tentativas_restantes--;
    return tentativas_restantes;
}

bool Forca::nao_ganhou()
{   
    for(char i : palavra_atual)
    {
      if(!chutou[i])
      { 
        return true;
      }
    }
    std::cout<<"Parabéns, palavra decifrada!"<<std::endl;
    std::cout<<"   ___________"<<std::endl;    
    std::cout<<"  '._==_==_=_.'"<<std::endl;     
    std::cout<<"  .-\\:      /-. "<<std::endl;   
    std::cout<<" | (|:.     |) | "<<std::endl;   
    std::cout<<"  '-|:.     |-'   "<<std::endl;  
    std::cout<<"    \\::.    /      "<<std::endl;
    std::cout<<"     '::. .'        "<<std::endl;
    std::cout<<"       ) (          "<<std::endl;
    std::cout<<"     _.' '._        "<<std::endl;
    std::cout<<"    '-------'"<<std::endl;

    return false;
}

bool Forca::update_n_ganou()
{
    n_ganhou = true;
    return true;
}

bool Forca::nao_enforcou()
{
    if(tentativas_restantes == 0)
    {
        n_enforcou = false;
    }
    else
    {
        n_enforcou = true;
    }
    return n_enforcou;

}

bool Forca::update_n_enforcou()
{   
    tentativas_restantes = 6;
    n_enforcou = true;
    return true;
}

bool Forca::nao_desistiu()
{   
    int quit;
    std::cout << "Deseja encerrar o jogo?: "<<std::endl;
    std::cout<<"1 -> Sim"<<std::endl;
    std::cout<<"2 -> Não"<<std::endl;
    std::cin>>quit;
    if(quit ==1)
    {
        n_desistiu = false;
    }

    return n_desistiu;
}

bool Forca::update_n_desistiu()
{
    n_desistiu = true;
    return true;
}

void Forca::verify_n_draw(int s_t)
{
    if( s_t == 6 && n_ganhou == true)
    {  
        cout<<"  _______"<<endl;
        cout<<" |/      |" <<endl;     
        cout<<" |      " <<endl;     
        cout<<" |" <<endl;     
        cout<<" |" <<endl;     
        cout<<" |" <<endl;     
        cout<<" |" <<endl;     
        cout<<" |" <<endl;     
        cout<<"_|__________ \n" <<endl;  

        n_enforcou = true;
    }
    if( s_t == 5 && n_ganhou == true)
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
        n_enforcou = true;
    }
    else if( s_t == 4 && n_ganhou == true)
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
        n_enforcou = true; 
    }
    else if( s_t == 3 && n_ganhou == true)
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
        n_enforcou = true;
    }
    else if( s_t == 2 && n_ganhou == true)
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
        n_enforcou = true;
    }
    else if( s_t == 1 && n_ganhou == true)
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
        n_enforcou = true;
    }
    if( s_t == 0 && n_ganhou == true)
    {      
    std::cout<<"Game over! Você foi enforcadx!"<<std::endl;
    std::cout<<"    _______________"<<std::endl;  
    std::cout<<"   /               \\     "<<std::endl;  
    std::cout<<"  /                 \\    "<<std::endl;  
    std::cout<<"//                   \\/\\ "<<std::endl; 
    std::cout<<"\\|   XXXX     XXXX   | / "<<std::endl;  
    std::cout<<" |   XXXX     XXXX   |/  "<<std::endl;   
    std::cout<<" |   XXX       XXX   |   "<<std::endl;   
    std::cout<<" |                   |   "<<std::endl;   
    std::cout<<" \\__      XXX      __/   "<<std::endl;  
    std::cout<<"   |\\     XXX     /|     "<<std::endl;  
    std::cout<<"   | |           | |     "<<std::endl;   
    std::cout<<"   | I I I I I I I |     "<<std::endl;   
    std::cout<<"   |  I I I I I I  |     "<<std::endl;   
    std::cout<<"   \\_             _/     "<<std::endl;  
    std::cout<<"     \\_         _/       "<<std::endl;  
    std::cout<<"       \\_______/"<<std::endl;
    n_enforcou = false;
    }
}
