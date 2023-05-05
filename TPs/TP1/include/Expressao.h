#ifndef EXPRESSAO
#define EXPRESSAO

#include <string>
#include <Pilha.h>
#include <Fila.h>
#include <Arvore.h>
#include <Lista.h>
#include <fstream>

using namespace std;

class Expressao {

    private:
        /* ATRIBUTOS */
        int infixaOuPosfixa;
        int expressaoInfixaOuPosfixa; // 1 se for posfixa e 2 se for infixa
        int tamanhoExpressao;
        double resultadoExpressao; 
        Lista *expressao;
        Fila *posFixa;
        Arvore *inFixa;

    public:
        /* CONSTRUTOR E DESTRUTOR */
        Expressao(char expressaoChar[1000], int k); //CONSTRUTOR
        ~Expressao(); //DESTRUTOR

        /* MÉTODOS */
        int validacaoDeExpressao(char expressaoChar[1000]); // Retorna 1 se for POSFIXA ou 2 se for INFIXA ou 0 se for invalida
        int armazenaExpressao(char expressaoChar[1000]);

        int recuperaExpressaoPosFixa();
        int converteExpressao();
        int convertePraPosFixa(NoArvore* no);
        int convertePraInFixa();

        int resolveExpressao();
        int resolvePosFixa(); // Usando TAD pilhas
        int resolveInFixa(); // Usando TAD Arvore

        bool eNumero(char c);

        CelulaLista* converteNum(CelulaLista* aux);

};

#endif