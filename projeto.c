#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define TAMALUNO 2
#define TAMPROFESSOR 2
#define TAMDISCIPLINA 2

typedef struct aluno {
    int matricula;
    char nome[50];
    char sexo;
    int dia, mes, ano; //data nascimento 
    char cpf[15];
    int ativo;
} aluno;

typedef struct professor {
    int matricula;
    char nome[50];
    char sexo;
    int dia, mes, ano; //data nascimento
    char cpf[15];
    int ativo;
} professor;

typedef struct disciplina {
    char nome[50];
    char codigo[10];
    int semestre;
    int disprof;
    int ativo;
    int alunomatriculado[TAMALUNO]; 
    char codis[10];
    
} disciplina;
//valindando a data
int validaData(int dia, int mes, int ano) {
    int resultado;
    if (ano < 1 || mes < 1 || mes > 12 || dia < 1) return 0;

    int diasMes[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (mes == 2 && ((ano % 4 == 0 && ano % 100 != 0) || ano % 400 == 0)) {
        diasMes[2] = 29; // fevereiro em ano bissexto
    }

    return (dia <= diasMes[mes]) ? 1 : 0;
}
//Descobrindo a posição do aluno
int posaluno(aluno a[], int qtdaluno, int matricula){
    int i;
    for(i = 0; i < qtdaluno; i++){
        if(a[i].matricula == matricula){
            return i;
        }
    }
    return -1;
}
int posdisc(disciplina d[], int qtdisciplina, char codigo[]){
    int i;
    for(i=0; i<qtdisciplina; i++){
        if(strcmp(d[i].codigo, codigo) == 0){
            return i;
        }
    }
    return -1;
}

int posprof(professor p[], int qtdprof, int matricula){
    int i;
    for(i=0; i<qtdprof; i++){
        if(p[i].matricula == matricula){
            return i;
        }
    }
    return -1;
}


int main(void){
    aluno a[TAMALUNO];
    professor p[TAMPROFESSOR];
    disciplina d[TAMDISCIPLINA];
    int opcao;
    int sair = 0;
    int qtdaluno = 0;
    int qtdprof = 0;
    int qtdisciplina = 0;
    int qtdalunomatriculado = 0;
    
    while(!sair){
        //Menu principal
        printf("\n---Projeto Escola---\n");
        printf("Escolha uma opção:\n");
        printf("1- Aluno\n");
        printf("2- Professor\n");
        printf("3- Disciplina\n");
        printf("4- Relatórios\n");
        printf("5- Finalizar programa\n");
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
                    printf("\n---Aluno---\n");
                    printf("1- Cadastrar aluno\n");
                    printf("2- Listar aluno\n");
                    printf("3- Atualizar aluno\n");
                    printf("4- Excluir aluno\n");
                    printf("5- Voltar ao menu principal\n");
                    scanf("%d", &opcaoaluno);
                    switch(opcaoaluno){
                        case 5:{
                            sairaluno = 1;
                            break;
                        }
                        case 1:{
                            int matricula;
                            if(qtdaluno == TAMALUNO){
                                printf("A lista está cheia\n");
                            }else{
                                printf("Cadastrando aluno\n");
                                printf("--Informações do aluno--\n");
                                printf("Matricula: ");
                                scanf("%d", &matricula);
                                if(matricula < 0){
                                    printf("\nMatricula inválida\n");
                                    break;
                                }else{
                                    a[qtdaluno].matricula = matricula;
                                    //Nome do aluno
                                    getchar();
                                    printf("Nome: ");
                                    fgets(a[qtdaluno].nome, sizeof(a[qtdaluno].nome), stdin);
                                    a[qtdaluno].nome[strcspn(a[qtdaluno].nome, "\n")] = '\0';
                                    //Sexo do aluno
                                    printf("Sexo: 'F' ou 'M': ");
                                    scanf(" %c", &a[qtdaluno].sexo);
                                    a[qtdaluno].sexo = toupper(a[qtdaluno].sexo);
                                    if(a[qtdaluno].sexo != 'F' && a[qtdaluno].sexo != 'M'){
                                        printf("\nNão entendi! Use apenas 'M' ou 'F'\n");
                                        break;
                                    }
                                    //CPF do aluno
                                    printf("CPF: ");
                                    scanf(" %14[^\n]", a[qtdaluno].cpf);
                                    
                                    //Data de nascimento do aluno
                                    int res;
                                    printf("Data de nascimento 'dd/mm/aaaa': ");
                                    scanf("%d/%d/%d", &a[qtdaluno].dia, &a[qtdaluno].mes, &a[qtdaluno].ano);
                                    res= validaData(a[qtdaluno].dia, a[qtdaluno].mes, a[qtdaluno].ano);
                                    if(res == 0){
                                        printf("Data inválida!\n");
                                        break;
                                    }
                                    
                                    a[qtdaluno].ativo = 1;
                                    qtdaluno++;
                                 
                                printf("---Cadastro realizado com sucesso---\n");
                                }
                            }
                        }break;
                        case 2:{
                            if(qtdaluno == 0){
                                printf("A lista está vazia\n");
                            }else{
                                printf("Listando os alunos\n");
                                for(int i=0; i < qtdaluno; i++){
                                    if(a[i].ativo == 1){
                                        printf("--Aluno %d--\n ", i+ 1);
                                        printf("Matricula: %d  |  Nome: %s\n", a[i].matricula, a[i].nome);
                                        printf("Sexo: %c  |  Data de Nascimento: %d/%d/%d\n", a[i].sexo, a[i].dia, a[i].mes, a[i].ano);
                                        printf("CPF: %s\n", a[i].cpf);
                                        
                                    }
                                }
                            }
                            
                        }break;
                        case 3:{
                            int atualizarM;
                            if(qtdaluno == 0){
                                printf("\nNenhum aluno cadastrado\n");
                                break;
                            }
                            printf("Informe a matricula do aluno que você deseja atualizar: ");
                            scanf("%d", &atualizarM);
                            int posicao = posaluno(a, qtdaluno, atualizarM);
                            
                            if(posicao == -1){
                                printf("Aluno não encontrado!\n");
                            }else{
                                aluno novoaluno;
                                getchar();
                                //Nome do novo aluno
                                printf("\nNome: ");
                                fgets(novoaluno.nome, sizeof(novoaluno.nome), stdin);
                                novoaluno.nome[strcspn(novoaluno.nome, "\n")] = '\0';
                                
                                //Sexo do novo aluno
                                printf("Sexo: 'F' ou 'M': ");
                                scanf(" %c", &novoaluno.sexo);
                                novoaluno.sexo = toupper(novoaluno.sexo);
                                if(novoaluno.sexo != 'F' && novoaluno.sexo != 'M'){
                                    printf("Não entendi! Use apenas 'M' ou 'F'\n");
                                    break;
                                }
                                //CPF do novo aluno 
                                printf("CPF: ");
                                scanf(" %14[^\n]", novoaluno.cpf);
                                  
                                //Data de nascimento do novo aluno
                                int res;
                                printf("Data de nascimento: 'dd/mm/aaaa': ");
                                scanf("%d/%d/%d", &novoaluno.dia, &novoaluno.mes, &novoaluno.ano);
                                res= validaData(novoaluno.dia, novoaluno.mes, novoaluno.ano);
                                if(res == 0){
                                    printf("Data inválida!\n");
                                    break;
                                }
                                novoaluno.ativo = a[posicao].ativo;
                                novoaluno.matricula = a[posicao].matricula;
                                a[posicao] = novoaluno;
                                printf("\nCadastro atualizado com sucesso\n");
                            }
                            
                        }break;
                        case 4:{
                            int excluir;
                            if(qtdaluno == 0){
                                printf("\nNenhum aluno cadastrado\n");
                                break;
                            }
                            printf("Digite a matricula do aluno que deseja excluir: ");
                            scanf("%d", &excluir);
                            int posexcluir = posaluno(a, qtdaluno, excluir);
                            if(posexcluir == -1){
                                printf("Matricula não encontrada\n");
                                
                            }else{
                                for(int i = posexcluir; i < qtdaluno - 1; i++){
                                    a[i] = a[i+1];
                                }
                                qtdaluno--;
                                printf("--Aluno excluído com sucesso--\n");
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
                    printf("\n---Professor---\n");
                    printf("1- Cadastrar professor\n");
                    printf("2- Listar professor\n");
                    printf("3- Atualizar professor\n");
                    printf("4- Excluir professor\n");
                    printf("5- Voltar ao menu principal\n");
                    scanf("%d", &opcaoprofessor);
                    switch(opcaoprofessor){
                        case 5:{
                            sairprofessor = 1;
                            break;
                        }break;
                        case 1:{
                            int matricula;
                            if(qtdprof == TAMPROFESSOR){
                                printf("A lista está cheia\n");
                                
                            }else{
                                printf("Cadastrando professor\n");
                                printf("--Informações do professor--\n");
                                printf("Matricula: ");
                                scanf("%d", &matricula);
                                if(matricula < 0){
                                    printf("\nMatricula inválida\n");
                                    break;
                                }else{
                                    p[qtdprof].matricula = matricula;
                                    //Nome do professor
                                    getchar();
                                    printf("Nome: ");
                                    fgets(p[qtdprof].nome, sizeof(p[qtdprof].nome), stdin);
                                    p[qtdprof].nome[strcspn(p[qtdprof].nome, "\n")] = '\0';
                                    //Sexo do professor
                                    printf("Sexo: 'F' ou 'M': ");
                                    scanf(" %c", &p[qtdprof].sexo);
                                    p[qtdprof].sexo = toupper(p[qtdprof].sexo);
                                    if(p[qtdprof].sexo != 'F' && p[qtdprof].sexo != 'M'){
                                        printf("\nNão entendi! Use apenas 'M' ou 'F'\n");
                                        break;
                                    }
                                    //CPF do professor
                                    printf("CPF: ");
                                    scanf(" %14[^\n]", p[qtdprof].cpf);
                                    
                                    //Data de nascimento do professor
                                    int res;
                                    printf("Data de nascimento 'dd/mm/aaaa': ");
                                    scanf("%d/%d/%d", &p[qtdprof].dia, &p[qtdprof].mes, &p[qtdprof].ano);
                                    res= validaData(p[qtdprof].dia, p[qtdprof].mes, p[qtdprof].ano);
                                    if(res == 0){
                                        printf("Data inválida!\n");
                                        break;
                                    }
                                    
                                    p[qtdprof].ativo = 1;
                                    qtdprof++;
                                 
                                    printf("---Cadastro realizado com sucesso---\n");
                                }
                                    
                            }
                            
                        }break;
                        case 2:{
                            if(qtdprof == 0){
                                printf("A lista está vazia\n");
                            }else{
                                printf("Listando os professores\n");
                                for(int i=0; i < qtdprof; i++){
                                    if(p[i].ativo == 1){
                                        printf("--Professor %d--\n ", i+ 1);
                                        printf("Matricula: %d  |  Nome: %s\n", p[i].matricula, p[i].nome);
                                        printf("Sexo: %c  |  Data de Nascimento: %d/%d/%d\n", p[i].sexo, p[i].dia, p[i].mes, p[i].ano);
                                        printf("CPF: %s\n", p[i].cpf);
                                        
                                    }
                                }
                            }
                            
                        }break;
                        case 3:{
                            int atualizarM;
                            if(qtdprof == 0){
                                printf("\nNenhum professor cadastrado\n");
                                break;
                            }
                            printf("Informe a matricula do professor que você deseja atualizar: ");
                            scanf("%d", &atualizarM);
                            int posicao = posprof(p, qtdprof, atualizarM);
                            
                            if(posicao == -1){
                                printf("\nProfessor não encontrado!\n");
                            }else{
                                professor novoprof;
                                getchar();
                                //Nome do novo professor
                                printf("\nNome: ");
                                fgets(novoprof.nome, sizeof(novoprof.nome), stdin);
                                novoprof.nome[strcspn(novoprof.nome, "\n")] = '\0';
                                
                                //Sexo do novo professor
                                printf("Sexo: 'F' ou 'M': ");
                                scanf(" %c", &novoprof.sexo);
                                novoprof.sexo = toupper(novoprof.sexo);
                                if(novoprof.sexo != 'F' && novoprof.sexo != 'M'){
                                    printf("Não entendi! Use apenas 'M' ou 'F'\n");
                                    break;
                                }
                                //CPF do novo professor 
                                printf("CPF: ");
                                scanf(" %14[^\n]", novoprof.cpf);
                                    
                                //Data de nascimento do novo professor
                                int res;
                                printf("Data de nascimento: 'dd/mm/aaaa': ");
                                scanf("%d/%d/%d", &novoprof.dia, &novoprof.mes, &novoprof.ano);
                                res= validaData(novoprof.dia, novoprof.mes, novoprof.ano);
                                if(res == 0){
                                    printf("Data inválida!\n");
                                    break;
                                }
                                novoprof.ativo = p[posicao].ativo;
                                novoprof.matricula = p[posicao].matricula;
                                p[posicao] = novoprof;
                                printf("\nCadastro atualizado com sucesso\n");
                            }
                            
                        }break;
                        case 4:{
                            int excluir;
                            if(qtdprof == 0){
                                printf("\nNenhum professor cadastrado\n");
                                break;
                            }
                            printf("Digite a matricula do professor que deseja excluir: ");
                            scanf("%d", &excluir);
                            int posexcluir = posprof(p, qtdprof, excluir);
                            if(posexcluir == -1){
                                printf("Matricula não encontrada\n");
                                
                            }else{
                                for(int i = posexcluir; i < qtdprof - 1; i++){
                                    p[i] = p[i+1];
                                }
                                qtdprof--;
                                printf("--Professor excluído com sucesso--\n");
                            }
                            
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
                    printf("\n---Disciplina---\n");
                    printf("1- Cadastrar disciplina\n");
                    printf("2- Listar disciplinas\n");
                    printf("3- Atualizar disciplina\n");
                    printf("4- Excluir disciplina\n");
                    printf("5- Inserir aluno na disciplina\n");
                    printf("6- Excluir aluno da disciplina\n");
                    printf("7- Voltar ao menu principal\n");
                    scanf("%d", &opcaodisciplina);
                    switch(opcaodisciplina){
                        case 7:{
                            sairdisciplina = 1;
                            break;
                        }break;
                        case 1:{
                            char codigo[10];
                            if(qtdisciplina == TAMDISCIPLINA){
                                printf("A lista está cheia\n");
                                break;
                            }else{
                                printf("Cadastrando disciplina\n");
                                printf("--Informações da disciplina--\n");
                                printf("Código: ");
                                scanf("%9s", codigo);
                                strcpy(d[qtdisciplina].codigo, codigo);
                                
                                    //Nome da disciplina
                                    
                                printf("Nome: ");
                                getchar();
                                fgets(d[qtdisciplina].nome, sizeof(d[qtdisciplina].nome), stdin);
                                d[qtdisciplina].nome[strcspn(d[qtdisciplina].nome, "\n")] = '\0';
                                    
                                    //Semestre
                                printf("Semestre: ");
                                scanf("%d", &d[qtdisciplina].semestre);
                                if(d[qtdisciplina].semestre < 1){
                                    printf("\nSemestre inválido. Digite um valor maior que zero\n");
                                    break;
                                }
                                //Matricula do prof responsável
                                    
                                printf("Matrícula do professor: ");
                                scanf("%d", &d[qtdisciplina].disprof);
                                //Verifica se ha professor com a matricula
                                int existe = 0;
                                for(int j=0; j<qtdprof; j++){
                                    if(d[qtdisciplina].disprof == p[j].matricula){
                                        existe = 1;
                                        break;
                                    }
                                }
                                if(!existe){
                                    printf("\nNão há professor cadastrado com a matrícula informada\n");
                                    break;
                                }else{
                                    printf("\nCadastro realizado com sucesso\n");
                                } 
                                d[qtdisciplina].ativo = 1;
                                qtdisciplina++;
                                
                            }
                                
                        }break;
                        case 2:{
                            if(qtdisciplina == 0){
                                printf("A lista está vazia\n");
                            }else{
                                printf("Listando as disciplinas\n");
                                for(int i=0; i < qtdisciplina; i++){
                                    if(d[i].ativo == 1){
                                        printf("--Disciplina %d--\n ", i+ 1);
                                        printf("Código: %s  |  Nome: %s\n", d[i].codigo, d[i].nome);
                                        printf("Semestre: %d\n", d[i].semestre);
                                        printf("Professor responsável: %d\n", d[i].disprof);
                                    }
                                }
                            }
                            
                        }break;
                        case 3:{
                            char atualizarcod[10];
                            if(qtdisciplina == 0){
                                printf("\nNenhuma disciplina cadastrada\n");
                                break;
                            }
                            printf("Informe o código da disciplina que você deseja atualizar: ");
                            scanf("%9s", atualizarcod);
                            int posicao = posdisc(d, qtdisciplina, atualizarcod);
                            
                            if(posicao == -1){
                                printf("\nDisciplina não encontrado!\n");
                            }else{
                                disciplina novadisc;
                                strcpy(novadisc.codigo, d[posicao].codigo);
                                //Nome da disciplina
                                printf("Nome: ");
                                getchar();
                                fgets(novadisc.nome, sizeof(novadisc.nome), stdin);
                                novadisc.nome[strcspn(novadisc.nome, "\n")] = '\0';
                                
                                //Semestre
                                
                                printf("Semestre: ");
                                scanf("%d", &novadisc.semestre);
                                if(novadisc.semestre < 1){
                                    printf("\nSemestre inválido. Digite um valor maior que zero\n");
                                    break;
                                }
                                //Matricula do prof responsável 
                                
                                printf("Matrícula do professor: ");
                                scanf("%d", &novadisc.disprof);
                                //Verifica se ha professor com a matricula
                                int existe = 0;
                                for(int j=0; j<qtdprof; j++){
                                    if(novadisc.disprof == p[j].matricula){
                                        existe = 1;
                                        break;
                                    }
                                }
                                if(!existe){
                                    printf("\nNão há professor cadastrado com a matrícula informada\n");
                                    break;
                                }else{
                                    printf("\nCadastro realizado com sucesso\n");
                                }
                                novadisc.ativo = d[posicao].ativo;
                                d[posicao] = novadisc;
                            }
                            
                        }break;
                        case 4:{
                            char excluir[10];
                            if(qtdisciplina == 0){
                                printf("\nNenhuma disciplina cadastrada\n");
                                break;
                            }
                            printf("Digite o código da disciplina que deseja excluir: ");
                            scanf("%9s", excluir);
                            int posexcluir = posdisc(d, qtdisciplina, excluir);
                            if(posexcluir == -1){
                                printf("Código não encontrado\n");
                                
                            }else{
                                for(int i = posexcluir; i < qtdisciplina - 1; i++){
                                    d[i] = d[i+1];
                                }
                                qtdisciplina--;
                                printf("--Disciplina excluída com sucesso--\n");
                            }
                            
                        }break;
                        case 5:{
                            int a_matricula;
                            char codisc[10];
                            printf("\n--Atribuindo aluno à disciplina--\n");
                            printf("Informe o código da disciplina: \n");
                            scanf("%9s", codisc);
                            int poscod = posdisc(d, qtdisciplina, codisc);
                            if(poscod == -1){
                                printf("\nCódigo da disciplina não localizado\n");
                                break;
                            }
                            printf("Informe a matrícula do aluno: \n");
                            scanf("%d", &a_matricula);
                            int posmat = posaluno(a, qtdaluno, a_matricula);
                            if(posmat == -1){
                                printf("\nMatrícula do aluno não localizada\n");
                                break;
                            }
                            int matriculado = 0;
                            for(int j=0; j<TAMALUNO; j++){
                                if(d[poscod].alunomatriculado[j]==0){
                                    d[poscod].alunomatriculado[j] = a_matricula;
                                    matriculado = 1;
                                }
                            }
                            if(matriculado){
                                printf("\nAluno %s matriculado na disciplina %s com sucesso\n", a[posmat].nome, d[poscod].codigo);
                            }else{
                                printf("\nNão há vagas nesta disciplina\n");
                            }
                            
                        }break;
                        case 6:{
                            int a_matricula;
                            char codisc[10];
                            printf("\n--Atribuindo aluno à disciplina--\n");
                            printf("Informe o código da disciplina: \n");
                            scanf("%9s", codisc);
                            int poscod = posdisc(d, qtdisciplina, codisc);
                            if(poscod == -1){
                                printf("\nCódigo da disciplina não localizado\n");
                                break;
                            }
                            printf("Informe a matrícula do aluno: \n");
                            scanf("%d", &a_matricula);
                            int posmat = posaluno(a, qtdaluno, a_matricula);
                            if(posmat == -1){
                                printf("\nMatrícula do aluno não localizada\n");
                                break;
                            }          
                            int excluiralunodisc = 0;
                            for(int j=0; j<TAMALUNO; j++){
                                if(d[poscod].alunomatriculado[j]== a_matricula){
                                    d[poscod].alunomatriculado[j] = 0;
                                    excluiralunodisc = 1;
                                    break;
                                }
                            }
                            if(excluiralunodisc){
                            printf("\nAluno %s excluído da disciplina %s com sucesso\n", a[posmat].nome, d[poscod].codigo);
                            }else{
                                printf("\nAluno não está matriículado nesta disciplina\n");
                            }

                        }break;
                        default:{
                            printf("\nOpção inválida!\n");
                        }
                    }
                }
            }break;
            case 4:{
                printf("\n---Relatórios---\n");
                printf("desenvolvimento");
                
            }break;
            default:{
                printf("\nOpção inválida!\n");
            }break;
        }
        
    }
    return 0;
}
