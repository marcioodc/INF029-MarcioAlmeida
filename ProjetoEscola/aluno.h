#ifndef ALUNO_H
#define ALUNO_H
#define TAM_ALUNO 2

typedef struct aluno{
    int matricula;
    char nome[100];
    char cpf[15];
    char sexo[3];
    int data_nascimento[15];
}aluno;

int cadastrar_aluno(aluno a[], int *qtd_aluno);

#endif
