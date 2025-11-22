#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define TAM 10

// valores no tabuleiro:
// 0 = vazio
// 1 = navio (N)
// 2 = tiro errado (X)
// 3 = acerto (O)

void read_line(char *buf, int n) {
    if(!fgets(buf, n, stdin)){
        buf[0] = '\0';
        return;
    }
    size_t L = strlen(buf);
    if(L > 0 && buf[L-1] == '\n'){
        buf[L-1] = '\0';
    }
}

int parseCell(const char *s, int *r, int *c){
    if(!s || strlen(s) < 2){
        return 0;
    }
    char rowChar = toupper(s[0]);
    if(rowChar < 'A' || rowChar > 'J'){
        return 0;
    }
    int col;
    if(sscanf(s+1, "%d", &col) != 1){
        return 0;
    }
    if(col < 1 || col > TAM){
        return 0;
    }
    *r = rowChar - 'A';
    *c = col - 1;
    return 1;
}

void inicializar(int tab[TAM][TAM]){
    for(int i=0;i<TAM;i++){
        for(int j=0;j<TAM;j++){
            tab[i][j] = 0;
        }
    }
}

void Tab_Jogador(int tab[TAM][TAM]){
    printf("   ");
    for(int j=1; j<=TAM; j++){
        printf("%2d ", j);
        printf("\n");
    }
    for(int i=0; i<TAM; i++){
        printf(" %c ", 'A' + i);
        for(int j=0; j<TAM; j++){
            if(tab[i][j] == 0){
                printf(" . ");
            }else if(tab[i][j] == 1){
                printf(" N ");
            }else if(tab[i][j] == 2){
                printf(" X ");
            }else if(tab[i][j] == 3){
                printf(" O ");
            }
        }
        printf("\n");
    }
}

void Tab_Adversario(int tiros[TAM][TAM]){
    printf("   ");
    for(int j=1; j<=TAM; j++){
        printf("%2d ", j);
    }
    printf("\n");
    for(int i=0; i<TAM; i++){
        printf(" %c ", 'A' + i);
        for (int j=0; j<TAM; j++){
            if (tiros[i][j] == 0){
                printf(" . ");
            }else if(tiros[i][j] == 2){
                printf(" X ");
            }else if(tiros[i][j] == 3){
                printf(" O ");
            }else{
              printf(" . ");
            }
        }
        printf("\n");
    }
}

int podeColocar(int tab[TAM][TAM], int linha, int coluna, int tam, char dir) {
    if(linha<0 || linha>=TAM || coluna<0 || coluna>=TAM){
        return 0;
    }
    if(dir == 'H'){
        if(coluna + tam > TAM){
          return 0;
        }
        for(int j=0; j<tam; j++){
            if(tab[linha][coluna+j] != 0){
                return 0;
            }
        }
    }else{
        if(linha + tam > TAM){
            return 0;
        }
        for(int i=0; i<tam; i++){
            if(tab[linha+i][coluna] != 0){
              return 0;
            }
        }
    }
    return 1;
}

void colocar(int tab[TAM][TAM], int linha, int coluna, int tam, char dir) {
    if(dir == 'H'){
        for(int j=0; j<tam; j++){
            tab[linha][coluna+j] = 1;
        }
    }else{
        for(int i=0; i<tam; i++){
            tab[linha+i][coluna] = 1;
        }
    }
}

void pos_navio(int tab[TAM][TAM], int jogador){
    char buf[64];
    int r,c;
    char dir;
    printf("\n--- Jogador %d: posicione seus navios ---\n", jogador);
    while(1){
        printf("Barco tamanho 4 - informe a posição inicial e direção H/V");
        printf("\nH - horizontal |  V - vertical");
        read_line(buf, sizeof(buf));
        char cell[8], d;
        if(sscanf(buf, "%s %c", cell, &d) >= 1){
            if(!parseCell(cell, &r, &c)){ 
                printf("Entrada inválida. Tente novamente.\n"); 
                continue; 
            }
            dir = toupper(d);
            if(dir != 'H' && dir != 'V'){ 
                printf("Direção inválida. H ou V.\n"); 
                continue; 
            }
            if(!podeColocar(tab, r, c, 4, dir)){ 
               printf("Não cabe ou colide. Tente outra posição.\n"); 
                continue; 
            }
            colocar(tab, r, c, 4, dir);
            break;
        } else{ 
          printf("Formato inválido.\n");
        }
    }

    while(1){
        printf("Barco tamanho 3 - informe a posição inicial e direção H/V");
        printf("\nH - horizontal  |  V - vertical: ");
        read_line(buf, sizeof(buf));
        char cell[8]; char d;
        if(sscanf(buf, "%s %c", cell, &d) >= 1){
            if(!parseCell(cell, &r, &c)){ 
              printf("Entrada inválida. Tente novamente.\n");
              continue; 
            }
            dir = toupper(d);
            if(dir != 'H' && dir != 'V'){ 
                printf("Direção inválida. H ou V.\n"); 
                continue; 
            }
            if(!podeColocar(tab, r, c, 3, dir)){ 
                printf("Não cabe ou colide. Tente outra posição.\n"); 
                continue; 
            }
            colocar(tab, r, c, 3, dir);
            break;
        } else{
            printf("Formato inválido.\n");
        }
    }

    for(int i=1; i<=3; i++){
        while(1){
            printf("Barco tamanho 1 (%d/3) - informe a posição: ", i);
            read_line(buf, sizeof(buf));
            if(!parseCell(buf, &r, &c)){
                printf("Entrada inválida. Tente novamente.\n");
                continue; 
            }
            if(!podeColocar(tab, r, c, 1, 'H')){ 
                printf("Posição ocupada. Tente outra.\n");
                continue; 
            }
            colocar(tab, r, c, 1, 'H');
            break;
        }
    }
    printf("\nPosicionamento concluído para jogador %d.\n", jogador);
}

