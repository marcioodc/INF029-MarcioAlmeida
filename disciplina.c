#include "disciplina.h"
#include "aluno.h"
#include "professor.h"

int posdisc(disciplina d[], int qtdisciplina, char codigo[]){
    int i;
    for(i=0; i<qtdisciplina; i++){
        if(strcmp(d[i].codigo, codigo) == 0){
            return i;
        }
    }
    return -1;
}

void cadastrardisciplina(disciplina d[], int *qtdisciplina, professor p[], int *qtdprof){
        //cadastrar disciplina
    for(int j=0; j<TAMALUNO; j++){
        d[*qtdisciplina].alunomatriculado[j] = 0;
    }
    char codigo[10];
    if(*qtdisciplina == TAMDISCIPLINA){
        printf("A lista está cheia!\n");
        return;
    }else{
        printf("--Cadastrando disciplina--\n");
        printf("Informações da disciplina:\n");
        printf("Código: ");
        scanf("%9s", codigo);
        if(posdisc(d, *qtdisciplina, codigo) != -1){
            printf("Já existe disciplina com este código!\n");
            return;
        }
        strcpy(d[*qtdisciplina].codigo, codigo);
            //Nome da disciplina
        printf("Nome: ");
        getchar();
        fgets(d[*qtdisciplina].nome, sizeof(d[*qtdisciplina].nome), stdin);
        d[*qtdisciplina].nome[strcspn(d[*qtdisciplina].nome, "\n")] = '\0';
            //Semestre
        printf("Semestre: ");
        scanf("%d", &d[*qtdisciplina].semestre);
        if(d[*qtdisciplina].semestre < 1){
            printf("\nSemestre inválido. Digite um valor maior que zero!\n");
            return;
        }
            //Quantidade de vagas
        printf("Quantidade de vagas: ");
        scanf("%d", &d[*qtdisciplina].qtdvagas);
        if(d[*qtdisciplina].qtdvagas < 1){
            printf("\nValor inválido! Digite um valor maior que 0!\n");
            return;
        }
            //Matricula do prof responsável
        printf("Matrícula do professor: ");
        scanf("%d", &d[*qtdisciplina].disprof);
            //Verifica se ha professor com a matricula
        int existe = 0;
        for(int j=0; j< *qtdprof; j++){
            if(d[*qtdisciplina].disprof == p[j].matricula && p[j].ativo == 1){
                existe = 1;
            }
        }
        if(!existe){
            printf("\nNão há professor cadastrado com a matrícula informada!\n");
            return;
        }else{
            printf("\n***Cadastro realizado com sucesso!***\n");
            d[*qtdisciplina].ativo = 1;
            (*qtdisciplina)++;
            return; 
        }
    }
}

void listardisciplina(disciplina d[], int *qtdisciplina){
    if(*qtdisciplina == 0){
        printf("A lista está vazia!\n");
        return;
    }else{
        printf("--Listando as disciplinas--\n");
        for(int i=0; i < *qtdisciplina; i++){
            if(d[i].ativo == 1){
                printf("Código: %s  |  Nome: %s\n", d[i].codigo, d[i].nome);
                printf("Semestre: %d\n", d[i].semestre);
                printf("Professor responsável: %d\n", d[i].disprof);
            }
        }
        return;
    }
}

void atualizardisciplina(disciplina d[], int *qtdisciplina, professor p[], int *qtdprof){
    char atualizarcod[10];
    if(*qtdisciplina == 0){
        printf("\nNenhuma disciplina cadastrada!\n");
        return;
    }
    printf("Informe o código da disciplina que você deseja atualizar: ");
    scanf("%9s", atualizarcod);
    int posicao = posdisc(d, *qtdisciplina, atualizarcod);
    if(posicao == -1){
        printf("\nDisciplina não encontrado!\n");
    }else{
        disciplina novadisc = d[posicao];
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
            printf("\nSemestre inválido. Digite um valor maior que zero!\n");
            return;
        }
            //Quantidade de vagas
        printf("Quantidade de vagas: ");
        scanf("%d", &novadisc.qtdvagas);
        if(novadisc.qtdvagas < 1){
            printf("\nValor inválido! Digite um valor maior que 0!\n");
            return;
        }
            //Matricula do prof responsável 
        printf("Matrícula do professor: ");
        scanf("%d", &novadisc.disprof);
            //Verifica se ha professor com a matricula
        int existe = 0;
        for(int j=0; j< *qtdprof; j++){
            if(novadisc.disprof == p[j].matricula){
                existe = 1;
                break;
            }
        }
        if(!existe){
            printf("\nNão há professor cadastrado com a matrícula informada!\n");
            return;
        }else{
            printf("\n***Cadastro realizado com sucesso!***\n");
            novadisc.ativo = d[posicao].ativo;
            d[posicao] = novadisc;
            return;
        }
    }
}

