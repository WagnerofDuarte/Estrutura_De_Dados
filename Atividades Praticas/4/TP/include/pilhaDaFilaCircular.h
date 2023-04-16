#ifndef PILHA_DA_FILA_CIRCULAR
#define PILHA_DA_FILA_CIRCULAR

#include <filaCircular.h>
#include <iostream>

class PilhaDaFilaCircular {

    public:
        PilhaDaFilaCircular();
        int empilha(int item);
        int desempliha();
        void destroi();
        bool pilhaVazia();
        bool pilhaCheia();
    
    private:
        FilaCircular fila1;
        FilaCircular fila2;
        bool f1Ouf2; //Se true, a pilha esta na fila 1, C.C, a pilha esta na fila 2

};

#endif