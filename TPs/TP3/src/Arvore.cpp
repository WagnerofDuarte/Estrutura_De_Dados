#include <Arvore.h>

Arvore::Arvore(char _caractere, int _frequencia){
    raiz = new NoArvore(_caractere, _frequencia);
}