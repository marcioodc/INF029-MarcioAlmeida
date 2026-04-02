#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "disciplina.h"
#include "professor.h"

int validar_codigo(disciplina d[], char codigo[], int *ativo)
{
    for (int j = 0; j < *ativo; j++)
    {
        if (strcmp(codigo, d[j].codigo) == 0)
        {
            return 1;
        }
    }
    if (strcmp(codigo, "") == 0)
    {
        return 1;
    }
    return 0;
}

int cadastrar_disciplina(disciplina d[], int *D_ativa, professor p[], int *P_ativa)
{
    int semestre;
    int qtdvagas;
    int matricula;
    int pos = -1;
    if (*P_ativa == 0)
    {
        return 1;
    }
    if (*D_ativa == QTDISCIPLINA)
    {
        return 2;
    }
    else
    {
        getchar();
        printf("\nInforme o nome da disciplina: ");
        fgets(d[*D_ativa].nome, sizeof(d[*D_ativa].nome), stdin);
        d[*D_ativa].nome[strcspn(d[*D_ativa].nome, "\n")] = '\0';

        printf("Informe o código da disciplina: ");
        fgets(d[*D_ativa].codigo, sizeof(d[*D_ativa].codigo), stdin);
        d[*D_ativa].codigo[strcspn(d[*D_ativa].codigo, "\n")] = '\0';

        printf("Informe o semestre da disciplina: ");
        scanf("%d", &semestre);
        if (semestre < 1 || semestre > 10)
        {
            return 3;
        }
        d[*D_ativa].semestre = semestre;

        printf("Informe a matrícula do professor responsável pela disciplina: ");
        scanf("%d", &matricula);
        for (int i = 0; i < *D_ativa; i++)
        {
            if (matricula == p[i].matricula)
            {
                pos = i;
                break;
            }
        }
        if (pos == -1)
        {
            return 4;
        }
        d[*D_ativa].matricula_professor = matricula;

        printf("Informe a quantidade de vagas disponíveis para a disciplina: ");
        scanf("%d", &qtdvagas);
        if (qtdvagas < 1)
        {
            return 5;
        }
        d[*D_ativa].qtdvagas = qtdvagas;

        (*D_ativa)++;
        return 0;
    }
}

int listar_disciplina(disciplina d[], int *D_ativa, professor p[])
{
    if (*D_ativa == 0)
    {
        return 1;
    }
    for (int i = 0; i < *D_ativa; i++)
    {
        printf("Disciplina: %s\nCódigo: %s\nSemestre: %d\nVagas disponíveis: %d\n", d[i].nome, d[i].codigo, d[i].semestre, d[i].qtdvagas);
        for (int j = 0; j < *D_ativa; j++)
        {
            if (d[i].matricula_professor == p[j].matricula)
            {
                printf("Professor: %s\n", p[j].nome);
                break;
            }
        }
        printf("\n");
    }
    return 0;
}

int atualizar_disciplina(disciplina d[], int *D_ativa, professor p[], int *P_ativa)
{
    char busca_matricula;
    int OpAtualizar;
    int pos = -1;
    if (*D_ativa == 0)
    {
        return 1;
    }
    printf("\nInforme o código da disciplina que deseja atualizar: ");
    scanf("%s", &busca_matricula);
    for (int i = 0; i < *D_ativa; i++)
    {
        if (strcmp(busca_matricula, d[i].codigo) == 0)
        {
            pos = i;
            break;
        }
    }
    if (pos == -1)
    {
        return 2;
    }
    printf("\nO que deseja atualizar?\n");
    printf("1 - Matrícula\n2 - Nome\n3 - Sexo\n4 - CPF\n5 - Data de Nascimento\n");
    scanf("%d", &OpAtualizar);
    switch (OpAtualizar)
    {
    case 1:
        char codigo[10];
        printf("\nInforme o código: ");
        scanf("%s", &codigo);
        if (validar_codigo(d, codigo, D_ativa) != 0)
        {
            return 2;
        }
        strcpy(d[pos].codigo, codigo);
        return 0;
        break;
    case 2:
        getchar();
        printf("Informe o nome: ");
        fgets(d[pos].nome, sizeof(d[pos].nome), stdin);
        d[pos].nome[strcspn(d[pos].nome, "\n")] = '\0';
        return 0;
        break;
    case 3:
        int semestre;
        printf("Informe o semestre da disciplina: ");
        scanf("%d", &semestre);
        if (semestre < 1 || semestre > 10)
        {
            return 3;
        }
        d[*D_ativa].semestre = semestre;
        return 0;
        break;
    case 4:
        char matricula;
        printf("Informe a matrícula do professor responsável pela disciplina: ");
        scanf("%s", &matricula);
        for (int i = 0; i < *D_ativa; i++)
        {
            if (matricula == p[i].matricula)
            {
                pos = i;
                break;
            }
        }
        if (pos == -1)
        {
            return 4;
        }
        d[*D_ativa].matricula_professor = matricula;
        return 0;
        break;
    case 5:
        int qtdvagas;
        printf("Informe a quantidade de vagas disponíveis para a disciplina: ");
        scanf("%d", &qtdvagas);
        if (qtdvagas < 1)
        {
            return 5;
        }
        d[*D_ativa].qtdvagas = qtdvagas;

        (*D_ativa)++;
        return 0;
        break;
    default:
        printf("\nOpção inválida!\n");
        return 0;
    }
}