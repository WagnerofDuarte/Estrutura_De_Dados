#include <Fila.h>
#include <iostream>

using namespace std;

Fila::Fila() {

    frente = new CelulaNumero(0, NULL);
    tras = frente;
    tamanho = -1;
}

Fila::~Fila() {

    limpa();
    delete frente;

}

int Fila::getTamanho(){
    return tamanho;
}

bool Fila::vazia(){

    if(tamanho == 0){
        return true;
    } else {
        return false;
    }

}

void Fila::enfileira(double numero){

    CelulaNumero *novaCelula;

    novaCelula = new CelulaNumero(numero, nullptr);
    tras->setProx(novaCelula);
    tras = novaCelula;
    
    tamanho++;
}

double Fila::desenfileira(){

    CelulaNumero *celula;
    double numero;

    if(tamanho == 0){
        return 0;
    }

    numero = frente->getProx()->getNumero();
    celula = frente;
    frente = frente->getProx();

    delete celula;
    tamanho --;

    return numero;

}

void Fila::limpa(){

    CelulaNumero *aux;

    aux = frente->getProx();

    if(aux == NULL){
        
    } else {

        while (aux != NULL){
            frente->setProx(aux->getProx());
            delete aux;
            aux = frente->getProx();
        }   

    tamanho = 0;
    tras = frente;
    }
}