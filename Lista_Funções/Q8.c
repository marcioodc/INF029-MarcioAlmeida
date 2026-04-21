#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char *CadastrarCliente()
{
    char n[100];
    char DataNascimento[15];
    char sexo;
    char cpf[15];

    printf("Informe o nome do cliente: ");
    fgets(n, sizeof(n), stdin);
    n[strcspn(n, "\n")] = '\0';
    char *nome = malloc(strlen(n) + 1);
    strcpy(nome, n);
    return nome;

    printf("Informe a data de nascimento do cliente: ");
    scanf(" %14s", DataNascimento);
    char *DNascimento = malloc(strlen(DataNascimento) + 1);
    strcpy(DNascimento, DataNascimento);
    return DNascimento;

    printf("Informe o CPF do cliente: ");
    scanf(" %15s", cpf);
    char *c_cpf = malloc(strlen(cpf) + 1);
    strcpy(c_cpf, cpf);
    return c_cpf;

    printf("Informe o sexo do cliente (F/ M/ O): ");
    scanf(" %c", &sexo);
    sexo = toupper(sexo);
    char *c_sexo = malloc(sizeof(char));
    *c_sexo = sexo;
    return c_sexo;
}

int main()
{
    char *nome;
    char *DNascimento;
    char *c_cpf;
    char *c_sexo;

    nome = CadastrarCliente();
    DNascimento = CadastrarCliente();   
    printf("Nome: %s\n", nome);
    printf("Data de Nascimento: %s\n", DNascimento);
    printf("CPF: %s\n", c_cpf);
    printf("Sexo: %c\n", *c_sexo);
    free(nome);
    free(DNascimento);
    free(c_cpf);
    free(c_sexo);
    return 0;
}