#include <iostream>
#include <fstream>
#include <string>
#include <Expressao.h>


int main(int argc, char** argv){

    fstream arquivo("entradas.in");
    //fstream arquivo(argv[1]);
    string linha;

    Expressao *expressaoPrincipal;
    char expressaoChar[1000];
    int tamanho = 0;

    while(getline(arquivo, linha)){

        string comando;
        string tipo;
        bool achouComando = false;
        bool achouTipo = false;
        
        for(int i = 0; i < linha.size(); i++){

            if(!achouComando){
                if(linha[i] != ' '){
                    comando += linha[i];
                } else {
                    achouComando = true;
                }
            } else if(achouComando && !achouTipo && comando == "LER"){
                tamanho = 0;
                if(!achouTipo){
                    if(linha[i] != ' '){
                        tipo += linha[i];
                    } else {   
                        achouTipo = true;
                    }
                }
            } else if(achouComando && comando == "LER" && achouTipo){

                expressaoChar[tamanho] = linha[i];
                tamanho++;

            }
        }

        if(comando == "LER"){

            int infixaOuPosfixa;

            if(tipo == "INFIXA"){
                infixaOuPosfixa = 2;
            } else if(tipo == "POSFIXA"){
                infixaOuPosfixa = 1;
            } else {
                infixaOuPosfixa = 0;
            }

            if(expressaoPrincipal->validacaoDeExpressao(expressaoChar, tamanho, infixaOuPosfixa) != 0){
                expressaoPrincipal = new Expressao(expressaoChar, tamanho, infixaOuPosfixa);
            } else {
                cout << "ERRO: ";
                for(int i = 0; i < tamanho; i++){
                    cout << expressaoChar[i];
                }
                cout << " NAO VALIDA" << endl;
            }

        } else if(comando == "POSFIXA" && expressaoPrincipal->getTamanhoExpressao() > 0){
            expressaoPrincipal->converteExpressao(1);

        }else if(comando == "INFIXA" && expressaoPrincipal->getTamanhoExpressao() > 0){
            expressaoPrincipal->converteExpressao(2);

        }  else if(comando == "RESOLVE" && expressaoPrincipal->getTamanhoExpressao() > 0){
            expressaoPrincipal->resolveExpressao();
            
        } else if(expressaoPrincipal->getTamanhoExpressao() <= 0){

            cout << "ERRO: ";
            for(int i = 0; i < tamanho; i++){
                cout << expressaoChar[i];
            }
            cout << " NAO EXISTE" << endl;
        }
    }

    return 0;
}