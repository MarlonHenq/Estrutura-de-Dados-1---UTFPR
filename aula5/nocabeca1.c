#include <stdio.h>

typedef struct no{
    int chave;
    struct no *prox;
} No;

No *criaLista()
{
    No* cabeca = (No *) malloc(sizeof(No));
    
    if (cabeca == NULL) return NULL;
    
    cabeca->chave = -1; //valor reservadocabeca->prox = NULL;
    cabeca->prox = NULL;

    return cabeca;
}

No *alocaNo(int n){
    No *novo = (No *) malloc(sizeof(No));
    if (novo == NULL) return NULL;
    novo->chave = n;
    novo->prox = NULL;
    return novo;
}

void insereInicio2(No *cabeca, int n){
    No *novo = alocaNo(n);
    if (novo == NULL) return;
    novo->prox = cabeca->prox;
    cabeca->prox = novo;
}

void imprimeLista(No *p){

    if (p != NULL) p = p->prox;
    else printf("Lista vazia\n");

    while (p != NULL){
        printf("%d\n", p->chave);
        p = p->prox;
    }
}

void removeInicio(No *cabeca){

    if (cabeca->prox == NULL) {
        printf("Lista vazia\n");
        return;
    }

    No *aux = cabeca->prox;
    cabeca->prox = aux->prox;
    free(aux); // Já ia morrer mesmo fdp
}

No *busca(No *cabeca, int n){
    No *p = cabeca->prox;
    while (p != NULL) {
        p = p->prox;
        if (p->chave == n) return p;
    }

    printf("Não encontrado\n");
    return NULL;
}

void insereFinal(No *cabeca, int n){
    No *novo = alocaNo(n);
    if (novo == NULL) return;
    No *p = cabeca;
    while (p->prox != NULL) p = p->prox;
    p->prox = novo;
}

void copiaLista (No *cabeca, No *cabeca2){
    No *p = cabeca->prox;
    while (p != NULL) {
        insereInicio2(cabeca2, p->chave);
        p = p->prox;
    }
}


int main(){
    
    No *prim = criaLista();
    insereInicio2(prim, 7);
    insereInicio2(prim, 12);
    insereInicio2(prim, 78);
    insereInicio2(prim, 92);
    
    // printf("%d\n", prim->chave);
    // printf("%d\n", prim->prox->chave);

    imprimeLista(prim);

    while(prim->prox != NULL){
        removeInicio(prim);
    }

    printf("\n\n");

    imprimeLista(prim);

    printf("\n\n");

    insereInicio2(prim, 7070);

    imprimeLista(prim);

    return 0;
}