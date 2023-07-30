#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
// Trabalhando com recursão

int fibona(n){//
    if(n == 0){
        return 0;
    }
    else{
        if(n == 2 || n == 3)
            return 1;
        else
            return fibona(n-1) + fibona(n-2);        
    }
}

void main(){
    int n;
    printf("digite a posicao do enesimo termo de fibonacci: ");
    scanf("%d", &n);
    printf("%d", fibona(n));

}