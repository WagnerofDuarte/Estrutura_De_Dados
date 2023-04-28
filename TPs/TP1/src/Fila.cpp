#include <Fila.h>
#include <iostream>

using namespace std;

Fila::Fila() {

    frente = new CelulaFila(0, NULL);
    tras = frente;
    tamanho = -1;
}

Fila::~Fila() {

    limpa();
    //delete frente;

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

void Fila::enfileira(char _caractere){

    CelulaFila *novaCelula;

    novaCelula = new CelulaFila(_caractere, nullptr);
    tras->setProx(novaCelula);
    tras = novaCelula;
    tamanho++;
}

char Fila::desenfileira(){

    CelulaFila *celula;
    char caractere;

    if(tamanho == 0){
        return 0;
    }

    caractere = frente->getProx()->getCaractere();
    celula = frente;
    frente = frente->getProx();

    delete celula;
    tamanho --;

    cout << "Desenfileirou: " << caractere << endl;

    return caractere;

}

void Fila::limpa(){

    CelulaFila *aux;

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