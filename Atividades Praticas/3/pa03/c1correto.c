#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv){

  int i;
  int *a = malloc(sizeof(int) * 10);

  if (!a) return -1; /*malloc failed*/

  for (i = 0; i < 10; i++){ // Era pra ser ate 10
    a[i] = i;
  }

  free(a);

  return 0;

}