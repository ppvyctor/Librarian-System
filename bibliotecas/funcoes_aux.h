#ifndef FUNCOES_AUX_H
#define FUNCOES_AUX_H

#include <stdio.h>
#include <stdlib.h>
#include "locados.h"
#include "disponiveis.h"
#include "clientF.h"

/*Nas funções 8 função abaixo onde tais emprestam e devolvem os livros, a pequena dificuldade não foi na construção de um código funcional
que alterasse as lista para coseguir realizar uma devlução ou um empréstimo de um livro, mas sim, a dificuldade pelo qual enfrentamos, foi
em fazer o código funcionar dentro de uma função void, já que após divérsas pesquisas, a manipulação de listas dentro de uma função void
na qual estavamos tentando fazer, não deveria receber o ponteiro da lista, mas sim, um duplo ponteiro da lista. Portanto, após uma breve
modificação na lógica dos códigos abaixo, nas váriaveis de parâmetro e na chamada de cada função, enfim, a modificação das listas usando cada
função foi concluida, e assim conseguimos realizar as modificações nas listas dentro da função. */

//Abaixo estão todas as funções usadas para realizar o empréstimo de livros.


void emprestimo_codigo_cliente_e_livro(Livros_Disponiveis **L_Disponiveis, Livros_Emprestados **L_Emprestados, Cliente **cliente, int codigo_cliente, int codigo_livro)
{
    Livros_Disponiveis *aux1, *L_Disponiveis1, *aux2;
    Cliente *aux3, *cliente1;
    Livros_Emprestados *L_Emprestados1;
    aux1 = NULL;
    aux2 = NULL;
    aux3 = NULL;
    L_Disponiveis1 = *L_Disponiveis;
    cliente1 = *cliente;
    L_Emprestados1 = *L_Emprestados;

    for(; cliente1 != NULL; cliente1 = cliente1->prox)
    {
        if(cliente1->cd_Identificacao == codigo_cliente)
        {
            for(; L_Disponiveis1 != NULL; L_Disponiveis1 = L_Disponiveis1->prox)
            {
                if(L_Disponiveis1->cd_registro == codigo_livro)
                {
                    L_Emprestados1 = Inputar_Emprestados_Ordenadamente(L_Emprestados1, cliente1->cd_Identificacao, L_Disponiveis1->cd_registro, L_Disponiveis1->Titulo, L_Disponiveis1->Assunto, L_Disponiveis1->Autor);
                    aux2 = Aux_Disp(aux2, L_Disponiveis1->cd_registro, L_Disponiveis1->Titulo, L_Disponiveis1->Assunto, L_Disponiveis1->Autor);
                }
                else
                {
                    aux1 = Inputar_Disponivel_Ordenadamente(aux1, L_Disponiveis1->cd_registro, L_Disponiveis1->Titulo, L_Disponiveis1->Assunto, L_Disponiveis1->Autor);
                }
            }
        }
        aux3 = Aux_Cliente(aux3, cliente1->cd_Identificacao, cliente1->Nome);
        if(cliente1->Emprestimo != NULL)
        {
            for(; cliente1->Emprestimo != NULL; cliente1->Emprestimo = cliente1->Emprestimo->prox)
            {
                aux3->Emprestimo = Inputar_Disponivel_Ordenadamente(aux3->Emprestimo, cliente1->Emprestimo->cd_registro, cliente1->Emprestimo->Titulo, cliente1->Emprestimo->Assunto, cliente1->Emprestimo->Autor);
            }
        }
        if(aux2 != NULL)
        {
            aux3->Emprestimo = Inputar_Disponivel_Ordenadamente(aux3->Emprestimo, aux2->cd_registro, aux2->Titulo, aux2->Assunto, aux2->Autor);
            aux2 = aux2->prox;
        }
    }
    *L_Disponiveis = aux1;
    *cliente = aux3;
    *L_Emprestados = L_Emprestados1;
}

