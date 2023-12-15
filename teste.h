#ifndef MINHASFUNCOES_H_INCLUDED
#define MINHASFUNCOES_H_INCLUDED
#endif // MINHASFUNCOES_H_INCLUDED

#include <stdlib.h>
#include <stdio.h>        //para entrada e saida
#include <string.h>       //para cadeia de caracter
#include "ValidarDados.h" // validar a data, hora

#define MAX_PASSAGENS 50 // ja define o maximo de passagens a serem cadastradas

/*
    Struct que armazena as variaveis
    que receberao os dados das passagens.
*/
typedef struct PassagensAereas
{
    int id;
    char aero_Origem[4];
    char aero_Destino[4];
    char cid_Origem[15];
    char cid_Destino[15];
    int dia;
    int mes;
    int ano;
    char H_partida[6];
    char H_chegada[6];
    char valor_passagem[15];
} PassagensAereas;

//variaveis globais
PassagensAereas passagens[MAX_PASSAGENS]; // define o maximo de passagens na struct
int total_Passagens = 0;                  // garante a inicializacao com o total de zero passagens
int ultimo_ID = 0;                        // inicia o ultimo ID com zero

// MENU principal
void Menu()
{
    printf("\n-- Menu Principal\n");
    printf("1. Listar todas as passagens\n");
    printf("2. Pesquisar uma passagem\n");
    printf("3. Cadastrar uma passagem\n");
    printf("4. Editar uma passagem\n");
    printf("5. Excluir uma passagem\n");
    printf("6. Sair do programa\n");
}

// Procedimento para listar as passagens.
void listarPassagens()
{
    printf("\nLista de Passagens.\n");
    printf("Total de passagens: %d\n", total_Passagens);

    for (int i = 0; i < total_Passagens; i++)
    {
        printf("\nID: %d\n", passagens[i].id);
        printf("Aeroporto Origem: %s\n", passagens[i].aero_Origem);
        printf("Aeroporto Destino: %s\n", passagens[i].aero_Destino);
        printf("Cidade Origem: %s\n", passagens[i].cid_Origem);
        printf("Cidade Destino: %s\n", passagens[i].cid_Destino);
        printf("Data: %d/%d/%d\n", passagens[i].dia, passagens[i].mes, passagens[i].ano);
        printf("Hora Partida: %s\n", passagens[i].H_partida);
        printf("Hora Chegada: %s\n", passagens[i].H_chegada);
        printf("Valor passagem: %s\n", passagens[i].valor_passagem);
    }
}

/*  Procedimento que pesquisa as passagens abrindo um sub menu
    onde o usuario escolhe as opcoes de pesquisa.
*/
void pesquisarPassagem()
{
    int opcao;
    int encontrado = 0; // teste
    char chave[50];

    printf("\nSub-menu de Pesquisa.\n");
    printf("1. ID da passagem\n");
    printf("2. Aeroporto origem\n");
    printf("3. Aeroporto destino\n");
    printf("4. Cidade origem\n");
    printf("5. Cidade destino\n");
    printf("Escolha uma opcao de pesquisa: ");
    scanf("%d", &opcao);

    printf("Digite a chave de pesquisa: ");
    scanf(" %[^\n]s", chave);

    for (int i = 0; i < total_Passagens; i++)
    {
        switch (opcao)
        {
        case 1:
            if (atoi(chave) == passagens[i].id) // converte a chave para inteiro
            {
                encontrado = 1;
            }
            break;
        case 2:
            if (strcmp(chave, passagens[i].aero_Origem) == 0) // comparacao de strings
            {
                encontrado = 1;
            }
            break;
        case 3:
            if (strcmp(chave, passagens[i].aero_Destino) == 0)
            {
                encontrado = 1;
            }
            break;
        case 4:
            if (strcmp(chave, passagens[i].cid_Origem) == 0)
            {
                encontrado = 1;
            }
            break;
        case 5:
            if (strcmp(chave, passagens[i].cid_Destino) == 0)
            {
                encontrado = 1;
            }
            break;
        default:
            printf("Opcao invalida.\n");
            return;
        }

        if (encontrado)
        {
            printf("\nID: %d\n", passagens[i].id);
            printf("Aeroporto Origem: %s\n", passagens[i].aero_Origem);
            printf("Aeroporto Destino: %s\n", passagens[i].aero_Destino);
            printf("Cidade Origem: %s\n", passagens[i].cid_Origem);
            printf("Cidade Destino: %s\n", passagens[i].cid_Destino);
            printf("Data: %d\n", passagens[i].dia);
            printf("Data: %d\n", passagens[i].mes);
            printf("Data: %d\n", passagens[i].ano);
            printf("Hora Partida: %s\n", passagens[i].H_partida);
            printf("Hora Chegada: %s\n", passagens[i].H_chegada);
            printf("Valor_passagem: %s\n", passagens[i].valor_passagem);
            return;
        }
    }

    printf("Nenhuma passagem encontrada com a chave fornecida.\n");
}

