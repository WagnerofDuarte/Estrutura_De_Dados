#ifndef ALGORITIMOS_FECHO_CONVEXO
#define ALGORITIMOS_FECHO_CONVEXO

#include <Lista.h>

class AlgoritimosFechoConvexo {

    private:
        //Ponto pontos[];
        int orientacao(Ponto* p1, Ponto* p2, Ponto* p3);
    
    public:
        AlgoritimosFechoConvexo();

        Lista* marchaDeJarvis(Lista* listaDePontos);
        void scanDeGraham();

};

#endif