void emprestimo_codigo_cliente_titulo_livro(Livros_Disponiveis **L_Disponiveis, Livros_Emprestados **L_Emprestados, Cliente **cliente, int codigo_cliente, char titulo[])
{
    Livros_Disponiveis *aux1, *L_Disponiveis1, *aux2;
    Cliente *aux3, *cliente1;
    Livros_Emprestados *L_Emprestados1;
    aux1 = NULL;
    aux2 = NULL;
    aux3 = NULL;
    L_Disponiveis1 = *L_Disponiveis;
    cliente1 = *cliente;
    L_Emprestados1 = *L_Emprestados;

    for(; cliente1 != NULL; cliente1 = cliente1->prox)
    {
        if(cliente1->cd_Identificacao == codigo_cliente)
        {
            for(; L_Disponiveis1 != NULL; L_Disponiveis1 = L_Disponiveis1->prox)
            {
                if(strcmp(titulo, L_Disponiveis1->Titulo) == 0)
                {
                    L_Emprestados1 = Inputar_Emprestados_Ordenadamente(L_Emprestados1, cliente1->cd_Identificacao, L_Disponiveis1->cd_registro, L_Disponiveis1->Titulo, L_Disponiveis1->Assunto, L_Disponiveis1->Autor);
                    aux2 = Aux_Disp(aux2, L_Disponiveis1->cd_registro, L_Disponiveis1->Titulo, L_Disponiveis1->Assunto, L_Disponiveis1->Autor);
                }
                else
                {
                    aux1 = Inputar_Disponivel_Ordenadamente(aux1, L_Disponiveis1->cd_registro, L_Disponiveis1->Titulo, L_Disponiveis1->Assunto, L_Disponiveis1->Autor);
                }
            }
        }
        aux3 = Aux_Cliente(aux3, cliente1->cd_Identificacao, cliente1->Nome);
        if(cliente1->Emprestimo != NULL)
        {
            for(; cliente1->Emprestimo != NULL; cliente1->Emprestimo = cliente1->Emprestimo->prox)
            {
                aux3->Emprestimo = Inputar_Disponivel_Ordenadamente(aux3->Emprestimo, cliente1->Emprestimo->cd_registro, cliente1->Emprestimo->Titulo, cliente1->Emprestimo->Assunto, cliente1->Emprestimo->Autor);
            }
        }
        if(aux2 != NULL)
        {
            aux3->Emprestimo = Inputar_Disponivel_Ordenadamente(aux3->Emprestimo, aux2->cd_registro, aux2->Titulo, aux2->Assunto, aux2->Autor);
            aux2 = aux2->prox;
        }
    }
    *L_Disponiveis = aux1;
    *cliente = aux3;
    *L_Emprestados = L_Emprestados1;
}

void emprestimo_nome_cliente_e_codigo_Livro(Livros_Disponiveis **L_Disponiveis, Livros_Emprestados **L_Emprestados, Cliente **cliente, char nome_cliente[], int codigo_livro)
{
    Livros_Disponiveis *aux1, *L_Disponiveis1, *aux2;
    Cliente *aux3, *cliente1;
    Livros_Emprestados *L_Emprestados1;
    aux1 = NULL;
    aux2 = NULL;
    aux3 = NULL;
    L_Disponiveis1 = *L_Disponiveis;
    cliente1 = *cliente;
    L_Emprestados1 = *L_Emprestados;

    for(; cliente1 != NULL; cliente1 = cliente1->prox)
    {
        if(strcmp(nome_cliente, cliente1->Nome) == 0)
        {
            for(; L_Disponiveis1 != NULL; L_Disponiveis1 = L_Disponiveis1->prox)
            {
                if(L_Disponiveis1->cd_registro == codigo_livro)
                {
                    L_Emprestados1 = Inputar_Emprestados_Ordenadamente(L_Emprestados1, cliente1->cd_Identificacao, L_Disponiveis1->cd_registro, L_Disponiveis1->Titulo, L_Disponiveis1->Assunto, L_Disponiveis1->Autor);
                    aux2 = Aux_Disp(aux2, L_Disponiveis1->cd_registro, L_Disponiveis1->Titulo, L_Disponiveis1->Assunto, L_Disponiveis1->Autor);
                }
                else
                {
                    aux1 = Inputar_Disponivel_Ordenadamente(aux1, L_Disponiveis1->cd_registro, L_Disponiveis1->Titulo, L_Disponiveis1->Assunto, L_Disponiveis1->Autor);
                }
            }
        }
        aux3 = Aux_Cliente(aux3, cliente1->cd_Identificacao, cliente1->Nome);
        if(cliente1->Emprestimo != NULL)
        {
            for(; cliente1->Emprestimo != NULL; cliente1->Emprestimo = cliente1->Emprestimo->prox)
            {
                aux3->Emprestimo = Inputar_Disponivel_Ordenadamente(aux3->Emprestimo, cliente1->Emprestimo->cd_registro, cliente1->Emprestimo->Titulo, cliente1->Emprestimo->Assunto, cliente1->Emprestimo->Autor);
            }
        }
        if(aux2 != NULL)
        {
            aux3->Emprestimo = Inputar_Disponivel_Ordenadamente(aux3->Emprestimo, aux2->cd_registro, aux2->Titulo, aux2->Assunto, aux2->Autor);
            aux2 = aux2->prox;
        }
    }
    *L_Disponiveis = aux1;
    *cliente = aux3;
    *L_Emprestados = L_Emprestados1;
}

