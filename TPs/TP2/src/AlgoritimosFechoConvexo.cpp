#include <AlgoritimosFechoConvexo.h>

using namespace std;

AlgoritimosFechoConvexo::AlgoritimosFechoConvexo(){


}

Lista* AlgoritimosFechoConvexo::marchaDeJarvis(Lista* listaDePontos){

    Ponto* na_envoltoria = listaDePontos->menorPonto();
    Lista* pontosDaEnvoltoria = new Lista();

    bool lopou = false;

    while(!lopou){

        pontosDaEnvoltoria->insereFinal(na_envoltoria->getX(), na_envoltoria->getY());
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

    return pontosDaEnvoltoria;

}

void AlgoritimosFechoConvexo::scanDeGraham(){



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