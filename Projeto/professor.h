#ifndef PROFESSOR_H
#define PROFESSOR_H

#define TAMPROFESSOR 100

typedef struct professor {
    int matricula;
    char nome[50];
    char sexo;
    int dia, mes, ano; //data nascimento
    char cpf[15];
    int ativo;
} professor;

int cadastrarprof(professor p[], int *qtdprof);
int listarprof(professor p[], int *qtdprof);
int atualizarprof(professor p[], int *qtdprof);
int excluirprof(professor p[], int *qtdprof);
int posprof(professor p[], int qtdprof, int matricula);
int validata(int dia, int mes, int ano);
int validarcpf(professor p[], int i);

#endif
