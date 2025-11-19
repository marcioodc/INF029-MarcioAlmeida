// #################################################
//  Instituto Federal da Bahia
//  Salvador - BA
//  Curso de Análise e Desenvolvimento de Sistemas http://ads.ifba.edu.br
//  Disciplina: INF029 - Laboratório de Programação
//  Professor: Renato Novais - renato@ifba.edu.br

//  ----- Orientações gerais -----
//  Descrição: esse arquivo deve conter as questões do trabalho do aluno.
//  O aluno deve preencher seus dados abaixo, e implementar as questões do trabalho

//  ----- Dados do Aluno -----
//  Nome: Marcio Victor dos Santos Almeida
//  email: marcio203v1@gmail.com
//  Matrícula: 20232160039
//  Semestre: 2025.2

//  Copyright © 2016 Renato Novais. All rights reserved.
// Última atualização: 07/05/2021 - 19/08/2016 - 17/10/2025

// #################################################

#include <stdio.h>
#include "trabalho1.h" 
#include <stdlib.h>
#include <string.h>

DataQuebrada quebraData(char data[]);
/*

## função utilizada para testes  ##

 somar = somar dois valores
@objetivo
    Somar dois valores x e y e retonar o resultado da soma
@entrada
    dois inteiros x e y
@saida
    resultado da soma (x + y)
 
int somar(int x, int y)
{
    int soma;
    soma = x + y;
    return soma;
}


## função utilizada para testes  ##

 fatorial = fatorial de um número
@objetivo
    calcular o fatorial de um número
@entrada
    um inteiro x
@saida
    fatorial de x -> x!
 
int fatorial(int x)
{ //função utilizada para testes
  int i, fat = 1;
    
  for (i = x; i > 1; i--)
    fat = fat * i;
    
  return fat;
}

int teste(int a)
{
    int val;
    if (a == 2)
        val = 3;
    else
        val = 4;

    return val;
}


 Q1 = validar data
@objetivo
    Validar uma data
@entrada
    uma string data. Formatos que devem ser aceitos: dd/mm/aaaa, onde dd = dia, mm = mês, e aaaa, igual ao ano. dd em mm podem ter apenas um digito, e aaaa podem ter apenas dois digitos.
@saida
    0 -> se data inválida
    1 -> se data válida
 @restrições
    Não utilizar funções próprias de string (ex: strtok)   
    pode utilizar strlen para pegar o tamanho da string
 */
int bissexto(int ano){
  if((ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0)){
	return 1;
  }else{
	return 0;
  }
}

