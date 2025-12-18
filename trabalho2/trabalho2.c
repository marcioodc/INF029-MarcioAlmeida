#include <stdio.h>
#include <stdlib.h>
#define TAM 10

#include "trabalho2.h"

int vetorPrincipal[TAM];
int ehPosicaoValida(int posicao);
/*
Objetivo: criar estrutura auxiliar na posição 'posicao'.
com tamanho 'tamanho'

Rertono (int)
    SUCESSO - criado com sucesso
    JA_TEM_ESTRUTURA_AUXILIAR - já tem estrutura na posição
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
    SEM_ESPACO_DE_MEMORIA - Sem espaço de memória
    TAMANHO_INVALIDO - o tamanho deve ser maior ou igual a 1
*/

static EstruturaAux estruturas[TAM];

int criarEstruturaAuxiliar(int posicao,int tamanho)
{
    if(ehPosicaoValida(posicao) != SUCESSO){
        return POSICAO_INVALIDA;
    }
    if(tamanho < 1){
        return TAMANHO_INVALIDO;
    }
    int idx = posicao -1;
    if(estruturas[idx].p){
        return JA_TEM_ESTRUTURA_AUXILIAR;
    }
    estruturas[idx].p = malloc(tamanho * sizeof(int));
    if(!estruturas[idx].p){
        return SEM_ESPACO_DE_MEMORIA;
    }
    estruturas[idx].tam = tamanho;
    estruturas[idx].cont = 0;
    return SUCESSO;
}


void ordenar(int *v, int n)
{
    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            if(v[i] > v[j]){
                int t = v[i];
                v[i] = v[j];
                v[j] = t;
            }
        }
    }
}
/*
Objetivo: inserir número 'valor' em estrutura auxiliar da posição 'posicao'
Rertono (int)
    SUCESSO - inserido com sucesso
    SEM_ESPACO - não tem espaço
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
CONSTANTES
*/
int inserirNumeroEmEstrutura(int posicao,int valor)
{
    if(ehPosicaoValida(posicao) != SUCESSO){
        return POSICAO_INVALIDA;
    }
    int idx = posicao -1;
    if(!estruturas[idx].p){
        return SEM_ESTRUTURA_AUXILIAR;
    }
    if(estruturas[idx].cont == estruturas[idx].tam){
        return SEM_ESPACO;
    }
    estruturas[idx].p[estruturas[idx].cont++] = valor;
    return SUCESSO;
}

/*
Objetivo: excluir o numero 'valor' da estrutura auxiliar no final da estrutura.
ex: suponha os valores [3, 8, 7, 9,  ,  ]. Após excluir, a estrutura deve ficar da seguinte forma [3, 8, 7,  ,  ,  ].
Obs. Esta é uma exclusão lógica

Rertono (int)
    SUCESSO - excluido com sucesso
    ESTRUTURA_AUXILIAR_VAZIA - estrutura vazia
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int excluirNumeroDoFinaldaEstrutura(int posicao)
{
    if(ehPosicaoValida(posicao) != SUCESSO){
        return POSICAO_INVALIDA;
    }
    int idx = posicao -1;
    if(!estruturas[idx].p){
        return SEM_ESTRUTURA_AUXILIAR;
    }
    if(estruturas[idx].cont == 0){
        return ESTRUTURA_AUXILIAR_VAZIA;
    }
    estruturas[idx].cont--;
    return SUCESSO;
}
/*
Objetivo: excluir o numero 'valor' da estrutura auxiliar da posição 'posicao'.
Caso seja excluido, os números posteriores devem ser movidos para as posições anteriores
ex: suponha os valores [3, 8, 7, 9,  ,  ] onde deve ser excluido o valor 8. A estrutura deve ficar da seguinte forma [3, 7, 9,  ,  ,  ]
Obs. Esta é uma exclusão lógica
Rertono (int)
    SUCESSO - excluido com sucesso 'valor' da estrutura na posição 'posicao'
    ESTRUTURA_AUXILIAR_VAZIA - estrutura vazia
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    NUMERO_INEXISTENTE - Número não existe
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar

*/
int excluirNumeroEspecificoDeEstrutura(int posicao,int valor)
{
    if(ehPosicaoValida(posicao) != SUCESSO){
        return POSICAO_INVALIDA;
    }
    int idx = posicao-1;
    if(!estruturas[idx].p){
        return SEM_ESTRUTURA_AUXILIAR;
    }
    if(estruturas[idx].cont == 0){
        return ESTRUTURA_AUXILIAR_VAZIA;
    }
    for(int i=0; i<estruturas[idx].cont; i++){
        if(estruturas[idx].p[i] == valor){
            for(int j=i; j<estruturas[idx].cont-1; j++){
                estruturas[idx].p[j] = estruturas[idx].p[j+1];
            }
            estruturas[idx].cont--;
            return SUCESSO;
        }
    }
    return NUMERO_INEXISTENTE;
}

