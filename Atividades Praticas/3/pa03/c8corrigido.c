#include <stdlib.h>
#include <stdint.h>

// A solucao é aumentar o tamanho de blocos disponiveis do source para 27, de forma que as referencias possam ser feitas adequadamente

int main() {
    
    char* destination = calloc(27, sizeof(char));
    char* source = malloc(27 * sizeof(char));

    for(uint8_t i = 0; i < 27; i++) {
        *(destination + i) = *(source + i);
    }

    free(destination);
    free(source);

    return 0;
}