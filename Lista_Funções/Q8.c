#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int CadastrarCliente(){
    char nome[100];
    char DataNascimento[15];
    char sexo;
    char cpf[15];

    printf("Informe o nome do cliente: ");
    fgets(nome, sizeof(nome), stdin);
    nome[strcspn(nome, "\n")] = '\0';

    printf("Informe a data de nascimento do cliente: ");
    scanf(" %s", DataNascimento);

    printf("Informe o CPF do cliente: ");
    scanf(" %15s", cpf);

    printf("Informe o sexo do cliente (F/ M/ O): ");
    scanf(" %c", &sexo);
    sexo = toupper(sexo);
    
    return nome, DataNascimento, cpf, sexo;
}

int main()
{
    
    return 0;
}