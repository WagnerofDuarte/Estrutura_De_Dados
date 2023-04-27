#ifndef CELULA_PILHA
#define CELULA_PILHA

#include <iostream>

class CelulaPilha {

    private:
        /* ATRIBUTOS */
        char caractere;
        CelulaPilha *prox;
    public:
        CelulaPilha(char _caractere, CelulaPilha *_prox);
        ~CelulaPilha();

        char getCaractere();

        CelulaPilha *getProx();
        void setProx(CelulaPilha *_prox);
    };

#endif