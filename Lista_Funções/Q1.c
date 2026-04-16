#include <stdio.h>
#include <stdlib.h>

int somar(int a, int b){
    return a + b;
}

int main(){
    int num1, num2;

    scanf("%d", &num1);
    scanf("%d", &num2);

    int soma = somar(num1, num2);

    printf("SOMA: %d", soma);
}
