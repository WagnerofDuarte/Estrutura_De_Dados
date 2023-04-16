#include <filaCircular.h>

FilaCircular::FilaCircular(){

    frente = 0;
    tras = 0;
    tamanho = 0;

}

int FilaCircular::getTamanho(){
    return tamanho;
}
int FilaCircular::getMAXTAM(){
    return MAXTAM;
}

void FilaCircular::enfileira(int item){

    if(tamanho == MAXTAM){
        throw "Fila Cheia!";
    }

    itens[tras] = item;
    tras = (tras + 1) % MAXTAM;
    tamanho++;

}

int FilaCircular::desenfileira(){

    int aux;

    if(tamanho == 0){
        throw "Fila Vazia!";
    }

    aux = itens[frente];
    frente = (frente + 1) % MAXTAM;
    tamanho--;

    return aux;

}
void FilaCircular::limpa(){

    frente = 0;
    tras = 0;
    tamanho = 0;

}