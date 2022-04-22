#include <stdio.h>
#include <stdlib.h>

typedef struct No
{
    int idade;
    struct No *proximo;

} No;
No *inserirNoInicio(No *lista, int idade);
void imprimirLista(No *lista);
No *inserirNoFinal(No *lista, int idade);
No *eliminarNoInicio(No *lista);
No *eliminarNoFim(No *lista);
int tamanho(No *lista);
No *inserir(No *lista, int idade, int posicao);
No *remover(No *lista, int pos);

void main()
{
    No *lista = NULL;
    int idade;

    while (1)
    {
        printf("insira a idade\n");
        scanf("%d", &idade);
        if (idade < 0)
        {
            break;
        }
        lista = inserirNoFinal(lista, idade);
    }

    // printf("insira a idade e a posicao");
    // int pos;
    // scanf("%d", &idade);
    // scanf("%d", &pos);
    // lista = inserir(lista, idade, pos);

    // lista = eliminarNoInicio(lista);
    // lista = eliminarNoInicio(lista);
    // lista = eliminarNoFim(lista);
    // lista = eliminarNoFim(lista);

    lista = remover(lista, 2);
    imprimirLista(lista);
    // printf("\ntamanho: %d", tamanho(lista));
}

void imprimirLista(No *lista)
{
    No *auxiliar = lista;

    while (auxiliar != NULL)
    {
        printf("idade: %d ", auxiliar->idade);
        auxiliar = auxiliar->proximo;
    }
}

No *inserirNoInicio(No *lista, int idade)
{

    No *novoelemento = (No *)malloc(sizeof(No));
    novoelemento->idade = idade;
    novoelemento->proximo = lista;
    lista = novoelemento;

    return lista;
}

No *inserirNoFinal(No *lista, int idade)
{
    No *novoelemento = (No *)malloc(sizeof(No));
    novoelemento->idade = idade;
    novoelemento->proximo = NULL;

    if (lista == NULL)
    {
        lista = novoelemento;
    }
    else
    {
        No *auxiliar = lista;
        while (auxiliar->proximo != NULL)
        {
            auxiliar = auxiliar->proximo;
        }
        auxiliar->proximo = novoelemento;
    }

    return lista;
}

No *eliminarNoInicio(No *lista)
{
    No *auxiliar = lista;
    lista = lista->proximo;
    auxiliar->proximo = NULL;
    free(auxiliar);

    return lista;
}

No *eliminarNoFim(No *lista)
{
    No *auxiliar = lista;
    No *auxiliar2;

    while (auxiliar->proximo != NULL)
    {
        auxiliar2 = auxiliar;
        auxiliar = auxiliar->proximo;
    }

    auxiliar2->proximo = NULL;
    free(auxiliar);

    return lista;
}

int tamanho(No *lista)
{
    No *auxiliar = lista;
    int c = 0;

    while (auxiliar != NULL)
    {
        auxiliar = auxiliar->proximo;
        c++;
    }

    return c;
}
No *inserir(No *lista, int idade, int posicao)
{
    No *novoelemento = (No *)malloc(sizeof(No));
    novoelemento->idade = idade;
    novoelemento->proximo = NULL;

    if (posicao >= 0 && posicao <= tamanho(lista))
    {
        No *auxiliar = lista;
        No *auxiliar2;
        int i = 0;

        if (posicao == 0)
        {
            lista = inserirNoInicio(lista, idade);
        }
        else
        {
            while (i < posicao - 1)
            {
                auxiliar = auxiliar->proximo;
                i++;
            }
            novoelemento->proximo = auxiliar->proximo;
            auxiliar->proximo = novoelemento;
        }
    }

    return lista;
}

No *remover(No *lista, int pos)
{
    No *auxiliar = lista;
    No *auxiliar2;
    int i = 0;
    while (i < pos - 1)
    {
        auxiliar = auxiliar->proximo;
        i++;
    }
    auxiliar2 = auxiliar->proximo;
    auxiliar = auxiliar2->proximo;
    auxiliar2->proximo = NULL;
    free(auxiliar2);
    return lista;
}