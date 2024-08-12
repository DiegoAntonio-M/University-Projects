# include <stdio.h>
# include <math.h>
# include <stdlib.h>
# include <string.h>

int fatorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    } else {
        return n * fatorial(n - 1);
    }
}

int main() {

    int numero;
    printf("Digite um número para calcular o fatorial: ");
    scanf("%d", &numero);
    
    int resultado = fatorial(numero);
    printf("O fatorial de %d é %d\n", numero, resultado);
    
    return 0;
}