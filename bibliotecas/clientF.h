#ifndef clientF_h
#define clientF_h

//importação das bibliotecas principais
#include "disponiveis.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>

#define Tam_Assunto 101
#define Tam_Nome 51

typedef struct CLIENTE
{
    int cd_Identificacao;
    char Nome[Tam_Nome];
    Livros_Disponiveis *Emprestimo;
    struct CLIENTE *prox;
}Cliente;

//Abaixo está a função que insere um novo cliente.
Cliente* Aux_Cliente(Cliente *list, int Cd_Cliente, char nome[])
{
    Cliente *novo;
    novo = (Cliente*)malloc(sizeof(Cliente));
    novo->cd_Identificacao = Cd_Cliente;
    strcpy(novo->Nome, nome);
    novo->Emprestimo = NULL;
    novo->prox = list;
    return novo;
}

//Abaixo está a função que apenas ordena a lista de clientes
Cliente* Ordenamento_Cliente (Cliente *cliente)
{
    Cliente *cliente1, *aux1;
    Livros_Disponiveis *aux2, *aux3;
    int identificador;
    cliente1 = NULL;
    aux1 = NULL;
    aux2 = NULL;
    aux3 = NULL;

    if(cliente->prox != NULL)
    {
        do
        {
            identificador = 0;
            if(strcmp(cliente->prox->Nome, cliente->Nome) <= 0)
            {
                identificador++;
                cliente1 = Aux_Cliente(cliente1, cliente->prox->cd_Identificacao, cliente->prox->Nome);
                aux2 = cliente->prox->Emprestimo;
                for(; aux2 != NULL; aux2 = aux2->prox)
                {
                    cliente1->Emprestimo = Inputar_Disponivel_Ordenadamente(cliente1->Emprestimo, aux2->cd_registro, aux2->Titulo, aux2->Assunto, aux2->Autor);
                }
                cliente1 = Aux_Cliente(cliente1, cliente->cd_Identificacao, cliente->Nome);
                aux2 = cliente->Emprestimo;
                for(; aux2 != NULL; aux2 = aux2->prox)
                {
                    cliente1->Emprestimo = Inputar_Disponivel_Ordenadamente(cliente1->Emprestimo, aux2->cd_registro, aux2->Titulo, aux2->Assunto, aux2->Autor);
                }
                cliente = cliente->prox;
                cliente = cliente->prox;
            }
            else
            {
                cliente1 = Aux_Cliente(cliente1, cliente->cd_Identificacao, cliente->Nome);
                aux2 = cliente->Emprestimo;
                for(; aux2 != NULL; aux2 = aux2->prox)
                {
                    cliente1->Emprestimo = Inputar_Disponivel_Ordenadamente(cliente1->Emprestimo, aux2->cd_registro, aux2->Titulo, aux2->Assunto, aux2->Autor);
                }
                cliente = cliente->prox;
                cliente1 = Aux_Cliente(cliente1, cliente->cd_Identificacao, cliente->Nome);
                aux2 = cliente->Emprestimo;
                for(; aux2 != NULL; aux2 = aux2->prox)
                {
                    cliente1->Emprestimo = Inputar_Disponivel_Ordenadamente(cliente1->Emprestimo, aux2->cd_registro, aux2->Titulo, aux2->Assunto, aux2->Autor);
                }
                cliente = cliente->prox;
            }
            for(; cliente != NULL; cliente = cliente->prox)
            {

                if(strcmp(cliente->Nome, cliente1->Nome) <= 0)
                {
                    identificador++;
                    aux1 = Aux_Cliente(aux1, cliente1->cd_Identificacao, cliente1->Nome);
                    aux3 = cliente1->Emprestimo;
                    cliente1 = cliente1->prox;
                    aux2 = cliente->Emprestimo;
                    cliente1 = Aux_Cliente(cliente1, cliente->cd_Identificacao, cliente->Nome);
                    for(; aux2 != NULL; aux2 = aux2->prox)
                    {
                        cliente1->Emprestimo = Inputar_Disponivel_Ordenadamente(cliente1->Emprestimo, aux2->cd_registro, aux2->Titulo, aux2->Assunto, aux2->Autor);
                    }
                    cliente1 = Aux_Cliente(cliente1, aux1->cd_Identificacao, aux1->Nome);
                    for(; aux3 != NULL; aux3 = aux3->prox)
                    {
                        cliente1->Emprestimo = Inputar_Disponivel_Ordenadamente(cliente1->Emprestimo, aux3->cd_registro, aux3->Titulo, aux3->Assunto, aux3->Autor);
                    }
                    aux1 = aux1->prox;
                }
                else
                {
                    cliente1 = Aux_Cliente(cliente1, cliente->cd_Identificacao, cliente->Nome);
                    aux2 = cliente->Emprestimo;
                    for(; aux2 != NULL; aux2 = aux2->prox)
                    {
                        cliente1->Emprestimo = Inputar_Disponivel_Ordenadamente(cliente1->Emprestimo, aux2->cd_registro, aux2->Titulo, aux2->Assunto, aux2->Autor);                      
                    }
                }
            }
            for(; cliente1 != NULL; cliente1 = cliente1->prox)
            {
                aux2 = cliente1->Emprestimo;
                cliente = Aux_Cliente(cliente, cliente1->cd_Identificacao, cliente1->Nome);
                for(; aux2 != NULL; aux2 = aux2->prox)
                {
                    cliente->Emprestimo = Inputar_Disponivel_Ordenadamente(cliente->Emprestimo, aux2->cd_registro, aux2->Titulo, aux2->Assunto, aux2->Autor);
                }
            }
        } while (identificador != 0);
        
    }
    return cliente;
}

