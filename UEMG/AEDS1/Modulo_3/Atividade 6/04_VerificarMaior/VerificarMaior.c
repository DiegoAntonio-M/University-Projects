# include <stdio.h>
# include <math.h>
# include <stdlib.h>
# include <string.h>

int verificarMaior(int valor1, int valor2, int valor3) {

    int maior = valor1;
    if (valor1 > maior) {
        maior = valor1;
    }
    if (valor3 > maior) {
        maior = valor3;
    }
    return maior;
}

int main() {

    int v1;
    int v2;
    int v3;

    printf("Digite o primeiro valor: ");
    scanf("%d", &v1);
    printf("Digite o segundo valor: ");
    scanf("%d", &v2);
    printf("Digite o terceiro valor: ");
    scanf("%d", &v3);

    int maior = verificarMaior(v1, v2, v3);
    printf("O maior valor é: %d\n", maior);

    return 0;
}