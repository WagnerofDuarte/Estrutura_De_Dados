#include <pilhaDaFilaCircular.h>

PilhaDaFilaCircular::PilhaDaFilaCircular(){

    fila1 = FilaCircular();
    fila2 = FilaCircular();
    f1Ouf2 = true;

}

int PilhaDaFilaCircular::empilha(int item){

    if(pilhaCheia()){
        std::cout << "A pilha esta cheia!" << std::endl;
        return 0;
    }

    if(f1Ouf2){
        fila1.enfileira(item);
    } else {
        fila2.enfileira(item);
    }

    std::cout << "Item " << item << " foi adicionado!" << std::endl;

    return 1;
}

int PilhaDaFilaCircular::desempliha(){

    if(pilhaVazia()){
        std::cout << "A pilha esta vazia!" << std::endl;
        return 0;
    }

    if(f1Ouf2){
        fila2.limpa();
        int tamanho = fila1.getTamanho();
        for(int i = 0; i < (tamanho - 1); i++){
            int aux = fila1.desenfileira();
            fila2.enfileira(aux);
        }
        std::cout << "Item " << fila1.desenfileira() << " foi removido!" << std::endl;
        f1Ouf2 = false;
    } else {
        fila1.limpa();
        int tamanho = fila2.getTamanho();
        for(int i = 0; i < (tamanho - 1); i++){
            int aux = fila2.desenfileira();
            fila1.enfileira(aux);
        }
        std::cout << "Item " << fila2.desenfileira() << " foi removido!" << std::endl;
        f1Ouf2 = true;
    }
    return 1;
}

void PilhaDaFilaCircular::destroi(){

    fila1.limpa();
    fila2.limpa();
}

bool PilhaDaFilaCircular::pilhaVazia(){
    if(fila1.getTamanho() == 0 && fila2.getTamanho() == 0){
        return true;
    } else {
        return false;
    }
}

bool PilhaDaFilaCircular::pilhaCheia(){
    if(fila1.getTamanho() == fila1.getMAXTAM() || fila1.getTamanho() == fila1.getMAXTAM()){
        return true;
    } else {
        return false;
    }
}

//1 Inicial
// 1,5,7,9 F1
// n,n,n,n F2

//2 Remove
// n,n,n,n F1
// 1,5,7,n F2

//3 Adiciona
// n,n,n,n F1
// 1,5,7,0 F2

//4 Remove
// 1,5,7,n F1
// n,n,n,n F2