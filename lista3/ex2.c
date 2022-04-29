// 2. Faça uma agenda de compromissos:
//      a. Crie e leia um vetor de n estruturas de dados contento: compromisso
//  (máximo 60 letras) e data.
//      b. A data deve ser outra estrutura de dados contendo dia, mês e ano.
//      c. Leia dois inteiros m (mês) e a (ano). Apresente todos os compromissos do
//  mês m do ano a. Repita o procedimento até ler m = 0.


#include <stdio.h>
#include <stdlib.h>

typedef struct data{
    int dia, mes, ano;
} data;

typedef struct compromissos
{
    char nome[60];
    data x;
} compromissos;


int main(){
    int qCompromissos;
    printf("Informe a quantidade de compromissos: \n");
    scanf("%d", &qCompromissos);

    compromissos c[qCompromissos];
    
    for (int i = 0; i < qCompromissos; i++){
        printf("Informe o nome do compromisso %d: \n", i+1);
        setbuf(stdin, NULL);
        fgets(c[i].nome, 60, stdin);

        printf("Informe a data do seu compromisso (DD;MM;AAAA)\n");
        scanf("%d;%d;%d", &c[i].x.dia,&c[i].x.mes,&c[i].x.ano);
    }
    
    printf("Informe a data que queira pesquisar (MM;AAAA) \n");
    int mes, ano;
    scanf("%d;%d", &mes, &ano);
    
    for (int i = 0; i < qCompromissos; i++){
        if (c[i].x.mes == mes && c[i].x.ano == ano){
            printf("%s", c[i].nome);
        }
    }
    

    return 0;
}