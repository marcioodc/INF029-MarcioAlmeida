#ifndef professor_h
#define professor_h

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define TAMPROF 2

typedef struct professor {
    int matricula;
    char nome[50];
    char sexo;
    int dia, mes, ano; //data nascimento
    char cpf[15];
    int ativo;
} professor;

void cadastrarprof(professor p[], int *qtdprof);
void listarprof(professor p[], int *qtdprof);
void atualizarprof(professor p[], int *qtdprof);
void excluirprof(professor p[], int *qtdprof, disciplina d[], int *qtdisciplina);

#endif