#ifndef NO_ARVORE
#define NO_ARVORE

#include <iostream>

class NoArvore {

    private:
        /* ATRIBUTOS */
        char caractere;
        //NoArvore *esq;
        //NoArvore *dir;

    public:

        NoArvore *esq;
        NoArvore *dir;

        NoArvore(char _caractere);
        ~NoArvore();

        char getCaractere();
        void setCaractere(char _caractere);

        NoArvore *getEsq();
        NoArvore *getDir();

        void setEsq(NoArvore *_esq);
        void setDir(NoArvore *_dir);
    };

#endif