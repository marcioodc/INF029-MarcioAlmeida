#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#include "aluno.h"

int validar_matricula(aluno a[], char matricula[], int *A_ativo)
{
    for (int j = 0; j < *A_ativo; j++)
    {
        if (strcmp(matricula, a[j].matricula) == 0)
        {
            return 1;
        }
    }
    if (atoi(matricula) < 0)
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

int cadastrar_aluno(aluno a[], int *A_ativo)
{
    int pos = -1;
    if (*A_ativo == tam_aluno)
    {
        return 1;
    }
    else
    {
        char matricula[10];
        printf("\nInforme a matricula: ");
        scanf("%s", &matricula);
        if (validar_matricula(a, matricula, A_ativo) != 0)
        {
            return 2;
        }
        strcpy(a[*A_ativo].matricula, matricula);

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

        getchar();
        char a_data_nascimento[15];
        printf("Informe a data de nascimento: ");
        scanf(" %s", a_data_nascimento);
        if (validar_DATA(a_data_nascimento) == 1)
        {
            return 5;
        }
        strcpy(a[*A_ativo].data_nascimento, a_data_nascimento);

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
    printf("\n>>>Listagem de alunos<<<\n");
    for (int i = 0; i < *A_ativo; i++)
    {
        printf("\nNome: %s\nMatricula: %s\nSexo: %c\nCPF: %s\nData de nascimento: %s\n", a[i].nome, a[i].matricula, a[i].sexo, a[i].cpf, a[i].data_nascimento);
    }
    return 0;
}

int atualizar_aluno(aluno a[], int *A_ativo)
{
    if (*A_ativo == 0)
    {
        return 1;
    }
    char matricula[10];
    printf("\nInforme a matricula do aluno para atualizar: ");
    scanf("%s", &matricula);
    for (int i = 0; i < *A_ativo; i++)
    {
        if (strcmp(matricula, a[i].matricula) == 0)
        {
            int opcao;
            printf("\nO que deseja atualizar?\n1. Matricula\n2. Nome\n3. Sexo\n4. CPF\n5. Data de nascimento\n");
            scanf("%d", &opcao);
            switch (opcao)
            {            
                case 1:
            {
                char nova_matricula[10];
                printf("Informe a nova matricula: ");
                scanf("%s", &nova_matricula);
                if (validar_matricula(a, nova_matricula, A_ativo) != 0)
                {
                    return 2;
                }
                strcpy(a[i].matricula, nova_matricula);
                return 0;
            }
            break;
            case 2:
            {
                getchar();
                printf("Informe o nome: ");
                fgets(a[i].nome, sizeof(a[i].nome), stdin);
                a[i].nome[strcspn(a[i].nome, "\n")] = '\0';
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
                a[i].sexo = sexo;
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
                strcpy(a[i].cpf, cpf);
                return 0;
            }
            break; 
            case 5:
            {
                getchar();
                char a_data_nascimento[15];
                printf("Informe a data de nascimento: ");
                scanf(" %s", a_data_nascimento);
                if (validar_DATA(a_data_nascimento) == 1)
                {
                    return 5;
                }
                strcpy(a[i].data_nascimento, a_data_nascimento);
                return 0;
            }   
            break;
            default:
                printf("Opcao invalida!");
                return 0;
            }
        }
    }
    return 2;
}

int excluir_aluno(aluno a[], int *A_ativo)
{
    if (*A_ativo == 0)
    {
        return 1;
    }
    char matricula[10];
    printf("\nInforme a matricula do aluno para excluir: ");
    scanf("%s", &matricula);
    for (int i = 0; i < *A_ativo; i++)
    {
        if (strcmp(matricula, a[i].matricula) == 0)
        {
            for (int j = i; j < *A_ativo - 1; j++)
            {
                a[j] = a[j + 1];
            }
            (*A_ativo)--;
            return 0;
        }
    }
    return 2;
}

