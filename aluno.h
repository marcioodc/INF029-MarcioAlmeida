#ifndef aluno_h
#define aluno_h

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define TAMALUNO 2

typedef struct aluno {
    int matricula;
    char nome[50];
    char sexo;
    int dia, mes, ano; //data nascimento 
    char cpf[15];
    int ativo;
} aluno;

void cadastraraluno(aluno a[], int *qtdaluno);
void listaraluno(aluno a[], int *qtdaluno);
void atualizaraluno(aluno a[], int *qtdaluno);
void excluiraluno(aluno a[], int *qtdaluno, d[], int *qtdisciplina);
int posaluno(aluno a[], int *qtdaluno, int matricula);
int validaData(int dia, int mes, int ano);

#endif
