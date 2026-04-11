#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "disciplina.h"
#include "professor.h"
#include "aluno.h"

int validar_codigo(disciplina d[], char codigo[], int *D_ativa)
{
    for (int j = 0; j < *D_ativa; j++)
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

int cadastrar_disciplina(disciplina d[], int *D_ativa, professor p[], int *P_ativo)
{
    int semestre;
    int qtdvagas;
    int matricula;
    int pos = -1;
    if (*P_ativo == 0)
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

        printf("Informe o codigo da disciplina: ");
        fgets(d[*D_ativa].codigo, sizeof(d[*D_ativa].codigo), stdin);
        d[*D_ativa].codigo[strcspn(d[*D_ativa].codigo, "\n")] = '\0';

        printf("Informe o semestre da disciplina: ");
        scanf("%d", &semestre);
        if (semestre < 1 || semestre > 10)
        {
            return 3;
        }
        d[*D_ativa].semestre = semestre;

        printf("Informe a matricula do professor responsavel pela disciplina: ");
        scanf("%d", &matricula);
        for (int i = 0; i < *P_ativo; i++)
        {
            if (matricula == p[i].matricula)
            {
                d[*D_ativa].matricula_professor = matricula;
                pos = 1;
                break;
            }
        }
        if (pos == -1)
        {
            return 4;
        }

        printf("Informe a quantidade de vagas disponiveis para a disciplina: ");
        scanf("%d", &qtdvagas);
        if (qtdvagas < 1)
        {
            return 5;
        }
        d[*D_ativa].vagas_total = qtdvagas;
        d[*D_ativa].qtdalunos = 0;
        (*D_ativa)++;
        return 0;
    }
}

int listar_disciplina(disciplina d[], int *D_ativa, professor p[], int *P_ativo)
{
    if (*D_ativa == 0)
    {
        return 1;
    }
    printf("\n>>>Disciplinas cadastradas<<<\n");
    for (int i = 0; i < *D_ativa; i++)
    {
        printf("%d - Disciplina: %s\tCodigo: %s\tSemestre: %d\tVagas disponiveis: %d\t", i + 1, d[i].nome, d[i].codigo, d[i].semestre, d[i].vagas_total - d[i].qtdalunos);
        for (int j = 0; j < *P_ativo; j++)
        {
            if (d[i].matricula_professor == p[j].matricula)
            {
                printf("Professor: %s\n", p[j].nome);
                break;
            }
        }
    }
    return 0;
}

