#include <stdio.h>

void ordene(int **ppa, int **ppb, int **ppc){ // Função sorting
    //printf("%p %p %p\n", *pa, *pb, *pc);
    //printf("%p %p %p\n", **pa, **pb, **pc);

    int temp; //Variável auxiliar

    if(**ppa < **ppb){ // Sorting
        temp = **ppa;
        **ppa = **ppb;
        **ppb = temp;
    }
    if(**ppa < **ppc){
        temp = **ppa;
        **ppa = **ppc;
        **ppc = temp;
    }
    if(**ppb < **ppc){
        temp = **ppb;
        **ppb = **ppc;
        **ppc = temp;
    }
}

//Main Intacta
int main()
{
    int a = 0 ;
    int b = 0 ;
    int c = 0 ;
    int *pa = &a ;
    int *pb = &b ;
    int *pc = &c ;
    scanf("%i%i%i",pa,pb,pc);
    ordene(&pa,&pb,&pc);
    printf("PA = %i, ",*pa);
    printf("PB = %i, ",*pb);
    printf("PC = %i",*pc);
}