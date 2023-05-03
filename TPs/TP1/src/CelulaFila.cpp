#include <CelulaFila.h>

CelulaFila::CelulaFila(char _caractere, double _numero, CelulaFila *_prox) {

    caractere  = _caractere;
    numero = _numero;
    prox = _prox;

}

CelulaFila::~CelulaFila() {


}

char CelulaFila::getCaractere(){
    return caractere;

}

double CelulaFila::getNum(){
    return numero;
}

CelulaFila *CelulaFila::getProx(){
    return prox;
}

void CelulaFila::setProx(CelulaFila *_prox){
    prox = _prox;

}