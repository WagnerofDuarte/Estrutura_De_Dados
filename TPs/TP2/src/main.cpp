#include <iostream>
#include <iostream>

#include <Arquivos.h>
#include <Lista.h>
#include <AlgoritimosFechoConvexo.h>
#include <AlgoritimosOrdenacao.h>

int main(int argc, char** argv){

    /* LEITURA DO ARQUIVO */

    Arquivos* ArquivoTeste = new Arquivos("ENTRADA10.txt");
    
    string conteudoDoArquivo = ArquivoTeste->lerArquivo();

    Lista* listaTeste = new Lista(true);

    /* ARMAZENAMENTO DOS PONTOS NA LISTA */

    string aux_x;
    string aux_y;
    char x_ou_y = 'x';

    for(int i = 1; i < conteudoDoArquivo.size(); i++){

        if(conteudoDoArquivo[i] == '|'){

            listaTeste->insereFinal(stoi(aux_x), stoi(aux_y), NULL, NULL);
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

    /* ALGORITIMOS DE FECHO - MARCHA DE JARVIS E SCAN DE GRAHAN*/

    AlgoritimosFechoConvexo* testeDeFecho = new AlgoritimosFechoConvexo();

    //Lista* testeResultado = testeDeFecho->marchaDeJarvis(listaTeste);
    FechoConvexo* fechoFinal = testeDeFecho->scanDeGraham(listaTeste);

    /* ALGORITIMOS DE ORDENAÇÃO */ /* CALCULA ANGULO */

    //AlgoritimosDeOrdenacao* testeDeOrdenacao = new AlgoritimosDeOrdenacao(listaTeste);

    /* INSERTION SORT */

    //testeDeOrdenacao->insertionSort(listaTeste);

    /* MERGE SORT */

    //testeDeOrdenacao->mergeSort(listaTeste, 0, (listaTeste->getTam()));

    /* RADIX SORT */

    //testeDeOrdenacao->radixSort(listaTeste);

    /* PRINT DE RESULTADOS */

    cout << "FECHO CONVEXO" << endl;
    fechoFinal->imprimirFecho();
    cout << endl;

    return 0;

}