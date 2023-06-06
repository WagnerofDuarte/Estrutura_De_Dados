#include <iostream>
#include <iostream>

#include <Arquivos.h>
#include <Lista.h>
#include <AlgoritimosFechoConvexo.h>

int main(int argc, char** argv){

    /* LEITURA DO ARQUIVO */

    Arquivos* ArquivoTeste = new Arquivos("ENTRADA100.txt");
    
    string conteudoDoArquivo = ArquivoTeste->lerArquivo();
    cout << conteudoDoArquivo << endl;
    cout << endl;

    Lista* listaTeste = new Lista();

    /* ARMAZENAMENTO DOS PONTOS NA LISTA */

    string aux_x;
    string aux_y;
    char x_ou_y = 'x';

    for(int i = 1; i < conteudoDoArquivo.size(); i++){

        if(conteudoDoArquivo[i] == '|'){

            listaTeste->insereFinal(stoi(aux_x), stoi(aux_y));
            aux_x = "";
            aux_y = "";
            x_ou_y = 'x';

        } else if (conteudoDoArquivo[i] != ' '){

            if(x_ou_y == 'x'){
                aux_x = aux_x + conteudoDoArquivo[i];
            } else {
                aux_y = aux_y + conteudoDoArquivo[i];
            }

        } else {
            if(x_ou_y == 'x'){
                x_ou_y = 'y';
            } else {
                x_ou_y = 'x';
            }
        }
        
    }

    listaTeste->imprime();

    /* ALGORITIMOS DE FECHO */

    AlgoritimosFechoConvexo* testeDeFecho = new AlgoritimosFechoConvexo();

    Lista* testeResultado = testeDeFecho->marchaDeJarvis(listaTeste);

    cout << "FECHO CONVEXO" << endl;
    testeResultado->imprime();

    return 0;

}