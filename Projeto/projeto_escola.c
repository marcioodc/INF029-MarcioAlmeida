#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "aluno.h"
#include "professor.h"
#include "disciplina.h"
#include "relatorio.h"

void menu_principal();
void menu_aluno();
void menu_professor();
void menu_disciplina();
void menu_relatorio();

int main(void){
    aluno a[TAMALUNO];
    professor p[TAMPROFESSOR];
    disciplina d[TAMDISCIPLINA];
    int opcao;
    int sair = 0;
    int qtdaluno = 0;
    int qtdprof = 0;
    int qtdisciplina = 0;

    while(!sair){
        //Menu principal
        menu_principal();
        scanf("%d", &opcao);
        switch(opcao){
            case 0: {
                printf("\nFinalizando o programa!\n");
                sair = 1;
                break;
            }
            case 1:{
                int sairaluno = 0;
                int opcaoaluno;
                
                while(!sairaluno){
                    //Menu aluno
                    menu_aluno();
                    scanf("%d", &opcaoaluno);
                    switch(opcaoaluno){
                        case 0:{
                            printf("\n---Voltando ao menu principal---\n");
                            sairaluno = 1;
                            break;
                        }
                        case 1:{
                            int C_Resu = cadastraraluno(a, &qtdaluno);
                            switch(C_Resu){
                                case 0:{
                                    printf("\nA lista está cheia!\n");
                                }break;
                                case 1:{
printf("Já existe aluno cadastrado com essa matrícula!\n");
}break;
                                case 2:{
printf("Matrícula inválida!\n");
}break;
                                case 3:{
printf("CPF inválido!\n");
}break;
                                case 4:{
printf("Não entendi. Use apenas 'M' ou 'F'!\n");
}break;
                                case 5:{
printf("Data inválida!\n");
}break;
                                case 6:{
printf("***Aluno cadastrado com sucesso!***\n");
}break;
}
                        }break;
                        case 2:{
                            int L_Resu = listaraluno(a, &qtdaluno);
if(L_Resu == 0){
printf("Nenhum aluno cadastrado!\n");
}else{
listaraluno(a, &qtdaluno);
}
                        }break;
                        case 3:{
                            int A_Resu = atualizaraluno(a, &qtdaluno);
switch(A_Resu){
case 0:{
printf("Nenhum aluno cadastrado!\n");
}break;
case 1:{
printf("Aluno não localizado!\n");
}break;
case 2:{
printf("Não entendi. Use apenas 'M' ou 'F'!\n");
}break;
case 3:{
printf("CPF inválido!\n");
}break;
case 4:{
printf("Data inválida!\n");
}break;
case 5:{
printf("***Cadastro atualizado com sucesso!***\n");
}break;
}
                        }break;
                        case 4:{
                            int E_Resu = excluiraluno(a, &qtdaluno);
if(E_Resu == 0){
printf("Nenhum aluno cadastrado!\n");
}else if(E_Resu == 1){
printf("Aluno não localizado!\n");
}else{
printf("***Aluno excluído com sucesso!***\n");
}
                        }break;
                        default:{
                            printf("\nOpção inválida!\n");
                        }break;
                    }
                    
                }
            }break;
            case 2:{
                int sairprofessor = 0;
                int opcaoprofessor;
                
                while(!sairprofessor){
                    //Menu professor
                    menu_professor();
                    scanf("%d", &opcaoprofessor);
                    switch(opcaoprofessor){
                        case 0:{
                            printf("\n---Voltando ao menu principal---\n");
                            sairprofessor = 1;
                        }break;
                        case 1:{
                            int C_Resul = cadastrarprof(p, &qtdprof);
                            switch(C_Resul){
                                case 0:{
                                    printf("\nA lista está cheia!\n");
                                }break;
                                case 1:{
printf("Já existe professor cadastrado com essa matrícula!\n");
}break;
                                case 2:{
printf("Matrícula inválida!\n");
}break;
                                case 3:{
printf("CPF inválido!\n");
}break;
                                case 4:{
printf("Não entendi. Use apenas 'M' ou 'F'!\n");
}break;
                                case 5:{
printf("Data inválida!\n");
}break;
                                case 6:{
printf("***Professor cadastrado com sucesso!***\n");
}break;
}
                        }break;
                        case 2:{
                            int L_Resul = listarprof(p, &qtdprof);
if(L_Resul == 0){
printf("Nenhum professor cadastrado!\n");
}else{
listarprof(p, &qtdprof);
                        }break;
                        case 3:{
                            int A_Resul = atualizarprof(p, &qtdprof);
switch(A_Resul){
case 0:{
printf("Nenhum professor cadastrado!\n");
}break;
case 1:{
printf("Professor não localizado!\n");
}break;
case 2:{
printf("Não entendi. Use apenas 'M' ou 'F'!\n");
}break;
case 3:{
printf("CPF inválido!\n");
}break;
case 4:{
printf("Data inválida!\n");
}break;
case 5:{
printf("***Cadastro atualizado com sucesso!***\n");
}break;
}
                        }break;
                        case 4:{
                            int E_Resul = excluirprof(p, &qtdprof);
if(E_Resul == 0){
printf("Nenhum professor cadastrado!\n");
}else if(E_Resul == 1){
printf("Professor não localizado!\n");
}else{
printf("***Professor excluído com sucesso!***\n");
}
                        }break;
                        default:{
                            printf("\nOpção inválida!\n");
                        }break;
                    }
                    
                }
                
            }break;
            case 3:{
                int sairdisciplina = 0;
                int opcaodisciplina;
                while(!sairdisciplina){
                    //menu disciplina
                    menu_disciplina();
                    scanf("%d", &opcaodisciplina);
                    switch(opcaodisciplina){
                        case 0:{
                            printf("\n--Voltando ao menu principal--\n");
                            sairdisciplina = 1;
                        }break;
                        case 1:{
                            int C_Result = cadastrardisciplina(d, &qtdisciplina, p, &qtdprof); 
switch(C_Result){
case 0:{
printf("Limite de cadastro atingido!\n");
}break;
case 1:{
printf("Já existe disciplina cadastrada com o código informado!\n");
}break;
case 2:{
printf("O semestre deve ser superior a 0\n");
}break;
case 3:{
printf("A quantidade de vagas não pode ser inferior a 0\n");
}break;
case 4:{
printf("Professor não localizado\n");
}break;
case 5:{
printf("***Disciplina cadastrada com sucesso!***\n");
}break;
}
                        }break;
                        case 2:{
                            int L_Result = listardisciplina(d, &qtdisciplina);
if(L_Result == 0){
printf("Nenhuma disciplina cadastrada!\n");
}else{
listardisciplina(d, &qtdisciplina);
}
                        }break;
                        case 3:{
                            int A_Result = atualizardisciplina(d, &qtdisciplina, p, &qtdprof);
switch(A_Result){
case 0:{
printf("Nenhuma disciplina cadastrada!\n");
}break;
case 1:{
printf("Disciplina não encontrada!\n");
}break;
case 2:{
printf("O semestre deve ser superior a 0\n");
}break;
case 3:{
printf("A quantidade de vagas não pode ser inferior a 0!\n");
}break;
case 4:{
printf("Professor não localizado!\n");
}break;
case 5:{
printf("***Disciplina atualizada com sucesso!***\n");
}break;
}
                        }break;
                        case 4:{
                            int E_Result = excluirdisciplina(d, &qtdisciplina);
if(E_Result == 0)
printf("Nenhuma disciplina cadastrada!\n");
}else if(E_Result == 1){
printf("Disciplina não encontrada!\n");
}else{
printf("***Disciplina excluída com sucesso!***\n");
}
                        }break;
                        case 5:{
                            int AA_Result = atribuiralunodisciplina(d, &qtdisciplina, a, &qtdaluno);
switch(AA_Result){
case 0:{
printf("Nenhum aluno cadastrado!\n");
}break;
case 1:{
printf("Disciplina não encontrada!\n");
}break;
case 2:{
printf("Aluno não localizado!\n");
}break;
case 3:{
printf("***Aluno atribuído à disciplina com sucesso!***\n");
}break;
}
                        }break;
                        case 6:{
                            int EA_Result = excluiralunodisciplina(d, &qtdisciplina, a, &qtdaluno);
switch(EA_RESULT){
case 0:{
printf("Nenhum aluno cadastrado!\n");
}break;
case 1:{
printf("Disciplina não encontrada!\n");
}break;
case 2:{
printf("Aluno não localizado!\n");
}break;
case 3:{
printf("O aluno já está matriculado nesta disciplina!\n");
}break;
case 4:{
printf("***Aluno excluído da disciplina com sucesso!***\n");
}break;
case 5:{
printf("Não há vaga nesta disciplina!\n");
}break;
}
                        }break;
                        default:{
                            printf("\nOpção inválida!\n");
                        }
                    }
                }
            }break;
            case 4:{
                int opcaorelatorio;
                int sairrelatorio = 0;
                while(!sairrelatorio){
                    //menu relatório
                    menu_relatorio();
                    scanf("%d", &opcaorelatorio);
                    switch(opcaorelatorio){
                        case 0:{
                            printf("\n---Voltando ao menu principal---\n");
                            sairrelatorio = 1;
                        }break;
                        case 1: {
                            Rlistaralunos(a, &qtdaluno);
                        }break;
                        case 2:{
                            Rlistarprofessor(p, &qtdprof);
                        }break;
                        case 3:{
                            Rlistardisciplina(d, &qtdisciplina, p, &qtdprof);
                        }break;
                        case 4:{
                            Ralunosdisciplina(a, &qtdaluno, d, &qtdisciplina, p, &qtdprof);
                        } break;
                        case 5:{
                            Rsexoalunos(a, &qtdaluno);
                        }break;
                        case 6:{
                            Rnomealunos(a, &qtdaluno);
                        }break;
                        case 7:{
                            Ralunosdatanascimento(a, &qtdaluno);
                        }break;
                        case 8:{
                            Rprofessorsexo(p, &qtdprof);
                        }break;
                        case 9:{
                            Rnomeprofessor(p, &qtdprof);
                        }break;
                        case 10:{
                            Rprofessordatanascimento(p, &qtdprof);
                        }break;
                        case 11:{
                            Raniversariantesmes(a, &qtdaluno, p, &qtdprof);
                        }break;
                        case 12:{
                            Rbuscarnome(a, &qtdaluno, p, &qtdprof);
                        }break;
                        case 13:{
                            Ralunos3disciplinas(a, &qtdaluno, d, &qtdisciplina);
                        }break;
                        case 14:{
                            Rdisciplinas40(d, &qtdisciplina, p, &qtdprof);
                        }break;
                        default:{
                            printf("\nOpção inválida!\n");
                        }break;
                    }
                }break;
            }
            default:{
                printf("\nOpção inválida!\n");
            }break;
        }
        
    }
    return 0;
}

