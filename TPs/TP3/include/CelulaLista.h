#ifndef CELULA_LISTA
#define CELULA_LISTA

#include <iostream>
#include <Arvore.h>

/* Esta classe representa um elemento basico de uma TAD Lista Encadeada, sendo ela uma celula. Essa celula é capaz 
   de armazenar diversos itens relevantes para a execucao do sistema */

class CelulaLista {

    private:
        char caractere;
        bool caractereValido;
        int frequencia;

        CelulaLista *prox;
        Arvore* arvoreFrequencias;

    public:
        CelulaLista(char _caractere, bool _caractereValido);

        char getCaractere();
        void setCaractere(char _caractere);
        CelulaLista* getProx();
        void setProx(CelulaLista *_prox);
        Arvore* getArvoreFrequencias();

        int getFrequencia();
        void setFrequencia(int _frequencia);
        void incrementarFrequencia();
};

#endif