void emprestimo_nome_cliente_e_Livro(Livros_Disponiveis **L_Disponiveis, Livros_Emprestados **L_Emprestados, Cliente **cliente, char nome_cliente[], char titulo[])
{
    Livros_Disponiveis *aux1, *L_Disponiveis1, *aux2;
    Cliente *aux3, *cliente1;
    Livros_Emprestados *L_Emprestados1;
    aux1 = NULL;
    aux2 = NULL;
    aux3 = NULL;
    L_Disponiveis1 = *L_Disponiveis;
    cliente1 = *cliente;
    L_Emprestados1 = *L_Emprestados;

    for(; cliente1 != NULL; cliente1 = cliente1->prox)
    {
        if(strcmp(nome_cliente, cliente1->Nome) == 0)
        {
            for(; L_Disponiveis1 != NULL; L_Disponiveis1 = L_Disponiveis1->prox)
            {
                if(strcmp(titulo, L_Disponiveis1->Titulo) == 0)
                {
                    L_Emprestados1 = Inputar_Emprestados_Ordenadamente(L_Emprestados1, cliente1->cd_Identificacao, L_Disponiveis1->cd_registro, L_Disponiveis1->Titulo, L_Disponiveis1->Assunto, L_Disponiveis1->Autor);
                    aux2 = Aux_Disp(aux2, L_Disponiveis1->cd_registro, L_Disponiveis1->Titulo, L_Disponiveis1->Assunto, L_Disponiveis1->Autor);
                }
                else
                {
                    aux1 = Inputar_Disponivel_Ordenadamente(aux1, L_Disponiveis1->cd_registro, L_Disponiveis1->Titulo, L_Disponiveis1->Assunto, L_Disponiveis1->Autor);
                }
            }
        }
        aux3 = Aux_Cliente(aux3, cliente1->cd_Identificacao, cliente1->Nome);
        if(cliente1->Emprestimo != NULL)
        {
            for(; cliente1->Emprestimo != NULL; cliente1->Emprestimo = cliente1->Emprestimo->prox)
            {
                aux3->Emprestimo = Inputar_Disponivel_Ordenadamente(aux3->Emprestimo, cliente1->Emprestimo->cd_registro, cliente1->Emprestimo->Titulo, cliente1->Emprestimo->Assunto, cliente1->Emprestimo->Autor);
            }
        }
        if(aux2 != NULL)
        {
            aux3->Emprestimo = Inputar_Disponivel_Ordenadamente(aux3->Emprestimo, aux2->cd_registro, aux2->Titulo, aux2->Assunto, aux2->Autor);
            aux2 = aux2->prox;
        }
    }
    *L_Disponiveis = aux1;
    *cliente = aux3;
    *L_Emprestados = L_Emprestados1;
}