// se posição é um valor válido {entre 1 e 10}
int ehPosicaoValida(int posicao)
{
    return (posicao >= 1 && posicao <= TAM) ? SUCESSO : POSICAO_INVALIDA;
}
/*
Objetivo: retorna os números da estrutura auxiliar da posição 'posicao (1..10)'.
os números devem ser armazenados em vetorAux

Retorno (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
 int getDadosEstruturaAuxiliar(int posicao,int vetorAux[])
{
    if(ehPosicaoValida(posicao) != SUCESSO)
        return POSICAO_INVALIDA;

    int idx = posicao - 1;
    if(!estruturas[idx].p){
        return SEM_ESTRUTURA_AUXILIAR;
    }
    for(int i=0; i<estruturas[idx].cont; i++){
        vetorAux[i] = estruturas[idx].p[i];
    }
    return SUCESSO;
}

/*
Objetivo: retorna os números ordenados da estrutura auxiliar da posição 'posicao (1..10)'.
os números devem ser armazenados em vetorAux

Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao (1..10)'
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int getDadosOrdenadosEstruturaAuxiliar(int posicao, int vetorAux[])
{
    int ret = getDadosEstruturaAuxiliar(posicao, vetorAux);
    if(ret! = SUCESSO){
        return ret;
    }
    ordenar(vetorAux, estruturas[posicao-1].cont);
    return SUCESSO;
}
/*
Objetivo: retorna os números de todas as estruturas auxiliares.
os números devem ser armazenados em vetorAux

Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    TODAS_ESTRUTURAS_AUXILIARES_VAZIAS - todas as estruturas auxiliares estão vazias
*/
int getDadosDeTodasEstruturasAuxiliares(int vetorAux[])
{
    int k = 0;
    for(int i=0; i<TAM; i++){
        if(estruturas[i].p){
            for(int j=0; j<estruturas[i].cont; j++){
                vetorAux[k++] = estruturas[i].p[j];
            }
        }
    }
    return k == 0 ? TODAS_ESTRUTURAS_AUXILIARES_VAZIAS: SUCESSO;
}

/*
Objetivo: retorna os números ordenados de todas as estruturas auxiliares.
os números devem ser armazenados em vetorAux

Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    TODAS_ESTRUTURAS_AUXILIARES_VAZIAS - todas as estruturas auxiliares estão vazias
*/
int getDadosOrdenadosDeTodasEstruturasAuxiliares(int vetorAux[])
{
    int ret = getDadosDeTodasEstruturasAuxiliares(vetorAux);
    if(ret! = SUCESSO){
        return ret;
    }
    int total = 0;
    for(int i=0; i<TAM; i++){
        total += estruturas[i].cont;
    }
    ordenar(vetorAux, total);
    return SUCESSO;
}
    