/*
    Procedimento para cadastrar passagens
    validado a data e a hora
*/
void cadastrarPassagem()
{
    if (total_Passagens < MAX_PASSAGENS)
    {
        PassagensAereas P;
        P.id = ++ultimo_ID; // Numero de ID auto-incrementado

        do
        {
            printf("Digite o aeroporto de origem: ");
            scanf(" %s", P.aero_Origem);
            if (strlen(P.aero_Origem) != 3 || !validarAero(P.aero_Origem))
            {
                printf("\nAeroporto de origem invalido!\n");
            }
        } while (strlen(P.aero_Origem) != 3 || !validarAero(P.aero_Origem)); // Testa se sao 3 caracteres

        do
        {
            printf("Digite o aeroporto de destino: ");
            scanf(" %s", P.aero_Destino);
            if (strlen(P.aero_Destino) != 3 || !validarAero(P.aero_Destino))
            {
                printf("\nAeroporto de destino invalido\n!");
            }
        } while (strlen(P.aero_Destino) != 3 || !validarAero(P.aero_Destino));

        fflush(stdin);

        do
        {
            printf("Digite a cidade de origem: ");
            fgets(P.cid_Origem, sizeof(P.cid_Origem), stdin);
            P.cid_Origem[strcspn(P.cid_Origem, "\n")] = '\0'; // Remove a nova linha
            if (!validarCidade(P.cid_Origem))
            {
                printf("\nCiadade de origem invalida!\n");
            }
        } while (!validarCidade(P.cid_Origem));

        do
        {
            printf("Digite a cidade de destino: ");
            fgets(P.cid_Destino, sizeof(P.cid_Destino), stdin);
            P.cid_Destino[strcspn(P.cid_Destino, "\n")] = '\0'; // Remove a nova linha
            if (!validarCidade(P.cid_Destino))
            {
                printf("\nCiadade de destino invalida!\n");
            }
        } while (!validarCidade(P.cid_Destino));

        do
        {
            printf("Digite a data do voo (formato DD/MM/AAAA): ");
            scanf("%d/%d/%d", &P.dia, &P.mes, &P.ano);

            if (!DataValida(P.dia, P.mes, P.ano))
            {
                printf("Data Invalida!\n");
            }

        } while (!DataValida(P.dia, P.mes, P.ano)); // Testa se a data e valida

        do
        {
            printf("Digite a hora de partida do voo: ");
            scanf(" %s", P.H_partida);

            if (!validarHora(P.H_partida))
            {
                printf("Hora invalida!\n");
            }
        } while (!validarHora(P.H_partida)); // Testa se a hora e valida

        do
        {
            printf("Digite a hora de chegada do voo: ");
            scanf(" %s", P.H_chegada);

            if (!validarHora(P.H_chegada))
            {
                printf("Hora invalida!\n");
            }
        } while (!validarHora(P.H_chegada));

        printf("Digite o valor da passagem: ");
        scanf("%s", P.valor_passagem);

        passagens[total_Passagens++] = P; // Adiciona a passagem P ao array incrementado ao total

        printf("Passagem cadastrada com sucesso!\n");
    }
    else
    {
        printf("Limite total de passagens alcancado.\n");
    }
}

