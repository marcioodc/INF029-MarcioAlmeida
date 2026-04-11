#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#include "aluno.h"

int validar_matricula(aluno a[], int matricula, int *A_ativo)
{
    for (int j = 0; j < *A_ativo; j++)
    {
        if (matricula == a[j].matricula)
        {
            return 1;
        }
    }
    if (matricula < 0)
    {
        return 1;
    }
    return 0;
}

int validar_CPF(char cpf[])
{
    if (strlen(cpf) != 11)
    {
        return 0;
    }
    return 1;
}

int cadastrar_aluno(aluno a[], int *A_ativo)
{
    if (*A_ativo == tam_aluno)
    {
        return 1;
    }
    else
    {
        int matricula;
        printf("\nInforme a matricula: ");
        scanf("%d", &matricula);
        if (validar_matricula(a, matricula, A_ativo) != 0)
        {
            return 2;
        }
        a[*A_ativo].matricula = matricula;

        getchar();
        printf("Informe o nome: ");
        fgets(a[*A_ativo].nome, sizeof(a[*A_ativo].nome), stdin);
        a[*A_ativo].nome[strcspn(a[*A_ativo].nome, "\n")] = '\0';

        char sexo;
        printf("Informe o sexo (F ou M): ");
        scanf(" %c", &sexo);
        sexo = toupper(sexo);
        if (sexo != 'F' && sexo != 'M')
        {
            return 3;
        }
        a[*A_ativo].sexo = sexo;

        char cpf[15];
        printf("Informe o CPF: ");
        scanf("%15s", cpf);
        if (validar_CPF(cpf) == 0)
        {
            return 4;
        }
        strcpy(a[*A_ativo].cpf, cpf);

        char data_nascimento[15];
        printf("Informe a data de nascimento: ");
        scanf("%s", data_nascimento);
        if (validar_DATA(data_nascimento) == 0)
        {
            return 5;
        }
        strcpy(a[*A_ativo].data_nascimento, data_nascimento);

        (*A_ativo)++;
        return 0;
    }
}

int listar_aluno(aluno a[], int *A_ativo)
{
    if (*A_ativo == 0)
    {
        return 1;
    }

    int j = 1;
    printf("\n>>>Alunos cadastrados<<<\n");
    for (int i = 0; i < *A_ativo; i++)
    {
        printf("%d - Matricula: %d\tNome: %s\tSexo: %c\tCPF: %s\tData de Nascimento: %s\n", i + 1, a[i].matricula, a[i].nome, a[i].sexo, a[i].cpf, a[i].data_nascimento);
    }
    return 0;
}

int atualizar_aluno(aluno a[], int *A_ativo)
{
    int busca_matricula;
    int OpAtualizar;
    int pos = -1;
    if (*A_ativo == 0)
    {
        return 1;
    }
    printf("\nInforme a matricula do aluno que deseja atualizar: ");
    scanf("%d", &busca_matricula);
    for (int i = 0; i < *A_ativo; i++)
    {
        if (busca_matricula == a[i].matricula)
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
    printf("1 - Matricula\n2 - Nome\n3 - Sexo\n4 - CPF\n5 - Data de Nascimento\n");
    scanf("%d", &OpAtualizar);
    switch (OpAtualizar)
    {
    case 1:
    {
        int matricula;
        printf("\nInforme a matricula: ");
        scanf("%d", &matricula);
        if (validar_matricula(a, matricula, A_ativo) != 0)
        {
            return 2;
        }
        a[pos].matricula = matricula;
        return 0;
    }
    break;
    case 2:
    {
        getchar();
        printf("Informe o nome: ");
        fgets(a[pos].nome, sizeof(a[pos].nome), stdin);
        a[pos].nome[strcspn(a[pos].nome, "\n")] = '\0';
        return 0;
    }
    break;
    case 3:
    {
        char sexo;
        printf("Informe o sexo (F ou M): ");
        scanf(" %c", &sexo);
        sexo = toupper(sexo);
        if (sexo != 'F' && sexo != 'M')
        {
            return 3;
        }
        a[pos].sexo = sexo;
        return 0;
    }
    break;
    case 4:
    {
        char cpf[15];
        printf("Informe o CPF: ");
        scanf("%15s", cpf);
        if (validar_CPF(cpf) == 0)
        {
            return 4;
        }
        strcpy(a[pos].cpf, cpf);
        return 0;
    }
    break;
    case 5:
    {
        char data_nascimento[15];
        printf("Informe a data de nascimento: ");
        scanf("%s", data_nascimento);
        if (validar_DATA(data_nascimento) == 0)
        {
            return 5;
        }
        strcpy(a[pos].data_nascimento, data_nascimento);
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

int excluir_aluno(aluno a[], int *A_ativo)
{
    int busca_matricula;
    int pos = -1;
    if (*A_ativo == 0)
    {
        return 1;
    }
    printf("\nInforme a matricula do aluno que deseja excluir: ");
    scanf("%d", &busca_matricula);
    for (int i = 0; i < *A_ativo; i++)
    {
        if (busca_matricula == a[i].matricula)
        {
            pos = i;
            break;
        }
    }
    if (pos == -1)
    {
        return 2;
    }
    for (int j = pos; j < *A_ativo - 1; j++)
    {
        a[j] = a[j + 1];
    }
    (*A_ativo)--;
    return 0;
}

int validar_DATA(char data[])
{
    int d, m, a;
    if (sscanf(data, "%d/%d/%d", &d, &m, &a) != 3)
    {
        return 0;
    }
    if (m < 1 || m > 12 || a < 1800 || a > 2025)
    {
        return 0;
    }
    int dias_mes[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if ((a % 4 == 0 && a % 100 != 0) || (a % 400 == 0))
    {
        dias_mes[1] = 29;
    }
    if (d < 1 || d > dias_mes[m - 1])
    {
        return 0;
    }
    return 1;
}