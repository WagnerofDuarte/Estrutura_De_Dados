#ifndef CELULA_LISTA
#define CELULA_LISTA

#include <iostream>

class CelulaLista {

    private:
        char caractere;
        bool caractereValido;
        int frequencia;

        CelulaLista *prox;
        //Criar arvore

    public:
        CelulaLista(char _caractere, bool _caractereValido);

        char getCaractere();
        void setCaractere(char _caractere);

        CelulaLista* getProx();
        void setProx(CelulaLista *_prox);

        int getFrequencia();
        void incrementarFrequencia();

};

#endif