//Abaixo estão todas as funções usadas para realizar a devolução do livros.
void devolucao_codigo_cliente_e_livro(Livros_Disponiveis **L_Disponiveis, Livros_Emprestados **L_Emprestados, Cliente **cliente, int codigo_cliente, int codigo_livro)
{
    Livros_Emprestados *aux1, *L_Emprestados1;
    Cliente *aux3, *cliente1;
    Livros_Disponiveis *L_Disponiveis1, *aux2;
    int identificador;
    identificador = 0;
    aux1 = NULL;
    aux2 = NULL;
    aux3 = NULL;
    L_Disponiveis1 = *L_Disponiveis;
    cliente1 = *cliente;
    L_Emprestados1 = *L_Emprestados;

    for(; cliente1 != NULL; cliente1 = cliente1->prox)
    {
        if(cliente1->cd_Identificacao == codigo_cliente)
        {
            identificador++;
            for(; L_Emprestados1 != NULL; L_Emprestados1 = L_Emprestados1->prox)
            {
                if(L_Emprestados1->Cd_Identificacao_Livro_Emprestado == codigo_livro)
                {
                    L_Disponiveis1 = Inputar_Disponivel_Ordenadamente(L_Disponiveis1, codigo_livro, L_Emprestados1->Titulo, L_Emprestados1->Assunto, L_Emprestados1->Autor);
                }
                else
                {
                    aux1 = Inputar_Emprestados_Ordenadamente(aux1, L_Emprestados1->Cd_Identificacao_Cliente, L_Emprestados1->Cd_Identificacao_Livro_Emprestado, L_Emprestados1->Titulo, L_Emprestados1->Assunto, L_Emprestados1->Autor);
                }
            }
        }
        if(identificador != 0)
        {
            identificador = 0;
            aux3 = Aux_Cliente(aux3, cliente1->cd_Identificacao, cliente1->Nome);
            for(; cliente1->Emprestimo != NULL; cliente1->Emprestimo = cliente1->Emprestimo->prox)
            {
                if(cliente1->Emprestimo->cd_registro != codigo_livro)
                {
                    aux2 = Aux_Disp(aux2, cliente1->Emprestimo->cd_registro, cliente1->Emprestimo->Titulo, cliente1->Emprestimo->Assunto, cliente1->Emprestimo->Autor);
                    aux3->Emprestimo = Inputar_Disponivel_Ordenadamente(aux3->Emprestimo, aux2->cd_registro, aux2->Titulo, aux2->Assunto, aux2->Autor);
                }
            }
            
        }
        else
        {
            aux3 = Aux_Cliente(aux3, cliente1->cd_Identificacao, cliente1->Nome);
            for(; cliente1->Emprestimo != NULL; cliente1->Emprestimo = cliente1->Emprestimo->prox)
            {
                aux3->Emprestimo = Inputar_Disponivel_Ordenadamente(aux3->Emprestimo, cliente1->Emprestimo->cd_registro, cliente1->Emprestimo->Titulo, cliente1->Emprestimo->Assunto, cliente1->Emprestimo->Autor);
            }
        }
    }
    *L_Disponiveis = L_Disponiveis1;
    *cliente = aux3;
    *L_Emprestados = aux1;
}

void devolucao_codigo_cliente_titulo_livro(Livros_Disponiveis **L_Disponiveis, Livros_Emprestados **L_Emprestados, Cliente **cliente, int codigo_cliente, char titulo[])
{
    Livros_Emprestados *aux1, *L_Emprestados1;
    Cliente *aux3, *cliente1;
    Livros_Disponiveis *L_Disponiveis1, *aux2;
    int identificador;
    identificador = 0;
    aux1 = NULL;
    aux2 = NULL;
    aux3 = NULL;
    L_Disponiveis1 = *L_Disponiveis;
    cliente1 = *cliente;
    L_Emprestados1 = *L_Emprestados;

    for(; cliente1 != NULL; cliente1 = cliente1->prox)
    {
        if(cliente1->cd_Identificacao == codigo_cliente)
        {
            identificador++;
            for(; L_Emprestados1 != NULL; L_Emprestados1 = L_Emprestados1->prox)
            {
                if(strcmp(titulo, L_Emprestados1->Titulo) == 0)
                {
                    L_Disponiveis1 = Inputar_Disponivel_Ordenadamente(L_Disponiveis1, L_Emprestados1->Cd_Identificacao_Livro_Emprestado, L_Emprestados1->Titulo, L_Emprestados1->Assunto, L_Emprestados1->Autor);
                }
                else
                {
                    aux1 = Inputar_Emprestados_Ordenadamente(aux1, L_Emprestados1->Cd_Identificacao_Cliente, L_Emprestados1->Cd_Identificacao_Livro_Emprestado, L_Emprestados1->Titulo, L_Emprestados1->Assunto, L_Emprestados1->Autor);
                }
            }
        }
        if(identificador != 0)
        {
            identificador = 0;
            aux3 = Aux_Cliente(aux3, cliente1->cd_Identificacao, cliente1->Nome);
            for(; cliente1->Emprestimo != NULL; cliente1->Emprestimo = cliente1->Emprestimo->prox)
            {
                if(strcmp(titulo, cliente1->Emprestimo->Titulo) != 0)
                {
                    aux2 = Aux_Disp(aux2, cliente1->Emprestimo->cd_registro, cliente1->Emprestimo->Titulo, cliente1->Emprestimo->Assunto, cliente1->Emprestimo->Autor);
                    aux3->Emprestimo = Inputar_Disponivel_Ordenadamente(aux3->Emprestimo, aux2->cd_registro, aux2->Titulo, aux2->Assunto, aux2->Autor);
                }
            }
        }
        else
        {
            aux3 = Aux_Cliente(aux3, cliente1->cd_Identificacao, cliente1->Nome);
            for(; cliente1->Emprestimo != NULL; cliente1->Emprestimo = cliente1->Emprestimo->prox)
            {
                aux3->Emprestimo = Inputar_Disponivel_Ordenadamente(aux3->Emprestimo, cliente1->Emprestimo->cd_registro, cliente1->Emprestimo->Titulo, cliente1->Emprestimo->Assunto, cliente1->Emprestimo->Autor);
            }
        }
    }
    *L_Disponiveis = L_Disponiveis1;
    *cliente = aux3;
    *L_Emprestados = aux1;
}

