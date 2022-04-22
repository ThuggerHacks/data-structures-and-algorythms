#include <stdio.h>
#include <stdlib.h>

typedef struct No
{
    int valor;
    struct No *proximo;
} No;

No *inserir(No *tras, No *frente, int valor);
void mostrar(No *tras);
No *remover(No *frente);

void main()
{
    No *frente, *tras;
    frente = tras = inserir(tras, frente, 10);
    tras = inserir(tras, frente, 12);
    tras = inserir(tras, frente, 15);
    tras = inserir(tras, frente, 25);
    // frente = remover(frente);
    // frente = remover(frente);
    mostrar(frente);
}

No *inserir(No *tras, No *frente, int valor)
{
    No *temp = (No *)malloc(sizeof(No));
    temp->valor = valor;
    temp->proximo = NULL;

    if (frente == NULL && tras == NULL)
    {
        frente = tras = temp;
    }
    else
    {
        tras->proximo = temp;
        tras = temp;
    }

    return tras;
}

No *remover(No *frente)
{
    No *temp = frente;
    No *q = temp;

    if (frente != NULL)
    {
        temp = temp->proximo;
        q->proximo = NULL;
        free(q);
    }

    return temp;
}

void mostrar(No *frente)
{
    No *temp = frente;

    while (temp != NULL)
    {
        printf("valor: %d\n", temp->valor);
        temp = temp->proximo;
    }
}