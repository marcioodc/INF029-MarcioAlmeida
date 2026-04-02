#ifndef DISCIPLINA_H
#define DISCIPLINA_H

#include "aluno.h"
#include "professor.h"

#define QTDISCIPLINA 2

typedef struct disciplina
{
    char nome[50];
    char codigo[10];
    int semestre;
    int matricula_professor;
    int qtdvagas;
    int alunomatriculado[40];
} disciplina;

int cadastrar_disciplina(disciplina d[], int *D_ativa, professor p[], int *P_ativa);
int listar_disciplina(disciplina d[], int *D_ativa, professor p[]);
int atualizar_disciplina(disciplina d[], int *D_ativa, professor p[], int *P_ativa);
int excluir_disciplina(disciplina d[], int *D_ativa);
int matricular_aluno(disciplina d[], int *D_ativa, aluno a[], int *A_ativa);
int excluir_aluno_disciplina(disciplina d[], int *D_ativa, aluno a[], int *A_ativa);
int validar_codigo(disciplina d[], char codigo[], int *ativo);

#endif