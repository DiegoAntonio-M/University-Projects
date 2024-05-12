# include <stdio.h>

int main () {

    int n;
    double H = 0.0;

    printf("Digite um valor inteiro e positivo: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Valor inválido\n");
        return 0;
    }

    for (int i = 1; i <= n; i++) {
        H += 1.0 / i;
    }

    printf("H(%d) = %.2lf\n", n, H);

    return 0;
} 
