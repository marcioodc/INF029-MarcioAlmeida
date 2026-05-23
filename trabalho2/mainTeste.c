#include <stdio.h>
#include <stdlib.h>

#include "trabalho2.h"

void show_log(char *str);

void testeInserirSemNada();
void testeCriarEstrutura();
void testeInserirComEstrutura();
void testeExcluir();
void testeExcluirNumeroEspecifico();
void testeListar();
void testeRetornarTodosNumeros();
void testeMudarTamanhoEstrutura();
void testeListaEncadeada();

int main()
{
    inicializar();
    testeInserirSemNada();
    testeCriarEstrutura();
    // testeInserirComEstrutura();
    //  testeExcluir();
    //    testeExcluirNumeroEspecifico();
    //    testeListar();
    //    testeRetornarTodosNumeros();
    //    testeMudarTamanhoEstrutura();
    //    testeListaEncadeada();
    finalizar();
}
int ligado = 0;
void show_log(char *str)
{
    if (ligado)
        printf("###%s###\n", str);
}

void testeInserirSemNada()
{
    show_log("testeInserirSemNada()");
    printf("01 %d\n", inserirNumeroEmEstrutura(2, 2) == SEM_ESTRUTURA_AUXILIAR);
    printf("02 %d\n", inserirNumeroEmEstrutura(-2, 2) == POSICAO_INVALIDA);
    printf("03 %d\n", inserirNumeroEmEstrutura(0, 2) == POSICAO_INVALIDA);
    printf("04 %d\n", inserirNumeroEmEstrutura(11, 2) == POSICAO_INVALIDA);
}

void testeCriarEstrutura()
{
    show_log("testeCriarEstrutura()");
    printf("05 %d\n", criarEstruturaAuxiliar(-2, 5) == POSICAO_INVALIDA);
    printf("06 %d\n", criarEstruturaAuxiliar(0, 5) == POSICAO_INVALIDA);
    printf("07 %d\n", criarEstruturaAuxiliar(11, 5) == POSICAO_INVALIDA);
    printf("08 %d\n", criarEstruturaAuxiliar(2, -5) == TAMANHO_INVALIDO);
    printf("09 %d\n", criarEstruturaAuxiliar(2, 0) == TAMANHO_INVALIDO);
    printf("10 %d\n", criarEstruturaAuxiliar(2, 3) == SUCESSO);
    printf("11 %d\n", criarEstruturaAuxiliar(2, 6) == JA_TEM_ESTRUTURA_AUXILIAR);
}
/*
2 [ , , ]
*/

void testeInserirComEstrutura()
{
    show_log("testeInserirComEstrutura()");
    // ###  int inserirNumeroEmEstrutura(int valor, int posicao); ###
    printf("12 %d\n", inserirNumeroEmEstrutura(2, 4) == SUCESSO);
    printf("13 %d\n", inserirNumeroEmEstrutura(2, -2) == SUCESSO);
    printf("14 %d\n", inserirNumeroEmEstrutura(2, 6) == SUCESSO);
    printf("15 %d\n", inserirNumeroEmEstrutura(2, 5) == SEM_ESPACO);
}
/*
2 [4,-2,6]
*/
void testeExcluir()
{
    show_log("testeExcluir()");
    // ###  int excluirNumeroDoFinaldaEstrutura(int posicao); ###
    printf("16 %d\n", excluirNumeroDoFinaldaEstrutura(2) == SUCESSO);
    printf("17 %d\n", excluirNumeroDoFinaldaEstrutura(2) == SUCESSO);
    printf("18 %d\n", excluirNumeroDoFinaldaEstrutura(0) == POSICAO_INVALIDA);
    printf("19 %d\n", excluirNumeroDoFinaldaEstrutura(1) == SEM_ESTRUTURA_AUXILIAR);
    printf("20 %d\n", excluirNumeroDoFinaldaEstrutura(2) == SUCESSO);
    printf("21 %d\n", excluirNumeroDoFinaldaEstrutura(2) == ESTRUTURA_AUXILIAR_VAZIA);
}

/*
2 [ , , ]
*/

void testeExcluirNumeroEspecifico()
{
    show_log("testeExcluirNumeroEspecifico()");
    // ###  int excluirNumeroEspecificoDeEstrutura(int posicao, int valor); ###
    printf("22 %d\n", criarEstruturaAuxiliar(9, 3) == SUCESSO);
    printf("23 %d\n", inserirNumeroEmEstrutura(9, 7) == SUCESSO);
    printf("24 %d\n", inserirNumeroEmEstrutura(9, 4) == SUCESSO);
    printf("25 %d\n", excluirNumeroEspecificoDeEstrutura(9, 12) == NUMERO_INEXISTENTE);
    printf("26 %d\n", excluirNumeroEspecificoDeEstrutura(9, 7) == SUCESSO);
    printf("27 %d\n", excluirNumeroEspecificoDeEstrutura(9, 4) == SUCESSO);
    printf("28 %d\n", excluirNumeroEspecificoDeEstrutura(1, 2) == SEM_ESTRUTURA_AUXILIAR);
}
/*
9 [ 4, , ]
*/

