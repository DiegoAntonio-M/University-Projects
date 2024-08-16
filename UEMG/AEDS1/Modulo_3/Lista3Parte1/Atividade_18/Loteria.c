# include <stdio.h>
# include <math.h>
# include <stdlib.h>
# include <string.h>
# include <time.h>

void sortearNumeros(int *guardarSorteados, int tamanho, int intervaloMax) {
    for (int i = 0; i < tamanho; i++) {
        guardarSorteados[i] = rand() % intervaloMax + 1;
    }    
}

int guardarIguais(int *resultado, int *sorteados, int tamanhoSorteados, int *bilete, int tamanhoBilete) {
    int contagem = 0;
    for (int i = 0; i < tamanhoSorteados; i++) {
        for (int ii = 0; ii < tamanhoBilete; ii++) {
            if (sorteados[i] == bilete[ii]) {
                contagem++;
                resultado = (int *) realloc(resultado, contagem * sizeof(int));
                if (resultado == NULL) {                    
                    return -1;
                }
                resultado[contagem-1] = bilete[ii];
            }
        }
    }
    return contagem;
}

int main() {

    int *numSorteados = NULL;
    int *numBiletes = NULL;
    int *resultado = NULL;

    int quantidadeSorteados = 6;
    numSorteados = (int *) calloc(quantidadeSorteados, sizeof(int));
    if (numSorteados == NULL) {
        printf("Erro ao alocar memória.\n");
        return 1;
    }

    int quantidadeNumBilete = 6;
    numBiletes = (int *) calloc(quantidadeNumBilete, sizeof(int));
    if (numBiletes == NULL) {
        printf("Erro ao alocar memória.\n");
        return 1;
    }

    resultado = (int *) calloc(1, sizeof(int));
    if (resultado == NULL) {
        printf("Erro ao alocar memória.\n");
        return 1;
    }

    srand(time(0));
    time(0);
    sortearNumeros(numBiletes, quantidadeNumBilete, 99);

    fputs("<##> Grando Bilete <##>\n >>>", stdout);

    for (int i = 0; i < quantidadeNumBilete; i++) {
        printf("| %d ", numBiletes[i]);
    }
    printf("|\n");

    // srand(time(0));
    time(0);
    sortearNumeros(numSorteados, quantidadeSorteados, 99);

    fputs("Os numeros sorteados são:\n >>>", stdout);

    for (int i = 0; i < quantidadeSorteados; i++) {
        printf("| %d ", numSorteados[i]);
    }
    printf("|\n");

    int tamanhoResult = guardarIguais(resultado, numSorteados, quantidadeSorteados, numBiletes, quantidadeNumBilete);
    
    fputs("O resultado final eh:\n >>>", stdout);

    if (tamanhoResult != 0) {
        for (int i = 0; i < tamanhoResult; i++) {
            printf("| %d ", resultado[i]);
        }
        printf("|\n");
    } else if (tamanhoResult != -1) {
        fputs(" Não tiveram numeros correspodnetes\n", stdout);
    } else {
        printf("Erro ao alocar memória.\n");
        return 1;
    }

    free(numSorteados);
    free(numBiletes);
    free(resultado);

    return 0;
}