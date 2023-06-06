#include <CelulaLista.h>

CelulaLista::CelulaLista(int _x, int _y){
    
    prox = NULL;
    ponto = new Ponto(_x, _y);

}

Ponto* CelulaLista::getPonto(){
    
    return ponto;
}

CelulaLista* CelulaLista::getProx(){
    
    return prox;
}

void CelulaLista::setProx(CelulaLista *_prox){
    
    prox = _prox;
}