void devolucao_nome_cliente_e_codigo_livro(Livros_Disponiveis **L_Disponiveis, Livros_Emprestados **L_Emprestados, Cliente **cliente, char nome[], int codigo_livro)
{
    Livros_Emprestados *aux1, *L_Emprestados1;
    Cliente *aux3, *cliente1;
    Livros_Disponiveis *L_Disponiveis1, *aux2;
    int identificador;
    identificador = 0;
    aux1 = NULL;
    aux2 = NULL;
    aux3 = NULL;
    L_Disponiveis1 = *L_Disponiveis;
    cliente1 = *cliente;
    L_Emprestados1 = *L_Emprestados;

    for(; cliente1 != NULL; cliente1 = cliente1->prox)
    {
        if(strcmp(nome, cliente1->Nome) == 0)
        {
            identificador++;
            for(; L_Emprestados1 != NULL; L_Emprestados1 = L_Emprestados1->prox)
            {
                if(L_Emprestados1->Cd_Identificacao_Livro_Emprestado == codigo_livro)
                {
                    L_Disponiveis1 = Inputar_Disponivel_Ordenadamente(L_Disponiveis1, L_Emprestados1->Cd_Identificacao_Livro_Emprestado, L_Emprestados1->Titulo, L_Emprestados1->Assunto, L_Emprestados1->Autor);
                }
                else
                {
                    aux1 = Inputar_Emprestados_Ordenadamente(aux1, L_Emprestados1->Cd_Identificacao_Cliente, L_Emprestados1->Cd_Identificacao_Livro_Emprestado, L_Emprestados1->Titulo, L_Emprestados1->Assunto, L_Emprestados1->Autor);
                }
            }
        }
        if(identificador != 0)
        {
            identificador = 0;
            aux3 = Aux_Cliente(aux3, cliente1->cd_Identificacao, cliente1->Nome);
            for(; cliente1->Emprestimo != NULL; cliente1->Emprestimo = cliente1->Emprestimo->prox)
            {
                if(L_Emprestados1->Cd_Identificacao_Livro_Emprestado != codigo_livro)
                {
                    aux2 = Aux_Disp(aux2, cliente1->Emprestimo->cd_registro, cliente1->Emprestimo->Titulo, cliente1->Emprestimo->Assunto, cliente1->Emprestimo->Autor);
                    aux3->Emprestimo = Inputar_Disponivel_Ordenadamente(aux3->Emprestimo, aux2->cd_registro, aux2->Titulo, aux2->Assunto, aux2->Autor);
                }
            }
        }
        else
        {
            aux3 = Aux_Cliente(aux3, cliente1->cd_Identificacao, cliente1->Nome);
            for(; cliente1->Emprestimo != NULL; cliente1->Emprestimo = cliente1->Emprestimo->prox)
            {
                aux3->Emprestimo = Inputar_Disponivel_Ordenadamente(aux3->Emprestimo, cliente1->Emprestimo->cd_registro, cliente1->Emprestimo->Titulo, cliente1->Emprestimo->Assunto, cliente1->Emprestimo->Autor);
            }
        }
    }
    *L_Disponiveis = L_Disponiveis1;
    *cliente = aux3;
    *L_Emprestados = aux1;
}

