#include <stdio.h>
#include <stdlib.h>

typedef struct no{ // Nó simples utilizado para lista simples, lista com cabeça e lista circular
    int chave;
    struct no *prox;
}TNo;

void listaSimplesMenu();
void listaComCabecaMenu();
void listaCircularMenu();
void listaDuplamenteEncadeadaMenu();

int main(){

    int opcaoUsuario = 0; //Variável que armazena a opção do usuário

    while (opcaoUsuario!=5){
        printf("====================Menu1====================\n"); //Menu princial para escolher qual lista utilizar
        printf("1 - Lista Simples\n");
        printf("2 - Lista com Cabeça\n");
        printf("3 - Lista Circular\n");
        printf("4 - Lista Duplamente Encadeada\n");
        printf("5 - Sair do programa\n");

        printf("\nEscolha uma opção: ");
        scanf("%d", &opcaoUsuario); // Recepção da resposta do usuário

        printf("==============================================\n");

        switch (opcaoUsuario){
            case 1:
                system("@cls||clear"); //Clear no terminal do usuário (comando válido para Windows, Linux e MacOsX)
                // printf("Lista Simples\n");
                listaSimplesMenu();
                break;
            case 2:
                system("@cls||clear");
                // printf("Lista com Cabeça\n");
                listaComCabecaMenu();
                break;
            case 3:
                system("@cls||clear");
                // printf("Lista Circular\n");
                listaCircularMenu();
                break;
            case 4:
                system("@cls||clear");
                // printf("Lista Duplamente Encadeada\n");
                listaDuplamenteEncadeadaMenu();
                break;
            case 5:
                printf("Saindo do programa\n");
                break;
            default:
                printf("Opção inválida\n");
                break;
        }

    }
    printf("Bye!\n");
    exit(1);

    return 0;
}

//MENUS

void listaSimplesMenu(){ //Menu da lista Simples
    int opcaoUsuario = 0;
    int chave;
    TNo *lista = NULL;

    while (opcaoUsuario!=4){
        printf("================Menu Lista Simples================\n");
        printf("1 - Inserir\n");
        printf("2 - Remover\n");
        printf("3 - Imprimir\n");
        printf("4 - Sair do Menu Lista Simples\n");

        printf("\nEscolha uma opção: ");
        scanf("%d", &opcaoUsuario);

        printf("===================================================\n");

        switch (opcaoUsuario){
            case 1:
                printf("Digite a chave: ");
                scanf("%d", &chave);
                // insereLista(&lista, chave);
                break;
            case 2:
                printf("Lista: \n");
                // imprimeLista(lista);
                break;
            case 3:
                printf("Digite a chave: ");
                scanf("%d", &chave);
                // buscaLista(lista, chave);
                break;
            case 4:
                system("@cls||clear"); //Clear no terminal do usuário (comando válido para Windows, Linux e MacOsX)
                return;
                break;
            default:
                system("@cls||clear");
                printf("Opção inválida\n");
                break;
        }
    }
}

void listaComCabecaMenu(){ // Menu da lista com cabeça
    int opcaoUsuario = 0;
    int chave;
    TNo *lista = NULL;

    while (opcaoUsuario!=4){
        printf("================Menu Lista Com Cabeça================\n");
        printf("1 - Inserir\n");
        printf("2 - Remover\n");
        printf("3 - Imprimir\n");
        printf("4 - Sair do Menu Lista Com Cabeça\n");

        printf("\nEscolha uma opção: ");
        scanf("%d", &opcaoUsuario);

        printf("=====================================================\n");

        switch (opcaoUsuario){
            case 1:
                printf("Digite a chave: ");
                scanf("%d", &chave);
                // insereLista(&lista, chave);
                break;
            case 2:
                printf("Lista: \n");
                // imprimeLista(lista);
                break;
            case 3:
                printf("Digite a chave: ");
                scanf("%d", &chave);
                // buscaLista(lista, chave);
                break;
            case 4:
                system("@cls||clear"); //Clear no terminal do usuário (comando válido para Windows, Linux e MacOsX)
                return;
                break;
            default:
                system("@cls||clear");
                printf("Opção inválida\n");
                break;
        }
    }
}

void listaCircularMenu(){ // Menu da lista circular
    int opcaoUsuario = 0;
    int chave;
    TNo *lista = NULL;

    while (opcaoUsuario!=4){
        printf("================Menu Lista Circular================\n");
        printf("1 - Inserir\n");
        printf("2 - Remover\n");
        printf("3 - Imprimir\n");
        printf("4 - Sair do Menu Lista Circular\n");

        printf("\nEscolha uma opção: ");
        scanf("%d", &opcaoUsuario);

        printf("====================================================\n");

        switch (opcaoUsuario){
            case 1:
                printf("Digite a chave: ");
                scanf("%d", &chave);
                // insereLista(&lista, chave);
                break;
            case 2:
                printf("Lista: \n");
                // imprimeLista(lista);
                break;
            case 3:
                printf("Digite a chave: ");
                scanf("%d", &chave);
                // buscaLista(lista, chave);
                break;
            case 4:
                system("@cls||clear"); //Clear no terminal do usuário (comando válido para Windows, Linux e MacOsX)
                return;
                break;
            default:
                system("@cls||clear");
                printf("Opção inválida\n");
                break;
        }
    }
}

void listaDuplamenteEncadeadaMenu(){ // Menu da lista duplamente encadeada
    int opcaoUsuario = 0;
    int chave;
    TNo *lista = NULL;

    while (opcaoUsuario!=4){
        printf("================Menu Lista Duplamente Encadeada================\n");
        printf("1 - Inserir\n");
        printf("2 - Remover\n");
        printf("3 - Imprimir\n");
        printf("4 - Sair do Menu Lista Duplamente Encadeada\n");

        printf("\nEscolha uma opção: ");
        scanf("%d", &opcaoUsuario);

        printf("===============================================================\n");

        switch (opcaoUsuario){
            case 1:
                printf("Digite a chave: ");
                scanf("%d", &chave);
                // insereLista(&lista, chave);
                break;
            case 2:
                printf("Lista: \n");
                // imprimeLista(lista);
                break;
            case 3:
                printf("Digite a chave: ");
                scanf("%d", &chave);
                // buscaLista(lista, chave);
                break;
            case 4:
                system("@cls||clear"); //Clear no terminal do usuário (comando válido para Windows, Linux e MacOsX)
                return;
                break;
            default:
                system("@cls||clear");
                printf("Opção inválida\n");
                break;
        }
    }
}