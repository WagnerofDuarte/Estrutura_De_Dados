#include <iostream>
#include <filaCircular.h>
#include <pilhaDaFilaCircular.h>



int main() {

    //Declaração de Variáveis, Constantes e Objetos

    PilhaDaFilaCircular pilha = PilhaDaFilaCircular();

    //Teste 1 - Adicionar tudo, e remover tudo

    //Adicionar tudo
    pilha.empilha(9);
    pilha.empilha(5);
    pilha.empilha(4);
    pilha.empilha(7);
    pilha.empilha(1);
    pilha.empilha(3);
    pilha.empilha(8);
    pilha.empilha(2);
    pilha.empilha(6);
    pilha.empilha(0);

    //Tenta adicionar em pilha lotada
    pilha.empilha(7); //teste de erro: nao ira adicionar pois a pilha ja esta cheia
    pilha.empilha(5); //teste de erro: nao ira adicionar pois a pilha ja esta cheia

    //Remove tudo
    pilha.desempliha();
    pilha.desempliha();
    pilha.desempliha();
    pilha.desempliha();
    pilha.desempliha();
    pilha.desempliha();
    pilha.desempliha();
    pilha.desempliha();
    pilha.desempliha();
    pilha.desempliha();

    //Tenta remover em pilha  vazia
    pilha.desempliha(); //teste de erro: nao ira desempilhar pois a pilha ja esta vazia
    pilha.desempliha(); //teste de erro: nao ira desempilhar pois a pilha ja esta vazia

    pilha.destroi(); // Apaga a pilha

    std::cout << std::endl;
    std::cout << "TESTE 2:" << std::endl;
    std::cout << std::endl;

    //Teste 2 - Adicionar e remover aleatoriamente
    pilha.empilha(3);
    pilha.desempliha();
    pilha.desempliha();
    pilha.desempliha();
    pilha.empilha(5);
    pilha.desempliha();
    pilha.desempliha();
    pilha.empilha(4);
    pilha.empilha(7);
    pilha.desempliha();
    pilha.desempliha();
    pilha.desempliha();
    pilha.empilha(6);
    pilha.empilha(2);
    pilha.empilha(1);
    pilha.desempliha();
    pilha.desempliha();
    pilha.desempliha();
    pilha.desempliha();
    pilha.empilha(8);
    pilha.empilha(9);

    pilha.destroi();

    return 0;
}