/*
Objetivo: modificar o tamanho da estrutura auxiliar da posição 'posicao' para o novo tamanho 'novoTamanho' + tamanho atual
Suponha o tamanho inicial = x, e novo tamanho = n. O tamanho resultante deve ser x + n. Sendo que x + n deve ser sempre >= 1

Rertono (int)
    SUCESSO - foi modificado corretamente o tamanho da estrutura auxiliar
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
    NOVO_TAMANHO_INVALIDO - novo tamanho não pode ser negativo
    SEM_ESPACO_DE_MEMORIA - erro na alocação do novo valor
*/
int modificarTamanhoEstruturaAuxiliar(int posicao, int novoTamanho)
{
    if(ehPosicaoValida(posicao)!=SUCESSO){
        return POSICAO_INVALIDA;
    }
    int idx = posicao-1;
    if(!estruturas[idx].p){
        return SEM_ESTRUTURA_AUXILIAR;
    }
    int novoTam = estruturas[idx].tam + novoTamanho;
    if(novoTam < 1){
        return NOVO_TAMANHO_INVALIDO;
    }
    int *novo=realloc(estruturas[idx].p, novoTam*sizeof(int));
    if(!novo){
        return SEM_ESPACO_DE_MEMORIA;
    }
    estruturas[idx].p = novo;
    estruturas[idx].tam = novoTam;
    if(estruturas[idx].cont > novoTam){
        estruturas[idx].cont = novoTam;
    }
    return SUCESSO;
}
    
/*
Objetivo: retorna a quantidade de elementos preenchidos da estrutura auxiliar da posição 'posicao'.

Retorno (int)
    POSICAO_INVALIDA - posição inválida
    SEM_ESTRUTURA_AUXILIAR - sem estrutura auxiliar
    ESTRUTURA_AUXILIAR_VAZIA - estrutura auxiliar vazia
    Um número int > 0 correpondente a quantidade de elementos preenchidos da estrutura
*/
int getQuantidadeElementosEstruturaAuxiliar(int posicao)
{
    if(ehPosicaoValida(posicao) != SUCESSO){
        return POSICAO_INVALIDA;
    }
    int idx = posicao - 1;
    if(!estruturas[idx].p){
        return SEM_ESTRUTURA_AUXILIAR;
    }
    return estruturas[idx].cont;
}
    
/*
Objetivo: montar a lista encadeada com cabeçote com todos os números presentes em todas as estruturas.

Retorno (No*)
    NULL, caso não tenha nenhum número nas listas
    No*, ponteiro para o início da lista com cabeçote
*/

No *montarListaEncadeadaComCabecote()
{
    No *cabecote = malloc(sizeof(No));
    if(!cabecote){
       return NULL; 
    } 
    cabecote->prox = NULL;
    No *atual = cabecote;
    int total = 0;

    for(int i=0; i<TAM; i++){
        if(estruturas[i].p && estruturas[i].cont > 0){
            for(int j=0; j<estruturas[i].cont; j++){
                No *novo = malloc(sizeof(No));
                if(!novo){
                    destruirListaEncadeadaComCabecote(&cabecote);
                    return NULL;
                }
                novo->conteudo = estruturas[i].p[j];
                novo->prox = NULL;
                atual->prox = novo;
                atual = novo;
                total++;
            }
        }
    }
    if(total == 0){
        free(cabecote);
        return NULL;
    }
    return cabecote;
}

/*
Objetivo: retorna os números da lista enceada com cabeçote armazenando em vetorAux.
Retorno void
*/

void getDadosListaEncadeadaComCabecote(No *inicio, int vetorAux[])
{   
    int i = 0;
    if(!inicio){
       return; 
    } 
    No *p = inicio->prox;
    while(p){
        vetorAux[i++] = p->conteudo;
        p = p->prox;
    }
}

/*
Objetivo: Destruir a lista encadeada com cabeçote a partir de início.
O ponteiro inicio deve ficar com NULL.

Retorno 
    void.
*/

void destruirListaEncadeadaComCabecote(No **inicio)
{
    if(!inicio || !*inicio){
        return;
    }
    No *aux;
    while(*inicio){
        aux = *inicio;
        *inicio = (*inicio)->prox;
        free(aux);
    }
    *inicio = NULL;
}

/*
Objetivo: inicializa o programa. deve ser chamado ao inicio do programa 

*/

void inicializar()
{
    for(int i=0; i<TAM; i++){
        estruturas[i].p = NULL;
        estruturas[i].cont = 0;
        estruturas[i].tam = 0;
    }
}

/*
Objetivo: finaliza o programa. deve ser chamado ao final do programa 
para poder liberar todos os espaços de memória das estruturas auxiliares.

*/
void finalizar()
{
    for(int i=0; i<TAM; i++){
        free(estruturas[i].p);
        estruturas[i].p = NULL;
        estruturas[i].cont = 0;
        estruturas[i].tam = 0;
    }
}
