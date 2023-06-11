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
        void setProx(CelulaListaPonto *_prox);
        Ponto* getPonto();
        CelulaListaPonto* getProx();
};

#endif