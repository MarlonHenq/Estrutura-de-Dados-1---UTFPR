5) Complete o algoritmo, implementando o procedimento "criptografia" utilizando a
criptografia de césar.
OBS: não pode conter alteração na Main.
# include <stdio.h>
// ... criptografia (...) {...}
int main()
{
    char text[30];
    scanf("%s",text);
    criptografia(text);
    printf("%s",text);
}

ENTRADA :
String de tamanho max = 30 caracteres
contendo apenas os seguintes caracteres:
A até Z (maiúsculo, sem 'Ç' e sem acentuação ) ;
/0 ;
EX de entrada: ABCDEFGHIJKLMNOPQRSTUVWXYZ
EX de saida : DEFGHIJKLMNOPQRSTUVWXYZABC