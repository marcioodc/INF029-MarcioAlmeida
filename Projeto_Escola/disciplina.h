#ifndef DISCIPLINA_H
#define DISCIPLINA_H

#include "aluno.h"
#include "professor.h"

#define QTDISCIPLINA 5

typedef struct disciplina
{
    char nome[100];
    char codigo[10];
    int semestre;
    int matricula_professor;
    int vagas_total;
    int alunos_matriculados[40];
    int qtdalunos;
} disciplina;

int cadastrar_disciplina(disciplina d[], int *D_ativa, professor p[], int *P_ativo);
int listar_disciplina(disciplina d[], int *D_ativa, professor p[], int *P_ativo);
int atualizar_disciplina(disciplina d[], int *D_ativa, professor p[], int *P_ativo);
int excluir_disciplina(disciplina d[], int *D_ativa);
int matricular_aluno_disciplina(disciplina d[], int *D_ativa, aluno a[], int *A_ativo);
int excluir_aluno_disciplina(disciplina d[], int *D_ativa, aluno a[], int *A_ativo);
int validar_codigo(disciplina d[], char codigo[], int *D_ativa);

#endif