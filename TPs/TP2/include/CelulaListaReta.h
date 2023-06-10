#ifndef CELULA_LISTA_RETA
#define CELULA_LISTA_RETA

#include <Reta.h>
#include <iostream>

class CelulaListaReta {

    private:
        Reta *reta;
        CelulaListaReta *prox;
        
    public:
        CelulaListaReta(Ponto *A, Ponto *B);

        Reta* getReta();

        CelulaListaReta* getProx();
        void setProx(CelulaListaReta *_prox);
};

#endif