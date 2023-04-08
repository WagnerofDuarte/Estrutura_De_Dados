#include <stdio.h>
#include <stdlib.h>

// Para que a memoria seja alocada corretamente, deve-se efetuar um free depois de cada alocacao, senao lixo de memoria serao deixados pra traz.


int main() {

  char *p;

  p = (char *) malloc(19);
  free(p);
  p = (char *) malloc(12);
  free(p);
  p = (char *) malloc(16);
  free(p);

  return 0;
}