//A função abaixo identifica se o cliente cujo nome dado já está ou não cadastrado
int Identificador_Clientes_Existentes(Cliente *cliente, char nome[])
{
    for(; cliente != NULL; cliente = cliente->prox)
    {
        if(strcmp(nome, cliente->Nome) == 0) return 1;
    }
    return 0;
}

//A função abaixo identifica se o cliente cujo codigo dado já está ou não cadastrado
int Identificador_Clientes_Existentes_codigo(Cliente *cliente, int codigo)
{
    for(; cliente != NULL; cliente = cliente->prox)
    {
        if(cliente->cd_Identificacao == codigo)
        {
            return 1;
        }
    }
    return 0;
}

//Abaixo esta a função que faz a visualização que faz a visualização da lista de clientes.
void print_clientes_cadastrados(Cliente *cliente)
{
    if(cliente == NULL)
    {
        printf("Não há nenhum cliente cadastrado no momento.\n\n");
    }
    else
    {
        for(; cliente!= NULL; cliente = cliente->prox)
        {
            printf("Código do cliente: %i\n", cliente->cd_Identificacao);
            printf("\tNome do cliente: %s\n\n", cliente->Nome);
        }
    }
    system("pause");
}

//Abaixo esta a função que faz a visualização dos livros emprestados por cliente
void print_livros_emprestados_por_cliente(Cliente *cliente)
{
    Cliente *cliente1;
    Livros_Disponiveis *aux;
    cliente1 = cliente;

    printf("Abaixo estão todos os clientes com os seus respectivos livros alugados.\n\n");
    for(; cliente1 != NULL; cliente1 = cliente1->prox)
    {
        aux = cliente1->Emprestimo;
        printf("Código do cliente: %i\n", cliente1->cd_Identificacao);
        printf("\tNome do cliente: %s.\n", cliente1->Nome);
        printf("\tLivros emprestados: ");
        if(aux == NULL)
        {
            printf("O cliente não alugou nenhum livro.\n\n");
        }
        else
        {
            for(; aux != NULL; aux = aux->prox)
            {
                printf("\"%s\"(cod. %i)",aux->Titulo, aux->cd_registro);
                if(aux->prox != NULL)
                {
                    if(aux->prox->prox != NULL)
                    {
                        printf(", ");
                    }
                    else
                    {
                        printf(" e ");
                    }
                }
                else
                {
                    printf(".\n\n");
                }
            }
        }
    }
}

