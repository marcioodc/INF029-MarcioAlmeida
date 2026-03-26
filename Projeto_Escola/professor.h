#ifndef professor_h
#define professor_h
#define tam_professor 3

typedef struct professor{
  char nome[100];
  char sexo[3];
  char cpf[15];
  char data_nascimento[10];
  int matricula[6];
}professor;

int cadastrar_professor(professor p[], qtdprofessor);
int listar_professor(professor p[], int qtdprofessor);
int atualizar_professor(professor p[], int qtdprofessor);
int excluir_professor(professor p[], int qtdprofessor);
int validar_DATA(char data_nascimento);
int validar_CPF(char cpf);


#endif