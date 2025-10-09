#ifndef PROFESSOR_H
#define PROFESSOR_H

#define TAMPROFESSOR 2

typedef struct professor {
    int matricula;
    char nome[50];
    char sexo;
    int dia, mes, ano; //data nascimento
    char cpf[12];
    int ativo;
} professor;

void cadastrarprof(professor p[], int *qtdprof);
void listarprof(professor p[], int *qtdprof);
void atualizarprof(professor p[], int *qtdprof);
void excluirprof(professor p[], int *qtdprof);
int posprof(professor p[], int qtdprof, int matricula);
int validata(int dia, int mes, int ano);

#endif
