#ifndef RETA
#define RETA

#include <Ponto.h>
class Reta {

    private:
        Ponto *pontoA;
        Ponto *pontoB;

    public:
        Reta(Ponto* A, Ponto* B);
        void setPontoA(Ponto* A);
        void setPontoB(Ponto* B);
        Ponto* getPontoA();
        Ponto* getPontoB();
};

#endif