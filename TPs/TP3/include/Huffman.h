#ifndef HUFFMAN
#define HUFFMAN

#include <Lista.h>

using namespace std;

class Huffman {

    private:
        Lista* listaDeFrequencias;

    public:
        Huffman();
        void calcularFrequencias(Lista* listaDeCaracteres);

};

#endif