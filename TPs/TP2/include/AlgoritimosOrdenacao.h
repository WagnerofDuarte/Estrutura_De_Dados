#ifndef ALGORITIMOS_DE_ORDENACAO
#define ALGORITIMOS_DE_ORDENACAO

#include <Lista.h>
#include <math.h>
class AlgoritimosDeOrdenacao {

    private:
        void calculaAngulos(Lista* lista);
        void merge(Lista*, int inicio, int meio, int fim);
        Lista* coutingSort(Lista* lista, int digito);
        int numNaPosicao(double _num, int digito);

    public:
        AlgoritimosDeOrdenacao(Lista* lista);

        void insertionSort(Lista* lista);
        void mergeSort(Lista* lista, int inicio, int fim);
        void radixSort(Lista* lista);

};

#endif