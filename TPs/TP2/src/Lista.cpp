#include <Lista.h>

using namespace std;

Lista::Lista(bool _ponto_ou_reta){

    ponto_ou_reta = _ponto_ou_reta;

    if(ponto_ou_reta){

        primeiro = new CelulaListaPonto(0, 0);
        ultimo = primeiro;

        primeiraReta = NULL;
        ultimaReta = NULL;

    } else {

        primeiro = NULL;
        ultimo = NULL;

        primeiraReta = new CelulaListaReta(NULL, NULL);
        ultimaReta = primeiraReta;
    }

    tam = 0;

}

int Lista::getTam(){
    return tam;
}

CelulaListaPonto* Lista::getPrimeiro(){
    return primeiro;
}

CelulaListaReta* Lista::getPrimeiraReta(){
    return primeiraReta;
}

CelulaListaPonto* Lista::getUltimo(){
    return ultimo;
}

void Lista::setPrimeiro(CelulaListaPonto* celula){
    primeiro = celula;
}

void Lista::setUltimo(CelulaListaPonto* celula){
    ultimo = celula;
}

Ponto* Lista::menorPontoX(){

    Ponto* menorPonto = primeiro->getPonto();
    CelulaListaPonto* aux = primeiro;

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

Ponto* Lista::menorPontoY(){

    Ponto* menorPonto = primeiro->getPonto();
    CelulaListaPonto* aux = primeiro;

    bool lopou = false;

    while(!lopou){

        if(aux->getPonto()->getY() < menorPonto->getY()){
            menorPonto = aux->getPonto();
        } else if(aux->getPonto()->getY() == menorPonto->getY()){
            if(aux->getPonto()->getX() < menorPonto->getX()){
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

    CelulaListaPonto* aux = primeiro;

    for(int i = 0; i < p; i++){

        aux = aux->getProx();

    }

    return aux->getPonto();

}

Reta* Lista::retaNaPosicao(int p){

    CelulaListaReta* aux = primeiraReta;

    for(int i = 0; i < p; i++){

        aux = aux->getProx();

    }

    return aux->getReta();

}

CelulaListaPonto* Lista::celulaNaPosicao(int p){

    CelulaListaPonto* aux = primeiro;

    for(int i = 0; i < p; i++){

        aux = aux->getProx();

    }

    return aux;

}

void Lista::insereFinal(int _x, int _y, Ponto* A, Ponto* B){

    if(ponto_ou_reta){

        CelulaListaPonto *nova = new CelulaListaPonto(_x, _y);

        if(tam == 0){

            delete primeiro;

            primeiro = nova;
            ultimo = primeiro;

        } else {
            ultimo->setProx(nova);
            ultimo = nova;
            nova->setProx(primeiro);
        }

    } else {

        CelulaListaReta *nova = new CelulaListaReta(A,B);

        if(tam == 0){

            delete primeiraReta;

            primeiraReta = nova;
            ultimaReta = primeiraReta;

        } else {
            ultimaReta->setProx(nova);
            ultimaReta = nova;
            nova->setProx(primeiraReta);
        }

    }

    tam++;

}

void Lista::insereInicio(int _x, int _y, Ponto* A, Ponto* B){

    if(ponto_ou_reta){

        CelulaListaPonto *nova = new CelulaListaPonto(_x, _y);

        if(tam == 0){

            delete primeiro;

            primeiro = nova;
            ultimo = primeiro;

        } else {
            nova->setProx(primeiro);
            primeiro = nova;
            ultimo->setProx(primeiro);
        }

    } else {

        CelulaListaReta *nova = new CelulaListaReta(A,B);

        if(tam == 0){

            delete primeiraReta;

            primeiraReta = nova;
            ultimaReta = primeiraReta;

        } else {
            nova->setProx(primeiraReta);
            primeiraReta = nova;
            ultimaReta->setProx(primeiraReta);
        }

    }
    
    tam++; 
}

void Lista::removeInicio(){

    CelulaListaPonto* aux = primeiro->getProx();
    delete primeiro;
    primeiro = aux;
    ultimo->setProx(primeiro);
    tam--;


}

void Lista::imprime(){

    cout << retaNaPosicao(tam-1)->getPontoA()->getX() << " " << retaNaPosicao(tam-1)->getPontoA()->getY() << endl;

    for(int i = tam-1; i >= 0; i--){

        cout << retaNaPosicao(i)->getPontoB()->getX() << " " << retaNaPosicao(i)->getPontoB()->getY() << endl;

    }

    cout << endl;

}

void Lista::limpa(){
    
    CelulaListaPonto *p;

    p = primeiro->getProx();

    while(p != NULL){

        primeiro->setProx(p->getProx());
        delete p;
        p = primeiro->getProx();

    }

    ultimo = primeiro;
    tam = 0;

}