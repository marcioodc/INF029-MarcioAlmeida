#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "relatorio.h"
#include "aluno.h"
#include "professor.h"
#include "disciplina.h"

void Rlistaralunos(aluno a[], int *qtdaluno){
        //listando os alunos
    if(*qtdaluno == 0){
        printf("\nNão há alunos cadastrados!\n");
        return;
    }else{
        printf("\n--Listando os alunos--\n");
        for(int i=0; i < *qtdaluno; i++){
            if(a[i].ativo == 1){
                printf("%d - %s (%d)\n", i+1, a[i].nome, a[i].matricula);
            }
        }
        return;
    }                   
}

void Rlistarprofessor(professor p[], int *qtdprof){
        //listando professores
    if(*qtdprof == 0){
        printf("Não há professores cadastrados!\n");
        return;
    }else{
        printf("\n--Listando os professores--");
        printf("\nN° | Nome | Matrícula\n");
        for(int i=0; i < *qtdprof; i++){
            if(p[i].ativo == 1){
                printf("%d |  %s  | %d\n", i+1, p[i].nome, p[i].matricula);
            }
        }
        return;
    }
}

void Rlistardisciplina(disciplina d[], int *qtdisciplina, professor p[], int *qtdprof){
            //Listando disciplina
    if(*qtdisciplina == 0){
        printf("\nNão há disciplinas cadastradas!\n");
        return;
    }else{
        printf("\nN° | Disciplina | Código\n");
        for(int i=0; i < *qtdisciplina; i++){
            if(d[i].ativo == 1){
                printf("%d |  %s  | %s\n", i+1, d[i].nome, d[i].codigo);
                int posprofessor = posprof(p, *qtdprof, d[i].disprof);
                if(posprofessor != -1){
                    printf("Semestre: %d | Prof° responsável: %s\n", d[i].semestre, p[posprofessor].nome);
                }
            }
        }
    }
}

void Ralunosdisciplina(aluno a[], int *qtdaluno, disciplina d[], int *qtdisciplina, professor p[], int *qtdprof){
            // Listar disciplina com alunos matriculados
    if(*qtdisciplina == 0){
        printf("\nNão há disciplina cadastrada!\n");
        return;
    }else{
        for(int i=0; i< *qtdisciplina; i++){
            if(d[i].ativo == 1){
                printf("\nDisciplina: %s | Código: %s ", d[i].nome, d[i].codigo);
                int posprofessor = posprof(p, *qtdprof, d[i].disprof);
                if(posprofessor != -1){
                    printf("Professor responsável: %s\n", p[posprofessor].nome);
                }
                printf("Alunos matriculados:\n");
                int temaluno = 0;
                for(int j=0; j<TAMALUNO; j++){
                    if(d[i].alunomatriculado[j] != 0){
                        int posal = posaluno(a, *qtdaluno, d[i].alunomatriculado[j]);
                        if(posal != -1){
                            printf("- %s (Matrícula: %d)\n", a[posal].nome, a[posal].matricula);
                            temaluno = 1;
                        }
                    }
                }
                if(!temaluno){
                    printf("Nenhum aluno matriculado nesta disciplina!\n\n");
                }
            }
        }
    }
    return;
}

void Rsexoalunos(aluno a[], int *qtdaluno){
        //alunos listados por sexo
    int masc = 0;
    int fem = 0;
    if(*qtdaluno == 0){
        printf("\nNão há alunos cadastrados!\n");
        return;
    }else{
        printf("\n--Masculino--\n");
        for(int i=0; i< *qtdaluno; i++){
            if(a[i].sexo == 'M' || a[i].sexo == 'm'){
                printf("%s | %c\n", a[i].nome, a[i].sexo);
                masc++;
            }
        }   
        if(masc == 0){
            printf("\nNão há aluno masculino matriculado!\n");  
        }
        printf("\n--Feminino--\n");
        for(int j=0; j< *qtdaluno; j++){
            if(a[j].sexo == 'F' || a[j].sexo == 'f'){
                printf("%s | %c\n", a[j].nome, a[j].sexo);
                fem++;
            }
        }
        if(fem == 0){
            printf("\nNão há aluna femino matriculada!\n");
            }
        return;
    }
}

