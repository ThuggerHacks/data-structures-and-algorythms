#include <stdio.h>
#include <stdlib.h>

//estrutura de dados
typedef struct No
{
    int valor;
    struct No *proximo;
} No;

//prototipo de funcoes da lista
No *inserirNoFimDaLista(No *lista, int valor);
void imprimirLista(No *lista);
No *inserirNoInicioDaLista(No *lista, int valor);
No *inserirEmUmaPosicaoDaLista(No *lista, int pos, int valor);
No *removerNoInicioDaLista(No *lista);
No *removerNoFimDaLista(No *lista);
int tamanhoDaLista(No *lista);
No *removerEmUmaPosicaoDaLista(No *lista, int pos);

//prototipo de funcoes de pilha
No *inserirNaPilha(No *topo, int valor);
void mostrarPilha(No *topo);
int tamanhoDaPilha(No *topo);
No *eliminarDaPilha(No *topo);

//prototipo de funcoes de filas
No *inserirNaFila(No *tras, No *frente, int valor);
void mostrarFila(No *tras);
No *removerDaFila(No *frente);

//prototipo de funcoes de manipulacao das estruturas de dado
void copiarLista(No **listaA, No **listaB);
void copiarListaFilaParaPilha(No **listaA, No **fila_C_frente, No **pilha_F);
void dividirPilha(No **pilha_F, No **pilha_E, No **fila_C_tras, No **fila_C_frente);
int menorElementoDeUmaPilha(No **pilha_E);
int segundoMenorElementoDeUmaPilha(No **pilha_E);
int terceiroMenorElementoDeUmaPilha(No **pilha_E);
void removerTodosElementosIguaisAoTerceiroElementoDaPilha(No **lista, No **pilha_E);

//=========================================================

void main()
{

    //LISTAS
    No *listaA = NULL;
    No *listaB = NULL;
    //FILAS
    No *fila_C_frente = NULL;
    No *fila_C_tras = NULL;
    //=========================
    No *fila_D_frente = NULL;
    No *fila_D_tras = NULL;
    //PILHAS
    No *pilha_E = NULL;
    No *pilha_F = NULL;

    //teste de funcao para copiar listaA para listaB
    // listaA = inserirNoFimDaLista(listaA, 10);
    // listaA = inserirNoFimDaLista(listaA, 20);
    // listaA = inserirNoFimDaLista(listaA, 30);
    // listaA = inserirNoFimDaLista(listaA, 40);
    // copiarLista(&listaA, &listaB);
    // imprimirLista(listaB);

    //TESTE DE FUNCAO PARA COPIAR lista A e fila C para pilha F
    // listaA = inserirNoFimDaLista(listaA, 10);
    // listaA = inserirNoFimDaLista(listaA, 20);
    // listaA = inserirNoFimDaLista(listaA, 30);
    // listaA = inserirNoFimDaLista(listaA, 40);
    // fila_C_frente = fila_C_tras = inserirNaFila(fila_C_tras, fila_C_frente, 200);
    // fila_C_tras = inserirNaFila(fila_C_tras, fila_C_frente, 300);
    // fila_C_tras = inserirNaFila(fila_C_tras, fila_C_frente, 400);
    // copiarListaFilaParaPilha(&listaA, &fila_C_frente, &pilha_F);
    // mostrarPilha(pilha_F);

    //teste da funcao que divide a pilha F em 2 partes eguarda na pilha E e a outra parte igual guardada na fila C
    // pilha_F = inserirNaPilha(pilha_F, 11);
    // pilha_F = inserirNaPilha(pilha_F, 12);
    // pilha_F = inserirNaPilha(pilha_F, 31);
    // pilha_F = inserirNaPilha(pilha_F, 81);
    // pilha_F = inserirNaPilha(pilha_F, 8);
    // dividirPilha(&pilha_F, &pilha_E, &fila_C_tras, &fila_C_frente);
    // mostrarFila(fila_C_frente);
    // mostrarPilha(pilha_E);

    //teste para funcao que elimina todos os elementos iguais ao terceiro menor de uma pilha E
    pilha_E = inserirNaPilha(pilha_E, -1);
    pilha_E = inserirNaPilha(pilha_E, 13);
    pilha_E = inserirNaPilha(pilha_E, 5);
    pilha_E = inserirNaPilha(pilha_E, 2);
    pilha_E = inserirNaPilha(pilha_E, 4);
    //============================================
    listaA = inserirNoFimDaLista(listaA, 4);
    listaA = inserirNoFimDaLista(listaA, 4);
    listaA = inserirNoFimDaLista(listaA, 20);
    listaA = inserirNoFimDaLista(listaA, 30);
    removerTodosElementosIguaisAoTerceiroElementoDaPilha(&listaA, &pilha_E);
    removerTodosElementosIguaisAoTerceiroElementoDaPilha(&listaA, &pilha_E);
    imprimirLista(listaA);
}

