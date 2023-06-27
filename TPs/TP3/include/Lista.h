#ifndef LISTA
#define LISTA

#include <CelulaLista.h>

class Lista {

    private:
        int tam;
        CelulaLista* primeiro;
        CelulaLista* ultimo;

    public:
        Lista();

        void insereFinal(char _caractere, bool _caractereValido);
        void removeInicio();
        void inserePosicao(int posicao);
        
        int getTam();
        CelulaLista* getPrimeiro();
        CelulaLista* getPosicao(int posicao);

        void ordena();

        void imprime();

};

#endif