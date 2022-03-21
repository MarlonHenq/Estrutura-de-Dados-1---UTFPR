# include <stdio.h>

void criptografia(char *var){ //função para criptografar a mensagem (shift +3)
    char letra;
    for (int i = 0; i < 30; i++){ //loop para percorrer a mensagem
        if ((var[i] + 3) >= 'A' && (var[i] + 3) <= 'Z'){ //Verifica se a letra +3 está entre a e Z
            letra = var[i] + 3; //letra recebe a letra +3
        }
        else{ //Se não, volta-se para o começo do alfabeto e adiciona +3
            letra = var[i] + 3;
            letra = letra - 26;
        }
    }
}

//Main Intacta
int main()
{
    char text[30];
    scanf("%s",text);
    criptografia(text);
    printf("%s",text);
}