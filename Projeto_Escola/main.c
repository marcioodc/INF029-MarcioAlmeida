#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "aluno.h"
#include "professor.h"
#include "disciplina.h"

int menu_principal();
int menu_aluno();
int menu_professor();
int menu_disciplina();
int menu_relatorios();

int main(void)
{
  aluno a[tam_aluno];
  professor p[tam_professor];
  disciplina d[QTDISCIPLINA];
  int P_ativo = 0;
  int D_ativa = 0;
  int A_ativo = 0;
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
          int A_Cadastro = cadastrar_aluno(a, &ativo);
          switch (A_Cadastro)
          {
          case 0:
          {
            printf("\nAluno cadastrado com sucesso!");
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
          if (listar_aluno(a, &ativo) == 1)
          {
            printf("\n>>>Não ha alunos cadastrados!<<<\n");
          }
        }
        break;
        // ATUALIZAR
        case 3:
        {
          printf("Atualizar cadastro de aluno\n");
          int A_Atualizar = atualizar_aluno(a, &ativo);
          switch (A_Atualizar)
          {
          case 0:
            printf("\nCadastro atualizado com sucesso!\n");
            break;
          case 1:
            printf("\n>>>Não ha alunos cadastrados!<<<\n");
            break;
          case 2:
            printf("\n>>>Matrícula não encontrada!<<<\n");
            break;
          case 3:
            printf("\n>>>Sexo inválido!<<<\n");
            break;
          case 4:
            printf("\n>>>CPF inválido!<<<\n");
            break;
          case 5:
            printf("\n>>>Data de nascimento inválida!<<<\n");
            break;
          default:
            printf("\nOpção inválida!\n");
            break;
          }
        }
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
          int R_professor = cadastrar_professor(p, &P_ativo);
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
          if (listar_professor(p, &P_ativo) == 1)
          {
            printf("\n>>>Não ha professores cadastrados!<<<\n");
          }
          break;
        case 3:
        {
          printf("Atualizar cadastro do professor\n");
          int P_Atualizar = atualizar_professor(p, &P_ativo);
          switch (P_Atualizar)
          {
          case 0:
            printf("\nCadastro atualizado com sucesso!\n");
            break;
          case 1:
            printf("\n>>>Não ha professores cadastrados!<<<\n");
            break;
          case 2:
            printf("\n>>>Matrícula não encontrada!<<<\n");
            break;
          case 3:
            printf("\n>>>Sexo inválido!<<<\n");
            break;
          case 4:
            printf("\n>>>CPF inválido!<<<\n");
            break;
          case 5:
            printf("\n>>>Data de nascimento inválida!<<<\n");
            break;
          default:
            printf("\nOpção inválida!\n");
            break;
          }
        }
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
          printf("\nCadastramento de disciplina!\n");
          int D_cadastrar = cadastrar_disciplina(d, &D_ativa, p, &P_ativo);
          switch (D_cadastrar)
          {
          case 0:
            printf("\nDisciplina cadastrada com sucesso!\n");
            break;
          case 1:
            printf("\n>>>Não ha professores cadastrados!<<<\n");
            break;
          case 2:
            printf("\nLimite de disciplinas cadastradas alcançado!\n");
            break;
          case 3:
            printf("\nSemestre inválido!\n");
            break;
          case 4:
            printf("\nProfessor não encontrado!\n");
            break;
          case 5:
            printf("\nQuantidade de vagas inválida!\n");
            break;
          default:
            printf("\nOpção inválida!\n");
            break;
          }
        }
        break;
        case 2:
        {
          if (listar_disciplina(d, &D_ativa, p, &P_ativo) == 1)
          {
            printf("\n>>>Não ha disciplinas cadastradas!<<<\n");
          }
        }
        break;
        case 3:
        {
          printf("\nAtualizar dados da disciplina!\n");
          int D_atualizar = atualizar_disciplina(d, &D_ativa, p, &P_ativo);
          switch (D_atualizar)
          {
          case 0:
            printf("\nDisciplina atualizada com sucesso!\n");
            break;
          case 1:
            printf("\nLimite de disciplinas cadastradas alcançado!\n");
            break;
          case 2:
            printf("\nCódigo inválido!\n");
            break;
          case 3:
            printf("\nSemestre inválido!\n");
            break;
          case 4:
            printf("\nProfessor não encontrado!\n");
            break;
          case 5:
            printf("\nQuantidade de vagas inválida!\n");
            break;
          default:
            printf("\nOpção inválida!\n");
            break;
          }
        }
        break;
        case 4:
        {
        }
        break;
        case 5:
        {
          printf("\nMatricular aluno na disciplina!\n");
          int D_A_matricular = matricular_aluno_disciplina(d, &D_ativa, a, &A_ativo);
          switch (D_A_matricular)
          {
          case 0:
            printf("\nAluno matriculado com sucesso!\n");
            break;
          case 1:
            printf("\nNão ha disciplinas cadastradas!\n");
            break;
          case 2:
            printf("\nNão ha alunos cadastrados!\n");
            break;
          case 3:
            printf("\nDisciplina sem vagas disponíveis!\n");
            break;
          case 4:
            printf("\nCódigo da matrícula não encontrado!\n");
            break;
          case 5:
            printf("\nMatrícula do aluno não encontrada!\n");
            break;
          default:
            printf("\nOpção inválida!\n");
            break;
          }
        }
        break;
        case 6:
        {
        }
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
