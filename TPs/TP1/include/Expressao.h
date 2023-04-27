#ifndef EXPRESSAO
#define EXPRESSAO

#include <string>
#include <Pilha.h>
#include <Fila.h>
#include <Arvore.h>

using namespace std;

class Expressao {

    private:
        /* ATRIBUTOS */
        string expressaoString;
        bool infixaOuPosfixa;
        double resultadoExpressao;
        Fila expressao;

    public:
        /* CONSTRUTOR E DESTRUTOR */
        Expressao(string _expressaoString); //CONSTRUTOR
        ~Expressao(); //DESTRUTOR

        /* MÉTODOS */
        int validarExpressao(); // Retorna 1 se for POSFIXA ou 2 se for INFIXA ou 0 se for invalida

        void transformarExpressaoEmFila();

        int convertePraPosFixa();
        int convertePraInFixa();

        int ResolvePosFixa(); // Usando TAD pilhas
        int ResolveInFixa(); // Usando TAD ???

};

#endif