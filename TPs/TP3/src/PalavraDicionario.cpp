#include <PalavraDicionario.h>

PalavraDicionario::PalavraDicionario(char _caractere, string _bits){

    caractere = _caractere;
    bits = _bits;
    prox = NULL;

}

void PalavraDicionario::setBits(string _bits){
    bits = _bits;
}

string PalavraDicionario::getBits(){
    return bits;
}

void PalavraDicionario::setCaractere(char _caractere){
    caractere = _caractere;
}

char PalavraDicionario::getCaractere(){
    return caractere;
}

void PalavraDicionario::setProx(PalavraDicionario* _prox){
    prox = _prox;
}

PalavraDicionario* PalavraDicionario::getProx(){
    return prox;
}
