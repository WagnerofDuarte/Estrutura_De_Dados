#ifndef PALAVRA_DICIONARIO
#define PALAVRA_DICIONARIO

#include <iostream>
#include <string>


using namespace std;

/* Esta classe representa uma adaptação do elemento basico de uma TAD Lista Encadeada, sendo ela uma celula.
   A PalavraDicionário visa armazenar os caracteres do dicionário, assim como as suas representações binárias */

class PalavraDicionario {

    private:
        char caractere;
        string bits;
        PalavraDicionario* prox;

    public:
        PalavraDicionario(char _caractere, string _bits);

        void setBits(string _bits);
        string getBits();

        void setCaractere(char _caractere);
        char getCaractere();

        void setProx(PalavraDicionario* _prox);
        PalavraDicionario* getProx();
};

#endif