void testeListar()
{
    show_log("testeListar()");
    // ###  int getDadosEstruturaAuxiliar(int posicao, int vetorAux[]); ###
    printf("29 %d\n", inserirNumeroEmEstrutura(2, 7) == SUCESSO);
    printf("30 %d\n", inserirNumeroEmEstrutura(2, -9) == SUCESSO);

    int vet[2];

    printf("31 %d\n", getDadosEstruturaAuxiliar(1, vet) == SEM_ESTRUTURA_AUXILIAR);
    printf("32 %d\n", getDadosEstruturaAuxiliar(11, vet) == POSICAO_INVALIDA);
    printf("33 %d\n", getDadosEstruturaAuxiliar(2, vet) == SUCESSO);

    printf("34 %d\n", vet[0] == 7);
    printf("35 %d\n", vet[1] == -9);

    printf("36 %d\n", getDadosOrdenadosEstruturaAuxiliar(1, vet) == SEM_ESTRUTURA_AUXILIAR);
    printf("37 %d\n", getDadosOrdenadosEstruturaAuxiliar(11, vet) == POSICAO_INVALIDA);
    printf("38 %d\n", getDadosOrdenadosEstruturaAuxiliar(2, vet) == SUCESSO);

    printf("39 %d\n", vet[0] == -9);
    printf("40 %d\n", vet[1] == 7);

    printf("41 %d\n", getDadosEstruturaAuxiliar(2, vet) == SUCESSO);

    printf("42 %d\n", vet[0] == 7);
    printf("43 %d\n", vet[1] == -9);

    printf("44 %d\n", excluirNumeroDoFinaldaEstrutura(2) == SUCESSO);
    printf("45 %d\n", excluirNumeroDoFinaldaEstrutura(2) == SUCESSO);
}

/*
2 [ , , ]
*/

void testeRetornarTodosNumeros()
{
    show_log("testeRetornarTodosNumeros()");
    int vet1[2];
    printf("46 %d\n", getDadosDeTodasEstruturasAuxiliares(vet1) == TODAS_ESTRUTURAS_AUXILIARES_VAZIAS);

    printf("47 %d\n", getDadosOrdenadosDeTodasEstruturasAuxiliares(vet1) == TODAS_ESTRUTURAS_AUXILIARES_VAZIAS);

    printf("48 %d\n", inserirNumeroEmEstrutura(2, 3) == SUCESSO);
    printf("49 %d\n", inserirNumeroEmEstrutura(2, 8) == SUCESSO);
    printf("50 %d\n", inserirNumeroEmEstrutura(2, 0) == SUCESSO);
    /*
2 [3,8,0]
*/

    printf("51 %d\n", criarEstruturaAuxiliar(5, 10) == SUCESSO);

    printf("52 %d\n", inserirNumeroEmEstrutura(5, 1) == SUCESSO);
    printf("53 %d\n", inserirNumeroEmEstrutura(5, 34) == SUCESSO);
    printf("54 %d\n", inserirNumeroEmEstrutura(5, 12) == SUCESSO);
    printf("55 %d\n", inserirNumeroEmEstrutura(5, 6) == SUCESSO);
    printf("56 %d\n", inserirNumeroEmEstrutura(5, 27) == SUCESSO);
    printf("57 %d\n", inserirNumeroEmEstrutura(5, -6) == SUCESSO);
    /*
2 [3,8,0]
5 [1,34,12,6,27,-6, , , , ]
*/
    int vet[9];

    printf("58 %d\n", getDadosDeTodasEstruturasAuxiliares(vet) == SUCESSO);

    printf("59 %d\n", vet[0] == 3);
    printf("60 %d\n", vet[1] == 8);
    printf("61 %d\n", vet[2] == 0);
    printf("62 %d\n", vet[3] == 1);
    printf("63 %d\n", vet[4] == 34);
    printf("64 %d\n", vet[5] == 12);
    printf("65 %d\n", vet[6] == 6);
    printf("66 %d\n", vet[7] == 27);
    printf("67 %d\n", vet[8] == -6);

    int vet2[9];

    printf("68 %d\n", getDadosOrdenadosDeTodasEstruturasAuxiliares(vet2) == SUCESSO);

    printf("69 %d\n", vet2[0] == -6);
    printf("70 %d\n", vet2[1] == 0);
    printf("71 %d\n", vet2[2] == 1);
    printf("72 %d\n", vet2[3] == 3);
    printf("73 %d\n", vet2[4] == 6);
    printf("74 %d\n", vet2[5] == 8);
    printf("75 %d\n", vet2[6] == 12);
    printf("76 %d\n", vet2[7] == 27);
    printf("77 %d\n", vet2[8] == 34);

    printf("78 %d\n", getDadosDeTodasEstruturasAuxiliares(vet) == SUCESSO);

    printf("79 %d\n", vet[0] == 3);
    printf("80 %d\n", vet[1] == 8);
    printf("81 %d\n", vet[2] == 0);
    printf("82 %d\n", vet[3] == 1);
    printf("83 %d\n", vet[4] == 34);
    printf("84 %d\n", vet[5] == 12);
    printf("85 %d\n", vet[6] == 6);
    printf("86 %d\n", vet[7] == 27);
    printf("87 %d\n", vet[8] == -6);
}
/*
2 [3,8,0]
5 [1,34,12,6,27,-6, , , , ]
*/

