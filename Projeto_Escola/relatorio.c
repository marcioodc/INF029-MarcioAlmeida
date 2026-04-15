#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "aluno.h"
#include "relatorio.h"
#include "professor.h"
#include "disciplina.h"

int listar_alunos(aluno a[], int *A_ativo)
{
    printf("\n>>>Lista de alunos cadastrados<<<\n");
    printf("\n");
    for (int i = 0; i < *A_ativo; i++)
    {
        printf("%d - Nome: %s\tMatricula: %d\tSexo: %c\t\tCPF: %s\tData de nascimento: %s\n", i + 1, a[i].nome, a[i].matricula, a[i].sexo, a[i].cpf, a[i].data_nascimento);
    }
    return 0;
}

int listar_professores(professor p[], int *P_ativo)
{
    printf("\n>>>Lista de professores cadastrados<<<\n");
    printf("\n");
    for (int i = 0; i < *P_ativo; i++)
    {
        printf("%d - Nome: %s\tMatricula: %d\tSexo: %c\t\tCPF: %s\tData de nascimento: %s\n", i + 1, p[i].nome, p[i].matricula, p[i].sexo, p[i].cpf, p[i].data_nascimento);
    }
    return 0;
}

int listar_disciplinas(disciplina d[], int *D_ativa, professor p[], int *P_ativo)
{
    char nome_p[100];
    printf("\n>>>Lista de disciplinas cadastradas<<<\n");
    printf("\n");
    for (int i = 0; i < *D_ativa; i++)
    {
        for (int j = 0; j < *P_ativo; j++)
        {
            if (d[i].matricula_professor == p[j].matricula)
            {
                strcpy(nome_p, p[j].nome);
                break;
            }
        }
        printf("%d - Codigo: %s\tNome: %s\tSemestre: %d\tQuantidade de vagas: %d\t\tProfessor: %s\n", i + 1, d[i].codigo, d[i].nome, d[i].semestre, d[i].vagas_total, nome_p);
    }
    return 0;
}

int listar_alunos_disciplina(disciplina d[], int *D_ativa, aluno a[], int *A_ativo)
{
    char nome_a[100];
    int matricula_a;
    printf("\n>>>Lista de alunos matriculados em cada disciplina<<<\n");
    for (int i = 0; i < *D_ativa; i++)
    {
        printf("\n%d - Codigo: %s\tNome: %s\tSemestre: %d\n", i + 1, d[i].codigo, d[i].nome, d[i].semestre);
        printf("Alunos matriculados\n");
        for (int j = 0; j < d[i].qtdalunos; j++)
        {
            for (int k = 0; k < *A_ativo; k++)
            {
                if (d[i].alunos_matriculados[j] == a[k].matricula)
                {
                    strcpy(nome_a, a[k].nome);
                    matricula_a = a[k].matricula;
                    break;
                }
            }
            printf("- Nome: %s\tMatricula: %d\n", nome_a, matricula_a);
        }
    }
    return 0;
}

int listar_alunos_sexo(aluno a[], int *A_ativo)
{
    if (*A_ativo == 0)
    {
        return 1;
    }
    printf("\n>>>Alunos por sexo<<<\n");
    printf("\nSexo masculino\n");
    int j = 0;
    for (int i = 0; i < *A_ativo; i++)
    {

        if (a[i].sexo == 'm' || a[i].sexo == 'M')
        {
            j++;
            printf("%d - Nome: %s\tMatricula: %d\tSexo: %c\n", j, a[i].nome, a[i].matricula, a[i].sexo);
        }
    }
    printf("\nSexo feminino\n");
    j = 0;
    for (int i = 0; i < *A_ativo; i++)
    {
        if (a[i].sexo == 'f' || a[i].sexo == 'F')
        {
            j++;
            printf("%d - Nome: %s\tMatricula: %d\tSexo: %c\n", j, a[i].nome, a[i].matricula, a[i].sexo);
        }
    }
    return 0;
}

int alunos_ordenados_nome(aluno a[], int *A_ativo)
{
    if (*A_ativo == 0)
    {
        return 1;
    }
    aluno aux;
    for (int i = 0; i < *A_ativo - 1; i++)
    {
        for (int j = 0; j < *A_ativo - i - 1; j++)
        {
            if (strcmp(a[j].nome, a[j + 1].nome) > 0)
            {
                aux = a[j];
                a[j] = a[j + 1];
                a[j + 1] = aux;
            }
        }
    }
    printf("\n>>>Lista de alunos por nome<<<\n");
    printf("\n");
    for (int i = 0; i < *A_ativo; i++)
    {
        printf("%d - Nome: %s\tMatricula: %d\n", i + 1, a[i].nome, a[i].matricula);
    }
    return 0;
}

