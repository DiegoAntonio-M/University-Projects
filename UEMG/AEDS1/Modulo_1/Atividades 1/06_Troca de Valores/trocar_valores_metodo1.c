# include <stdio.h>

int main () {

    float valueA = 0;
    float valueB = 0;
    float valueCache = 0;

    printf("Digite o valor A: ");
    scanf("%f", &valueA);

    printf("Digite o valor B: ");
    scanf("%f", &valueB);

    valueCache = valueA;

    valueA = valueB;

    valueB = valueCache;

    printf("O valor de A é: %f e o valor de B é: %f", valueA, valueB);

}