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
        Expressao(char expressaoChar[1000], int tamanho, int _infixaOuPosfixa); //CONSTRUTOR
        ~Expressao(); //DESTRUTOR

        /* MÉTODOS */
        int validacaoDeExpressao(char expressaoChar[1000], int tamanho, int _infixaOuPosfixa); // Retorna 1 se for POSFIXA ou 2 se for INFIXA ou 0 se for invalida
        void armazenaExpressao(char expressaoChar[1000]);

        void imprimirExpressao(char expressaoChar[1000], int tamanho);

        void converteExpressao(int _infixaOuPosfixa);
        void convertePraPosFixa(NoArvore* no);
        void convertePraInFixa();

        void resolveExpressao();
        void resolvePosFixa(); // Usando TAD pilhas
        void resolveInFixa(); // Usando TAD Arvore

        bool eNumero(char c);
        bool eOperador(char c);

        int getTamanhoExpressao();

        CelulaLista* converteNum(CelulaLista* aux);

};

#endif