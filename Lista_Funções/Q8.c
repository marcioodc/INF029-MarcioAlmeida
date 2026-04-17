#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct cliente{
    char nome[100];
    char DataNascimento[15];
    char sexo;
    char cpf[15];
}cliente;
int CadastrarCliente(){
    printf("Informe o nome do cliente: ");
    fgets(cliente.nome, sizeof(cliente.nome), stdin);
    cliente.nome[strcspn(cliente.nome, "\n")] = '\0';

    printf("Informe a data de nascimento do cliente: ");
    scanf(" %s", cliente.DataNascimento);

    printf("Informe o CPF do cliente: ");
    scanf(" %15s", cliente.cpf);

    printf("Informe o sexo do cliente (F/ M/ O): ");
    scanf(" %c", &cliente.sexo);
    cliente.sexo = toupper(cliente.sexo);
    
    return 0;
}

int main()
{
    printf("Nome: %s\nData de nascimento: %s\nCPF: %s\nSexo: %s\n", cliente.nome, cliente.DataNascimento, cliente.cpf, cliente.sexo);
    return 0;
}
