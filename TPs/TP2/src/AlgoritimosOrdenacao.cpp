#include <AlgoritimosOrdenacao.h>
#include <iostream>

using namespace std;

AlgoritimosDeOrdenacao::AlgoritimosDeOrdenacao(Lista* lista){

    calculaAngulos(lista);

}

void AlgoritimosDeOrdenacao::insertionSort(Lista* lista){

    int tamanho = lista->getTam();

    for(int i = 1; i < tamanho; i++){
        Ponto* ponto_aux = lista->pontoNaPosicao(i);

        for(int j = 0; j < i; j++){
            if(lista->pontoNaPosicao(j)->getAngulo() >= ponto_aux->getAngulo()){

                CelulaListaPonto* celula_aux = lista->celulaNaPosicao(i);

                // Caso: se o ultimo elemento mudar de posicao
                if(i == tamanho - 1){
                    lista->setUltimo(lista->celulaNaPosicao(i - 1));
                    // Caso: se o ultimo elemento mudar de posicao, e for pra primeira posicao
                    if(j == 0){
                        lista->setPrimeiro(celula_aux);
                        break;
                    }
                }

                lista->celulaNaPosicao(i - 1)->setProx(celula_aux->getProx());
                celula_aux->setProx(lista->celulaNaPosicao(j));
 
                if(j != 0){
                    lista->celulaNaPosicao(j-1)->setProx(celula_aux);
                //Caso: se o primeiro elemento for trocado
                } else {
                    lista->getUltimo()->setProx(celula_aux);
                    lista->setPrimeiro(celula_aux);
                }
                break;
            }
        }
    }
}

void AlgoritimosDeOrdenacao::mergeSort(Lista* lista, int inicio, int fim){

    if(fim - inicio > 1){

        int meio = ((fim + inicio)/2);
        mergeSort(lista, inicio, meio);
        mergeSort(lista, (meio), fim);
        merge(lista, inicio, meio, fim);

    }

}

void AlgoritimosDeOrdenacao::merge(Lista* lista, int inicio, int meio, int fim){

    Lista* esq = new Lista(true);
    Lista* dir = new Lista(true);

    for(int i = inicio; i < meio; i++){
        esq->insereFinal(lista->celulaNaPosicao(i)->getPonto()->getX(), lista->celulaNaPosicao(i)->getPonto()->getY(), NULL, NULL);
        esq->getUltimo()->getPonto()->setAngulo(lista->celulaNaPosicao(i)->getPonto()->getAngulo());
    }

    for(int i = meio; i < fim; i++){
        dir->insereFinal(lista->celulaNaPosicao(i)->getPonto()->getX(), lista->celulaNaPosicao(i)->getPonto()->getY(), NULL, NULL);
        dir->getUltimo()->getPonto()->setAngulo(lista->celulaNaPosicao(i)->getPonto()->getAngulo());
    }

    int topo_esq = 0;
    int topo_dir = 0;

    for(int i = inicio; i < fim; i++){

        if(topo_esq >= esq->getTam()){

            lista->pontoNaPosicao(i)->setX(dir->pontoNaPosicao(topo_dir)->getX());
            lista->pontoNaPosicao(i)->setY(dir->pontoNaPosicao(topo_dir)->getY());
            lista->pontoNaPosicao(i)->setAngulo(dir->pontoNaPosicao(topo_dir)->getAngulo());
            topo_dir++;

        } else if(topo_dir >= dir->getTam()){

            lista->pontoNaPosicao(i)->setX(esq->pontoNaPosicao(topo_esq)->getX());
            lista->pontoNaPosicao(i)->setY(esq->pontoNaPosicao(topo_esq)->getY());
            lista->pontoNaPosicao(i)->setAngulo(esq->pontoNaPosicao(topo_esq)->getAngulo());
            topo_esq++;

        } else if(esq->pontoNaPosicao(topo_esq)->getAngulo() < dir->pontoNaPosicao(topo_dir)->getAngulo()){

            lista->pontoNaPosicao(i)->setX(esq->pontoNaPosicao(topo_esq)->getX());
            lista->pontoNaPosicao(i)->setY(esq->pontoNaPosicao(topo_esq)->getY());
            lista->pontoNaPosicao(i)->setAngulo(esq->pontoNaPosicao(topo_esq)->getAngulo());
            topo_esq++;

        } else {

            lista->pontoNaPosicao(i)->setX(dir->pontoNaPosicao(topo_dir)->getX());
            lista->pontoNaPosicao(i)->setY(dir->pontoNaPosicao(topo_dir)->getY());
            lista->pontoNaPosicao(i)->setAngulo(dir->pontoNaPosicao(topo_dir)->getAngulo());
            topo_dir++;

        }
    }
}

int AlgoritimosDeOrdenacao::numNaPosicao(double _num, int digito){

    int pot = 1;
    int num = _num * 1000000;

    for(int i = 0; i < digito; i++){
        pot = pot * 10;
    }

    return (num/pot) % 10;
}

Lista* AlgoritimosDeOrdenacao::coutingSort(Lista* lista, int digito){

    Lista* lista_aux = new Lista(true);

    for(int k = 0; k < 10; k++){
        for(int j = 0; j < lista->getTam(); j++){
            if(numNaPosicao(lista->pontoNaPosicao(j)->getAngulo(), digito) == k){
                lista_aux->insereFinal(lista->pontoNaPosicao(j)->getX(), lista->pontoNaPosicao(j)->getY(), NULL, NULL);
                lista_aux->getUltimo()->getPonto()->setAngulo(lista->pontoNaPosicao(j)->getAngulo());
            }
        }
    }

    return lista_aux;
}

void AlgoritimosDeOrdenacao::radixSort(Lista* lista){

    Lista *lista_ordenada = coutingSort(lista, 0);

    for(int i = 1; i < 7; i++){
        lista_ordenada = coutingSort(lista_ordenada, i);
    }

    lista->setPrimeiro(lista_ordenada->getPrimeiro());
    lista->setUltimo(lista_ordenada->getUltimo());
}

void AlgoritimosDeOrdenacao::calculaAngulos(Lista* lista){

    Ponto* menorPonto = lista->menorPontoY();
    int tam = lista->getTam();

    for(int i = 0; i < tam; i++){

        lista->pontoNaPosicao(i)->calcularAngulo(menorPonto);

    }
}