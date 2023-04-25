#include <Expressao.h>

Expressao::Expressao(string _expressaoString){
    expressaoString = _expressaoString;
    infixaOuPosfixa = validarExpressao();
    expressao = Fila();
    expressao.enfileira(-1);
    
    transformarExpressaoEmFila(); //Instanciar a TAD que ira armazenar a expressao
}

Expressao::~Expressao() {

}

int Expressao::validarExpressao(){

}

int Expressao::convertePraPosFixa(){
    

}

int Expressao::convertePraInFixa(){
    
}

int Expressao::ResolvePosFixa(){
    
}

int Expressao::ResolveInFixa(){
    
}

void Expressao::transformarExpressaoEmFila(){


}