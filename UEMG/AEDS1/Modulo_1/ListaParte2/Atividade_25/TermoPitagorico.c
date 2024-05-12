# include <stdio.h>

int main () {

    int a = 0;
    int b = 0;
    int c = 0;

    for (a = 1; a <= 1000; a++) {
        for (b = a; b <= 1000; b++) {
            c = 1000 - a - b;
            if (a * a + b * b == c * c) {
                printf("O terno pitagórico para o qual a + b + c = 1000 é: a=%d, b=%d, c=%d\n", a, b, c);
                return 0;
            }
        }
    }

    printf("Não foi encontrado um terno pitagórico para o qual a + b + c = 1000.\n");

    return 0;
}