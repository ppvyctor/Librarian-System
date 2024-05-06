//Criação da biblioteca
#ifndef locados_h
#define locados_h

//importação das bibliotecas principais
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>

#define Tam_Assunto 101
#define Tam_Nome 51

typedef struct LIVROS_EMPRESTADOS
{
    int Cd_Identificacao_Cliente, Cd_Identificacao_Livro_Emprestado;
    char Titulo[Tam_Nome], Assunto[Tam_Assunto], Autor[Tam_Nome];
    struct LIVROS_EMPRESTADOS *prox;
}Livros_Emprestados;

//Abaixo é a função de inserir elementos na lista de livros.
Livros_Emprestados* Aux_Emprestados(Livros_Emprestados *list, int Cd_I_C, int Cd_I_L_E, char titulo[], char assunto[], char autor[])
{
    Livros_Emprestados *aux;
    aux = (Livros_Emprestados*)malloc(sizeof(Livros_Emprestados));
    aux->Cd_Identificacao_Cliente = Cd_I_C;
    aux->Cd_Identificacao_Livro_Emprestado = Cd_I_L_E;
    strcpy(aux->Titulo, titulo);
    strcpy(aux->Assunto, assunto);
    strcpy(aux->Autor, autor);
    aux->prox = list;
    return aux;
}

//Abaixo a função insere os livros que foram emprestados por ordem alfabetica
Livros_Emprestados* Inputar_Emprestados_Ordenadamente(Livros_Emprestados *list, int Cd_I_C, int Cd_I_L_E, char titulo[], char assunto[], char autor[])
{
    Livros_Emprestados *aux1;
    int identif;
    aux1 = NULL;
    identif = 0;

    /*Tivemos dificuldades na função de ordenação e inclusão de livros na lista de de livros disponiveis,
    já que, não estavamos conseguindo desenvolver um programa adequado para ordenar a lista a cada nova inclusão de livros.*/
    if(list != NULL)
    {
        for(; list != NULL; list = list->prox)
        {
            if(strcmp(autor, list->Autor) <= 0 && identif == 0)
            {
                aux1 = Aux_Emprestados(aux1, Cd_I_C, Cd_I_L_E, titulo, assunto, autor);
                identif++;
            }
            aux1 = Aux_Emprestados(aux1, list->Cd_Identificacao_Cliente, list->Cd_Identificacao_Livro_Emprestado, list->Titulo, list->Assunto, list->Autor);
        }
        if(identif == 0)
        {
            aux1 = Aux_Emprestados(aux1, Cd_I_C, Cd_I_L_E, titulo, assunto, autor);
        }
        for(; aux1 != NULL; aux1 = aux1->prox)
        {
            list = Aux_Emprestados(list, aux1->Cd_Identificacao_Cliente, aux1->Cd_Identificacao_Livro_Emprestado, aux1->Titulo, aux1->Assunto, aux1->Autor);
        }
        return list;
    }
    else
    {
        aux1 = Aux_Emprestados(aux1, Cd_I_C, Cd_I_L_E, titulo, assunto, autor);
        return aux1;
    }
}

//Função de identificação de livro existente por titulo
int Identificador_livro_Emprestado_existente(Livros_Emprestados *list, char titulo[])
{
    for(; list != NULL; list = list->prox)
    {
        if(strcmp(list->Titulo, titulo) == 0) return 1;
    }
    return 0;
}

//Função de identificação de livro existente por codigo
int Identificador_livro_Emprestado_existente_por_codigo(Livros_Emprestados *list, int codigo)
{
    for(; list != NULL; list = list->prox)
    {
        if(list->Cd_Identificacao_Livro_Emprestado == codigo) return 1;
    }
    return 0;
}

//Abaixo esta a função que faz a visualização que faz a visualização da lista de livros emprestados
void print_livros_emprestados(Livros_Emprestados *list)
{
    if(list == NULL)
    {
        printf("Não há livros emprestados no momento.\n\n");
    }
    else
    {
        for(; list != NULL; list = list->prox)
        {
            printf("Código do Livro: %i\n", list->Cd_Identificacao_Livro_Emprestado);
            printf("\tCódigo do cliente: %i\n", list->Cd_Identificacao_Cliente);
            printf("\tTitulo: %s\n", list->Titulo);
            printf("\tAssunto: %s\n", list->Assunto);
            printf("\tAutor: %s\n\n", list->Autor);
        }

    }
    system("pause");
}

//finalização da biblioteca
#endif