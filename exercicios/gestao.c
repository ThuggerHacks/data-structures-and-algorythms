#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Padaria
{
    char tipoPao[50];
    int id_padaria;
    double preco;
} Padaria;

typedef struct Funcionario
{
    char nome[50];
    double salario;
    char funcao[50];
    double quantidadeVendida;
    int id_funcionario;
} Funcionario;

typedef struct NoPadaria
{
    struct NoPadaria *esquerda;
    struct NoPadaria *direita;
    struct Padaria padaria;
} NoPadaria;

typedef struct NoFuncionario
{
    struct NoFuncionario *esquerda;
    struct NoFuncionario *direita;
    struct Funcionario funcionario;
} NoFuncionario;

void imprimirPao(NoPadaria *padaria);
void imprimirFuncionario(NoFuncionario *funcionario);
NoFuncionario *inserirFuncionario(NoFuncionario *funcionario, double salario, char nome[50], char funcao[50], int id);
NoPadaria *inserirPao(NoPadaria *padaria, char tipo_pao[50], int id, double preco);
NoPadaria *venderPao(NoPadaria *padaria, NoFuncionario **funcionario, int id_pao, int id_vendedor);
NoFuncionario *apagarFuncionario(NoFuncionario *funcionario, int id);

int quantidadePao = 0;

void main()
{

    NoPadaria *pao = NULL;
    NoFuncionario *funcionario = NULL;

    int i = 1;
inicio:
    while (i)
    {
        printf("digite:\n1- para inserir pao\n2-para inserir funcionario\n3-para vender pao\n4-para ver quantidade de paes\n5-para ver paes\n6-para ver funcionarios\n7-para sair\n");

        int opcao;
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            printf("digite o tipo de pao\n");
            char tipo_pao[50];
            scanf("%s", tipo_pao);
            printf("digite o id\n");
            int id;
            scanf("%d", &id);
            printf("digite o preco");
            float preco;
            scanf("%f", &preco);
            pao = inserirPao(pao, tipo_pao, id, preco);
            printf("inserido com sucesso\n digite 1 para voltar e 2 para sair");
            int op;
            scanf("%d", &op);
            if (op == 2)
            {
                i = 0;
            }
            else if (op == 1)
            {
                goto inicio;
            }
            else
            {
                printf("opcao invalida\n");
                i = 0;
            }
            break;

        case 2:
            printf("digite o id do funcionario\n");
            scanf("%d", &id);
            printf("digite o nome do funcionario\n");
            char nome[50];
            scanf("%s", nome);
            printf("digite o salario\n");
            float salario;
            scanf("%f", &salario);
            printf("digite a funcao\n");
            char funcao[50];
            scanf("%s", funcao);
            funcionario = inserirFuncionario(funcionario, salario, nome, funcao, id);
            printf("funcionario inserido com sucesso\n digite 1 para voltar ou 2 para sair\n");
            scanf("%d", &op);
            if (op == 1)
            {
                goto inicio;
            }
            else if (op == 2)
            {
                i = 0;
            }
            else
            {
                printf("opcao invalida\n");
                i = 0;
            }

            break;

        case 3:
            printf("digite o id do vendedor\n");
            int id_vendedor;
            scanf("%d", &id_vendedor);
            printf("digite o id do pao\n");
            int id_pao;
            scanf("%d", &id_pao);
            pao = venderPao(pao, &funcionario, id_pao, id_vendedor);
            printf("vendido com sucesso\n digite 1 para voltar e 2 para sair");
            scanf("%d", &op);
            if (op == 2)
            {
                i = 0;
            }
            else if (op == 1)
            {
                goto inicio;
            }
            else
            {
                printf("opcao invalida\n");
                i = 0;
            }
            break;
        case 4:
            printf("Quantidade: %d\n", quantidadePao);
            printf("vendido com sucesso\n digite 1 para voltar e 2 para sair");
            scanf("%d", &op);
            if (op == 2)
            {
                i = 0;
            }
            else if (op == 1)
            {
                goto inicio;
            }
            else
            {
                printf("opcao invalida\n");
                i = 0;
            }
            break;
        case 5:
            imprimirPao(pao);
            printf("digite 1 para voltar ou 2 para sair\n");
            scanf("%d", &op);
            if (op == 2)
            {
                i = 0;
            }
            else if (op == 1)
            {
                goto inicio;
            }
            else
            {
                printf("opcao invalida\n");
                i = 0;
            }
            break;
        case 6:
            imprimirFuncionario(funcionario);
            printf("digite 1 para voltar ou 2 para sair\n");
            scanf("%d", &op);
            if (op == 2)
            {
                i = 0;
            }
            else if (op == 1)
            {
                goto inicio;
            }
            else
            {
                printf("opcao invalida\n");
                i = 0;
            }
            break;
        case 7:
            i = 0;
        default:
            printf("opcao invalida\n");
            i = 0;
        }
    }
}

