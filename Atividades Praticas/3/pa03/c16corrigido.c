#include <stdio.h>
#include <stdlib.h>

// Uma divisao de inteiros nem sempre ira gerar outro inteiro. Deve-se mudar os tipos das variaveis da divisao para double
// Para evitar uma divisao por 0, deve-se cheacr se o divisor nao é 0.

double actual_calc(double a, double b){

  if(b == 0.0){
    return 0;
  }

  double c;
  c=a/b;

  return c;
}

int calc(){

  double a = 13.0;
  double b = 0.0;

  actual_calc(a, b);

  return 0;
}

int main(){
  calc();
  return 0;
}