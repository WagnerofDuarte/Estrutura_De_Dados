#include "funcoes.h"
#include <stdio.h>

long long int fatorial_it(int n){

    int fatorial = 1;

	for(int i = 1; i <= n; i++){
		fatorial = fatorial * i;
    }

	return fatorial;
};

long long int fibonacci_it(int n){

    int a = 0;
    int b = 1;
    int c = 0;

    for(int i = 0; i < n; i++){

        c = a + b;
        a = b;
        b = c;
    }

    return b;
	
};

long long int fatorial_rec(int n){

	if(n >= 1){
	    return n * fatorial_rec(n-1);	
    } else {
        return 1;
    }	
};

long long int fibonacci_rec(int n){

    if(n < 2){
        return 1;
    } else {
        return fibonacci_rec(n - 1) + fibonacci_rec(n - 2);
    }
};
