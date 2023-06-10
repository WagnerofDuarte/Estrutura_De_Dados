#include <Ponto.h>
#include <math.h>

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

void Ponto::setX(int _x){
    x = _x;
}

void Ponto::setY(int _y){
    y = _y;
}

void Ponto::calcularAngulo(Ponto* ponto_zero){
    
    int deltX = x - ponto_zero->getX();
    int deltY = y - ponto_zero->getY();

    double _angulo = atan2(deltY, deltX);

    angulo = _angulo;

}

void Ponto::setAngulo(double _angulo){
    angulo = _angulo;

}

double Ponto::getAngulo(){
    return angulo;
}
