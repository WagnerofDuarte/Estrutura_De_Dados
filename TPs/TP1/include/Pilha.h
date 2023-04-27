#ifndef PILHA
#define PILHA

#include <string>
#include <iostream>
#include <CelulaPilha.h>

using namespace std;

class Pilha {
    private:
        /* ATRIBUTOS */
        int tamanho;
        CelulaPilha* topo; 

    public:
        /* CONSTRUTOR E DESTRUTOR*/
        Pilha();
        ~Pilha();

        bool vazia();

        int getTamanho();

        void empilha(char caractere);
        char desempilha();
        void limpa();

    };




#endif