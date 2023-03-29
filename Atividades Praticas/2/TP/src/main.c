#include "funcoes.h"
#include <stdio.h>

int main(int argc, char ** argv){
    
    char serie = *(argv[1]);
    char tipo = *(argv[2]);
    int valor = atoi(argv[3]);
    long long int resultado;
    
	if(serie == 'a'){
		
		if(tipo == 'i'){
		   resultado = fatorial_it(valor);
		} else {
		    resultado = fatorial_rec(valor);
		}
		
	} else if(serie == 'b') {
		
		if(tipo == 'i'){
		    resultado = fibonacci_it(valor);
		} else {
		   resultado = fibonacci_rec(valor);
		}
	}
	
	printf("%lld\n", resultado);

}
