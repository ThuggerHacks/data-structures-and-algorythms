#include <stdio.h>
#include <stdlib.h>

typedef struct No
{
    int valor;
    struct No *proximo;
    struct No *anterior;
} No;

void inserirInicio(No **lista, int valor);
void imprimir(No **lista);
void inserirFim(No **lista, int valor);
void inserirPosicao(No **lista, int valor, int pos);
void removerInicio(No **lista);
void removerFim(No **lista);
void removerPosicao(No **lista, int pos);
int tamanho(No **lista);

void main()
{

    No *lista = NULL;

    inserirInicio(&lista, 3);
    inserirInicio(&lista, 8);
    inserirInicio(&lista, 7);
    inserirInicio(&lista, 12);
    imprimir(&lista);
}

void inserirInicio(No **lista, int valor)
{
    No *novo = (No *)malloc(sizeof(No));
    novo->proximo = NULL;
    novo->anterior = NULL;
    novo->valor = valor;

    novo->proximo = (*lista);
    if ((*lista))
        (*lista)->anterior = novo;

    *lista = novo;
}

void inserirFim(No **lista, int valor)
{
    No *novo = (No *)malloc(sizeof(No));
    novo->proximo = NULL;
    novo->anterior = NULL;
    novo->valor = valor;

    if ((*lista) == NULL)
    {
        *lista = novo;
    }
    else
    {
        No *ultimo = (*lista);

        while (ultimo->proximo)
        {
            ultimo = ultimo->proximo;
        }

        ultimo->proximo = novo;
        novo->anterior = ultimo;
    }
}

void inserirPosicao(No **lista, int valor, int pos)
{

    No *novo = (No *)malloc(sizeof(No));
    novo->proximo = NULL;
    novo->anterior = NULL;
    novo->valor = valor;

    if ((*lista) == NULL)
    {
        *lista = novo;
    }
    else
    {
        if (pos == 0)
        {
            inserirInicio(lista, valor);
        }
        else if (pos > tamanho(lista) || pos < 0)
        {
            printf("posicao invalida");
        }
        else if (tamanho(lista) == pos)
        {
            inserirFim(lista, valor);
        }
        else
        {
            int i = 0;
            No *alvo = (*lista);
            No *alvo2;

            while (i < pos - 1)
            {
                alvo = alvo->proximo;
                i++;
            }

            novo->proximo = alvo->proximo;
            alvo->proximo->anterior = novo;
            alvo->proximo = novo;
            novo->anterior = alvo;
        }
    }
}

void removerInicio(No **lista)
{
    if ((*lista))
    {
        No *no = (*lista);
        (*lista)->anterior = NULL;
        *lista = (*lista)->proximo;
        no->proximo = NULL;
        free(no);
    }
}

void removerFim(No **lista)
{
    if ((*lista))
    {
        No *auxiliar = (*lista);
        No *auxiliar2;

        if (auxiliar->proximo == NULL)
        {
            removerInicio(lista);
        }
        else
        {

            while (auxiliar->proximo)
            {
                auxiliar2 = auxiliar;
                auxiliar = auxiliar->proximo;
            }
            auxiliar2->proximo = NULL;
            auxiliar->anterior = NULL;
            free(auxiliar);
        }
    }
}

void removerPosicao(No **lista, int pos)
{
    if ((*lista))
    {
        if (pos == 0)
        {
            removerInicio(lista);
        }
        else if (pos == tamanho(lista))
        {
            removerFim(lista);
        }
        else if (pos > 0 && pos < tamanho(lista))
        {
            No *auxiliar = (*lista);
            No *auxiliar2;

            int i = 0;

            while (i < pos - 1)
            {
                auxiliar = auxiliar->proximo;
                i++;
            }

            auxiliar2 = auxiliar->proximo;
            auxiliar->proximo = auxiliar2->proximo;
            auxiliar2->proximo->anterior = auxiliar;
            auxiliar2->proximo = NULL;
            auxiliar2->anterior = NULL;
            free(auxiliar2);
        }
        else
        {
            printf("posicao invalida");
        }
    }
}
int tamanho(No **lista)
{
    No *no = (*lista);
    int tam = 0;
    while (no)
    {
        no = no->proximo;
        tam++;
    }
    return tam;
}
void imprimir(No **lista)
{
    No *no = (*lista);

    while (no)
    {
        printf("%d\n", no->valor);
        no = no->proximo;
    }
}