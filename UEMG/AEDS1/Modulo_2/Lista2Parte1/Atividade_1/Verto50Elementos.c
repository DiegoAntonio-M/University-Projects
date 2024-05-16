// Criar um vetor de 50 elementos;
// Para a  posição i será: f(i) = i + i^2;
// Registre f(i) em cada posição (Usando laço);
// Imprima as posições ímpares do vetor e seus valores (Usando laço);
// Imprima todas as posições e seus valores (Usando laço);

# include <stdio.h>
# include <math.h>

int main() {

    int vetor[50] = {0};
    int tamanhoVetor = sizeof(vetor)/sizeof(vetor[0]);

    for (int i = 0; i < tamanhoVetor; i++) {
        vetor[i] = i + pow(i,2);
    }

    printf("\nO vetores sendo as posições ímpares:\n\n");
    
    for (int i = 0; i < tamanhoVetor; i++) {
        if (i % 2 == 1) {
            printf("vetor[%d] = %d\n", i, vetor[i]);
        }
    }

    printf("\nO vetor contem os seguintes números:\n");

    for (int i = 0; i < tamanhoVetor; i++){
        printf("vetor[%d] = %d\n", i, vetor[i]);
    }

    return 0;
}