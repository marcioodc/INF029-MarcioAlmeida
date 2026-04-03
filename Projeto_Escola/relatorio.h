#ifndef RELATORIO_H
#define RELATORIO_H

#include "aluno.h"
#include "professor.h"
#include "disciplina.h"

int listar_alunos(aluno a[], int *A_ativo);
int listar_professores(professor p[], int *P_ativo);
int listar_disciplinas(disciplina d[], int *D_ativo, professor p[], int *P_ativo);
int listar_alunos_disciplina(disciplina d[], int *D_ativo, aluno a[], int *A_ativo);

#endif