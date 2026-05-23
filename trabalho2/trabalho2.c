#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// tamanho da estrutura principal
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
int criarEstruturaAuxiliar(int posicao, int tamanho)
{
    int retorno = 0;
    /* a posicao pode já existir estrutura auxiliar
    retorno = JA_TEM_ESTRUTURA_AUXILIAR;
    // se posição é um valor válido {entre 1 e 10}
    retorno = POSICAO_INVALIDA;
    // o tamanho ser muito grande
    retorno = SEM_ESPACO_DE_MEMORIA;
    // o tamanho nao pode ser menor que 1
    retorno = TAMANHO_INVALIDO;
    // deu tudo certo, crie
    retorno = SUCESSO;*/
    int *vetorAuxiliar[tamanho];
    if (vetorPrincipal[posicao] != 0)
    {
        retorno = JA_TEM_ESTRUTURA_AUXILIAR;
    }
    else if (ehPosicaoValida(posicao) != SUCESSO)
    {
        retorno = POSICAO_INVALIDA;
    }
    else if (tamanho > 100)
    {
        retorno = SEM_ESPACO_DE_MEMORIA;
    }
    else if (tamanho < 1)
    {
        retorno = TAMANHO_INVALIDO;
    }
    else
    {
        int *vetorAuxiliar = malloc(tamanho * sizeof(int));
        vetorPrincipal[posicao] = 1;
        for (int i = 0; i < tamanho; i++)
        {
            vetorAuxiliar[i] = -1;
        }
        retorno = SUCESSO;
    }
    // tamanho = tamanho da estrutura auxiliar
    return retorno;
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
int inserirNumeroEmEstrutura(int posicao, int valor)
{
    int retorno = 0;
    int existeEstruturaAuxiliar = 0;
    int temEspaco = 0;
    int posicao_invalida = 0;
    int tamanho;
    int vetorAuxiliar[tamanho];

    if (posicao < 1 || posicao > 10)
        retorno = POSICAO_INVALIDA;
    else
    {
        // testar se existe a estrutura auxiliar
        if (vetorPrincipal[posicao - 1] != 0)
        {
            existeEstruturaAuxiliar = 1;
        }
        if (existeEstruturaAuxiliar)
        {
            // testar se tem espaço
            for (int i = 0; i < tamanho; i++)
            {
                if (vetorAuxiliar[i] == -1)
                {
                    temEspaco = 1;
                    break;
                }
            }
            if (temEspaco)
            {
                // insere
                for (int j = 0; j < tamanho; j++)
                {
                    if (vetorAuxiliar[j] == -1)
                    {
                        vetorAuxiliar[j] = valor;
                    }
                }
                retorno = SUCESSO;
            }
            else
            {
                retorno = SEM_ESPACO;
            }
        }
        else
        {
            retorno = SEM_ESTRUTURA_AUXILIAR;
        }
    }

    return retorno;
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
    int retorno = SUCESSO;
    int vetorAuxiliar[TAM];
    if (vetorAuxiliar[posicao - 1] == 0)
    {
        retorno = ESTRUTURA_AUXILIAR_VAZIA;
    }
    if (vetorPrincipal[posicao - 1] == 0)
    {
        retorno = SEM_ESTRUTURA_AUXILIAR;
    }
    if (posicao > vetorPrincipal[posicao - 1] || posicao < 1)
    {
        retorno = POSICAO_INVALIDA;
    }
    for (int i = TAM - 1; i >= 0; i--)
    {
        if (vetorAuxiliar[posicao - 1] != -1)
        {
            vetorAuxiliar[posicao - 1] = -1;
            break;
        }
    }
    return retorno;
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
int excluirNumeroEspecificoDeEstrutura(int posicao, int valor)
{
    int retorno = SUCESSO;
    int vetorAuxiliar[TAM];
    if (vetorAuxiliar[posicao - 1] == 0)
    {
        retorno = ESTRUTURA_AUXILIAR_VAZIA;
    }
    if (vetorPrincipal[posicao - 1] == 0)
    {
        retorno = SEM_ESTRUTURA_AUXILIAR;
    }
    if (vetorAuxiliar[posicao - 1] != valor)
    {
        retorno = NUMERO_INEXISTENTE;
    }
    if (posicao > vetorPrincipal[posicao - 1] || posicao < 1)
    {
        retorno = POSICAO_INVALIDA;
    }
    for (int i = 0; i < TAM; i++)
    {
        if (vetorAuxiliar[posicao - 1] == valor)
        {
            vetorAuxiliar[posicao - 1] = -1;
            break;
        }
    }
    return retorno;
}

// se posição é um valor válido {entre 1 e 10}
int ehPosicaoValida(int posicao)
{
    int retorno = 0;
    if (posicao < 1 || posicao > 10)
    {
        retorno = POSICAO_INVALIDA;
    }
    else
        retorno = SUCESSO;

    return retorno;
}
/*
Objetivo: retorna os números da estrutura auxiliar da posição 'posicao (1..10)'.
os números devem ser armazenados em vetorAux

Retorno (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int getDadosEstruturaAuxiliar(int posicao, int vetorAux[])
{

    int retorno = 0;
    int vetorAuxiliar[TAM] = {0};
    if (vetorPrincipal[posicao - 1] == 0)
    {
        retorno = SEM_ESTRUTURA_AUXILIAR;
    }
    if (posicao < 1 || posicao > 10)
    {
        retorno = POSICAO_INVALIDA;
    }
    for (int i = 0; i < TAM; i++)
    {
        vetorAux[i] = vetorAuxiliar[posicao - 1];
    }
    retorno = SUCESSO;
    return retorno;
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

    int retorno = 0;
    int vetorAuxiliar[TAM] = {0};
    if (vetorPrincipal[posicao - 1] == 0)
    {
        retorno = SEM_ESTRUTURA_AUXILIAR;
    }
    if (posicao < 1 || posicao > 10)
    {
        retorno = POSICAO_INVALIDA;
    }
    for (int i = 0; i < TAM; i++)
    {
        vetorAux[i] = vetorAuxiliar[posicao - 1];
    }
    for (int i = 0; i < TAM - 1; i++)
    {
        for (int j = 0; j < TAM - i - 1; j++)
        {
            if (vetorAux[j] > vetorAux[j + 1])
            {
                int temp = vetorAux[j];
                vetorAux[j] = vetorAux[j + 1];
                vetorAux[j + 1] = temp;
            }
        }
    }
    retorno = SUCESSO;
    return retorno;
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

    int retorno = 0;
    int vetorAuxiliar[TAM] = {0};
    for (int j = 0; j < 10; j++)
    {
        if (vetorPrincipal[j] == 0)
        {
            retorno = TODAS_ESTRUTURAS_AUXILIARES_VAZIAS;
            return retorno;
        }
    }
    for (int i = 0; i < 10; i++)
    {
        if (vetorPrincipal[i] != 0)
        {
            for (int j = 0; j < TAM; j++)
            {
                vetorAux[i * TAM + j] = vetorAuxiliar[i];
            }
        }
    }
    retorno = SUCESSO;
    return retorno;
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

    int retorno = 0;
    int vetorAuxiliar[TAM] = {0};
    for (int j = 0; j < 10; j++)
    {
        if (vetorPrincipal[j] == 0)
        {
            retorno = TODAS_ESTRUTURAS_AUXILIARES_VAZIAS;
            return retorno;
        }
    }
    for (int i = 0; i < 10; i++)
    {
        if (vetorPrincipal[i] != 0)
        {
            for (int j = 0; j < TAM; j++)
            {
                vetorAux[i * TAM + j] = vetorAuxiliar[i];
            }
        }
    }
    for (int i = 0; i < 10 * TAM - 1; i++)
    {
        for (int j = 0; j < 10 * TAM - i - 1; j++)
        {
            if (vetorAux[j] > vetorAux[j + 1])
            {
                int temp = vetorAux[j];
                vetorAux[j] = vetorAux[j + 1];
                vetorAux[j + 1] = temp;
            }
        }
    }
    retorno = SUCESSO;
    return retorno;
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
    int retorno = 0;
    int *vetorAuxiliar[TAM] = {NULL};
    if (posicao < 1 || posicao > TAM)
    {
        return POSICAO_INVALIDA;
    }
    if (novoTamanho < 0)
    {
        return NOVO_TAMANHO_INVALIDO;
    }
    posicao--;
    if (vetorPrincipal[posicao] == 0)
    {
        return SEM_ESTRUTURA_AUXILIAR;
    }
    int *temp = realloc(vetorAuxiliar[posicao], (TAM + novoTamanho) * sizeof(int));
    if (temp == NULL)
    {
        return SEM_ESPACO_DE_MEMORIA;
    }
    vetorAuxiliar[posicao] = temp;
    for (int i = TAM; i < TAM + novoTamanho; i++)
    {
        vetorAuxiliar[posicao][i] = -1;
    }
    retorno = SUCESSO;
    return retorno;
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

    int retorno = 0;
    int vetorAuxiliar[TAM] = {0};
    if (posicao < 1 || posicao > 10)
    {
        retorno = POSICAO_INVALIDA;
    }
    if (vetorPrincipal[posicao - 1] == 0)
    {
        retorno = SEM_ESTRUTURA_AUXILIAR;
    }
    if (vetorAuxiliar[posicao - 1] == 0)
    {
        retorno = ESTRUTURA_AUXILIAR_VAZIA;
    }
    int count = 0;
    for (int i = 0; i < TAM; i++)
    {
        if (vetorAuxiliar[posicao - 1] != -1)
        {
            count++;
        }
    }
    retorno = count;
    return retorno;
}

/*
Objetivo: montar a lista encadeada com cabeçote com todos os números presentes em todas as estruturas.

Retorno (No*)
    NULL, caso não tenha nenhum número nas listas
    No*, ponteiro para o início da lista com cabeçote
*/
No *montarListaEncadeadaComCabecote()
{
    int vetorAuxiliar[TAM];
    No *inicio = NULL;
    No *atual = NULL;
    for (int i = 0; i < 10; i++)
    {
        if (vetorPrincipal[i] != 0)
        {
            for (int j = 0; j < TAM; j++)
            {
                if (vetorAuxiliar[j] != -1)
                {
                    No *novoNo = malloc(sizeof(No));
                    if (novoNo == NULL)
                    {
                        return NULL;
                    }
                    novoNo->conteudo = vetorAuxiliar[j];
                    novoNo->prox = NULL;
                    if (inicio == NULL)
                    {
                        inicio = novoNo;
                        atual = inicio;
                    }
                    else
                    {
                        atual->prox = novoNo;
                        atual = atual->prox;
                    }
                }
            }
        }
    }
    return inicio;
}

/*
Objetivo: retorna os números da lista enceada com cabeçote armazenando em vetorAux.
Retorno void
*/
void getDadosListaEncadeadaComCabecote(No *inicio, int vetorAux[])
{
    No *atual = inicio;
    int i = 0;
    while (atual != NULL)
    {
        vetorAux[i] = atual->conteudo;
        atual = atual->prox;
        i++;
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
    No *atual = *inicio;
    No *proximo = NULL;
    while (atual != NULL)
    {
        proximo = atual->prox;
        free(atual);
        atual = proximo;
    }
    *inicio = NULL;
}

/*
Objetivo: inicializa o programa. deve ser chamado ao inicio do programa

*/

void inicializar()
{
    int *vetorAuxiliar[TAM] = {NULL};
    int vetorPrincipal[TAM] = {0};
    for (int i = 0; i < TAM; i++)
    {
        vetorPrincipal[i] = 0;
    }
    for (int i = 0; i < 10; i++)
    {
        vetorAuxiliar[i] = NULL;
    }
}

/*
Objetivo: finaliza o programa. deve ser chamado ao final do programa
para poder liberar todos os espaços de memória das estruturas auxiliares.

*/

void finalizar()
{
    int *vetorAuxiliar[TAM] = {NULL};
    int vetorPrincipal[TAM] = {0};
    for (int i = 0; i < 10; i++)
    {
        if (vetorPrincipal[i] != 0)
        {
            free(vetorAuxiliar[i]);
            vetorPrincipal[i] = 0;
        }
    }
}

void dobrar(int *x)
{
    *x = *x * 2;
}