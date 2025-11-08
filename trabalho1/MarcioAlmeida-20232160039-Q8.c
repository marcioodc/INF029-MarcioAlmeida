#include <stadio.h>
#include <string.h>

void main(){
  char tabuleiro[10][10];
  int linha, coluna;
  char jogador = 'X';
  int jogadas = 0;
  int venceu = 0;

  for(int i=0; i<3; i++){
    for(int j=0; j<3; j++){
      tabuleiro[i][j] = ' ';
    }
  }
  while(1){
    printf("\n   1   2   3\n");
    printf("A  %c |  %c |  %c ", tabuleiro[0][0], tabuleiro[0][1], tabuleiro[0][2]);
    printf("  ---+---+---\n");
    printf("B  %c |  %c |  %c ", tabuleiro[1][0], tabuleiro[1][1], tabuleiro[1][2]);
    printf("  ---+---+---+\n");
    printf("C  %c |  %c |  %c ", tabuleiro[2][0], tabuleiro[2][1], tabuleiro[2][2]);
    printf("\nJogador %c, informe a sua jogada: ", jogador);
    scanf("%c%d", &linhanum, colunanum;);

    if(linhanum == 'A' || linhanum == 'a'){
      linha = 0;
    }else if(linhanum == 'B' || linhanum == 'b'){
      linha = 1;
    }else if(linhanum == 'C' || linhanum == 'c'){
      linha = 2;
    }else{
      printf("\nJogada inválida!\n");
    }
    if(colunanum<1 || colunanum>3){
      printf("\nJogada inválida!\n");
    }
    coluna = colunanum - 1;
    if(tabuleiro[linha][coluna] != ' '){
      printf("\nPosição oculpada. Tente novamente!\n");
    }
    tabuleiro[linha][coluna] = jogador;
    jogador++;

    for(i=0; i<3; i++){
      if(tabuleiro[i][0]==jogador && tabuleiro[i][1]==jogador && tabuleiro[i][2]){
        venceu = 1;
      }
      if(tabuleiro[0][i]==jogador && tabuleiro[1][i]==jogador && tabuleiro[2][i]==jogador){
        venceu = 1;
      }
    }
    if(tabuleiro[0][0]==jogador && tabuleiro[1][1]==jogador && tabuleiro[2][2]==jogador){
      venceu = 1;
    }
    if(tabuleiro[0][2]==jogador && tabuleiro[1][1]==jogador && tabuleiro[2][0]==jogador){
      venceu = 1;
    }
    if(venceu){
      printf("\n   1   2   3\n");
      printf("A  %c |  %c |  %c ", tabuleiro[0][0], tabuleiro[0][1], tabuleiro[0][2]);
      printf("  ---+---+---\n");
      printf("B  %c |  %c |  %c ", tabuleiro[1][0], tabuleiro[1][1], tabuleiro[1][2]);
      printf("  ---+---+---+\n");
      printf("C  %c |  %c |  %c ", tabuleiro[2][0], tabuleiro[2][1], tabuleiro[2][2]);
      printf("\nJogador %c venceu!\n");
      break;
    }
    if(jogadas == 9){
      printf("\nEmpate\n");
      break;
    }
    if(jogador == 'X'){
      jogador = 'O'
    }else{
      jogador = 'X';
    }
  }
}
