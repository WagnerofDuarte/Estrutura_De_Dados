#ifndef FILA
#define FILA

#include <CelulaFila.h>

class Fila {

    private:
        /* ATRIBUTOS */
        int tamanho;
        CelulaFila* frente;
        CelulaFila* tras;

    public:
        /* CONSTRUTOR E DESTRUTOR */
        Fila(/* args */);
        ~Fila();

        int getTamanho();
        bool vazia();

        void enfileira(char _caractere, double _num);
        char desenfileira();
        void limpa();
};

#endif