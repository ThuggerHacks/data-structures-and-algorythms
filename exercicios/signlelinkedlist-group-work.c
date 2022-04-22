#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//estrutura de dados
typedef struct Pessoa
{
    char nome[50];
    int idade;
    int sexo;
} Pessoa;

typedef struct No
{
    Pessoa pessoa;
    struct No *proximo;
} No;

//prototipo de funcoes da lista
No *inserirNoFimDaLista(No *lista, char nome[50], int idade, int sexo);
void imprimir(No *estrutura);
No *inserirNoInicioDaLista(No *lista, char nome[50], int idade, int sexo);
No *inserirEmUmaPosicaoDaLista(No *lista, int pos, char nome[50], int idade, int sexo);
No *removerNoInicioDaLista(No *lista);
No *removerNoFimDaLista(No *lista);
int tamanhoDaLista(No *lista);
No *removerEmUmaPosicaoDaLista(No *lista, int pos);

//prototipo de funcoes de pilha
No *inserirNaPilha(No *topo, char nome[50], int idade, int sexo);
int tamanhoDaPilha(No *topo);
No *eliminarDaPilha(No *topo);

//prototipo de funcoes de filas
No *inserirNaFila(No *tras, No *frente, char nome[50], int idade, int sexo);
No *removerDaFila(No *frente);

//prototipo de funcoes de manipulacao das estruturas de dado
void removerPrimos(No **pilha_F, No **lista);
int segundaMenorIdade(No **fila);
int menorIdade(No **fila);
void removerSegundoMenorDaFilaParaPilha(No **fila_frente, No **pilha);
//=========================================================

void main()
{

    //LISTAS
    No *listaA = NULL;
    //FILAS
    No *fila_B_frente = NULL;
    No *fila_B_tras = NULL;
    //PILHAS
    No *pilha_C = NULL;

    pilha_C = inserirNaPilha(pilha_C, "Braimo", 19, 1);
    pilha_C = inserirNaPilha(pilha_C, "Braimo1", 13, 1);
    pilha_C = inserirNaPilha(pilha_C, "Braimo2", 12, 1);
    pilha_C = inserirNaPilha(pilha_C, "Braimo3", 9, 0);
    pilha_C = inserirNaPilha(pilha_C, "Braimo4", 5, 1);
    removerPrimos(&pilha_C, &listaA);

    fila_B_frente = fila_B_tras = inserirNaFila(fila_B_tras, fila_B_frente, "Braimo", 10, 1);
    fila_B_tras = inserirNaFila(fila_B_tras, fila_B_frente, "Braimo2", 11, 1);
    fila_B_tras = inserirNaFila(fila_B_tras, fila_B_frente, "Braimo", 13, 1);
    fila_B_tras = inserirNaFila(fila_B_tras, fila_B_frente, "Braimo", 8, 0);
    removerSegundoMenorDaFilaParaPilha(&fila_B_frente, &pilha_C);
    imprimir(pilha_C);
}

