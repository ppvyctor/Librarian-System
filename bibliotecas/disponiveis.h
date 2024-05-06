//Criação da biblioteca
#ifndef disponiveis_h
#define disponiveis_h

//importação das bibliotecas principais
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>

//Definição do tamanho do titulo, assunto e autor do livro
#define Tam_Assunto 101
#define Tam_Nome 51

typedef struct LIVROS_DISPONIVEIS
{
    int cd_registro;//quantidade de dígitos
    char Titulo[Tam_Nome], Assunto[Tam_Assunto], Autor[Tam_Nome];
    struct LIVROS_DISPONIVEIS *prox;
}Livros_Disponiveis;

//Abaixo esta uma função auxiliar que insere um livro na lista de livros Disponíveis.
Livros_Disponiveis* Aux_Disp(Livros_Disponiveis *list, int cd, char titulo[], char assunto[], char autor[])
{
    Livros_Disponiveis *aux;

    aux = (Livros_Disponiveis*)malloc(sizeof(Livros_Disponiveis));
    aux->cd_registro = cd;
    strcpy(aux->Titulo, titulo);
    strcpy(aux->Assunto, assunto);
    strcpy(aux->Autor, autor);
    aux->prox = list;
    return aux;
}

/*Abaixo, está a função que será usada para inserir um livro na lista de livros disponíveis
  Ela foi criada pois além de inserir um livro na lista de livros disponíveis, ela também, ordena os livros a medida em que se é inserido um livro novo.*/
Livros_Disponiveis* Inputar_Disponivel_Ordenadamente(Livros_Disponiveis *list, int cd, char titulo[], char assunto[], char autor[])
{
    Livros_Disponiveis *aux1;
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
                aux1 = Aux_Disp(aux1, cd, titulo, assunto, autor);
                identif++;
            }
            aux1 = Aux_Disp(aux1, list->cd_registro, list->Titulo, list->Assunto, list->Autor);
        }
        if(identif == 0)
        {
            aux1 = Aux_Disp(aux1, cd, titulo, assunto, autor);
        }
        for(; aux1 != NULL; aux1 = aux1->prox)
        {
            list = Aux_Disp(list, aux1->cd_registro, aux1->Titulo, aux1->Assunto, aux1->Autor);
        }
        return list;
    }
    else
    {
        aux1 = Aux_Disp(aux1, cd, titulo, assunto, autor);
        return aux1;
    }
}

//A função abaixo identifica se o livro digitado pelo usuário, já foi anteriormente cadastrado.
int Identificador_livro_existente(Livros_Disponiveis *list, char titulo[])
{
    for(; list != NULL; list = list->prox)
    {
        if(strcmp(list->Titulo, titulo) == 0) return 1;
    }
    return 0;
}

//Identificação de livro existente por codigo
int Identificador_livro_existente_por_codigo(Livros_Disponiveis *list, int codigo)
{
    for(; list != NULL; list = list->prox)
    {
        if(list->cd_registro == codigo) return 1;
    }
    return 0;
}

//Abaixo esta a função que faz a visualização que faz a visualização da lista de livros disponíveis
void print_livros_disponiveis(Livros_Disponiveis *list)
{
    if(list == NULL)
    {
        printf("Não há livros disponíveis no momento.\n\n");
    }
    else
    {
        printf("Abaixo está todos os livros disponíveis na biblioteca.\n\n");
        for(; list!=NULL; list = list->prox)
        {
            printf("Código do livro: %i\n", list->cd_registro);
            printf("\tTítulo: %s\n", list->Titulo);
            printf("\tAssunto: %s\n", list->Assunto);
            printf("\tAutor: %s\n\n", list->Autor);
        }
    }
    system("pause");
}