void devolucao_nome_cliente_e_livro(Livros_Disponiveis **L_Disponiveis, Livros_Emprestados **L_Emprestados, Cliente **cliente, char nome[], char titulo[])
{
    Livros_Emprestados *aux1, *L_Emprestados1;
    Cliente *aux3, *cliente1;
    Livros_Disponiveis *L_Disponiveis1, *aux2;
    int identificador;
    identificador = 0;
    aux1 = NULL;
    aux2 = NULL;
    aux3 = NULL;
    L_Disponiveis1 = *L_Disponiveis;
    cliente1 = *cliente;
    L_Emprestados1 = *L_Emprestados;

    for(; cliente1 != NULL; cliente1 = cliente1->prox)
    {
        if(strcmp(nome, cliente1->Nome) == 0)
        {
            identificador++;
            for(; L_Emprestados1 != NULL; L_Emprestados1 = L_Emprestados1->prox)
            {
                if(strcmp(titulo, L_Emprestados1->Titulo) == 0)
                {
                    L_Disponiveis1 = Inputar_Disponivel_Ordenadamente(L_Disponiveis1, L_Emprestados1->Cd_Identificacao_Livro_Emprestado, L_Emprestados1->Titulo, L_Emprestados1->Assunto, L_Emprestados1->Autor);
                }
                else
                {
                    aux1 = Inputar_Emprestados_Ordenadamente(aux1, L_Emprestados1->Cd_Identificacao_Cliente, L_Emprestados1->Cd_Identificacao_Livro_Emprestado, L_Emprestados1->Titulo, L_Emprestados1->Assunto, L_Emprestados1->Autor);
                }
            }
        }
        if(identificador != 0)
        {
            identificador = 0;
            aux3 = Aux_Cliente(aux3, cliente1->cd_Identificacao, cliente1->Nome);
            for(; cliente1->Emprestimo != NULL; cliente1->Emprestimo = cliente1->Emprestimo->prox)
            {
                if(strcmp(titulo, cliente1->Emprestimo->Titulo) != 0)
                {
                    aux2 = Aux_Disp(aux2, cliente1->Emprestimo->cd_registro, cliente1->Emprestimo->Titulo, cliente1->Emprestimo->Assunto, cliente1->Emprestimo->Autor);
                    aux3->Emprestimo = Inputar_Disponivel_Ordenadamente(aux3->Emprestimo, aux2->cd_registro, aux2->Titulo, aux2->Assunto, aux2->Autor);
                }
            }
        }
        else
        {
            aux3 = Aux_Cliente(aux3, cliente1->cd_Identificacao, cliente1->Nome);
            for(; cliente1->Emprestimo != NULL; cliente1->Emprestimo = cliente1->Emprestimo->prox)
            {
                aux3->Emprestimo = Inputar_Disponivel_Ordenadamente(aux3->Emprestimo, cliente1->Emprestimo->cd_registro, cliente1->Emprestimo->Titulo, cliente1->Emprestimo->Assunto, cliente1->Emprestimo->Autor);
            }
        }
    }
    *L_Disponiveis = L_Disponiveis1;
    *cliente = aux3;
    *L_Emprestados = aux1;
}

//A função abaixo realiza a visualização mais detalhada dos livros Emprestado pelo codigo. Caso o cliente não tenha alugado o livro, a função também avisará do mesmo
void print_Livro_Emprestado_codigo(Livros_Emprestados *L_Emprestado, Livros_Disponiveis *L_Disponivel, int codigo)
{
    int identificador;
    identificador = 0;
    if(L_Emprestado == NULL)
    {
        printf("Não há nenhum livro emprestado na biblioteca. Já que,  ");
    }
    else
    {
        for(; L_Emprestado != NULL; L_Emprestado = L_Emprestado->prox)
        {
            if(L_Emprestado->Cd_Identificacao_Livro_Emprestado == codigo)
            {
                printf("Código do Livro: %i\n", L_Emprestado->Cd_Identificacao_Livro_Emprestado);
                printf("\tCódigo do Cliente que alugou o livro: %i\n", L_Emprestado->Cd_Identificacao_Cliente);
                printf("\tTítulo do livro: %s\n", L_Emprestado->Titulo);
                printf("\tAssunto do livro: %s\n", L_Emprestado->Assunto);
                printf("\tAutor do Livro: %s\n\n", L_Emprestado->Autor);
                identificador++;
                break;
            }
        }
    }
    if(identificador == 0)
    {
        for(; L_Disponivel != NULL; L_Disponivel = L_Disponivel->prox)
        {
            if(L_Disponivel->cd_registro == codigo)
            {
                printf("o livro está disponível para ser alugado na biblioteca\n\n");
                identificador++;
                break;
            }
        }
        if(identificador == 0)
        {
            printf("o livro do código %i, não está cadastrado no sistema.\n\n", codigo);
        }
    }
}

