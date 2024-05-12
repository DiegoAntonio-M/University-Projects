# include <stdio.h>

int main () {

    double nota = 0;
    double soma = 0;
    int contador = 0;
    double media = 0;

    printf("Digite as notas uma por uma (entre 10 e 20). Para terminar, digite uma nota inválida.\n");

    while (1 == 1) {
        printf("Digite uma nota: ");
        scanf("%lf", &nota);

        if (nota < 10 || nota > 20) {
            break;
        }

        soma += nota;
        contador++;
    }

    if (contador > 0) {
        media = soma / contador;
        printf("A média aritmética das notas é: %.2lf\n", media);
    } else {
        printf("Nenhuma nota válida foi inserida.\n");
    }

    return 0;
}