#include <stdio.h>

int main () {

    float salarioBasePorDia = 0;
    float diaTrabalhados = 0;
    float porcentagemDoImposto = 0;
    float salarioFinal = 0;

    salarioBasePorDia = 30.0;
    porcentagemDoImposto = 0.08;

    printf("Digite os dias trabalhados: ");
    scanf("%f", &diaTrabalhados);

    // printf("Digite o salário por dia: R$");
    // scanf("%f", &salarioBasePorDia);

    // printf("Digite em porcentagem o imposto cobrado:");
    // scanf("%f", &porcentagemDoImposto);

    salarioFinal = salarioBasePorDia*(diaTrabalhados*(1 - porcentagemDoImposto));

    printf("O salário final será de: R$%f", salarioFinal);

}