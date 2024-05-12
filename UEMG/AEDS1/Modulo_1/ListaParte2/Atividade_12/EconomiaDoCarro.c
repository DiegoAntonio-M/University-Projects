# include <stdio.h>

int main () {

    double kilometragemPercorrida = 0;
    double litrosGastos = 0;

    double eficiencia = 0;

    printf("Digite a kilometragem percorrida: ");
    scanf("%lf", &kilometragemPercorrida);
    printf("Litros Gastos: ");
    scanf("%lf", &litrosGastos);

    eficiencia = kilometragemPercorrida / litrosGastos;

    printf("A eficiencia é de: %.1lf por litro ", eficiencia);

    if (eficiencia < 8) {
        printf("- Venda o Carro!");
    } else if ((8 <= eficiencia) && (eficiencia < 14)) {
        printf("- Econômico!");
    } else if (14 <= eficiencia) {
        printf("- Super Econômico!");
    }
}