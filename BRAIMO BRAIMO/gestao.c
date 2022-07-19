#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//estrutura para padaria

typedef struct Padaria
{
    char tipoPao[50];
    int id_padaria;
    double preco;
} Padaria;

//estrutura para funcionario

typedef struct Funcionario
{
    char nome[50];
    double salario;
    char funcao[50];
    double quantidadeVendida;
    int id_funcionario;
} Funcionario;

//no padaria

typedef struct NoPadaria
{
    struct NoPadaria *esquerda;
    struct NoPadaria *direita;
    struct Padaria padaria;
} NoPadaria;

//no do funcionario
typedef struct NoFuncionario
{
    struct NoFuncionario *esquerda;
    struct NoFuncionario *direita;
    struct Funcionario funcionario;
} NoFuncionario;

//prototipos de funcoes

void imprimirPao(NoPadaria *padaria);

void imprimirFuncionario(NoFuncionario *funcionario);

Funcionario novoFuncionario(double salario, char nome[50], char funcao[50], int id);

NoFuncionario *inserirFuncionario(NoFuncionario *funcionario, Funcionario dadosFuncionario);

Padaria novo_pao(char tipo_pao[50], int id, double preco);

NoPadaria *inserirPao(NoPadaria *padaria, Padaria dadosPao);

NoPadaria *venderPao(NoPadaria *padaria, NoFuncionario **funcionario, int id_pao, int id_vendedor);

NoFuncionario *apagarFuncionario(NoFuncionario *funcionario, int id);

void imprimirFuncionarioViaId(NoFuncionario *funcionario, int id);

void menu();

//main

int quantidade = 0;

void main()
{

    menu();
}

//funcao para limpar tela

void limparTela()
{
    system("clear");
}

//menu com todas as operacoes

void menu()
{

    //inicializar raizes das arvores funcionario e padaria

    NoPadaria *pao = NULL;
    NoFuncionario *funcionario = NULL;

    //variavel para controlar o loop

    int i = 1;

    //label para voltar a opcao inicial quando necessario

inicio:
    while (i)
    {
        //conjunto de operacoes possiveis

        printf("digite:\n1- para inserir pao\n2-para inserir funcionario\n3-para vender pao\n4-para ver quantidade de paes\n5-para ver paes\n6-para ver funcionarios\n7-Apagar Funcionarios\n8-Ver funcionario\n9-para sair\n");

        //escolher uma das operacoes

        int opcao;
        scanf("%d", &opcao);
        limparTela();

        switch (opcao)
        {
        case 1:
            printf("digite o tipo de pao\n\n");
            char tipo_pao[50];
            scanf("%s", tipo_pao);
            limparTela();

            printf("digite o id\n\n");
            int id;
            scanf("%d", &id);
            limparTela();

            printf("digite o preco\n\n");
            float preco;
            scanf("%f", &preco);
            limparTela();

            pao = inserirPao(pao, novo_pao(tipo_pao, id, preco));
            printf("\ninserido com sucesso\n digite 1 para voltar e 2 para sair\n");
            int op;
            scanf("%d", &op);
            limparTela();

            //verificar se quer voltar ao menu inicial ou sair
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
            limparTela();

            printf("digite o nome do funcionario\n");
            char nome[50];
            scanf("%s", nome);
            limparTela();

            printf("digite o salario\n");
            float salario;
            scanf("%f", &salario);
            limparTela();

            printf("digite a funcao\n");
            char funcao[50];
            scanf("%s", funcao);
            limparTela();

            funcionario = inserirFuncionario(funcionario, novoFuncionario(salario, nome, funcao, id));
            printf("\nfuncionario inserido com sucesso\n digite 1 para voltar ou 2 para sair\n");
            scanf("%d", &op);
            limparTela();

            //verificar se quer voltar ao menu inicial ou sair
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
            limparTela();

            printf("digite o id do pao\n");
            int id_pao;
            scanf("%d", &id_pao);
            limparTela();

            pao = venderPao(pao, &funcionario, id_pao, id_vendedor);
            printf("digite 1 para voltar e 2 para sair\n");
            scanf("%d", &op);
            limparTela();

            //verificar se quer voltar ao menu inicial ou sair
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
            printf("Quantidade: %d\n", quantidade);
            printf("digite 1 para voltar e 2 para sair\n");
            scanf("%d", &op);
            limparTela();

            //verificar se quer voltar ao menu inicial ou sair
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
            limparTela();
            //verificar se quer voltar ao menu inicial ou sair
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
            limparTela();
            //verificar se quer voltar ao menu inicial ou sair
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
            printf("digite o id do funcionario\n");
            scanf("%d", &id);
            funcionario = apagarFuncionario(funcionario, id);

            printf("digite 1 para voltar ou 2 para sair\n");
            scanf("%d", &op);
            limparTela();
            //verificar se quer voltar ao menu inicial ou sair
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
        case 8:
            printf("digite o id do funcionario\n");
            scanf("%d", &id);
            limparTela();
            imprimirFuncionarioViaId(funcionario, id);
            //verificar se quer voltar ao menu inicial ou sair
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
        case 9:
            i = 0;
            break;
        default:
            printf("opcao invalida\n");
            i = 0;
        }
    }
}

