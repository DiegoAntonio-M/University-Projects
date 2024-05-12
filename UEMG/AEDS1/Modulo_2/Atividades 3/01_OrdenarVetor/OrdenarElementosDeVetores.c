# include <stdio.h>


int main() {
    
    int vetor[10] = {};
    int numeroAuxiliar = 0;
    int contarMovimentacoes = 0;
    int contarCiclos = 0;
    int movimentacoesPorCiclo = 0;

    int tamanhoVetor = sizeof(vetor)/sizeof(vetor[0]);

    for (int i = 0; i < tamanhoVetor; i++) {

        printf("(%d/%d) - Digite o valor para a posição %d do vetor: ", i+1, tamanhoVetor, i+1);
        scanf("%d", &vetor[i]);        
    }

    printf("\nEsses são os números inseridos:\n");
    for (int i = 0; i < tamanhoVetor; i++) {
        printf("[%d] ", vetor[i]);
    }
    printf("\n\n");

    do {
        movimentacoesPorCiclo = 0;
        for (int i = 0; i < tamanhoVetor - (1 + contarCiclos); i++) {
            
            if (vetor[i] > vetor[i+1]) {

                numeroAuxiliar = vetor[i];
                vetor[i] = vetor[i+1];
                vetor[i+1] = numeroAuxiliar;
                contarMovimentacoes++;
                movimentacoesPorCiclo++;
            }
        }
        contarCiclos++;

    } while (movimentacoesPorCiclo != 0);
    
    
    printf("\nEsses são os números inseridos de forma organizada:\n");
    for (int i = 0; i < tamanhoVetor; i++) {
        printf("[%d] ", vetor[i]);
    }
    printf("\n\n");
    printf("Foram utilizados %d movimentações para organizar.\n\n", contarMovimentacoes);   
        
    return 0;
}