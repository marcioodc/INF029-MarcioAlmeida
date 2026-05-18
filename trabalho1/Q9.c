#include <stdio.h>
#include <ctype.h>
#include <string.h>

/*Faça um programa que implemente o jogo de batalha naval
O número de navios de guerra deve ser um parâmetro global. Precisando
aumentar a quantidade de navios, o programador deve apenas mudar esse valor. Deve
ter pelo menos 1 barco de tamanho 4, 1 de tamanho 3, 3 barcos de tamanho 1. Os
demais barcos, se existirem devem ser obrigatoriamente de tamanho 2. Desta forma, o
número mínimo de barco é: 5 barcos. O número máximo de barcos é 10.
O tabuleiro de cada jogador deve ser uma matriz 10 x 10. d)
Cada jogador, no início do jogo deve dizer onde vai posicionar, cada um dos seus barcos. O programa
deve controlar se os barcos estão posicionados de forma correta. Use a seguinte
configuração para representar o mapa:
[   ] espaço em branco-> posição do mar sem nada (e.g. barco, tiro do
oponente, tiro do jogador.
[ N ] Navio posicionado
[ 0 ] Posição do navio abatida
[ X ] Tiro inválido
O programa deve ter uma função para o jogador poder Listar o tabuleiro.
- Em seu tabuleiro ele deve ver seus barcos, os tiros do oponente e os
espaços em branco.
- No tabuleiro do adversário deve ver seus tiros certeiros e seus tiros errados
O programa deve ter a função para o jogador atirar, onde ele deve escolher uma
célula da matriz para jogar.
Cada jogador joga uma vez, depois é a vez do oponente.
Vence o jogador que acertar todos os navios do oponente primeiro
Faça divida o problema em pequenas funções, e utilize o conceito de modularização. O programa deve ser escrito em C. O código deve ser bem documentado, O programa deve ser testado com diferentes jogadas para garantir que está funcionando corretamente.
*/

void inicializarTabuleiro(char tabuleiro[10][10]);
void imprimirTabuleiro(char tabuleiro[10][10]);
int posicionarBarcos(char tabuleiro[10][10], int numBarcos);

int main()
{
    printf("Jogo de Batalha Naval\n");
    for (int i = 0; i < 10; i++)
        printf("-");
    printf("\n");
    printf("Número de navios: %d\n", 5);
    printf("Configuração dos navios:\n");
    printf("1 navio de tamanho 4\n");
    printf("1 navio de tamanho 3\n");
    printf("3 navios de tamanho 1\n");
    printf("4 navios de tamanho 2\n");
    printf("Configuração do tabuleiro:\n");
    printf("[   ] espaço em branco-> posição do mar sem nada (e.g. barco, tiro do oponente, tiro do jogador.\n");
    printf("[ N ] Navio posicionado\n");
    printf("[ 0 ] Posição do navio abatida\n");
    printf("[ X ] Tiro inválido\n");
    char tabuleiro[10][10];
    char tabuleiroAdversario[10][10];
    char ataque[3];
    inicializarTabuleiro(tabuleiro);
    posicionarBarcos(tabuleiro, 5);
    printf("Tabuleiro do jogador:\n");
    imprimirTabuleiro(tabuleiro);
    printf("O jogo começa agora!\n");
    printf("Jogador 1, é sua vez de atirar!\n");
    scanf("%s", ataque);
    if (ataque(tabuleiro, tabuleiroAdversario, ataque) == 1)
    {
        printf("Parabéns! Você acertou um navio!\n");
        printf("Tabuleiro do adversário:\n");
        imprimirTabuleiro(tabuleiroAdversario);
    }

    return 0;
}
int ataque(char tabuleiro[10][10], char tabuleiroAdversario[10][10], char ataque[3])
{
    int linha = toupper(ataque[0]) - 'A' + 1;
    int coluna = ataque[1] - '1' + 1;

    if (tabuleiro[linha][coluna] == 'N')
    {
        tabuleiro[linha][coluna] = '0';
        tabuleiroAdversario[linha][coluna] = '0';
        return 1;
    }
    else if (tabuleiro[linha][coluna] == ' ')
    {
        tabuleiro[linha][coluna] = 'X';
        tabuleiroAdversario[linha][coluna] = 'X';
        printf("Tiro errado!\n");
        return 0;
    }
    else
    {
        printf("Tiro inválido! Você já atirou nessa posição.\n");
        return -1;
    }
}

void inicializarTabuleiro(char tabuleiro[10][10])
{
    for (int i = 1; i <= 10; i++)
    {
        for (int j = 1; j <= 10; j++)
        {
            tabuleiro[i][j] = ' ';
        }
    }
}

void imprimirTabuleiro(char tabuleiro[10][10])
{
    printf("   ");
    for (int j = 1; j <= 10; j++)
    {
        printf("%2d ", j);
    }
    printf("\n");
    for (int i = 1; i <= 10; i++)
    {
        printf("%2d ", i);
        for (int j = 1; j <= 10; j++)
        {
            printf("[%c]", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int posicionarBarcos(char tabuleiro[10][10], int numBarcos)
{
    imprimirTabuleiro(tabuleiro);
    while (numBarcos > 0)
    {
        char tipoBarco;
        int linha, coluna, orientacao;
        printf("Posicione seu barco (Tamanho Linha Coluna Orientacao): ", numBarcos);
        scanf(" %c %d %d %d", &tipoBarco, &linha, &coluna, &orientacao);
        if (tipoBarco != '4' && tipoBarco != '3' && tipoBarco != '2' && tipoBarco != '1')
        {
            printf("Tipo de barco inválido. Tente novamente.\n");
            continue;
        }
        if (linha < 1 || linha > 10 || coluna < 1 || coluna > 10)
        {
            printf("Posição inválida. Tente novamente.\n");
            continue;
        }
        if (orientacao != 0 && orientacao != 1)
        {
            printf("Orientação inválida. Tente novamente.\n");
            continue;
        }
        int tamanhoBarco = tipoBarco - '0';
        int fimLinha = linha + (orientacao == 0 ? 0 : tamanhoBarco - 1);
        int fimColuna = coluna + (orientacao == 1 ? 0 : tamanhoBarco - 1);
        if (fimLinha > 10 || fimColuna > 10)
        {
            printf("Barco não cabe no tabuleiro. Tente novamente.\n");
            continue;
        }
        int podePosicionar = 1;
        for (int i = linha; i <= fimLinha; i++)
        {
            for (int j = coluna; j <= fimColuna; j++)
            {
                if (tabuleiro[i][j] != ' ')
                {
                    podePosicionar = 0;
                    break;
                }
            }
            if (!podePosicionar)
            {
                break;
            }
        }
        if (podePosicionar)
        {
            for (int i = linha; i <= fimLinha; i++)
            {
                for (int j = coluna; j <= fimColuna; j++)
                {
                    tabuleiro[i][j] = 'N';
                }
            }
        }
        else
        {
            printf("Já existe um barco nessa posição. Tente novamente.\n");
            continue;
        }
        imprimirTabuleiro(tabuleiro);
        numBarcos--;
    }
    return 0;
}