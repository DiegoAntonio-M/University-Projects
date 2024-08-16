# include <stdio.h>
# include <math.h>
# include <stdlib.h>
# include <string.h>
# include <time.h>

void limparBuffer() {
    fflush(stdin);
    setbuf(stdin,NULL);
}

int main() {

    double *vetor = NULL;

    int tamanhoVetor = 0;
    int rangSorteio = 100;

    do {
        limparBuffer();
        fputs("Ecolha um tamanho para o vetor [10 <]: ", stdout);
        scanf("%d", &tamanhoVetor);
        
    } while (tamanhoVetor < 10);
    
    vetor = (double *) malloc(tamanhoVetor * sizeof(double));

    if (vetor == NULL) {
        printf("Erro ao alocar memória.\n");
        return 1;
    }

    srand(time(0));
    for (int i = 0; i < tamanhoVetor; i++) {
        vetor[i] = (double) (rand() % (rangSorteio + 1));
    }

    for (int i = 0; i < tamanhoVetor; i++) {
            printf("| %lf ", vetor[i]);
        }
        printf("|\n");

    free(vetor);

    return 0;
}