/*
    Procedimento que permite ao usuario editar
    uma passagem ja existente a partir do ID.
*/
void editarPassagem()
{
    int idEditar;
    int encontrado = 0;

    printf("\nEditar de Passagem.\n");
    printf("Digite o ID da passagem a ser editada: ");
    scanf("%d", &idEditar);

    for (int i = 0; i < total_Passagens; i++)
    {
        if (idEditar == passagens[i].id) // Se o ID for o mesmo digitado pelo usuario
        {
            printf("\nID: %d\n", passagens[i].id);
            printf("Aeroporto Origem: %s\n", passagens[i].aero_Origem);
            printf("Aeroporto Destino: %s\n", passagens[i].aero_Destino);
            printf("Cidade Origem: %s\n", passagens[i].cid_Origem);
            printf("Cidade Destino: %s\n", passagens[i].cid_Destino);
            printf("Data: %d/%d/%d\n", passagens[i].dia, passagens[i].mes, passagens[i].ano);
            printf("Hora Partida: %s\n", passagens[i].H_partida);
            printf("Hora Chegada: %s\n", passagens[i].H_chegada);
            printf("Valor passagem: %s\n", passagens[i].valor_passagem);

            // Atualiza as informacoes
            printf("\nDigite as novas informacoes:\n");

            do
            {
                printf("Digite o aeroporto de origem: ");
                scanf(" %s", passagens[i].aero_Origem);
                if (strlen(passagens[i].aero_Origem) != 3)
                {
                    printf("\nAeroporto de origem invalido!\n");
                }
            } while (strlen(passagens[i].aero_Origem) != 3); // Testa se sao 3 caracteres

            do
            {
                printf("Digite o aeroporto de destino: ");
                scanf(" %s", passagens[i].aero_Destino);
                if (strlen(passagens[i].aero_Destino) != 3)
                {
                    printf("\nAeroporto de destino invalido\n!");
                }
            } while (strlen(passagens[i].aero_Destino) != 3);

            fflush(stdin);

            printf("Digite a cidade de origem: ");
            fgets(passagens[i].cid_Origem, sizeof(passagens[i].cid_Origem), stdin);
            passagens[i].cid_Origem[strcspn(passagens[i].cid_Origem, "\n")] = '\0'; // Remover a nova linha

            printf("Digite a cidade de destino: ");
            fgets(passagens[i].cid_Destino, sizeof(passagens[i].cid_Destino), stdin);
            passagens[i].cid_Destino[strcspn(passagens[i].cid_Destino, "\n")] = '\0'; // Remover a nova linha

            do
            {
                printf("Digite a data do voo (formato DD/MM/AAAA): ");
                scanf("%d/%d/%d", &passagens[i].dia, &passagens[i].mes, &passagens[i].ano);

                if (!DataValida(passagens[i].dia, passagens[i].mes, passagens[i].ano))
                {
                    printf("Data Invalida!\n");
                }

            } while (!DataValida(passagens[i].dia, passagens[i].mes, passagens[i].ano)); // testa se a data e valida

            do
            {
                printf("Digite a hora de partida do voo: ");
                scanf(" %s", passagens[i].H_partida);

                if (!validarHora(passagens[i].H_partida))
                {
                    printf("Hora invalida!\n");
                }
            } while (!validarHora(passagens[i].H_partida)); // testa se a hora e valida

            do
            {
                printf("Digite a hora de chegada do voo: ");
                scanf(" %s", passagens[i].H_chegada);

                if (!validarHora(passagens[i].H_chegada))
                {
                    printf("Hora invalida!\n");
                }
            } while (!validarHora(passagens[i].H_chegada));

            printf("Digite o valor da passagem: ");
            scanf("%s", passagens[i].valor_passagem);

            printf("\n- Passagem atualizada com sucesso!\n");
            encontrado = 1;
            break;
        }
    }

    if (!encontrado)
    {
        printf("Nenhuma passagem foi encontrada com esse ID: %d.\n", idEditar);
    }
}

