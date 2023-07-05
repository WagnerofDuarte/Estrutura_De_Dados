#ifndef ARVORE
#define ARVORE

#include <NoArvore.h>
#include <iostream>

/* Esta classe é uma TAD que representa uma versao simplificada de uma árvore binária, usada para criar a árvore
   de frequencias do algorítmo de Huffman */
class Arvore {

    public:
        Arvore(char _caractere, int _frequencia);
        NoArvore *raiz;

};

#endif