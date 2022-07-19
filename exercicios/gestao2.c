#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Grafica
{
    char tipoCartaz[90];
    int id_cartaz;
    double preco;
} Grafica;

typedef struct Vendedor
{
    char nome[90];
    double salario;
    char funcao[90];
    double quantidadeVendida;
    int id_vendedor;
} Vendedor;

typedef struct ArvoreGrafica
{
    struct ArvoreGrafica *esquerda;
    struct ArvoreGrafica *direita;
    struct Grafica grafica;
} ArvoreGrafica;

typedef struct ArvoreVendedor
{
    struct ArvoreVendedor *esquerda;
    struct ArvoreVendedor *direita;
    struct Vendedor vendedor;
} ArvoreVendedor;

void imprimirCartzes(ArvoreGrafica *grafica);
void imprimirVendedor(ArvoreVendedor *vendedor);
ArvoreVendedor *inserirVendedor(ArvoreVendedor *vendedor, double salario, char nome[90], char funcao[90], int id);
ArvoreGrafica *inserirCartazes(ArvoreGrafica *grafica, char tipo_cartaz[90], int id, double preco);
ArvoreGrafica *venderCartaz(ArvoreGrafica *grafica, ArvoreVendedor **vendedor, int id_cartaz, int id_vendedor);
ArvoreVendedor *apagarCartaz(ArvoreVendedor *vendedor, int id);

void main()
{

    ArvoreGrafica *cartaz = NULL;
    ArvoreVendedor *vendedor = NULL;

    int condicao = 1;
cartaz:
    while (condicao)
    {
        printf("\n1-inserir cartaz\n2-inserir vendedor\n3-vender cartaz\n5-ver cartaz\n6-para ver vendedores\n7-sair\n");

        int opcao;
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            printf("digite o tipo de cartaz\n");
            char tipo_cartaz[90];
            scanf("%s", tipo_cartaz);
            printf("digite o id\n");
            int id;
            scanf("%d", &id);
            printf("digite o preco");
            float preco;
            scanf("%f", &preco);
            cartaz = inserirCartazes(cartaz, tipo_cartaz, id, preco);
            printf("inserido com sucesso\n digite 1 para voltar e 2 para sair");
            int opcao2;
            scanf("%d", &opcao2);
            if (opcao2 == 2)
            {
                condicao = 0;
            }
            else if (opcao2 == 1)
            {
                goto cartaz;
            }
            else
            {
                printf("opcao invalida\n");
                condicao = 0;
            }
            break;

        case 2:
            printf("digite o id do vendedor\n");
            scanf("%d", &id);
            printf("digite o nome do vendedor\n");
            char nome[90];
            scanf("%s", nome);
            printf("digite o salario\n");
            float salario;
            scanf("%f", &salario);
            printf("digite a funcao\n");
            char funcao[90];
            scanf("%s", funcao);
            vendedor = inserirVendedor(vendedor, salario, nome, funcao, id);
            printf("vendedor inserido com sucesso\n digite 1 para voltar ou 2 para sair\n");
            scanf("%d", &opcao2);
            int opcao2;
            scanf("%d", &opcao2);
            if (opcao2 == 2)
            {
                condicao = 0;
            }
            else if (opcao2 == 1)
            {
                goto cartaz;
            }
            else
            {
                printf("opcao invalida\n");
                condicao = 0;
            }

            break;

        case 3:
            printf("digite o id do vendedor\n");
            int id_vendedor;
            scanf("%d", &id_vendedor);
            printf("digite o id do cartaz\n");
            int id_cartaz;
            scanf("%d", &id_cartaz);
            cartaz = venderCartaz(cartaz, &vendedor, id_cartaz, id_vendedor);
            printf("vendido com sucesso\n digite 1 para voltar e 2 para sair");
            scanf("%d", &opcao2);
            int opcao2;
            scanf("%d", &opcao2);
            if (opcao2 == 2)
            {
                condicao = 0;
            }
            else if (opcao2 == 1)
            {
                goto cartaz;
            }
            else
            {
                printf("opcao invalida\n");
                condicao = 0;
            }
            break;
        case 4:
            imprimirCartzes(cartaz);
            printf("digite 1 para voltar ou 2 para sair\n");
            scanf("%d", &opcao2);
            int opcao2;
            scanf("%d", &opcao2);
            if (opcao2 == 2)
            {
                condicao = 0;
            }
            else if (opcao2 == 1)
            {
                goto cartaz;
            }
            else
            {
                printf("opcao invalida\n");
                condicao = 0;
            }
            break;
        case 5:
            imprimirVendedor(vendedor);
            printf("digite 1 para voltar ou 2 para sair\n");
            scanf("%d", &opcao2);
            int opcao2;
            scanf("%d", &opcao2);
            if (opcao2 == 2)
            {
                condicao = 0;
            }
            else if (opcao2 == 1)
            {
                goto cartaz;
            }
            else
            {
                printf("opcao invalida\n");
                condicao = 0;
            }
            break;
        case 6:
            condicao = 0;
        default:
            printf("opcao invalida\n");
            condicao = 0;
        }
    }
}

