#include <iostream>
#include <string>

#include <Expressao.h>

int main(){

    Expressao teste = Expressao("( 2 + 2 )");

    char a = '7';
    double ia = a - '0';
    ia = ia + 0.002;

    cout << "Teste: " << ia/2 << endl;

    Arvore* arvore = new Arvore();

    string palavra = "((2)+(2))";

    for(int i = 0; i < 9; i++){

        char c = palavra[i];
        arvore->InsereExpressaoPosFixa(arvore->getRaiz(), c);

    }

    arvore->leInFixa(arvore->getRaiz());

    //cout << "Leu? : " << arvore->getRaiz()->getCaractere() << endl;

    return 0;
}