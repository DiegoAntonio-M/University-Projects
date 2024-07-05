// Peça ao usuário que informe o Peso em Kg;
// Peça ao usuário que informe a Altura em cm;
// Calcule o IMC ---> IMC(peso, altura) = peso / (altura * altura);
// Depois classifique o IMC de acordo com a tabela:
// +-------------+------------------------------+
// |     IMC     |        Classificação         |
// +-------------+------------------------------+
// |    18.5 <   |        Abaixo do Peso        |
// | 18.5 < 25.0 |           Saldável           |
// | 25.0 < 30.0 |       Peso em excesso        |
// | 30.0 < 35.0 |       Obesidade Grau I       |
// | 35.0 < 40.0 |  Obesidade Grau II (Severa)  |
// |   < 40.0    | Obesidade Grau III (Mórbida) |
// +-------------+------------------------------+


# include <stdio.h>

int main() {

    float peso = 0;
    float altura = 0;
    float IMC = 0;

    printf("Digite o peso [Kg]: ");
    scanf("%f", &peso);

    printf("Digite a altura [cm]: ");
    scanf("%f", &altura);

    altura = altura / 100;

    IMC = peso / (altura * altura);

    printf("IMC -> %.2f", IMC);

    if (IMC < 18.5) {
        printf(" - Abaixo do Peso.\n");
    } else if ((18.5 <= IMC)|| (IMC < 25)) {
        printf(" - Saudavel.\n");
    } else if ((25 <= IMC)|| (IMC < 30)) {
        printf(" - Peso em Excesso.\n");
    } else if ((30 <= IMC)|| (IMC < 35)) {
        printf(" - Obesidade Grau I.\n");
    } else if ((35 <= IMC)|| (IMC < 40)) {
        printf(" - Obesidade Grau II (Severa).\n");
    } else if (40 <= IMC) {
        printf(" - Obesidade Grau III (Morbida).\n");
    }

    return 0;
}