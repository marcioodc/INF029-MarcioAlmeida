#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "aluno.h"

int posaluno(aluno a[], int qtdaluno, int matricula){
    for(int i = 0; i < qtdaluno; i++){
        if(a[i].matricula == matricula){
            return i;
        }
    }
    return -1;
}

int validaData(int dia, int mes, int ano) {
    if (ano < 1 || mes < 1 || mes > 12 || dia < 1){
        return 0;
    }
    int diasMes[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (mes == 2 && ((ano % 4 == 0 && ano % 100 != 0) || ano % 400 == 0)) {
        diasMes[2] = 29; // fevereiro em ano bissexto
    }
    return (dia <= diasMes[mes]) ? 1 : 0;
}

int cadastraraluno(aluno a[], int *qtdaluno){
    int matricula;
    if(*qtdaluno == TAMALUNO){
        return 0;
    }else{
        printf("--Cadastrando aluno--\n");
        printf("Informações do aluno:\n");
        printf("Matricula: ");
        scanf("%d", &matricula);
        if(posaluno(a, *qtdaluno, matricula) != -1){
            return 1;
        } 
        else if(matricula < 0){
            return 2;
        }else{
            a[*qtdaluno].matricula = matricula;
                //Nome do aluno
            getchar();
            printf("Nome: ");
            fgets(a[*qtdaluno].nome, sizeof(a[*qtdaluno].nome), stdin);
            a[*qtdaluno].nome[strcspn(a[*qtdaluno].nome, "\n")] = '\0';
                //Sexo do aluno
            printf("Sexo 'F' ou 'M': ");
            scanf(" %c", &a[*qtdaluno].sexo);
            a[*qtdaluno].sexo = toupper(a[*qtdaluno].sexo);
            if(a[*qtdaluno].sexo != 'F' && a[*qtdaluno].sexo != 'M'){
                return 3;
            }
                //CPF do aluno
            printf("CPF: ");
            scanf(" %15s", a[*qtdaluno].cpf);
            int cpf = validar_cpf(a[*qtdaluno].cpf);
            if(cpf == 0){
                return 4;
            }     
                //Data de nascimento do aluno
            printf("Data de nascimento 'dd/mm/aaaa': ");
            scanf("%d/%d/%d", &a[*qtdaluno].dia, &a[*qtdaluno].mes, &a[*qtdaluno].ano);
            int res= validaData(a[*qtdaluno].dia, a[*qtdaluno].mes, a[*qtdaluno].ano);
            if(res == 0){
                return 5;
            }           
            a[*qtdaluno].ativo = 1;
            (*qtdaluno)++;
            return 6;                     
        }
    }
}

int listaraluno(aluno a[], int qtdaluno){
    if(qtdaluno == 0){
        return 0;
    }else{
        printf("--Listando os alunos--\n");
        for(int i=0; i < qtdaluno; i++){
            if(a[i].ativo == 1){
                printf("\nMatricula: %d  -  Nome: %s\n", a[i].matricula, a[i].nome);
                printf("Sexo: %c  -  Data de Nascimento: %d/%d/%d\n", a[i].sexo, a[i].dia, a[i].mes, a[i].ano);
                printf("CPF: %s\n", a[i].cpf);
            }
        }
        return 1;
    }
}

int atualizaraluno(aluno a[], int *qtdaluno){
    int atualizarM;
    if(*qtdaluno == 0){
        return 0;
    }
    printf("Informe a matricula do aluno que você deseja atualizar: ");
    scanf("%d", &atualizarM);
    int posicao = posaluno(a, *qtdaluno, atualizarM);    
    if(posicao == -1){
        return 1;
    }else{
        aluno novoaluno;
        getchar();
            //Nome do novo aluno
        printf("\nNome: ");
        fgets(novoaluno.nome, sizeof(novoaluno.nome), stdin);
        novoaluno.nome[strcspn(novoaluno.nome, "\n")] = '\0';   
            //Sexo do novo aluno
        printf("Sexo: 'F' ou 'M': ");
        scanf(" %c", &novoaluno.sexo);
        novoaluno.sexo = toupper(novoaluno.sexo);
        if(novoaluno.sexo != 'F' && novoaluno.sexo != 'M'){
            return 2;
        }
            //CPF do novo aluno 
        printf("CPF: ");
        scanf(" %15s", novoaluno.cpf);
        int cpf = validar_cpf(novoaluno.cpf);
        if(cpf == 0){
            return 3;
        }
            //Data de nascimento do novo aluno
        printf("Data de nascimento: 'dd/mm/aaaa': ");
        scanf("%d/%d/%d", &novoaluno.dia, &novoaluno.mes, &novoaluno.ano);
        int res= validaData(novoaluno.dia, novoaluno.mes, novoaluno.ano);
        if(res == 0){
            return 4;
        }
        novoaluno.ativo = a[posicao].ativo;
        novoaluno.matricula = a[posicao].matricula;
        a[posicao] = novoaluno;
        return 5;
    }
}

int excluiraluno(aluno a[], int *qtdaluno){
    int excluir;
    if(*qtdaluno == 0){
        return 0;
    }
    printf("Digite a matricula do aluno que deseja excluir: ");
    scanf("%d", &excluir);
    int posexcluir = posaluno(a, *qtdaluno, excluir);
    if(posexcluir == -1){
        return 1;
    }else{
        for(int i = posexcluir; i < *qtdaluno - 1; i++){
            a[i] = a[i+1];
        }
        a[*qtdaluno].ativo = 0;
        (*qtdaluno)--;
        return 2;
    }
}

int validar_cpf(char cpf[]){
    if(strlen(cpf) > 16 || strlen(cpf) < 11){
        return 0;
    }
    for(int j = 0; cpf[j] != '\0'; ++j){
        if(isalpha((unsigned char)cpf[j])){
            return 0;
        }
    }
    return 1;
}
