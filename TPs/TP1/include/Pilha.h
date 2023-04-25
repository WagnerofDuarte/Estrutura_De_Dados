#ifndef PILHA
#define PILHA

#include <string>
#include <iostream>
#include <CelulaNumero.h>

using namespace std;

class Pilha {
    private:
        /* ATRIBUTOS */
        int tamanho;
        CelulaNumero* topo; 

    public:
        /* CONSTRUTOR E DESTRUTOR*/
        Pilha(/* args */);
        ~Pilha();

        bool vazia();

        int getTamanho();

        void empilha(double numero);
        double desempilha();
        void limpa();

    };




#endif