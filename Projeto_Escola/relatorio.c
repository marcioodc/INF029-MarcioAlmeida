#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "aluno.h"
#include "relatorio.h"
#include "professor.h"
#include "disciplina.h"

int listar_alunos(aluno a[], int *A_ativo)
{
    printf("\n>>>Lista de alunos cadastrados<<<\n");
    for (int i = 0; i < *A_ativo; i++)
    {
        printf("\t%d\nNome: %s\nMatricula: %d\nSexo: %c\nCPF: %s\nData de nascimento: %s\n", i + 1, a[i].nome, a[i].matricula, a[i].sexo, a[i].cpf, a[i].data_nascimento);
    }
    return 0;
}

int listar_professores(professor p[], int *P_ativo)
{
    printf("\n>>>Lista de professores cadastrados<<<\n");
    for (int i = 0; i < *P_ativo; i++)
    {
        printf("\t%d\nNome: %s\nMatricula: %d\nSexo: %c\nCPF: %s\nData de nascimento: %s\n", i + 1, p[i].nome, p[i].matricula, p[i].sexo, p[i].cpf, p[i].data_nascimento);
    }
    return 0;
}

int listar_disciplinas(disciplina d[], int *D_ativo, professor p[], int *P_ativo)
{
    char nome_p[100];
    printf("\n>>>Lista de disciplinas cadastradas<<<\n");
    for (int i = 0; i < *D_ativo; i++)
    {
        for (int j = 0; j < *P_ativo; j++)
        {
            if (d[i].matricula_professor == p[j].matricula)
            {
                strcpy(nome_p, p[j].nome);
                break;
            }
        }
        printf("\t%d\nCodigo: %d\nNome: %s\nSemestre: %d\nProfessor: %s\nQuantidade de vagas: %d\n", i + 1, d[i].codigo, d[i].nome, d[i].semestre, nome_p, d[i].vagas_total);
    }
    return 0;
}

int listar_alunos_disciplina(disciplina d[], int *D_ativo, aluno a[], int *A_ativo)
{
    char nome_a[100];
    printf("\n>>>Lista de alunos matriculados em cada disciplina<<<\n");
    for (int i = 0; i < *D_ativo; i++)
    {
        printf("\t%d\nCodigo: %d\nNome: %s\nSemestre: %d\n", i + 1, d[i].codigo, d[i].nome, d[i].semestre);
        printf("Alunos matriculados:\n");
        for (int j = 0; j < d[i].qtdalunos; j++)
        {
            for (int k = 0; k < *A_ativo; k++)
            {
                if (d[i].alunos_matriculados[j] == a[k].matricula)
                {
                    strcpy(nome_a, a[k].nome);
                    break;
                }
            }
            printf("\t%d. %s\n", j + 1, nome_a);
        }
    }
    return 0;
}

int listar_alunos_sexo(aluno a[], int *A_ativo)
{
    if (*A_ativo == 0)
    {
        return 1;
    }
    printf("\n>>>Listagem de alunos por sexo<<<\n");
    for (int i = 0; i < *A_ativo; i++)
    {
        if (a[i].sexo == 'm' || a[i].sexo == 'M')
        {
            printf("\nNome: %s\nMatricula: %d\nSexo: %c\nCPF: %s\nData de nascimento: %s\n", a[i].nome, a[i].matricula, a[i].sexo, a[i].cpf, a[i].data_nascimento);
        }
        if (a[i].sexo == 'f' || a[i].sexo == 'F')
        {
            printf("\nNome: %s\nMatricula: %d\nSexo: %c\nCPF: %s\nData de nascimento: %s\n", a[i].nome, a[i].matricula, a[i].sexo, a[i].cpf, a[i].data_nascimento);
        }
    }
    return 0;
}

int alunos_ordenados_nome(aluno a[], int *A_ativo)
{
    if (*A_ativo == 0)
    {
        return 1;
    }
    printf("\n>>>Listagem de alunos por nome<<<\n");
    aluno aux;
    for (int i = 0; i < *A_ativo - 1; i++)
    {
        for (int j = 0; j < *A_ativo - i - 1; j++)
        {
            if (strcmp(a[j].nome, a[j + 1].nome) > 0)
            {
                aux = a[j];
                a[j] = a[j + 1];
                a[j + 1] = aux;
            }
        }
    }
    for (int i = 0; i < *A_ativo; i++)
    {
        printf("\nNome: %s\nMatricula: %d\nSexo: %c\nCPF: %s\nData de nascimento: %s\n", a[i].nome, a[i].matricula, a[i].sexo, a[i].cpf, a[i].data_nascimento);
    }
    return 0;
}