//A função abaixo realiza a visualização mais detalhada dos livros Emprestado pelo titulo. Caso o cliente não tenha alugado o livro, a função também avisará do mesmo
void print_Livro_Emprestado_titulo(Livros_Emprestados *L_Emprestado, Livros_Disponiveis *L_Disponivel, char titulo[])
{
    int identificador;
    identificador = 0;
    if(L_Emprestado == NULL)
    {
        printf("Não há nenhum livro emprestado na biblioteca. Já que,  ");
    }
    else
    {
        for(; L_Emprestado != NULL; L_Emprestado = L_Emprestado->prox)
        {
            if(strcmp(L_Emprestado->Titulo, titulo) == 0)
            {
                printf("Código do Livro: %i\n", L_Emprestado->Cd_Identificacao_Livro_Emprestado);
                printf("\tCódigo do Cliente que alugou o livro: %i\n", L_Emprestado->Cd_Identificacao_Cliente);
                printf("\tTítulo do livro: %s\n", L_Emprestado->Titulo);
                printf("\tAssunto do livro: %s\n", L_Emprestado->Assunto);
                printf("\tAutor do Livro: %s\n\n", L_Emprestado->Autor);
                identificador++;
                break;
            }
        }
    }
    if(identificador == 0)
    {
        for(; L_Disponivel != NULL; L_Disponivel = L_Disponivel->prox)
        {
            if(strcmp(L_Disponivel->Titulo, titulo) == 0)
            {
                printf("o livro está disponível para ser alugado na biblioteca\n\n");
                identificador++;
                break;
            }
        }
        if(identificador == 0)
        {
            printf("o livro com o título \"%s\", não está cadastrado no sistema.\n\n", titulo);
        }
    }
}

//Função que altera o titulo do livro que esta na lista de emprestimo e cliente.
void Editar_titulo_livros_emprestados_e_cliente(Livros_Emprestados **L_Emprestado, Cliente **cliente, int codigo, char titulo[])
{
    Livros_Disponiveis *aux;
    Livros_Emprestados *L_Emprestado1, *aux2;
    Cliente *cliente1, *aux1;
    cliente1 = *cliente;
    L_Emprestado1 = *L_Emprestado;
    aux = NULL;
    aux1 = NULL;
    aux2 = NULL;

    for(; L_Emprestado1 != NULL; L_Emprestado1 = L_Emprestado1->prox)
    {
        if(L_Emprestado1->Cd_Identificacao_Livro_Emprestado == codigo)
        {
            aux2 = Inputar_Emprestados_Ordenadamente(aux2, L_Emprestado1->Cd_Identificacao_Cliente, L_Emprestado1->Cd_Identificacao_Livro_Emprestado, titulo, L_Emprestado1->Assunto, L_Emprestado1->Autor);
        }
        else
        {
            aux2 = Inputar_Emprestados_Ordenadamente(aux2, L_Emprestado1->Cd_Identificacao_Cliente, L_Emprestado1->Cd_Identificacao_Livro_Emprestado, L_Emprestado1->Titulo, L_Emprestado1->Assunto, L_Emprestado1->Autor);
        }
    }
    for(; cliente1 != NULL; cliente1 = cliente1->prox)
    {
        aux1 = Aux_Cliente(aux1, cliente1->cd_Identificacao, cliente1->Nome );
        aux = cliente1->Emprestimo;
        for(; aux != NULL; aux = aux->prox)
        {
            if(aux->cd_registro == codigo)
            {
                aux1->Emprestimo = Inputar_Disponivel_Ordenadamente(aux1->Emprestimo, aux->cd_registro, titulo, aux->Assunto, aux->Autor);
            }
            else
            {
                aux1->Emprestimo = Inputar_Disponivel_Ordenadamente(aux1->Emprestimo, aux->cd_registro, aux->Titulo, aux->Assunto, aux->Autor);
            }
        }
    }
    aux1 = Ordenamento_Cliente(aux1);
    *L_Emprestado = aux2;
    *cliente = aux1;
}

