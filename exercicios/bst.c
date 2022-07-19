#include <stdlib.h>
#include <stdio.h>

typedef struct No
{
    int valor;
    struct No *direita;
    struct No *esquerda;
} No;

No *inserir(No *raiz, int valor);
void imprimirSemOrdem(No *raiz);
void imprimirEmOrdemDecrescente(No *raiz);
void imprimirEmOrdemCrescente(No *raiz);
No *pesquisar(No *raiz, int valor);
No *atualizar(No *raiz, int valor, int valor2);
No *apagar(No *raiz, int valor);
No *menorValorDireita(No *elemento);

void main()
{
    No *raiz = NULL;
    raiz = inserir(raiz, 100);
    raiz = inserir(raiz, 9);
    raiz = inserir(raiz, 55);
    raiz = inserir(raiz, 8);
    raiz = inserir(raiz, 4);
    raiz = inserir(raiz, 12);
    // raiz = atualizar(raiz, 8, 400);
    raiz = apagar(raiz, 9);
    imprimirEmOrdemCrescente(raiz);

    /*
        100
        / \
       9   55
      / \  
     8   12   
    /
   4
    
    */
}

No *inserir(No *raiz, int valor)
{
    No *novo = (No *)malloc(sizeof(No));
    novo->direita = NULL;
    novo->esquerda = NULL;
    novo->valor = valor;
    if (raiz == NULL)
    {
        raiz = novo;
    }
    else
    {
        if (raiz->valor >= valor)
        {
            raiz->esquerda = inserir(raiz->esquerda, valor);
        }
        else
        {
            raiz->direita = inserir(raiz->direita, valor);
        }
    }

    return raiz;
}

No *pesquisar(No *raiz, int valor)
{
    if (raiz)
    {
        if (raiz->valor > valor)
        {
            return pesquisar(raiz->esquerda, valor);
        }
        else if (raiz->valor < valor)
        {
            return pesquisar(raiz->direita, valor);
        }
        else
        {
            return raiz;
        }
    }
}

No *atualizar(No *raiz, int valor, int valor2)
{

    No *aux = raiz;
    if (pesquisar(raiz, valor))
    {
        aux = pesquisar(raiz, valor);
        aux->valor = valor2;

        return raiz;
    }
}

No *menorValorDireita(No *elemento)
{

    No *auxiliar = elemento;

    while (elemento->esquerda)
    {
        auxiliar = auxiliar->esquerda;
    }

    return auxiliar;
}

No *apagar(No *raiz, int valor)
{
    if (raiz != NULL)
    {
        if (raiz->valor > valor)
        {
            raiz->esquerda = apagar(raiz->esquerda, valor);
        }
        else if (raiz->valor < valor)
        {
            raiz->direita = apagar(raiz->direita, valor);
        }
        else
        {
            if (raiz->direita == NULL && raiz->esquerda == NULL)
            {
                free(raiz);

                return NULL;
            }
            else if (raiz->direita == NULL)
            {
                No *auxiliar = raiz->esquerda;
                free(raiz);
                return auxiliar;
            }
            else if (raiz->esquerda == NULL)
            {
                No *auxiliar = raiz->direita;
                free(raiz);
                return auxiliar;
            }
            else
            {

                No *menorDireita = menorValorDireita(raiz->direita);
                raiz->valor = menorDireita->valor;
                raiz->direita = apagar(raiz->direita, menorDireita->valor);
            }
        }
    }

    return raiz;
}

void imprimirEmOrdemCrescente(No *raiz)
{
    if (raiz == NULL)
        return;
    imprimirEmOrdemCrescente(raiz->esquerda);
    printf("%d\n", raiz->valor);
    imprimirEmOrdemCrescente(raiz->direita);
}

void imprimirEmOrdemDecrescente(No *raiz)
{
    if (raiz == NULL)
        return;
    printf("%d\n", raiz->valor);
    imprimirEmOrdemDecrescente(raiz->esquerda);
    imprimirEmOrdemDecrescente(raiz->direita);
}

void imprimirSemOrdem(No *raiz)
{
    if (raiz == NULL)
        return;
    imprimirSemOrdem(raiz->esquerda);
    imprimirSemOrdem(raiz->direita);
    printf("%d\n", raiz->valor);
}