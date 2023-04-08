#include <stdlib.h>
#include <stdint.h>

// O indicador de final de string nao estava sendo alocado no alfabeto, pois precisaria ter um total de 26 posicoes + 1 posicao para o /0
//, agora com 27 espacos alocados, isso será possivel.

int main() {

    char* alphabet = calloc(27, sizeof(char));

    for(uint8_t i = 0; i < 26; i++) {
        *(alphabet + i) = 'A' + i;
    }
    *(alphabet + 26) = '\0';

    free(alphabet);
    return 0;
}