void Rnomealunos(aluno a[], int *qtdaluno){
    //alunos por ordem alfabética
    if(*qtdaluno == 0){
        printf("\nNenhum aluno cadastrado!\n");
        return;
    }else{
        for(int i=0; i< *qtdaluno-1; i++){
            for(int j=i+1; j< *qtdaluno; j++){
                if(strcmp(a[i].nome, a[j].nome) > 0){
                    aluno temp = a[i];
                    a[i] = a[j];
                    a[j] = temp;
                }
            }
        }
        printf("\n---Alunos---\n");
        for(int i=0; i< *qtdaluno; i++){
            printf("%s - %d", a[i].nome, a[i].matricula);
        }
        return;
    }
}

void Ralunosdatanascimento(aluno a[], int *qtdaluno){
    //alunos ordenados por data de nascimento
    if(*qtdaluno == 0){
        printf("\nNenhum aluno cadastrado!\n");
        return;
    }else{
        for(int i=0; i< *qtdaluno-1; i++){
            for(int j=i+1; j< *qtdaluno; j++){
                if(Acomparadata(a[i], a[j])){
                    aluno temp = a[i];
                    a[i] = a[j];
                    a[j] = temp;
                }
            }
        }
        for(int i=0; i< *qtdaluno; i++){
            printf("%02d/%02d/%04d  -  %s\n", a[i].dia, a[i].mes, a[i].ano, a[i].nome);
        }
        return;
    }
}

void Rprofessorsexo(professor p[], int *qtdprof){
    //professor ordenadas pelo sexo
    if(*qtdprof == 0){
        printf("\nNão há professores cadastrados!\n");
        return;
    }else{
        printf("\n--Masculino--\n");
        for(int i=0; i< *qtdprof; i++){
            if(p[i].sexo == 'M' || p[i].sexo == 'm'){
                printf("%s | %c\n", p[i].nome, p[i].sexo);
            }
        }
        printf("\n--Feminino--\n");
        for(int j=0; j< *qtdprof; j++){
            if(p[j].sexo == 'F' || p[j].sexo == 'f'){
                printf("%s | %c\n", p[j].nome, p[j].sexo);
            }
        }
        return;
    }
}

void Rnomeprofessor(professor p[], int *qtdprof){
        //professores ordenados pelo nome
    if(*qtdprof == 0){
        printf("\nNenhum professor cadastrado!\n");
        return;
    }else{
        for(int i=0; i< *qtdprof-1; i++){
            for(int j=i+1; j< *qtdprof; j++){
                if(strcmp(p[i].nome, p[j].nome) > 0){
                    professor temp = p[i];
                    p[i] = p[j];
                    p[j] = temp;
                }
            }
        }
        printf("\n---Professores---\n");
        for(int i=0; i< *qtdprof; i++){
            printf("%s - %d\n", p[i].nome, p[i].matricula);
        }
        return;
    }
}

void Rprofessordatanascimento(professor p[], int *qtdprof){
        //professores ordenados pela data de nascimento 
    if(*qtdprof == 0){
        printf("\nNenhum professor cadastrado!\n");
        return;
    }else{
        for(int i=0; i< *qtdprof-1; i++){
            for(int j=i+1; j< *qtdprof; j++){
                if(Pcomparadata(p[i], p[j])){
                    professor temp = p[i];
                    p[i] = p[j];
                    p[j] = temp;
                }
            }
        }
        for(int i=0; i< *qtdprof; i++){
            printf("%02d/%02d/%04d  -  %s\n", p[i].dia, p[i].mes, p[i].ano, p[i].nome);
        }
        return;
    }
}

