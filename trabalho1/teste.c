#include <stdio.h>
#include <string.h>

int main(){
    char texto[] = "Olá, o mundo é muito grande. Tem muitas pessoas, e muitos problemas";
    char busca[] = "muito";
    int posicoes[30];
    int qtdOcorrencias = q4(texto, busca, posicoes);
    printf("Quantidade de ocorrências: %d\n", qtdOcorrencias);
    for (int i = 0; i < qtdOcorrencias; i++)
    {
        printf("Posição %d: %d - %d\n", i + 1, posicoes[i * 2], posicoes[i * 2 + 1]);
    }
    return 0;
}