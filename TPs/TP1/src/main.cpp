#include <iostream>
#include <fstream>
#include <string>
#include <Expressao.h>


int main(){

    /*
        1) Abrir e Ler o arquivo -- N
        2) Validar a expressao antes de armazena-la -- N
        3) Caso a expressao seja valida, guarda-la como INfixa ou POSfixa -- S
        4) Resolver a expreesao e armazenar seu resultado -- S/2
    
    
    
    */

    
    //string palavraInFixa = "((((3)*(2))/(4))+((2)+(3)))";//OK
    //string palavraInFixa = "(((3)-((5)+(6)))+((5)*(4)))";//OK
    //string palavraInFixa = "((3)/((2)*(((1)+((7)-(5))))))"; //OK 
    //string palavraInFixa = "((((((3)+(((4,89)*(5,87))-(2,0987)))*(2)/(5,9)))+(376))-((66,5)/((7,6)/(8,0987))))"; //OK
    //string palavraInFixa = "(((2)+(2))+(7))"; //OK
    string palavraPosFixa = "5 1 2 + 4 * + 3 -"; //OK

    cout << palavraPosFixa << endl;

    Expressao *teste = new Expressao(palavraPosFixa);

    return 0;
}