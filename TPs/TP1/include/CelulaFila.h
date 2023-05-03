#ifndef CELULA_FILA
#define CELULA_FILA

#include <iostream>

class CelulaFila {

    private:
        /* ATRIBUTOS */
        char caractere;
        double numero;
        CelulaFila *prox;
    public:
        CelulaFila(char _caractere, double _numero, CelulaFila *_prox);
        ~CelulaFila();

        char getCaractere();
        double getNum();

        CelulaFila *getProx();
        void setProx(CelulaFila *_prox);
    };

#endif