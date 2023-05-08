#ifndef ARVORE
#define ARVORE

#include <NoArvore.h>
#include <Fila.h>

class Arvore {

    private:
        /* ATRIBUTOS */
        double resultado;
    public:
        /* CONSTRUTOR E DESTRUTOR */
        NoArvore *raiz;

        Arvore();
        ~Arvore();

        double gerarResultado(NoArvore* &no);
        double calculadora(char operador, double p1, double p2);
        //double getResultado();

        NoArvore* getRaiz();

        /* MÉTODOS */
        bool InsereExpressaoPosFixa(NoArvore* &no, char caractere, double num);
        void limpa();

        void leInFixa(NoArvore* no);
};


#endif