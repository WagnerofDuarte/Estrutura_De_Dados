#ifndef RETA
#define RETA

#include <Ponto.h>
class Reta {

    private:
        Ponto *pontoA;
        Ponto *pontoB;

    public:
        Reta(Ponto* A, Ponto* B);

        Ponto* getPontoA();
        void setPontoA(Ponto* A);

        Ponto* getPontoB();
        void setPontoB(Ponto* B);

};

#endif