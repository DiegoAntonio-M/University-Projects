# include <stdio.h>

int main () {

    int valorFinal = 2000000;
    int contar = 0;
    float soma = 0;

    for (int i = 2; i <= valorFinal; i++) {

        // printf("%d \n", i);

        contar = 0;

        for (int ii = 1; ii <= i; ii++) {
         
            if (i % ii == 0) {
                contar ++;
            }
        }

        if (contar == 2) {
            soma += i;
            printf("%d - ", i);
            printf("%.0f \n", soma);
        }
        
    }   
}