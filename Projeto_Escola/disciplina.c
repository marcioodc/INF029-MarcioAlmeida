#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "disciplina.h"
#include "professor.h"

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

int listar_disciplina(disciplina d[], int *D_ativa, professor p[], int *P_ativa)
{
    if (*P_ativa == 0)
    {
        return 2;
    }
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
    return 0;
}