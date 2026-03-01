#include <stdio.h>
#include <string.h>
#include <ctype.h>


int menu_principal();
int menu_aluno();
int menu_professor();
int menu_disciplina();

int main(){
  int op, op_aluno, op_prof, op_disciplina;
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
            cadastrar_aluno();
            break;
          case 2:
            atualizar_cadastro_aluno();
            break;
          case 3:
            excluir_cadastro_aluno();
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
            cadastrar_professor();
            break;
          case 2:
            atualizar_cadastro_professor();
            break;
          case 3:
            excluir_cadastro_professor();
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
        printf("Opção inválida. Tente novamente.\n");
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