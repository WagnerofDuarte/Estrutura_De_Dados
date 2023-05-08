#include <CelulaLista.h>
#include <iostream>

CelulaLista::CelulaLista() {

    prox = NULL;

}

CelulaLista::~CelulaLista(){


}

char CelulaLista::getCaractere(){
    return caractere;
}

double CelulaLista::getNum(){
    
    return num;
}

CelulaLista* CelulaLista::getProx(){
    return prox;
}


void CelulaLista::setCaractere(char _caractere){
    caractere = _caractere;
}

void CelulaLista::setNum(double _num){
    num = _num;
}

void CelulaLista::setProx(CelulaLista *_prox){
    prox = _prox;
}
