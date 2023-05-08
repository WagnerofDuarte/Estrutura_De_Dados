#ifndef ARVORE
#define ARVORE

#include <NoArvore.h>
#include <Utilidades.h>
#include <Fila.h>

class Arvore {

    private:
        /* ATRIBUTOS */
        double resultado;
    public:
        Utilidades *utilidades;
        /* CONSTRUTOR E DESTRUTOR */
        NoArvore *raiz;

        Arvore();
        ~Arvore();

        double gerarResultado(NoArvore* &no);

        NoArvore* getRaiz();

        /* MÉTODOS */
        bool InsereExpressaaoInFixa(NoArvore* &no, char caractere, double num);
        void limpa();

        void leInFixa(NoArvore* no);
};


#endif