//Abaixo esta a função que faz a visualização de um livro de acordo com um código dado pelo cliente 
void print_visualizacao_livros_disponiveis_codigo(Livros_Disponiveis *list, int codigo)
{
    for(; list != NULL; list = list->prox)
    {
        if(list->cd_registro == codigo)
        {
            printf("Abaixo está as informações do Livro com o código %i:\n\n", codigo);
            printf("Código do livro: %i\n", list->cd_registro);
            printf("\tTítulo do livro: %s\n", list->Titulo);
            printf("\tAssunto do livro: \"%s\"\n", list->Assunto);
            printf("\tAutor do livro: %s\n\n", list->Autor);
            break;
        }
    }
}

//Abaixo esta a função que faz a visualização de um livro de acordo com um titulo dado pelo cliente 
void print_visualizacao_livros_disponiveis_titulo(Livros_Disponiveis *list, char titulo[])
{
    for(; list != NULL; list = list->prox)
    {
        if(strcmp(list->Titulo, titulo) == 0)
        {
            printf("Abaixo está as informações do Livro com o título \"%s\":\n\n", titulo);
            printf("Código do livro: %i\n", list->cd_registro);
            printf("\tTítulo do livro: %s\n", list->Titulo);
            printf("\tAssunto do livro: \"%s\"\n", list->Assunto);
            printf("\tAutor do livro: %s\n\n", list->Autor);
            break;
        }
    }
}

//Função que altera o titulo do livro.
Livros_Disponiveis* Edicao_titulo_livro_disponivel(Livros_Disponiveis *L_Disponiveis, int codigo, char titulo[])
{
    Livros_Disponiveis *aux;
    aux = NULL;
    for(; L_Disponiveis != NULL; L_Disponiveis = L_Disponiveis->prox)
    {
        if(L_Disponiveis->cd_registro == codigo)
        {
            aux = Inputar_Disponivel_Ordenadamente(aux, L_Disponiveis->cd_registro, titulo, L_Disponiveis->Assunto, L_Disponiveis->Autor);
        }
        else
        {
            aux = Inputar_Disponivel_Ordenadamente(aux, L_Disponiveis->cd_registro, L_Disponiveis->Titulo, L_Disponiveis->Assunto, L_Disponiveis->Autor);
        }
    }
    return aux;
}

//colocar a função de edição do assunto na lista de livros disponiveis
Livros_Disponiveis* Edicao_assunto_livro_disponivel(Livros_Disponiveis *L_Disponiveis, int codigo, char assunto[])
{
    Livros_Disponiveis *aux;
    aux = NULL;
    for(; L_Disponiveis != NULL; L_Disponiveis = L_Disponiveis->prox)
    {
        if(L_Disponiveis->cd_registro == codigo)
        {
            aux = Inputar_Disponivel_Ordenadamente(aux, L_Disponiveis->cd_registro, L_Disponiveis->Titulo, assunto, L_Disponiveis->Autor);
        }
        else
        {
            aux = Inputar_Disponivel_Ordenadamente(aux, L_Disponiveis->cd_registro, L_Disponiveis->Titulo, L_Disponiveis->Assunto, L_Disponiveis->Autor);
        }
    }
    return aux;
}

//colocar a função de edição do nome do autor na lista de livros disponiveis
Livros_Disponiveis* Edicao_autor_livro_disponivel(Livros_Disponiveis *L_Disponiveis, int codigo, char autor[])
{
    Livros_Disponiveis *aux;
    aux = NULL;
    for(; L_Disponiveis != NULL; L_Disponiveis = L_Disponiveis->prox)
    {
        if(L_Disponiveis->cd_registro == codigo)
        {
            aux = Inputar_Disponivel_Ordenadamente(aux, L_Disponiveis->cd_registro, L_Disponiveis->Titulo, L_Disponiveis->Assunto, autor);
        }
        else
        {
            aux = Inputar_Disponivel_Ordenadamente(aux, L_Disponiveis->cd_registro, L_Disponiveis->Titulo, L_Disponiveis->Assunto, L_Disponiveis->Autor);
        }
    }
    return aux;
}

//finalização da biblioteca
#endif