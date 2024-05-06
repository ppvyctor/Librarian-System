#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <ctype.h>
#include "bibliotecas/clientF.h"
#include "bibliotecas/disponiveis.h"
#include "bibliotecas/locados.h"
#include "bibliotecas/funcoes_aux.h"

#define Tam_Assunto 101
#define Tam_Nome 51

int main()
{
    setlocale(LC_ALL, "Portuguese");

    //Abaixo está a declaração das variáveis.
    Livros_Disponiveis *L_D;
    Livros_Emprestados *Livro_emprestado;
    Cliente *cliente;
    int opcao, opcao2, Codigo_Cliente, Codigo_Livro, identificador, i, cd_aux_cliente, cd_aux_Disponivel;
    char nome[Tam_Nome], titulo[Tam_Nome], assunto[Tam_Assunto], autor[Tam_Nome], res[1];

    Codigo_Cliente = 0;
    Codigo_Livro = 0;
    L_D = NULL;
    Livro_emprestado = NULL;
    cliente = NULL;

    printf("BEM VINDO À CENTRAL BIBLIOTECÁRIA!!!\n\n");
    while(1)
    {
        printf("Escolha uma das opções abaixo:\n");
        printf("\t1) Cadastro de novo livro.\n");
        printf("\t2) Cadastro de cliente.\n");
        printf("\t3) Realizar emprestimo de livro.\n");
        printf("\t4) Realizar devolução de livro.\n");
        printf("\t5) Visualização de livros emprestados.\n");
        printf("\t6) Visualização de livros disponíveis na Biblioteca.\n");
        printf("\t7) Visualização de lista de clientes.\n");
        printf("\t8) Editar cadastro de cliente ou Livros.\n");
        printf("\t9) Sair da Central.\n\n");
        printf("Digite o número da opcão desejada: ");
        scanf("%i", &opcao);
        identificador = 0;

        if(opcao == 1)
        {
            //Aqui está sendo realizado o cadastro de um novo livro.
            do
            {
                system("cls");
                Codigo_Livro++;
                while(1)
                {
                    printf("Digite o título do Livro: ");
                    fflush(stdin);
                    fgets(titulo, Tam_Nome, stdin);
                    remocao_enter(titulo);
                    
                    if(identificador_vazio(titulo[0]) == 1)
                    {
                        printf("\nOOOPS!! nenhuma digitação identificada, por favor tente novamente.\n\n");
                        system("pause");
                        system("cls");
                        continue;
                    }

                    if(titulo[0] == ' ')
                    {
                        printf("\nOOOPS!! No início da digitação, há um espaço em branco.\n\n");
                        system("pause");
                        system("cls");
                        continue;
                    }
                    if(Identificador_livro_existente(L_D, titulo))
                    {
                        printf("O Livro já é existente no catálogo.\n\n");
                        system("pause");
                        system("cls");
                        identificador++;
                        Codigo_Livro--;
                        break;
                    }
                    break;
                }
                while(identificador == 0)
                {
                    printf("Digite o assunto do livro: ");
                    fflush(stdin);
                    fgets(assunto, Tam_Assunto, stdin);
                    remocao_enter(assunto);

                    if(assunto[0] == ' ')
                    {
                        printf("\nOOOPS!!! tem um espaço vazio no início da digitação.\n\n");
                        system("pause");
                        system("cls");
                        printf("Digite o título do Livro: %s\n", titulo);
                        continue;
                    }

                    if(identificador_vazio(assunto[0]) == 1)
                    {
                        printf("\nOOOPS!! nenhuma digitação identificada, por favor tente novamente.\n\n");
                        system("pause");
                        system("cls");
                        continue;
                    }

                    break;
                }
                while(identificador == 0)
                {
                    printf("Digite o nome do autor(a) do livro: ");
                    fflush(stdin);
                    fgets(autor, Tam_Nome, stdin);
                    remocao_enter(autor);

                    if(autor[0] == ' ')
                    {
                        printf("\nOOOPS!!! Há um espaço vazio no início do nome.\n\n");
                        system("pause");
                        system("cls");
                        printf("Digite o título do Livro: %s\n", titulo);
                        printf("Digite o assunto do livro: %s\n", assunto);
                        continue;
                    }
                    
                    if(identificador_vazio(autor[0]) == 1)
                    {
                        printf("\nOOOPS!! nenhuma digitação identificada, por favor tente novamente.\n\n");
                        system("pause");
                        system("cls");
                        continue;
                    }

                    for(i = 0; autor[i] != '\0'; i++)
                    {
                        if(isdigit(autor[i]))
                        {
                            identificador++;
                            break;
                        }
                    }
                    if(identificador != 0)
                    {
                        identificador = 0;
                        printf("\nOOOPS!!! Não se pode colocar número ou símbolos em um assunto de um livro.\n\n");
                        system("pause");
                        system("cls");
                        printf("Digite o título do Livro: %s\n", titulo);
                        printf("Digite o assunto do livro: %s\n", assunto);
                        continue;
                    }
                    break;
                }
                if(identificador == 0)
                {
                    autor[0] = toupper(autor[0]);
                    if(isdigit(titulo[0]) == 0)
                    {
                        titulo[0] = toupper(titulo[0]);
                    }
                    assunto[0] = toupper(assunto[0]);
                    for(i = 1; autor[i] != '\0'; i++)
                    {
                        if(isdigit(titulo[i]) == 0)
                        {
                            titulo[i] = tolower(titulo[i]);
                        }
                        autor[i] = tolower(autor[i]);
                    }
                    for(i = 1; assunto[i] != '\0'; i++)
                    {
                        assunto[i] = tolower(assunto[i]);
                    }
                    L_D = Inputar_Disponivel_Ordenadamente(L_D, Codigo_Livro, titulo, assunto, autor);
                    system("cls");
                    printf("O livro \"%s\" do autor(a) \"%s\" foi cadastrado com sucesso!!\n", titulo, autor);
                    printf("O código do livro é: %i\n\n", Codigo_Livro);
                    printf("ATENÇÃO: Para realizar uma alteração de qualquer informação do livro, será solicitado o código do mesmo!!\n\n");
                    system("pause");
                }
                identificador = 0;
                while(1)
                {
                    system("cls");
                    printf("Escolha uma das opções abaixo: \n");
                    printf("\t1) Cadastrar um novo livro.\n");
                    printf("\t2) Voltar ao menu principal.\n\n");
                    printf("Digite escolha uma das opções acima: ");
                    scanf("%i", &opcao);

                    if(opcao == 1 || opcao == 2)
                    {
                        break;
                    }
                    else
                    {
                        printf("Digitação inválida, por favor tente novamente.\n\n");
                        system("pause");
                        continue;
                    }
                }
            }while(opcao == 1);

            system("cls");
            continue;
        }
        //Abaixo está sendo cadastrado um novo cliente.
        if(opcao == 2)
        {
            do
            {
                system("cls");
                Codigo_Cliente++;
                //Abaixo estamos solicitando o nome do cliente para seu cadastro
                while(1)
                {
                    printf("Digite o nome do(a) cliente: ");
                    fflush(stdin);
                    fgets(nome, Tam_Nome, stdin);
                    remocao_enter(nome);

                    if(identificador_vazio(nome[0]) == 1)
                    {
                        printf("\nOOOPS!! nenhuma digitação identificada, por favor tente novamente.\n\n");
                        system("pause");
                        system("cls");
                        continue;
                    }

                    if(Identificador_Clientes_Existentes(cliente, nome))
                    {
                        printf("OOOPS!!! O(A) cliente já foi cadastrado no sistema.\n\n");
                        system("pause");
                        system("cls");
                        Codigo_Cliente--;
                    }
                    if(nome[0] == ' ')
                    {
                        printf("OOPS!! Há um espaço no começo da digitação.\n\n");
                        system("pause");
                        system("cls");
                        continue;
                    }
                    for(i = 0; nome[i] != '\0'; i++)
                    {
                        if(isdigit(nome[i]))
                        {
                            identificador++;
                            break;
                        }
                    }
                    if(identificador != 0)
                    {
                        identificador = 0;
                        printf("Há um número ou símbolo na digitação do nome do(a) cliente, por favor, reescreva o nome.\n\n");
                        system("pause");
                        system("cls");
                        continue;
                    }
                    nome[0] = toupper(nome[0]);
                    for(i = 1; nome[i] != '\0'; i++)
                    {
                        nome[i] = tolower(nome[i]);
                    }
                    break;
                }
                cliente = Aux_Cliente(cliente, Codigo_Cliente, nome);
                cliente = Ordenamento_Cliente(cliente);
                system("cls");
                printf("O cliente \"%s\" foi cadastrado com sucesso!!\n", nome);
                printf("O código do cliente é: %i\n", Codigo_Cliente);
                printf("\nATENÇÃO: Para realizar uma alteração do nome do cliente, será necessário saber o código do mesmo.\n\n");
                system("pause");
                while(1)
                {
                    system("cls");
                    printf("Escolha uma das opções abaixo: \n");
                    printf("\t1) Cadastrar outro cliente.\n");
                    printf("\t2) Voltar ao menu principal.\n\n");
                    printf("Digite ao lado o número da opção desejada: ");
                    scanf("%i", &opcao);

                    if(opcao == 1 || opcao == 2)
                    {
                        break;
                    }
                    printf("OOOPS!! O número digitado, não condiz com o solicitado.\n\n");
                    system("pause");
                }
            }while(opcao == 1);
            system("cls");
            continue;
        }

        //Abaixo iá ser realizado o processo de empréstimo de um livro
        if(opcao == 3 || opcao == 4)
        {
            do
            {
                while(1)
                {
                    system("cls");
                    if(opcao == 3)
                    {
                        printf("Escolha como deseja procurar o cliente que irá realizar o empréstimo do livro.\n");
                    }
                    else
                    {
                        printf("Escolha como deseja procurar o cliente que irá realizar a devolução do livro.\n");
                    }
                    printf("\t1) Código do cliente.\n");
                    printf("\t2) Nome do cliente.\n\n");
                    printf("Digite a opção desejada: ");
                    scanf("%i", &opcao2);

                    if(opcao2 == 1 || opcao2 == 2)
                    {
                        break;
                    }
                    printf("O número digitado não condiz com o solicitado.\n\n");
                    system("pause");
                }
                if(opcao2 == 1)
                {
                    while(1)
                    {
                        system("cls");
                        printf("Digite o codigo do cliente: ");
                        scanf("%i", &cd_aux_cliente);
                        if(Identificador_Clientes_Existentes_codigo(cliente, cd_aux_cliente))
                        {
                            break;
                        }
                        system("cls");
                        printf("Código do cliente não encontrado no sistema.\n");
                        printf("Digite qualquer coisa diferente de \"n ou N\" para tentar novamente uma digitação: ");
                        scanf("%s", &res[0]);
                        res[0] = toupper(res[0]);
                        if(res[0] == 'N')
                        {
                            identificador++;
                            break;
                        }
                    }
                    if(identificador == 0)
                    {
                        while(1)
                        {
                            system("cls");
                            if(opcao == 3)
                            {
                                printf("Escolha abaixo como deseja realizar a procura do livro que será emprestado.\n");
                            }
                            else
                            {
                                printf("Escolha abaixo como deseja realizar a procura do livro que será devolvido.\n");
                            }
                            printf("\t1) Código do livro.\n");
                            printf("\t2) Título do livro.\n");
                            printf("Digite a opção desejada ao lado: ");
                            scanf("%i", &opcao2);;

                            if(opcao2 == 1 || opcao2 == 2)
                            {
                                break;
                            }
                            printf("OOOPS!! Digite apenas 1 ou 2 para realizae a busca pelo livro emprestado.\n\n");
                            system("pause");
                        }
                        if(opcao2 == 1)
                        {
                            do
                            {
                                system("cls");
                                printf("Digite o código do livro: ");
                                scanf("%i", &cd_aux_Disponivel);
                                if(opcao == 3)
                                {
                                    if(Identificador_livro_existente_por_codigo(L_D, cd_aux_Disponivel))
                                    {
                                        identificador++;
                                        break;
                                    }
                                    if(Identificador_livro_Emprestado_existente_por_codigo(Livro_emprestado, cd_aux_Disponivel))
                                    {
                                        printf("O livro já foi alugado.\n\n");
                                    }
                                    else
                                    {
                                        printf("OOOPS!! O código do livro é inválido.\n\n");
                                    }
                                }
                                else
                                {
                                    if(Identificador_livro_Emprestado_existente_por_codigo(Livro_emprestado, cd_aux_Disponivel))
                                    {
                                        identificador++;
                                        break;
                                    }
                                    if(Identificador_livro_existente_por_codigo(L_D, cd_aux_Disponivel))
                                    {
                                        printf("Este livro ainda não foi alugado.\n\n");
                                    }
                                    else
                                    {
                                        printf("OOOPS!! O código do livro é inválido.\n\n");
                                    }
                                }
                                system("pause");
                                printf("\nDigite qualquer coisa diferente de \"n ou N\" para realizar outra digitação: ");
                                scanf("%s", &res[0]);
                                res[0] = toupper(res[0]);
                            }while(res[0] != 'N');
                            if(identificador != 0)
                            {
                                system("cls");
                                identificador = 0;
                                if(opcao == 3)
                                {
                                    emprestimo_codigo_cliente_e_livro(&L_D, &Livro_emprestado, &cliente, cd_aux_cliente, cd_aux_Disponivel);
                                    cliente = Ordenamento_Cliente(cliente);
                                    printf("Empréstimo realizado com sucesso!!!\n\n");
                                }
                                else
                                {
                                    devolucao_codigo_cliente_e_livro(&L_D, &Livro_emprestado, &cliente, cd_aux_cliente, cd_aux_Disponivel);
                                    cliente = Ordenamento_Cliente(cliente);
                                    printf("Devolução realizada com sucesso!!!\n\n");
                                }
                                system("pause");
                            }
                        }
                        else
                        {
                            while(1)
                            {
                                system("cls");
                                printf("Digite o título do livro: ");
                                fflush(stdin);
                                fgets(titulo, Tam_Nome, stdin);
                                remocao_enter(titulo);

                                if(identificador_vazio(titulo[0]) == 1)
                                {
                                    printf("\nOOOPS!! nenhuma digitação identificada, por favor tente novamente.\n\n");
                                    system("pause");
                                    system("cls");
                                    continue;
                                }

                                if(isdigit(titulo[0]) == 0)
                                {
                                    titulo[0] = toupper(titulo[0]);
                                }
                                for(i = 1; titulo[i]!= '\0'; i++)
                                {
                                    if(isdigit(titulo[i]) == 0)
                                    {
                                        titulo[i] = tolower(titulo[i]);
                                    }
                                }
                                if(opcao == 3)
                                {
                                    if(Identificador_livro_existente(L_D, titulo))
                                    {
                                        identificador++;
                                        break;
                                    }
                                    if(Identificador_livro_Emprestado_existente(Livro_emprestado, titulo))
                                    {
                                        printf("O livro já foi alugado.\n\n");
                                    }
                                    else
                                    {
                                        printf("OOOPS!! Não há livro com esse títilo é inválido.\n\n");
                                    }
                                }
                                else
                                {
                                    if(Identificador_livro_Emprestado_existente(Livro_emprestado, titulo))
                                    {
                                        identificador++;
                                        break;
                                    }
                                    if(Identificador_livro_existente(L_D, titulo))
                                    {
                                        printf("O Livro ainda não foi alugado.\n\n");
                                    }
                                    else
                                    {
                                        printf("OOOPS!! O título do livro é inválido.\n\n");
                                    }
                                }
                                system("pause");
                                printf("\nDigite qualquer coisa diferente de \"n ou N\" para realizar outra digitação: ");
                                scanf("%s", &res[0]);
                                res[0] = toupper(res[0]);

                                if(res[0] == 'N')
                                {
                                    break;
                                }
                            }
                            if(identificador != 0)
                            {
                                system("cls");
                                identificador = 0;
                                if(opcao == 3)
                                {
                                    emprestimo_codigo_cliente_titulo_livro(&L_D, &Livro_emprestado, &cliente, cd_aux_cliente, titulo);
                                    cliente = Ordenamento_Cliente(cliente);
                                    printf("Empréstimo realizado com sucesso!!!\n\n");
                                }
                                else
                                {
                                    devolucao_codigo_cliente_titulo_livro(&L_D, &Livro_emprestado, &cliente, cd_aux_cliente, titulo);
                                    cliente = Ordenamento_Cliente(cliente);
                                    printf("Devolução realizada com sucesso!!!\n\n");
                                }
                                system("pause");
                            }
                        }
                    }
                    else
                    {
                        identificador = 0;
                    }
                }
                else
                {
                    while(1)
                    {
                        system("cls");
                        printf("Digite o nome do cliente: ");
                        fflush(stdin);
                        fgets(nome, Tam_Nome, stdin);
                        remocao_enter(nome);

                        if(identificador_vazio(nome[0]) == 1)
                        {
                            printf("\nOOOPS!! nenhuma digitação identificada, por favor tente novamente.\n\n");
                            system("pause");
                            system("cls");
                            continue;
                        }

                        nome[0] = toupper(nome[0]);
                        for(i = 1; nome[i]!= '\0'; i++)
                        {
                            nome[i] = tolower(nome[i]);
                        }
                        if(Identificador_Clientes_Existentes(cliente, nome))
                        {
                            break;
                        }
                        system("cls");
                        printf("Nome do cliente não encontrado no sistema.\n");
                        printf("Digite qualquer coisa diferente de \"n ou N\" para tentar novamente uma digitação: ");
                        scanf("%s", &res[0]);
                        res[0] = toupper(res[0]);
                        if(res[0] == 'N')
                        {
                            identificador++;
                            break;
                        }
                    }
                    if(identificador == 0)
                    {
                        while(1)
                        {
                            system("cls");
                            if(opcao == 3)
                            {
                                printf("Escolha abaixo como deseja realizar a procura do livro que será emprestado.\n");
                            }
                            else
                            {
                                printf("Escolha abaixo como deseja realizar a procura do livro que será devolvido.\n");
                            }
                            printf("\t1) Código do livro.\n");
                            printf("\t2) Título do livro.\n");
                            printf("Digite a opção desejada ao lado: ");
                            scanf("%i", &opcao2);
                            if(opcao2 == 1 || opcao2 == 2)
                            {
                                break;
                            }
                            printf("OOOPS!! Digite apenas 1 ou 2 para realizae a busca pelo livro emprestado.\n\n");
                            system("pause");
                        }
                        if(opcao2 == 1)
                        {
                            while(1)
                            {
                                system("cls");
                                printf("Digite o código do livro: ");
                                scanf("%i", &cd_aux_Disponivel);
                                if(opcao == 3)
                                {
                                    if(Identificador_livro_existente_por_codigo(L_D, cd_aux_Disponivel))
                                    {
                                        identificador++;
                                        break;
                                    }
                                    if(Identificador_livro_Emprestado_existente_por_codigo(Livro_emprestado, cd_aux_Disponivel))
                                    {
                                        printf("O livro já foi alugado.\n\n");
                                    }
                                    else
                                    {
                                        printf("OOOPS!! O código do livro é inválido.\n\n");
                                    }
                                }
                                else
                                {
                                    if(Identificador_livro_Emprestado_existente_por_codigo(Livro_emprestado, cd_aux_Disponivel))
                                    {
                                        identificador++;
                                        break;
                                    }
                                    if(Identificador_livro_existente_por_codigo(L_D, cd_aux_Disponivel))
                                    {
                                        printf("O livro ainda não foi alugado.\n\n");
                                    }
                                    else
                                    {
                                        printf("OOOPS!! O código do livro é inválido.\n\n");
                                    }
                                }
                                system("pause");
                                printf("\nDigite qualquer coisa diferente de \"n ou N\" para realizar outra digitação: ");
                                scanf("%s", &res[0]);
                                res[0] = toupper(res[0]);

                                if(res[0] == 'N')
                                {
                                    break;
                                }
                            }
                            if(identificador != 0)
                            {
                                system("cls");
                                identificador = 0;
                                if(opcao == 3)
                                {
                                    emprestimo_nome_cliente_e_codigo_Livro(&L_D, &Livro_emprestado, &cliente, nome, cd_aux_Disponivel);
                                    cliente = Ordenamento_Cliente(cliente);
                                    printf("Empréstimo realizado com sucesso!!!\n\n");
                                }
                                else
                                {
                                    devolucao_nome_cliente_e_codigo_livro(&L_D, &Livro_emprestado,& cliente, nome, cd_aux_Disponivel);
                                    cliente = Ordenamento_Cliente(cliente);
                                    printf("Devolução realizada com sucesso!!!\n\n");
                                }
                                system("pause");
                            }
                        }
                        else
                        {
                            while(1)
                            {
                                system("cls");
                                printf("Digite o título do livro: ");
                                fflush(stdin);
                                fgets(titulo, Tam_Nome, stdin);
                                remocao_enter(titulo);

                                if(identificador_vazio(titulo[0]) == 1)
                                {
                                    printf("\nOOOPS!! nenhuma digitação identificada, por favor tente novamente.\n\n");
                                    system("pause");
                                    system("cls");
                                    continue;
                                }

                                titulo[0] = toupper(titulo[0]);
                                if(isdigit(titulo[0]) == 0)
                                {
                                    titulo[0] = toupper(titulo[0]);
                                }
                                for(i = 1; titulo[i]!= '\0'; i++)
                                {
                                    if(isdigit(titulo[i]) == 0)
                                    {
                                        titulo[i] = tolower(titulo[i]);
                                    }
                                }
                                if(opcao == 3)
                                {
                                    if(Identificador_livro_existente(L_D, titulo))
                                    {
                                        identificador++;
                                        break;
                                    }
                                    if(Identificador_livro_Emprestado_existente(Livro_emprestado, titulo))
                                    {
                                        printf("O livro já foi alugado.\n");
                                    }
                                    else
                                    {
                                        printf("OOOPS!! O título do livro é inválido.\n\n");
                                    }
                                }
                                else
                                {
                                    if(Identificador_livro_Emprestado_existente(Livro_emprestado, titulo))
                                    {
                                        identificador++;
                                        break;
                                    }
                                    if(Identificador_livro_existente(L_D, titulo))
                                    {
                                        printf("O livro ainda não foi alugado.\n\n");
                                    }
                                    else
                                    {
                                        printf("OOOPS!! O titulo do livro é inválido.\n\n");
                                    }
                                }
                                system("pause");
                                printf("\nDigite qualquer coisa diferente de \"n ou N\" para realizar outra digitação: ");
                                scanf("%s", &res[0]);
                                res[0] = toupper(res[0]);

                                if(res[0] == 'N')
                                {
                                    break;
                                }
                            }
                            if(identificador != 0)
                            {
                                system("cls");
                                identificador = 0;
                                if(opcao == 3)
                                {
                                    emprestimo_nome_cliente_e_Livro(&L_D, &Livro_emprestado, &cliente, nome, titulo);
                                    cliente = Ordenamento_Cliente(cliente);
                                    printf("Empréstimo realizado com sucesso!!!\n\n");
                                }
                                else
                                {
                                    devolucao_nome_cliente_e_livro(&L_D, &Livro_emprestado, &cliente, nome, titulo);
                                    cliente = Ordenamento_Cliente(cliente);
                                    printf("Devolução realizada com sucesso!!!\n\n");
                                }
                                system("pause");
                            }
                        }
                    }
                    else
                    {
                        identificador = 0;
                    }
                }

                while(1)
                {
                    system("cls");
                    printf("Escolha uma das opções abaixo.\n");
                    printf("\t1) Realizar outro empréstimo de livro.\n");
                    printf("\t2) Voltar ao menu principal.\n\n");
                    printf("Digite um número da opção desejada ao lado: ");
                    scanf("%i", &opcao2);

                    if(opcao2 == 1 || opcao2 == 2)
                    {
                        break;
                    }
                    printf("OOOPS!! O número digitado não condiz com o solicitado.\n\n");
                    system("pause");
                }
            } while(opcao2 == 1);
            system("cls");
            continue;
        }
        if(opcao == 5 || opcao == 6 || opcao == 7)
        {
            while(1)
            {   while(1)
                {
                    system("cls");
                    printf("Escolha uma das opções abaixo.\n");
                    if(opcao == 5)
                    {
                        printf("\t1) Visualizar os livros Emprestados à um cliente escolhido.\n");
                        printf("\t2) Visualizar todos os clientes com seus respectivos livros alugados .\n");
                        printf("\t3) Visualizar com mais detalhes a informação de um livro emprestado escolhido.\n");
                        printf("\t4) Visualizar todos os livros emprestados.\n\n");
                    }
                    else
                    {
                        if(opcao == 6)
                        {
                            printf("\t1) Visualizar os livros disponíveis procurando pelo código.\n");
                            printf("\t2) Visualizar todos os livros disponíveis procurando por título.\n");
                            printf("\t3) Visualizar todos os livros disponíveis.\n\n");
                        }
                        else
                        {
                            printf("\t1) Visualizar todos os clientes procurando pelo código.\n");
                            printf("\t2) Visualizar todos os clienres procurando por nome.\n");
                            printf("\t3) Visualizar todos os clientes cadastrados.\n\n");
                        }
                    }
                    printf("Digite a opção escolhida ao lado: ");
                    scanf("%i", &opcao2);
                    if(opcao2 == 4 && opcao == 5)
                    {
                        break;
                    }
                    if(opcao2 < 4 && opcao2 > 0)
                    {
                        break;
                    }
                    printf("OOOPS!! O número digitado não condiz com o solicitado.\n\n");
                    system("pause");
                }
                system("cls");
                if(opcao == 5)
                {
                    if(opcao2 == 1)
                    {
                        while(1)
                        {
                            system("cls");
                            printf("1) Código do cliente.\n");
                            printf("2) Nome do cliente.\n\n");
                            printf("Digite uma das opções abaixo: ");
                            scanf("%i", &opcao2);
                            if(opcao2 < 3 && opcao2 > 0)
                            {
                                break;
                            }
                            printf("OOOPS!!! opção incorreta, o número digitado deverá ser 1 ou 2.\n\n");
                            system("pause");
                            printf("cls");
                            printf("Digite qualquer coisa diferente de \"n ou N\" para continuar digitando: ");
                            scanf("%s", &res[0]);
                            res[0] = toupper(res[0]);
                            if(res[0] == 'N')
                            {
                                identificador++;
                                break;
                            }
                        }
                        if(identificador != 0)
                        {
                            identificador = 0;
                        }
                        else
                        {
                            while(1)
                            {
                                system("cls");
                                if(opcao2 == 1)
                                {
                                    printf("Digite o código do cliente ao lado: ");
                                    scanf("%i", &cd_aux_cliente);
                                    if(Identificador_Clientes_Existentes_codigo(cliente, cd_aux_cliente) == 1)
                                    {
                                        system("cls");
                                        print_emprestimo_cliente_codigo(cliente, cd_aux_cliente);
                                        system("pause");
                                        break;
                                    }
                                    else
                                    {
                                        printf("O código do cliente não está cadastrado.\n\n");
                                        printf("Digite qualquer coisa diferente de \"n ou N\" para tentar uma nova digitação: ");
                                        scanf("%s", &res[0]);
                                        res[0] = toupper(res[0]);
                                        if(res[0] == 'N')
                                        {
                                            break;
                                        }
                                    }
                                }
                                else
                                {
                                    printf("Digite o nome do cliente ao lado: ");
                                    fflush(stdin);
                                    fgets(nome, Tam_Nome, stdin);
                                    remocao_enter(nome);

                                    if(identificador_vazio(nome[0]) == 1)
                                    {
                                        printf("\nOOOPS!! nenhuma digitação identificada, por favor tente novamente.\n\n");
                                        system("pause");
                                        system("cls");
                                        continue;
                                    }

                                    nome[0] = toupper(nome[0]);
                                    for(i = 1; nome[i] != '\0'; i++)
                                    {
                                        nome[i] = tolower(nome[i]);
                                    }
                                    if(Identificador_Clientes_Existentes(cliente, nome))
                                    {
                                        system("cls");
                                        print_emprestimo_cliente_nome(cliente, nome);
                                        system("pause");
                                        break;
                                    }
                                    else
                                    {
                                        printf("O código do cliente não está cadastrado.\n\n");
                                        printf("Digite qualquer coisa diferente de \"n ou N\" para tentar uma nova digitação: ");
                                        scanf("%s", &res[0]);
                                        res[0] = toupper(res[0]);
                                        if(res[0] == 'N')
                                        {
                                            break;
                                        }
                                    }
                                }
                            }
                        }
                    }
                    else
                    {
                        if(opcao2 == 2)
                        {
                            print_livros_emprestados_por_cliente(cliente);
                            system("pause");
                            system("cls");
                        }
                        else
                        {
                            if(opcao2 == 3)
                            {
                                while(1)
                                {
                                    system("cls");
                                    printf("1) Código do livro.\n");
                                    printf("2) Título do livro.\n\n");
                                    printf("Digite uma das opções abaixo: ");
                                    scanf("%i", &opcao2);
                                    if(opcao2 < 3 && opcao2 > 0)
                                    {
                                        break;
                                    }
                                    printf("OOOPS!!! opção incorreta, o número digitado deverá ser 1 ou 2.\n\n");
                                    system("pause");
                                    printf("cls");
                                    printf("Digite qualquer coisa diferente de \"n ou N\" para continuar digitando: ");
                                    scanf("%s", &res[0]);
                                    res[0] = toupper(res[0]);
                                    if(res[0] == 'N')
                                    {
                                        identificador++;
                                        break;
                                    }
                                }
                                if(identificador != 0)
                                {
                                    identificador = 0;
                                }
                                else
                                {
                                    while(1)
                                    {
                                        system("cls");
                                        if(opcao2 == 1)
                                        {
                                            printf("Digite o código do livro ao lado: ");
                                            scanf("%i", &cd_aux_Disponivel);
                                            if(Identificador_livro_Emprestado_existente_por_codigo(Livro_emprestado, cd_aux_Disponivel) == 1 || Identificador_livro_existente_por_codigo(L_D, cd_aux_Disponivel) == 1)
                                            {
                                                system("cls");
                                                print_Livro_Emprestado_codigo(Livro_emprestado, L_D, cd_aux_Disponivel);
                                                system("pause");
                                                break;
                                            }
                                            else
                                            {
                                                printf("O código digitado não está cadastrado.\n\n");
                                                printf("Digite qualquer coisa diferente de \"n ou N\" para tentar uma nova digitação: ");
                                                scanf("%s", &res[0]);
                                                res[0] = toupper(res[0]);
                                                if(res[0] == 'N')
                                                {
                                                    break;
                                                }
                                            }
                                        }
                                        else
                                        {
                                            printf("Digite o título do livro ao lado: ");
                                            fflush(stdin);
                                            fgets(titulo, Tam_Nome, stdin);
                                            remocao_enter(titulo);

                                            if(identificador_vazio(titulo[0]) == 1)
                                            {
                                                printf("\nOOOPS!! nenhuma digitação identificada, por favor tente novamente.\n\n");
                                                system("pause");
                                                system("cls");
                                                continue;
                                            }

                                            if(isdigit(titulo[0]) == 0)
                                            {
                                                titulo[0] = toupper(titulo[0]);
                                            }
                                            for(i = 1; titulo[i] != '\0'; i++)
                                            {
                                                if(isdigit(titulo[i]) == 0)
                                                {
                                                    titulo[i] = tolower(titulo[i]);
                                                }
                                            }
                                            if(Identificador_livro_Emprestado_existente(Livro_emprestado, titulo) == 1 || Identificador_livro_existente(L_D, titulo) == 1)
                                            {
                                                system("cls");
                                                print_Livro_Emprestado_titulo(Livro_emprestado, L_D, titulo);
                                                system("pause");
                                                break;
                                            }
                                            else
                                            {
                                                printf("O código digitado não está cadastrado.\n\n");
                                                printf("Digite qualquer coisa diferente de \"n ou N\" para tentar uma nova digitação: ");
                                                scanf("%s", &res[0]);
                                                res[0] = toupper(res[0]);
                                                if(res[0] == 'N')
                                                {
                                                    break;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                            else
                            {
                                system("cls");
                                print_livros_emprestados(Livro_emprestado);
                            }
                        }
                    }
                }
                else
                {
                    if(opcao == 6)
                    {
                        if(opcao2 == 1)
                        {
                            do
                            {
                                system("cls");
                                printf("Digite o código do livro ao lado: ");
                                scanf("%i", &cd_aux_Disponivel);
                                if(cd_aux_Disponivel < 1)
                                {
                                    printf("OOPS!! não se tem código de livros disponíveis menores ou igual a 0.\n\n");
                                    system("pause");
                                    system("cls");
                                }
                                else
                                {
                                    if(Identificador_livro_existente_por_codigo(L_D, cd_aux_Disponivel) == 1)
                                    {
                                        identificador = 0;
                                        system("cls");
                                        print_visualizacao_livros_disponiveis_codigo(L_D, cd_aux_Disponivel);
                                        system("pause");
                                        break;
                                    }
                                    else
                                    {
                                        printf("OOPS!! o codigo do livro não foi encontrado.\n\n");
                                        system("pause");
                                        system("cls");
                                    }
                                }
                                printf("Digite qualquer coisa diferente de \"n ou N\" para continuar digitando um código: ");
                                scanf("%s", &res[0]);
                                res[0] = toupper(res[0]);
                            }while(res[0] != 'N');
                        }
                        else
                        {
                            if(opcao2 == 2)
                            {
                                do
                                {
                                    system("cls");
                                    printf("Digite o título do livro: ");
                                    fflush(stdin);
                                    fgets(titulo, Tam_Nome, stdin);
                                    remocao_enter(titulo);

                                    if(identificador_vazio(titulo[0]) == 1)
                                    {
                                        printf("\nOOOPS!! nenhuma digitação identificada, por favor tente novamente.\n\n");
                                        system("pause");
                                        system("cls");
                                        continue;
                                    }

                                    if(titulo[0] == ' ')
                                    {
                                        printf("OOOPS!! há um espaço em branco no início do titulo.\n\n");
                                        system("pause");
                                        system("cls");
                                    }
                                    else
                                    {
                                        titulo[0] = toupper(titulo[0]);
                                        for(i = 1; i < Tam_Nome; i++)
                                        {
                                            if(isdigit(titulo[i]) == 0)
                                            {
                                                titulo[i] = tolower(titulo[i]);
                                            }
                                        }
                                        if(Identificador_livro_existente(L_D, titulo) == 1)
                                        {
                                            system("cls");
                                            print_visualizacao_livros_disponiveis_titulo(L_D, titulo);
                                            system("pause");
                                            break;
                                        }
                                        else
                                        {
                                            printf("OOPS!! o título do livro não foi encontrado.\n\n");

                                            system("pause");
                                            system("cls");
                                        }
                                    }

                                    printf("Digite qualquer coisa diferente de \"n ou N\" para continuar digitando um título: ");
                                    scanf("%s", &res[0]);
                                    res[0] = toupper(res[0]);
                                }while(res[0] != 'N');
                            }
                            else
                            {
                                print_livros_disponiveis(L_D);
                            }
                        }
                    }
                    else
                    {
                        if(opcao2 == 1)
                        {
                            do
                            {
                                system("cls");
                                printf("Digite o código do cliente ao lado: ");
                                scanf("%i", &cd_aux_cliente);
                                if(cd_aux_cliente < 1)
                                {
                                    printf("OOPS!! não se tem códigos de cliente menor ou igual a 0.\n\n");
                                    system("pause");
                                    system("cls");
                                }
                                else
                                {
                                    if(Identificador_Clientes_Existentes_codigo(cliente, cd_aux_cliente) == 1)
                                    {
                                        identificador = 0;
                                        system("cls");
                                        print_clientes_codigo(cliente, cd_aux_cliente);
                                        system("pause");
                                        break;
                                    }
                                    else
                                    {
                                        printf("OOPS!! o codigo do cliente não foi encontrado.\n\n");
                                        system("pause");
                                        system("cls");
                                    }
                                }
                                printf("Digite qualquer coisa diferente de \"n ou N\" para continuar digitando um código: ");
                                scanf("%s", &res[0]);
                                res[0] = toupper(res[0]);
                            }while(res[0] != 'N');
                        }
                        else
                        {
                            if(opcao2 == 2)
                            {
                                do
                                {
                                    system("cls");
                                    printf("Digite o nome do cliente: ");
                                    fflush(stdin);
                                    fgets(nome, Tam_Nome, stdin);
                                    remocao_enter(nome);

                                    if(identificador_vazio(nome[0]) == 1)
                                    {
                                        printf("\nOOOPS!! nenhuma digitação identificada, por favor tente novamente.\n\n");
                                        system("pause");
                                        system("cls");
                                        continue;
                                    }

                                    identificador = 0;
                                    if(nome[0] == ' ')
                                    {
                                        printf("OOOPS!! há um espaço em branco no início do titulo.\n\n");
                                        system("pause");
                                        system("cls");
                                    }
                                    else
                                    {
                                        if(isdigit(nome[0]) != 0)
                                        {
                                            printf("Não se pode ter número no nome do cliente.\n\n");
                                            system("pause");
                                            system("cls");
                                        }
                                        else
                                        {
                                            nome[0] = toupper(nome[0]);
                                            identificador = 0;
                                            for(i = 1; i < Tam_Nome; i++)
                                            {
                                                if(isdigit(nome[i]))
                                                {
                                                    identificador++;
                                                    break;
                                                }
                                                nome[i] = tolower(nome[i]);
                                            }
                                            if(identificador != 0)
                                            {
                                                identificador = 0;
                                                printf("Não se pode ter digitação de número no nome do cliente.\n\n");
                                                system("pause");
                                                system("cls");
                                            }
                                            else
                                            {
                                                if(Identificador_Clientes_Existentes(cliente, nome) == 1)
                                                {
                                                    system("cls");
                                                    print_clientes_nome(cliente, nome);
                                                    system("pause");
                                                    break;
                                                }
                                                else
                                                {
                                                    printf("OOPS!! o nome do cliente não foi encontrado.\n\n");
                                                    system("pause");
                                                    system("cls");
                                                }
                                            }
                                        }
                                    }
                                    printf("Digite qualquer coisa diferente de \"n ou N\" para continuar digitando um título: ");
                                    scanf("%s", &res[0]);
                                    res[0] = toupper(res[0]);
                                }while(res[0] != 'N');
                            }
                            else
                            {
                                print_clientes_cadastrados(cliente);
                            }
                        }
                    }
                }

                while(1)
                {
                    system("cls");
                    printf("Escolha uma das opções abaixo: \n");
                    if(opcao == 5)
                    {
                        printf("\t1) Vizualizar novamente todas as opções de visualização dos livros emprestados.\n");
                    }
                    else
                    {
                        if(opcao == 6)
                        {
                            printf("\t1) Vizualizar novamente todas as opções de visualização dos livros disponíveis.\n");
                        }
                        else
                        {
                            printf("\t1) Vizualizar novamente todas as opções de visualização do cliente.\n");
                        }
                    }
                    printf("\t2) Voltar ao menu principal.\n\n");
                    printf("Digite o número da opção que deseja seguir: ");
                    scanf("%i", &opcao2);
                    if(opcao2 == 1 || opcao2 == 2)
                    {
                        break;
                    }
                    printf("OOOPS! o número digitado não esta de acordo com o solicitado.\n\n");
                    system("pause");
                }
                if(opcao2 == 2)
                {
                    break;
                }
            }
            system("cls");
            continue;
        }
        if(opcao == 8)
        {
            identificador = 0;
            do
            {
                while(1)
                {
                    system("cls");
                    printf("Escolha uma das opções abaixo.\n");
                    printf("\t1) Alterar o nome de um cliente.\n");
                    printf("\t2) Alterar as informações de um livro.\n\n");
                    printf("Digite a opção desejada ao lado: ");
                    scanf("%i", &opcao2);
                    if(opcao2 < 1 || opcao2 > 2)
                    {
                        printf("OOOPS!! digitação incorreta!!!\n\n");
                        system("pause");
                        system("cls");
                        printf("Digite qualquer coisa diferente de \"n ou N\" para continuar realizando uma digitação\n");
                        scanf("%s", &res[0]);
                        res[0] = toupper(res[0]);
                        if(res[0] != 'N')
                        {
                            continue;
                        }
                        identificador++;
                    }
                    break;
                }
                if(identificador == 0)
                {
                    if(opcao2 == 1)
                    {
                        while(1)
                        {
                            system("cls");
                            printf("Digite o código do cliente: ");
                            scanf("%i", &cd_aux_cliente);
                            if(cd_aux_cliente <= 0)
                            {
                                printf("OOOPS!! O código do cliente tem de ser um número maior ou igual a 0.\n\n");
                                system("pause");
                                system("cls");
                            }
                            else
                            {
                                if(Identificador_Clientes_Existentes_codigo(cliente, cd_aux_cliente) == 1)
                                {
                                    while(1)
                                    {
                                        system("cls");
                                        printf("Digite como deseja renomear o cliente: ");
                                        fflush(stdin);
                                        fgets(nome, Tam_Nome, stdin);
                                        remocao_enter(nome);

                                        if(identificador_vazio(nome[0]) == 1)
                                        {
                                            printf("\nOOOPS!! nenhuma digitação identificada, por favor tente novamente.\n\n");
                                            system("pause");
                                            system("cls");
                                            continue;
                                        }

                                        printf("Se deseja digitar novamente, tecle qualquer botão diferente de \"n ou N\": ");
                                        scanf("%s", &res[0]);
                                        res[0] = toupper(res[0]);
                                        if(res[0] != 'N')
                                        {
                                            continue;
                                        }
                                        if(titulo[0] == ' ')
                                        {
                                            printf("OOOPS!! há um espaço em branco no início do titulo.\n\n");
                                            system("pause");
                                            system("cls");
                                        }
                                        else
                                        {
                                            if(isdigit(nome[0]) == 1)
                                            {
                                                printf("OOOPS!!! não se pode haver digitação de número no nome do cliente.\n\n");
                                                system("pause");
                                                system("cls");
                                            }
                                            else
                                            {
                                                nome[0] = toupper(nome[0]);
                                                for(i = 1; nome[i] < Tam_Nome; i++)
                                                {
                                                    if(isdigit(nome[i]) == 1)
                                                    {
                                                        identificador++;
                                                        break;
                                                    }
                                                    nome[i] = tolower(nome[i]);
                                                }
                                                if(identificador != 0)
                                                {
                                                    identificador = 0;
                                                    printf("OOOPS!!! não se pode haver digitação de número no nome do cliente.\n\n");
                                                    system("pause");
                                                    system("cls");
                                                }
                                                else
                                                {
                                                    system("cls");
                                                    cliente = Editar_cliente(cliente, cd_aux_cliente, nome);
                                                    printf("O nome foi alterado com sucesso!!!\n\n");
                                                    system("pause");
                                                    system("cls");
                                                    break;
                                                }
                                            }
                                        }
                                        printf("Digite qualquer coisa diferente de \"n ou N\" para tentar realizar uma nova digitação: ");
                                        scanf("%s", &res[0]);
                                        res[0] = toupper(res[0]);
                                        if(res[0] == 'N')
                                        {
                                            break;
                                        }
                                    }
                                    break;
                                }
                                else
                                {
                                    printf("Não existe cliente cadastrado com o código \"%i\"\n\n", cd_aux_cliente);
                                    system("pause");
                                    system("cls");
                                }
                            }
                            printf("Digite qualquer coisa diferente de \"n ou N\" para realizar uma nova digitação: ");
                            scanf("%s", &res[0]);
                            res[0] = toupper(res[0]);
                            if(res[0] == 'N')
                            {
                                break;
                            }
                        }
                    }
                    else
                    {
                        while(1)
                        {
                            system("cls");
                            printf("Digite o código do livro ao lado: ");
                            scanf("%i", &cd_aux_Disponivel);
                            if(cd_aux_Disponivel < 1)
                            {
                                printf("Não existe nenhum livro cadastrado que tenha um código menor ou igual a 0.\n\n");
                                system("pause");
                                system("cls");
                            }
                            else
                            {
                                if(Identificador_livro_existente_por_codigo(L_D, cd_aux_Disponivel) == 1)
                                {
                                    opcao = 1;
                                    break;
                                }
                                else
                                {
                                    if(Identificador_livro_Emprestado_existente_por_codigo(Livro_emprestado, cd_aux_Disponivel) == 1)
                                    {
                                        opcao = 2;
                                        break;
                                    }
                                    else
                                    {
                                    printf("O livro com o código \"%i\" não consta no sistema.\n\n", cd_aux_Disponivel);
                                    system("pause");
                                    system("cls");
                                    }
                                }
                            }
                            printf("Digite qualquer coisa diferente de \"n ou N\" para digitar novamente um código: ");
                            scanf("%s", &res[0]);
                            res[0] = toupper(res[0]);
                            if(res[0] == 'N')
                            {
                                identificador++;
                                break;
                            }
                        }
                        if(identificador == 0)
                        {
                            while(1)
                            {
                                system("cls");
                                printf("Escolha uma das opções abaixo.\n");
                                printf("\t1) Alterar título.\n");
                                printf("\t2) Alterar assunto.\n");
                                printf("\t3) Alterar autor.\n\n");
                                printf("Digite o número da opção que deseja realizar a edição de informação: ");
                                scanf("%i", &opcao2);
                                if(opcao2 == 1)
                                {
                                    //Edição do titulo de um livro.
                                    while(1)
                                    {
                                        system("cls");
                                        printf("Digite o novo titulo do livro: ");
                                        fflush(stdin);
                                        fgets(titulo, Tam_Nome, stdin);
                                        remocao_enter(titulo);

                                        if(identificador_vazio(titulo[0]) == 1)
                                        {
                                            printf("\nOOOPS!! nenhuma digitação identificada, por favor tente novamente.\n\n");
                                            system("pause");
                                            system("cls");
                                            continue;
                                        }

                                        if(titulo[0] == ' ')
                                        {
                                            printf("OOOPS!!! há um espaço em branco no inicio do titulo.\n\n");
                                            system("pause");
                                            system("cls");
                                        }
                                        else
                                        {
                                            titulo[0] = toupper(titulo[0]);
                                            for(i = 1; titulo[i] < Tam_Nome; i++)
                                            {
                                                titulo[i] = tolower(titulo[i]);
                                            }
                                            break;
                                        }
                                        printf("Digite qualquer coisa diferente de \"n ou N\" para digitar novamente um titulo para o livro: ");
                                        scanf("%s", &res[0]);
                                        res[0] = toupper(res[0]);
                                        if(res[0] == 'N')
                                        {
                                            identificador++;
                                            break;
                                        }
                                    }
                                    if(identificador == 0)
                                    {
                                        system("cls");
                                        if(opcao == 1)
                                        {
                                            //colocar a função de edição do titulo na lista de livros disponiveis
                                            L_D = Edicao_titulo_livro_disponivel(L_D, cd_aux_Disponivel, titulo);
                                        }
                                        else
                                        {
                                            //colocar a função de edição do titulo na lista de livros emprestados e na lista de livros disponiveis dentro da lista de clientes
                                            Editar_titulo_livros_emprestados_e_cliente(&Livro_emprestado, &cliente, cd_aux_Disponivel, titulo);
                                        }
                                        printf("O titulo do livro foi alterado com sucesso!!\n\n");
                                        system("pause");
                                        system("cls");
                                    }
                                    else
                                    {
                                        identificador = 0;
                                    }
                                }
                                else
                                {
                                    if(opcao2 == 2)
                                    {
                                        //Edição do assunto de um livro
                                        while(1)
                                        {
                                            system("cls");
                                            printf("Digite o novo assunto do livro: ");
                                            fflush(stdin);
                                            fgets(assunto, Tam_Assunto, stdin);
                                            remocao_enter(assunto);

                                            if(identificador_vazio(assunto[0]) == 1)
                                            {
                                                printf("\nOOOPS!! nenhuma digitação identificada, por favor tente novamente.\n\n");
                                                system("pause");
                                                system("cls");
                                                continue;
                                            }
                                        
                                            if(assunto[0] == ' ')
                                            {
                                                printf("OOOPS!!! há um espaço em branco no inicio do assunto.\n\n");
                                                system("pause");
                                                system("cls");
                                            }
                                            else
                                            {
                                                assunto[0] = toupper(assunto[0]);
                                                for(i = 1; assunto[i] < Tam_Nome; i++)
                                                {
                                                    assunto[i] = tolower(assunto[i]);
                                                }
                                                break;
                                            }
                                            printf("Digite qualquer coisa diferente de \"n ou N\" para digitar novamente o assunto do livro: ");
                                            scanf("%s", &res[0]);
                                            res[0] = toupper(res[0]);
                                            if(res[0] == 'N')
                                            {
                                                identificador++;
                                                break;
                                            }
                                        }
                                        if(identificador == 0)
                                        {
                                            system("cls");
                                            if(opcao == 1)
                                            {
                                                //colocar a função de edição do assunto na lista de livros disponiveis
                                                L_D = Edicao_assunto_livro_disponivel(L_D, cd_aux_Disponivel, assunto);
                                            }
                                            else
                                            {
                                                //colocar a função de edição do assunto na lista de livros emprestados e na lista de livros disponiveis dentro da lista de clientes
                                                Editar_assunto_livros_emprestados_e_cliente(&Livro_emprestado, &cliente, cd_aux_Disponivel, assunto);
                                            }
                                            printf("O assunto do livro foi alterado com sucesso!!\n\n");
                                            system("pause");
                                            system("cls");
                                        }
                                        else
                                        {
                                            identificador = 0;
                                        }
                                    }
                                    else
                                    {
                                        if(opcao2 == 3)
                                        {
                                            //Edição do autor de um livro
                                            while(1)
                                            {
                                                system("cls");
                                                printf("Digite o novo nome do autor do livro: ");
                                                fflush(stdin);
                                                fgets(autor, Tam_Nome, stdin);
                                                remocao_enter(autor);

                                                if(identificador_vazio(autor[0]) == 1)
                                                {
                                                    printf("\nOOOPS!! nenhuma digitação identificada, por favor tente novamente.\n\n");
                                                    system("pause");
                                                    system("cls");
                                                    continue;
                                                }
                                                
                                                if(autor[0] == ' ')
                                                {
                                                    printf("OOOPS!!! há um espaço em branco no inicio do nome do autor.\n\n");
                                                    system("pause");
                                                    system("cls");
                                                }
                                                else
                                                {
                                                    if(isdigit(autor[0]) == 1)
                                                    {
                                                        printf("Não se pode ter digitação de número no nome do autor.\n\n");
                                                        system("pause");
                                                        system("cls");
                                                    }
                                                    else
                                                    {
                                                        identificador = 0;
                                                        autor[0] = toupper(autor[0]);
                                                        for(i = 1; autor[i] < Tam_Nome; i++)
                                                        {
                                                            if(isdigit(autor[i]) == 0)
                                                            {
                                                                autor[i] = tolower(autor[i]);
                                                            }
                                                            else
                                                            {
                                                                identificador++;
                                                                break;
                                                            }
                                                        }
                                                        if(identificador == 0)
                                                        {
                                                            break;
                                                        }
                                                        else
                                                        {
                                                            identificador = 0;
                                                            printf("Não se pode ter número na digitação do nome do autor.\n\n");
                                                            system("pause");
                                                            system("cls");
                                                        }
                                                    }
                                                }
                                                printf("Digite qualquer coisa diferente de \"n ou N\" para digitar novamente um o nome do autor: ");
                                                scanf("%s", &res[0]);
                                                res[0] = toupper(res[0]);
                                                if(res[0] == 'N')
                                                {
                                                    identificador++;
                                                    break;
                                                }
                                            }
                                            if(identificador == 0)
                                            {
                                                system("cls");
                                                if(opcao == 1)
                                                {
                                                    //colocar a função de edição do nome do autor na lista de livros disponiveis
                                                    L_D = Edicao_autor_livro_disponivel(L_D, cd_aux_Disponivel, autor);
                                                }
                                                else
                                                {
                                                    //colocar a função de edição do nome do autor na lista de livros emprestados e n alista de livros disponiveis dentro da lista de clientes
                                                    Editar_autor_livros_emprestados_e_cliente(&Livro_emprestado, &cliente, cd_aux_Disponivel, autor);
                                                }
                                                printf("O nome do autor foi alterado com sucesso!!\n\n");
                                                system("pause");
                                                system("cls");
                                            }
                                            else
                                            {
                                                identificador = 0;
                                            }
                                        }
                                        else
                                        {
                                            printf("OOOPS!! O número digitado não condiz com a solicitação.\n\n");
                                            system("pause");
                                            system("cls");
                                            printf("Digite qualquer coisa diferente de \"n ou N\" para digitar novamente uma opção: ");
                                            scanf("%s", &res[0]);
                                            res[0] = toupper(res[0]);
                                            if(res[0] == 'N')
                                            {
                                                break;
                                            }
                                        }
                                    }
                                }
                                system("cls");
                                printf("Digite qualquer coisa diferente de \"n ou N\" caso deseje realizar alguma outra alteração em algum livro: ");
                                scanf("%s", &res[0]);
                                res[0] = toupper(res[0]);
                                if(res[0] == 'N')
                                {
                                    break;
                                }
                            }
                        }
                        else
                        {
                            identificador = 0;
                        }
                    }
                }
                else
                {
                    identificador = 0;
                }
                do
                {
                    system("cls");
                    printf("Escolha uma das opções abaixo.\n");
                    printf("\t1) Realizar outra alteração de cadastro.\n");
                    printf("\t2) Voltar ao menu principal.\n\n");
                    printf("Digite uma das opção desejada ao lado: ");
                    scanf("%i", &opcao2);
                    if(opcao2 < 1 || opcao2 > 2)
                    {
                        printf("OOOPS!! digitação incorreta, por favor escolha a opção 1 ou 2.\n\n");
                        system("pause");
                    }
                }while(opcao2 < 1 || opcao2 > 2);
            } while(opcao2 != 2);
            system("cls");
            continue;
        }
        if(opcao == 9)
        {
            system("cls");
            break;
        }
        else
        {
            printf("O número digitado não é compatível com nenhuma das opções dadas.\n\n");
            system("pause");
            system("cls");
        }
    }
    printf("OBRIGADO POR USAR ESTE SISTEMA BIBLIOTECÁRIO!!!\n");
    printf("VOLTE SEMPRE!!\n\n");
    system("pause");
    return 0;
}
