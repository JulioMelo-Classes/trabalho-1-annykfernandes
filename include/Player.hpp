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

                int lv;

                std::string name;

                std::vector<std::string> words;

                int score = 1;

                Player();

                void setLevel(int l);

                std::string getName();

                void setName(std::string n);

                void setScore(int scr);

                void setWords(std::vector<std::string> w);
};

#endif