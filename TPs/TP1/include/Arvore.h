#ifndef ARVORE
#define ARVORE

#include <NoArvore.h>
#include <Fila.h>

class Arvore {

    private:
        /* ATRIBUTOS */
        NoArvore *raiz;

    public:
        /* CONSTRUTOR E DESTRUTOR */
        Arvore();
        ~Arvore();

        NoArvore* getRaiz();

        /* MÉTODOS */
        bool InsereExpressaoPosFixa(NoArvore* no, char caractere);
        void limpa();

        void leInFixa(NoArvore* no);
};


#endif