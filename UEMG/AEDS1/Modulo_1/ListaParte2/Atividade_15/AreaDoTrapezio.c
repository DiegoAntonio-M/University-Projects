# include <stdio.h>

int main () {

    float baseMaior = 0;
    float baseMenor = 0;
    float altura = 0;
    double areaDoTrapezio = 0;

    printf("Calcule a área do trapézio:\n\n");

    do {
        printf("Digite a base maior: ");
        scanf("%f", &baseMaior);

        if (baseMaior <= 0) {
            printf("Digite um numero interio positivo e não nulo.\n");
        }        
    } while (baseMaior <= 0);   
    

    do {
        printf("Digite a base menor: ");
        scanf("%f", &baseMenor);
        if (baseMenor <= 0) {
            printf("Digite um numero interio positivo e não nulo.\n");
        }
        if (baseMenor >= baseMaior) {
            printf("Digite um numero menor que base maior.\n");
        }
    } while ((baseMenor >= baseMaior) || (baseMenor <= 0));

    do {
        printf("Digite a altura: ");
        scanf("%f", &altura);

        if (altura <= 0) {
            printf("Digite um numero interio positivo e não nulo.\n");
        }        
    } while (altura <= 0);   
    
    areaDoTrapezio = ((baseMaior + baseMenor) * altura)/2;

    printf("Área do Trapézio >>> %.4lf", areaDoTrapezio);
}

    