//funcao para retornar um certo funcionario

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

//funcao para atribuir dados ao funcionario novo

Funcionario novoFuncionario(double salario, char nome[50], char funcao[50], int id)
{
    Funcionario novo;
    strcpy(novo.nome, nome);
    strcpy(novo.funcao, funcao);
    novo.id_funcionario = id;
    novo.salario = salario;
    novo.quantidadeVendida = 0;

    return novo;
}

//funcao para atualizar a quantidade vendida por um funcionario
NoFuncionario *atualizarFuncionarioQuantidadeVendida(NoFuncionario *funcionario, int id)
{
    if (pesquisarFuncionario(funcionario, id))
    {
        NoFuncionario *aux = funcionario;
        aux = pesquisarFuncionario(funcionario, id);
        aux->funcionario.quantidadeVendida = 1 + aux->funcionario.quantidadeVendida;

        return aux;
    }
    else
    {
        printf("O funcionario nao existe\n");
    }
}

//funcao para adicionar um novo funcionario
NoFuncionario *inserirFuncionario(NoFuncionario *funcionario, Funcionario dadosFuncionario)
{

    if (pesquisarFuncionario(funcionario, dadosFuncionario.id_funcionario))
    {
        printf("funcionario com o id: %d ja existe.\n", dadosFuncionario.id_funcionario);
    }
    else
    {

        NoFuncionario *novo_funcionario = (NoFuncionario *)malloc(sizeof(NoFuncionario));
        novo_funcionario->esquerda = NULL;
        novo_funcionario->direita = NULL;
        novo_funcionario->funcionario = dadosFuncionario;

        if (funcionario == NULL)
        {
            funcionario = novo_funcionario;
        }
        else
        {
            if (funcionario->funcionario.id_funcionario >= dadosFuncionario.id_funcionario)
            {
                funcionario->esquerda = inserirFuncionario(funcionario->esquerda, dadosFuncionario);
            }
            else
            {
                funcionario->direita = inserirFuncionario(funcionario->direita, dadosFuncionario);
            }
        }
    }

    return funcionario;
}

//funcao para encontrar o minimo valor da direita

NoFuncionario *minimoValorDireitaFuncionario(NoFuncionario *funcionario)
{

    NoFuncionario *aux = funcionario;

    while (aux->esquerda)
    {
        aux = aux->esquerda;
    }

    return aux;
}

//funcao para apagar um funcionario especificado
NoFuncionario *apagarFuncionario(NoFuncionario *funcionario, int id)
{
    if (funcionario != NULL)
    {
        if (pesquisarFuncionario(funcionario, id))
        {
            funcionario = pesquisarFuncionario(funcionario, id);

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
            short int id = funcionario->funcionario.id_funcionario;
            funcionario->funcionario = temp->funcionario;
            funcionario->funcionario.id_funcionario = id;
            funcionario->direita = apagarFuncionario(funcionario->direita, temp->funcionario.id_funcionario);
        }
    }

    return funcionario;
}

//funcao que retorna um pao especificado
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