void Raniversariantesmes(aluno a[], int *qtdaluno, professor p[], int *qtdprof){
        //aniversariantes do mês    
        if(*qtdaluno == 0 || *qtdprof == 0){
        printf("\nNão há dados cadastrados!\n");
        return;
    }else{
        int mes = -1;
        while(mes != 0){
            printf("Selecione o mês: \n");
            printf("0- Voltar ao menu Relatórios\n");
            printf("1- Janeiro   | 7- Julho\n2- Fevereiro | 8- Agosto\n3- Março     | 9- Setembro\n");
            printf("4- Abril     | 10- Outubro\n5- Maio      | 11- Novembro\n6- Junho     | 12- Dezembro\n");
            scanf("%d", &mes);
            if(mes >= 1 && mes <= 12){
                meses(a, *qtdaluno, p, *qtdprof, mes);
            }else{
                printf("\nMês inválido!\n");
                
            }
        }
        return;
    }
}
void Rbuscarnome(aluno a[], int *qtdaluno, professor p[], int *qtdprof){
    if(*qtdaluno && *qtdprof == 0){
        printf("Não há dados cadastrados!\n");
        return;
    }else{
        char busca[50];
        printf("Informe o nome que deseja buscar: ");
        fgets(busca, sizeof(busca), stdin);
        busca[strcspn(busca, "\n")] = '\0';
        for(int i=0; i < *qtdaluno; i++){
            if(strcmp(a[i].nome, busca) == 0){
                printf("%s\n", a[i].nome);
            }else{
                printf("Aluno não localizado!\n");
            }
        }
        for(int j=0; j < *qtdaluno; j++){
            if(strcmp(p[j].nome, busca) == 0){
                printf("%s\n", p[j].nome);
            }else{
                printf("Professor não localizado!\n");
            }
        }
        return;
    }
}

void Ralunos3disciplinas(aluno a[], int *qtdaluno, disciplina d[], int *qtdisciplina){
        //alunos cadastrados -3 disciplinas
    if(*qtdaluno == 0){
        printf("\nNenhum aluno cadastrado!\n");
        return; 
    }else if(*qtdisciplina == 0){
        printf("\nNenhuma disciplina cadastrada!\n");
        return;
    }else{
        printf("\nAlunos matriculados em menos de 3 disciplinas: \n");
        for(int i=0; i< *qtdaluno; i++){
            if(a[i].ativo == 1){
                int icont = 0;
                for(int j=0; j< *qtdisciplina; j++){
                    for(int k=0; k<TAMALUNO; k++){
                        if(d[j].alunomatriculado[k] == a[i].matricula){
                            icont++;
                        }
                    }
                }
                if(icont < 3){
                    printf("Nome: %s | Matrícula: %d", a[i].nome, a[i].matricula);
                }
            }
        }
        return;
    }
}

void Rdisciplinas40(disciplina d[], int *qtdisciplina, professor p[], int *qtdprof){
    if(*qtdisciplina == 0){
        printf("\nNenhuma disciplina cadastrada!\n");
        return;
    }else{
        int encontrou = 0;
        printf("\nDisciplinas com mais de 40 vagas:\n");
        for(int i = 0; i < *qtdisciplina; i++){
            if(d[i].ativo && d[i].qtdvagas > 40){
                printf("N°%d | %s | Código: %s | Vagas: %d\n", i+1, d[i].nome, d[i].codigo, d[i].qtdvagas);
                int posprofessor = posprof(p, *qtdprof, d[i].disprof);
                if(posprofessor != -1){
                    printf("Professor responsável: %s\n", p[posprofessor].nome);
                }  
                encontrou = 1;
            }
        }
        if(!encontrou){ 
            printf("\nNão há disciplinas com mais de 40 vagas!\n");
        }
        return;
    }
}

int Acomparadata(aluno i, aluno j) {
    return (i.ano > j.ano) ||
           (i.ano == j.ano && i.mes > j.mes) ||
           (i.ano == j.ano && i.mes == j.mes && i.dia > j.dia);
}

int Pcomparadata(professor i, professor j) {
    return (i.ano > j.ano) ||
           (i.ano == j.ano && i.mes > j.mes) ||
           (i.ano == j.ano && i.mes == j.mes && i.dia > j.dia);
}

void meses(aluno a[], int qtdaluno, professor p[], int qtdprof, int mes){
    int cont = 0;
    for(int i=0; i<qtdaluno; i++){
        if(a[i].ativo && a[i].mes == mes){
            printf("Aluno: %s\n", a[i].nome);
            printf("Matrícula: %d\n", a[i].matricula);
            printf("Data de nascimento: %02d/%02d/%04d\n", a[i].dia, a[i].mes, a[i].ano);
            cont++;
        }
    }
    for(int j=0; j<qtdprof; j++){
        if(p[j].ativo && p[j].mes == mes){
            printf("Professor: %s\n", p[j].nome);
            printf("Matrícula: %d\n", p[j].matricula);
            printf("Data de nascimento: %02d/%02d/%04d\n", p[j].dia, p[j].mes, p[j].ano);
            cont++;
        }
    }
    if(cont == 0){
        printf("\nNão há aniversariantes neste mês!\n");
    }
}
