#include "../include/Player.hpp"

std::string level;
int lv;
std::string name;
std::vector<std::string> words;
int score = 0;


Player::Player() 
{   
    level = "Fácil";
    name = "fulaninho";
    words.push_back("");
    lv = 5;
}

void Player::setLevel(int l)
{   
    
    if(l == 1)
    {
        level = "Fácil";
         lv = 5;
    }
    else if(l = 2)
    {
        level = "Médio";
        lv = 10;
    }
    else if(l = 3)
    {
        level = "Difícil";
        lv = 20;
    }
}

void Player::setName(std::string n)
{
    name = n;
}

void Player::setScore()
{   
    score = (score * lv);
    cout<<"Score final: "<< score << endl;
}

void Player::setWords(std::vector<std::string> w)
{
    words = w;
    cout<<"Palavras que conseguiu: "<<endl;
    for(int i = 0; i < words.size(); i++)
    {
        cout<<words[i]<<endl;
    }
}

void Player::update_score(int point)
{
    if(point == 1)
    {
        score++;
    }
}
