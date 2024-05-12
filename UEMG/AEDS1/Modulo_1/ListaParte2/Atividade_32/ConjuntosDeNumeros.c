# include <stdio.h>
# include <math.h>

int main () {

    double valor = 0.0;

    while (1 == 1) {
        printf("Digite um valor: ");
        scanf("%lf", &valor);

        if (valor <= 0) {
            break;
        }

        printf("Quadrado: %.2lf\n", valor * valor);
        printf("Cubo: %.2lf\n", valor * valor * valor);
        printf("Raiz quadrada: %.2lf\n", sqrt(valor));
    }

    printf("Programa finalizado.\n");

    return 0;
}
