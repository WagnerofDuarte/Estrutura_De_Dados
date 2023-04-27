#include <CelulaPilha.h>
#include <NoArvore.h>

CelulaPilha::CelulaPilha(char _caractere, CelulaPilha *_prox) {

    caractere  = _caractere;
    prox = _prox;

}

CelulaPilha::~CelulaPilha() {


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