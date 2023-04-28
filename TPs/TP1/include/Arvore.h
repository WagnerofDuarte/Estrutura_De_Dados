#ifndef ARVORE
#define ARVORE

#include <NoArvore.h>
#include <Fila.h>

class Arvore {

    private:
        /* ATRIBUTOS */

    public:
        /* CONSTRUTOR E DESTRUTOR */
        NoArvore *raiz;

        Arvore();
        ~Arvore();

        NoArvore* getRaiz();

        /* MÉTODOS */
        bool InsereExpressaoPosFixa(NoArvore* &no, char caractere);
        void limpa();

        void leInFixa(NoArvore* no);
};


#endif