/*
int modificarTamanhoEstruturaAuxiliar(int posicao, int novoTamanho);
Objetivo: modificar o tamanho da estrutura auxiliar da posição 'posicao' para o novo tamanho 'novoTamanho' + tamanho atual
Suponha o tamanho inicial = x, e novo tamanho = n. O tamanho resultante deve ser x + n. Sendo que x + n deve ser sempre >= 1

Rertono (int)
    SUCESSO - foi modificado corretamente o tamanho da estrutura auxiliar
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
    NOVO_TAMANHO_INVALIDO - novo tamanho não pode ser negativo
    SEM_ESPACO_DE_MEMORIA - erro na alocação do novo valor
*/
void testeMudarTamanhoEstrutura()
{
    show_log("testeMudarTamanhoEstrutura()");
    int vet[1];
    printf("88 %d\n", modificarTamanhoEstruturaAuxiliar(2, -3) == NOVO_TAMANHO_INVALIDO);
    printf("89 %d\n", modificarTamanhoEstruturaAuxiliar(2, -4) == NOVO_TAMANHO_INVALIDO);
    printf("90 %d\n", modificarTamanhoEstruturaAuxiliar(11, 7) == POSICAO_INVALIDA);
    printf("91 %d\n", modificarTamanhoEstruturaAuxiliar(0, 7) == POSICAO_INVALIDA);
    printf("92 %d\n", modificarTamanhoEstruturaAuxiliar(1, 7) == SEM_ESTRUTURA_AUXILIAR);

    // modificar para tamanho de 3 para 1
    printf("93 %d\n", modificarTamanhoEstruturaAuxiliar(2, -2) == SUCESSO);
    printf("94 %d\n", getQuantidadeElementosEstruturaAuxiliar(2) == 1);
    printf("95 %d\n", getDadosEstruturaAuxiliar(2, vet) == SUCESSO);
    printf("96 %d\n", vet[0] == 3);

    // modificar para tamanho de 1 para 4
    printf("97 %d\n", modificarTamanhoEstruturaAuxiliar(2, 3) == SUCESSO);
    printf("98 %d\n", getQuantidadeElementosEstruturaAuxiliar(2) == 1);
    printf("99 %d\n", getDadosEstruturaAuxiliar(2, vet) == SUCESSO);
    printf("100 %d\n", vet[0] == 3);

    printf("101 %d\n", inserirNumeroEmEstrutura(2, 4) == SUCESSO);
    printf("102 %d\n", inserirNumeroEmEstrutura(2, -2) == SUCESSO);
    printf("103 %d\n", inserirNumeroEmEstrutura(2, 6) == SUCESSO);
    printf("104 %d\n", inserirNumeroEmEstrutura(2, 5) == SEM_ESPACO);
}

/*
2 [3,4,-2,6]
5 [1,34,12,6,27,-6, , , , ]
*/

void testeListaEncadeada()
{
    show_log("testeListaEncadeada()");
    int vet[10];
    No *inicio = montarListaEncadeadaComCabecote();
    getDadosListaEncadeadaComCabecote(inicio, vet);

    printf("105 %d\n", vet[0] == 3);
    printf("106 %d\n", vet[1] == 4);
    printf("107 %d\n", vet[2] == -2);
    printf("108 %d\n", vet[3] == 6);
    printf("109 %d\n", vet[4] == 1);
    printf("110 %d\n", vet[5] == 34);
    printf("111 %d\n", vet[6] == 12);
    printf("112 %d\n", vet[7] == 6);
    printf("113 %d\n", vet[8] == 27);
    printf("114 %d\n", vet[9] == -6);

    destruirListaEncadeadaComCabecote(&inicio);

    printf("115 %d\n", inicio == NULL);
}
