#ifndef FILE_HPP
#define FILE_HPP

#include<iostream>
#include <vector>
#include<string>
#include <fstream>
using namespace std;

class File
{   
    public:
        std::vector<std::string> file_lines;
        //Member functions
        File();//constructor
        std::vector<std::string> loadFile(std::string path);
        bool validateScoresFile(std::vector<std::string> scores_file);
        bool validateWordsFile(std::vector<std::string> words_file);
        void getScores();
};

#endif