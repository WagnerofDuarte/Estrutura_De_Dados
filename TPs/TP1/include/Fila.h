#ifndef FILA
#define FILA

#include <CelulaFila.h>
#include <Pilha.h>

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

        char getFrente();
        double getFrenteNumero();

        void enfileira(char _caractere, double _num);
        char desenfileira();
        double desenfileraDouble();
        void limpa();

        double gerarResultado();
        bool eNumero(char c);

        void leFila();

        double calculadora(char operador, double p1, double p2);
};

#endif