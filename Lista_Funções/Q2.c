#include <stdio.h>
#include <stdlib.h>

int subtrair(int a, int b, int c){
    return a - b - c;
}

int main(){
    int num1, num2, num3;

    scanf("%d", &num1);
    scanf("%d", &num2);
    scanf("%d", &num3);

    int subtracao = subtrair(num1, num2, num3);

    printf("\nSUBTRAÇÃO: %d", subtracao);
    return 0;
}