//funcoes de lista
No *inserirNoFimDaLista(No *lista, int valor)
{
    //criar novo no
    No *novo_no = (No *)malloc(sizeof(No));
    //atribuir valores
    novo_no->valor = valor;
    novo_no->proximo = NULL;

    //inserir o primeiro elemento caso esteja vazia
    if (lista == NULL)
    {
        lista = novo_no;
    }
    else
    {
        //precorrer a lista para encontrar o ultimo elemento
        No *p = lista;
        while (p->proximo != NULL)
        {
            p = p->proximo;
        }
        //conectar o novo elemento no ultimo elemento encontrado
        p->proximo = novo_no;
    }

    //retornar a lista com o novo elemento inserido no final
    return lista;
}

No *inserirNoInicioDaLista(No *lista, int valor)
{

    //criar novo no
    No *novo_no = (No *)malloc(sizeof(No));
    //inserir valores no novo no
    novo_no->valor = valor;
    novo_no->proximo = NULL;

    //conectar o novo no a raiz da lista
    novo_no->proximo = lista;
    lista = novo_no;

    //retornar a lista co o novo elemento
    return lista;
};

No *inserirEmUmaPosicaoDaLista(No *lista, int pos, int valor)
{
    //criar novo no
    No *novo_no = (No *)malloc(sizeof(No));
    novo_no->valor = valor;
    novo_no->proximo = NULL;

    //inserir na primeira posicao o novo no caso nao exista um elemento na lista
    if (lista == NULL)
    {
        lista = novo_no;
    }
    else
    {
        //inserir o novo elemento na posicao 0, caso seja especificado
        if (pos == 0)
        {
            lista = inserirNoInicioDaLista(lista, valor);
        }
        else
        {

            No *p = lista;
            //precorrer a lista ate a posicao especificada
            int i;
            for (i = 0; i < pos - 1; i++)
            {
                if (p->proximo != NULL)
                {
                    p = p->proximo;
                }
            }
            //conectar o novo elemento a posicao especificada
            novo_no->proximo = p->proximo;
            p->proximo = novo_no;
        }
    }

    //retornar a lista com o novo elemento

    return lista;
}

No *removerNoInicioDaLista(No *lista)
{

    No *no = lista;
    //conectar a raiz ao segundo elemento da lista
    lista = lista->proximo;
    //desconectar o primeiro elemento da lista ao seu proximo
    no->proximo = NULL;
    //eliminar o primeiro elemento da lista
    free(no);

    //retornar a lista com o elemento removido
    return lista;
}

No *removerNoFimDaLista(No *lista)
{

    //variavel para armazenar o ultimo elemento da lista,
    //inicialmente aponta para o primeiro elemento da lista.
    No *ultimoElemento = lista;
    //variavel para armazenar o penultimo elemento da lista
    No *antesDoUltimoElemento;

    //precorrer a lista para encontrar o penultimo e ultimo elemntos
    while (ultimoElemento->proximo != NULL)
    {
        //armazenar o penultimo elemento na variavel antesDoUltimoElemento
        antesDoUltimoElemento = ultimoElemento;
        //passar o ponteiro ao proximo elemento a ser verificado
        ultimoElemento = ultimoElemento->proximo;
    }

    //desconectar o penultimo elemento do ultimo elemento
    antesDoUltimoElemento->proximo = NULL;
    //liberar a memoria/ eliminar definitivamento o elemento da lista, visto que ja nao 	possui 	conexoes a direita e nem a esquerda
    free(ultimoElemento);

    //retornar a lista com o elemento do fim removido
    return lista;
};

No *removerEmUmaPosicaoDaLista(No *lista, int pos)
{

    //eremover o primeiro elemento caso seja especificado a posicao 0
    if (pos == 0)
    {
        lista = removerNoInicioDaLista(lista);
    }
    else
    {
        No *no = lista;
        No *q;
        int i;
        //precorrer a lista ate a posicao especificada
        for (i = 0; i < pos - 1; i++)
        {
            if (pos <= tamanhoDaLista(lista))
            {
                no = no->proximo;
            }
        }
        //remover o no especificado
        q = no->proximo;
        no->proximo = q->proximo;
        q->proximo = NULL;
        free(q);
    }
    return lista;
}
void imprimirLista(No *lista)
{

    No *no = lista;

    while (no != NULL)
    {
        printf("%d ", no->valor);
        no = no->proximo;
    }
}

