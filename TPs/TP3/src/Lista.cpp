#include <Lista.h>

using namespace std;

Lista::Lista(){
    
    primeiro = new CelulaLista('0', false);
    ultimo = primeiro;
    tam = 0;
}

// Insere um novo elemento ao final da lista
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

// Remove o primeiro elemento da lista
void Lista::removeInicio(){
    CelulaLista* aux = primeiro->getProx();
    delete primeiro;
    primeiro = aux;
    tam--;

}
// Remove um elemento de indíce específico da lista
void Lista::removePosicao(int posicao){
    CelulaLista* aux = getPosicao(posicao);
    getPosicao(posicao - 1)->setProx(aux->getProx());
    delete aux;
    tam--;
}
// Implementa o algorítimo do InsertionSort para ordenar a lista, usando como chave as frequncias dos caracteres
void Lista::ordena(){

    for(int i =  1; i < tam; i++){
        CelulaLista* celula_aux = getPosicao(i);
        for(int j = 0; j < i; j++){
            if(getPosicao(j)->getFrequencia() > celula_aux->getFrequencia()){ 

                getPosicao(i-1)->setProx(celula_aux->getProx());
                celula_aux->setProx(getPosicao(j));

                if(i == tam - 1){
                    ultimo = getPosicao(i - 1);
                    if(j == 0){
                        primeiro = celula_aux;
                        break;
                    }
                }

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
/* Retorna a celula de índide i da lista */
CelulaLista* Lista::getPosicao(int posicao){

    CelulaLista* aux = primeiro;
    for(int i = 0; i < posicao; i++){
        aux = aux->getProx();
    }
    return aux;
}

/* Funcao que existe para que, se caso alguma celula mude sua frequencia, sua posicao será ajustada, para que a lista
   continue ordenada*/
int Lista::reposiciona(int posicao){

    CelulaLista* queVaiMudar = getPosicao(posicao);
    CelulaLista* aux = queVaiMudar->getProx();
    if(aux == NULL){
        return -1;
    }
    if(aux->getProx() != NULL){
        while(queVaiMudar->getFrequencia() >= aux->getProx()->getFrequencia()){
            aux = aux->getProx();
            if(aux->getProx() == NULL){
                break;
            }
        }
    }
    if(primeiro == queVaiMudar){
        primeiro = queVaiMudar->getProx();
    }
    if(ultimo == aux){
        ultimo = queVaiMudar;
    }
    
    queVaiMudar->setProx(aux->getProx());
    aux->setProx(queVaiMudar);

    return 0;
}

/* Faz uma copia do objeto e seus elemntos */
void Lista::copiaLista(Lista* lista){
    CelulaLista* aux = lista->getPrimeiro();
    while(aux != NULL){
        insereFinal(aux->getCaractere(), true);
        ultimo->setFrequencia(aux->getFrequencia());
        ultimo->getArvoreFrequencias()->raiz->setFrequencia(aux->getFrequencia());
        aux = aux->getProx();
    }
}

int Lista::getTam(){
    return tam;
}

CelulaLista* Lista::getPrimeiro(){
    return primeiro;
}

CelulaLista* Lista::getUltimo(){
    return ultimo;
}