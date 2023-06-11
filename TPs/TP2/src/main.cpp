#include <iostream>
#include <iostream>
#include <time.h>

#include <Arquivos.h>
#include <Lista.h>
#include <AlgoritimosFechoConvexo.h>
#include <AlgoritimosOrdenacao.h>

int main(int argc, char** argv){

    /* LEITURA DO ARQUIVO */

    Arquivos* arquivoTeste = new Arquivos(argv[2]);
    string conteudoDoArquivo = arquivoTeste->lerArquivo();
    Lista* listaDePontos = new Lista(true);

    /* ARMAZENAMENTO DOS PONTOS NA LISTA */

    string aux_x;
    string aux_y;
    char x_ou_y = 'x';

    for(int i = 1; i < conteudoDoArquivo.size(); i++){

        if(conteudoDoArquivo[i] == '|'){

            listaDePontos->insereFinal(stoi(aux_x), stoi(aux_y), NULL, NULL);
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

    AlgoritimosFechoConvexo* encontrarFecho = new AlgoritimosFechoConvexo();
    FechoConvexo* fechoFinal;

    double tempoTotalJarvis;
    double tempoGrahamInsertion;
    double tempoGrahamMerge;
    double tempoGrahamRadix;

    long antes;
    long depois;

    for(int i = 0; i < 4; i++){

        Lista* listaDePontosAux = new Lista(true);
        for(int i = 0; i < listaDePontos->getTam(); i++){
            listaDePontosAux->insereFinal(listaDePontos->pontoNaPosicao(i)->getX(), listaDePontos->pontoNaPosicao(i)->getY(), NULL, NULL);
        }

        switch (i) {
        case 0:
            antes = clock();
            fechoFinal = encontrarFecho->marchaDeJarvis(listaDePontosAux);
            depois = clock();
            tempoTotalJarvis = (double)(depois - antes)/CLOCKS_PER_SEC;
            break;
        case 1:
            antes = clock();
            fechoFinal = encontrarFecho->scanDeGraham(listaDePontosAux, 1);
            depois = clock();
            tempoGrahamInsertion = (double)(depois - antes)/CLOCKS_PER_SEC;
            break;
        case 2:
            antes = clock();
            fechoFinal = encontrarFecho->scanDeGraham(listaDePontosAux, 2);
            depois = clock();
            tempoGrahamMerge = (double)(depois - antes)/CLOCKS_PER_SEC;
            break;
        case 3:
            antes = clock();
            fechoFinal = encontrarFecho->scanDeGraham(listaDePontosAux, 3);
            depois = clock();
            tempoGrahamRadix = (double)(depois - antes)/CLOCKS_PER_SEC;
            break;
        default:
            break;
        }

    }

    /* PRINT DE RESULTADOS */

    cout << "FECHO CONVEXO" << endl;
    fechoFinal->imprimirFecho();
    cout << setprecision(3) << fixed;
    cout << "GRAHAM+MERGESORT: " << tempoGrahamMerge << "s" << endl;
    cout << "GRAHAM+INSERTIONSORT: " << tempoGrahamInsertion << "s" << endl;
    cout << "GRAHAM+LINEAR: " << tempoGrahamRadix << "s" << endl;
    cout << "JARVIS: " << tempoTotalJarvis << "s" << endl;

    return 0;

}