#include <Pilha.h>

Pilha::Pilha() {

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

CelulaPilha* Pilha::getTopo(){

    return topo;

}

int Pilha::getTamanho(){
    return tamanho;
}

void Pilha::empilha(char caractere, double numero){

    CelulaPilha *celula;
    celula = new CelulaPilha(caractere, numero, topo);
    topo = celula;

    tamanho++;

} 

void Pilha::empilhaLista(Lista* aux){

    CelulaPilha *celula;
    celula = new CelulaPilha('L', 0, topo);
    topo = celula;

    celula->setL(aux);

    tamanho++;

}

double Pilha::desempilha(){

    double numero;
    CelulaPilha *celula;

    if(tamanho == 0){
        return 0;
    }

    numero = topo->getNumero();
    celula = topo;
    topo = topo->getProx();
    
    delete celula;
    tamanho--;

    return numero;

}
void Pilha::limpa(){

    while(!vazia()){
        desempilha();
    }

}