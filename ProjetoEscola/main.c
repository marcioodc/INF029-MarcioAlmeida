#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "aluno.h"

int menu_principal();
int menu_aluno();
int menu_professor();
int menu_disciplina();

int main(){
  int op, op_aluno, op_prof, op_disciplina;
  int qtd_aluno = 0, qtd_prof = 0, qtd_disciplina = 0;
  aluno a[TAM_ALUNO];
  while(1){
    switch(menu_principal()){
      case 0:
        printf("Saindo do programa...\n");
        return 0;
      case 1:
        switch(menu_aluno()){
          case 0:
            break;
          case 1:
            int cas_aluno = cadastrar_aluno(a, &qtd_aluno);
            switch(cas_aluno){
              case 0:
                printf("Aluno cadastrado com sucesso!\n");
                break;
              case 1:
                printf("Erro: Matrícula já existe ou é inválida. Tente novamente!\n");
                break;
              case 2:
                printf("Erro: Nome do aluno é muito longo. Tente novamente!\n");
                break;
              case 3:
                printf("Erro: Sexo do aluno é inválido. Tente novamente!\n");
                break;
              case 4:
                printf("Erro: Data de nascimento do aluno é inválida. Tente novamente!\n");
                break;
              default:
                printf("Erro desconhecido. Tente novamente!\n");
            }
            break;
          /*case 2:
            int acas_aluno = atualizar_cadastro_aluno();
            switch(acas_aluno){
              case 0:
                printf("Cadastro do aluno atualizado com sucesso!\n");
                break;
              case 1:
                printf("Erro: Matrícula não encontrada. Tente novamente.\n");
                break;
              case 2:
                printf("Erro: Nome do aluno é muito longo. Tente novamente.\n");
                break;
              case 3:
                printf("Erro: Idade do aluno é inválida. Tente novamente.\n");
                break;
              default:
                printf("Erro desconhecido. Tente novamente.\n");
            }
            break;
          case 3:
            int ecas_aluno = excluir_cadastro_aluno();
            switch(ecas_aluno){
              case 0:
                printf("Cadastro do aluno excluído com sucesso!\n");
                break;
              case 1:
                printf("Erro: Matrícula não encontrada. Tente novamente.\n");
                break;
              default:
                printf("Erro desconhecido. Tente novamente.\n");
            }
            break;
          default:
            printf("Opção inválida. Tente novamente.\n");
        }
        break;
      case 2:
        switch(menu_professor()){
          case 0:
            break;
          case 1:
            //cadastrar_professor();
            break;
          case 2:
            //atualizar_cadastro_professor();
            break;
          case 3:
            //excluir_cadastro_professor();
            break;
          default:
            printf("Opção inválida. Tente novamente.\n");
        }
        break;
      case 3:
        switch(menu_disciplina()){
          case 0:
            break;
          // Adicione as opções para disciplina aqui
          default:
            printf("Opção inválida. Tente novamente.\n");
        }
        break;
      // Adicione o menu para relatório aqui
      default:
        printf("Opção inválida. Tente novamente.\n");*/
          }
    }
  }
}

int menu_principal(){
  int op;
  printf("\n>>>Projeto Escola<<<\n");
  printf("Escolha uma opcção:\n");
  printf("0 > Sair\n");
  printf("1 > Menu aluno\n");
  printf("2 > Menu professor\n");
  printf("3 > Menu disciplina\n");
  printf("4 > Menu Relatório\n");
  scanf("%d", &op);
  return op;
}

int menu_aluno(){
  int op_aluno; 
  printf("\n>>>MENU ALUNO<<<\n");
  printf("0 > Voltar\n");
  printf("1 > Cadastrar aluno\n");
  printf("2 > Atualizar cadastro do aluno\n");
  printf("3 > Excluir cadastro do aluno\n");
  scanf("%d", &op_aluno);
  return op_aluno;
}

int menu_professor(){
  int op_prof;
  printf("\n>>>MENU PROFESSOR<<<\n");
  printf("0 > Voltar\n");
  printf("1 > Cadastrar professor\n");
  printf("2 > Atualizar cadastro do professor\n");
  printf("3 > Excluir cadastro do professor\n");
  scanf("%d", &op_prof);
  return op_prof;
}

int menu_disciplina(){
  printf("\n>>>MENU DISCIPLINA<<<\n");
  printf("0 > Voltar\n");
  printf("1 > Cadastar disciplina\n");
}