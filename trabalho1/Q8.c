#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/*O programa deve sempre mostrar o tabuleiro do jogo da velha, com o jogador que
deve jogar; Jogador 2, informe sua jogada:
Cada jogador (jogador 1 e jogador 2) terá sua vez de jogar. O jogador um tem a
marca “X” e o jogador 2 a marca “0”.
O jogador deve informar a célula de interesse: ex: B3. O programa deve verificar
se é uma célula válida
O programa deve informar qual foi o ganhador, ou se não houve ganhador
Deve ter apresentação do tabuleiro a cada jogada
*/

void tabuleiro(char matriz[3][3])
{
    printf("\n\t    1   2   3 \n\t");
    printf("A   %c | %c | %c \n", matriz[0][0], matriz[0][1], matriz[0][2]);
    printf("\t");
    for (int m = 0; m < 15; m++)
        printf("-");
    printf("\n\t");
    printf("B   %c | %c | %c \n", matriz[1][0], matriz[1][1], matriz[1][2]);
    printf("\t");
    for (int m = 0; m < 15; m++)
        printf("-");
    printf("\n\t");
    printf("C   %c | %c | %c \n", matriz[2][0], matriz[2][1], matriz[2][2]);
}
int main()
{
    char matriz[3][3];
    int ganhou = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            matriz[i][j] = ' ';
        }
    }
    int vez = 1;
    printf("\n");
    printf("\n=================================\n");
    printf("\tJOGO DA VELHA\n");
    printf("=================================\n");
    for (int i = 0; i < 9; i++)
    {
        char jogador1 = 'X';
        char jogador2 = 'O';
        char jogada[3];
        tabuleiro(matriz);
        char jogador = (i % 2) == 0 ? jogador1 : jogador2;
        printf("\n=== Jogador %d ===\n", vez);
        printf("\nInforme sua jogada: ");
        scanf("%s", jogada);
        int linha = toupper(jogada[0]) - 'A';
        int coluna = jogada[1] - '1';
        if (linha < 0 || linha >= 3 || coluna < 0 || coluna >= 3 || matriz[linha][coluna] != ' ')
        {
            printf("Jogada inválida. Tente novamente.\n");
            i--;
            continue;
        }
        matriz[linha][coluna] = jogador;
        for (int j = 0; j < 3; j++)
        {
            if (matriz[j][0] == jogador && matriz[j][1] == jogador && matriz[j][2] == jogador)
            {
                ganhou = jogador;
                break;
            }
            if (matriz[0][j] == jogador && matriz[1][j] == jogador && matriz[2][j] == jogador)
            {
                ganhou = jogador;
                break;
            }
        }
        if (ganhou)
        {
            break;
        }
        if (matriz[0][0] == jogador && matriz[1][1] == jogador && matriz[2][2] == jogador)
        {
            ganhou = jogador;
            break;
        }
        if (matriz[0][2] == jogador && matriz[1][1] == jogador && matriz[2][0] == jogador)
        {
            ganhou = jogador;
            break;
        }
        vez = (vez == 1) ? 2 : 1;
    }
    tabuleiro(matriz);
    if (ganhou)
    {
        printf("\n\n=================================\n");
        printf("\tJOGADOR %d VENCEU!\n", vez);
        printf("=================================\n");
    }
    else
    {
        printf("\n\n=================================\n");
        printf("\tEMPATE!\n");
        printf("=================================\n");
    }
    return 0;
}