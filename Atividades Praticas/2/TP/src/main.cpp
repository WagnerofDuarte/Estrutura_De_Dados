#include "funcoes.h"
#include <stdio.h>
#include <string>

int main(int argc, char ** argv){ 
    
    int valor = atoi(argv[3]);
	printf("%d \n", valor);
    long long int resultado = 0;

    //fatorial
	if(*(argv[1]) == 'f'){
		//iterativo
		if(*(argv[2]) == 'i'){
		   resultado = fatorial_it(valor);
		//recursivo
		} else {
		    resultado = fatorial_rec(valor);
		}
		
	//serie de fibonacci
	} else if(*(argv[1]) == 's') {
		//iterativo
		if(*(argv[2]) == 'i'){
		    resultado = fibonacci_it(valor);
		//recursivo
		} else {
		   resultado = fibonacci_rec(valor);
		}
	}
	
	printf("%lld\n", resultado);

	return 0;

}
