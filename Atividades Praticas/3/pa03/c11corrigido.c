#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

//Memoria ocupada pelo ponteiro msg, nao foi liberado. Free adicionado!

int main(void) {

        char *msg = malloc(8);
        strcpy(msg, "Holberton");
        msg[0] = 'R';
        printf("%ld, %s\n", (long)getpid(), msg);

        free(msg);

        return (0);

}
