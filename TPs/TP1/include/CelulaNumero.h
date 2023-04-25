#ifndef CELULA_NUMERO
#define CELULA_NUMERO

#include <iostream>

class CelulaNumero {

    private:
        /* ATRIBUTOS */
        double numero;
        CelulaNumero *prox;
    public:
        CelulaNumero(double _numero, CelulaNumero *prox);
        ~CelulaNumero();

        double getNumero();

        CelulaNumero *getProx();
        void setProx(CelulaNumero *_prox);
    };

#endif