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

void Pilha::empilha(char caractere){

    CelulaPilha *celula;
    celula = new CelulaPilha(caractere, topo);
    topo = celula;

    cout << "Empilhou: " << topo->getCaractere() << endl;

    tamanho++;

}

char Pilha::desempilha(){

    char caractere;
    CelulaPilha *celula;

    if(tamanho == 0){
        return 0;
    }

    caractere = topo->getCaractere();
    celula = topo;
    topo = topo = topo->getProx();

    cout << "Desempilhou: " << caractere << endl;

    delete celula;
    tamanho--;

    return caractere;

}
void Pilha::limpa(){

    while(!vazia()){
        desempilha();
    }

}