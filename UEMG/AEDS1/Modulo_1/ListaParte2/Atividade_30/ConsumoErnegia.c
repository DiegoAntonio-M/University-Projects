# include <stdio.h>

int main () {

    int numHabitantes = 0;
    double valorKwh = 0.0;
    double consumo = 0.0;
    int codigo = 0;
    double totalConsumo = 0.0;
    double maiorConsumo = 0.0;
    double menorConsumo = 0.0;
    double consumoResidencial = 0.0;
    double consumoComercial = 0.0;
    double consumoIndustrial = 0.0;

    printf("Digite o número de habitantes: ");
    scanf("%d", &numHabitantes);

    printf("Digite o valor do kwh: ");
    scanf("%lf", &valorKwh);
    
    printf("1 - Residencial;\n");
    printf("2 - Comercial;\n");
    printf("3 - Industrial.\n");

    for (int i = 0; i < numHabitantes; i++) {
        printf("Digite o consumo do mês e o código do consumidor (consumo codigo): ");
        scanf("%lf %d", &consumo, &codigo);

        totalConsumo += consumo;
        if (i == 0) {
            maiorConsumo = consumo;
            menorConsumo = consumo;
        } else {
            if (consumo > maiorConsumo) {
                maiorConsumo = consumo;
            }
            if (consumo < menorConsumo) {
                menorConsumo = consumo;
            }
        }

        switch (codigo) {
            case 1:
                consumoResidencial += consumo;
                break;
            case 2:
                consumoComercial += consumo;
                break;
            case 3:
                consumoIndustrial += consumo;
                break;
        }
    }

    printf("Maior consumo: %.2lf\n", maiorConsumo);
    printf("Menor consumo: %.2lf\n", menorConsumo);
    printf("Média de consumo: %.2lf\n", totalConsumo / numHabitantes);
    printf("Total de consumo residencial: %.2lf\n", consumoResidencial);
    printf("Total de consumo comercial: %.2lf\n", consumoComercial);
    printf("Total de consumo industrial: %.2lf\n", consumoIndustrial);

    return 0;
}
