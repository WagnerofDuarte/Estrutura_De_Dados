#include <iostream>
#include <fstream>
#include <string>
#include <Expressao.h>


int main(){

    /*
        1) Abrir e Ler o arquivo -- N
        2) Validar a expressao antes de armazena-la -- N
        3) Caso a expressao seja valida, guarda-la como INfixa ou POSfixa -- S
        4) Converter de um tipo pro outro -- S
        5) Resolver a expreesao e armazenar seu resultado -- S
    
    */

    fstream arquivo("entradas.in");
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

        cout << endl;

    }

    return 0;
}