#include <CelulaNumero.h>

CelulaNumero::CelulaNumero(double _numero, CelulaNumero *_prox) {

    numero = _numero;
    prox = _prox;

}

CelulaNumero::~CelulaNumero() {


}

double CelulaNumero::getNumero(){
    return numero;

}

CelulaNumero *CelulaNumero::getProx(){
    return prox;
}

void CelulaNumero::setProx(CelulaNumero *_prox){
    prox = _prox;

}