int contarNavios(int tab[TAM][TAM]){
    int cont = 0;
    for (int i=0; i<TAM; i++){
        for (int j=0; j<TAM; j++){
            if (tab[i][j] == 1){
                cont++;
            }
        }
    }
    return cont;
}

int atirar(int tabAlvo[TAM][TAM], int tirosDoJogador[TAM][TAM], int linha, int coluna){
    if(tirosDoJogador[linha][coluna] != 0){
        return -1;
    }
    if(tabAlvo[linha][coluna] == 1){
        tabAlvo[linha][coluna] = 3;      
        tirosDoJogador[linha][coluna] = 3;
        return 1;
    }else{
        if(tabAlvo[linha][coluna] == 0){
            tabAlvo[linha][coluna] = 2;
        }
        tirosDoJogador[linha][coluna] = 2;
        return 0;
    }
}

int main(){
    int barcos1[TAM][TAM], barcos2[TAM][TAM];
    int tiros1[TAM][TAM], tiros2[TAM][TAM];
    inicializar(barcos1); inicializar(barcos2);
    inicializar(tiros1); inicializar(tiros2);
    pos_navio(barcos1, 1);
    pos_navio(barcos2, 2);

    int vez = 1;
    char buf[64];
    int r,c;
    int restante1 = contarNavios(barcos1);
    int restante2 = contarNavios(barcos2);
    while(1){
        if(vez == 1){
            printf("\n---Jogador 1---\n");
            printf("Seu tabuleiro:\n");
            Tab_Jogador(barcos1);
            printf("\nPosições jogadas:\n");
            Tab_Adversario(tiros1);
            while(1){
                printf("Jogador 1, informe a posição que deseja atirar: ");
                read_line(buf, sizeof(buf));
                if(!parseCell(buf, &r, &c)){ 
                    printf("Entrada inválida. Use A-J e 1-10.\n"); 
                    continue; 
                }
                int res = atirar(barcos2, tiros1, r, c);
                if(res == -1){ 
                    printf("Você já atirou nessa posição. Tente outra.\n");
                    continue; 
                }
                if(res == 1){
                    printf("ACERTOU!\n");
                    restante2 = contarNavios(barcos2);
                    if(restante2 == 0){
                        printf("\nJogador 1 venceu! Acertou todos os navios do oponente.\n");
                        return 0;
                    }
                }else{
                    printf("ÁGUA.\n");
                }
                break;
            }
            vez = 2;
        }else{
            printf("\n---Jogador 2---\n");
            printf("Seu tabuleiro:\n");
            Tab_Jogador(barcos2);
            printf("\nPosições jogadas:\n");
            Tab_Adversario(tiros2);
            while(1){
                printf("Jogador 2, informe a posição que deseja atirar: ");
                read_line(buf, sizeof(buf));
                if (!parseCell(buf, &r, &c)){ 
                    printf("Entrada inválida. Use A-J e 1-10.\n"); 
                    continue;
                }
                int res = atirar(barcos1, tiros2, r, c);
                if (res == -1){ 
                    printf("Você já atirou nessa posição. Tente outra.\n"); 
                    continue;
                }
                if (res == 1){
                    printf("ACERTOU!\n");
                    restante1 = contarNavios(barcos1);
                    if (restante1 == 0){
                        printf("\nJogador 2 venceu! Acertou todos os navios do oponente.\n");
                        return 0;
                    }
                } else {
                    printf("ÁGUA.\n");
                }
                break;
            }
            vez = 1;
        } 
        printf("Pressione ENTER para passar a vez...");
        read_line(buf, sizeof(buf));
    }
    return 0;
}