void menu_principal(){
    printf("\n---Projeto Escola---\n");
    printf("\nEscolha uma opção:\n");
    printf("0- Finalizar programa\n");
    printf("1- Aluno\n");
    printf("2- Professor\n");
    printf("3- Disciplina\n");
    printf("4- Relatórios\n");
}

void menu_aluno(){
    printf("\n---Aluno---\n");
    printf("0- Voltar ao menu principal\n");
    printf("1- Cadastrar aluno\n");
    printf("2- Listar aluno\n");
    printf("3- Atualizar aluno\n");                
    printf("4- Excluir aluno\n");                              
}

void menu_professor(){
    printf("\n---Professor---\n");
    printf("0- Voltar ao menu principal\n");
    printf("1- Cadastrar professor\n");
    printf("2- Listar professor\n");
    printf("3- Atualizar professor\n");
    printf("4- Excluir professor\n");
}

void menu_disciplina(){
    printf("\n---Disciplina---\n");
    printf("0- Voltar ao menu principal\n");
    printf("1- Cadastrar disciplina\n");
    printf("2- Listar disciplinas\n");
    printf("3- Atualizar disciplina\n");
    printf("4- Excluir disciplina\n");
    printf("5- Inserir aluno na disciplina\n");
    printf("6- Excluir aluno da disciplina\n");
}

void menu_relatorio(){
    printf("\n---Relatórios---\n");
    printf("0- Voltar ao menu principal\n");
    printf("1- Listar alunos\n");
    printf("2- Listar professor\n");
    printf("3- Listar disciplina\n");
    printf("4- Dados da disciplina\n");
    printf("5- Alunos ordenados por sexo\n");
    printf("6- Alunos ordenados por nome\n");
    printf("7- Alunos ordenados por data de nascimento\n");
    printf("8- Professores ordenados por sexo\n");
    printf("9- Professores ordenados por nome\n");
    printf("10- Professores ordenados por data de nascimento\n");
    printf("11- Aniversariantes do mês\n");
    printf("12- Pesquisa por nome\n");
    printf("13- Alunos matriculados em menos de 3 disciplinas\n");
    printf("14- Lista de disciplinas com mais de 40 vagas\n");
}
