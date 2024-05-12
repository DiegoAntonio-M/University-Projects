#include <stdio.h>
#include <math.h>

int main () {

    double cateto1 = 0;
    double cateto2 = 0;
    double hipotenusa = 0;


    printf("Digite o comprimento do primeiro cateto: ");
    scanf("%lf", &cateto1);

    printf("Digite o comprimento do segundo cateto: ");
    scanf("%lf", &cateto2);


    hipotenusa = pow((pow(cateto1 , 2) + pow(cateto2, 2)),0.5);
    hipotenusa = sqrt((pow(cateto1 , 2) + pow(cateto2, 2)));


    printf("A hipotenusa do triângulo retângulo é: %.2f\n", hipotenusa);
}