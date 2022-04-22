#include <stdio.h>
#include <stdlib.h>

typedef struct No
{
    int idade;
    struct No *proximo;
} No;

No *inserir(No *topo, int idade);
void mostrar(No *topo);
No *eliminar(No *topo);

int main()
{
    No *topo = NULL;
    topo = inserir(topo, 10);
    topo = inserir(topo, 12);
    topo = inserir(topo, 15);
    topo = eliminar(topo);
    mostrar(topo);
    return 0;
}

No *inserir(No *topo, int idade)
{

    No *novoelemento = (No *)malloc(sizeof(No));
    novoelemento->idade = idade;
    novoelemento->proximo = topo;

    topo = novoelemento;

    return topo;
}

void mostrar(No *topo)
{

    No *auxiliar = topo;
    while (auxiliar != NULL)
    {
        printf("idade: %d\n", auxiliar->idade);
        auxiliar = auxiliar->proximo;
    }
}

No *eliminar(No *topo)
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