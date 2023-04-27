#ifndef CELULA_FILA
#define CELULA_FILA

#include <iostream>

class CelulaFila {

    private:
        /* ATRIBUTOS */
        char caractere;
        CelulaFila *prox;
    public:
        CelulaFila(char _caractere, CelulaFila *_prox);
        ~CelulaFila();

        char getCaractere();

        CelulaFila *getProx();
        void setProx(CelulaFila *_prox);
    };

#endif