//Visualização de um cliente de acordo com um código passado
void print_emprestimo_cliente_codigo(Cliente *cliente, int codigo)
{
    Cliente *cliente1;
    Livros_Disponiveis *aux;
    cliente1 = cliente;
    if(cliente1 == NULL)
    {
        printf("Não há nenhum cliente cadastrado.\n\n");
    }
    else
    {
        for(; cliente1 != NULL; cliente1 = cliente1->prox)
        {
            if(cliente1->cd_Identificacao == codigo)
            {
                aux = cliente1->Emprestimo;
                printf("Nome do cliente: %s\n", cliente1->Nome);
                printf("Código do cliente: %i\n", cliente1->cd_Identificacao);
                printf("Livros alugados pelo cliente: ");
                if(aux == NULL)
                {
                    printf("O cliente não alugou nenhum livro.\n\n");
                }
                else
                {
                    printf("\n");
                    for(; aux != NULL; aux = aux->prox)
                    {
                        printf("\t-Código do livro: %i\n", aux->cd_registro);
                        printf("\t-Título do livro: %s\n\n", aux->Titulo);
                    }
                }
            }
        }
    }
}

//Visualização de um cliente de acordo com um nome passado
void print_emprestimo_cliente_nome(Cliente *cliente, char nome[])
{
    Livros_Disponiveis *aux;
    Cliente *cliente1;
    cliente1 = cliente;
    
    if(cliente1 == NULL)
    {
        printf("Não há nenhum cliente cadastrado.\n\n");
    }
    else
    {
        for(; cliente1 != NULL; cliente1 = cliente1->prox)
        {
            if(strcmp(nome, cliente1->Nome) == 0)
            {
                aux = cliente1->Emprestimo;
                printf("Nome do cliente: %s\n", cliente1->Nome);
                printf("Código do cliente: %i\n", cliente1->cd_Identificacao);
                printf("Livros alugados pelo cliente: ");
                if(aux == NULL)
                {
                    printf("O cliente não alugou nenhum livro.\n\n");
                }
                else
                {
                    printf("\n");
                    for(; aux != NULL; aux = aux->prox)
                    {
                        printf("\t-Código do livro: %i\n", aux->cd_registro);
                        printf("\t-Título do livro: %s\n\n", aux->Titulo);
                    }
                }
            }
        }
    }
}

//colocar a função de impressão da visualizar de todos os clientes procurando pelo código.
void print_clientes_codigo(Cliente *cliente, int codigo)
{
    for(; cliente != NULL; cliente = cliente->prox)
    {
        if(cliente->cd_Identificacao == codigo)
        {
            printf("Abaixo está as informações do cliente que tem o código %i:\n\n", codigo);
            printf("Código do cliente: %i\n", codigo);
            printf("\tNome do cliente: %s\n\n", cliente->Nome);
            break;
        }
    }
}

//colocar a função de impressão da visualizar de todos os clientes procurando pelo nome.
void print_clientes_nome(Cliente *cliente, char nome[])
{
    for(; cliente != NULL; cliente = cliente->prox)
    {
        if(strcmp(cliente->Nome, nome) == 0)
        {
            printf("Abaixo está as informações do cliente \"%s\":\n\n", nome);
            printf("Código do cliente: %i\n", cliente->cd_Identificacao);
            printf("\tNome do cliente: %s\n\n", cliente->Nome);
            break;
        }
    }
}

//A funçaõ abaixo serve para editar o nome de um cliente, dado o código de identificação do mesmo
Cliente* Editar_cliente(Cliente *cliente, int codigo, char nome[])
{
    Cliente *cliente1;
    Livros_Disponiveis *aux;
    aux = NULL;
    cliente1 = NULL;

    for(; cliente != NULL; cliente = cliente->prox)
    {
        if(cliente->cd_Identificacao == codigo)
        {
            cliente1 = Aux_Cliente(cliente1, codigo, nome);
        }
        else
        {
            cliente1 = Aux_Cliente(cliente1, cliente->cd_Identificacao, cliente->Nome);
        }
        aux = cliente->Emprestimo;
        for(; aux != NULL; aux = aux->prox)
        {
            cliente1->Emprestimo = Inputar_Disponivel_Ordenadamente(cliente1->Emprestimo, aux->cd_registro, aux->Titulo, aux->Assunto, aux->Autor);
        }
    }
    cliente1 = Ordenamento_Cliente(cliente1);
    return cliente1;
}

//finalização da biblioteca
#endif