ArvoreVendedor *pesquisarVendedor(ArvoreVendedor *vendedor, int id)
{
    if (vendedor != NULL)
    {
        if (vendedor->vendedor.id_vendedor > id)
        {
            return pesquisarVendedor(vendedor->esquerda, id);
        }
        else if (vendedor->vendedor.id_vendedor < id)
        {
            return pesquisarVendedor(vendedor->direita, id);
        }
        else
        {
            return vendedor;
        }
    }
}

ArvoreVendedor *atualizarVendedorQuantidadeVendida(ArvoreVendedor *vendedor, int id, int quantidadeVendida)
{
    if (pesquisarVendedor(vendedor, id))
    {
        ArvoreVendedor *aux = vendedor;
        aux = pesquisarVendedor(vendedor, id);
        aux->vendedor.quantidadeVendida = quantidadeVendida + aux->vendedor.quantidadeVendida;

        return aux;
    }
    else
    {
        printf("O vendedor nao existe\n");
    }
}

ArvoreVendedor *inserirVendedor(ArvoreVendedor *vendedor, double salario, char nome[90], char funcao[90], int id)
{

    if (pesquisarVendedor(vendedor, id))
    {
        printf("vendedor com o id: %d ja existe.\n", id);
    }
    else
    {

        ArvoreVendedor *novo_vendedor = (ArvoreVendedor *)malloc(sizeof(ArvoreVendedor));
        novo_vendedor->vendedor.salario = salario;
        strcpy(novo_vendedor->vendedor.nome, nome);
        strcpy(novo_vendedor->vendedor.funcao, funcao);
        novo_vendedor->vendedor.id_vendedor = id;
        novo_vendedor->vendedor.quantidadeVendida = 0;
        novo_vendedor->esquerda = NULL;
        novo_vendedor->direita = NULL;

        if (vendedor == NULL)
        {
            vendedor = novo_vendedor;
        }
        else
        {
            if (vendedor->vendedor.id_vendedor >= id)
            {
                vendedor->esquerda = inserirVendedor(vendedor->esquerda, salario, nome, funcao, id);
            }
            else
            {
                vendedor->direita = inserirVendedor(vendedor->direita, salario, nome, funcao, id);
            }
        }
    }

    return vendedor;
}

ArvoreVendedor *minimoValorDireitaVendedor(ArvoreVendedor *vendedor)
{

    ArvoreVendedor *aux = vendedor;

    while (aux->esquerda)
    {
        aux = aux->esquerda;
    }

    return aux;
}
ArvoreVendedor *apagarCartaz(ArvoreVendedor *vendedor, int id)
{
    if (vendedor != NULL)
    {
        if (vendedor->vendedor.id_vendedor > id)
        {
            vendedor->esquerda = apagarCartaz(vendedor->esquerda, id);
        }
        else if (vendedor->vendedor.id_vendedor < id)
        {
            vendedor->direita = apagarCartaz(vendedor->direita, id);
        }
        else
        {
            if (vendedor->direita == NULL && vendedor->esquerda == NULL)
            {
                free(vendedor);
                return NULL;
            }
            else if (vendedor->direita == NULL)
            {
                ArvoreVendedor *temp = vendedor->esquerda;
                free(vendedor);
                return temp;
            }
            else if (vendedor->direita == NULL)
            {
                ArvoreVendedor *temp = vendedor->esquerda;
                free(vendedor);
                return temp;
            }

            ArvoreVendedor *temp = minimoValorDireitaVendedor(vendedor->direita);
            vendedor->vendedor.quantidadeVendida = temp->vendedor.quantidadeVendida;
            vendedor->vendedor.salario = temp->vendedor.salario;
            strcpy(vendedor->vendedor.nome, temp->vendedor.nome);
            strcpy(vendedor->vendedor.funcao, temp->vendedor.funcao);
            vendedor->direita = apagarCartaz(vendedor->direita, temp->vendedor.id_vendedor);
        }
    }

    return vendedor;
}

ArvoreGrafica *pesuisarCartaz(ArvoreGrafica *grafica, int id)
{
    if (grafica != NULL)
    {
        if (grafica->grafica.id_cartaz > id)
        {
            return pesuisarCartaz(grafica->esquerda, id);
        }
        else if (grafica->grafica.id_cartaz < id)
        {
            return pesuisarCartaz(grafica->direita, id);
        }
        else
        {
            return grafica;
        }
    }
}

