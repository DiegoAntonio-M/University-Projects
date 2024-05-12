# include <stdio.h>

int main () {

    int valor = 0;
    int nota100 = 0;
    int nota50 = 0;
    int nota20 = 0;
    int nota10 = 0;
    int nota5 = 0;
    int nota1 = 0;

    printf("Digite o valor do saque: ");
    scanf("%d", &valor);

    nota100 = valor / 100;
    valor = valor % 100;

    nota50 = valor / 50;
    valor = valor % 50;

    nota20 = valor / 20;
    valor = valor % 20;

    nota10 = valor / 10;
    valor = valor % 10;

    nota5 = valor / 5;
    valor = valor % 5;

    nota1 = valor;

    printf("Notas necessárias para o saque:\n");
    if (nota100 != 0) {
        printf("Notas de R$ 100: %d\n", nota100);
    }
    if (nota50 != 0) {
        printf("Notas de R$ 50: %d\n", nota50);
    }
    if (nota20 != 0) {
        printf("Notas de R$ 20: %d\n", nota20);
    }
    if (nota10 != 0) {
        printf("Notas de R$ 10: %d\n", nota10);
    }
    if (nota5 != 0) {
        printf("Notas de R$ 5: %d\n", nota5);
    }
    if (nota1 != 0) {
        printf("Notas de R$ 1: %d\n", nota1);
    }

    return 0;
}
