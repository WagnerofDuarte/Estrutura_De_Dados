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
        CelulaPilha* getTopo();

        void empilha(char caractere, double numero);
        void empilhaLista(Lista* aux);

        double desempilha();
        void limpa();

    };




#endif