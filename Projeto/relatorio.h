#ifndef RELATORIO_H
#define RELATORIO_H

#include "aluno.h"
#include "professor.h"
#include "disciplina.h"

void Rlistaralunos(aluno a[], int *qtdaluno);
void Rlistarprofessor(professor p[], int *qtdprof);
void Rlistardisciplina(disciplina d[], int *qtdisciplina, professor p[], int *qtdprof);
void Ralunosdisciplina(aluno a[], int *qtdaluno, disciplina d[], int *qtdisciplina, professor p[], int *qtdprof);
void Rsexoalunos(aluno a[], int *qtdaluno);
void Rnomealunos(aluno a[], int *qtdaluno);
void Ralunosdatanascimento(aluno a[], int *qtdaluno);
void Rprofessorsexo(professor p[], int *qtdprof);
void Rnomeprofessor(professor p[], int *qtdprof);
void Rprofessordatanascimento(professor p[], int *qtdprof);
void Raniversariantesmes(aluno a[], int *qtdaluno, professor p[], int *qtdprof);
void Ralunos3disciplinas(aluno a[], int *qtdaluno, disciplina d[], int *qtdisciplina);
void Rdisciplinas40(disciplina d[], int *qtdisciplina, professor p[], int *qtdprof);
void meses(aluno a[], int qtdaluno, professor p[], int qtdprof, int mes);
int Pcomparadata(professor i, professor j);
int Acomparadata(aluno i, aluno j);

#endif