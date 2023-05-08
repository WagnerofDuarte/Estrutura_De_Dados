#include <Fila.h>
#include <iostream>

using namespace std;

Fila::Fila() {

    frente = new CelulaFila(0, 0, NULL);
    tras = frente;
    tamanho = 0;
}

Fila::~Fila() {

    limpa();
    //delete frente;

}

int Fila::getTamanho(){
    return tamanho;
}

bool Fila::vazia(){

    if(tamanho == 0){
        return true;
    } else {
        return false;
    }

}

char Fila::getFrente(){

    return frente->getCaractere();

}

double Fila::getFrenteNumero(){

    return frente->getNum();

}

void Fila::enfileira(char _caractere, double _num){

    CelulaFila *novaCelula;

    novaCelula = new CelulaFila(_caractere, _num, NULL);
    tras->setProx(novaCelula);
    tras = novaCelula;
    tamanho++;

}

char Fila::desenfileira(){

    CelulaFila *celula;
    char caractere;

    if(tamanho == 0){
        return 0;
    }

    caractere = frente->getProx()->getCaractere();
    celula = frente;
    frente = frente->getProx();

    delete celula;
    tamanho --;

    return caractere;

}

double Fila::desenfileraDouble(){

    CelulaFila *celula;
    double num;

    if(tamanho == 0){
        return 0;
    }

    num = frente->getProx()->getNum();
    celula = frente;
    frente = frente->getProx();

    delete celula;
    tamanho --;

    return num;

}

bool Fila::eNumero(char c) {
    if(c == '0' || c == '1' || c == '2' || c == '3' || c == '4' || c == '5' || c == '6' || c == '7' || c == '8' || c == '9'){
        return true;
    } else {
        return false;
    }
}

double Fila::gerarResultado(){

    Pilha* pilha = new Pilha();
    double resultado;

    int i = 0;

    while(tamanho > 0 || pilha->getTamanho() > 2){

        if(eNumero(frente->getCaractere()) /* desenfileira retornar um num */){
            /* empilhar o numero na pilha */
            pilha->empilha(frente->getCaractere(), frente->getNum());
            i++;
        } else {
            /* Pq achou um operador */
            double p1, p2;
            p2 = pilha->desempilha();
            p1 = pilha->desempilha();
            resultado = calculadora(frente->getCaractere(), p1, p2);
            pilha->empilha(resultado, resultado);
            i--;
            /* Faca a conta em questao desempilhando os dois primeiros numeros*/
        }

        desenfileira();
    }

    pilha->desempilha();
    pilha->desempilha();

    return resultado;

}

void Fila::leFila(){

    CelulaFila* celula = frente->getProx();

    while(celula != NULL){

        if(celula->getCaractere() == '0'){
            cout << celula->getNum() << " ";
        } else {
            cout << celula->getCaractere() << " ";
        }
        
        celula = celula->getProx();
    }

    cout << endl;

}

void Fila::limpa(){

    CelulaFila *aux;

    aux = frente->getProx();

    if(aux == NULL){
        
    } else {

        while (aux != NULL){
            frente->setProx(aux->getProx());
            delete aux;
            aux = frente->getProx();
        }   

    tamanho = 0;
    tras = frente;
    }
}

double Fila::calculadora(char operador, double p1, double p2){

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