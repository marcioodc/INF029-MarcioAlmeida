#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "aluno.h"

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
        if (matricula < 0)
        {
            return 2;
        }
        else
        {
            a[*ativo].matricula = matricula;
        }
        getchar();
        // NOME
        printf("Informe o nome: ");
        fgets(a[*ativo].nome, sizeof(a[*ativo].nome), stdin);
        a[*ativo].nome[strcspn(a[*ativo].nome, "\n")] = '\0';
        getchar();
        // SEXO
        char sexo;
        printf("Informe o sexo (F ou M): ");
        scanf("%c", &sexo);
        sexo = toupper(sexo);
        if (sexo != 'F' && sexo != 'M')
        {
            return 3;
        }
        else
        {
            a[*ativo].sexo = sexo;
        }
        // CPF
        printf("Informe o CPF: ");
        scanf(" 15S", a[*ativo].cpf);
        getchar();
        // DATA NASCIMENTO
        printf("Informe a data de nascimento: ");
        scanf("%s", a[*ativo].data_nascimento);

        (*ativo)++;
        return 0;
    }
}

int listar_aluno(aluno a[], int *ativo)
{
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