# include <stdio.h>
# include <math.h>

int main () {

    double a = 0;
    double b = 0;
    double c = 0;
    double delta = 0;
    double x1 = 0;
    double x2 = 0;

    printf("Escreva a equação do segundo grau sendo -> (ax^2 + bx + c = 0):\n");

    do {
        printf("Termo a: ");
        scanf("%lf", &a);

        if (a == 0) {
            printf("\nTermo a sendo 0 não se caracterixa como uma equação do segundo grau, digite novamente.\n");
        }
        
    } while (a == 0);
    
    printf("Termo b: ");
    scanf("%lf", &b);

    printf("Termo c: ");
    scanf("%lf", &c);

    delta = (b*b) - 4 * a * c;

    // printf("%lf", delta);

    if (delta < 0) {
        printf("Não possui raiz real.\n");
    } else if (delta == 0) {
        printf("Possui apenas uma raiz.\n");
        x1 = (-b)/(2 * a);
        printf(">> x1 = %lf\n", x1);
    } else if (delta > 0) {
        printf("Possui duas raizes reais.\n");

        x1 = ((-b) - sqrt(delta))/(2 * a);
        printf(">> x1 = %lf\n", x1);

        x2 = ((-b) + sqrt(delta))/(2 * a);
        printf(">> x2 = %lf\n", x2);
    }
      
    
}