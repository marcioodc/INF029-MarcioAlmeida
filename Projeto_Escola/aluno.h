#ifndef aluno_h
#define aluno_h
#define tam_aluno 2

typedef struct aluno
{
  char nome[100];
  char sexo;
  char cpf[15];
  char data_nascimento[10];
  int matricula;
} aluno;

int cadastrar_aluno(aluno a[], int *ativo);
int listar_aluno(aluno a[], int *ativo);
int atualizar_aluno(aluno a[], int *ativo);
int excluir_aluno(aluno a[], int *ativo);
int validar_DATA(char data_nascimento);
int validar_CPF(char cpf);

#endif