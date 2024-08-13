# include <stdio.h>
# include <math.h>
# include <stdlib.h>
# include <string.h>

void receba (int *vetor, int quantElementos) {
    printf("Digite %d numeros: ", quantElementos);
    for (int i = 0; i < quantElementos; i++) {
        scanf("%d", &vetor[i]);
    }
}

void imprima (int *vetor, int quantElementos) {
    for (int i = 0; i < quantElementos; i++) {
        printf("| %d ", vetor[i]);
    }
    fputs("|\n", stdout);
}

void imprimaReverso (int *vetor, int quantElementos) {
    for (int i = 0; i < quantElementos; i++) {
        printf("| %d ", vetor[quantElementos - i - 1]);
    }
    fputs("|\n", stdout);
}

int main() {

    int quantidadeElementos = 5;
    int vetorV[quantidadeElementos] = {};

    receba(vetorV, quantidadeElementos);
    imprima(vetorV, quantidadeElementos);
    imprimaReverso(vetorV, quantidadeElementos);

    return 0;
}