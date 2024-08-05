# include <stdio.h>
# include <math.h>
# include <stdlib.h>
# include <string.h>

int main() {

    int tamanhoLinha = 5;
    int tamanhoColuna = 4;
    int tamanhoProfundidade = 3;

    int matriz[tamanhoProfundidade][tamanhoLinha][tamanhoColuna] = {};

    int tamanhoFace = tamanhoLinha * tamanhoColuna;
    int tamanhoMatriz = tamanhoFace * tamanhoProfundidade;

    int numeroAuxiliar = 0;
    int contarMovimentacoes = 0;
    int movimentacoesPorCiclo = 0;
    int contarCiclos = 0;

    for (int iii = 0; iii < tamanhoProfundidade; iii++) {
        for (int i = 0; i < tamanhoLinha; i++) {
            for (int ii = 0; ii < tamanhoColuna; ii++) {
                printf("(%d/%d) - Digite o valor para a posição %dx%dx%d do vetor: ", ii + 1 + tamanhoColuna*i + tamanhoFace * iii, tamanhoMatriz, iii+1,i+1, ii+1);
                scanf("%d", &matriz[iii][i][ii]);
            }
        }
    }


    do {

        movimentacoesPorCiclo = 0;

        for (int i = 0; i < tamanhoMatriz - (1 + contarCiclos); i++) {

        int posicaoLinha1 = ((i)/tamanhoColuna) % tamanhoLinha;
        int posicaoLinha2 = ((i+1)/tamanhoColuna) % tamanhoLinha;
        int posicaoColuna1 = (i) % tamanhoColuna;
        int posicaoColuna2 = (i+1) % tamanhoColuna;
        int posicaoProfundidade1 = (i)/(tamanhoFace);
        int posicaoProfundidade2 = (i+1)/(tamanhoFace);

            if (matriz[posicaoProfundidade1][posicaoLinha1][posicaoColuna1] > matriz[posicaoProfundidade2][posicaoLinha2][posicaoColuna2]) {

                numeroAuxiliar = matriz[posicaoProfundidade1][posicaoLinha1][posicaoColuna1];
                matriz[posicaoProfundidade1][posicaoLinha1][posicaoColuna1] = matriz[posicaoProfundidade2][posicaoLinha2][posicaoColuna2];
                matriz[posicaoProfundidade2][posicaoLinha2][posicaoColuna2] = numeroAuxiliar;
                contarMovimentacoes++;
                movimentacoesPorCiclo++;
            }
        }
        contarCiclos++;

        
    } while (movimentacoesPorCiclo != 0);
    

    for (int iii = 0; iii < tamanhoProfundidade; iii++) {
        for (int i = 0; i < tamanhoLinha; i++) {
            for (int ii = 0; ii < tamanhoColuna; ii++) {
                printf("| %d ", matriz[iii][i][ii]);
            }
            printf("|\n");
        }
        printf("\n =<=/=/=>= \n\n");
    }

    return 0;
}