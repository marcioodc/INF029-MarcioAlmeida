#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "aluno.h"

int menu_principal(){
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

void menu_aluno(){
  printf("\n>>>MENU ALUNO<<<\n");
  printf("0 > Voltar\n");
  printf("1 > Cadastrar aluno\n");
  printf("2 > Atualizar cadastro do aluno\n");
  printf("3 > Excluir cadastro do aluno\n");
  scanf("%d", &op_aluno);
  return op_aluno;
}

