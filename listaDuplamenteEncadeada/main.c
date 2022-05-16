#include<stdio.h>
#include<stdlib.h>

typedef struct no{
	int chave;
	struct no *ant;
	struct no *prox;
}TNo;

TNo * alocaNo(int k)
{
	TNo *paux;
	paux = (TNo *)malloc(sizeof(TNo));
	if(paux==NULL) return NULL;
	paux->chave = k;
	paux->prox = NULL;
	paux->ant = NULL;
	return paux;
}

// void insereListaR(TNo **p, int chave){
//     TNo *paux;
//     paux = alocaNo(chave);
//     if(paux==NULL) return;
//     if(*p==NULL){
//         *p = paux;
//         return;
//     }
//     if(chave < (*p)->chave){
//         paux->prox = *p;
//         (*p)->ant = paux;
//         *p = paux;
//         return;
//     }
//     TNo *paux2 = *p;
//     while(paux2->prox != NULL && paux2->prox->chave < chave){
//         paux2 = paux2->prox;
//     }
//     paux->prox = paux2->prox;
//     paux->ant = paux2;
//     if(paux2->prox != NULL) paux2->prox->ant = paux;
//     paux2->prox = paux;
// }


void insereListaD(TNo **p, int chave) //Começa da direita
{
	TNo *novo;
	novo = alocaNo(chave);
	if(novo == NULL) return;
	novo->prox = *p;
	//verifica lista
	if(*p!=NULL)
	(*p)->ant = novo;
	*p = novo;
}

void imprimeLista(TNo *p)
{
	if(p==NULL)
	{
		printf("Lista vazia!\n");
		return;
	}
	while(p!=NULL)
	{
		printf("%d\n", p->chave);
		p = p->prox;
	}
}

void imprimeListaE(TNo *p){ // Começa do ultimo elemento
    if(p==NULL)
    {
        printf("\nLista vazia!");
        return;
    }
    while(p->prox!=NULL)
    {
        p = p->prox;
    }
    while(p!=NULL)
    {
        printf("%d\n", p->chave);
        p = p->ant;
    }
}

TNo *buscaNo(TNo *p, int elem){
    while(p!=NULL){
        if(p->chave == elem) return p;
        p = p->prox;
    }
    return NULL;
}

void removeNo(TNo **p, int k){
    TNo *paux;
    paux = *p;

    if(paux==NULL) return;
    else{
        if ((*p)->chave == k){
            *p = (*p)->prox;
            paux -> prox = NULL;
            paux -> ant = NULL;
            free(paux);
            return;
        }
        else{
            while(paux->prox != NULL && paux->prox->chave != k){
                paux = paux->prox;
            }
            if(paux->prox == NULL) return;
            else{
                paux->ant->prox = paux->prox;
                paux->prox->ant = paux->ant;

                // ou 
                // TNo *anterior, *proximo;
                // anterior = paux->ant;
                // proximo = paux->prox;
                // anterior->prox = proximo;
                // proximo->ant = anterior;

                paux->prox = NULL;
                paux->ant = NULL;
                free(paux);
            }
        }
    }
}

int main()
{
	TNo *prim=NULL;
	int op=1,n;
	while(op!=5)
	{
		printf("\n1-Insere inicio");
		printf("\n2-Imprime");
		printf("\n3-Busca");
		printf("\n4-Remove");
		printf("\n5-Sair\n");
		printf("\nInforme opcao:");
		scanf("%d",&op);
		switch(op)
		{
			case 1:
				{
					printf("\nInforme valor:");
					scanf("%d",&n);
					insereListaD(&prim, n);	
				}break;
			case 2:
				{
					imprimeLista(prim);

                    printf("INVERTE\n");

                    imprimeListaE(prim);
				} break;
            case 3:
                {
                    printf("Informe valor:\n");
                    scanf("%d",&n);
                    TNo *recebe = buscaNo(prim, n);
                    if(recebe!=NULL) printf("Elemento encontrado!\n");
                    else printf("Elemento nao encontrado!\n");
                } break;
		}
	}
	
}