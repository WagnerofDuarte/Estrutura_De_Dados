#include <stdio.h>

//fact nao foi inicializado, logo ira iniciar o programa com valores lixo. Deve-se inicilaizar fact com 1.

int main(void) {

  int n, i, fact = 1;

  printf("Positive integer:");
  scanf("%d", &n);
  
  for(i = 1; i<=n; i++) 
    fact = fact*i;

  printf("Factorial %d = %d\n", n, fact);
}
