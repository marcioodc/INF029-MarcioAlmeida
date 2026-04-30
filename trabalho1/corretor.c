// #################################################
//  Instituto Federal da Bahia
//  Salvador - BA
//  Curso de Análise e Desenvolvimento de Sistemas http://ads.ifba.edu.br
//  Disciplina: INF029 - Laboratório de Programação
//  Professor: Renato Novais - renato@ifba.edu.br

//  ----- Orientações gerais -----
//  Descrição: esse arquivo contém exemplos de testes das questões do trabalho.
//  o aluno pode incrementar os testes

//  Copyright © 2016 Renato Novais. All rights reserved.
// Última atualização: 19/08/2016 - 12/12/2018

// #################################################

#include <stdio.h>
#include <string.h>

// renomeie o arquivo do include abaixo para trabalho1.h
#include "MarcioAlmeida20232160039.h"

void testSomar();    // função utilizada para testes
void testFatorial(); // função utilizada para testes
void testQ1();
void testQ2();
void testQ3();
void testQ4();
void testQ5();
void testQ6();
void testQ7();

int main()
{
    /*testSomar();
    testFatorial();
    testQ1();
    testQ2();
    testQ3();
    testQ4();
    testQ5();*/
    testQ6();/*
    testQ7();*/
}

int ligado = 0;
void show_log(char *str)
{
    if (ligado)
        printf("###%s###\n", str);
}

void testSomar()
{
    show_log("testeSomar()");
    printf("01 %d\n", somar(3, 4) == 7);
    printf("02 %d\n", somar(-1, -3) == -4);
    printf("03 %d\n", somar(-6, 6) == 0);
    printf("04 %d\n", somar(74, 9) == 83);
    printf("05 %d\n", somar(30, -9) == 21);
    printf("06 %d\n", somar(-2, 8) == 6);
    printf("07 %d\n", somar(1000, 99) == 1099);
}

void testFatorial()
{
    show_log("testFatorial()");
    printf("08 %d\n", fatorial(3) == 6);
    printf("09 %d\n", fatorial(1) == 1);
    printf("10 %d\n", fatorial(5) == 120);
}

void testQ1()
{
    show_log("testQ1()");
    char str[11];
    strcpy(str, "29/02/2015");
    printf("11 %d\n", q1(str) == 0);
    strcpy(str, "29/02/2012");
    printf("12 %d\n", q1(str) == 1);
    strcpy(str, "9/13/2014");
    printf("13 %d\n", q1(str) == 0);
    strcpy(str, "45/4/2014");
    printf("14 %d\n", q1(str) == 0);
    strcpy(str, "/9/2014");
    printf("15 %d\n", q1(str) == 0);
}

void testQ2()
{
    show_log("testQ2()");
    char datainicial[11], datafinal[11];
    int qtdDias, qtdMeses, qtdAnos;
    DiasMesesAnos dma;

    // teste 1
    qtdDias = -1;
    qtdMeses = -1;
    qtdAnos = -1;

    strcpy(datainicial, "01/06/2015");
    strcpy(datafinal, "01/06/2016");
    dma = q2(datainicial, datafinal);
    printf("16 %d\n", dma.retorno == 1);
    printf("17 %d\n", dma.qtdDias == 0);
    printf("18 %d\n", dma.qtdMeses == 0);
    printf("19 %d\n", dma.qtdAnos == 1);

    // teste 2 - retornos
    qtdDias = -1;
    qtdMeses = -1;
    qtdAnos = -1;

    strcpy(datainicial, "01/30/2015");
    strcpy(datafinal, "01/06/2016");
    dma = q2(datainicial, datafinal);
    printf("20 %d\n", dma.retorno == 2);

    strcpy(datainicial, "01/3/2015");
    strcpy(datafinal, "40/06/2016");
    dma = q2(datainicial, datafinal);
    printf("21 %d\n", dma.retorno == 3);

    strcpy(datainicial, "01/06/2016");
    strcpy(datafinal, "01/06/2015");
    dma = q2(datainicial, datafinal);
    printf("22 %d\n", dma.retorno == 4);

    // teste 3
    qtdDias = -1;
    qtdMeses = -1;
    qtdAnos = -1;

    strcpy(datainicial, "06/06/2017");
    strcpy(datafinal, "07/07/2017");
    dma = q2(datainicial, datafinal);
    printf("23 %d\n", dma.retorno == 1);
    printf("24 %d\n", dma.qtdDias == 1);
    printf("25 %d\n", dma.qtdMeses == 1);
    printf("26 %d\n", dma.qtdAnos == 0);
}

