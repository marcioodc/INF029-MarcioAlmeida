#include <stdio.h>
#include <stdlib.h>

#define TAM 10
#define NUM_NAVIOS 5

typedef struct
{
    char tabuleiro[TAM][TAM];
    int partesRestantes;
} Jogador;

void inicializarTabuleiro(Jogador *j)
{
    for (int i = 0; i < TAM; i++)
    {
        for (int k = 0; k < TAM; k++)
        {
            j->tabuleiro[i][k] = ' ';
        }
    }
    j->partesRestantes = 10;
}

void mostrarTabuleiro(Jogador *j, int mostrarNavios)
{
    printf("\n    ");
    for (int i = 0; i < TAM; i++)
    {
        printf("%2d ", i + 1);
    }
    printf("\n");
    for (int i = 0; i < TAM; i++)
    {
        printf("%2d  ", i + 1);
        for (int k = 0; k < TAM; k++)
        {
            char c = j->tabuleiro[i][k];
            if (mostrarNavios == 0 && c == 'N')
            {
                c = ' ';
            }
            printf("[%c]", c);
        }
        printf("\n");
    }
}

int validarPosicao(Jogador *j, int linha, int coluna)
{
    if (linha < 0 || linha >= TAM ||
        coluna < 0 || coluna >= TAM)
    {
        return 0;
    }
    if (j->tabuleiro[linha][coluna] != ' ')
    {
        return 0;
    }
    return 1;
}

void posicionarNavio(Jogador *j, int tamanho)
{
    int linha;
    int coluna;
    int orientacao;
    int valido;
    do
    {
        valido = 1;
        printf("\n>POSICIONE SEUS NAVIOS<\n");
        printf("\n=== NAVIO TAMANHO %d ===\n", tamanho);
        printf("Linha e Coluna: ");
        scanf("%d %d", &linha, &coluna);
        linha--;
        coluna--;
        if (tamanho > 1)
        {
            printf("Orientacao (0-horizontal / 1-vertical): ");
            scanf("%d", &orientacao);
        }
        else
        {
            orientacao = 0;
        }
        for (int i = 0; i < tamanho; i++)
        {
            int l = linha;
            int c = coluna;
            if (orientacao == 0)
            {
                c += i;
            }
            else
            {
                l += i;
            }
            if (!validarPosicao(j, l, c))
            {
                valido = 0;
                break;
            }
        }
        if (!valido)
        {
            printf("Posicao invalida!\n");
        }

    } while (!valido);
    for (int i = 0; i < tamanho; i++)
    {
        int l = linha;
        int c = coluna;
        if (orientacao == 0)
        {
            c += i;
        }
        else
        {
            l += i;
        }
        j->tabuleiro[l][c] = 'N';
    }
}

void posicionarNavios(Jogador *j)
{
    posicionarNavio(j, 4);
    posicionarNavio(j, 3);
    posicionarNavio(j, 1);
    posicionarNavio(j, 1);
    posicionarNavio(j, 1);
    if (NUM_NAVIOS > 5)
    {
        for (int i = 0; i < NUM_NAVIOS - 5; i++)
        {
            posicionarNavio(j, 2);
        }
    }
}

void atirar(Jogador *defensor)
{
    int linha;
    int coluna;
    printf("\nLinha e coluna do tiro: ");
    scanf("%d %d", &linha, &coluna);
    linha--;
    coluna--;
    if (linha < 0 || linha >= TAM ||
        coluna < 0 || coluna >= TAM)
    {
        printf("Tiro invalido!\n");
        return;
    }
    if (defensor->tabuleiro[linha][coluna] == 'N')
    {
        printf("Acertou um navio!\n");
        defensor->tabuleiro[linha][coluna] = '0';
        defensor->partesRestantes--;
    }
    else if (defensor->tabuleiro[linha][coluna] == ' ')
    {
        printf("Agua!\n");
        defensor->tabuleiro[linha][coluna] = 'X';
    }
    else
    {
        printf("Posicao ja atacada!\n");
    }
}

int main()
{
    Jogador jogador1;
    Jogador jogador2;
    inicializarTabuleiro(&jogador1);
    inicializarTabuleiro(&jogador2);
    printf("=================================\n");
    printf("\tBATALHA NAVAL\n");
    printf("=================================\n");
    printf("\n=== JOGADOR 1 ===\n");
    posicionarNavios(&jogador1);
    printf("\n=== JOGADOR 2 ===\n");
    posicionarNavios(&jogador2);
    while (jogador1.partesRestantes > 0 &&
           jogador2.partesRestantes > 0)
    {
        printf("\n=================================\n");
        printf("\tVEZ DO JOGADOR 1\n");
        printf("=================================\n");
        printf("\nSEU TABULEIRO:\n");
        mostrarTabuleiro(&jogador1, 1);
        printf("\nTABULEIRO INIMIGO:\n");
        mostrarTabuleiro(&jogador2, 0);
        atirar(&jogador2);
        if (jogador2.partesRestantes == 0)
        {
            printf("\nJOGADOR 1 VENCEU!\n");
            break;
        }
        printf("\n=================================\n");
        printf("\tVEZ DO JOGADOR 2\n");
        printf("=================================\n");
        printf("\nSEU TABULEIRO:\n");
        mostrarTabuleiro(&jogador2, 1);
        printf("\nTABULEIRO INIMIGO:\n");
        mostrarTabuleiro(&jogador1, 0);
        atirar(&jogador1);
        if (jogador1.partesRestantes == 0)
        {
            printf("\nJOGADOR 2 VENCEU!\n");
            break;
        }
    }
    return 0;
}