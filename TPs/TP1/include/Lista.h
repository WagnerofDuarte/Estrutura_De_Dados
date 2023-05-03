#ifndef LISTA
#define LISTA

#include <CelulaLista.h>

class Lista {

    private:
        CelulaLista* primeiro;
        CelulaLista* ultimo;
        CelulaLista* posiciona(int pos, bool antes);
        int tamanho;

    public:

        Lista();
        ~Lista();

        void insereFinal(char caractere);
        void imprime();
        void limpa();

        int getTamanho();

        CelulaLista* getPrimeiro();
        CelulaLista* getUltimo();

};

#endif