#include <CelulaFila.h>

CelulaFila::CelulaFila(char _caractere, CelulaFila *_prox) {

    caractere  = _caractere;
    prox = _prox;

}

CelulaFila::~CelulaFila() {


}

char CelulaFila::getCaractere(){
    return caractere;

}

CelulaFila *CelulaFila::getProx(){
    return prox;
}

void CelulaFila::setProx(CelulaFila *_prox){
    prox = _prox;

}