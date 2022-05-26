#include <stdio.h>
#include <stdlib.h>

//Cores especiais
#define errorColor     "\x1b[31m"
#define listColor    "\x1b[34m"
#define alertColor  "\x1b[33m"
#define contrastColor    "\x1b[36m"

#define resetColor   "\x1b[0m"

typedef struct no{ // Nó simples utilizado para lista simples, lista com cabeça e lista circular
    int chave;
    struct no *prox;
}TNo;

typedef struct Cabeca{ // Nó cabeca
    char nome[20];
    TNo *inicio;
}TCabeca;

//Declaração de Menus
void listaSimplesMenu();
void listaComCabecaMenu();
void listaCircularMenu();
void listaDuplamenteEncadeadaMenu();
void helpMenu();

//Aloca nó Simples
TNo *alocaNoSimples(int k){
    TNo *novo = (TNo*)malloc(sizeof(TNo));

    if (novo == NULL) return;

    novo->chave = k;
    novo->prox = NULL;

    return novo;
}
//Imprime Listas
void imprimeListas(TNo *p){
    if (p == NULL){
        printf(errorColor "LISTA VAZIA\n " resetColor);
        return;
    }

    while (p!=NULL){
        printf(listColor "%d\n" resetColor, p->chave);
        p = p -> prox;
    }
}

//Busca nó Simples
TNo *buscaNo(TNo *p, int k){
    if (p == NULL) return NULL;

    while (p!=NULL){
        if (p->chave == k) return p;
        p = p -> prox;
    }
    printf(errorColor "Nó não encontrado\n" resetColor);
    return NULL;
}

//Funções de Lista Simples
void insereListaSimples(TNo **p, int k, int chave){
    TNo *novo=NULL;

    novo = alocaNoSimples(k);

    if (novo == NULL) return NULL;

    if (chave == NULL){
        novo -> prox = *p;
        *p = novo;
    }
    else{
        TNo *aux = buscaNo(*p, chave);
        novo -> prox = aux -> prox;
        aux -> prox = novo;
    }
    
}

void insereOrdemCrescenteListaSimples(TNo **p, int k){ //VERIFICAR
    TNo *novo=NULL;
    TNo *aux = NULL;

    novo = alocaNoSimples(k);

    if (novo == NULL) return NULL;

    if (*p == NULL){
        *p = novo;
    }
    else{
        aux = *p;
        while (aux->prox != NULL && aux->chave > k){
            aux = aux -> prox;
        }
        novo -> prox = aux -> prox;
        aux -> prox = novo;
    }
}

void removeListaSimples(TNo **p, int k){

    TNo *aux = NULL, *anterior = NULL;

    if (p==NULL) return;

    aux = *p;

    if (aux->chave==k){
        if (aux->prox == NULL){
            free(*p);
            *p = NULL;
            return;
        }
        else{
            aux = *p;
            *p = (*p)->prox;
            free(aux);
            return;
        }
    }
    else{
        anterior = aux;
        aux = aux -> prox;

        while (aux!=NULL){
            if(aux->chave == k){
                //printf("Chave Encontrada\n");
                anterior->prox = aux->prox;
                free(aux);
                return;
            }

            anterior = aux;
            aux = aux -> prox;
        }
    }
    printf(errorColor "Nó não Exite\n" resetColor);
}

void removeTodosListaSimples(TNo **p){
    TNo *aux = NULL;
    aux = *p;

    while (aux!=NULL){
        *p = (*p)->prox;
        free(aux);
        aux = *p;
    }
}

//Main
int main(){

    int opcaoUsuario = 0; //Variável que armazena a opção do usuário

    while (opcaoUsuario!=6){
        printf("====================Menu1====================\n"); //Menu princial para escolher qual lista utilizar
        printf("1 - Lista Simples\n");
        printf("2 - Lista com Cabeça\n");
        printf("3 - Lista Circular\n");
        printf("4 - Lista Duplamente Encadeada\n");
        printf("5 - Help\n");
        printf("6 - Sair do programa\n");

        printf("\nEscolha uma opção: ");
        scanf("%d", &opcaoUsuario); // Recepção da resposta do usuário

        printf("=============================================\n");

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
                helpMenu();
                break;
            case 6:
                system("@cls||clear");
                printf("Saindo do programa\n");
                break;
            default:
                system("@cls||clear");
                printf(errorColor "Opção inválida\n" resetColor);
                break;
        }

    }
    printf(contrastColor "Bye!\n" resetColor);
    exit(1);

    return 0;
}

//MENUS

