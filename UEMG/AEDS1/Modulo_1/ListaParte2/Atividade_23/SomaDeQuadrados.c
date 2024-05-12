# include <stdio.h>

int main () {

    int n = 100;
    int soma_quadrados = 0;
    int quadrado_soma = 0;
    int diferenca = 0;

    for (int i = 1; i <= n; i++) {
        soma_quadrados += i * i;
        quadrado_soma += i;
    }

    quadrado_soma *= quadrado_soma;
    diferenca = quadrado_soma - soma_quadrados;

    printf("A diferença entre a soma dos quadrados dos primeiros %d números naturais e o quadrado da soma é: %d\n", n, diferenca);

    return 0;
}