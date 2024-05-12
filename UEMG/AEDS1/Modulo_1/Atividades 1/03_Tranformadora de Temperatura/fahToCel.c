# include <stdio.h>

int main () {

    float tempFahrenheit = 0;
    float tempCelsius = 0;

    printf("Digite a Temperatura em Fahrenheit:");
    scanf("%f", &tempFahrenheit);

    tempCelsius = (5.0*(tempFahrenheit-32.0)/9.0);

    printf("A conversão da Temperatura de Fahrenheit para celsius é: %fºC", tempCelsius);

}