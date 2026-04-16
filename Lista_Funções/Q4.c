#include <stdio.h>
#include <stdlib.h>

int ler3numeros(int num[]){
    scanf("%d", &num[0]);
    scanf("%d", &num[1]);
    scanf("%d", &num[2]);

    return num[0];
    return num[1];
    return num[2];
}

int main(){
    int numeros[3];
    
    ler3numeros(numeros);
    printf("Os números lidos foram: %d, %d e %d\n", numeros[0], numeros[1], numeros[2]);
    return 0;

}