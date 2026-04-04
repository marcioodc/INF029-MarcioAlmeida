#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "professor.h"

int valida_matricula(professor p[], int matricula, int *P_ativo)
{
    for (int j = 0; j < *P_ativo; j++)
    {
        if (matricula == p[j].matricula)
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

int validacao_cpf(char cpf[])
{
    if (strlen(cpf) != 11)
    {
        return 0;
    }
    return 1;
}

int validar_data(char data_nascimento[])
{
    char dia[3], mes[3], ano[5];
    for (int i = 0; data_nascimento[i] != '\0'; i++)
    {
        while (data_nascimento[i] != '/')
        {
            dia[0] = data_nascimento[i];
            dia[1] = data_nascimento[i + 1];
            dia[2] = '\0';
            i++;
        }
        i++;
        while (data_nascimento[i] != '/')
        {
            mes[0] = data_nascimento[i];
            mes[1] = data_nascimento[i + 1];
            mes[2] = '\0';
            i++;
        }
        i++;
        while (data_nascimento[i] != '\0')
        {
            ano[0] = data_nascimento[i];
            ano[1] = data_nascimento[i + 1];
            ano[2] = data_nascimento[i + 2];
            ano[3] = data_nascimento[i + 3];
            ano[4] = '\0';
            i++;
        }
        int d = atoi(dia);
        int m = atoi(mes);
        int a = atoi(ano);
        if (d < 1 || d > 31 || m < 1 || m > 12 || a < 1900 || a > 2024)
        {
            return 1;
        }
        if ((m == 4 || m == 6 || m == 9 || m == 11) && d > 30)
        {
            return 1;
        }
        if (m == 2)
        {
            if ((a % 4 == 0 && a % 100 != 0) || (a % 400 == 0))
            {
                if (d > 29)
                {
                    return 1;
                }
            }
            else
            {
                if (d > 28)
                {
                    return 1;
                }
            }
        }
    }
    return 0;
}

int cadastrar_professor(professor p[], int *P_ativo)
{
    if (*P_ativo == tam_professor)
    {
        return 1;
    }
    else
    {
        int matricula;
        printf("\nInforme a matricula: ");
        scanf("%d", &matricula);
        if (valida_matricula(p, matricula, P_ativo) != 0)
        {
            return 2;
        }
        p[*P_ativo].matricula = matricula;

        getchar();
        printf("Informe o nome: ");
        fgets(p[*P_ativo].nome, sizeof(p[*P_ativo].nome), stdin);
        p[*P_ativo].nome[strcspn(p[*P_ativo].nome, "\n")] = '\0';

        char sexo;
        printf("Informe o sexo (F ou M): ");
        scanf(" %c", &sexo);
        sexo = toupper(sexo);
        if (sexo != 'F' && sexo != 'M')
        {
            return 3;
        }
        p[*P_ativo].sexo = sexo;

        char cpf[15];
        printf("Informe o CPF: ");
        scanf("%15s", cpf);
        if (validacao_cpf(cpf) == 0)
        {
            return 4;
        }
        strcpy(p[*P_ativo].cpf, cpf);

        char p_data_nascimento[15];
        printf("Informe a data de nascimento: ");
        scanf("%s", p_data_nascimento);
        if (validar_data(p_data_nascimento) == 1)
        {
            return 5;
        }
        strcpy(p[*P_ativo].data_nascimento, p_data_nascimento);

        (*P_ativo)++;
        return 0;
    }
}

int listar_professor(professor p[], int *P_ativo)
{
    if (*P_ativo == 0)
    {
        return 1;
    }
    int j = 1;
    printf("\n>>>professores cadastrados<<<\n");
    for (int i = 0; i < *P_ativo; i++)
    {
        printf("\nMatricula: %d\nNome: %s\nSexo: %c\nCPF: %s\nData de Nascimento: %s\n", p[i].matricula, p[i].nome, p[i].sexo, p[i].cpf, p[i].data_nascimento);
        printf("\n");
    }
    return 0;
}

int atualizar_professor(professor p[], int *P_ativo)
{
    int busca_matricula;
    int OpAtualizar;
    int pos = -1;
    if (*P_ativo == 0)
    {
        return 1;
    }
    printf("\nInforme a matricula do professor que deseja atualizar: ");
    scanf("%d", &busca_matricula);
    for (int i = 0; i < *P_ativo; i++)
    {
        if (busca_matricula == p[i].matricula)
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
        if (valida_matricula(p, matricula, P_ativo) != 0)
        {
            return 2;
        }
        p[pos].matricula = matricula;
        return 0;
    }
    break;
    case 2:
    {
        getchar();
        printf("Informe o nome: ");
        fgets(p[pos].nome, sizeof(p[pos].nome), stdin);
        p[pos].nome[strcspn(p[pos].nome, "\n")] = '\0';
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
        p[pos].sexo = sexo;
        return 0;
    }
    break;
    case 4:
    {
        char cpf[15];
        printf("Informe o CPF: ");
        scanf("%15s", cpf);
        if (validacao_cpf(cpf) == 0)
        {
            return 4;
        }
        strcpy(p[pos].cpf, cpf);
        return 0;
    }
    break;
    case 5:
    {
        char p_d_nascimento[15];
        printf("Informe a data de nascimento: ");
        scanf("%s", p_d_nascimento);
        if (validar_data(p_d_nascimento) == 1)
        {
            return 5;
        }
        strcpy(p[pos].data_nascimento, p_d_nascimento);
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

int excluir_professor(professor p[], int *P_ativo)
{
    int busca_matricula;
    int pos = -1;
    if (*P_ativo == 0)
    {
        return 1;
    }
    printf("\nInforme a matricula do professor que deseja excluir: ");
    scanf("%d", &busca_matricula);
    for (int i = 0; i < *P_ativo; i++)
    {
        if (busca_matricula == p[i].matricula)
        {
            pos = i;
            break;
        }
    }
    if (pos == -1)
    {
        return 2;
    }
    for (int j = pos; j < *P_ativo - 1; j++)
    {
        p[j] = p[j + 1];
    }
    (*P_ativo)--;
    return 0;
}
