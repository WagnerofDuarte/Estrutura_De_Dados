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

bool Arvore::InsereExpressaoPosFixa(NoArvore* no, char caractere){

    if(no == NULL){

        no = new NoArvore(caractere);

    } else {

        if(caractere == '('){

            cout << "Entrou no (" << endl;
            
            if(eOperador(no->getCaractere())){

                InsereExpressaoPosFixa(no->getDir(), caractere);
                

            } else {

                if(no->getEsq() == NULL){

                    InsereExpressaoPosFixa(no->getEsq(), caractere);
                    

                } else {

                    if(no->getEsq()->getCaractere() == '(' || eOperador(no->getEsq()->getCaractere())){

                        InsereExpressaoPosFixa(no->getEsq(), caractere);
                        

                    } else {
                        //Expressao Errada!
                    }

                }

            }

        } else if(eNumero(caractere)) {

            cout << "Entrou no NUM" << endl;

            if(no->getEsq() == NULL && no->getDir() == NULL){

                if(no->getCaractere() == '('){

                    no->setCaractere(caractere);

                    return true;

                } else {
                    //Volta pro Pai
                    return false;
                }

            } else {

                if(!InsereExpressaoPosFixa(no->getEsq(), caractere)){

                    InsereExpressaoPosFixa(no->getDir(), caractere);

                }

            }

        } else if(eOperador(caractere)){

            cout << "Entrou no Operador" << endl;

            if(no->getDir() == NULL){

                if(no->getEsq() == NULL){

                    //Ta errado

                } else {

                    if(no->getEsq()->getCaractere() == '('){

                        InsereExpressaoPosFixa(no->getEsq(), caractere);
                        

                    } else {

                        no->setCaractere(caractere);

                    }

                }

            } else {

                InsereExpressaoPosFixa(no->getDir(), caractere);
                
            }
        }
    }
    return true;
}

void Arvore::leInFixa(NoArvore* no){

    if(no != NULL){
        leInFixa(no->getEsq());
        cout << "Char do Nó: " << no->getCaractere() << endl;
        leInFixa(no->getDir());
    } else {
        cout << "No nulo" << endl;
    }

}

void Arvore::limpa(){


}