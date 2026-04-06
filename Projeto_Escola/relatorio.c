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
        printf("\t%d\nNome: %s\nMatricula: %s\nSexo: %c\nCPF: %s\nData de nascimento: %s\n", i + 1, a[i].nome, a[i].matricula, a[i].sexo, a[i].cpf, a[i].data_nascimento);
    }
    return 0;
}

int listar_professores(professor p[], int *P_ativo)
{
    printf("\n>>>Lista de professores cadastrados<<<\n");
    for (int i = 0; i < *P_ativo; i++)
    {
        printf("\t%d\nNome: %s\nMatricula: %s\nSexo: %c\nCPF: %s\nData de nascimento: %s\n", i + 1, p[i].nome, p[i].matricula, p[i].sexo, p[i].cpf, p[i].data_nascimento);
    }
    return 0;
}

int listar_disciplinas(disciplina d[], int *D_ativa, professor p[], int *P_ativo)
{
    char nome_p[100];
    printf("\n>>>Lista de disciplinas cadastradas<<<\n");
    for (int i = 0; i < *D_ativa; i++)
    {
        for (int j = 0; j < *P_ativo; j++)
        {
            if (strcmp(d[i].matricula_professor, p[j].matricula) == 0)
            {
                strcpy(nome_p, p[j].nome);
                break;
            }
        }
        printf("\t%d\nCodigo: %s\nNome: %s\nSemestre: %d\nProfessor: %s\nQuantidade de vagas: %d\n", i + 1, d[i].codigo, d[i].nome, d[i].semestre, nome_p, d[i].vagas_total);
    }
    return 0;
}

