#include <stdio.h>

int main () {

    int numero = 1000;
    int i = 1;
    int soma = 0;

    while (i <= numero) {
        
        if ((i % 3 == 0) || (i % 5 == 0)) {
            soma += i;
            // printf("Soma: %d\n", soma);
        }
        
        i++;
    }
    printf("Soma: %d\n", soma);
}