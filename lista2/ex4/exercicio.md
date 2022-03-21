4) Complete o algoritmo, implementando o procedimento "ordene", que colocará os números
pa, pb, pc em ordem decrescente.
OBS: você não poderá fazer alterações na Main.

#include <stdio.h>
// ... ordene (...) {...}
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


Entrada 1 : 7 8 9
SAIDA 1 : PA = 9, PB = 8, PC = 7
Entrada 2 : 8 7 9
SAIDA 2 : PA = 9, PB = 8, PC = 7