int tamanhoDaLista(No *lista)
{

    No *no = lista;
    int i = 0;
    while (no != NULL)
    {
        i++;
        no = no->proximo;
    }

    return i;
}

//funcoes de pilha

No *inserirNaPilha(No *topo, int valor)
{

    //criar alocacao na memoria
    No *novoelemento = (No *)malloc(sizeof(No));
    //inserir valores no novo no
    novoelemento->valor = valor;
    //atribuir o endereco do topo ao novo no
    novoelemento->proximo = topo;

    //atribuir o endereco do novo elemento ao topo
    topo = novoelemento;

    //retornar o elemento do topo
    return topo;
}

void mostrarPilha(No *topo)
{

    No *auxiliar = topo;
    while (auxiliar != NULL)
    {
        printf("valor: %d\n", auxiliar->valor);
        auxiliar = auxiliar->proximo;
    }
}

No *eliminarDaPilha(No *topo)
{

    if (topo != NULL)
    {
        No *auxiliar = topo;
        topo = topo->proximo;
        auxiliar->proximo = NULL;
        free(auxiliar);
    }
    return topo;
}

int tamanhoDaPilha(No *topo)
{
    int contador = 0;
    while (topo != NULL)
    {
        contador++;
        topo = topo->proximo;
    }

    return contador;
}
//funcoes de filas

No *inserirNaFila(No *tras, No *frente, int valor)
{
    //criar alocacao na memoria
    No *novo_no = (No *)malloc(sizeof(No));
    //inserir valores no novo no
    novo_no->valor = valor;
    novo_no->proximo = NULL;

    //inserir novo elemento na primeira posicao da fila
    if (frente == NULL && tras == NULL)
    {
        frente = tras = novo_no;
    }
    else
    {
        //conectar o novo elemento ao ultimo elemento da fila
        tras->proximo = novo_no;
        tras = novo_no;
    }

    return tras;
}

No *removerDaFila(No *frente)
{
    No *no = frente;
    No *q = no;

    if (frente != NULL)
    {
        no = no->proximo;
        q->proximo = NULL;
        free(q);
    }

    return no;
}

void mostrarFila(No *frente)
{
    No *no = frente;

    while (no != NULL)
    {
        printf("valor: %d\n", no->valor);
        no = no->proximo;
    }
}

//funcoes para manipulacao das estruturas de dado acima
//copiar lista A para lista B

void copiarLista(No **listaA, No **listaB)
{
    //precorrer a lista A
    while ((*listaA) != NULL)
    {
        //inserir valores da lista A na lista B
        (*listaB) = inserirNoFimDaLista((*listaB), (*listaA)->valor);
        //mover o ponteiro para o proximo elemento da listaA
        (*listaA) = (*listaA)->proximo;
    }
}

//funcao para copiar dados de uma LISTA A, fila C e adicionar em uma pilha F

void copiarListaFilaParaPilha(No **listaA, No **fila_C_frente, No **pilha_F)
{

    //precorrer a listaA
    while ((*listaA) != NULL)
    {
        //inserir elementos da pilha F na listaA
        (*pilha_F) = inserirNaPilha((*pilha_F), (*listaA)->valor);
        //passar o ponteiro para o proximo elemento da pilhaF
        (*listaA) = (*listaA)->proximo;
    }

    //precorrer a filaC
    while ((*fila_C_frente) != NULL)
    {
        //inser elemtnos da piLHaF na filaC
        (*pilha_F) = inserirNaPilha((*pilha_F), (*fila_C_frente)->valor);
        //passar o ponteiro da filaC para o proximo elemento
        (*fila_C_frente) = (*fila_C_frente)->proximo;
    }
}

//funcao para dividir a pilha em duas partes iguais