ArvoreGrafica *inserirCartazes(ArvoreGrafica *grafica, char tipo_cartaz[90], int id, double preco)
{
    if (pesuisarCartaz(grafica, id))
    {
        printf("O id do cartaz: %d  ja existe.\n", id);
    }
    else
    {
        ArvoreGrafica *novo_cartaz = (ArvoreGrafica *)malloc(sizeof(ArvoreGrafica));
        novo_cartaz->grafica.id_cartaz = id;
        strcpy(novo_cartaz->grafica.tipoCartaz, tipo_cartaz);
        novo_cartaz->grafica.preco = preco;
        novo_cartaz->esquerda = NULL;
        novo_cartaz->direita = NULL;

        if (grafica == NULL)
        {
            grafica = novo_cartaz;
        }
        else
        {
            if (grafica->grafica.id_cartaz >= id)
            {
                grafica->esquerda = inserirCartazes(grafica->esquerda, tipo_cartaz, id, preco);
            }
            else
            {
                grafica->direita = inserirCartazes(grafica->direita, tipo_cartaz, id, preco);
            }
        }
    }

    return grafica;
}

ArvoreGrafica *minimoValorDireitaGrafica(ArvoreGrafica *grafica)
{
    if (grafica != NULL)
    {
        ArvoreGrafica *aux = grafica;
        while (aux->esquerda)
        {
            aux = aux->esquerda;
        }

        return aux;
    }
}
ArvoreGrafica *apagarCartaz(ArvoreGrafica *grafica, int id_cartaz)
{

    if (grafica != NULL)
    {
        if (grafica->grafica.id_cartaz > id_cartaz)
        {
            grafica->esquerda = apagarCartaz(grafica->esquerda, id_cartaz);
        }
        else if (grafica->grafica.id_cartaz < id_cartaz)
        {
            grafica->direita = apagarCartaz(grafica->direita, id_cartaz);
        }
        else
        {
            if (grafica->direita == NULL && grafica->esquerda == NULL)
            {
                free(grafica);
                return NULL;
            }
            else if (grafica->direita == NULL)
            {
                ArvoreGrafica *temp = grafica->esquerda;
                free(grafica);
                return temp;
            }
            else if (grafica->esquerda == NULL)
            {
                ArvoreGrafica *temp = grafica->direita;
                free(grafica);
                return temp;
            }

            ArvoreGrafica *temp = minimoValorDireitaGrafica(grafica->direita);
            grafica->grafica.preco = temp->grafica.preco;
            strcpy(grafica->grafica.tipoCartaz, temp->grafica.tipoCartaz);
            grafica->direita = apagarCartaz(grafica->direita, temp->grafica.id_cartaz);
        }
    }
    return grafica;
};

ArvoreGrafica *venderCartaz(ArvoreGrafica *grafica, ArvoreVendedor **vendedor, int id_cartaz, int id_vendedor)
{
    if (grafica == NULL)
    {
        printf("a grafica esta sem cartaz.\n");
    }
    else if (!pesuisarCartaz(grafica, id_cartaz))
    {
        printf("o cartaz especificado esta indisponivel.\n");
    }
    else
    {
        if (pesquisarVendedor((*vendedor), id_vendedor))
        {
            grafica = apagarCartaz(grafica, id_cartaz);
            atualizarVendedorQuantidadeVendida((*vendedor), id_vendedor, 1);
            printf("cartaz %d vendido com sucesso.\n", id_cartaz);
        }
        else
        {
            printf("O vendedor nao existe\n");
        }
    }

    return grafica;
}

void imprimirCartzes(ArvoreGrafica *grafica)
{
    if (grafica == NULL)
        return;
    imprimirCartzes(grafica->esquerda);
    printf("tipo de cartaz: %s, preco do cartaz: %.2f, id do cartaz: %d\n", grafica->grafica.tipoCartaz, grafica->grafica.preco, grafica->grafica.id_cartaz);
    imprimirCartzes(grafica->direita);
}

void imprimirVendedor(ArvoreVendedor *vendedor)
{
    if (vendedor == NULL)
        return;

    imprimirVendedor(vendedor->esquerda);
    printf("nome: %s, salario: %.2f, funcao: %s, quantidadeVendida: %.2f, id: %d\n", vendedor->vendedor.nome, vendedor->vendedor.salario, vendedor->vendedor.funcao, vendedor->vendedor.quantidadeVendida, vendedor->vendedor.id_vendedor);
    imprimirVendedor(vendedor->direita);
}