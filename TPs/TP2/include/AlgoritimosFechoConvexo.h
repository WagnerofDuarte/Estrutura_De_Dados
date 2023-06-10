#ifndef ALGORITIMOS_FECHO_CONVEXO
#define ALGORITIMOS_FECHO_CONVEXO

#include <Lista.h>
#include <AlgoritimosOrdenacao.h>
#include <FechoConvexo.h>

class AlgoritimosFechoConvexo {

    private:
        //Ponto pontos[];
        int orientacao(Ponto* p1, Ponto* p2, Ponto* p3);
    
    public:

        FechoConvexo* marchaDeJarvis(Lista* listaDePontos);
        FechoConvexo* scanDeGraham(Lista* listaDePontos, int ord);

};

#endif