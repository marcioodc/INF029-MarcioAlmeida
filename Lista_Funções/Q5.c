#include <stdio.h>
#include <stdlib.h>

#include <stdio.h>
#include <stdlib.h>

int ler4numeros()
{
    int n[4];
    for (int i = 0; i < 4; i++)
    {
        scanf("%d", &n[i]);
        return n[i];
    }
}
typedef struct
{
    int numero[4];
} ler;
int main()
{
    ler ler;
    for (int i = 0; i < 4; i++)
    {
        ler.numero[i] = ler4numeros();
    }
    printf("Os numeros lidos foram: %d, %d, %d, %d\n", ler.numero[0], ler.numero[1], ler.numero[2], ler.numero[3]);

    return 0;
}