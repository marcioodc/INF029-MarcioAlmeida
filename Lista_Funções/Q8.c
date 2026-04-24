#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct
{
    char nome[100];
    char DataNascimento[15];
    char sexo;
    char cpf[15];
} cliente;

cliente c[2];

void CadastrarCliente()
{
    printf("Informe o nome do cliente: ");
    fgets(c[0].nome, sizeof(c[0].nome), stdin);
    c[0].nome[strcspn(c[0].nome, "\n")] = '\0';

    printf("Informe a data de nascimento do cliente: ");
    scanf(" %s", c[0].DataNascimento);

    printf("Informe o CPF do cliente: ");
    scanf(" %15s", c[0].cpf);

    printf("Informe o sexo do cliente (F/ M/ O): ");
    scanf(" %c", &c[0].sexo);
    c[0].sexo = toupper(c[0].sexo);
}

int main()
{
    CadastrarCliente();
    printf("---Cliente---\n");
    printf("Nome: %s\nCPF: %s\nData de Nascimento: %s\nSexo: %c\n", c[0].nome, c[0].cpf, c[0].DataNascimento, c[0].sexo);
    return 0;
}
