#include <stdlib.h>
#include <stdio.h>


//Loop infinito no while, alocando memoria indefinidamente, causando grandes problemas de alocacao de memoria ao sistema. Limete de iterações adicionado
//Ponteiro p, nunca é liberado, ocupando cada vez mais memoria. Metodo free adicionado

int main(void) {

        int *p;
        int limite = 10;
        int i = 0;

        while(i < limite) {
                p = malloc(128);
                printf("%ld\n", (long)p);
                free(p);
                i++;
        }

        return (0);
}