NoFuncionario *pesquisarFuncionario(NoFuncionario *funcionario, int id)
{
    if (funcionario != NULL)
    {
        if (funcionario->funcionario.id_funcionario > id)
        {
            return pesquisarFuncionario(funcionario->esquerda, id);
        }
        else if (funcionario->funcionario.id_funcionario < id)
        {
            return pesquisarFuncionario(funcionario->direita, id);
        }
        else
        {
            return funcionario;
        }
    }
}

NoFuncionario *atualizarFuncionarioQuantidadeVendida(NoFuncionario *funcionario, int id, int quantidadeVendida)
{
    if (pesquisarFuncionario(funcionario, id))
    {
        NoFuncionario *aux = funcionario;
        aux = pesquisarFuncionario(funcionario, id);
        aux->funcionario.quantidadeVendida = quantidadeVendida + aux->funcionario.quantidadeVendida;

        return aux;
    }
    else
    {
        printf("O funcionario nao existe\n");
    }
}

NoFuncionario *inserirFuncionario(NoFuncionario *funcionario, double salario, char nome[50], char funcao[50], int id)
{

    if (pesquisarFuncionario(funcionario, id))
    {
        printf("funcionario com o id: %d ja existe.\n", id);
    }
    else
    {

        NoFuncionario *novo_funcionario = (NoFuncionario *)malloc(sizeof(NoFuncionario));
        novo_funcionario->funcionario.salario = salario;
        strcpy(novo_funcionario->funcionario.nome, nome);
        strcpy(novo_funcionario->funcionario.funcao, funcao);
        novo_funcionario->funcionario.id_funcionario = id;
        novo_funcionario->funcionario.quantidadeVendida = 0;
        novo_funcionario->esquerda = NULL;
        novo_funcionario->direita = NULL;

        if (funcionario == NULL)
        {
            funcionario = novo_funcionario;
        }
        else
        {
            if (funcionario->funcionario.id_funcionario >= id)
            {
                funcionario->esquerda = inserirFuncionario(funcionario->esquerda, salario, nome, funcao, id);
            }
            else
            {
                funcionario->direita = inserirFuncionario(funcionario->direita, salario, nome, funcao, id);
            }
        }
    }

    return funcionario;
}

NoFuncionario *minimoValorDireitaFuncionario(NoFuncionario *funcionario)
{

    NoFuncionario *aux = funcionario;

    while (aux->esquerda)
    {
        aux = aux->esquerda;
    }

    return aux;
}
NoFuncionario *apagarFuncionario(NoFuncionario *funcionario, int id)
{
    if (funcionario != NULL)
    {
        if (funcionario->funcionario.id_funcionario > id)
        {
            funcionario->esquerda = apagarFuncionario(funcionario->esquerda, id);
        }
        else if (funcionario->funcionario.id_funcionario < id)
        {
            funcionario->direita = apagarFuncionario(funcionario->direita, id);
        }
        else
        {
            if (funcionario->direita == NULL && funcionario->esquerda == NULL)
            {
                free(funcionario);
                return NULL;
            }
            else if (funcionario->direita == NULL)
            {
                NoFuncionario *temp = funcionario->esquerda;
                free(funcionario);
                return temp;
            }
            else if (funcionario->direita == NULL)
            {
                NoFuncionario *temp = funcionario->esquerda;
                free(funcionario);
                return temp;
            }

            NoFuncionario *temp = minimoValorDireitaFuncionario(funcionario->direita);
            funcionario->funcionario.quantidadeVendida = temp->funcionario.quantidadeVendida;
            funcionario->funcionario.salario = temp->funcionario.salario;
            strcpy(funcionario->funcionario.nome, temp->funcionario.nome);
            strcpy(funcionario->funcionario.funcao, temp->funcionario.funcao);
            funcionario->direita = apagarFuncionario(funcionario->direita, temp->funcionario.id_funcionario);
        }
    }

    return funcionario;
}

