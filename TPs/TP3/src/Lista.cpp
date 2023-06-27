#include <Lista.h>

using namespace std;

Lista::Lista(){
    
    primeiro = new CelulaLista('0', false);
    ultimo = primeiro;
    tam = 0;

}

void Lista::insereFinal(char _caractere, bool _caractereValido){
    
    CelulaLista *nova = new CelulaLista(_caractere, _caractereValido);

    if(tam == 0){
        delete primeiro;
        primeiro = nova;
        ultimo = primeiro;
    } else {
        ultimo->setProx(nova);
        ultimo = nova;
    }

    tam++;

}

void Lista::removeInicio(){
    
    CelulaLista* aux = primeiro->getProx();
    delete primeiro;
    primeiro = aux;
    tam--;

}

void Lista::inserePosicao(int posicao){
    


}

CelulaLista* Lista::getPosicao(int posicao){

    CelulaLista* aux = primeiro;

    for(int i = 0; i <= posicao; i++){
        aux = aux->getProx();
    }

    return aux;

}


int Lista::getTam(){
    return tam;
}

CelulaLista* Lista::getPrimeiro(){
    return primeiro;
}




/*------------------------------*/


void Lista::imprime(){

    CelulaLista* aux = primeiro;

    while(aux != NULL){
        cout << endl << aux->getCaractere();
        aux = aux->getProx();
    }

}