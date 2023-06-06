#include <Lista.h>

using namespace std;

Lista::Lista(){
    
    primeiro = new CelulaLista(0, 0);
    ultimo = primeiro;
    tam = 0;

}

int Lista::getTam(){
    return tam;
}

CelulaLista* Lista::getPrimeiro(){
    return primeiro;
}

Ponto* Lista::menorPonto(){

    Ponto* menorPonto = primeiro->getPonto();
    CelulaLista* aux = primeiro;

    bool lopou = false;

    while(!lopou){

        if(aux->getPonto()->getX() < menorPonto->getX()){
            menorPonto = aux->getPonto();
        } else if(aux->getPonto()->getX() == menorPonto->getX()){
            if(aux->getPonto()->getY() < menorPonto->getY()){
                menorPonto = aux->getPonto();
            }
        }

        aux = aux->getProx();

        if(aux == primeiro){
            lopou = true;
        }

    }

    return menorPonto;

}

Ponto* Lista::pontoNaPosicao(int p){

    CelulaLista* aux = primeiro;

    for(int i = 0; i < p; i++){

        aux = aux->getProx();

    }

    return aux->getPonto();

}

void Lista::insereFinal(int _x, int _y){
    
    CelulaLista *nova = new CelulaLista(_x, _y);

    if(tam == 0){

        delete primeiro;

        primeiro = nova;
        ultimo = primeiro;

    } else {
        ultimo->setProx(nova);
        ultimo = nova;
        nova->setProx(primeiro);
    }

    tam++;

}

void Lista::imprime(){
    
    CelulaLista *celula;
    celula = primeiro;

    bool lopou = false;

    while(!lopou){
        
        cout << celula->getPonto()->getX() << " " << celula->getPonto()->getY() << endl;
        celula = celula->getProx();

        if(celula == primeiro){
            lopou = true;
        }

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
    tam = 0;

}