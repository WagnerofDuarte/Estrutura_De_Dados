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

bool Arvore::InsereExpressaoPosFixa(NoArvore* &no, char caractere){

    bool acabou = false;

    if(no == NULL){

        if(caractere == '('){
            no = new NoArvore(caractere);
            cout << "Elemento Guardado: " << no->getCaractere() << endl;
        }

    } else {

        if(caractere == '('){

            cout << "Entrou no (" << endl;
            
            if(eOperador(no->getCaractere())){

                InsereExpressaoPosFixa(no->dir, caractere);
                

            } else {

                if(no->esq == NULL){

                    InsereExpressaoPosFixa(no->esq, caractere);

                } else {

                    if(no->esq->getCaractere() == '(' || eOperador(no->esq->getCaractere())){

                        InsereExpressaoPosFixa(no->esq, caractere);
                        

                    } else {
                        //Expressao Errada!
                    }

                }

            }

        } else if(eNumero(caractere)) {

            cout << "Entrou no NUM" << endl;

            if(no->esq == NULL && no->dir == NULL){ // É uma folha?

                 cout << "Achou uma folha " << endl;

                if(no->getCaractere() == '('){

                    cout << "Achou uma folha disponivel" << endl;

                    no->setCaractere(caractere);

                    acabou = true;

                    return true;

                } else {
                    //Volta pro Pai
                    cout << "Achou uma folha INdisponivel" << endl;
                    return false;
                }

            } else { // Se não for folha, percorra a arvore

                cout << "Nao achou uma folha" << endl;

                if(InsereExpressaoPosFixa(no->esq, caractere)){

                    cout << "Insecao feita" << endl;
                    return true;

                } else {

                    InsereExpressaoPosFixa(no->dir, caractere);
                    return false;


                }

            }

        } else if(eOperador(caractere)){

            cout << "Entrou no Operador" << endl;

            if(no->dir == NULL){

                cout << "NAO tem filho na direita" << endl;

                if(no->esq != NULL){

                    cout << "Mas TEM filho na esquerda" << endl;

                    if(eNumero(no->esq->getCaractere())){

                        cout << "O filho na esquerda é um numero!" << endl;

                        if(no->getCaractere() == '('){

                            cout << "Como aqui tem um (, vou atualizar o no atual" << endl;

                            no->setCaractere(caractere);

                            return true;

                        } else {

                            cout << "N tem '(', vou ir pra esq" << endl;

                            if(InsereExpressaoPosFixa(no->esq, caractere)){
                                return true;
                            } else {
                                return false;
                            }

                        }
                    }

                    if(eOperador(no->esq->getCaractere()) || no->esq->getCaractere() == '('){

                        cout << "O filho na esquerda N é um numero!" << endl;
                        cout << "Logo, vou ir mais pra esquerda" << endl;

                        if(!InsereExpressaoPosFixa(no->esq, caractere)){

                            cout << "Vou inserir aqui, pois voltei e n coloquei nada" << endl;
                            no->setCaractere(caractere);
                            return true;

                        } else {
                            cout << "Nao vou inserir aqui, pois ja inseri mais embaixo" << endl;
                            return true;
                        }
                    }

                } else {

                    cout << "É uma folha" << endl;
                    return false;

                }
            } else {

                cout << "Tem filho na direita, ent vou p la" << endl;

                if(InsereExpressaoPosFixa(no->dir, caractere)){
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
        leInFixa(no->esq);
        cout << no->getCaractere() << endl;
        leInFixa(no->dir);
    }

}

void Arvore::limpa(){


}