//funcoes de lista
No *inserirNoFimDaLista(No *lista, char nome[50], int idade, int sexo)
{
    //criar novo no
    No *novo_no = (No *)malloc(sizeof(Pessoa));
    //atribuir valores
    novo_no->pessoa.idade = idade;
    novo_no->pessoa.sexo = sexo;
    strcpy(novo_no->pessoa.nome, nome);
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

No *inserirNoInicioDaLista(No *lista, char nome[50], int idade, int sexo)
{

    //criar novo no
    No *novo_no = (No *)malloc(sizeof(Pessoa));
    //inserir valores no novo no
    novo_no->pessoa.idade = idade;
    novo_no->pessoa.sexo = sexo;
    strcpy(novo_no->pessoa.nome, nome);
    novo_no->proximo = NULL;

    //conectar o novo no a raiz da lista
    novo_no->proximo = lista;
    lista = novo_no;

    //retornar a lista co o novo elemento
    return lista;
};

No *inserirEmUmaPosicaoDaLista(No *lista, int pos, char nome[50], int idade, int sexo)
{
    //criar novo no
    No *novo_no = (No *)malloc(sizeof(Pessoa));
    novo_no->pessoa.idade = idade;
    novo_no->pessoa.sexo = sexo;
    strcpy(novo_no->pessoa.nome, nome);
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
            lista = inserirNoInicioDaLista(lista, nome, idade, sexo);
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
void imprimir(No *estrutura)
{

    No *no = estrutura;

    while (no != NULL)
    {
        if (no->pessoa.sexo)
        {
            printf("nome: %s\nidade: %d\nsexo:Masculino\n\n", no->pessoa.nome, no->pessoa.idade);
        }
        else
        {
            printf("nome: %s\nidade: %d\nsexo:Femenino\n\n", no->pessoa.nome, no->pessoa.idade);
        }
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
No *inserirNaPilha(No *topo, char nome[50], int idade, int sexo)
{

    //criar alocacao na memoria
    No *novoelemento = (No *)malloc(sizeof(Pessoa));
    //inserir valores no novo no
    novoelemento->pessoa.idade = idade;
    novoelemento->pessoa.sexo = sexo;
    strcpy(novoelemento->pessoa.nome, nome);
    //atribuir o endereco do topo ao novo no
    novoelemento->proximo = topo;

    //atribuir o endereco do novo elemento ao topo
    topo = novoelemento;

    //retornar o elemento do topo
    return topo;
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

No *inserirNaFila(No *tras, No *frente, char nome[50], int idade, int sexo)
{
    //criar alocacao na memoria
    No *novo_no = (No *)malloc(sizeof(Pessoa));
    //inserir valores no novo no
    novo_no->pessoa.idade = idade;
    novo_no->pessoa.sexo = sexo;
    strcpy(novo_no->pessoa.nome, nome);
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

//funcoes para manipulacao das estruturas de dado acima
//copiar lista A para lista B

//funcao para dividir a pilha em duas partes iguais
int EhPrimo(int valor)
{
    int cont = 0;
    int loop = 1;

    while (loop <= valor)
    {
        if (valor % loop == 0)
        {
            cont++;
        }
        loop++;
    }

    if (cont == 2)
    {
        return 1;
    }

    return 0;
}
void removerPrimos(No **pilha_C, No **lista)
{
    No *pilha = (*pilha_C);
    No *pilha_nPrimos = NULL;

    while (pilha->proximo != NULL)
    {
        if (EhPrimo(pilha->pessoa.idade) != 1)
        {
            pilha_nPrimos = inserirNaPilha(pilha_nPrimos, pilha->pessoa.nome, pilha->pessoa.idade, pilha->pessoa.sexo);
        }
        else
        {
            (*lista) = inserirNoFimDaLista((*lista), pilha->pessoa.nome, pilha->pessoa.idade, pilha->pessoa.sexo);
        }
        pilha = pilha->proximo;
    }
    (*pilha_C) = pilha_nPrimos;
}

//funcao para encontrar o primeiro maior elemento de uma estrutura E

int menorIdade(No **fila)
{
    //pegar qualquer valor da pilha para ser o menor elemento, depois iremos substituir com o verdadeiro menor
    int menor = (*fila)->pessoa.idade;
    No *filaa = (*fila);
    //precorrer a pilha
    while (filaa)
    {
        //verificar se o valor atual da iteracao eh menor que o valor da variavel menor
        if (menor > filaa->pessoa.idade)
        {
            //caso seja verdadeiro a afirmacao acima, substituir o valor da variavelmenor pelo valor da iteracao
            menor = filaa->pessoa.idade;
        }
        //passar o ponteiro para o proximo elemmento
        filaa = filaa->proximo;
    }

    return menor;
}

int maiorElementoDaFila(No **fila)
{
    No *filaa = (*fila);
    //pegar qualquer elemento da pilha para ser o nosso maior elemento
    int maior = filaa->pessoa.idade;
    //precorrer a pilha
    while (filaa)
    {
        //verificar se o valor da variavel maior eh ou nao maior que o valor da iteracao
        if (maior < filaa->pessoa.idade)
        {
            //caso seja menor, substituir pelo valor maior
            maior = filaa->pessoa.idade;
        }
        //passar o ponteiro para a proxima iteracao
        filaa = filaa->proximo;
    }

    return maior;
}

int segundaMenorIdade(No **fila)
{
    int menor = menorIdade(fila);
    int segundoMenor = maiorElementoDaFila(fila);
    No *aux = (*fila);

    while (aux)
    {
        if (segundoMenor > aux->pessoa.idade && aux->pessoa.idade != menor)
        {
            segundoMenor = aux->pessoa.idade;
        }
        aux = aux->proximo;
    }

    return segundoMenor;
}

void removerSegundoMenorDaFilaParaPilha(No **fila_frente, No **pilha)
{

    No *pessoa = (*fila_frente);
    No *pessoa2 = NULL;
    int segunda_menor_idade = segundaMenorIdade(fila_frente);

    while (pessoa != NULL)
    {
        if (pessoa->pessoa.idade == segunda_menor_idade)
        {
            (*pilha) = inserirNaPilha((*pilha), pessoa->pessoa.nome, pessoa->pessoa.idade, pessoa->pessoa.sexo);
        }
        else
        {
            pessoa2 = inserirNoFimDaLista(pessoa2, pessoa->pessoa.nome, pessoa->pessoa.idade, pessoa->pessoa.sexo);
        }

        pessoa = pessoa->proximo;
    }
    (*fila_frente) = pessoa2;
}