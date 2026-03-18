#endif
#ALUNO_H

typedef struct aluno{
  char nome[100];
  char sexo[3];
  char cpf[15];
  int matricula;
}Aluno;

int cadastrar_aluno(Aluno a[], qtdAluno);