int q1(char data[]){
  int i=0;
  int dia=0;
  int mes=0;
  int ano=0;
  int cont=0;
  while(data[i] >= '0' && data[i] <= '9' && cont < 2){
	  dia = dia * 10 + (data[i] - '0');
	  i++;
	  cont++;
  }
  if(data[i++] != '/'){
	  return 0;
  }
  cont = 0;
  while(data[i] >= '0' && data[i] <= '9' && cont < 2){
	  mes = mes * 10 + (data[i] - '0');
	  i++;
	  cont++;
  }
  if(data[i++] != '/'){
	  return 0;
  }
  cont = 0;
  while(data[i] >= '0' && data[i] <= '9' && cont < 4){
	  ano = ano * 10 + (data[i] - '0');
	  i++;
	  cont++;
  }
  if(data[i] != '\0'){
	  return 0;
  }
  int diasmes[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
  if(bissexto(ano)){
	  diasmes[2] = 29;
  }
  if(dia<1 || dia>diasmes[mes]){
	  return 0;
  }
  if(mes<1 || mes>12){
	  return 0;
  }
  if(ano<1){
	  return 0;
  }
  return 1;
}

/*
 Q2 = diferença entre duas datas
 @objetivo
    Calcular a diferença em anos, meses e dias entre duas datas
 @entrada
    uma string datainicial, uma string datafinal. 
 @saida
    Retorna um tipo DiasMesesAnos. No atributo retorno, deve ter os possíveis valores abaixo
    1 -> cálculo de diferença realizado com sucesso
    2 -> datainicial inválida
    3 -> datafinal inválida
    4 -> datainicial > datafinal
    Caso o cálculo esteja correto, os atributos qtdDias, qtdMeses e qtdAnos devem ser preenchidos com os valores correspondentes.
 */

DiasMesesAnos q2(char datainicial[], char datafinal[]){
  DiasMesesAnos dma = {0,0,0,0};
  if (q1(datainicial) == 0){
      dma.retorno = 2;
      return dma;
  }else if (q1(datafinal) == 0){
      dma.retorno = 3;
      return dma;
  }
  int dia_inicial, mes_inicial, ano_inicial;
  int dia_final, mes_final, ano_final;
  quebraData(datainicial);
  quebraData(datafinal);
  if(ano_final < ano_inicial){
	  dma.retorno = 4;
	  return dma;
  }else if(ano_final == ano_inicial && mes_final < mes_inicial){
	  dma.retorno = 4;
	  return dma;
  }else if(ano_final == ano_inicial && mes_final == mes_inicial && dia_final < dia_inicial){
	  dma.retorno = 4;
	  return dma;
  }
  dma.qtdAnos= ano_final - ano_inicial;
  dma.qtdMeses= mes_final - mes_inicial;
  dma.qtdDias= dia_final - dia_inicial;
  if(dma.qtdDias < 0){
	  int diasmes[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
	  int mes_anterior;
	  int ano_ref;
	  if(mes_final == 1){
          mes_anterior = 12;
		  ano_ref = ano_final - 1;
	  }else{
		  mes_anterior = mes_final - 1;
		  ano_ref = ano_final;
	  }
	  if(bissexto(ano_ref)){
		  diasmes[2] = 29;
	  }
	  dma.qtdDias += diasmes[mes_anterior];
	  dma.qtdMeses--;
  }
  if(dma.qtdMeses < 0){
	  dma.qtdMeses += 12;
	  dma.qtdAnos--;
  }
  dma.retorno = 1;
  return dma;
      
}


/*
 Q3 = encontrar caracter em texto
 @objetivo
    Pesquisar quantas vezes um determinado caracter ocorre em um texto
 @entrada
    uma string texto, um caracter c e um inteiro que informa se é uma pesquisa Case Sensitive ou não. Se isCaseSensitive = 1, a pesquisa deve considerar diferenças entre maiúsculos e minúsculos.
        Se isCaseSensitive != 1, a pesquisa não deve  considerar diferenças entre maiúsculos e minúsculos.
 @saida
    Um número n >= 0.
 */
int q3(char *texto, char c, int isCaseSensitive){
    int qtdOcorrencias = -1;
    int i = 0;
	if(isCaseSensitive != 1 && c >= 'A' && c<= 'Z'){
		c = c + 32;
  }
  while(texto[i] != '\0'){
    char atual = texto[i];
    if(isCaseSensitive != 1 && atual >= 'A' && atual <= 'Z'){
      atual = atual + 32;
    }
    if(atual == c){
      qtdOcorrencias++;
    }
    i++;
  }
  return qtdOcorrencias;
}

/*
 Q4 = encontrar palavra em texto
 @objetivo
    Pesquisar todas as ocorrências de uma palavra em um texto
 @entrada
    uma string texto base (strTexto), uma string strBusca e um vetor de inteiros (posicoes) que irá guardar as posições de início e fim de cada ocorrência da palavra (strBusca) no texto base (texto).
 @saida
    Um número n >= 0 correspondente a quantidade de ocorrências encontradas.
    O vetor posicoes deve ser preenchido com cada entrada e saída correspondente. Por exemplo, se tiver uma única ocorrência, a posição 0 do vetor deve ser preenchido com o índice de início do texto, e na posição 1, deve ser preenchido com o índice de fim da ocorrencias. Se tiver duas ocorrências, a segunda ocorrência será amazenado nas posições 2 e 3, e assim consecutivamente. Suponha a string "Instituto Federal da Bahia", e palavra de busca "dera". Como há uma ocorrência da palavra de busca no texto, deve-se armazenar no vetor, da seguinte forma:
        posicoes[0] = 13;
        posicoes[1] = 16;
        Observe que o índice da posição no texto deve começar ser contado a partir de 1.
        O retorno da função, n, nesse caso seria 1;

 */
int q4(char *strTexto, char *strBusca, int posicoes[30])
{
  int qtdOcorrencias = -1;
  int tambusca = strlen(strBusca);
  int tamtexto = strlen(strTexto);
  for(int i=0; i<=tamtexto - tambusca; i++){
    int encontrou = 1;
    for(int j=0; j<tambusca; j++){
      if(strTexto[i+j] != strBusca[j]){
        encontrou = 0;
        break;
      }
      if(encontrou){
        posicoes[qtdOcorrencias * 2] = i + 1;
        posicoes[qtdOcorrencias * 2 + 1] = i + tambusca;
        qtdOcorrencias++;
      }
    }
  }
  return qtdOcorrencias;
}


 /*Q5 = inverte número
 @objetivo
    Inverter número inteiro
 @entrada
    uma int num.
 @saida
    Número invertido
 */

int q5(int num)
{
  int invertido = 0;
  while(num != 0){
	int digito = num % 10;
	invertido = invertido * 10 + digito;
	num = num / 10;
  }
  num = invertido;
  return num;
}

/*
 Q6 = ocorrência de um número em outro
 @objetivo
    Verificar quantidade de vezes da ocorrência de um número em outro
 @entrada
    Um número base (numerobase) e um número de busca (numerobusca).
 @saida
    Quantidade de vezes que número de busca ocorre em número base
 
*/
int q6(int numerobase, int numerobusca)
{
  int qtdOcorrencias;
  char baseStr[50];
  char buscaStr[50];
  int i = 0;
  int j=0;
  if(numerobase == 0){
	  baseStr[i++] = '0';
  }else{
	  int temp = numerobase;
	  int digitos[50];
	  int n = 0;
      while(temp > 0){
		  digitos[n++] = temp % 10;
		  temp /= 10;
	  }
	  for(int d=n-1; d>=0; d--){
		  baseStr[i++] = digitos[d] + '0';
	  }
  }
  baseStr[i] = '\0';
  if(numerobusca == 0){
	  buscaStr[j++] = '\0';
  }else{
	  int temp = numerobusca;
	  int digitos[50];
	  int n = 0;
      while(temp > 0){
		  digitos[n++] = temp % 10;
		  temp /= 10;
	  }
	  for(int d=n-1; d>=0; d--){
		  buscaStr[j++] = digitos[d] + '0';
	  }
  }
  buscaStr[j] = '\0';
  int tambase = strlen(baseStr);
  int tambusca = strlen(buscaStr);
  for(i=0; i<=tambase - tambusca; i++){
	  int encontrou = 1;
	  for(int k=0; k<tambusca;k++){
		  if(baseStr[i+k] != buscaStr[k]){
			  encontrou = 0;
			  break;
		  }
		  if(encontrou){
			  qtdOcorrencias++;
		  }
	  }
  }
  return qtdOcorrencias;
}

/*
 Q7 = jogo busca palavras
 @objetivo
    Verificar se existe uma string em uma matriz de caracteres em todas as direções e sentidos possíves
 @entrada
    Uma matriz de caracteres e uma string de busca (palavra).
 @saida
    1 se achou 0 se não achou
 
*/
 int q7(char matriz[8][10], char palavra[5])
 {
  int achou = 0;
  int tampalavra = strlen(palavra);
  int direcoes[8][2] = {{0,-1},{0,1},{1,0},{-1,0},{1,1},{-1,-1},{-1,1},{1,-1}};
  for(int i=0; i<8; i++){
	  for(int j=0; j<10; j++){
		  for(int d=0; d<8; d++){
			  int dx = direcoes[d][0];
			  int dy = direcoes[d][1];
			  int x=i, y=j;
			  int encontrou = 1;
			  for(int k=0; k<tampalavra; k++){
				  if(x<0 || x>=8 || y<0 || y>=10){
					  encontrou = 0;
					  break;
				  }
				  if(matriz[x][y] != palavra[k]){
					  encontrou = 0;
					  break;
				  }
				  x += dx;
				  y += dy;
			  }
			  if(encontrou){
				  achou = 1;
				  return achou;
			  }
		  }
	  }	
  }
  return achou;
 }

DataQuebrada quebraData(char data[]){
  DataQuebrada dq;
  char sDia[3];
	char sMes[3];
	char sAno[5];
	int i; 

	for (i = 0; data[i] != '/'; i++){
		sDia[i] = data[i];	
	}
	if(i == 1 || i == 2){ 
		sDia[i] = '\0'; 
	}else {
		dq.valido = 0;
    return dq;
  }
	int j = i + 1; 
	i = 0;
	for (; data[j] != '/'; j++){
		sMes[i] = data[j];
		i++;
	}
	if(i == 1 || i == 2){ 
		sMes[i] = '\0'; 
	}else {
		dq.valido = 0;
    return dq;
  }
	j = j + 1;
	i = 0;
	for(; data[j] != '\0'; j++){
	 	sAno[i] = data[j];
	 	i++;
	}
	if(i == 2 || i == 4){
		sAno[i] = '\0';  
	}else {
		dq.valido = 0;
    return dq;
  }
  dq.iDia = atoi(sDia);
  dq.iMes = atoi(sMes);
  dq.iAno = atoi(sAno); 
	dq.valido = 1;
    
  return dq;
}
