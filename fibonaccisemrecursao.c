#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
// Trabalhando fibonacci sem recursão

int fibonacci(n){//
    int fib[n], aux = 0;
    if(n == 0){
        return 0;
    }
    if(n == 1 || n == 2){
        return 1;
    }  
    else{
        fib[0] = 0;
        fib[1] = 1;
        fib[2] = 1;
        for(int x = 2; x <= n; x++){
            fib[x] = fib[x-1] + fib[x-2];    
        }
        return fib[n];
    }
}

void main(){
    int n;
    printf("digite a posicao do enesimo termo de fibonacci: ");
    scanf("%d", &n);
    printf("%d", fibonacci(n));

}