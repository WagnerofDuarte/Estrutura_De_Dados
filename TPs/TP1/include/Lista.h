#ifndef LISTA
#define LISTA

#include <CelulaLista.h>

class Lista {

    private:
        CelulaLista* primeiro;
        CelulaLista* ultimo;
        int tamanho;

    public:

        Lista();
        ~Lista();

        void insereFinal(char caractere, double num);
        void insereInicio(char caractere, double num);

        void imprime();
        void limpa();

        void setUltimo(CelulaLista* celula);

        int getTamanho();

        void concatena(Lista* _lista);

        CelulaLista* getPrimeiro();
        CelulaLista* getUltimo();

};

#endif