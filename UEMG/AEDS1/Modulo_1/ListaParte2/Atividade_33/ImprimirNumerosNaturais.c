# include <stdio.h>

int main () {

    int n = 0;
    int i = 0;
    int j = 0;
    int count = 0;

    printf("Digite o valor de n: ");
    scanf("%d", &n);

    printf("Digite o valor de i: ");
    scanf("%d", &i);

    printf("Digite o valor de j: ");
    scanf("%d", &j);

    for (int num = 0; count < n; num++) {
        if (num % i == 0 || num % j == 0) {
            printf("%d ", num);
            count++;
        }
    }

    printf("\n");

    return 0;
}
