#include <stdio.h>
#include <stdlib.h>
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
            case 5: {
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
                        case 5:{
                            printf("\n---Voltando ao menu principal---\n");
                            sairaluno = 1;
                            break;
                        }
                        case 1:{//cadastrar
                            cadastraraluno(a, &qtdaluno);
                        }break;
                        case 2:{//listar
                            listaraluno(a, &qtdaluno);
                        }break;
                        case 3:{//atualizar
                            atualizaraluno(a, &qtdaluno);
                        }break;
                        case 4:{//excluir
                            excluiraluno(a, &qtdaluno, d, &qtdisciplina);
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
                            cadastrarprof(p, &qtdprof);
                        }break;
                        case 2:{
                            listarprof(p, &qtdprof);
                        }break;
                        case 3:{
                            atualizarprof(p, &qtdprof);
                        }break;
                        case 4:{
                            excluirprof(p, &qtdprof, d, &qtdisciplina);
                        }break;
                        default:{
                            printf("\nOpção inválida!\n");
                        }
                    }
                    
                }
                
            }break;
            case 3:{
                int sairdisciplina = 0;
                int opcaodisciplina;
                while(!sairdisciplina){
                    menu_disciplina();
                    scanf("%d", &opcaodisciplina);
                    switch(opcaodisciplina){
                        case 0:{
                            printf("\n--Voltando ao menu principal--\n");
                            sairdisciplina = 1;
                        }break;
                        case 1:{
                            cadastrardisciplina(d, &qtdisciplina, p, &qtdprof); 
                        }break;
                        case 2:{
                            listardisciplina(d, &qtdisciplina);
                        }break;
                        case 3:{
                            atualizardisciplina(d, &qtdisciplina, p, &qtdprof);
                        }break;
                        case 4:{
                            excluirdisciplina(d, &qtdisciplina);
                        }break;
                        case 5:{
                            atribuiralunodisciplina(d, &qtdisciplina, a, &qtdaluno);
                        }break;
                        case 6:{
                            excluiralunodisciplina(d, &qtdisciplina, a, &qtdaluno);
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
                    menu_relatorio();
                    scanf("%d", &opcaorelatorio);
                    switch(opcaorelatorio){
                        case 1:{
                            printf("\n---Voltando ao menu principal---\n");
                            sairrelatorio = 1;
                        }break;
                        case 2: {
                            Rlistaralunos(a, &qtdaluno);
                        }break;
                        case 3:{
                            Rlistarprofessor(p, &qtdprof);
                        }break;
                        case 4:{
                            Rlistardisciplina(d, &qtdisciplina, p, &qtdprof);
                        }break;
                        case 5:{
                            Ralunosdisciplina(a, &qtdaluno, d, &qtdisciplina, p, &qtdprof);
                        } break;
                        case 6:{
                            Rsexoalunos(a, &qtdaluno);
                        }break;
                        case 7:{
                            Rnomealunos(a, &qtdaluno);
                        }break;
                        case 8:{
                            Ralunosdatanascimento(a, &qtdaluno);
                        }break;
                        case 9:{
                            Rprofessorsexo(p, &qtdprof);
                        }break;
                        case 10:{
                            Rnomeprofessor(p, &qtdprof);
                        }break;
                        case 11:{
                            Rprofessordatanascimento(p, &qtdprof);
                        }break;
                        case 12:{
                            Raniversariantesmes(a, &qtdaluno, p, &qtdprof);
                        }break;
                        case 13:{/*
                            char busca;
                            printf("Informe o nome de quem deseja buscar: \n");
                            fgets(busca, sizeof(busca), stdin);
                            
                          */  
                            
                            
                        }break;
                        case 14:{//imprimir os alunos que estão matriculados em menos de 3 disciplinas
                            Ralunos3disciplinas(a, &qtdaluno, d, &qtdisciplina);
                        }break;
                        case 15:{//disciplinas cujas vagas são superiores a 40
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
    printf("1- Aluno\n");
    printf("2- Professor\n");
    printf("3- Disciplina\n");
    printf("4- Relatórios\n");
    printf("5- Finalizar programa\n");
}

void menu_aluno(){
    printf("\n---Aluno---\n");
    printf("1- Cadastrar aluno\n");
    printf("2- Listar aluno\n");
    printf("3- Atualizar aluno\n");                
    printf("4- Excluir aluno\n");
    printf("5- Voltar ao menu principal\n");                                
}

void menu_professor(){
    printf("\n---Professor---\n");
    printf("1- Cadastrar professor\n");
    printf("2- Listar professor\n");
    printf("3- Atualizar professor\n");
    printf("4- Excluir professor\n");
    printf("5- Voltar ao menu principal\n");
}

void menu_disciplina(){
    printf("\n---Disciplina---\n");
    printf("1- Cadastrar disciplina\n");
    printf("2- Listar disciplinas\n");
    printf("3- Atualizar disciplina\n");
    printf("4- Excluir disciplina\n");
    printf("5- Inserir aluno na disciplina\n");
    printf("6- Excluir aluno da disciplina\n");
    printf("7- Voltar ao menu principal\n");
}

void menu_relatorio(){
    printf("\n---Relatórios---\n");
    printf("1- Voltar ao menu principal\n");
    printf("2- Listar alunos\n");
    printf("3- Listar professor\n");
    printf("4- Listar disciplina\n");
    printf("5- Dados da disciplina\n");
    printf("6- Alunos ordenados por sexo\n");
    printf("7- Alunos ordenados por nome\n");
    printf("8- Alunos ordenados por data de nascimento\n");
    printf("9- Professores ordenados por sexo\n");
    printf("10- Professores ordenados por nome\n");
    printf("11- Professores ordenados por data de nascimento\n");
    printf("12- Aniversariantes do mês\n");
    printf("13- Pesquisa por nome\n");
    printf("14- Alunos matriculados em menos de 3 disciplinas\n");
    printf("15- Lista de disciplinas com mais de 40 vagas\n");
}
