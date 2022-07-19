#include <stdio.h>
#include <stdlib.h>

typedef struct No
{
    int valor;
    struct No *proximo;
} No;

void imprimir(No **lista);
void inserirInicio(No **lista, int valor);
void inserirFim(No **lista, int valor);
int tamanho(No **lista);
void inserirPosicao(No **lista, int valor, int pos);
void apagarInicio(No **lista);
void apagarFim(No **lista);
void apagarPosicao(No **lista, int pos);

int main(int argc, char *argv[])
{
    No *lista = NULL;

    inserirInicio(&lista, 5);
    inserirInicio(&lista, 10);
    inserirInicio(&lista, 20);
    inserirFim(&lista, 50);
    //	inserirFim(&lista,60);
    //inserirPosicao(&lista,100,5);
    //inserirPosicao(&lista,65,2);
    //	apagarInicio(&lista);
    //	apagarInicio(&lista);
    //	apagarInicio(&lista);
    //	apagarInicio(&lista);
    //	apagarFim(&lista);
    //	apagarFim(&lista);
    //	apagarFim(&lista);
    //	apagarFim(&lista);
    apagarPosicao(&lista, 2);
    imprimir(&lista);
}

void inserirInicio(No **lista, int valor)
{

    No *novo = (No *)malloc(sizeof(No));
    novo->valor = valor;
    novo->proximo = NULL;

    if ((*lista) == NULL)
    {
        (*lista) = novo;
        novo->proximo = (*lista);
    }
    else
    {
        novo->proximo = (*lista)->proximo;
        (*lista)->proximo = novo;
    }
}

void inserirFim(No **lista, int valor)
{
    No *novo = (No *)malloc(sizeof(No));
    novo->valor = valor;
    novo->proximo = NULL;

    if ((*lista) == NULL)
    {
        (*lista) = novo;
        novo->proximo = (*lista);
    }
    else
    {
        novo->proximo = (*lista)->proximo;
        (*lista)->proximo = novo;
        (*lista) = novo;
    }
}

int tamanho(No **lista)
{
    No *auxiliar = (*lista)->proximo;
    int tam = 0;

    do
    {
        tam++;
        auxiliar = auxiliar->proximo;
    } while (auxiliar != (*lista)->proximo);

    return tam;
}
void inserirPosicao(No **lista, int valor, int pos)
{

    No *novo = (No *)malloc(sizeof(No));
    novo->valor = valor;
    novo->proximo = NULL;
    if (pos == 0)
    {
        inserirInicio(lista, valor);
    }
    else if (pos == tamanho(lista))
    {
        inserirFim(lista, valor);
    }
    else
    {
        if (pos <= tamanho(lista))
        {
            int i = 0;
            No *aux = (*lista)->proximo;
            while (pos - 1 > i)
            {
                aux = aux->proximo;
                i++;
            }
            novo->proximo = aux->proximo;
            aux->proximo = novo;
        }
        else
        {
            printf("posicao invalida!\n");
        }
    }
}

void apagarInicio(No **lista)
{
    if ((*lista) != NULL)
    {

        No *auxiliar = (*lista)->proximo;
        (*lista)->proximo = auxiliar->proximo;
        auxiliar->proximo = NULL;
        if ((*lista)->proximo == NULL)
        {
            (*lista) = NULL;
        }
        free(auxiliar);
    }
    else
    {
        printf("lista vazia\n");
    }
}

void apagarFim(No **lista)
{
    if ((*lista) != NULL)
    {
        No *auxiliar = (*lista)->proximo;
        No *auxiliar2;

        if ((*lista)->proximo == (*lista))
        {
            apagarInicio(lista);
        }
        else
        {
            while (auxiliar != (*lista))
            {
                auxiliar2 = auxiliar;
                auxiliar = auxiliar->proximo;
            }
            auxiliar2->proximo = (*lista)->proximo;
            (*lista) = auxiliar2;
            auxiliar->proximo = NULL;
            free(auxiliar);
        }
    }
}

//needs some fix
void apagarPosicao(No **lista, int pos)
{
    if ((*lista) != NULL)
    {
        if (pos == 0)
        {
            apagarInicio(lista);
        }
        else if (pos == tamanho(lista))
        {
            apagarFim(lista);
        }
        else if (pos < tamanho(lista) && pos > 0)
        {
            No *aux = (*lista);
            int i = 0;
            while (i < pos - 1)
            {
                aux = aux->proximo;
                i++;
            }

            No *aux2 = aux->proximo;
            aux->proximo = aux2->proximo;
            aux2->proximo = NULL;
            free(aux2);
        }
        else
        {
            printf("posicao invalida!\n");
        }
    }
}

void imprimir(No **lista)
{

    if ((*lista) != NULL)
    {
        No *auxiliar = (*lista)->proximo;

        do
        {
            printf("valor: %d\n", auxiliar->valor);
            auxiliar = auxiliar->proximo;
        } while (auxiliar != (*lista)->proximo);
    }
}