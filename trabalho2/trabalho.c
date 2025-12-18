#include <stdio.h>
#include <stdlib.h>
#define TAM 10

#include "trabalho2.h"

static EstruturaAux estruturas[TAM];

int ehPosicaoValida(int posicao)
{
    return (posicao >= 1 && posicao <= TAM) ? SUCESSO : POSICAO_INVALIDA;
}

void ordenar(int *v, int n)
{
    for(int i=0;i<n-1;i++)
        for(int j=i+1;j<n;j++)
            if(v[i]>v[j]){
                int t=v[i];
                v[i]=v[j];
                v[j]=t;
            }
}


int criarEstruturaAuxiliar(int posicao,int tamanho)
{
    if(ehPosicaoValida(posicao)!=SUCESSO)
        return POSICAO_INVALIDA;
    if(tamanho<1)
        return TAMANHO_INVALIDO;

    int idx=posicao-1;
    if(estruturas[idx].p)
        return JA_TEM_ESTRUTURA_AUXILIAR;

    estruturas[idx].p=malloc(tamanho*sizeof(int));
    if(!estruturas[idx].p)
        return SEM_ESPACO_DE_MEMORIA;

    estruturas[idx].tam=tamanho;
    estruturas[idx].cont=0;
    return SUCESSO;
}

int inserirNumeroEmEstrutura(int posicao,int valor)
{
    if(ehPosicaoValida(posicao)!=SUCESSO)
        return POSICAO_INVALIDA;

    int idx=posicao-1;
    if(!estruturas[idx].p)
        return SEM_ESTRUTURA_AUXILIAR;
    if(estruturas[idx].cont==estruturas[idx].tam)
        return SEM_ESPACO;

    estruturas[idx].p[estruturas[idx].cont++]=valor;
    return SUCESSO;
}

int excluirNumeroDoFinaldaEstrutura(int posicao)
{
    if(ehPosicaoValida(posicao)!=SUCESSO)
        return POSICAO_INVALIDA;

    int idx=posicao-1;
    if(!estruturas[idx].p)
        return SEM_ESTRUTURA_AUXILIAR;
    if(estruturas[idx].cont==0)
        return ESTRUTURA_AUXILIAR_VAZIA;

    estruturas[idx].cont--;
    return SUCESSO;
}

int excluirNumeroEspecificoDeEstrutura(int posicao,int valor)
{
    if(ehPosicaoValida(posicao)!=SUCESSO)
        return POSICAO_INVALIDA;

    int idx=posicao-1;
    if(!estruturas[idx].p)
        return SEM_ESTRUTURA_AUXILIAR;
    if(estruturas[idx].cont==0)
        return ESTRUTURA_AUXILIAR_VAZIA;

    for(int i=0;i<estruturas[idx].cont;i++){
        if(estruturas[idx].p[i]==valor){
            for(int j=i;j<estruturas[idx].cont-1;j++)
                estruturas[idx].p[j]=estruturas[idx].p[j+1];
            estruturas[idx].cont--;
            return SUCESSO;
        }
    }
    return NUMERO_INEXISTENTE;
}

int getDadosEstruturaAuxiliar(int posicao,int vetorAux[])
{
    if(ehPosicaoValida(posicao)!=SUCESSO)
        return POSICAO_INVALIDA;

    int idx=posicao-1;
    if(!estruturas[idx].p)
        return SEM_ESTRUTURA_AUXILIAR;

    for(int i=0;i<estruturas[idx].cont;i++)
        vetorAux[i]=estruturas[idx].p[i];

    return SUCESSO;
}

int getDadosOrdenadosEstruturaAuxiliar(int posicao,int vetorAux[])
{
    int ret=getDadosEstruturaAuxiliar(posicao,vetorAux);
    if(ret!=SUCESSO) return ret;

    ordenar(vetorAux,estruturas[posicao-1].cont);
    return SUCESSO;
}

int getDadosDeTodasEstruturasAuxiliares(int vetorAux[])
{
    int k=0;
    for(int i=0;i<TAM;i++){
        if(estruturas[i].p){
            for(int j=0;j<estruturas[i].cont;j++)
                vetorAux[k++]=estruturas[i].p[j];
        }
    }
    return k==0?TODAS_ESTRUTURAS_AUXILIARES_VAZIAS:SUCESSO;
}

int getDadosOrdenadosDeTodasEstruturasAuxiliares(int vetorAux[])
{
    int ret=getDadosDeTodasEstruturasAuxiliares(vetorAux);
    if(ret!=SUCESSO) return ret;

    int total=0;
    for(int i=0;i<TAM;i++)
        total+=estruturas[i].cont;

    ordenar(vetorAux,total);
    return SUCESSO;
}

int modificarTamanhoEstruturaAuxiliar(int posicao,int novoTamanho)
{
    if(ehPosicaoValida(posicao)!=SUCESSO)
        return POSICAO_INVALIDA;
    if(novoTamanho<0)
        return NOVO_TAMANHO_INVALIDO;

    int idx=posicao-1;
    if(!estruturas[idx].p)
        return SEM_ESTRUTURA_AUXILIAR;

    int novoTam=estruturas[idx].tam+novoTamanho;
    if(novoTam<1)
        return NOVO_TAMANHO_INVALIDO;

    int *novo=realloc(estruturas[idx].p,novoTam*sizeof(int));
    if(!novo)
        return SEM_ESPACO_DE_MEMORIA;

    estruturas[idx].p=novo;
    estruturas[idx].tam=novoTam;
    if(estruturas[idx].cont>novoTam)
        estruturas[idx].cont=novoTam;

    return SUCESSO;
}

int getQuantidadeElementosEstruturaAuxiliar(int posicao)
{
    if(ehPosicaoValida(posicao)!=SUCESSO)
        return POSICAO_INVALIDA;

    int idx = posicao - 1;
    if(!estruturas[idx].p){
        return SEM_ESTRUTURA_AUXILIAR;
    }
    return estruturas[idx].cont;
}


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

void getDadosListaEncadeadaComCabecote(No *inicio, int vetorAux[])
{   
    int i=0;
    if(!inicio){
       return; 
    } 
    No *p = inicio->prox;
    while(p){
        vetorAux[i++] = p->conteudo;
        p = p->prox;
    }
}

void destruirListaEncadeadaComCabecote(No **inicio)
{
    if(!inicio||!*inicio) return;
    No *aux;
    while(*inicio){
        aux=*inicio;
        *inicio=(*inicio)->prox;
        free(aux);
    }
    *inicio=NULL;
}


void inicializar()
{
    for(int i=0;i<TAM;i++){
        estruturas[i].p=NULL;
        estruturas[i].cont=0;
        estruturas[i].tam=0;
    }
}

void finalizar()
{
    for(int i=0;i<TAM;i++){
        free(estruturas[i].p);
        estruturas[i].p=NULL;
        estruturas[i].cont=0;
        estruturas[i].tam=0;
    }
}
