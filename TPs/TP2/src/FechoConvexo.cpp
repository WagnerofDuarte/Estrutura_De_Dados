#include <FechoConvexo.h>

using namespace std;

FechoConvexo::FechoConvexo(){

    retasDoFecho = new Lista(false);

}

void FechoConvexo::imprimirFecho(){

    retasDoFecho->imprime();

}

void FechoConvexo::adicionarReta(Reta* reta){

    retasDoFecho->insereFinal(NULL, NULL, reta->getPontoA(), reta->getPontoB());

}
