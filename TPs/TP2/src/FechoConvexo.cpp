#include <FechoConvexo.h>

using namespace std;

FechoConvexo::FechoConvexo(){
    retasDoFecho = new Lista(false);
}

void FechoConvexo::imprimirFecho(){
    retasDoFecho->imprime();
}

void FechoConvexo::adicionarReta(Reta* reta){
    retasDoFecho->insereFinal(0, 0, reta->getPontoA(), reta->getPontoB());
}
