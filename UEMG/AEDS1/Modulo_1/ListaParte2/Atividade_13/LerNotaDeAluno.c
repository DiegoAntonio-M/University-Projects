# include <stdio.h>

int main () {

    float nota1 = 0;
    float nota2 = 0;
    double media = 0;

    printf("Digite as notas para calcular a média:\n\n");

    printf("Nota 1: ");
    scanf("%f", &nota1);

    printf("Nota 2: ");
    scanf("%f", &nota2);

    if (((nota1 < 0) || (nota2 < 0)) || ((nota1 > 10) || nota2 > 10) ) {
        printf("Esse número não é válido.\n");
    } else {
        media = (nota1 + nota2) / 2;
        printf("Média >>> %.2lf", media);
    }
    
}