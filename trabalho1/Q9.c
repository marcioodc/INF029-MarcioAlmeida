#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

/*Faça um programa que implemente o jogo de batalha naval.

O número de navios de guerra deve ser um parâmetro global.
Deve:
1 barco de tamanho 4
1 de tamanho 3
3 barcos de tamanho 1.
Os demais barcos, se existirem devem ser obrigatoriamente de tamanho 2.
Desta forma, o número mínimo de barco é: 5 barcos.
O tabuleiro de cada jogador deve ser uma matriz 10 x 10.
Cada jogador, no início do jogo deve dizer onde vai posicionar, cada um dos seus barcos. O programa
deve controlar se os barcos estão posicionados de forma correta
Use a seguinte configuração para representar o mapa:
[   ] espaço em branco-> posição do mar sem nada (e.g. barco, tiro do
oponente, tiro do jogador)
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
Vence o jogador que acertar todos os navios do oponente primeiro*/
