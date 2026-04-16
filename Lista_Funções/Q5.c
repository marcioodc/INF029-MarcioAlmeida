#include <stdio.h>
#include <stdlib.h>

#include <stdio.h>
#include <stdlib.h>

int ler4numeros(int num[]){
    scanf("%d", &num[0]);
    scanf("%d", &num[1]);
    scanf("%d", &num[2]);
    scanf("%d", &num[3]);

    return num[0];
    return num[1];
    return num[2];
    return num[3];
}

int main(){

    typedef struct lernumeros{
        int num[4];
    }lernumeros;   
    
    lernumeros numeros;
    ler4numeros(numeros.num);

    printf("Os números lidos foram:");
    for(int i = 0; i < 4; i++){
        printf(" %d", numeros.num[i]);
    }

    return 0;

}