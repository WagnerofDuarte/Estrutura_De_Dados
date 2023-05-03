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
        double resultadoExpressao;
        Lista *expressao;
        Fila *posFixa;
        Arvore *inFixa;

    public:
        /* CONSTRUTOR E DESTRUTOR */
        Expressao(string nomeDoArquivo); //CONSTRUTOR
        ~Expressao(); //DESTRUTOR

        /* MÉTODOS */
        int validacaoDeExpressao(string nomeDoArquivo); // Retorna 1 se for POSFIXA ou 2 se for INFIXA ou 0 se for invalida
        int armazenaExpressao(string nomeDoArquivo);

        int convertePraPosFixa();
        int convertePraInFixa();

        int resolvePosFixa(); // Usando TAD pilhas
        int resolveInFixa(); // Usando TAD Arvore

        bool eNumero(char c);

        CelulaLista* converteNum(CelulaLista* aux);

};

#endif