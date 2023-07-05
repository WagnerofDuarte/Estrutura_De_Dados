#ifndef NO_ARVORE
#define NO_ARVORE

#include <iostream>

using namespace std;

/* Esta classe representa um elemento basico de uma TAD Árvore, sendo ela um nó da árvore. Esse nó é capaz 
   de armazenar diversos itens relevantes para a execucao do sistema */

class NoArvore {

    private:
        char caractere;
        int frequencia;

    public:
        NoArvore(char _caractere, int _frequencia);

        NoArvore *esq;
        NoArvore *dir;

        void setCaractere(char _caractere);
        char getCaractere();
        void setFrequencia(int _frequencia);
        int getFrequencia();

};

#endif