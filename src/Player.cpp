#include "../include/Player.hpp"

std::string level;
std::string name;
std::vector<std::string> words;
int score;


Player::Player() 
{   
    level = "Fácil";
    name = "fulaninho";
    words.push_back("");
    score = 0;
}
void Player::setName(std::string n)
{
    name = n;
}
std::string Player::getName()
{   
    std::cout<<name<<std::endl;
    return name;
} 

void Player::setScore(int s)
{
    score = s;
}
int Player::getScore()
{
    return score;
}