int atualizar_disciplina(disciplina d[], int *D_ativa, professor p[], int *P_ativo)
{
    char busca_codigo[10];
    int OpAtualizar;
    int pos = -1;
    if (*D_ativa == 0)
    {
        return 1;
    }
    printf("\nInforme o codigo da disciplina que deseja atualizar: ");
    scanf("%s", busca_codigo);
    for (int i = 0; i < *D_ativa; i++)
    {
        if (strcmp(busca_codigo, d[i].codigo) == 0)
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
    printf("1 - codigo\n2 - Nome\n3 - Semestre\n4 - Professor\n5 - Quantidade de Vagas\n");
    scanf("%d", &OpAtualizar);
    switch (OpAtualizar)
    {
    case 1:
    {
        char codigo[10];
        printf("\nInforme o codigo: ");
        scanf("%s", codigo);
        if (validar_codigo(d, codigo, D_ativa) != 0)
        {
            return 2;
        }
        strcpy(d[pos].codigo, codigo);
        return 0;
    }
    break;
    case 2:
    {
        getchar();
        printf("Informe o nome: ");
        fgets(d[pos].nome, sizeof(d[pos].nome), stdin);
        d[pos].nome[strcspn(d[pos].nome, "\n")] = '\0';
        return 0;
    }
    break;
    case 3:
    {
        int semestre;
        printf("Informe o semestre da disciplina: ");
        scanf("%d", &semestre);
        if (semestre < 1 || semestre > 10)
        {
            return 3;
        }
        d[pos].semestre = semestre;
        return 0;
    }
    break;
    case 4:
    {
        int matricula;
        int achou = -1;
        printf("Informe a matricula do professor responsavel pela disciplina: ");
        scanf("%d", &matricula);
        for (int i = 0; i < *P_ativo; i++)
        {
            if (matricula == p[i].matricula)
            {
                achou = 1;
                d[pos].matricula_professor = matricula;
                break;
            }
        }
        if (achou == -1)
        {
            return 4;
        }
        return 0;
    }
    break;
    case 5:
    {
        int qtdvagas;
        printf("Informe a quantidade de vagas disponiveis para a disciplina: ");
        scanf("%d", &qtdvagas);
        if (qtdvagas < d[pos].qtdalunos)
        {

            return 5;
        }
        d[pos].vagas_total = qtdvagas;
        return 0;
    }
    break;
    default:
    {
        printf("\nOpcao invalida!\n");
        return 0;
        break;
    }
    }
}

int excluir_disciplina(disciplina d[], int *D_ativa)
{
    char busca_codigo[10];
    int pos = -1;
    if (*D_ativa == 0)
    {
        return 1;
    }
    printf("\nInforme o codigo da disciplina que deseja excluir: ");
    scanf("%s", busca_codigo);
    for (int i = 0; i < *D_ativa; i++)
    {
        if (strcmp(busca_codigo, d[i].codigo) == 0)
        {
            pos = i;
            break;
        }
    }
    if (pos == -1)
    {
        return 2;
    }
    for (int j = pos; j < *D_ativa - 1; j++)
    {
        d[j] = d[j + 1];
    }
    (*D_ativa)--;
    return 0;
}

int matricular_aluno_disciplina(disciplina d[], int *D_ativa, aluno a[], int *A_ativo)
{
    char dcodigo[10];
    int a_matricula;
    if (*D_ativa == 0)
    {
        return 1;
    }
    if (*A_ativo == 0)
    {
        return 2;
    }

    printf("\nInforme o codigo da disciplina para matricular o aluno: ");
    scanf("%s", dcodigo);
    for (int i = 0; i < *D_ativa; i++)
    {
        if (strcmp(dcodigo, d[i].codigo) == 0)
        {
            if (d[i].qtdalunos == d[i].vagas_total)
            {
                return 3;
            }
            printf("Informe a matricula do aluno: ");
            scanf("%d", &a_matricula);
            for (int j = 0; j < *A_ativo; j++)
            {
                if (a_matricula == a[j].matricula)
                {
                    for (int k = 0; k < d[i].qtdalunos; k++)
                    {
                        if (d[i].alunos_matriculados[k] == a_matricula)
                        {
                            return 6;
                        }
                    }
                    d[i].alunos_matriculados[d[i].qtdalunos] = a_matricula;
                    d[i].qtdalunos++;
                    return 0;
                }
            }
            return 5;
        }
    }
    return 4;
}

int excluir_aluno_disciplina(disciplina d[], int *D_ativa, aluno a[], int *A_ativo)
{
    char dcodigo[10];
    int a_matricula;
    if (*D_ativa == 0)
    {
        return 1;
    }
    if (*A_ativo == 0)
    {
        return 2;
    }

    printf("\nInforme o codigo da disciplina para excluir o aluno: ");
    scanf("%s", dcodigo);
    for (int i = 0; i < *D_ativa; i++)
    {
        if (strcmp(dcodigo, d[i].codigo) == 0)
        {
            printf("Informe a matricula do aluno: ");
            scanf("%d", &a_matricula);
            for (int j = 0; j < *A_ativo; j++)
            {
                if (a_matricula == a[j].matricula)
                {
                    for (int k = 0; k < d[i].qtdalunos; k++)
                    {
                        if (d[i].alunos_matriculados[k] == a_matricula)
                        {
                            for (int l = k; l < d[i].qtdalunos - 1; l++)
                            {
                                d[i].alunos_matriculados[l] = d[i].alunos_matriculados[l + 1];
                            }
                            d[i].qtdalunos--;
                            return 0;
                        }
                    }
                    return 5;
                }
            }
            return 4;
        }
    }
    return 3;
}