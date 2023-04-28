#include <NoArvore.h>

NoArvore::NoArvore(char _caractere){

    caractere = _caractere;
    esq = NULL;
    dir = NULL;

}

NoArvore::~NoArvore(){

}

char NoArvore::getCaractere(){
    return caractere;
}

NoArvore *NoArvore::getEsq(){
    return esq;
}

NoArvore *NoArvore::getDir(){
    return dir;
}

void NoArvore::setCaractere(char _caractere){
    caractere = _caractere;
}

void NoArvore::setEsq(NoArvore *_esq){
    esq = _esq;
}

void NoArvore::setDir(NoArvore *_dir){
    dir = _dir;
}

