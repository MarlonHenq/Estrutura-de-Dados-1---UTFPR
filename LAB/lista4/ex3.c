// 3) Faça um programa que leia 2 valores inteiros e chame uma função que receba estas 2
// variáveis e troque o seu conteúdo, ou seja, esta função é chamada passando duas variáveis A e
// B por exemplo e, após a execução da função, A conterá o valor de B e B terá o valor de A.
// Entrada 1 : 6 8
// SAIDA 1 : PA = 8, PB = 6

#include <stdio.h>
#include <stdlib.h>

void troca(int *p, int *p2){
    int aux;
    aux = *p;
    *p = *p2;
    *p2 = aux;
}

int main(){
    int a = 4, b = 5;

    troca(&a,&b);

    printf("a = %d, b = %d \n", a, b);

    return 0;
}