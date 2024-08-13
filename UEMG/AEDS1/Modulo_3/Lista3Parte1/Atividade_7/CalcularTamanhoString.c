# include <stdio.h>
# include <math.h>
# include <stdlib.h>
# include <string.h>

void tamanhoString(char *str, int *tamanhoString) {
    // int tamanho1 = sizeof(str);
    // int tamanho2 = sizeof(str[0]);
    // int tamanhoArray = tamanho1/tamanho2;
    int achado = 0;
    int i = 0; 
    while (achado == 0) {
        if (str[i+1] == '\000' && str[i] == '\n') {
            *tamanhoString = i;
            achado = 1;
            break;
        }
        i++;    
    }    
}

int main() {
    
    char string[40] = {};
    int tamanhoDaFrase = 0;
    fputs("Digite uma frase: ", stdout);
    fgets(string, 38, stdin);
    tamanhoString(string, &tamanhoDaFrase);

    printf("O tamanho da Frase eh: %d.", tamanhoDaFrase);

    return 0;
}