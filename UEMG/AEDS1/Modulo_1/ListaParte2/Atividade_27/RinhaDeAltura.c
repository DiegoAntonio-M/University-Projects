# include <stdio.h>

int main () {

    double alturaChico = 1.50;
    double alturaZe = 1.10;
    double crescimentoAnualChico = 0.02; // crescimento anual de Chico
    double crescimentoAnualZe = 0.03; // crescimento anual de Zé
    int anos = 0;

    while (alturaZe <= alturaChico) {
        alturaChico += crescimentoAnualChico;
        alturaZe += crescimentoAnualZe;
        anos++;
    }

    printf("Serão necessários %d anos para que Zé seja maior que Chico.\n", anos);

    return 0;
}
