# include <stdio.h>

int main () {

    int opcao = 0;
    double velocidade = 0.0;

    while (1 == 1) {
        printf("Menu:\n");
        printf("1 - Converter de km/h para m/s\n");
        printf("2 - Converter de m/s para km/h\n");
        printf("3 - Finalizar programa\n");
        printf("Digite a opção desejada: ");
        scanf("%d", &opcao);

        if (opcao == 3) {
            break;
        }

        printf("Digite a velocidade: ");
        scanf("%lf", &velocidade);

        if (opcao == 1) {
            printf("A velocidade em m/s é: %.2lf\n", velocidade / 3.6);
        } else if (opcao == 2) {
            printf("A velocidade em km/h é: %.2lf\n", velocidade * 3.6);
        } else {
            printf("Opção inválida.\n");
        }
    }

    printf("Programa finalizado.\n");

    return 0;
}
