#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv){

  int i;
  int a[10];

  for (i = 0; i < 10; i++) // Era pra ser até 10, pois vai de 0 ate 9
    a[i] = i;
    
  for (i = 0; i < 10; i++){
    printf("%d ", a[i]);
  }

  printf("\n");

  return 0;
}


