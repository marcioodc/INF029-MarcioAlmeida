#ifndef aluno_h
#define aluno_h
#define tam_aluno 3

typedef struct aluno{
  char nome[100];
  char sexo[3];
  char cpf[15];
  char data_nascimento[10];
  int matricula[6];
}aluno;

int cadastrar_aluno(aluno a[], qtdaluno);
int listar_aluno(aluno a[], int qtdaluno);
int atualizar_aluno(aluno a[], int qtdaluno);
int excluir_aluno(aluno a[], int qtdaluno);
int validar_DATA(char data_nascimento);
int validar_CPF(char cpf);

#endif