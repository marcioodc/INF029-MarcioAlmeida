#include <stdio.h>
#include <string.h>

int ler3letras()
{
    char letra[3];
    for (int i = 0; i < 3; i++)
    {
        scanf(" %c", &letra[i]);
        return letra[i];
    }
}

int main()
{
    char letras[3];
    for (int i = 0; i < 3; i++)
    {
        letras[i] = ler3letras();
    }
    printf("As letras lidas foram: %c, %c, %c\n", letras[0], letras[1], letras[2]);
    return 0;
}