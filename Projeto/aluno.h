#ifndef ALUNO_H
#define ALUNO_H

#define TAMALUNO 2

typedef struct aluno {
    int matricula;
    char nome[50];
    char sexo;
    int dia, mes, ano; //data nascimento 
    int cpf[12];
    int ativo;
} aluno;

int cadastraraluno(aluno a[], int *qtdaluno);
int listaraluno(aluno a[], int *qtdaluno);
int atualizaraluno(aluno a[], int *qtdaluno);
int excluiraluno(aluno a[], int *qtdaluno);
int posaluno(aluno a[], int qtdaluno, int matricula);
int validaData(int dia, int mes, int ano);

#endif
