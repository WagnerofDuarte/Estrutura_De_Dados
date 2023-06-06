#ifndef LISTA
#define LISTA

#include <CelulaLista.h>

class Lista {

    private:
        CelulaLista* primeiro;
        CelulaLista* ultimo;
        int tam;

    public:
        Lista();
        ~Lista();

        void insereFinal(int _x, int _y);

        Ponto* menorPonto();
        Ponto* pontoNaPosicao(int p);

        void imprime();
        void limpa();

        int getTam();

        CelulaLista* getPrimeiro();

};

#endif