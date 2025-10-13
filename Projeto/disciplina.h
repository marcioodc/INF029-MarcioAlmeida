#ifndef DISCIPLINA_H
#define DISCIPLINA_H
#include "professor.h"
#include "aluno.h"

#define TAMDISCIPLINA 100

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
int cadastrardisciplina(disciplina d[], int *qtdisciplina, professor p[], int *qtdprof);
int listardisciplina(disciplina d[], int *qtdisciplina);
int atualizardisciplina(disciplina d[], int *qtdisciplina, professor p[], int *qtdprof);
int excluirdisciplina(disciplina d[], int *qtdisciplina);
int atribuiralunodisciplina(disciplina d[], int *qtdisciplina, aluno a[], int *qtdaluno);
int excluiralunodisciplina(disciplina d[], int *qtdisciplina, aluno a[], int *qtdaluno);

#endif
