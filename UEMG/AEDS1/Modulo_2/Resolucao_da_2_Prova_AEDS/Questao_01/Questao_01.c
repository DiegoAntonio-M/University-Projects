// Faça uma matriz 5x5, que contenha números interios;
// Ordene que de forma:
// -- As duas primeira linhas contenha os maiores valores em ordem decrecente;
// -- As duas últimas linhas contenhas os menores valores em ordem crescente;
// -- A linha do meio terao os valores que sobrarem;
// Imprima a Matriz.
//
// Exemplo:
// +----+----+----+----+----+
// | 25 | 24 | 23 | 22 | 21 |
// +----+----+----+----+----+
// | 20 | 19 | 18 | 17 | 16 |
// +----+----+----+----+----+
// |    |    |    |    |    |
// +----+----+----+----+----+
// |  1 |  2 |  3 |  4 |  5 |
// +----+----+----+----+----+
// |  6 |  7 |  8 |  9 | 10 |
// +----+----+----+----+----+

# include <stdio.h>
# include <math.h>
# include <stdlib.h>
# include <string.h>

int main() {

    int matriz[5][5] = {{2, 3 ,8 ,4 ,6}, {1, 7, 20, 25, 15}, {10, 13, 17, 23, 5}, {16, 11, 18, 22, 9}, {12, 14, 19, 24, 21}};
    int quantLinha = sizeof(matriz[0])/sizeof(matriz[0][0]);
    int qunantColuna = sizeof(matriz[0][0]) + 1;
    int tamanhoMatriz = quantLinha * qunantColuna;

    int movimentacoesPorCiclo = 0;
    int numeroAuxiliar = 0;
    int contarCiclos = 0;


    do {
        movimentacoesPorCiclo = 0;
        for (int i = 0; i < tamanhoMatriz - (1 + contarCiclos); i++) {

            int posicaoLinha1 = (i)/qunantColuna;
            int posicaoLinha2 = (i+1)/qunantColuna;
            int posicaoColuna1 = (i) % qunantColuna;
            int posicaoColuna2 = (i+1) % qunantColuna;

            if (matriz[posicaoLinha1][posicaoColuna1] < matriz[posicaoLinha2][posicaoColuna2]) {

                numeroAuxiliar = matriz[posicaoLinha1][posicaoColuna1];
                matriz[posicaoLinha1][posicaoColuna1] = matriz[posicaoLinha2][posicaoColuna2];
                matriz[posicaoLinha2][posicaoColuna2] = numeroAuxiliar;
                // contarMovimentacoes++;
                movimentacoesPorCiclo++;
            }
        }
        contarCiclos++;

    } while (movimentacoesPorCiclo != 0);

    movimentacoesPorCiclo = 0;
    numeroAuxiliar = 0;
    contarCiclos = 0;

    do {
        movimentacoesPorCiclo = 0;
        for (int i = quantLinha * 3; i < tamanhoMatriz - (1 + contarCiclos); i++) {

            int posicaoLinha1 = (i)/qunantColuna;
            int posicaoLinha2 = (i+1)/qunantColuna;
            int posicaoColuna1 = (i) % qunantColuna;
            int posicaoColuna2 = (i+1) % qunantColuna;

            if (matriz[posicaoLinha1][posicaoColuna1] > matriz[posicaoLinha2][posicaoColuna2]) {

                numeroAuxiliar = matriz[posicaoLinha1][posicaoColuna1];
                matriz[posicaoLinha1][posicaoColuna1] = matriz[posicaoLinha2][posicaoColuna2];
                matriz[posicaoLinha2][posicaoColuna2] = numeroAuxiliar;
                // contarMovimentacoes++;
                movimentacoesPorCiclo++;
            }
        }
        contarCiclos++;

    } while (movimentacoesPorCiclo != 0);

    for (int i = quantLinha * 2; i < quantLinha * 3; i++) {

            int posicaoLinha1 = (i)/qunantColuna;
            int posicaoLinha2 = (i+1)/qunantColuna;
            int posicaoColuna1 = (i) % qunantColuna;
            int posicaoColuna2 = (i+1) % qunantColuna;

            matriz[posicaoLinha1][posicaoColuna1] = 0;

    }
    
    for (int i = 0; i < quantLinha; i++) {

        for (int ii = 0; ii < qunantColuna; ii++) {
            (matriz[i][ii] != 0) ? printf("| %d ", matriz[i][ii]) : fputs("|   ", stdout);
        }
        fputs("|\n", stdout);
    }   

    return 0;
}