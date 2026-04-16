#include <stdio.h>
#include <stdlib.h>

int fat(int num){
    if(num == 0 || num == 1){
        return 1;
    }else{
        return num * fat(num - 1);
    }
}

int main(){
    int num;

    scanf("%d", &num);
    
    if(fat(num) == 1){
        printf("Não é possível calcular o fatorial");
    }else{
        printf("O fatorial de %d é: %d\n", num, fat(num));
    }
    return 0;
}