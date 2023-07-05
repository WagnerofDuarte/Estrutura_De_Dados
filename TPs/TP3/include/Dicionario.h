#ifndef DICIONARIO
#define DICIONARIO

#include <iostream>
#include <Arvore.h>
#include <PalavraDicionario.h>

using namespace std;

/* Esta classe é uma adaptacao de uma TAD Lista Encadeada que representa o dicionário que deve ser criado
   durante a execucao do algoritimo de Huffman, que armazena o dicionário, ou seja, a representacao, em bits, de cada
   caractere presente no arquivo de texto á ser compactado */

class Dicionario {

    private:
        int tam;
        PalavraDicionario* primeiro;
        PalavraDicionario* ultimo;

    public:
        Dicionario();

        void insereLetra(char _caractere, string _bits);
        PalavraDicionario* buscarLetra(char letra);
        PalavraDicionario* buscarBits(string bits);

        int getTam();
        PalavraDicionario* getPrimeiro();
        void setPrimeiro(PalavraDicionario* _primeiro);
        PalavraDicionario* getUltimo();
        void setUltimo(PalavraDicionario* _ultimo);
};

#endif