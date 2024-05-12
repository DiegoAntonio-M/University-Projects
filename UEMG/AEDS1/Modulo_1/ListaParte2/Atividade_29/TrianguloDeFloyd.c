# include <stdio.h>

int main () {

    int n = 0;
    int count = 1;

    printf("Digite um número inteiro positivo: ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        for (int ii = 1; ii <= i; ii++) {
            printf("%d ", count);
            count++;
        }
        printf("\n");
    }

    return 0;
}