NoPadaria *pesquisarPao(NoPadaria *padaria, int id)
{
    if (padaria != NULL)
    {
        if (padaria->padaria.id_padaria > id)
        {
            return pesquisarPao(padaria->esquerda, id);
        }
        else if (padaria->padaria.id_padaria < id)
        {
            return pesquisarPao(padaria->direita, id);
        }
        else
        {
            return padaria;
        }
    }
}

NoPadaria *inserirPao(NoPadaria *padaria, char tipo_pao[50], int id, double preco)
{
    if (pesquisarPao(padaria, id))
    {
        printf("O id do pao: %d  ja existe.\n", id);
    }
    else
    {
        NoPadaria *novo_pao = (NoPadaria *)malloc(sizeof(NoPadaria));
        novo_pao->padaria.id_padaria = id;
        strcpy(novo_pao->padaria.tipoPao, tipo_pao);
        novo_pao->padaria.preco = preco;
        novo_pao->esquerda = NULL;
        novo_pao->direita = NULL;

        if (padaria == NULL)
        {
            padaria = novo_pao;
        }
        else
        {
            if (padaria->padaria.id_padaria >= id)
            {
                padaria->esquerda = inserirPao(padaria->esquerda, tipo_pao, id, preco);
            }
            else
            {
                padaria->direita = inserirPao(padaria->direita, tipo_pao, id, preco);
            }
        }
        quantidadePao++;
    }

    return padaria;
}

NoPadaria *minimoValorDireitaPao(NoPadaria *padaria)
{
    if (padaria != NULL)
    {
        NoPadaria *aux = padaria;
        while (aux->esquerda)
        {
            aux = aux->esquerda;
        }

        return aux;
    }
}
NoPadaria *apagarPao(NoPadaria *padaria, int id_pao)
{

    if (padaria != NULL)
    {
        if (padaria->padaria.id_padaria > id_pao)
        {
            padaria->esquerda = apagarPao(padaria->esquerda, id_pao);
        }
        else if (padaria->padaria.id_padaria < id_pao)
        {
            padaria->direita = apagarPao(padaria->direita, id_pao);
        }
        else
        {
            if (padaria->direita == NULL && padaria->esquerda == NULL)
            {
                free(padaria);
                return NULL;
            }
            else if (padaria->direita == NULL)
            {
                NoPadaria *temp = padaria->esquerda;
                free(padaria);
                return temp;
            }
            else if (padaria->esquerda == NULL)
            {
                NoPadaria *temp = padaria->direita;
                free(padaria);
                return temp;
            }

            NoPadaria *temp = minimoValorDireitaPao(padaria->direita);
            padaria->padaria.preco = temp->padaria.preco;
            strcpy(padaria->padaria.tipoPao, temp->padaria.tipoPao);
            padaria->direita = apagarPao(padaria->direita, temp->padaria.id_padaria);
        }
    }
    return padaria;
};

NoPadaria *venderPao(NoPadaria *padaria, NoFuncionario **funcionario, int id_pao, int id_vendedor)
{
    if (padaria == NULL)
    {
        printf("a padaria esta sem pao.\n");
    }
    else if (!pesquisarPao(padaria, id_pao))
    {
        printf("o pao especificado esta indisponivel.\n");
    }
    else
    {
        if (pesquisarFuncionario((*funcionario), id_vendedor))
        {
            padaria = apagarPao(padaria, id_pao);
            atualizarFuncionarioQuantidadeVendida((*funcionario), id_vendedor, 1);
            quantidadePao--;
            printf("pao %d vendido com sucesso.\n", id_pao);
        }
        else
        {
            printf("O funcionario nao existe\n");
        }
    }

    return padaria;
}

void imprimirPao(NoPadaria *padaria)
{
    if (padaria == NULL)
        return;
    imprimirPao(padaria->esquerda);
    printf("tipo de pao: %s, preco do pao: %.2f, id do pao: %d\n", padaria->padaria.tipoPao, padaria->padaria.preco, padaria->padaria.id_padaria);
    imprimirPao(padaria->direita);
}

void imprimirFuncionario(NoFuncionario *funcionario)
{
    if (funcionario == NULL)
        return;

    imprimirFuncionario(funcionario->esquerda);
    printf("nome: %s, salario: %.2f, funcao: %s, quantidadeVendida: %.2f, id: %d\n", funcionario->funcionario.nome, funcionario->funcionario.salario, funcionario->funcionario.funcao, funcionario->funcionario.quantidadeVendida, funcionario->funcionario.id_funcionario);
    imprimirFuncionario(funcionario->direita);
}