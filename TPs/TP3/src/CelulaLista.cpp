#include <CelulaLista.h>

CelulaLista::CelulaLista(char _caractere, bool _caractereValido){
    
    prox = NULL;
    caractere = _caractere;
    caractereValido = _caractereValido;
    frequencia = 1;
    arvoreFrequencias = new Arvore(caractere, frequencia);

}

char CelulaLista::getCaractere(){
    return caractere;
}

void CelulaLista::setCaractere(char _caractere){
    caractere = _caractere;
}

CelulaLista* CelulaLista::getProx(){
    return prox;
}

void CelulaLista::setProx(CelulaLista *_prox){
    prox = _prox;
}

int CelulaLista::getFrequencia(){
    return frequencia;
}

void CelulaLista::setFrequencia(int _frequencia){
    frequencia = _frequencia;
}

void CelulaLista::incrementarFrequencia(){
    frequencia++;
}

Arvore* CelulaLista::getArvoreFrequencias(){
    return arvoreFrequencias;
}
