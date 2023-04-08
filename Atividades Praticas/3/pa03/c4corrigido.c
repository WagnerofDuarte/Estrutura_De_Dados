#include <stdlib.h>

struct Matrix {
  int rows, cols;
  int** data;
};

int main(){

  //O ponteiro text nunca foi inicializado, entao nao convem libera-lo da memoria
  //Deve-se inicilaizar a raiz de rotation3D, para que seus atrinutos sejam usados
  //deve-se liberar cada elemento 'data' de rotation3D, primeiro liberando as colunas de cada linha, e depois as linhas

  int i;
  struct Matrix * rotation3D;

  rotation3D = (struct Matrix*) malloc(sizeof(struct Matrix));
  rotation3D->rows=4;
  rotation3D->cols=4;
  rotation3D->data=(int**) malloc(sizeof(int*)*rotation3D->rows);

  for(i=0;i<rotation3D->rows;i++){
    rotation3D->data[i]=(int*) malloc(sizeof(int)*rotation3D->cols);
  }

  for(i=0;i<rotation3D->rows;i++){
    free(rotation3D->data[i]);
  }

  free(rotation3D->data);
  free(rotation3D);

  return 0;
}