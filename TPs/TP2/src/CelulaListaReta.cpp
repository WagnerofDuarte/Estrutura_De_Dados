#include <CelulaListaReta.h>

CelulaListaReta::CelulaListaReta(Ponto *A, Ponto *B){
    reta = new Reta(A, B);
    prox = NULL;
}

Reta* CelulaListaReta::getReta(){
    return reta;
}

CelulaListaReta* CelulaListaReta::getProx(){
    return prox;
}

void CelulaListaReta::setProx(CelulaListaReta *_prox){
    prox = _prox;
}