int alunos_ordenados_data(aluno a[], int *A_ativo)
{
    if (*A_ativo == 0)
    {
        return 1;
    }
    printf("\n>>>Lista de alunos por data de nascimento<<<\n");
    aluno aux;
    for (int i = 0; i < *A_ativo - 1; i++)
    {
        for (int j = 0; j < *A_ativo - i - 1; j++)
        {
            if (comparar_datas(a[j].data_nascimento, a[j + 1].data_nascimento) > 0)
            {
                aux = a[j];
                a[j] = a[j + 1];
                a[j + 1] = aux;
            }
        }
    }
    printf("\n");
    for (int i = 0; i < *A_ativo; i++)
    {
        printf("%d - Nome: %s\tMatricula: %d\tData de nascimento: %s\n", i + 1, a[i].nome, a[i].matricula, a[i].data_nascimento);
    }
    return 0;
}

int listar_professores_sexo(professor p[], int *P_ativo)
{
    if (*P_ativo == 0)
    {
        return 1;
    }
    printf("\n>>>Lista de professores por sexo<<<\n");
    printf("\nSexo masculino\n");
    int j;
    for (int i = 0; i < *P_ativo; i++)
    {
        if (p[i].sexo == 'm' || p[i].sexo == 'M')
        {
            j = 1;
            printf("%d - Nome: %s\tMatricula: %d\tSexo: %c\n", j, p[i].nome, p[i].matricula, p[i].sexo);
        }
        j++;
    }
    printf("\nSexo feminino\n");
    for (int i = 0; i < *P_ativo; i++)
    {
        if (p[i].sexo == 'f' || p[i].sexo == 'F')
        {
            j = 1;
            printf("%d - Nome: %s\tMatricula: %d\tSexo: %c\n", j, p[i].nome, p[i].matricula, p[i].sexo);
        }
        j++;
    }
    return 0;
}

int professores_ordenados_nome(professor p[], int *P_ativo)
{
    if (*P_ativo == 0)
    {
        return 1;
    }
    printf("\n>>>Lista de professores por nome<<<\n");
    professor aux;
    for (int i = 0; i < *P_ativo - 1; i++)
    {
        for (int j = 0; j < *P_ativo - i - 1; j++)
        {
            if (strcmp(p[j].nome, p[j + 1].nome) > 0)
            {
                aux = p[j];
                p[j] = p[j + 1];
                p[j + 1] = aux;
            }
        }
    }
    printf("\n");
    for (int i = 0; i < *P_ativo; i++)
    {
        printf("%d - Nome: %s\tMatricula: %d\n", i + 1, p[i].nome, p[i].matricula);
    }
    return 0;
}

int professores_ordenados_data(professor p[], int *P_ativo)
{
    if (*P_ativo == 0)
    {
        return 1;
    }
    printf("\n>>>Lista de professores por data de nascimento<<<\n");
    professor aux;
    for (int i = 0; i < *P_ativo - 1; i++)
    {
        for (int j = 0; j < *P_ativo - i - 1; j++)
        {
            if (comparar_datas(p[j].data_nascimento, p[j + 1].data_nascimento) > 0)
            {
                aux = p[j];
                p[j] = p[j + 1];
                p[j + 1] = aux;
            }
        }
    }
    printf("\n");
    for (int i = 0; i < *P_ativo; i++)
    {
        printf("%d - Nome: %s\tMatricula: %d\tData de nascimento: %s\n", i + 1, p[i].nome, p[i].matricula, p[i].data_nascimento);
    }
    return 0;
}

int aniversariantes_mes(aluno a[], int *A_ativo, professor p[], int *P_ativo)
{
    if (*A_ativo == 0)
    {
        return 1;
    }
    char mes[3];
    printf("Informe o mes (MM): ");
    scanf("%s", mes);
    printf("\n>>>Alunos aniversariantes do mes<<<\n");
    printf("\n");
    int j;
    for (int i = 0; i < *A_ativo; i++)
    {
        if (a[i].data_nascimento[3] == mes[0] && a[i].data_nascimento[4] == mes[1])
        {
            j = 1;
            printf("%d - Nome: %s\tMatricula: %d\tData de nascimento: %s\n", j, a[i].nome, a[i].matricula, a[i].data_nascimento);
        }
        j++;
    }
    printf("\n");
    printf("\n>>>Professores aniversariantes do mes<<<\n");
    printf("\n");
    for (int i = 0; i < *P_ativo; i++)
    {
        if (p[i].data_nascimento[3] == mes[0] && p[i].data_nascimento[4] == mes[1])
        {
            j = 1;
            printf("%d - Nome: %s\tMatricula: %d\tData de nascimento: %s\n", j, p[i].nome, p[i].matricula, p[i].data_nascimento);
        }
        j++;
    }
    return 0;
}

