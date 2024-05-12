# include <stdio.h>

int main () {

    int num = 0;
    int primeiro = 0;
    int segundo = 1;
    int proximo = 0;

    printf("Digite um número positivo: ");
    scanf("%d", &num);

    printf("Sequência Fibonacci até o primeiro número superior a %d: ", num);

    while (proximo <= num) {
        printf("%d ", primeiro);
        proximo = primeiro + segundo;
        primeiro = segundo;
        segundo = proximo;
    }

    printf("%d\n", proximo);

    return 0;
}