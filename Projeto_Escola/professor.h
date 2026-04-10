#ifndef professor_h
#define professor_h

#define tam_professor 3

typedef struct professor
{
  char nome[100];
  char sexo;
  char cpf[15];
  char data_nascimento[10];
  int matricula;
} professor;

int cadastrar_professor(professor p[], int *P_ativo);
int listar_professor(professor p[], int *P_ativo);
int atualizar_professor(professor p[], int *P_ativo);
int excluir_professor(professor p[], int *P_ativo);
int validacao_cpf(char cpf[]);
int validar_data(char data[]);
int valida_matricula(professor p[], int matricula, int *P_ativo);

#endif