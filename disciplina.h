#ifndef disciplina_h
#define disciplina_h

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "professor.h"
#include "aluno.h"

#define TAMDISCIPLINA 2

typedef struct disciplina {
    char nome[50];
    char codigo[10];
    int semestre;
    int disprof;
    int ativo;
    int qtdvagas;
    int alunomatriculado[TAMALUNO]; 

} disciplina;

int posdisc(disciplina d[], int qtdisciplina, char codigo[]);
void cadastrardisciplina(disciplina d[], int *qtdisciplina, professor p[], int *qtdprof);
void listardisciplina(disciplina d[], int *qtdisciplina);
void atualizardisciplina(disciplina d[], int *qtdisciplina, professor p[], int *qtdprof);
void excluirdisciplina(disciplina d[], int *qtdisciplina);
void atribuiralunodisciplina(disciplina d[], int *qtdisciplina, aluno a[], int *qtdaluno);
void excluiralunodisciplina(disciplina d[], int *qtdisciplina, aluno a[], int *qtdaluno);

#endif
