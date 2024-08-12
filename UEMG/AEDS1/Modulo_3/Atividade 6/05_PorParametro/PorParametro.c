# include <stdio.h>
# include <math.h>
# include <stdlib.h>
# include <string.h>

void encontrarOuMenorMaior(int a, int b, int c, int *menor, int *maior) {
    *menor = a;
    *maior = a;

    if (b < *menor) *menor = b;
    if (c < *menor) *menor = c;

    if (b > *maior) *maior = b;
    if (c > *maior) *maior = c;
}

int main() {

    int a, b, c, menor, maior;

    printf("Digite três valores: ");
    scanf("%d %d %d", &a, &b, &c);

    encontrarOuMenorMaior(a, b, c, &menor, &maior);

    printf("Menor valor: %d\n", menor);
    printf("Maior valor: %d\n", maior);

    return 0;
}