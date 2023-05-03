#include <Expressao.h>

Expressao::Expressao(string nomeDoArquivo){

    infixaOuPosfixa = 1;//validacaoDeExpressao(nomeDoArquivo);

    if(infixaOuPosfixa == 0){

        return;

    } else {

        expressao = new Lista();
        posFixa = new Fila();
        inFixa = new Arvore();

        armazenaExpressao(nomeDoArquivo);

    }
}

Expressao::~Expressao() {

}

int Expressao::validacaoDeExpressao(string nomeDoArquivo){
    
}

bool Expressao::eNumero(char c) {
    if(c == '0' || c == '1' || c == '2' || c == '3' || c == '4' || c == '5' || c == '6' || c == '7' || c == '8' || c == '9'){
        return true;
    } else {
        return false;
    }
}

int Expressao::armazenaExpressao(string nomeDoArquivo){

    /* Armazena a expressao em uma lista encadeada */
    for(int i = 0; i < nomeDoArquivo.size(); i++){

        char c = nomeDoArquivo[i];
        expressao->insereFinal(c);

    }

    expressao->imprime();

    CelulaLista* aux = new CelulaLista();
    aux = expressao->getPrimeiro();

    if(infixaOuPosfixa == 1) { // posfixa

        while(aux != NULL){

            char caractere = aux->getCaractere();

            if(eNumero(caractere)){
                aux = converteNum(aux);
                posFixa->enfileira(caractere, aux->getNum());

            } else if(caractere != ' ') {
                posFixa->enfileira(caractere, 0);
                aux = aux->getProx();

            } else {

                aux = aux->getProx();

            }
        }

    } else { // infixa

        while(aux != NULL){

            char caractere = aux->getCaractere();

            if(eNumero(caractere)){
                aux = converteNum(aux);
                inFixa->InsereExpressaoPosFixa(inFixa->raiz, caractere, aux->getNum());

            } else {
                inFixa->InsereExpressaoPosFixa(inFixa->raiz, caractere, 0);
                aux = aux->getProx();

            }
        }
    }

}

int Expressao::convertePraPosFixa(){
    

}

int Expressao::convertePraInFixa(){
    
}

int Expressao::resolvePosFixa(){
    
}

int Expressao::resolveInFixa(){

    resultadoExpressao = inFixa->gerarResultado(inFixa->raiz);

    cout << "Resultado: " << resultadoExpressao << endl;
    
}

CelulaLista* Expressao::converteNum(CelulaLista* celula){

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