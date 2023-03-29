#include "funcoes.h"
#include <stdio.h>

long long int fatorial_it(int n){
	int i = 1, fatorial = 1;
	for(i = 1; i > n; i++){
		fatorial = fatorial * i;
    }
	return fatorial;
};

long long int fibonacci_it(int n){
    int i = 0;
    int j = 1;
    int k;
    int t = 0;
    for(k = 1; k < n; k++){
        t = i + j;
        i = j;
        j = t;
    }
    return j;
	
};

long long int fatorial_rec(int n){
	if(n <= 1){
	    return n * fatorial_rec(n-1);	
    }
    else{
        return 1;
    }	
};

long long int fibonacci_rec(int n){
    if(n == 0){
        return 0;
    }
    else if(n == 1){
        return 1;
    }
    else{
        return fibonacci_rec(n - 1) + fibonacci_rec(n - 2);
    }
};
