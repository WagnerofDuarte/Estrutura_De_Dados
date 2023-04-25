#include <Pilha.h>

Pilha::Pilha(/* args */) {

    topo = NULL;

}

Pilha::~Pilha() {

    limpa();

}

bool Pilha::vazia(){

    if(tamanho == 0){
        return true;
    } else {
        return false;
    }

}

int Pilha::getTamanho(){
    return tamanho;
}

void Pilha::empilha(double numero){

    CelulaNumero *celula;
    celula = new CelulaNumero(numero, topo);
    topo = celula;

    tamanho++;

}

double Pilha::desempilha(){

    double numero;
    CelulaNumero *celula;

    if(tamanho == 0){
        return 0;
    }

    numero = topo->getNumero();
    celula = topo;
    topo = topo = topo->getProx();

    delete celula;
    tamanho--;

    return numero;

}
void Pilha::limpa(){

    while(!vazia()){
        desempilha();
    }

}