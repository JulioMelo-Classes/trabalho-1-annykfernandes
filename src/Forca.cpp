#ifndef FORCA_HPP
#define FORCA_HPP

#include<iostream>
#include <vector>
#include<string>
#include <fstream>
#include <map>

using namespace std;
 
class Forca {
    public:
        enum Dificuldade{
            FACIL, MEDIO, DIFICIL
        };
        
        map<char, bool> hit;
        
        int index_pair;
        
        std::vector< std::pair<std::string, int> > game_on_words;
        
        bool n_ganhou = true;

        bool n_enforcou = true;

        bool n_desistiu = true;

        char chute;

    private:
       
        std::vector< std::pair<std::string, int> > m_palavras; //<! palavras e sua ocorrência no Corpus
 
        std::string m_arquivo_scores; //<! nome do arquivo contendo os scores
 
        std::string m_arquivo_palavras; //<! nome do arquivo contendo as palavras
 
        Dificuldade d; //<! dificuldade do jogo
 
        std::string m_palavra_atual; //<! palavra sendo testada atualmente
 
        int m_tentativas_restantes;//<! tentativas restantes

        std::vector< std::pair<std::string, int> > pairs_easy;

        std::vector< std::pair<std::string, int> > pairs_medium;

        std::vector< std::pair<std::string, int> > pairs_hard;

    public:
        /**
         * Cria a classe Forca
         * O construtor pode ou não validar os arquivos de entrada, no entanto, mesmo com 
         * os arquivos inválidos o objeto deve ser construído. Para o caso de arquivos de palavras
         * ou scores inválidos, use o método eh_valido.
         * @param palavras o arquivo que contém as palavras
         * @param scores o nome do arquivo que contém os scores
         * @see eh_valido
         */
        // Forca( std::string palavras, std::string scores);
        Forca(std::vector< std::pair<std::string, int> > p);

        bool nao_ganhou();

        bool update_n_ganou();

        bool nao_enforcou();

        bool update_n_enforcou();

        bool nao_desistiu();

        bool update_n_desistiu();
 
        /**
         * Modifica a dificuldade do jogo.
         * De acordo com a dificuldade configurada, o método proxima_palavra retornará palavras
         * diferentes.
         * @param d a dificuldade desejada
         * @see proxima_palavra
         */
        void setLevel(int d);
 
        /**
         * Retorna a próxima palavra de acordo com a dificuldade atual.
         * Este método deve atualizar o atributo m_palavra_atual e retornar a palavra um texto no formato
         * "_ _ _ _ ... _" dependendo do tamanho de m_palavra_atual. O método também deve sortear as 
         * letras que devem aparecer dependendo do nível de dificuldade.
         * @return a próxima palavra do conjunto de palavras disponível de acordo com a dificuldade atual.
         */
        std::string proxima_palavra(int indx);
 
        /**
         * Retorna a palavra atual que está sendo jogada.
         * @return o valor do atributo m_palavra_atual.
         */
        std::string get_palavra_atual(int indx);

        bool verifica_palavra();

        void set_chute(char c);

        void set_palavra_atual(std::string p_a);

        void status_palavra();
 
        /**
         * Atualiza o número de tentativas restantes.
         * Este método é útil no caso do jogador escolher continuar o jogo.
         * @param tentativas atualiza o valor da variável m_tentativas_restantes.
         */
        void set_tentativas_restantes(int tentativas);
        /**
         * Retorna a quantidade de tentativas restantes.
         * @return a quantidade de tentativas restantes.
         */
        
        int get_tentativas_restantes();
        /**
         * Verifica o valor da valiável @param tentativas e desenha no console.
         */

        void update_tentativas();

        int status_tentativas();

        void reset_tentativas();

        void verify_n_draw(int s_t);
 
};

#endif
