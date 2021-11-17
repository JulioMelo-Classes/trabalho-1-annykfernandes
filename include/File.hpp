#ifndef FILE_HPP
#define FILE_HPP

#include<iostream>
#include <vector>
#include<string>
#include <fstream>
#include <regex>
#include <sstream>
#include <utility>

using namespace std;

class File
{   
    public:
        std::vector<std::string> file_lines;
        std::vector< std::pair<std::string, int> > pair_word_number;
        //Member functions
        File();
        std::vector<std::string> loadFile(std::string path);
        bool validateScoresFile(std::vector<std::string> scores_file);
        bool validateWordsFile(std::vector<std::string> words_file);
        void getScores();
        std::vector< std::pair<std::string, int> > generate_pairs(std::vector<std::string> w_lines);
};

#endif