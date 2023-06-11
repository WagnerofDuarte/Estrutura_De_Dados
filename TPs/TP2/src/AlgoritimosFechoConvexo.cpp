#include <AlgoritimosFechoConvexo.h>

using namespace std;

FechoConvexo* AlgoritimosFechoConvexo::marchaDeJarvis(Lista* listaDePontos){

    Ponto* na_envoltoria = listaDePontos->menorPontoX();
    Lista* pontosDaEnvoltoria = new Lista(true);

    bool lopou = false;

    while(!lopou){

        pontosDaEnvoltoria->insereFinal(na_envoltoria->getX(), na_envoltoria->getY(), NULL, NULL);
        Ponto* prox_ponto = listaDePontos->getPrimeiro()->getPonto();

        for(int i = 0; i < listaDePontos->getTam(); i++){
            int o = orientacao(na_envoltoria, prox_ponto, listaDePontos->pontoNaPosicao(i));
            if((prox_ponto->getX() == na_envoltoria->getX() &&  prox_ponto->getY() == na_envoltoria->getY()) || o == 1){
                prox_ponto = listaDePontos->pontoNaPosicao(i);
            }

        }
        na_envoltoria = prox_ponto;

        if(na_envoltoria->getX() == pontosDaEnvoltoria->getPrimeiro()->getPonto()->getX() && na_envoltoria->getY() == pontosDaEnvoltoria->getPrimeiro()->getPonto()->getY()){
            lopou = true;
        }
    }

    FechoConvexo* fecho = new FechoConvexo();

    for(int i = 1; i < pontosDaEnvoltoria->getTam(); i++){
        Reta* reta_aux = new Reta(pontosDaEnvoltoria->pontoNaPosicao(i), pontosDaEnvoltoria->pontoNaPosicao(i-1));
        fecho->adicionarReta(reta_aux);
    }

    return fecho;
}

FechoConvexo* AlgoritimosFechoConvexo::scanDeGraham(Lista* listaDePontos, int ord){

    AlgoritimosDeOrdenacao* algoritimosDeOrdenacao = new AlgoritimosDeOrdenacao(listaDePontos);
    Lista* pontosDaEnvoltoria = new Lista(true);

    if(ord == 1){
        algoritimosDeOrdenacao->insertionSort(listaDePontos);
    } else if(ord == 2){
        algoritimosDeOrdenacao->mergeSort(listaDePontos, 0, listaDePontos->getTam());
    } else {
        algoritimosDeOrdenacao->radixSort(listaDePontos);
    }

    for(int i = 0; i < listaDePontos->getTam(); i++){
        while(pontosDaEnvoltoria->getTam() >= 2 && orientacao(pontosDaEnvoltoria->pontoNaPosicao(1), pontosDaEnvoltoria->pontoNaPosicao(0), listaDePontos->pontoNaPosicao(i)) != 1){
            pontosDaEnvoltoria->removeInicio();
        }
        pontosDaEnvoltoria->insereInicio(listaDePontos->pontoNaPosicao(i)->getX(), listaDePontos->pontoNaPosicao(i)->getY(), NULL, NULL);
        pontosDaEnvoltoria->getPrimeiro()->getPonto()->setAngulo(listaDePontos->pontoNaPosicao(i)->getAngulo());
    }
    
    FechoConvexo* fecho = new FechoConvexo();

    for(int i = 1; i < pontosDaEnvoltoria->getTam(); i++){
        Reta* reta_aux = new Reta(pontosDaEnvoltoria->pontoNaPosicao(i), pontosDaEnvoltoria->pontoNaPosicao(i-1));
        fecho->adicionarReta(reta_aux);
    }

    return fecho;
}

int AlgoritimosFechoConvexo::orientacao(Ponto* p1, Ponto* p2, Ponto* p3){

    int x1 = p1->getX();
    int y1 = p1->getY();

    int x2 = p2->getX();
    int y2 = p2->getY();

    int x3 = p3->getX();
    int y3 = p3->getY();

    int _orientacao = ((y3-y2)*(x2-x1))-((y2-y1)*(x3-x2));

    if(_orientacao > 0){
        return 1;
    } else if (_orientacao < 0) {
        return -1;
    } else {
        return 0;
    }
}