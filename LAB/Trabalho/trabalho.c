// Trabalho de Estruturas de Dados

// Autores: 
// Marlon Henrique Sanches
// João Vitor Queiroz de Campos Pires

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

typedef struct noEncadeado{ // Nó encadeado
    int chave;
    struct noEncadeado *prox;
    struct noEncadeado *ant;
}TNoEncadeado;


//Declaração de Menus
void listaSimplesMenu();
void listaComCabecaMenu();
void listaCircularMenu();
void listaDuplamenteEncadeadaMenu();
void helpMenu();

//Aloca nó Simples
TNo *alocaNoSimples(int k){
    TNo *novo = (TNo*)malloc(sizeof(TNo));

    if (novo == NULL){
        printf(errorColor "Erro ao alocar memória\n" resetColor);
        return NULL;
    }

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

//Funções de Lista Simples e Com Cabeça
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
        
        if (aux == NULL) return;

        novo -> prox = aux -> prox;
        aux -> prox = novo;
    }
    
}

void insereOrdemCrescenteListaSimples(TNo **p, int k){ 
    TNo *anterior, *proximo;

    if (*p == NULL){ // Adiciona um nó se a lista está vazia
        *p = alocaNoSimples(k);
        return;
    } 

    if ((*p)->chave > k){ // Adiciona um nó no inicio da lista
        TNo *novo = alocaNoSimples(k);
        novo -> prox = *p;
        *p = novo;
        return;
    }


    while (*p != NULL && (*p) -> prox != NULL){ // Adiciona um nó no meio da lista

        if ((*p) -> prox -> chave > k){
            proximo = (*p) -> prox;
            anterior = *p;
            (*p) -> prox = alocaNoSimples(k);
            (*p) -> prox -> prox = proximo;
            return;
        }
        
        anterior = *p;
        p = &(*p)->prox;
    }

    (*p) -> prox = alocaNoSimples(k);
    return;

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

void divideListaSimples(TNo **p, TNo **Lista2, int k){
    TNo *busca = buscaNo(*p, k);

    if (busca == NULL) return;

    *Lista2 = busca -> prox;
    busca -> prox = NULL;
}

//Funções de Lista Circular
TNo *buscaNoCircular(TNo *p, int k){
    if (p == NULL) return NULL;

    TNo *aux = p;

    if (p->chave == k) return p;

    p = p -> prox;

    while (p!=aux){
        if (p->chave == k) return p;
        p = p -> prox;
    }
    printf(errorColor "Nó não encontrado\n" resetColor);
    return NULL;
}

void insereListaCircular(TNo **p, int k, int chave){
    TNo *novo=NULL;

    novo = alocaNoSimples(k);

    if (novo == NULL) return NULL;

    if (chave == NULL){
        novo -> prox = novo;
        *p = novo;
    }
    else{
        TNo *aux = buscaNoCircular(*p, chave);
        
        if (aux == NULL) return;

        novo -> prox = aux -> prox;
        aux -> prox = novo;
    }
}

void insereOrdemCrescenteListaCircular(TNo **p, int k){
    TNo *anterior, *proximo;

    if (*p == NULL){ //Insere caso lista vazia
        *p = alocaNoSimples(k);
        (*p) -> prox = *p; //Cria lista circular p aponta para p
        return;
    }

    if ((*p)->chave > k){ //Insere no inicio
        TNo *novo = alocaNoSimples(k);
        novo -> prox = *p;
        
        TNo *aux = *p;

        while (aux -> prox != *p){
            aux = aux -> prox;
        }
        aux -> prox = novo;
        *p = novo;

        return;
    }

    //Insere no meio (e final)
    anterior = *p;
    proximo = (*p) -> prox;

    while (proximo != *p && proximo -> chave < k){
        anterior = proximo;
        proximo = proximo -> prox;
    }
    
    TNo *novo = alocaNoSimples(k);
    novo -> prox = proximo;
    anterior -> prox = novo;
}

void imprimeListaCircular(TNo *p){
    if (p == NULL){
        printf(errorColor "LISTA VAZIA\n" resetColor);
        return;
    }
    TNo *aux = p;
    while (p->prox != aux){
        printf(listColor "%d\n" resetColor, p->chave);
        p = p -> prox;
    }
    printf(listColor "%d\n" resetColor, p->chave);
}

void removeListaCircular(TNo **p, int k){
    TNo *aux = NULL, *anterior = NULL;

    if (p==NULL) return;

    aux = *p;

    if (aux->chave==k){ //Caso remover o primeiro elemento da lista quando ele aponta para ele mesmo (lista unitária)
        if (aux->prox == aux){
            free(*p);
            *p = NULL;
            return;
        }
        else{ //Caso remover o primeiro elemento da lista quando ele aponta para outro elemento
            aux = *p;
            *p = (*p)->prox;
            
            while ((*p)->prox != aux){
                (*p) = (*p) -> prox;
            }
            (*p) -> prox = aux -> prox;

            free(aux);
            return;
        }
    }
    else{ //Caso remover elemento que não é o primeiro da lista
        anterior = aux;
        aux = aux -> prox;

        while (aux!=*p){
            if(aux->chave == k){
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

void removeTodosListaCircular(TNo **p){

    TNo *aux = NULL;
    aux = *p;

    while (aux!=*p){
        *p = (*p)->prox;
        free(aux);
        aux = *p;
    }
    free(aux);
    *p = NULL;
}

void divideListaCircular(TNo **p, TNo **Lista2, int k){
    TNo *busca = buscaNoCircular(*p, k);

    if (busca == NULL) return;

    *Lista2 = busca -> prox; // Seta a lista 2 a partir do proximo elemento do elemento da busca (que será o inicio da lista 2)
    
    while ((*Lista2)->prox != *p){ //Enquanto a lista 2 não apontar para o inicio da lista1
        (*Lista2) = (*Lista2) -> prox;
    }
    (*Lista2) -> prox = busca -> prox; //Seta o final da lista 2 para o seu começo (fechando a lista circular)

    TNo *aux = *p;
    while ((*p)->prox != busca){ //Enquanto a lista 1 não apontar para o inicio da lista2
        (*p) = (*p) -> prox;
    }
    (*p) -> prox = aux; //Seta o final da lista 2 para o seu começo (fechando a lista circular)

}

//Funções de Lista Duplamente Encadeada
TNoEncadeado *alocaNoEncadeado(int k){
    TNoEncadeado *novo = (TNoEncadeado *) malloc(sizeof(TNoEncadeado));

    if (novo == NULL){
        printf(errorColor "Erro ao alocar memória\n" resetColor);
        return NULL;
    }

    novo -> chave = k;
    novo -> prox = NULL;
    novo -> ant = NULL;

    return novo;
}

TNoEncadeado *buscaNoEncadeado(TNoEncadeado *p, int k){
    if (p == NULL) return NULL;

    TNoEncadeado *aux = p;

    if (p->chave == k) return p;

    p = p -> prox;

    while (p!=aux){
        if (p->chave == k) return p;
        p = p -> prox;
    }
    printf(errorColor "Nó não encontrado\n" resetColor);
    return NULL;
}

void insereListaDupla(TNoEncadeado **p, int k, int chave){
    TNoEncadeado *novo=NULL;

    novo = alocaNoEncadeado(k);

    if (novo == NULL) return;

    if (chave == NULL){ //Insere no inicio quando não ha nada na lista
        *p = novo;
    }
    else{                                   // Insere no meio
        TNoEncadeado *aux = buscaNoEncadeado(*p, chave); 
        
        if (aux == NULL) return;

        if (aux->prox == NULL){ //Insere no final
            aux->prox = novo;
            novo->ant = aux;
        }
        else{
            novo->prox = aux->prox;
            novo->ant = aux;
            aux->prox->ant = novo;
            aux->prox = novo;
        }
    }
}

void insereOrdemCrescenteListaDupla(TNoEncadeado **p, int k){ 
TNoEncadeado *anterior, *proximo;

    if (*p == NULL){ // Adiciona um nó se a lista está vazia
        *p = alocaNoEncadeado(k);
        return;
    } 

    if ((*p)->chave > k){ // Adiciona um nó no inicio da lista
        TNoEncadeado *novo = alocaNoEncadeado(k);
        novo -> prox = *p; //Novo ponteiro aponta para o proximo
        *p = novo; 
        (*p) -> prox -> ant = *p; //O proximo ponteiro aponta para o novo
        return;
    }

    while (*p != NULL && (*p) -> prox != NULL){ // Adiciona um nó no meio da lista

        if ((*p) -> prox -> chave > k){
            proximo = (*p) -> prox;
            anterior = *p;
            (*p) -> prox = alocaNoEncadeado(k);
            (*p) -> prox -> prox = proximo;
            
            (*p) -> prox -> ant = anterior;
            proximo -> ant = (*p) -> prox;
            return;
        }
        
        anterior = *p;
        p = &(*p)->prox;
    }

    (*p) -> prox = alocaNoEncadeado(k); // Adiciona um nó no final da lista
    (*p) -> prox -> ant = *p; //O ponteiro novo aponta de volta para o anterior
    return;
}

void removeListaDuplamenteEncadeada(TNoEncadeado **p, int k){
     TNoEncadeado *aux = NULL, *anterior = NULL;

    if (p==NULL) return;

    aux = *p;

    if (aux->chave==k){ // Caso remover elemento que é o primeiro da lista
        if (aux->prox == NULL){ //Caso remover elemento que é o unico da lista
            free(*p);
            *p = NULL;
            return;
        }
        else{
            aux = *p;
            *p = (*p)->prox;
            (*p) -> ant = NULL;

            free(aux);
            return;
        }
    }
    else{
        anterior = aux;
        aux = aux -> prox;

        while (aux!=NULL){
            if(aux->chave == k){

                if (aux->prox == NULL){ //Caso remover que é o ultimo da lista
                    anterior->prox = NULL;
                    free(aux);
                    return;
                }
                else{
                    anterior->prox = aux->prox; //Caso remover que é o meio da lista
                    aux->prox->ant = anterior;
                    free(aux);
                    return;
                }
            }

            anterior = aux;
            aux = aux -> prox;
        }
    }
    printf(errorColor "Nó não Exite\n" resetColor);
}

void divideListaDuplamenteEncadeada(TNoEncadeado **p, TNoEncadeado **Lista2, int k){
    TNo *busca = buscaNoEncadeado(*p, k);

    if (busca == NULL) return;

    *Lista2 = busca -> prox;
    (*Lista2) -> ant = NULL;
    
    busca -> prox = NULL;
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
    int memoriaOpcao = 0;
    int chave;
    int chave2;
    TNo *lista = NULL;
    TNo *lista2 = NULL;

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
                    if (memoriaOpcao == 0){
                        printf("================Menu Inserir================\n");
                        printf("1 - Inserir após um nó\n");
                        printf("2 - Inserir em ordem crescente\n");
                        printf("3 - Inserir no começo\n");
                        printf(alertColor "PS: A opção selecionada será usada por todas as inserções a partir dessa escolha para essa lista\n" resetColor);

                        printf("\nEscolha uma opção: ");
                        scanf("%d", &opcaoUsuario);

                        printf("=============================================\n");
                        memoriaOpcao = opcaoUsuario;

                        switch (memoriaOpcao){
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
                    else{
                        switch (memoriaOpcao){
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
                printf("Lista 1: \n");
                imprimeListas(lista);
                
                if (lista2 != NULL){
                    printf("------------\n");
                    printf("Lista 2: \n");
                    imprimeListas(lista2);
                }
                break;
            case 4:
                system("@cls||clear");
                if (lista == NULL){
                    printf(errorColor "LISTA VAZIA, não é possível dividir nada!\n" resetColor);
                }
                else if(lista2 != NULL){
                    printf(errorColor "A lista já foi dividida, não é possível dividir mais!\n" resetColor);
                }
                else{
                    printf("Digite a chave: ");
                    scanf("%d", &chave);
                    divideListaSimples(&lista, &lista2, chave);
                }

                break;
            case 5:
                system("@cls||clear"); //Clear no terminal do usuário (comando válido para Windows, Linux e MacOsX)
                
                if (lista != NULL || lista2 != NULL) {
                    printf(alertColor "Caso saia do menu a(s) lista(s) será(ão) perdida(s)\n" resetColor);
                    printf("Deseja sair? (1 - Sim, 2 - Não)\n");
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
                printf(errorColor "Opção inválida\n" resetColor);
                break;
        }
    }
}

void listaComCabecaMenu(){ // Menu da lista com cabeça
    int opcaoUsuario = 0;
    int memoriaOpcao = 0;
    int chave;
    int chave2;
    TCabeca *lista = (TCabeca*)malloc(sizeof(TCabeca));
    TCabeca *lista2 = (TCabeca*)malloc(sizeof(TCabeca));

    lista->inicio = NULL;
    lista2->inicio = NULL;

    while (opcaoUsuario!=5){
        printf("===============Menu Lista Com Cabeça===============\n");
        printf("1 - Inserir\n");
        printf("2 - Remover\n");
        printf("3 - Imprimir\n");
        printf("4 - Divide Lista\n");
        printf("5 - Sair do Menu Lista Com Cabeça\n");

        printf("\nEscolha uma opção: ");
        scanf("%d", &opcaoUsuario);

        printf("===================================================\n");

        switch (opcaoUsuario){
            case 1:
                system("@cls||clear");
                if ((lista->inicio) == NULL){
                    printf("Digite a chave do novo nó: ");
                    scanf("%d", &chave);
                    insereListaSimples(&(lista->inicio), chave, NULL); 
                }
                else{
                    if (memoriaOpcao == 0){
                        printf("================Menu Inserir================\n");
                        printf("1 - Inserir após um nó\n");
                        printf("2 - Inserir em ordem crescente\n");
                        printf("3 - Inserir no começo\n");
                        printf(alertColor "PS: A opção selecionada será usada por todas as inserções a partir dessa escolha para essa lista\n" resetColor);

                        printf("\nEscolha uma opção: ");
                        scanf("%d", &opcaoUsuario);

                        printf("=============================================\n");
                        memoriaOpcao = opcaoUsuario;

                        switch (memoriaOpcao){
                            case 1:
                                system("@cls||clear");
                                printf("Digite a chave do nó: ");
                                scanf("%d", &chave);
                                printf("Digite a chave do nó após o qual o novo nó será inserido: ");
                                scanf("%d", &chave2);
                                insereListaSimples(&(lista->inicio), chave, chave2);
                                break;
                            case 2:
                                system("@cls||clear");
                                printf("Digite a chave do nó: ");
                                scanf("%d", &chave);
                                insereOrdemCrescenteListaSimples(&(lista->inicio), chave);
                                break;
                            case 3:
                                system("@cls||clear");
                                printf("Digite a chave do nó: ");
                                scanf("%d", &chave);
                                insereListaSimples(&(lista->inicio), chave, NULL);
                                break;
                            default:
                                system("@cls||clear");
                                printf(errorColor "Opção inválida\n" resetColor);
                                break;
                        }
                    }
                    else{
                        switch (memoriaOpcao){
                            case 1:
                                system("@cls||clear");
                                printf("Digite a chave do nó: ");
                                scanf("%d", &chave);
                                printf("Digite a chave do nó após o qual o novo nó será inserido: ");
                                scanf("%d", &chave2);
                                insereListaSimples(&(lista->inicio), chave, chave2);
                                break;
                            case 2:
                                system("@cls||clear");
                                printf("Digite a chave do nó: ");
                                scanf("%d", &chave);
                                insereOrdemCrescenteListaSimples(&(lista->inicio), chave);
                                break;
                            case 3:
                                system("@cls||clear");
                                printf("Digite a chave do nó: ");
                                scanf("%d", &chave);
                                insereListaSimples(&(lista->inicio), chave, NULL);
                                break;
                            default:
                                system("@cls||clear");
                                printf(errorColor "Opção inválida\n" resetColor);
                                break;
                        }
                    }
                }
                break;
            case 2:
                system("@cls||clear");
                if ((lista->inicio) == NULL){
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
                        removeListaSimples(&(lista->inicio), chave);
                    }
                    else if (opcaoUsuario == 2){
                        system("@cls||clear");
                        removeTodosListaSimples(&(lista->inicio));
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
                printf("Lista 1: \n");
                imprimeListas((lista->inicio));
                
                if ((lista2->inicio) != NULL){
                    printf("------------\n");
                    printf("Lista 2: \n");
                    imprimeListas((lista2->inicio));
                }
                break;
            case 4:
                system("@cls||clear");
                if ((lista->inicio) == NULL){
                    printf(errorColor "LISTA VAZIA, não é possível dividir nada!\n" resetColor);
                }
                else if((lista2->inicio) != NULL){
                    printf(errorColor "A lista já foi dividida, não é possível dividir mais!\n" resetColor);
                }
                else{
                    printf("Digite a chave: ");
                    scanf("%d", &chave);
                    divideListaSimples(&(lista->inicio), &(lista2->inicio), chave);
                }

                break;
            case 5:
                system("@cls||clear"); //Clear no terminal do usuário (comando válido para Windows, Linux e MacOsX)
                
                if ((lista->inicio) != NULL || (lista2->inicio) != NULL) {
                    printf(alertColor "Caso saia do menu a(s) lista(s) será(ão) perdida(s)\n" resetColor);
                    printf("Deseja sair? (1 - Sim, 2 - Não)\n");
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
                printf(errorColor "Opção inválida\n" resetColor);
                break;
        }
    }
}

void listaCircularMenu(){ // Menu da lista circular
    int opcaoUsuario = 0;
    int memoriaOpcao = 0;
    int chave;
    int chave2;
    TNo *lista = NULL;
    TNo *lista2 = NULL;

    while (opcaoUsuario!=5){
        printf("================Menu Lista Circular================\n");
        printf("1 - Inserir\n");
        printf("2 - Remover\n");
        printf("3 - Imprimir\n");
        printf("4 - Divide Lista\n");
        printf("5 - Sair do Menu Lista Circular\n");

        printf("\nEscolha uma opção: ");
        scanf("%d", &opcaoUsuario);

        printf("===================================================\n");

        switch (opcaoUsuario){
            case 1:
                system("@cls||clear");
                if (lista == NULL){
                    printf("Digite a chave do novo nó: ");
                    scanf("%d", &chave);
                    insereListaCircular(&lista, chave, NULL); 
                }
                else{
                    if (memoriaOpcao == 0){
                        printf("================Menu Inserir================\n");
                        printf("1 - Inserir após um nó\n");
                        printf("2 - Inserir em ordem crescente\n");
                        printf(alertColor "PS: A opção selecionada será usada por todas as inserções a partir dessa escolha para essa lista\n" resetColor);

                        printf("\nEscolha uma opção: ");
                        scanf("%d", &opcaoUsuario);

                        printf("=============================================\n");
                        memoriaOpcao = opcaoUsuario;

                        switch (memoriaOpcao){
                            case 1:
                                system("@cls||clear");
                                printf("Digite a chave do nó: ");
                                scanf("%d", &chave);
                                printf("Digite a chave do nó após o qual o novo nó será inserido: ");
                                scanf("%d", &chave2);
                                insereListaCircular(&lista, chave, chave2);
                                break;
                            case 2:
                                system("@cls||clear");
                                printf("Digite a chave do nó: ");
                                scanf("%d", &chave);
                                insereOrdemCrescenteListaCircular(&lista, chave);
                                break;
                            default:
                                system("@cls||clear");
                                printf(errorColor "Opção inválida\n" resetColor);
                                break;
                        }
                    }
                    else{
                        switch (memoriaOpcao){
                            case 1:
                                system("@cls||clear");
                                printf("Digite a chave do nó: ");
                                scanf("%d", &chave);
                                printf("Digite a chave do nó após o qual o novo nó será inserido: ");
                                scanf("%d", &chave2);
                                insereListaCircular(&lista, chave, chave2);
                                break;
                            case 2:
                                system("@cls||clear");
                                printf("Digite a chave do nó: ");
                                scanf("%d", &chave);
                                insereOrdemCrescenteListaCircular(&lista, chave);
                                break;
                            default:
                                system("@cls||clear");
                                printf(errorColor "Opção inválida\n" resetColor);
                                break;
                        }
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
                        removeListaCircular(&lista, chave);
                    }
                    else if (opcaoUsuario == 2){
                        system("@cls||clear");
                        removeTodosListaCircular(&lista);
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
                printf("Lista 1: \n");
                imprimeListaCircular(lista);
                
                if (lista2 != NULL){
                    printf("------------\n");
                    printf("Lista 2: \n");
                    imprimeListaCircular(lista2);
                }
                break;
            case 4:
                system("@cls||clear");
                if (lista == NULL){
                    printf(errorColor "LISTA VAZIA, não é possível dividir nada!\n" resetColor);
                }
                else if(lista2 != NULL){
                    printf(errorColor "A lista já foi dividida, não é possível dividir mais!\n" resetColor);
                }
                else{
                    printf("Digite a chave: ");
                    scanf("%d", &chave);
                    divideListaCircular(&lista, &lista2, chave);
                }

                break;
            case 5:
                system("@cls||clear"); //Clear no terminal do usuário (comando válido para Windows, Linux e MacOsX)
                
                if (lista != NULL || lista2 != NULL) {
                    printf(alertColor "Caso saia do menu a(s) lista(s) será(ão) perdida(s)\n" resetColor);
                    printf("Deseja sair? (1 - Sim, 2 - Não)\n");
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
                printf(errorColor "Opção inválida\n" resetColor);
                break;
        }
    }
}

void listaDuplamenteEncadeadaMenu(){ // Menu da lista duplamente encadeada
    int opcaoUsuario = 0;
    int memoriaOpcao = 0;
    int chave;
    int chave2;
    TNo *lista = NULL;
    TNo *lista2 = NULL;

    while (opcaoUsuario!=5){
        printf("===========Menu Lista Duplamente Encadeada===========\n");
        printf("1 - Inserir\n");
        printf("2 - Remover\n");
        printf("3 - Imprimir\n");
        printf("4 - Divide Lista\n");
        printf("5 - Sair do Menu Lista Simples\n");

        printf("\nEscolha uma opção: ");
        scanf("%d", &opcaoUsuario);

        printf("=====================================================\n");

        switch (opcaoUsuario){
            case 1:
                system("@cls||clear");
                if (lista == NULL){
                    printf("Digite a chave do novo nó: ");
                    scanf("%d", &chave);
                    insereListaDupla(&lista, chave, NULL); 
                }
                else{
                    if (memoriaOpcao == 0){
                        printf("================Menu Inserir================\n");
                        printf("1 - Inserir após um nó\n");
                        printf("2 - Inserir em ordem crescente\n");
                        printf(alertColor "PS: A opção selecionada será usada por todas as inserções a partir dessa escolha para essa lista\n" resetColor);

                        printf("\nEscolha uma opção: ");
                        scanf("%d", &opcaoUsuario);

                        printf("=============================================\n");
                        memoriaOpcao = opcaoUsuario;

                        switch (memoriaOpcao){
                            case 1:
                                system("@cls||clear");
                                printf("Digite a chave do nó: ");
                                scanf("%d", &chave);
                                printf("Digite a chave do nó após o qual o novo nó será inserido: ");
                                scanf("%d", &chave2);
                                insereListaDupla(&lista, chave, chave2);
                                break;
                            case 2:
                                system("@cls||clear");
                                printf("Digite a chave do nó: ");
                                scanf("%d", &chave);
                                insereOrdemCrescenteListaDupla(&lista, chave);
                                break;
                            default:
                                system("@cls||clear");
                                printf(errorColor "Opção inválida\n" resetColor);
                                break;
                        }
                    }
                    else{
                        switch (memoriaOpcao){
                            case 1:
                                system("@cls||clear");
                                printf("Digite a chave do nó: ");
                                scanf("%d", &chave);
                                printf("Digite a chave do nó após o qual o novo nó será inserido: ");
                                scanf("%d", &chave2);
                                insereListaDupla(&lista, chave, chave2);
                                break;
                            case 2:
                                system("@cls||clear");
                                printf("Digite a chave do nó: ");
                                scanf("%d", &chave);
                                insereOrdemCrescenteListaDupla(&lista, chave);
                                break;
                            default:
                                system("@cls||clear");
                                printf(errorColor "Opção inválida\n" resetColor);
                                break;
                        }
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
                        removeListaDuplamenteEncadeada(&lista, chave);
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
                printf("Lista 1: \n");
                imprimeListas(lista);
                
                if (lista2 != NULL){
                    printf("------------\n");
                    printf("Lista 2: \n");
                    imprimeListas(lista2);
                }
                break;
            case 4:
                system("@cls||clear");
                if (lista == NULL){
                    printf(errorColor "LISTA VAZIA, não é possível dividir nada!\n" resetColor);
                }
                else if(lista2 != NULL){
                    printf(errorColor "A lista já foi dividida, não é possível dividir mais!\n" resetColor);
                }
                else{
                    printf("Digite a chave: ");
                    scanf("%d", &chave);
                    divideListaDuplamenteEncadeada(&lista, &lista2, chave);
                }

                break;
            case 5:
                system("@cls||clear"); //Clear no terminal do usuário (comando válido para Windows, Linux e MacOsX)
                
                if (lista != NULL || lista2 != NULL) {
                    printf(alertColor "Caso saia do menu a(s) lista(s) será(ão) perdida(s)\n" resetColor);
                    printf("Deseja sair? (1 - Sim, 2 - Não)\n");
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
                printf(errorColor "Opção inválida\n" resetColor);
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
    printf(contrastColor "João Vitor Queiroz de Campos Pires\n" resetColor);
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