int buscar_nome(aluno a[], int *A_ativo, professor p[], int *P_ativo)
{
    if (*A_ativo == 0 && *P_ativo == 0)
    {
        return 1;
    }
    char busca[100];
    printf("\n>>>Busca por nome<<<\n");
    printf("Informe o nome a ser buscado: ");
    fgets(busca, sizeof(busca), stdin);
    busca[strcspn(busca, "\n")] = '\0';
    if (strlen(busca) < 3)
    {
        return 2;
    }
    printf("\n>>>Alunos encontrados<<<\n");
    printf("\n");
    int j = 1;
    for (int i = 0; i < *A_ativo; i++)
    {
        if (strstr(a[i].nome, busca) != NULL)
        {
            printf("%d - Nome: %s\tMatricula: %d\tSexo: %c\t\tCPF: %s\tData de nascimento: %s\n", j, a[i].nome, a[i].matricula, a[i].sexo, a[i].cpf, a[i].data_nascimento);
        }
        j++;
    }
    printf("\n>>>Professores encontrados<<<\n");
    printf("\n");
    j = 1;
    for (int i = 0; i < *P_ativo; i++)
    {
        if (strstr(p[i].nome, busca) != NULL)
        {
            printf("%d - Nome: %s\tMatricula: %d\tSexo: %c\t\tCPF: %s\tData de nascimento: %s\n", j, p[i].nome, p[i].matricula, p[i].sexo, p[i].cpf, p[i].data_nascimento);
        }
        j++;
    }
    return 0;
}

int alunos_matriculados_menos_3_disciplinas(aluno a[], int *A_ativo, disciplina d[], int *D_ativa)
{
    if (*A_ativo == 0 || *D_ativa == 0)
    {
        return 1;
    }
    printf("\n>>>Alunos matriculados em menos de 3 disciplinas<<<\n");
    printf("\n");
    int l;
    for (int i = 0; i < *A_ativo; i++)
    {
        int contador = 0;
        for (int j = 0; j < *D_ativa; j++)
        {
            for (int k = 0; k < d[j].qtdalunos; k++)
            {
                if (a[i].matricula == d[j].alunos_matriculados[k])
                {
                    contador++;
                }
            }
        }
        if (contador < 3)
        {
            l = 1;
            printf("%d - Nome: %s\tMatricula: %d\n", l, a[i].nome, a[i].matricula);
        }
        l++;
    }
    return 0;
}

int disciplinas_professor_40vagas(professor p[], int *P_ativo, disciplina d[], int *D_ativa)
{
    if (*P_ativo == 0 || *D_ativa == 0)
    {
        return 1;
    }
    printf("\n>>>Disciplinas com mais de 40 vagas<<<\n");
    int k = 0;
    for (int i = 0; i < *D_ativa; i++)
    {
        if (d[i].vagas_total > 40)
        {
            char nome_p[100];
            char sexo_p;
            char cpf_p[15];
            int matricula_p;
            char data_nascimento_p[10];
            for (int j = 0; j < *P_ativo; j++)
            {
                if (d[i].matricula_professor == p[j].matricula)
                {
                    strcpy(data_nascimento_p, p[j].data_nascimento);
                    strcpy(nome_p, p[j].nome);
                    strcpy(cpf_p, p[j].cpf);
                    sexo_p = p[j].sexo;
                    matricula_p = p[j].matricula;
                    break;
                }
            }
            k++;
            printf("\n%d - Codigo: %s\tNome: %s\tSemestre: %d\tQuantidade de vagas: %d\n\tProfessor\nNome: %s\tMatricula: %d\tSexo: %c\tCPF: %s\tData de nascimento: %s\n", k, d[i].codigo, d[i].nome, d[i].semestre, d[i].vagas_total, nome_p, matricula_p, sexo_p, cpf_p, data_nascimento_p);
        }
    }
    return 0;
}

int comparar_datas(char d1[], char d2[])
{
    int dia1, mes1, ano1;
    int dia2, mes2, ano2;

    sscanf(d1, "%d/%d/%d", &dia1, &mes1, &ano1);
    sscanf(d2, "%d/%d/%d", &dia2, &mes2, &ano2);

    if (ano1 != ano2)
    {
        return ano1 - ano2;
    }
    if (mes1 != mes2)
    {
        return mes1 - mes2;
    }
    return dia1 - dia2;
}