/*
Autor: Maria Souza | Matricula: 720135
*/

/*
Biblioteca com as funcoes:
listagem, cadastro, pesquisa, edicao e exclusa de passagens.
*/
#include "Funcoes.h"
#include <stdio.h> //para entradas e saidas

int main()
{
    int opcao;
    carregarPassagens();

    do
    {
        printf("\n--- Menu Principal ---\n");
        printf("1. Listar todas as passagens\n");
        printf("2. Pesquisar uma passagem\n");
        printf("3. Cadastrar uma passagem\n");
        printf("4. Editar uma passagem\n");
        printf("5. Excluir uma passagem\n");
        printf("6. Sair do programa\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            listarPassagens();
            break;
        case 2:
            pesquisarPassagem();
            break;
        case 3:
            cadastrarPassagem();
            break;
        case 4:
            editarPassagem();
            break;
        case 5:
            excluirPassagem();
            break;
        case 6:
            printf("Encerrando o programa. Tenha um bom voo!\n");
            break;
        default:
            printf("Opcao invalida. Tente novamente.\n");
        }
        salvarPassagens();  //nova alteracao
    } while (opcao != 6);

    return 0;
}