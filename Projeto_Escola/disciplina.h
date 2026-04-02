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

int cadastrar_disciplina(disciplina d[], int *D_ativa);
int listar_disciplina(disciplina d[], int *D_ativa);
int atualizar_disciplina(disciplina d[], int *D_ativa);
int excluir_disciplina(disciplina d[], int *D_ativa);

#endif