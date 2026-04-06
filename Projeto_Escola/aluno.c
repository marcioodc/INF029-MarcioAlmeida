#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#include "aluno.h"

int validar_matricula(aluno a[], char matricula[tam_aluno][10], int *ativo)
{
    for (int j = 0; j < *ativo; j++)
    {
        if (strcmp(matricula[0], a[j].matricula[0]) == 0)
        {
            return 1;
        }
    }
    if (atoi(matricula[0]) < 0)
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
        char matricula[tam_aluno][10];
        printf("\nInforme a matricula: ");
        scanf("%s", &matricula[0]);
        if (validar_matricula(a, matricula[0], ativo) != 0)
        {
            return 2;
        }
        strcpy(a[*ativo].matricula, matricula[0]);

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
        strcpy(a[*ativo].data_nascimento, data_nascimento);

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
        printf("\nMatricula: %s\nNome: %s\nSexo: %c\nCPF: %s\nData de Nascimento: %s\n", a[i].matricula[0], a[i].nome, a[i].sexo, a[i].cpf, a[i].data_nascimento);
        printf("\n");
    }
    return 0;
}

int atualizar_aluno(aluno a[], int *ativo)
{
    char busca_matricula[tam_aluno][10];
    int OpAtualizar;
    int pos = -1;
    if (*ativo == 0)
    {
        return 1;
    }
    printf("\nInforme a matricula do aluno que deseja atualizar: ");
    scanf("%s", &busca_matricula[0]);
    for (int i = 0; i < *ativo; i++)
    {
        if (strcmp(busca_matricula[0], a[i].matricula[0]) == 0)
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
        char matricula[tam_aluno][10];
        printf("\nInforme a matricula: ");
        scanf("%s", &matricula[0]);
        if (validar_matricula(a, matricula[0], ativo) != 0)
        {
            return 2;
        }
        strcpy(a[pos].matricula, matricula[0]);
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
    char busca_matricula[tam_aluno][10];
    int pos = -1;
    if (*ativo == 0)
    {
        return 1;
    }
    printf("\nInforme a matricula do aluno que deseja excluir: ");
    scanf("%s", &busca_matricula[0]);
    for (int i = 0; i < *ativo; i++)
    {
        if (strcmp(busca_matricula[0], a[i].matricula[0]) == 0)
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
