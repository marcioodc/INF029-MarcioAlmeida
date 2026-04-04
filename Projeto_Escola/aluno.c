#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#include "aluno.h"

int validar_matricula(aluno a[], int matricula, int *ativo)
{
    for (int j = 0; j < *ativo; j++)
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

int validar_DATA(char data_nascimento[])
{
    int d, m, a;
    if (sscanf(data_nascimento, "%2d/%2d/%4d", &d, &m, &a) != 3)
    {
        return 1;
    }
    if (d < 1 || d > 31 || m < 1 || m > 12 || a < 1800 || a > 2025)
    {
        return 1;
    }
    if ((m == 4 || m == 6 || m == 9 || m == 11) && d > 30)
    {
        return 1;
    }
    if (m == 2)
    {
        int bissexto = (a % 4 == 0 && a % 100 != 0) || (a % 400 == 0);
        if ((bissexto && d > 29) || (!bissexto && d > 28))
        {
            return 1;
        }
    }
    return 0;
}

int cadastrar_aluno(aluno a[], int *ativo)
{
    if (*ativo == tam_aluno)
    {
        return 1;
    }
    else
    {
        int matricula;
        printf("\nInforme a matricula: ");
        scanf("%d", &matricula);
        if (validar_matricula(a, matricula, ativo) != 0)
        {
            return 2;
        }
        a[*ativo].matricula = matricula;

        getchar();
        printf("Informe o nome: ");
        fgets(a[*ativo].nome, sizeof(a[*ativo].nome), stdin);
        a[*ativo].nome[strcspn(a[*ativo].nome, "\n")] = '\0';

        char sexo;
        printf("Informe o sexo (F ou M): ");
        scanf(" %c", &sexo);
        sexo = toupper(sexo);
        if (sexo != 'F' && sexo != 'M')
        {
            return 3;
        }
        a[*ativo].sexo = sexo;

        char cpf[15];
        printf("Informe o CPF: ");
        scanf("%15s", cpf);
        if (validar_CPF(cpf) == 0)
        {
            return 4;
        }
        strcpy(a[*ativo].cpf, cpf);

        char data_nascimento[11];
        printf("Informe a data de nascimento: ");
        scanf("%10s", data_nascimento);
        if (validar_DATA(data_nascimento) == 1)
        {
            return 5;
        }

        (*ativo)++;
        return 0;
    }
}

int listar_aluno(aluno a[], int *ativo)
{
    if (*ativo == 0)
    {
        return 1;
    }

    int j = 1;
    printf("\n>>>Alunos cadastrados<<<\n");
    for (int i = 0; i < *ativo; i++)
    {
        printf("\t%d\nMatricula: %d\nNome: %s\nSexo: %c\nCPF: %s\nData de Nascimento: %s\n", i + 1, a[i].matricula, a[i].nome, a[i].sexo, a[i].cpf, a[i].data_nascimento);
        printf("\n");
    }
    return 0;
}

int atualizar_aluno(aluno a[], int *ativo)
{
    int busca_matricula;
    int OpAtualizar;
    int pos = -1;
    if (*ativo == 0)
    {
        return 1;
    }
    printf("\nInforme a matricula do aluno que deseja atualizar: ");
    scanf("%d", &busca_matricula);
    for (int i = 0; i < *ativo; i++)
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
        if (validar_matricula(a, matricula, ativo) != 0)
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
        char data_nascimento[11];
        printf("Informe a data de nascimento: ");
        scanf("%10s", data_nascimento);
        if (validar_DATA(data_nascimento) == 1)
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

int excluir_aluno(aluno a[], int *ativo)
{
    int busca_matricula;
    int pos = -1;
    if (*ativo == 0)
    {
        return 1;
    }
    printf("\nInforme a matricula do aluno que deseja excluir: ");
    scanf("%d", &busca_matricula);
    for (int i = 0; i < *ativo; i++)
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
    for (int j = pos; j < *ativo - 1; j++)
    {
        a[j] = a[j + 1];
    }
    (*ativo)--;
    return 0;
}
