#include <stdio.h>
#include <string.h>

int menu_principal();
int menu_aluno();
int menu_professor();
int menu_disciplina();
int menu_relatorios();

while(true){
  switch(PE){
case 0:{
  printf("Projeto finalizado!");
}
case 1:{


int menu_principal(){
  int PE;
  printf(">>>PROJETO ESCOLA<<<");
  printf("0 - Sair");
  printf("1 - Menu aluno");
  printf("2 - Menu professor");
  printf("3 - Menu disciplina");
  printf("4 - Menu relatórios");
  scanf("%d", &PE);
  return PE;
}

int menu_aluno(){
  int MA;
  printf(">>>MENU ALUNO<<<");
  printf("0 - Sair");
  printf("1 - Cadastrar aluno");
  printf("2 - Listar alunos cadastrados");
  printf("3 - Atualizar cadastro de aluno");
  printf("4 - Excluir cadastro de aluno");
  scanf("%d", &MA);
  return MA;
}

int menu_professor(){
  int MP;
  printf(">>>MENU PROFESSOR<<<");
  printf("0 - Sair");
  printf("1 - Cadastrar professor");
  printf("2 - Listar professores cadastrados");
  printf("3 - Atualizar cadastro do professor");
  printf("4 - Excluir cadastro do professor");
  scanf("%d", &MP);
  return MP;
}

int menu_disciplina(){
  int MD;
  printf(">>>MENU DISCIPLINA<<<");
  printf("0 - Sair");
  printf("1 - Cadastrar disciplina");
  printf("2 - Listar disciplinas cadastrados");
  printf("3 - Atualizar disciplina");
  printf("4 - Excluir disciplina");
  scanf("%d", &MD);
  return MD;
}

int menu_relatorios(){

}