//Função que altera o assunto do livro que esta na lista de emprestimo e cliente.
void Editar_assunto_livros_emprestados_e_cliente(Livros_Emprestados **L_Emprestado, Cliente **cliente, int codigo, char assunto[])
{
    Livros_Disponiveis *aux;
    Livros_Emprestados *L_Emprestado1, *aux2;
    Cliente *cliente1, *aux1;
    cliente1 = *cliente;
    L_Emprestado1 = *L_Emprestado;
    aux = NULL;
    aux1 = NULL;
    aux2 = NULL;

    for(; L_Emprestado1 != NULL; L_Emprestado1 = L_Emprestado1->prox)
    {
        if(L_Emprestado1->Cd_Identificacao_Livro_Emprestado == codigo)
        {
            aux2 = Inputar_Emprestados_Ordenadamente(aux2, L_Emprestado1->Cd_Identificacao_Cliente, L_Emprestado1->Cd_Identificacao_Livro_Emprestado, L_Emprestado1->Titulo, assunto, L_Emprestado1->Autor);
        }
        else
        {
            aux2 = Inputar_Emprestados_Ordenadamente(aux2, L_Emprestado1->Cd_Identificacao_Cliente, L_Emprestado1->Cd_Identificacao_Livro_Emprestado, L_Emprestado1->Titulo, L_Emprestado1->Assunto, L_Emprestado1->Autor);
        }
    }
    for(; cliente1 != NULL; cliente1 = cliente1->prox)
    {
        aux1 = Aux_Cliente(aux1, cliente1->cd_Identificacao, cliente1->Nome );
        aux = cliente1->Emprestimo;
        for(; aux != NULL; aux = aux->prox)
        {
            if(aux->cd_registro == codigo)
            {
                aux1->Emprestimo = Inputar_Disponivel_Ordenadamente(aux1->Emprestimo, aux->cd_registro, aux->Titulo, assunto, aux->Autor);
            }
            else
            {
                aux1->Emprestimo = Inputar_Disponivel_Ordenadamente(aux1->Emprestimo, aux->cd_registro, aux->Titulo, aux->Assunto, aux->Autor);
            }
        }
    }
    aux1 = Ordenamento_Cliente(aux1);
    *L_Emprestado = aux2;
    *cliente = aux1;
}

//Função que altera o autor do livro que esta na lista de emprestimo e cliente.
void Editar_autor_livros_emprestados_e_cliente(Livros_Emprestados **L_Emprestado, Cliente **cliente, int codigo, char autor[])
{
    Livros_Disponiveis *aux;
    Livros_Emprestados *L_Emprestado1, *aux2;
    Cliente *cliente1, *aux1;
    cliente1 = *cliente;
    L_Emprestado1 = *L_Emprestado;
    aux = NULL;
    aux1 = NULL;
    aux2 = NULL;

    for(; L_Emprestado1 != NULL; L_Emprestado1 = L_Emprestado1->prox)
    {
        if(L_Emprestado1->Cd_Identificacao_Livro_Emprestado == codigo)
        {
            aux2 = Inputar_Emprestados_Ordenadamente(aux2, L_Emprestado1->Cd_Identificacao_Cliente, L_Emprestado1->Cd_Identificacao_Livro_Emprestado, L_Emprestado1->Titulo, L_Emprestado1->Assunto, autor);
        }
        else
        {
            aux2 = Inputar_Emprestados_Ordenadamente(aux2, L_Emprestado1->Cd_Identificacao_Cliente, L_Emprestado1->Cd_Identificacao_Livro_Emprestado, L_Emprestado1->Titulo, L_Emprestado1->Assunto, L_Emprestado1->Autor);
        }
    }
    for(; cliente1 != NULL; cliente1 = cliente1->prox)
    {
        aux1 = Aux_Cliente(aux1, cliente1->cd_Identificacao, cliente1->Nome );
        aux = cliente1->Emprestimo;
        for(; aux != NULL; aux = aux->prox)
        {
            if(aux->cd_registro == codigo)
            {
                aux1->Emprestimo = Inputar_Disponivel_Ordenadamente(aux1->Emprestimo, aux->cd_registro, aux->Titulo, aux->Assunto, autor);
            }
            else
            {
                aux1->Emprestimo = Inputar_Disponivel_Ordenadamente(aux1->Emprestimo, aux->cd_registro, aux->Titulo, aux->Assunto, aux->Autor);
            }
        }
    }
    aux1 = Ordenamento_Cliente(aux1);
    *L_Emprestado = aux2;
    *cliente = aux1;
}

void remocao_enter(char nome[])
{
    int i;
    for(i = 0; nome[i] != '\0'; i++)
    {
        if(nome[i]  == '\n')
        {
            nome[i] = '\0';
            break;
        }
    }
}

int identificador_vazio(char str)
{
    if(isdigit(str) == 0)
    {
        if(isupper(str) == 0)
        {
            if(islower(str) == 0)
            {
                return 1;
            }
        }
    }
    return 0;
}

#endif