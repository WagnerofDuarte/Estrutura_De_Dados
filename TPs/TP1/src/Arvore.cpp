#include <Arvore.h>
#include <iostream>

using namespace std;

/*double calculadora(char operador, double p1, double p2){

    if(operador == '+'){
        return p1 + p2;
    } else if(operador == '-'){
        return p1 - p2;
    } else if(operador == '*'){
        return p1 * p2;
    } else if(operador == '/'){
        return p1 / p2;
    }

}*/

/*bool eNumero(char c) {
    if(c == '0' || c == '1' || c == '2' || c == '3' || c == '4' || c == '5' || c == '6' || c == '7' || c == '8' || c == '9'){
        return true;
    } else {
        return false;
    }
}*/

/*bool eOperador(char c) {

    if(c == '+' || c == '-' || c == '*' || c == '/'){
        return true;
    } else {
        return false;
    }

}*/

Arvore::Arvore() {

    raiz = NULL;
    utilidades = new Utilidades();

}

Arvore::~Arvore() {

    limpa();

}

NoArvore* Arvore::getRaiz(){
    return raiz;
}

bool Arvore::InsereExpressaaoInFixa(NoArvore* &no, char caractere, double num){

    bool acabou = false;

    if(no == NULL){

        if(caractere == '('){
            no = new NoArvore(caractere);
        }

    } else {

        if(caractere == '('){
            
            if(utilidades->eOperador(no->getCaractere())){

                InsereExpressaaoInFixa(no->dir, caractere, 0);
                

            } else {

                if(no->esq == NULL){

                    InsereExpressaaoInFixa(no->esq, caractere, 0);

                } else {

                    if(no->esq->getCaractere() == '(' || utilidades->eOperador(no->esq->getCaractere())){

                        InsereExpressaaoInFixa(no->esq, caractere, 0);
                        

                    } else {
                        //Expressao Errada!
                    }

                }

            }

        } else if(utilidades->eNumero(caractere)) {

            if(no->esq == NULL && no->dir == NULL){ // É uma folha?

                if(no->getCaractere() == '('){

                    no->setCaractere('0');
                    no->setNum(num);

                    acabou = true;

                    return true;

                } else {
                    //Volta pro Pai
                    return false;
                }

            } else { // Se não for folha, percorra a arvore

                if(InsereExpressaaoInFixa(no->esq, caractere, num)){
                    
                    return true;

                } else {

                    InsereExpressaaoInFixa(no->dir, caractere, num);
                    return false;


                }

            }

        } else if(utilidades->eOperador(caractere)){

            if(no->dir == NULL){

                if(no->esq != NULL){

                    if(utilidades->eNumero(no->esq->getCaractere())){

                        if(no->getCaractere() == '('){

                            no->setCaractere(caractere);

                            return true;

                        } else {

                            if(InsereExpressaaoInFixa(no->esq, caractere, 0)){
                                return true;
                            } else {
                                return false;
                            }

                        }
                    }

                    if(utilidades->eOperador(no->esq->getCaractere()) || no->esq->getCaractere() == '('){

                        if(!InsereExpressaaoInFixa(no->esq, caractere, 0)){

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

                if(InsereExpressaaoInFixa(no->dir, caractere, 0)){
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
        if(utilidades->eNumero(no->getCaractere())){
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

    if(utilidades->eNumero(no->esq->getCaractere())){

        if(utilidades->eNumero(no->dir->getCaractere())){

            return utilidades->calculadora(no->getCaractere(), (no->esq->getNum()), (no->dir->getNum()));

        } else {

            return utilidades->calculadora(no->getCaractere(), (no->esq->getNum()), gerarResultado(no->dir));

        }

    } else {

        if(utilidades->eNumero(no->dir->getCaractere())){

            return utilidades->calculadora(no->getCaractere(), gerarResultado(no->esq), (no->dir->getNum()));

        } else {

            return utilidades->calculadora(no->getCaractere(), gerarResultado(no->esq), gerarResultado(no->dir));

        }

    }

}