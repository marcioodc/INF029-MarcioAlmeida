#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "aluno.h"

int validar_cpf(char cpf[])
{
    if (strlen(cpf) != 11)
    {
        return 0;
    }
    return 1;
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
        printf("\nInforme a matrícula: ");
        scanf("%d", &matricula);
        // VERIFICA SE A MATRICULA É VÁLIDA
        for (int j = 0; j < *ativo; j++)
        {
            if (matricula == a[j].matricula)
            {
                return 2;
            }
        }
        if (matricula < 0)
        {
            return 2;
        }
        a[*ativo].matricula = matricula;

        getchar();
        // NOME
        printf("Informe o nome: ");
        fgets(a[*ativo].nome, sizeof(a[*ativo].nome), stdin);
        a[*ativo].nome[strcspn(a[*ativo].nome, "\n")] = '\0';

        // SEXO
        char sexo;
        printf("Informe o sexo (F ou M): ");
        scanf(" %c", &sexo);
        sexo = toupper(sexo);
        if (sexo != 'F' && sexo != 'M')
        {
            return 3;
        }
        a[*ativo].sexo = sexo;

        // CPF
        char cpf[15];
        printf("Informe o CPF: ");
        scanf("%15s", cpf);
        if (validar_cpf(cpf) == 0)
        {
            return 4;
        }
        strcpy(a[*ativo].cpf, cpf);

        // DATA NASCIMENTO
        printf("Informe a data de nascimento: ");
        scanf("%s", a[*ativo].data_nascimento);

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
        printf("%d -> Matrícula: %d", i + 1, a[i].matricula);
    }
    return 0;
}

int atualizar_aluno(aluno a[], int *ativo)
{
}

int excluir_aluno(aluno a[], int *ativo)
{
}

int validar_DATA(char data_nascimento)
{
}

int validar_CPF(char cpf)
{
}