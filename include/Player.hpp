#ifndef PLAYER_HPP
#define PLAYER_HPP

#include<iostream>
#include <vector>
#include<string>
#include <fstream>
#include <algorithm>
#include <sstream>
#include <iterator>
using namespace std;

class Player
{       
        public:

                std::string level= "Fácil";

                int lv;

                std::string name;

                std::vector<std::string> words_v;

                int score = 0;

                Player();

                void setLevel(int l);

                std::string getName();

                void setName(std::string n);


                void setWords(std::vector<std::string> w);

                void setScore();

                void update_score(int point);

                std::string final_data();
};

#endif