# include <stdio.h>

int main () {

    int valorInicial = 0;
    int valorFinal = 0;
    int soma = 0;

    printf("Digite o valor inicial e valor final: ");
    scanf("%d %d", &valorInicial, &valorFinal);

    if (valorInicial > valorFinal) {
        printf("Intervalo de valores inválido\n");
        return 0;
    }

    for (int i = valorInicial; i <= valorFinal; i++) {
        if (i % 2 != 0) {
            soma += i;
        }
    }

    printf("Soma dos ímpares neste intervalo: %d\n", soma);

    return 0;
} 
