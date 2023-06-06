#ifndef CELULA_LISTA
#define CELULA_LISTA

#include <Ponto.h>
#include <iostream>

class CelulaLista {

    private:
        Ponto *ponto;
        CelulaLista *prox;
        
    public:
        CelulaLista(int _x, int _y);

        Ponto* getPonto();

        CelulaLista* getProx();
        void setProx(CelulaLista *_prox);
};

#endif