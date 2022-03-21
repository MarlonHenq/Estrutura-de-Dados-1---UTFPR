# include <stdio.h>

void criptografia(char *var){
    char letra;
    for (int i = 0; i < 30; i++){
        if ((var[i] + 3) >= 'A' && (var[i] + 3) <= 'Z'){
            letra = var[i] + 3;
            
        }
        else{
            letra = var[i] + 3;
            letra = letra - 26;
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