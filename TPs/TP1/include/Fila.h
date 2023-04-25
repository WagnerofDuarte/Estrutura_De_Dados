#ifndef FILA
#define FILA

#include <CelulaNumero.h>

class Fila {

    private:
        /* ATRIBUTOS */
        int tamanho;
        CelulaNumero* frente;
        CelulaNumero* tras;

    public:
        /* CONSTRUTOR E DESTRUTOR */
        Fila(/* args */);
        ~Fila();

        int getTamanho();
        bool vazia();

        void enfileira(double numero);
        double desenfileira();
        void limpa();
};

#endif