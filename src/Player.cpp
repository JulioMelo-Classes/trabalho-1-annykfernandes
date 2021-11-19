#include "../include/Player.hpp"

std::string level = "Fácil";
int lv;
std::string name;
std::vector<std::string> words_v;
int score = 0;


Player::Player() 
{   
    level = "Fácil";
    name = "fulaninho";
    words_v.push_back("");
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
    // cout<<"Score final: "<< score << endl;
}

void Player::setWords(std::vector<std::string> w)
{
    words_v = w;
    cout<<"Palavras que conseguiu: "<<endl;
    for(int i = 0; i < words_v.size(); i++)
    {
        cout<<words_v[i]<<endl;
    }
}

void Player::update_score(int point)
{
    if(point == 1)
    {
        score++;
    }
}

std::string Player::final_data()
{   
    std::ostringstream vts;
    //solução do geeksforgeeks
    std::string words;

    if (!words_v.empty())
    {
        // Convert all but the last element to avoid a trailing ","
        std::copy(words_v.begin(), words_v.end()-1, std::ostream_iterator<std::string>(vts, ", "));
        // Now add the last element with no delimiter
        vts << words_v.back();
        words = vts.str();
    }

    std::string s_final_score = std::to_string(score); 
    
    std::string f_s = level + "; " + name + "; " + words + "; " + s_final_score;
    std::cout<<f_s<<std::endl;
    return f_s;
}
