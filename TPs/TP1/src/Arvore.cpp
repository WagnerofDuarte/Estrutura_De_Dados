#include <Arvore.h>
#include <iostream>

using namespace std;

Arvore::Arvore() {

    raiz = NULL;

} 

Arvore::~Arvore() {

    limpa();

}

NoArvore* Arvore::getRaiz(){
    return raiz;
}

bool eNumero(char c) {
    if(c == '0' || c == '1' || c == '2' || c == '3' || c == '4' || c == '5' || c == '6' || c == '7' || c == '8' || c == '9'){
        return true;
    } else {
        return false;
    }
}

bool eOperador(char c) {

    if(c == '+' || c == '-' || c == '*' || c == '/'){
        return true;
    } else {
        return false;
    }

}

bool Arvore::InsereExpressaoPosFixa(NoArvore* &no, char caractere, double num){

    if(no == NULL){

        if(caractere == '('){
            no = new NoArvore(caractere);
        }

    } else {

        if(caractere == '('){
            
            if(eOperador(no->getCaractere())){

                InsereExpressaoPosFixa(no->dir, caractere, 0);

            } else {

                if(no->esq == NULL){

                    InsereExpressaoPosFixa(no->esq, caractere, 0);

                } else {

                    if(no->esq->getCaractere() == '(' || eOperador(no->esq->getCaractere())){

                        InsereExpressaoPosFixa(no->esq, caractere, 0);
                        

                    } else {
                        //Expressao Errada!
                    }

                }

            }

        } else if(eNumero(caractere)) {

            if(no->esq == NULL && no->dir == NULL){ // É uma folha?

                if(no->getCaractere() == '('){

                    no->setCaractere('0');
                    no->setNum(num);

                    return true;

                } else {
                    //Volta pro Pai
                    return false;
                }

            } else { // Se não for folha, percorra a arvore

                if(InsereExpressaoPosFixa(no->esq, caractere, num)){
                    
                    return true;

                } else {

                    InsereExpressaoPosFixa(no->dir, caractere, num);
                    return false;


                }

            }

        } else if(eOperador(caractere)){

            if(no->dir == NULL){

                if(no->esq != NULL){

                    if(eNumero(no->esq->getCaractere())){

                        if(no->getCaractere() == '('){

                            no->setCaractere(caractere);

                            return true;

                        } else {

                            if(InsereExpressaoPosFixa(no->esq, caractere, 0)){
                                return true;
                            } else {
                                return false;
                            }

                        }
                    }

                    if(eOperador(no->esq->getCaractere()) || no->esq->getCaractere() == '('){

                        if(!InsereExpressaoPosFixa(no->esq, caractere, 0)){

                            no->setCaractere(caractere);
                            return true;

                        } else {
                
                            return true;
                        }
                    }

                } else {

                    
                    return false;

                }
            } else {

                if(InsereExpressaoPosFixa(no->dir, caractere, 0)){
                    return true;
                } else {
                    return false;
                }
            }
        }

    } 
}

void Arvore::leInFixa(NoArvore* no){

    if(no != NULL){
        cout << "(";
        cout << " ";
        leInFixa(no->esq);
        if(eNumero(no->getCaractere())){
            cout << no->getNum();
        } else {
            cout << " ";
            cout << no->getCaractere();
            cout << " ";
        }
        leInFixa(no->dir);
        cout << " ";
        cout << ")";
    }

}

void Arvore::limpa(){


}

double Arvore::gerarResultado(NoArvore* &no){

    if(eNumero(no->esq->getCaractere())){

        if(eNumero(no->dir->getCaractere())){

            return calculadora(no->getCaractere(), (no->esq->getNum()), (no->dir->getNum()));

        } else {

            return calculadora(no->getCaractere(), (no->esq->getNum()), gerarResultado(no->dir));

        }

    } else {

        if(eNumero(no->dir->getCaractere())){

            return calculadora(no->getCaractere(), gerarResultado(no->esq), (no->dir->getNum()));

        } else {

            return calculadora(no->getCaractere(), gerarResultado(no->esq), gerarResultado(no->dir));

        }

    }
 
}

double Arvore::calculadora(char operador, double p1, double p2){

    if(operador == '+'){
        return p1 + p2;
    } else if(operador == '-'){
        return p1 - p2; 
    } else if(operador == '*'){
        return p1 * p2;
    } else if(operador == '/'){
        return p1 / p2;
    } else {
        return 0;
    }

}