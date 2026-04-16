#include <stdio.h>
#include <stdlib.h>

int ler3numeros(int a, int b, int c){
    scanf("%d", &a);
    scanf("%d", &b);
    scanf("%d", &c);

    return a;
    return b;
    return c;
}

int main(){
    int numeros[3];
    ler3numeros(numeros[0], numeros[1], numeros[2]);
    printf("Os números lidos foram: %d, %d e %d\n", numeros[0], numeros[1], numeros[2]);
    return 0;

}