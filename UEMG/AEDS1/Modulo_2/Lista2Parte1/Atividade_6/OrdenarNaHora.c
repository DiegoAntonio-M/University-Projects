// Fazer uma listagem de 10 valores;
// Deverão ser inseridas pelo usuário;
// E ao mesmo tempo que inserido deverá organizar a lista em ordem crescente;
// Mostre os itens dos vetores em ordem.

# include <stdio.h>

int main() {

    int tamanhoVetor = 10;
    int vetor[tamanhoVetor] = {};
    int numeroAuxiliar = 0;
    int contarMovimentacoes = 0;
    int contarCiclos = 0;
    int movimentacoesPorCiclo = 0;

    for (int ii = 0; ii < tamanhoVetor; ii++) {

        printf("(%d/%d) - Digite um valor para organizar: ", ii+1, tamanhoVetor);
        scanf("%d", &vetor[ii]);
        contarCiclos = 0;

            do {
                movimentacoesPorCiclo = 0;
                // for (int i = 0; (i < (tamanhoVetor - (1 + contarCiclos + (tamanhoVetor - ii - 1)))); i++) {
                for (int i = 0; (i < (ii - contarCiclos)); i++) {
                    
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

        printf("\nEsses são os números inseridos:\n");
        for (int i = 0; i < (ii + 1) ; i++) {
            printf("[%d] ", vetor[i]);
        }
        printf("\n\n");

    }

    return 0;
}