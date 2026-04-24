#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct cliente{
    char nome[100];
    char DataNascimento[15];
    char sexo;
    char cpf[15];
} cliente;

int validar_data(char data[]){
    int d, m, a;
    if (sscanf(data, "%d/%d/%d", &d, &m, &a) != 3)
    {
        return 1;
    }
    if (m < 1 || m > 12 || a < 1800 || a > 2025)
    {
        return 1;
    }
    int dias_mes[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if ((a % 4 == 0 && a % 100 != 0) || (a % 400 == 0))
    {
        dias_mes[1] = 29;
    }
    if (d < 1 || d > dias_mes[m - 1])
    {
        return 1;
    }
    return 0;
}

int validar_CPF(char cpf[]){
    if (strlen(cpf) != 11)
    {
        return 1;
    }
    return 0;
}

int validar_nome(char nome[]){
    if(strlen(nome) > 20){
        return 1;
    }
    return 0;
}

int validar_sexo(char sexo){
    sexo = toupper(sexo);
    if (sexo != 'F' && sexo != 'M' && sexo != 'O')
    {
        return 1;
    }
    return 0;
}

int CadastrarCliente(cliente c[]){

    char nome[100];
    printf("Informe o nome do cliente: ");
    fgets(nome, sizeof(nome), stdin);
    nome[strcspn(nome, "\n")] = '\0';
    if (validar_nome(nome) == 1){
        return 1;
    }
    strcpy(c[0].nome, nome);

    char DataNascimento[15];
    printf("Informe a data de nascimento do cliente: ");
    scanf(" %s", DataNascimento);
    if (validar_data(DataNascimento) == 1){
        return 2;
    }
    strcpy(c[0].DataNascimento, DataNascimento);
    getchar();

    char cpf[15];
    printf("Informe o CPF do cliente: ");
    scanf(" %15s", cpf);
    if (validar_CPF(cpf) == 1){
        return 3;
    }
    strcpy(c[0].cpf, cpf);
    getchar();

    char sexo;
    printf("Informe o sexo do cliente (F/ M/ O): ");
    scanf(" %c", &sexo);
    sexo = toupper(sexo);
    if (validar_sexo(sexo) == 1){
        return 4;
    }
    c[0].sexo = sexo;
    getchar();

    return 0;
}

int main()
{
    cliente c[1];
    switch(CadastrarCliente(c)){
        case 1:
            printf("Nome invalido! O nome deve conter no maximo 20 caracteres.\n");
            break;
        case 2:
            printf("Data de nascimento invalida! A data deve estar no formato DD/MM/AAAA e ser uma data valida.\n");
            break;
        case 3:
            printf("CPF invalido! O CPF deve conter exatamente 11 caracteres.\n");
            break;
        case 4:
            printf("Sexo invalido! O sexo deve ser F, M ou O.\n");
            break;
        case 0:
            printf("Cliente cadastrado com sucesso!\n");
            printf("\nNome: %s\nData de nascimento: %s\nCPF: %s\nSexo: %c\n", c[0].nome, c[0].DataNascimento, c[0].cpf, c[0].sexo);
            break;
        default:
            printf("Erro desconhecido!\n");
            break;
    }
    
    return 0;
}

