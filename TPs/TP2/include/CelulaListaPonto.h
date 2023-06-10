#ifndef CELULA_LISTA_PONTO
#define CELULA_LISTA_PONTO

#include <Ponto.h>
#include <iostream>

class CelulaListaPonto {

    private:
        Ponto *ponto;
        CelulaListaPonto *prox;
        
    public:
        CelulaListaPonto(int _x, int _y);

        Ponto* getPonto();

        CelulaListaPonto* getProx();
        void setProx(CelulaListaPonto *_prox);
};

#endif