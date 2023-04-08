#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>

//Como a declaracao de a foi feita dentro do for, seu valor sempre será atualizado para 1, nunca incrementando. Deve-se declarar a fora do for

int inc(int a) {
  return a+1;
}

int main(int argc, char** argv) {

  printf("%d\n", argc);

  int a = 1;

  for(int i=1; i < 5; i++) {
     a = inc(a);
  }

  return argc;
}
