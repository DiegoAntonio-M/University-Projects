#include <stdio.h>

int main(int argc, char const *argv[]) {

    int numero = 0;
    int contar = 0;

    printf("Digite um numero inteiro positivo: ");
    scanf("%d", &numero);

    int i = numero;

    while (i >= 0) {

        int ii = 1;
        contar = 0;

        while (ii <= i) {

            if (i % ii == 0) {
                contar++;
            }
            ii++;
        }

        if (contar == 2) {
            printf("%d é primo!\n", i);
        }
        
        i--;
    }
    
    return 0;
}
