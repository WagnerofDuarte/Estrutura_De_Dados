#include <Reta.h>

Reta::Reta(Ponto* A, Ponto* B){
    pontoA = A;
    pontoB = B;
}

Ponto* Reta::getPontoA(){
    return pontoA;
}

void Reta::setPontoA(Ponto* A){
     pontoA = A;
}

Ponto* Reta::getPontoB(){
    return pontoB;
}

void Reta::setPontoB(Ponto* B){
    pontoB = B;
}
