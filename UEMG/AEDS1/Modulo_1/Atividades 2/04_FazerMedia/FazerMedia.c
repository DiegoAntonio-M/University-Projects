#include <stdio.h>

int main() {
    
    int numero = 0;
    int soma = 0;
    int contagem = 0;
    float media;

    for(int i = 0; i < 10; i++) {

        printf("Será calculado a média de 10 números positivos: \n\n");
        printf("(%d/10) Digite um número inteiro positivo: ",i + 1);
        scanf("%d", &numero);

        if(numero > 0) {
            soma += numero;
            contagem++;
        }
    }

    printf("\nSomente os números inteiros positivos serão considerados.\n");

    if(contagem > 0) {
        media = (float)soma / contagem;
        printf("\nA média dos números positivos digitados é: %.2f\n\n", media);
    } else {
        printf("Nenhum número positivo foi digitado.\n");
    }

    return 0;
}