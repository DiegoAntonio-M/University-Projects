# include <stdio.h>

int main () {

    int ano = 0;
    int bissexto = 0;

    printf("Digite o ano: ");
    scanf("%d", &ano);

    if (ano % 4 == 0) {
        if (ano % 100 != 0 || ano % 400 == 0) {
            printf("É ano Bissesto.\n");
        } else {
            printf("Não é ano Bissesto.\n");
        }
    } else {
            printf("Não é ano Bissesto.\n");
        }

    return 0;
}