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

void Lista::setUltimo(CelulaLista* celula){
    ultimo = celula;
}

void Lista::insereFinal(char caractere, double num){

    CelulaLista *nova;

    nova = new CelulaLista();
    nova->setCaractere(caractere);
    nova->setNum(num);
    ultimo->setProx(nova);
    ultimo = nova;
    tamanho++;

}

void Lista::insereInicio(char caractere, double num){

    CelulaLista *nova;

    nova = new CelulaLista();
    nova->setCaractere(caractere);
    nova->setNum(num);

    nova->setProx(primeiro->getProx());
    primeiro->setProx(nova);

    if(nova->getProx() == NULL){
        ultimo = nova;
    }

    tamanho++;
}

void Lista::concatena(Lista* _lista){

    ultimo->setProx(_lista->primeiro->getProx());
    ultimo = _lista->getUltimo();

    tamanho = tamanho + _lista->getTamanho();

}

void Lista::imprime(){

    CelulaLista *celula;

    celula = primeiro->getProx();

    while(celula != NULL){

        if(celula->getCaractere() == '0'){
            cout << celula->getNum();
        } else {
            cout << celula->getCaractere();
        }
        celula = celula->getProx();

    }

    cout << endl;

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