void excluirdisciplina(disciplina d[], int *qtdisciplina){
    char excluir[10];
    if(*qtdisciplina == 0){
        printf("\nNenhuma disciplina cadastrada!\n");
        return;
    }else{
        printf("Digite o código da disciplina que deseja excluir: ");
        scanf("%9s", excluir);
        int posexcluir = posdisc(d, *qtdisciplina, excluir);
        if(posexcluir == -1){
            printf("Código não encontrado!\n");
            return;
        }else{
            for(int i = posexcluir; i < *qtdisciplina - 1; i++){
                d[i] = d[i+1];
            }
            (*qtdisciplina)--;
            printf("***Disciplina excluída com sucesso!***\n");
            return;
        }
    }
}

void atribuiralunodisciplina(disciplina d[], int *qtdisciplina, aluno a[], int *qtdaluno){
    int a_matricula;
    char codisc[10];
    if(*qtdaluno == 0){
        printf("\nNenhum aluno cadastrado!\n");
        return;
    }else{
        printf("\n--Atribuindo aluno à disciplina--\n");
        printf("Informe o código da disciplina: \n");
        scanf("%9s", codisc);
        int poscod = posdisc(d, *qtdisciplina, codisc);
        if(poscod == -1){
            printf("\nCódigo da disciplina não localizado!\n");
            return;
        }
        printf("Informe a matrícula do aluno: \n");
        scanf("%d", &a_matricula);
        int posmat = posaluno(a, *qtdaluno, a_matricula);
        if(posmat == -1){
            printf("\nMatrícula do aluno não localizada!\n");
            return;
        }
        for(int j=0; j<TAMALUNO; j++){
            if(d[poscod].alunomatriculado[j] == a_matricula){
                printf("\nAluno já está matriculado nesta disciplina!\n");
                return;
            }
        }
        int matriculado = 0;
        for(int j=0; j<TAMALUNO; j++){
            if(d[poscod].alunomatriculado[j]==0){
                d[poscod].alunomatriculado[j] = a_matricula;
                matriculado++;
                break;
            }
        }
        if(matriculado){
            printf("\n***Aluno %s matriculado na disciplina %s com sucesso!***\n", a[posmat].nome, d[poscod].codigo);
        }else{
            printf("\nNão há vagas nesta disciplina!\n");
        }
    }
}

void excluiralunodisciplina(disciplina d[], int *qtdisciplina, aluno a[], int *qtdaluno){
    int a_matricula;
    char codisc[10];
    if(*qtdaluno == 0){
        printf("\nNão há aluno cadastrado!\n");
    }else{
        printf("\n--Excluíndo aluno da disciplina--\n");
        printf("Informe o código da disciplina: \n");
        scanf("%9s", codisc);
        int poscod = posdisc(d, *qtdisciplina, codisc);
        if(poscod == -1){
            printf("\nCódigo da disciplina não localizado!\n");
            return;
        }
        printf("Informe a matrícula do aluno: \n");
        scanf("%d", &a_matricula);
        int posmat = posaluno(a, *qtdaluno, a_matricula);
        if(posmat == -1){
            printf("\nMatrícula do aluno não localizada!\n");
            return;
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
            printf("\n***Aluno %s excluído da disciplina %s com sucesso!***\n", a[posmat].nome, d[poscod].codigo);
            return;
        }else{
            printf("\nAluno não está matriículado nesta disciplina!\n");
            return;
        }
    }
}
