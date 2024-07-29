# include <stdio.h>
# include <stdlib.h>
# include <string.h>

int main() {

    char string1[20] = {};
    char caracter[2] = {};

    int contarCaracater = 0;

    fputs("Digite a sua string: ", stdout);
    fgets(string1, 20, stdin);

    fputs("Digite o caracter que procura: ", stdout);
    fgets(caracter, 2, stdin);

    int tamanhoFrase = strlen(string1);

    for (int i = 0; i < tamanhoFrase; i++) {
        if (string1[i] == caracter[0]) {
            contarCaracater++;
        }        
    }

    printf("A quanitidade de caracter(es) '%c' é(são): %d", caracter[0], contarCaracater);

    return 0;
}