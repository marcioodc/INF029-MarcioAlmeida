#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "aluno.h"

int menu_principal();
int menu_aluno();
int menu_professor();
int menu_disciplina();
int menu_relatorios();

int main(void)
{
  int sair = 0;
  int ativo = 0;

  while (!sair)
  {
    int OP = menu_principal();
    switch (OP)
    {
    case 0:
    {
      printf("\n>>>Finalizando o projeto<<<\n");
      sair = 1;
      break;
    }
    // ALUNO
    case 1:
    {
      int opaluno = 0;
      while (!opaluno)
      {
        int OA = menu_aluno();
        switch (OA)
        {
        case 0:
        {
          printf("\n>>>Voltando ao menu principal<<<\n");
          opaluno = 1;
          break;
        }
        // CADASTRAR
        case 1:
        {
          printf("\nCadastramento de aluno\n");
          int R_aluno = cadastrar_aluno(a, &ativo);
          switch (R_aluno)
          {
          case 0:
          {
            printf("Aluno cadastrado com sucesso");
          }
          break;
          case 1:
          {
            printf("A lista está cheia");
          }
          break;
          case 2:
          {
            printf("Matrícula inválida ou ja existente");
          }
          break;
          case 3:
          {
            printf("sexo inválido");
          }
          break;
          case 4:
          {
            printf("CPF inválildo");
          }
          break;
          case 5:
          {
            printf("data inválida");
          }
          break;
          default:
          {
            printf("\nOpção inválida!\n");
          }
          }
        }
        break;
        // LISTAR
        case 2:
        {
        }
        break;
        // ATUALIZAR
        case 3:
        {
        }
        break;
        // EXCLUIR
        case 4:
        {
        }
        break;
        default:
        {
          printf("\nOpção inválida!\n");
        }
        break;
        }
      }
    }
    break;
    // PROFESSOR
    case 2:
    {
      int opprofessor = 0;
      while (!opprofessor)
      {
        int OP = menu_professor();
        switch (OP)
        {
        case 0:
        {
          printf("\n>>>Voltando ao menu principal<<<\n");
          opprofessor = 1;
          break;
        }
        case 1:
        {
          printf("\nCadastramento do professor\n");
          int R_professor = cadastrar_professor(p, &qtdprofessor);
          switch (R_professor)
          {
          case 0:
          {
            printf("Professor cadastrado com sucesso");
          }
          break;
          case 1:
          {
            printf("A lista está cheia");
          }
          break;
          case 2:
          {
            printf("Matrícula inválida ou já existente");
          }
          break;
          case 3:
          {
            printf("sexo inválido");
          }
          break;
          case 4:
          {
            printf("CPF inválildo");
          }
          break;
          case 5:
          {
            printf("data inválida");
          }
          break;
          default:
          {
            printf("\nOpção inválida!\n");
          }
          break;
          }
        }
        break;
        case 2:
        {
        }
        break;
        case 3:
        {
        }
        break;
        case 4:
        {
        }
        break;
        default:
        {
          printf("\nOpção inválida!\n");
        }
        break;
        }
      }
    }
    break;
    // DISCIPLINA
    case 3:
    {
      int opdisciplina = 0;
      while (!opdisciplina)
      {
        int OD = menu_disciplina();
        switch (OD)
        {
        case 0:
        {
          printf("\n>>>Voltando ao menu principal<<<\n");
          opdisciplina = 1;
          break;
        }
        case 1:
        {
        }
        break;
        case 2:
        {
        }
        break;
        case 3:
        {
        }
        break;
        case 4:
        {
        }
        break;
        default:
        {
          printf("\nOpção inválida!\n");
        }
        break;
        }
      }
    }
    break;
    // RELATÓRIOS
    case 4:
    {
      int oprelatorios = 0;
      while (!oprelatorios)
      {
        int OR = menu_relatorios();
        switch (OR)
        {
        case 0:
        {
          printf("\n>>>Voltando ao menu principal<<<\n");
          oprelatorios = 1;
          break;
        }
        case 1:
        {
        }
        break;
        case 2:
        {
        }
        break;
        case 3:
        {
        }
        break;
        case 4:
        {
        }
        break;
        case 5:
        {
        }
        break;
        case 6:
        {
        }
        break;
        case 7:
        {
        }
        break;
        case 8:
        {
        }
        break;
        case 9:
        {
        }
        break;
        case 10:
        {
        }
        break;
        case 11:
        {
        }
        break;
        case 12:
        {
        }
        break;
        case 13:
        {
        }
        break;
        case 14:
        {
        }
        break;
        default:
        {
          printf("\nOpção inválida!\n");
        }
        break;
        }
      }
    }
    break;
    default:
    {
      printf("\nOpção inválida!\n");
    }
    break;
    }
  }
}

int menu_principal()
{
  int PE;
  printf("\n>>>PROJETO ESCOLA<<<\n");
  printf("0 - Sair\n");
  printf("1 - Menu aluno\n");
  printf("2 - Menu professor\n");
  printf("3 - Menu disciplina\n");
  printf("4 - Menu relatórios\n");
  scanf("%d", &PE);
  return PE;
}

int menu_aluno()
{
  int MA;
  printf("\n>>>MENU ALUNO<<<\n");
  printf("0 - Sair\n");
  printf("1 - Cadastrar aluno\n");
  printf("2 - Listar alunos cadastrados\n");
  printf("3 - Atualizar cadastro de aluno\n");
  printf("4 - Excluir cadastro de aluno\n");
  scanf("%d", &MA);
  return MA;
}

int menu_professor()
{
  int MP;
  printf("\n>>>MENU PROFESSOR<<<\n");
  printf("0 - Sair\n");
  printf("1 - Cadastrar professor\n");
  printf("2 - Listar professores cadastrados\n");
  printf("3 - Atualizar cadastro do professor\n");
  printf("4 - Excluir cadastro do professor\n");
  scanf("%d", &MP);
  return MP;
}

int menu_disciplina()
{
  int MD;
  printf("\n>>>MENU DISCIPLINA<<<\n");
  printf("0 - Sair\n");
  printf("1 - Cadastrar disciplina\n");
  printf("2 - Listar disciplinas cadastrados\n");
  printf("3 - Atualizar disciplina\n");
  printf("4 - Excluir disciplina\n");
  scanf("%d", &MD);
  return MD;
}

int menu_relatorios()
{
}
