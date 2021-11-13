#include "../include/File.hpp"

std::vector<std::string> file_lines;

File::File()
{   
    file_lines.push_back("");
}

std::vector<std::string> File::loadFile(std::string path)
{   
    ifstream file(path);
    std::string line;
    if (file.is_open())
    {
        while(getline(file, line))
        {   
            file_lines.push_back(line);
        }
    file.close();
    }
    return file_lines;
}


bool File::validateScoresFile(std::vector<std::string> scores_file)
{     
    return true;     
}
bool File::validateWordsFile(std::vector<std::string> words_file)
{
    return true;     
}

void File::getScores()
{   
    std::cout<<"--------------------------------------------------------------------"<<std::endl;
    std::cout<<"Histórico do jogo: ";
    for(int i = 0; i<file_lines.size(); i++)
    {
        std::cout<<file_lines[i]<<std::endl;
    }
    std::cout<<"--------------------------------------------------------------------"<<std::endl;
}
