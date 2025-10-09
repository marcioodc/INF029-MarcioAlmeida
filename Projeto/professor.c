#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "professor.h"


void cadastrarprof(professor p[], int *qtdprof){
    //cadastrar professor
    int matricula;
    if(*qtdprof == TAMPROFESSOR){
        printf("A lista está cheia!\n");
        return;                        
    }else{
        printf("--Cadastrando professor--\n");
        printf("Informações do professor:\n");
        printf("Matricula: ");
        scanf("%d", &matricula);
        if(posprof(p, *qtdprof, matricula) != -1){
            printf("\nJá existe professor com essa matrícula!\n");
            return;
        }
        if(matricula < 0){
            printf("\nMatricula inválida!\n");
            return;
        }else{
            p[*qtdprof].matricula = matricula;
                                    //Nome do professor
            getchar();
            printf("Nome: ");
            fgets(p[*qtdprof].nome, sizeof(p[*qtdprof].nome), stdin);
            p[*qtdprof].nome[strcspn(p[*qtdprof].nome, "\n")] = '\0';
                                    //Sexo do professor
            printf("Sexo: 'F' ou 'M': ");
            scanf(" %c", &p[*qtdprof].sexo);
            p[*qtdprof].sexo = toupper(p[*qtdprof].sexo);
            if(p[*qtdprof].sexo != 'F' && p[*qtdprof].sexo != 'M'){
                printf("\nNão entendi! Use apenas 'M' ou 'F'!\n");
                return;
            }
                                    //CPF do professor
            printf("CPF (apenas números): ");
            scanf(" %12s", p[*qtdprof].cpf);
                                    
                                    //Data de nascimento do professor
            printf("Data de nascimento 'dd/mm/aaaa': ");
            scanf("%d/%d/%d", &p[*qtdprof].dia, &p[*qtdprof].mes, &p[*qtdprof].ano);
            int res= validaData(p[*qtdprof].dia, p[*qtdprof].mes, p[*qtdprof].ano);
            if(res == 0){
                printf("Data inválida!\n");
                return;
            }
            p[*qtdprof].ativo = 1;
            (*qtdprof)++;
            printf("***Cadastro realizado com sucesso!***\n");
            return;
        }
    }
}

void listarprof(professor p[], int *qtdprof){
    if(*qtdprof == 0){
        printf("A lista está vazia!\n");
        return;
    }else{
        printf("--Listando os professores--\n");
        for(int i=0; i < *qtdprof; i++){
            if(p[i].ativo == 1){
                printf("Matricula: %d  |  Nome: %s\n", p[i].matricula, p[i].nome);
                printf("Sexo: %c  |  Data de Nascimento: %d/%d/%d\n", p[i].sexo, p[i].dia, p[i].mes, p[i].ano);
                printf("CPF: %s\n", p[i].cpf);
            }
        }
        return;
    }
}

void atualizarprof(professor p[], int *qtdprof){
                                //atualizar professor
    int atualizarM;
    if(*qtdprof == 0){
        printf("\nNenhum professor cadastrado!\n");
        return;
    }
    printf("Informe a matricula do professor que você deseja atualizar: ");
    scanf("%d", &atualizarM);
    int posicao = posprof(p, *qtdprof, atualizarM);
                            
    if(posicao == -1){
        printf("\nProfessor não encontrado!\n");
        return;
    }else{
        professor novoprof;
        getchar();
                                //Nome do novo professor
        printf("\nNome: ");
        fgets(novoprof.nome, sizeof(novoprof.nome), stdin);
        novoprof.nome[strcspn(novoprof.nome, "\n")] = '\0';
                                
                                //Sexo do novo professor
        printf("Sexo: 'F' ou 'M': ");
        scanf(" %c", &novoprof.sexo);
        novoprof.sexo = toupper(novoprof.sexo);
        if(novoprof.sexo != 'F' && novoprof.sexo != 'M'){
            printf("Não entendi! Use apenas 'M' ou 'F'!\n");
            return;
        }
                                //CPF do novo professor 
        printf("CPF (apenas números): ");
        scanf(" %12s", novoprof.cpf);
        getchar();                          
                                //Data de nascimento do novo professor
        printf("Data de nascimento: 'dd/mm/aaaa': ");
        scanf("%d/%d/%d", &novoprof.dia, &novoprof.mes, &novoprof.ano);
        int res = validaData(novoprof.dia, novoprof.mes, novoprof.ano);
        if(res == 0){
            printf("Data inválida!\n");
            return;
        }
        novoprof.ativo = p[posicao].ativo;
        novoprof.matricula = p[posicao].matricula;
        p[posicao] = novoprof;
        printf("\n***Cadastro atualizado com sucesso!***\n");
        return;
    }
}

void excluirprof(professor p[], int *qtdprof){
     //excluir professor
    int excluir;
    if(*qtdprof == 0){
        printf("\nNenhum professor cadastrado!\n");
        return;
    }
    printf("Digite a matricula do professor que deseja excluir: ");
    scanf("%d", &excluir);
    int posexcluir = posprof(p, *qtdprof, excluir);
    if(posexcluir == -1){
        printf("Matricula não encontrada!\n");
        return;
    }else{
        for(int i = posexcluir; i < *qtdprof - 1; i++){
            p[i] = p[i+1];
        }
        (*qtdprof)--;
        p[*qtdprof].ativo = 0;
        printf("***Professor excluído com sucesso!***\n");
        return;
    } 
}

int posprof(professor p[], int qtdprof, int matricula){
    int i;
    for(i=0; i<qtdprof; i++){
        if(p[i].matricula == matricula){
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

