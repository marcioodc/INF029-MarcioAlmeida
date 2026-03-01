#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "aluno.h"

int cadastrar_aluno(aluno a[], int *qtd_aluno){
    if(*qtd_aluno >= TAM_ALUNO){
        return 1;
    }
    printf("Digite a matricula do aluno: ");
    scanf("%d", &a[*qtd_aluno].matricula);
    if(a[*qtd_aluno].matricula <= 0){
        return 1;
    }

    printf("Digite o nome do aluno: ");
    scanf(" %[^\n]s", a[*qtd_aluno].nome);
    if(strlen(a[*qtd_aluno].nome) == 0 || strlen(a[*qtd_aluno].nome) > 100){
        return 2;
    }

    printf("Digite o sexo do aluno (M/F): ");
    scanf(" %c", &a[*qtd_aluno].sexo);
    if(toupper(a[*qtd_aluno].sexo) != 'M' && toupper(a[*qtd_aluno].sexo) != 'F'){
        return 3;
    }

    printf("Digite a data de nascimento do aluno (dd/mm/aaaa): ");
    scanf("%d/%d/%d", &a[*qtd_aluno].data_nascimento[0], &a[*qtd_aluno].data_nascimento[1], &a[*qtd_aluno].data_nascimento[2]);
    if(a[*qtd_aluno].data_nascimento[0] <= 0 || a[*qtd_aluno].data_nascimento[0] > 31 ||
         a[*qtd_aluno].data_nascimento[1] <= 0 || a[*qtd_aluno].data_nascimento[1] > 12 ||
          a[*qtd_aluno].data_nascimento[2] <= 1800 || a[*qtd_aluno].data_nascimento[2] > 2026){
        return 4;
    }

    (*qtd_aluno)++;
    return 0;
}