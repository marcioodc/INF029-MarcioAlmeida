#ifndef RELATORIO_H
#define RELATORIO_H

#include "aluno.h"
#include "professor.h"
#include "disciplina.h"

int listar_alunos(aluno a[], int *A_ativo);
int listar_professores(professor p[], int *P_ativo);
int listar_disciplinas(disciplina d[], int *D_ativa, professor p[], int *P_ativo);
int listar_alunos_disciplina(disciplina d[], int *D_ativa, aluno a[], int *A_ativo);
int listar_alunos_sexo(aluno a[], int *A_ativo);
int alunos_ordenados_nome(aluno a[], int *A_ativo);
int alunos_ordenados_data(aluno a[], int *A_ativo);
int listar_professores_sexo(professor p[], int *P_ativo);
int professores_ordenados_nome(professor p[], int *P_ativo);
int professores_ordenados_data(professor p[], int *P_ativo);
int aniversariantes_mes(aluno a[], int *A_ativo, professor p[], int *P_ativo);
int buscar_nome(aluno a[], int *A_ativo, professor p[], int *P_ativo);
int alunos_matriculados_menos_3_disciplinas(aluno a[], int *A_ativo, disciplina d[], int *D_ativa);
int disciplinas_professor_40vagas(professor p[], int *P_ativo, disciplina d[], int *D_ativa);

#endif