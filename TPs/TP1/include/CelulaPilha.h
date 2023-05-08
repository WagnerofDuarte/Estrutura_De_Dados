#ifndef CELULA_PILHA
#define CELULA_PILHA

#include <iostream>
#include <Lista.h>

class CelulaPilha {

    private:
        /* ATRIBUTOS */
        char caractere;
        double numero;
        CelulaPilha *prox;
        Lista *L;
    public:
        CelulaPilha(char _caractere, double _numero, CelulaPilha *_prox);
        ~CelulaPilha();

        char getCaractere();
        double getNumero();

        CelulaPilha *getProx();
        void setProx(CelulaPilha *_prox);

        Lista *getL();
        void setL(Lista* aux);

    };

#endif