#ifndef PLAYER_HPP
#define PLAYER_HPP

#include<iostream>
#include <vector>
#include<string>
#include <fstream>
using namespace std;

class Player
{

        
        public:
                std::string level;
                std::string name;
                std::vector<std::string> words;
                int score;
                //Member functions

                Player();//Parameter Construtor

                void setName(std::string n);
                std::string getName(); 

                void setScore(int s);
                int getScore();
};

#endif