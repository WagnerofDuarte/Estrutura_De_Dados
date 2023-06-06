#include <Ponto.h>

Ponto::Ponto(int _x, int _y){

    x = _x;
    y = _y;

}

int Ponto::getX(){
    return x;
}

int Ponto::getY(){
    return y;
}

void Ponto::setDistancia(double _distancia){
    distancia = _distancia;
}

double Ponto::getDistancia(){
    return distancia;
}
