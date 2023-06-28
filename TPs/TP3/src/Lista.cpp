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

void Lista::ordena(){

    for(int i =  1; i < tam; i++){
        CelulaLista* celula_aux = getPosicao(i);
        for(int j = 0; j < i; j++){
            if(getPosicao(j)->getFrequencia() > celula_aux->getFrequencia()){ 
                if(i == tam - 1){
                    ultimo = getPosicao(i - 1);
                    if(j == 0){
                        primeiro = celula_aux;
                        break;
                    }
                }

                getPosicao(i-1)->setProx(celula_aux->getProx());
                celula_aux->setProx(getPosicao(j));

                if(j != 0){
                    getPosicao(j-1)->setProx(celula_aux);
                } else {
                    primeiro = celula_aux;
                }

                break;
            }
        }
    }
}

CelulaLista* Lista::getPosicao(int posicao){

    CelulaLista* aux = primeiro;

    for(int i = 0; i < posicao; i++){
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
        cout << endl << aux->getCaractere() << " " << aux->getFrequencia();
        aux = aux->getProx();
    }

    cout << endl;
    cout << endl;

}