void testQ3()
{
    show_log("testQ3()");
    char str[250];
    strcpy(str, "Renato Lima Novais");
    printf("27 %d\n", q3(str, 'a', 0) == 3);
    printf("28 %d\n", q3(str, 'b', 0) == 0);
    printf("29 %d\n", q3(str, 'l', 1) == 0);
    printf("30 %d\n", q3(str, 'l', 0) == 1);
    printf("31 %d\n", q3(str, 'L', 0) == 1);
}

void testQ4()
{
    show_log("testQ4()");
    char strTexto[250];
    char strBusca[50];
    int posicoes[30];
    int i;
    for (i = 0; i < 30; i++)
    {
        posicoes[i] = -1;
    }
    strcpy(strTexto, "Laboratorio de programacao: para ratos de programação");
    strcpy(strBusca, "rato");
    printf("32 %d\n", q4(strTexto, strBusca, posicoes) == 2);
    printf("33 %d\n", posicoes[0] == 5);
    printf("34 %d\n", posicoes[1] == 8);
    printf("35 %d\n", posicoes[2] == 34);
    printf("36 %d\n", posicoes[3] == 37);

    for (i = 0; i < 30; i++)
    {
        posicoes[i] = -1;
    }
    strcpy(strTexto, "Olá, o mundo é muito grande. Tem muitas pessoas, e muitos problemas");
    strcpy(strBusca, "mui");
    printf("37 %d\n", q4(strTexto, strBusca, posicoes) == 3);
    printf("38 %d\n", posicoes[0] == 16);
    printf("39 %d\n", posicoes[1] == 18);
    printf("40 %d\n", posicoes[2] == 34);
    printf("41 %d\n", posicoes[3] == 36);
    printf("42 %d\n", posicoes[4] == 52);
    printf("43 %d\n", posicoes[5] == 54);
}

void testQ5()
{
    show_log("testQ5()");
    printf("44 %d\n", q5(345) == 543);
    printf("45 %d\n", q5(78) == 87);
    printf("46 %d\n", q5(3) == 3);
    printf("47 %d\n", q5(5430) == 345);
}

void testQ6()
{
    show_log("testQ6()");
    printf("48 %d\n", q6(34567368, 3) == 2);
    printf("49 %d\n", q6(34567368, 4576) == 0);
    printf("50 %d\n", q6(3539343, 3) == 4);
    printf("51 %d\n", q6(3539343, 39) == 1);
}

void testQ7()
{
    show_log("testQ7()");
    char matrix[8][10] = {
        {'Q', 'M', 'J', 'D', 'L', 'A', 'Z', 'F', 'C', 'R'},
        {'N', 'B', 'Y', 'G', 'P', 'S', 'K', 'H', 'E', 'X'},
        {'V', 'O', 'W', 'U', 'T', 'I', 'Z', 'A', 'L', 'C'},
        {'M', 'Q', 'B', 'D', 'N', 'F', 'R', 'J', 'G', 'E'},
        {'H', 'S', 'K', 'T', 'U', 'X', 'W', 'O', 'P', 'Y'},
        {'C', 'Z', 'A', 'I', 'L', 'M', 'V', 'G', 'N', 'B'},
        {'D', 'F', 'E', 'H', 'S', 'K', 'J', 'Q', 'R', 'T'},
        {'U', 'X', 'Y', 'W', 'V', 'O', 'P', 'N', 'M', 'L'}};
    char stringBusca[6] = {'F', 'E', 'H', 'S', 'K'};
    printf("52 %d\n", q7(matrix, stringBusca) == 1);
    strcpy(stringBusca, "KJQRT");
    printf("53 %d\n", q7(matrix, stringBusca) == 1);
    strcpy(stringBusca, "AATOK");
    printf("54 %d\n", q7(matrix, stringBusca) == 0);
    strcpy(stringBusca, "LTBON");
    printf("55 %d\n", q7(matrix, stringBusca) == 1);
}
