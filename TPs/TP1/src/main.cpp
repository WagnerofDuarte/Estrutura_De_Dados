#include <iostream>
#include <fstream>
#include <string>
#include <Expressao.h>


int main(){

    fstream arquivo("entdouble.s1.n5.i.in");
    string linha;

    Expressao *expressaoPrincipal;

    while(getline(arquivo, linha)){

        string comando;
        char expressaoChar[1000];
        int k = 0;
        bool achouComando = false;
        
        for(int i = 0; i < linha.size(); i++){

            if(!achouComando){
                if(linha[i] != ' '){
                    comando += linha[i];
                } else {
                    achouComando = true;
                }
            }

            if(achouComando == true && comando == "LER"){

                //if(linha[i] != ' '){
                    expressaoChar[k] = linha[i];
                    k++;
               // }
            }
        }

        if(comando == "LER"){
            expressaoPrincipal = new Expressao(expressaoChar, k);

        } else if(comando == "POSFIXA" || comando == "INFIXA"){
            expressaoPrincipal->converteExpressao();

        }  else if(comando == "RESOLVE"){
            expressaoPrincipal->resolveExpressao();
            
        } else {


        }

        /*cout << comando << endl;

        for(int j = 0; j < k; j++){
            cout << expressaoChar[j];
        }*/
        cout << endl;

    }  
    /*
        1) Abrir e Ler o arquivo -- N
        2) Validar a expressao antes de armazena-la -- N
        3) Caso a expressao seja valida, guarda-la como INfixa ou POSfixa -- S
        4) Converter de um tipo pro outro -- S
        5) Resolver a expreesao e armazenar seu resultado -- S
    
    
    
    */

    /*
    //string palavra = "((((3)*(2))/(4))+((2)+(3)))";//OK
    //string palavra = "3,556 2,009 * 44,043 / 2 3,984 + +";//OK
    //string palavra = "(((3)-((5)+(6)))+((5)*(4)))";//OK
    //string palavra = "((3)/((2)*(((1)+((7)-(5))))))"; //OK 
    string palavra = "((((((3)+(((4,89)*(5,87))-(2,0987)))*(2)/(5,9)))+(376))-((66,5)/((7,6)/(8,0987))))"; //OK
    //string palavra = "(((2)+(2))+(7))"; //OK
    //string palavra = "5 1 2 + 4 * + 3 -"; //OK
    //string palavra = "5,09 389,097 2 * 42,33 6,99 - + /";//OK
    //string palavra = "5,09 389,097 * 42,33 + 6,99 7,0008 - + ";//OK

    Expressao *teste = new Expressao(palavra);

    teste->converteExpressao();
    teste->resolveExpressao();
    teste->converteExpressao();
    teste->resolveExpressao();*/

    return 0;
}