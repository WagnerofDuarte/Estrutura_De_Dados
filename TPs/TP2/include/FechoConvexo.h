#ifndef FECHO_CONVEXO
#define FECHO_CONVEXO

#include <Lista.h>

class FechoConvexo{

    private:
        Lista* retasDoFecho;

    public:
        FechoConvexo();
        void imprimirFecho();
        void adicionarReta(Reta* reta);

};

#endif