int listar_alunos_disciplina(disciplina d[], int *D_ativa, aluno a[], int *A_ativo)
{
    char nome_a[100];
    printf("\n>>>Lista de alunos matriculados em cada disciplina<<<\n");
    for (int i = 0; i < *D_ativa; i++)
    {
        printf("\t%d\nCodigo: %d\nNome: %s\nSemestre: %d\n", i + 1, d[i].codigo, d[i].nome, d[i].semestre);
        printf("Alunos matriculados:\n");
        for (int j = 0; j < d[i].qtdalunos; j++)
        {
            for (int k = 0; k < *A_ativo; k++)
            {
                if (strcmp(d[i].alunos_matriculados[j], a[k].matricula[0]) == 0)
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
            printf("\nNome: %s\nMatricula: %s\nSexo: %c\nCPF: %s\nData de nascimento: %s\n", a[i].nome, a[i].matricula, a[i].sexo, a[i].cpf, a[i].data_nascimento);
        }
        if (a[i].sexo == 'f' || a[i].sexo == 'F')
        {
            printf("\nNome: %s\nMatricula: %s\nSexo: %c\nCPF: %s\nData de nascimento: %s\n", a[i].nome, a[i].matricula, a[i].sexo, a[i].cpf, a[i].data_nascimento);
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
        printf("\nNome: %s\nMatricula: %s\nSexo: %c\nCPF: %s\nData de nascimento: %s\n", a[i].nome, a[i].matricula, a[i].sexo, a[i].cpf, a[i].data_nascimento);
    }
    return 0;
}

int alunos_ordenados_data(aluno a[], int *A_ativo)
{
    if (*A_ativo == 0)
    {
        return 1;
    }
    printf("\n>>>Listagem de alunos por data de nascimento<<<\n");
    aluno aux;
    for (int i = 0; i < *A_ativo - 1; i++)
    {
        for (int j = 0; j < *A_ativo - i - 1; j++)
        {
            if (strcmp(a[j].data_nascimento, a[j + 1].data_nascimento) > 0)
            {
                aux = a[j];
                a[j] = a[j + 1];
                a[j + 1] = aux;
            }
        }
    }
    for (int i = 0; i < *A_ativo; i++)
    {
        printf("\nNome: %s\nMatricula: %s\nSexo: %c\nCPF: %s\nData de nascimento: %s\n", a[i].nome, a[i].matricula, a[i].sexo, a[i].cpf, a[i].data_nascimento);
    }
    return 0;
}

int listar_professor_sexo(professor p[], int *P_ativo)
{
    if (*P_ativo == 0)
    {
        return 1;
    }
    printf("\n>>>Listagem de professores por sexo<<<\n");
    for (int i = 0; i < *P_ativo; i++)
    {
        if (p[i].sexo == 'm' || p[i].sexo == 'M')
        {
            printf("\nNome: %s\nMatricula: %s\nSexo: %c\nCPF: %s\nData de nascimento: %s\n", p[i].nome, p[i].matricula, p[i].sexo, p[i].cpf, p[i].data_nascimento);
        }
        if (p[i].sexo == 'f' || p[i].sexo == 'F')
        {
            printf("\nNome: %s\nMatricula: %s\nSexo: %c\nCPF: %s\nData de nascimento: %s\n", p[i].nome, p[i].matricula, p[i].sexo, p[i].cpf, p[i].data_nascimento);
        }
    }
    return 0;
}

int professores_ordenados_nome(professor p[], int *P_ativo)
{
    if (*P_ativo == 0)
    {
        return 1;
    }
    printf("\n>>>Listagem de professores por nome<<<\n");
    professor aux;
    for (int i = 0; i < *P_ativo - 1; i++)
    {
        for (int j = 0; j < *P_ativo - i - 1; j++)
        {
            if (strcmp(p[j].nome, p[j + 1].nome) > 0)
            {
                aux = p[j];
                p[j] = p[j + 1];
                p[j + 1] = aux;
            }
        }
    }
    for (int i = 0; i < *P_ativo; i++)
    {
        printf("\nNome: %s\nMatricula: %s\nSexo: %c\nCPF: %s\nData de nascimento: %s\n", p[i].nome, p[i].matricula, p[i].sexo, p[i].cpf, p[i].data_nascimento);
    }
    return 0;
}

int professores_ordenados_data(professor p[], int *P_ativo)
{
    if (*P_ativo == 0)
    {
        return 1;
    }
    printf("\n>>>Listagem de professores por data de nascimento<<<\n");
    professor aux;
    for (int i = 0; i < *P_ativo - 1; i++)
    {
        for (int j = 0; j < *P_ativo - i - 1; j++)
        {
            if (strcmp(p[j].data_nascimento, p[j + 1].data_nascimento) > 0)
            {
                aux = p[j];
                p[j] = p[j + 1];
                p[j + 1] = aux;
            }
        }
    }
    for (int i = 0; i < *P_ativo; i++)
    {
        printf("\nNome: %s\nMatricula: %s\nSexo: %c\nCPF: %s\nData de nascimento: %s\n", p[i].nome, p[i].matricula, p[i].sexo, p[i].cpf, p[i].data_nascimento);
    }
    return 0;
}

int aniversariantes_mes(professor p[], int *P_ativo, aluno a[], int *A_ativo)
{
    if (*P_ativo == 0 && *A_ativo == 0)
    {
        return 1;
    }
    char mes[3];
    printf("\n>>>Listagem de aniversariantes do mes<<<\n");
    printf("Informe o mes (MM): ");
    scanf("%s", mes);
    for (int i = 0; i < *P_ativo; i++)
    {
        if (p[i].data_nascimento[3] == mes[0] && p[i].data_nascimento[4] == mes[1])
        {
            printf("\nNome: %s\nMatricula: %s\nSexo: %c\nCPF: %s\nData de nascimento: %s\n", p[i].nome, p[i].matricula, p[i].sexo, p[i].cpf, p[i].data_nascimento);
        }
    }
    for (int i = 0; i < *A_ativo; i++)
    {
        if (a[i].data_nascimento[3] == mes[0] && a[i].data_nascimento[4] == mes[1])
        {
            printf("\nNome: %s\nMatricula: %s\nSexo: %c\nCPF: %s\nData de nascimento: %s\n", a[i].nome, a[i].matricula, a[i].sexo, a[i].cpf, a[i].data_nascimento);
        }
    }
    return 0;
}

int buscar_nome(aluno a[], int *A_ativo, professor p[], int *P_ativo)
{
    if (*A_ativo == 0 && *P_ativo == 0)
    {
        return 1;
    }
    char nome[100];
    printf("\n>>>Buscar por nome<<<\n");
    printf("Informe o nome: ");
    scanf(" %[^\n]s", nome);
    for (int i = 0; i < *P_ativo; i++)
    {
        if (strcmp(p[i].nome, nome) == 0)
        {
            printf("\nNome: %s\nMatricula: %s\nSexo: %c\nCPF: %s\nData de nascimento: %s\n", p[i].nome, p[i].matricula, p[i].sexo, p[i].cpf, p[i].data_nascimento);
        }
    }
    for (int i = 0; i < *A_ativo; i++)
    {
        if (strcmp(a[i].nome, nome) == 0)
        {
            printf("\nNome: %s\nMatricula: %s\nSexo: %c\nCPF: %s\nData de nascimento: %s\n", a[i].nome, a[i].matricula, a[i].sexo, a[i].cpf, a[i].data_nascimento);
        }
    }
    return 0;
}

int alunos_matriculados_3_disciplinas(disciplina d[], int *D_ativa, aluno a[], int *A_ativo)
{
    if (*A_ativo == 0 || *D_ativa == 0)
    {
        return 1;
    }
    printf("\n>>>Listagem de alunos matriculados em mais de 3 disciplinas<<<\n");
    for (int i = 0; i < *A_ativo; i++)
    {
        int contador = 0;
        for (int j = 0; j < *D_ativa; j++)
        {
            for (int k = 0; k < d[j].qtdalunos; k++)
            {
                if (strcmp(d[j].alunos_matriculados[k], a[i].matricula[0]) == 0)
                {
                    contador++;
                }
            }
        }
        if (contador > 3)
        {
            printf("\nNome: %s\nMatricula: %s\nSexo: %c\nCPF: %s\nData de nascimento: %s\n", a[i].nome, a[i].matricula, a[i].sexo, a[i].cpf, a[i].data_nascimento);
        }
    }
    return 0;
}

int disciplinas_professor_40_vagas(disciplina d[], int *D_ativa, professor p[], int *P_ativo)
{
    if (*D_ativa == 0 || *P_ativo == 0)
    {
        return 1;
    }
    printf("\n>>>Listagem de disciplinas com mais de 40 vagas<<<\n");
    for (int i = 0; i < *D_ativa; i++)
    {
        if (d[i].vagas_total > 40)
        {
            char nome_p[100];
            for (int j = 0; j < *P_ativo; j++)
            {
                if (strcmp(d[i].matricula_professor, p[j].matricula) == 0)
                {
                    strcpy(nome_p, p[j].nome);
                    break;
                }
            }
            printf("\nCodigo: %d\nNome: %s\nSemestre: %d\nProfessor: %s\nQuantidade de vagas: %d\n", d[i].codigo, d[i].nome, d[i].semestre, nome_p, d[i].vagas_total);
        }
    }
    return 0;
}
