#include <stdlib.h>
 // A posicao 10 do vetor dinamico x nao esta alocada na memoria, logo deve-se aumenta o tamanho para 11
 // A memoria nao foi liberada ao final da funcao f, logo adiciona-se a funcao free, antes do fim da funcao f

void f(void) {

    int* x = malloc(11 * sizeof(int));
    x[10] = 0;
    free(x);
}

int main(void) {

f();

return 0;
}