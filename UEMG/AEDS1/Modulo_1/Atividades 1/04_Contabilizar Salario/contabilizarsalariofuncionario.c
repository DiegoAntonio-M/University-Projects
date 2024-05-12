#include <stdio.h>

int main () {

    float salarioBase = 0;
    float Gratificacao = 0;
    float quantidadeDeImposto = 0;
    float salarioFinal = 0;

    printf("Digite o salário base do funcionário: ");
    scanf("%f", &salarioBase);

    quantidadeDeImposto = 0.07;
    Gratificacao = 1.05;

    // printf("Digite em porcentagem a gratificação sobre o salário base do funcionário: ");
    // scanf("%f", &Gratificacao);

    // printf("Digite em porcentagem o imposto a ser descontado so salário base do funcionário: ");
    // scanf("%f", &quantidadeDeImposto);

    salarioFinal = salarioBase*(1 + Gratificacao - quantidadeDeImposto);

    printf("O Salário Final é de: %f", salarioFinal);

}