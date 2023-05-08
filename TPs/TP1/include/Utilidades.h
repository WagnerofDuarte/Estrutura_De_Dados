#ifndef UTILIDADES
#define UTILIDADES

#include <CelulaLista.h>

class Utilidades {
    public:
        Utilidades();
        ~Utilidades();

        double calculadora(char operador, double p1, double p2);

        bool eNumero(char c);
        bool eOperador(char c);

        CelulaLista* converteNum(CelulaLista* celula);



    };

#endif
