#include <iostream>
#include <string>

#include <Expressao.h>

int main(){

    Expressao teste = Expressao("( 2 + 2 )");

    char a = '7';
    double ia = a - '0';
    ia = ia + 0.002;

    Arvore* arvore = new Arvore();

    //string palavra = "((((3)*(2))/(4))+((2)+(3)))";//OK
    //string palavra = "(((3)-((5)+(6)))+((5)*(4)))";//OK
    //string palavra = "((3)/((2)*(((1)+(7)-(5)))))"; //OK
    //string palavra = "((((((3)+(((4)*(5))-(2)))*(2)/(5)))+(3))-((6)/((7)/(8))))"; /OK
    string palavra = "(((2)+(2))+(7))"; //OK

    for(int i = 0; i < palavra.size(); i++){

        char c = palavra[i];
        arvore->InsereExpressaoPosFixa(arvore->raiz, c);

    }

    arvore->leInFixa(arvore->getRaiz());

    return 0;
}