void dividirPilha(No **pilha_F, No **pilha_E, No **fila_C_tras, No **fila_C_frente)
{
    //contador de posicao
    int i = 0;
    //precorrer a pilha F
    while ((*pilha_F) != NULL)
    {
        //verificar se ainda estamos na primeira metade
        if (i <= (tamanhoDaPilha((*pilha_F)) / 2))
        {
            //inserir em E
            (*pilha_E) = inserirNaPilha((*pilha_E), (*pilha_F)->valor);
        }
        else
        {
            //inserir em C caso estejamos na segunda metade
            //se for o primeiro elemento
            if ((*fila_C_frente) == NULL && (*fila_C_frente) == NULL)
            {
                (*fila_C_tras) = (*fila_C_frente) = inserirNaFila((*fila_C_tras), (*fila_C_frente), (*pilha_F)->valor);
            }
            else
            {
                //se nao for o primeiro elemento da fila
                (*fila_C_tras) = inserirNaFila((*fila_C_tras), (*fila_C_frente), (*pilha_F)->valor);
            }
        }
        i++;
        (*pilha_F) = (*pilha_F)->proximo;
    }
}

//funcao para encontrar o primeiro maior elemento de uma estrutura E

int menorElementoDeUmaPilha(No **pilha_E)
{
    //pegar qualquer valor da pilha para ser o menor elemento, depois iremos substituir com o verdadeiro menor
    int menor = (*pilha_E)->valor;
    No *pilha_E_auxiliar = (*pilha_E);
    //precorrer a pilha
    while (pilha_E_auxiliar)
    {
        //verificar se o valor atual da iteracao eh menor que o valor da variavel menor
        if (menor > pilha_E_auxiliar->valor)
        {
            //caso seja verdadeiro a afirmacao acima, substituir o valor da variavelmenor pelo valor da iteracao
            menor = pilha_E_auxiliar->valor;
        }
        //passar o ponteiro para o proximo elemmento
        pilha_E_auxiliar = pilha_E_auxiliar->proximo;
    }

    return menor;
}

int maiorElementoDaPilha(No **pilha_E)
{
    No *pilha_E_auxiliar = (*pilha_E);
    //pegar qualquer elemento da pilha para ser o nosso maior elemento
    int maior = pilha_E_auxiliar->valor;
    //precorrer a pilha
    while (pilha_E_auxiliar)
    {
        //verificar se o valor da variavel maior eh ou nao maior que o valor da iteracao
        if (maior < pilha_E_auxiliar->valor)
        {
            //caso seja menor, substituir pelo valor maior
            maior = pilha_E_auxiliar->valor;
        }
        //passar o ponteiro para a proxima iteracao
        pilha_E_auxiliar = pilha_E_auxiliar->proximo;
    }

    return maior;
}

int segundoMenorElementoDeUmaPilha(No **pilha_E)
{
    //armazenar o menor elemento da estrutura
    int menor = menorElementoDeUmaPilha(pilha_E);
    No *pilha_E_auxiliar = (*pilha_E);
    //armazenar o maior elemento da lista na variavel segundo maior elemento para mais tarde ser alterado pelo segundo maior valor
    int segundoMenor = maiorElementoDaPilha(pilha_E);

    //precorrer a pilha para encontrar o segundo maior elemento da pilha
    while (pilha_E_auxiliar)
    {

        if (segundoMenor > pilha_E_auxiliar->valor && pilha_E_auxiliar->valor != menor)
        {
            //armazenar o segundo menor elemento encontrado na iteracao
            segundoMenor = pilha_E_auxiliar->valor;
        }
        pilha_E_auxiliar = pilha_E_auxiliar->proximo;
    }

    return segundoMenor;
}

int terceiroMenorElementoDeUmaPilha(No **pilha_E)
{
    No *pilha_E_auxiliar = (*pilha_E);
    //armazenar o menor e o segundo menor elementos dentro de uma variavel para depois serem verificadas
    int menor = menorElementoDeUmaPilha(pilha_E);
    int segundoMenor = segundoMenorElementoDeUmaPilha(pilha_E);
    int terceiroMenor = maiorElementoDaPilha(pilha_E);

    while (pilha_E_auxiliar)
    {
        if (terceiroMenor > pilha_E_auxiliar->valor && pilha_E_auxiliar->valor != segundoMenor && pilha_E_auxiliar->valor != menor)
        {
            terceiroMenor = pilha_E_auxiliar->valor;
        }
        pilha_E_auxiliar = pilha_E_auxiliar->proximo;
    }

    return terceiroMenor;
}

void removerTodosElementosIguaisAoTerceiroElementoDaPilha(No **lista, No **pilha_E)
{
    No *elementos = (*lista);
    //contador para verificar a posicao do elemento
    int i = 0;

    while ((*lista))
    {
        if (elementos->valor == terceiroMenorElementoDeUmaPilha(pilha_E))
        {
            (*lista) = removerEmUmaPosicaoDaLista((*lista), i);
        }
        elementos = elementos->proximo;
        i++;
    }
}