void listaSimplesMenu(){ //Menu da lista Simples
    int opcaoUsuario = 0;
    int chave;
    int chave2;
    TNo *lista = NULL;

    while (opcaoUsuario!=5){
        printf("================Menu Lista Simples================\n");
        printf("1 - Inserir\n");
        printf("2 - Remover\n");
        printf("3 - Imprimir\n");
        printf("4 - Divide Lista\n");
        printf("5 - Sair do Menu Lista Simples\n");

        printf("\nEscolha uma opção: ");
        scanf("%d", &opcaoUsuario);

        printf("===================================================\n");

        switch (opcaoUsuario){
            case 1:
                system("@cls||clear");
                if (lista == NULL){
                    printf("Digite a chave do novo nó: ");
                    scanf("%d", &chave);
                    insereListaSimples(&lista, chave, NULL); 
                }
                else{
                    printf("================Menu Inserir================\n");
                    printf("1 - Inserir após um nó\n");
                    printf("2 - Inserir em ordem crescente\n");
                    printf("3 - Inserir no começo\n");

                    printf("\nEscolha uma opção: ");
                    scanf("%d", &opcaoUsuario);

                    printf("=============================================\n");

                    switch (opcaoUsuario){
                        case 1:
                            system("@cls||clear");
                            printf("Digite a chave do nó: ");
                            scanf("%d", &chave);
                            printf("Digite a chave do nó após o qual o novo nó será inserido: ");
                            scanf("%d", &chave2);
                            insereListaSimples(&lista, chave, chave2);
                            break;
                        case 2:
                            system("@cls||clear");
                            printf("Digite a chave do nó: ");
                            scanf("%d", &chave);
                            insereOrdemCrescenteListaSimples(&lista, chave);
                            break;
                        case 3:
                            system("@cls||clear");
                            printf("Digite a chave do nó: ");
                            scanf("%d", &chave);
                            insereListaSimples(&lista, chave, NULL);
                            break;
                        default:
                            system("@cls||clear");
                            printf(errorColor "Opção inválida\n" resetColor);
                            break;
                    }
                }
                break;
            case 2:
                system("@cls||clear");
                if (lista == NULL){
                    printf(errorColor "LISTA VAZIA, não é possível remover nada!\n" resetColor);
                }
                else{
                    printf("================Menu Remover================\n");
                    printf("1 - Remover um elemento\n");
                    printf("2 - Remover toda lista\n");

                    printf("\nEscolha uma opção: ");
                    scanf("%d", &opcaoUsuario);

                    printf("=============================================\n");

                    if (opcaoUsuario == 1){
                        system("@cls||clear");
                        printf("Digite a chave: ");
                        scanf("%d", &chave);
                        removeListaSimples(&lista, chave);
                    }
                    else if (opcaoUsuario == 2){
                        system("@cls||clear");
                        removeTodosListaSimples(&lista);
                    }
                    else{
                        system("@cls||clear");
                        printf(errorColor "Opção inválida\n" resetColor);
                        opcaoUsuario = 0;
                    }
                }
                break;
            case 3:
                system("@cls||clear");
                printf("Lista: \n");
                
                imprimeListas(lista);

                break;
            case 4:
                system("@cls||clear");
                //printf("Divisão da lista\n");
                break;
            case 5:
                system("@cls||clear"); //Clear no terminal do usuário (comando válido para Windows, Linux e MacOsX)
                
                if (lista != NULL) {
                    printf(alertColor "Caso saia do menu a lista será perdida\n" resetColor);
                    printf(alertColor "Deseja sair? (1 - Sim, 2 - Não)\n" resetColor);
                    scanf("%d", &opcaoUsuario);
                    if (opcaoUsuario==1) {
                        return;
                        system("@cls||clear");
                    }
                }
                else return;

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
                printf("Digite a chave: ");
                scanf("%d", &chave);
                // RemoverListaSimples(&lista, chave);
                break;
            case 3:
                printf("Lista: \n");
                // imprimeLista(lista);
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
                printf("Digite a chave: ");
                scanf("%d", &chave);
                // buscaLista(lista, chave);
                break;
            case 3:
                printf("Lista: \n");
                // imprimeLista(lista);
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
                printf("Digite a chave: ");
                scanf("%d", &chave);
                // buscaLista(lista, chave);
                break;
            case 3:
                printf("Lista: \n");
                // imprimeLista(lista);
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

void helpMenu(){
    int opcaoUsuario = 0;

    system("@cls||clear");
    printf("================Menu Help================\n");
    printf("Trabalho de Estruturas de Dados\n");
    printf("\n");
    printf("Autores: \n");
    printf(contrastColor "Marlon Henrique Sanches\n" resetColor);
    printf("=========================================\n");

    printf("\n");
    printf("\n");

    printf("0 - Sair\n");
    scanf("%d", &opcaoUsuario);
    if (opcaoUsuario>=0) {
        system("@cls||clear");
        return;
    }
}