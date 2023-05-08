#include <Utilidades.h>

Utilidades::Utilidades(){



}

Utilidades::~Utilidades(){


    
}

double Utilidades::calculadora(char operador, double p1, double p2){

    if(operador == '+'){
        return p1 + p2;
    } else if(operador == '-'){
        return p1 - p2;
    } else if(operador == '*'){
        return p1 * p2;
    } else if(operador == '/'){
        return p1 / p2;
    }
}


bool Utilidades::eNumero(char c){

    if(c == '0' || c == '1' || c == '2' || c == '3' || c == '4' || c == '5' || c == '6' || c == '7' || c == '8' || c == '9'){
        return true;
    } else {
        return false;
    }


}

bool Utilidades::eOperador(char c){

    if(c == '+' || c == '-' || c == '*' || c == '/'){
        return true;
    } else {
        return false;
    }


}

CelulaLista* Utilidades::converteNum(CelulaLista* celula){

    CelulaLista* aux;

    double potencia = 1;
    double num = 0;

    while(celula->getCaractere() != ',' && celula->getCaractere() != ')' && celula->getCaractere() != ' '){

        aux = celula;
        potencia = 1;

        while(aux->getProx()->getCaractere() != ',' && aux->getProx()->getCaractere() != ')' && aux->getProx()->getCaractere() != ' '){
            potencia = potencia * 10;
            aux = aux->getProx();
        }

        num = num + ((celula->getCaractere() - '0')*(potencia));
        celula = celula->getProx();

    }

    if(celula->getCaractere() == ','){

        potencia = 0.1;
        aux = celula->getProx();

        while(eNumero(aux->getCaractere())){
            num = num + ((aux->getCaractere() - '0')*(potencia));
            aux = aux->getProx();
            potencia = potencia / 10;
        }

        aux->setNum(num);
        return aux;

    } else {

        aux = aux->getProx();
        aux->setNum(num);

        return aux;

    }

}