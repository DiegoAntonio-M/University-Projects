// Demostrar os dividores entre 1 e n;
// Sendo "n" receber do usuário;
// Dê destaque nos primos;

#include <stdio.h>

int main () {

    int numero = 0;
    int contar = 0;
    
    printf("Digite um número: ");
    scanf("%d", &numero);

    for (int i = 1; i <= numero; i++) {

        contar = 0;
        
        for (int ii = 1; ii <= i; ii++) {
            
            if (i % ii == 0) {
                
                contar++;
                printf("O número %d é divisível por %d.\n", i, ii);
            }
        }

        if (contar == 2) {
            printf("O número %d é primo!\n", i);
        }
     
    }
    return 0;  
}




