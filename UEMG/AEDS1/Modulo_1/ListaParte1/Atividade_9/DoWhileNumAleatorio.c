#include <stdio.h>
#include <stdlib.h>

int main () {

    printf("...............................................\n");

    int numero = numero;
    int numeroAleatorio = numeroAleatorio;
    int tentativas = tentativas;
    double lixo12 = lixo12;
    int somaDeLixoAleatorio = somaDeLixoAleatorio + numero + tentativas + numeroAleatorio + lixo12;

    // printf("%d\n", numero);
    // printf("%d\n", numeroAleatorio);
    // printf("%d\n", tentativas);
    // printf("%d\n", somaDeLixoAleatorio);

    numero = 0;
    numeroAleatorio = 0;
    tentativas = 0;
    lixo12 = 0;

    do {
     
        printf("\nTente adivinhar o número: ");
        scanf("%d", &numero);

        numeroAleatorio = ((rand()*somaDeLixoAleatorio) + rand()) % 999;
        tentativas++;

        if (numeroAleatorio <= 0) {
            numeroAleatorio = (numeroAleatorio * (-1)) + 1;
        }        
        
        printf("O número era %d ", numeroAleatorio);
        printf("- %d tentativa(s).", tentativas);

    } while ((numero != numeroAleatorio) && (tentativas < 100000));

    if (tentativas < 100000) {
        printf("Você encontrou o numero!!! Depois de %d tentativa(s)", tentativas);
    } else {
        printf("Tente novamente."); //Tratativa do bug quando é respondido "." no scanf.
    }

    numero = 99791;
    numeroAleatorio = -7532;
    tentativas = 1;
    lixo12 = 97516;
    

    return 0;    
}