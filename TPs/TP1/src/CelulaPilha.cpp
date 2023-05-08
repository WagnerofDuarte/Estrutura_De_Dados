#include <CelulaPilha.h>
#include <NoArvore.h>

CelulaPilha::CelulaPilha(char _caractere, double _numero, CelulaPilha *_prox) {

    numero = _numero;
    caractere  = _caractere;
    prox = _prox;
    L = NULL;

}

CelulaPilha::~CelulaPilha() {


}

double CelulaPilha::getNumero(){
    return numero;

}

char CelulaPilha::getCaractere(){
    return caractere;

}

CelulaPilha *CelulaPilha::getProx(){
    return prox;
}

void CelulaPilha::setProx(CelulaPilha *_prox){
    prox = _prox;
}

Lista* CelulaPilha::getL(){
    return L;

}

void CelulaPilha::setL(Lista* aux){

    L = aux;
}