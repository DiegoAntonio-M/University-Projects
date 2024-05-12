#include <stdio.h>

int main () {

    int numero = 0;
    int i = 1;

    printf("Digite um número: ");
    scanf("%d", &numero);

    while (i <= numero) {
        
        if (numero % i == 0) {
            printf("O número %d eh divisível por %d.\n", numero, i);
        }
        
        i++;
    }
    
}

