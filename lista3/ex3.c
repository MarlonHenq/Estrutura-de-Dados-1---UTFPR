// 3. Crie uma estrutura representando os alunos de um determinado curso. A estrutura
// deve conter a matrícula do aluno, nome, nota da primeira prova, nota da segunda prova
// e nota da terceira prova.
// (a) Permita ao usuário entrar com os dados de 5 alunos.
// (b) Encontre o aluno com maior nota da primeira prova.
// (c) Encontre o aluno com maior media geral.
// (d) Encontre o aluno com menor media geral
// (e) Para cada aluno diga se ele foi aprovado ou reprovado, considerando o valor 6 para
// aprovação.

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct aluno{
    int matricula;
    char nome[50];
    int p1, p2, p3;
}aluno;

int main(){

    aluno vector[5];

    for (int i = 0; i < 5; i++){
        printf("Sobre o aluno %d digite:\n", i+1);
        printf("Matricula: \n");
        scanf("%d", &vector[i].matricula);
        printf("Nome:\n");
        setbuf(stdin, NULL);
        fgets(vector[i].nome, 50, stdin);
        printf("Digite as notas das provas (p1;p2;p3)");
        scanf("%d;%d;%d", &vector[i].p1, &vector[i].p2, &vector[i].p3);
    }

    char maiornotaN[50];
    strcpy(maiornotaN, vector[0].nome);
    int maiornota = vector[0].p1;

    for (int i = 1; i < 5; i++){
        if (maiornota < vector[i].p1){
            maiornota = vector[i].p1;
            strcpy(maiornotaN, vector[i].nome);
        }
    }
    
    printf("O aluno com maior nota é: %s", maiornotaN);

    return 0;
}