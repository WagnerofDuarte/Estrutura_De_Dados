#include <Lista.h>
#include <iostream>

using namespace std;

Lista::Lista(){

    primeiro = new CelulaLista();
    ultimo = primeiro;
    tamanho = 0;

}

Lista::~Lista(){

}

int Lista::getTamanho(){
    return tamanho;
}


CelulaLista* Lista::getPrimeiro(){
    return primeiro;
}

CelulaLista* Lista::getUltimo(){
    return ultimo;
}

void Lista::insereFinal(char caractere){

    CelulaLista *nova;

    nova = new CelulaLista();
    nova->setCaractere(caractere);
    ultimo->setProx(nova);
    ultimo = nova;
    tamanho++;

}

void Lista::imprime(){

    CelulaLista *celula;

    celula = primeiro->getProx();

    while(celula != NULL){

        cout << celula->getCaractere() << endl;
        celula = celula->getProx();

    }

}

void Lista::limpa(){

    CelulaLista *p;

    p = primeiro->getProx();

    while(p != NULL){

        primeiro->setProx(p->getProx());
        delete p;
        p = primeiro->getProx();

    }

    ultimo = primeiro;
    tamanho = 0;

}
