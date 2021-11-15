#include "../include/File.hpp"

std::vector<std::string> file_lines;
std::vector< std::pair<std::string, int> > pair_word_number;

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

    bool is_valid; 
    for(int i = 0; i<scores_file.size(); i++)
    {
        std::string a = scores_file[i];
        regex b("([a-zA-Zá-ú])+;([a-zA-Zá-ú]| |,)+;([a-zA-Zá-ú-]| |,|)+; [0-9]+$");
        if(regex_match(a, b))
        {
            is_valid = true;  
        }
        else
        {
            is_valid = false;
        }
    }
    return is_valid;
}
bool File::validateWordsFile(std::vector<std::string> words_file)
{
    bool is_valid; 
    for(int i = 0; i<words_file.size(); i++)
    {
        std::string a = words_file[i];
        regex b("([([a-zA-Zá-ú-]{4,}+) +[0-9]+");
        if(regex_match(a, b))
        {
            is_valid = true;  
        }
        else
        {
            is_valid = false;
        }
    }
    return is_valid;
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

std::vector< std::pair<std::string, int> > File::generate_pairs(std::vector<std::string> w_lines)
{   
    for(int i = 0; i<w_lines.size(); i++)
    {

        std::string str = w_lines[i];

        std::regex wrd("[^0-9 ]");
        std::sregex_iterator m_wrd(str.begin(), str.end(), wrd);
        std::sregex_iterator lastMatchWrd;

        std::vector<std::string> v_word;
        while(m_wrd != lastMatchWrd)
        {
            std::smatch sm_word = *m_wrd;
            v_word.push_back(sm_word.str());
            m_wrd++;
        }

        std::regex nbr("[0-9]");
        std::sregex_iterator m_nbr(str.begin(), str.end(), nbr);
        std::sregex_iterator lastMatchNbr;

        std::vector<std::string> v_number;
        while(m_nbr != lastMatchNbr)
        {
            std::smatch sm_number = *m_nbr;
            v_number.push_back(sm_number.str());
            m_nbr++;
        }

        std::ostringstream out_word;
        for(std::string s: v_word)
        {
            out_word << s;
        }
        std::string word(out_word.str());

        std::ostringstream out_number;
        for(std::string n: v_number)
        {
            out_number << n;
        }
        std::string s_number(out_number.str());
        std::stringstream ss;
        ss<<s_number;
        int number;
        ss>>number;

        pair_word_number.push_back(std::make_pair(word,number));

    }
    
    return pair_word_number;
}