/*
    Procedimento para excluir uma passagem aerea
    com base no ID inserido pelo usuario.
*/
void excluirPassagem()
{
    int idExcluir;
    int encontrado = 0; // teste

    printf("\nExcluir Passagem\n");
    printf("Digite o ID da passagem a ser excluida: ");
    scanf("%d", &idExcluir);

    for (int i = 0; i < total_Passagens; i++)
    {
        if (idExcluir == passagens[i].id) // Se o ID inserido for igual ao ID de uma das passagens
        {
            printf("\nID: %d\n", passagens[i].id);
            printf("Aeroporto Origem: %s\n", passagens[i].aero_Origem);
            printf("Aeroporto Destino: %s\n", passagens[i].aero_Destino);
            printf("Cidade Origem: %s\n", passagens[i].cid_Origem);
            printf("Cidade Destino: %s\n", passagens[i].cid_Destino);
            printf("Data: %d/%d/%d\n", passagens[i].dia, passagens[i].mes, passagens[i].ano);
            printf("Hora Partida: %s\n", passagens[i].H_partida);
            printf("Hora Chegada: %s\n", passagens[i].H_chegada);
            printf("Valor passagem: %s\n", passagens[i].valor_passagem);

            // Confirma exclusao
            char confirma;
            printf("\nDeseja realmente excluir esta passagem? (S/N): ");
            scanf(" %c", &confirma);

            if (confirma == 'S' || confirma == 's')
            {
                // Remove passagem
                for (int j = i; j < total_Passagens - 1; j++)
                {
                    passagens[j] = passagens[j + 1];
                }
                total_Passagens--; // Decrementa no total de passagens
                ultimo_ID--;       // Decrementa no ID
                printf("Passagem excluida com sucesso!\n");
            }
            else
            {
                printf("Exclusao cancelada.\n");
            }

            encontrado = 1;
            break;
        }
    }

    if (!encontrado)
    {
        printf("Nenhuma passagem encontrada com esse ID: %d.\n", idExcluir);
    }
}

/*
    Procedimento para salvar as passagens cadastradas
    pelo usuario.
*/
int salvarPassagens()
{
    FILE *arquivo = fopen("passagens.txt", "w");
    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    fprintf(arquivo, "%d\n", total_Passagens);
    fprintf(arquivo, "%d\n", ultimo_ID);

    for (int i = 0; i < total_Passagens; i++)
    {
        fprintf(arquivo, "%d;%s;%s;%s;%s;%d/%d/%d;%s;%s;%s\n",
                passagens[i].id,
                passagens[i].aero_Origem,
                passagens[i].aero_Destino,
                passagens[i].cid_Origem,
                passagens[i].cid_Destino,
                passagens[i].dia,
                passagens[i].mes,
                passagens[i].ano,
                passagens[i].H_partida,
                passagens[i].H_chegada,
                passagens[i].valor_passagem);
    }

    fclose(arquivo);
}

/*
    Procedimento para ler o arquivo e se
    nao existir, ele e' criado vazio.
*/
void carregarPassagens()
{
    FILE *arquivo = fopen("passagens.txt", "r");
    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    fscanf(arquivo, "%d", &total_Passagens);
    fscanf(arquivo, "%d", &ultimo_ID);

    for (int i = 0; i < total_Passagens; i++)
    {
        fscanf(arquivo, "%d;%3s;%3s;%49[^;];%49[^;];%d/%d/%d;%5[^;];%5[^;];%s",
               &passagens[i].id,
               passagens[i].aero_Origem,
               passagens[i].aero_Destino,
               passagens[i].cid_Origem,
               passagens[i].cid_Destino,
               &passagens[i].dia,
               &passagens[i].mes,
               &passagens[i].ano,
               passagens[i].H_partida,
               passagens[i].H_chegada,
               passagens[i].valor_passagem);
    }

    // fecha o arquivo
    fclose(arquivo);
}