//funcao que atribui dados ao novo pao a ser inserido
Padaria novo_pao(char tipo_pao[50], int id, double preco)
{
    Padaria novo;
    novo.id_padaria = id;
    novo.preco = preco;
    strcpy(novo.tipoPao, tipo_pao);

    return novo;
}

//funcao para inserir pao
NoPadaria *inserirPao(NoPadaria *padaria, Padaria dadosPao)
{
    if (pesquisarPao(padaria, dadosPao.id_padaria))
    {
        printf("O id do pao: %d  ja existe.\n", dadosPao.id_padaria);
    }
    else
    {
        NoPadaria *novo_pao = (NoPadaria *)malloc(sizeof(NoPadaria));
        novo_pao->padaria = dadosPao;
        novo_pao->esquerda = NULL;
        novo_pao->direita = NULL;

        if (padaria == NULL)
        {
            padaria = novo_pao;
            quantidade++;
        }
        else
        {
            if (padaria->padaria.id_padaria >= dadosPao.id_padaria)
            {
                padaria->esquerda = inserirPao(padaria->esquerda, dadosPao);
            }
            else
            {
                padaria->direita = inserirPao(padaria->direita, dadosPao);
            }
        }
    }

    return padaria;
}

//funcao para encontrar o minimo valor da direita para eliminar um pao com dois filhos
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

//funcao para apagar pao
NoPadaria *apagarPao(NoPadaria *padaria, int id_pao)
{

    if (padaria != NULL)
    {
        if (pesquisarPao(padaria, id_pao))
        {

            padaria = pesquisarPao(padaria, id_pao);

            if (padaria->direita == NULL && padaria->esquerda == NULL)
            {
                free(padaria);
                quantidade--;
                return NULL;
            }
            else if (padaria->direita == NULL)
            {
                NoPadaria *temp = padaria->esquerda;
                free(padaria);
                quantidade--;
                return temp;
            }
            else if (padaria->esquerda == NULL)
            {
                NoPadaria *temp = padaria->direita;
                free(padaria);
                quantidade--;
                return temp;
            }

            NoPadaria *temp = minimoValorDireitaPao(padaria->direita);
            short int id = padaria->padaria.id_padaria;
            padaria->padaria = temp->padaria;
            padaria->padaria.id_padaria = id;
            padaria->direita = apagarPao(padaria->direita, temp->padaria.id_padaria);
            quantidade--;
        }
    }
    return padaria;
};

//funcao para vender pao
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
            atualizarFuncionarioQuantidadeVendida((*funcionario), id_vendedor);
            printf("pao %d vendido com sucesso.\n", id_pao);
        }
        else
        {
            printf("O funcionario nao existe\n");
        }
    }

    return padaria;
}

//funcao para imprimir pao

void imprimirPao(NoPadaria *padaria)
{
    if (padaria == NULL)
        return;
    imprimirPao(padaria->esquerda);
    printf("tipo de pao: %s, preco do pao: %.2f, id do pao: %d\n", padaria->padaria.tipoPao, padaria->padaria.preco, padaria->padaria.id_padaria);
    imprimirPao(padaria->direita);
}

//funcao para imprimir funcionarios
void imprimirFuncionario(NoFuncionario *funcionario)
{
    if (funcionario == NULL)
        return;

    imprimirFuncionario(funcionario->esquerda);

    printf("nome: %s, salario: %.2f, funcao: %s, quantidadeVendida: %.2f, id: %d\n", funcionario->funcionario.nome, funcionario->funcionario.salario, funcionario->funcionario.funcao, funcionario->funcionario.quantidadeVendida, funcionario->funcionario.id_funcionario);

    imprimirFuncionario(funcionario->direita);
}

//imprimir funcionario especifico

void imprimirFuncionarioViaId(NoFuncionario *funcionario, int id)
{

    if (pesquisarFuncionario(funcionario, id))
    {
        funcionario = pesquisarFuncionario(funcionario, id);

        printf("nome: %s, salario: %.2f, funcao: %s, quantidadeVendida: %.2f, id: %d\n", funcionario->funcionario.nome, funcionario->funcionario.salario, funcionario->funcionario.funcao, funcionario->funcionario.quantidadeVendida, funcionario->funcionario.id_funcionario);
    }
}