#include <NoArvore.h>

NoArvore::NoArvore(char _caractere, int _frequencia){

    caractere = _caractere;
    frequencia = _frequencia;
    esq = NULL;
    dir = NULL;
}

void NoArvore::setCaractere(char _caractere){
    caractere = _caractere;
}

char NoArvore::getCaractere(){
    return caractere;
}

void NoArvore::setFrequencia(int _frequencia){
    frequencia = _frequencia;
}

int NoArvore::getFrequencia(){
    return frequencia;
}
