#include <stdio.h>
#include <stdlib.h>

int ler3numeros()
{
    int numeros[3];
    for (int i = 0; i < 3; i++)
    {
        scanf("%d", &numeros[i]);
        return numeros[i];
    }
}

int main()
{
    int num[3];
    for (int i = 0; i < 3; i++)
    {
        num[i] = ler3numeros();
    }
    printf("Os numeros lidos foram: %d, %d, %d\n", num[0], num[1], num[2]);
    return 0;
}