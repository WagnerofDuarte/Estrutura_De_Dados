#include <CelulaListaPonto.h>

CelulaListaPonto::CelulaListaPonto(int _x, int _y){
    prox = NULL;
    ponto = new Ponto(_x, _y);
}

Ponto* CelulaListaPonto::getPonto(){
    return ponto;
}

CelulaListaPonto* CelulaListaPonto::getProx(){
    return prox;
}

void CelulaListaPonto::setProx(CelulaListaPonto *_prox){  
    prox = _prox;
}