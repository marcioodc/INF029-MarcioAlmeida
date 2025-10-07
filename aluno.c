#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "aluno.h"
#include "disciplina.h"

int posaluno(aluno a[], int qtdaluno, int matricula){
    int i;
    for(i = 0; i < qtdaluno; i++){
        if(a[i].matricula == matricula){
            return i;
        }
    }
    return -1;
}

int validaData(int dia, int mes, int ano) {
    if (ano < 1 || mes < 1 || mes > 12 || dia < 1) return 0;

    int diasMes[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (mes == 2 && ((ano % 4 == 0 && ano % 100 != 0) || ano % 400 == 0)) {
        diasMes[2] = 29; // fevereiro em ano bissexto
    }

    return (dia <= diasMes[mes]) ? 1 : 0;
}

void cadastraraluno(aluno a[], int *qtdaluno){
    int matricula;
    if(*qtdaluno == TAMALUNO){
        printf("A lista está cheia!\n");
        return;
    }else{
        printf("--Cadastrando aluno--\n");
        printf("Informações do aluno:\n");
        printf("Matricula: ");
        scanf("%d", &matricula);
        if(posaluno(a, *qtdaluno, matricula) != -1){
        printf("\nJá existe aluno com essa matrícula!\n");
        return;
        } 
        else if(matricula < 0){
            printf("\nMatricula inválida!\n");
            return;
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
                printf("\nNão entendi! Use apenas 'M' ou 'F'!\n");
                return;
            }
                                    //CPF do aluno
            printf("CPF '123.456.789-01': ");
            scanf(" %15s", a[*qtdaluno].cpf);
                                      
                                    //Data de nascimento do aluno
            printf("Data de nascimento 'dd/mm/aaaa': ");
            scanf("%d/%d/%d", &a[*qtdaluno].dia, &a[*qtdaluno].mes, &a[*qtdaluno].ano);
            int res= validaData(a[*qtdaluno].dia, a[*qtdaluno].mes, a[*qtdaluno].ano);
            if(res == 0){
                printf("Data inválida!\n");
                return;
            }
                                    
            a[*qtdaluno].ativo = 1;
            (*qtdaluno)++;
                                 
            printf("***Cadastro realizado com sucesso***\n");
        }
    }
}

void listaraluno(aluno a[], int *qtdaluno){
                                //listar alunos
    if(*qtdaluno == 0){
        printf("A lista está vazia!\n");
        return;
    }else{
        printf("--Listando os alunos--\n");
        for(int i=0; i < *qtdaluno; i++){
            if(a[i].ativo == 1){
                printf("Matricula: %d  |  Nome: %s\n", a[i].matricula, a[i].nome);
                printf("Sexo: %c  |  Data de Nascimento: %d/%d/%d\n", a[i].sexo, a[i].dia, a[i].mes, a[i].ano);
                printf("CPF: %s\n", a[i].cpf);
                                       
            }
        }
        return;
    }
}

void atualizaraluno(aluno a[], int *qtdaluno){
                                //atualizar alunos
    int atualizarM;
    if(*qtdaluno == 0){
        printf("\nNenhum aluno cadastrado!\n");
        return;
    }
    printf("Informe a matricula do aluno que você deseja atualizar: ");
    scanf("%d", &atualizarM);
    int posicao = posaluno(a, *qtdaluno, atualizarM);
                            
    if(posicao == -1){
        printf("Aluno não encontrado!\n");
        return;
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
            printf("Não entendi! Use apenas 'M' ou 'F'!\n");
            return;
        }
                                //CPF do novo aluno 
        printf("CPF: ");
        scanf(" %14s", novoaluno.cpf);
                                  
                                //Data de nascimento do novo aluno
        printf("Data de nascimento: 'dd/mm/aaaa': ");
        scanf("%d/%d/%d", &novoaluno.dia, &novoaluno.mes, &novoaluno.ano);
        int res= validaData(novoaluno.dia, novoaluno.mes, novoaluno.ano);
        if(res == 0){
            printf("Data inválida!\n");
            return;
        }
        novoaluno.ativo = a[posicao].ativo;
        novoaluno.matricula = a[posicao].matricula;
        a[posicao] = novoaluno;
        printf("\n***Cadastro atualizado com sucesso!***\n");
        return;
    }
}

void excluiraluno(aluno a[], int *qtdaluno, disciplina d[], int *qtdisciplina){
                                //excluir aluno
    int excluir;
    if(*qtdaluno == 0){
        printf("\nNenhum aluno cadastrado!\n");
        return;
    }
    printf("Digite a matricula do aluno que deseja excluir: ");
    scanf("%d", &excluir);
    int posexcluir = posaluno(a, *qtdaluno, excluir);
    if(posexcluir == -1){
        printf("Matricula não encontrada!\n");
        return;
    }else{
        removerdedisciplina(d, *qtdisciplina, a[posexcluir].matricula, 'a');
        for(int i = posexcluir; i < *qtdaluno - 1; i++){
            a[i] = a[i+1];
        }
        (*qtdaluno)--;
        a[*qtdaluno].ativo = 0;
        printf("***Aluno excluído com sucesso***\n");
        return;
    }
}