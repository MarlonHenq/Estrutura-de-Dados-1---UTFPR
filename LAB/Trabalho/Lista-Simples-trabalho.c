#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int chave;
    struct no *prox;
}TNo;

TNo *alocaNo(int k){
    TNo *novo = (TNo*)malloc(sizeof(TNo));

    if (novo == NULL) return;

    novo->chave = k;
    novo->prox = NULL;

    return novo;
}

void insereLista(TNo **p, int k){
    TNo *novo=NULL;
    novo = alocaNo(k);

    if (novo == NULL) return NULL;

    novo -> prox = *p;
    *p = novo;
}

void imprimeLista(TNo *p){
    if (p == NULL){
        printf("LISTA VAZIA\n");
        return;
    }

    while (p!=NULL){
        printf("%d\n", p->chave);
        p = p -> prox;
    }
}

TNo *divideLista(TNo **p, int k){
    TNo *aux = NULL, *anterior = NULL;

    if (p==NULL) return NULL;

    aux = *p;

    if ((*p)->chave==k){
        *p = NULL;
        return aux;
    }
    else{
        anterior = aux;
        aux = aux -> prox;

        while (aux!=NULL){
            if(aux->chave == k){
                anterior->prox = NULL;
                return aux;
            }

            anterior = aux;
            aux = aux->prox;
        }

        printf("CHAVE NAO ENCONTRADA");

        return NULL;

    }

}

int main(){

    int op = 0;
    int k;

    TNo *lista = NULL;
    TNo *lista2 = NULL;

    while (op!=4){
        printf("===================\n");
        printf("1-Insere\n");
        printf("2-Imprime\n");
        printf("3-Divide\n");
        printf("4-Sair\n");
        printf("-Escolha a opção: ");
        scanf("%d", &op);
        printf("===================\n");

        switch (op){
            case 1:
                printf("Digite a chave: ");
                scanf("%d", &k);
                insereLista(&lista, k);
                break;
            case 2:
                printf("Lista1: \n");
                imprimeLista(lista);
                printf("-------\n");
                printf("Lista2: \n");
                imprimeLista(lista2);
                break;
            case 3:
                printf("Digite a chave: ");
                if (lista2 == NULL){
                    scanf("%d", &k);

                    lista2 = divideLista(&lista, k);
                }
                else{
                    printf("\n");
                    printf("LISTA NAO PODE SER DIVIDIDA NOVAMENTE\n");
                }
                
                break;
            case 4:
                printf("Goodbye\n");
                exit(1);
                break;
            default:
                printf("OPCAO INVALIDA\n");
        }
    }

    return 0;
}