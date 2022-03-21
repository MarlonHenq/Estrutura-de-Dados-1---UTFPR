# include <stdio.h>

void criptografia(char *var){
    char letra;
    for (int i = 0; i < 30; i++){
        if (var[i] >= 'A' && var[i] <= 'Z'){
            letra = var[i] - 'A';
            letra = letra + 3;
            letra = letra % 26;
            letra = letra + 'A';
            var[i] = letra;
        }
    }
}

int main()
{
    char text[30];
    scanf("%s",text);
    criptografia(text);
    printf("%s",text);
}