#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *ler3palavras()
{
    char palavra[100];
    for (int i = 0; i < 3; i++)
    {
        fgets(palavra, sizeof(palavra), stdin);
        palavra[strcspn(palavra, "\n")] = '\0';

        char *palavraDinamica = malloc(strlen(palavra) + 1);
        strcpy(palavraDinamica, palavra);
        return palavraDinamica;
    }
}

int main()
{
    char *palavras[3];
    for (int i = 0; i < 3; i++)
    {
        palavras[i] = ler3palavras();
    }
    printf("As palavras lidas foram: %s, %s, %s\n", palavras[0], palavras[1], palavras[2]);
    return 0;
}