// Declare uma matriz 3x6;
// Faça o usuário inserir os valores;
// Mostre a soma dos itens das colunas ímpares;
// Mostre a média aritmética da coluna 2 e da coluna 4;
// Substitua a coluna 6, pela soma da coluna 1 e 2;
// Mostre a matriz com as modificações da substituição.

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main () {

    // int tamanhoLinha = 4;
    // int tamanhoColuna = 5;

    int tamanhoLinha = 3;
    int tamanhoColuna = 6;

    int matriz [tamanhoLinha][tamanhoColuna] = {};


    int numeroAuxiliar = 0;
    int contarMovimentacoes = 0;
    int contarCiclos = 0;
    int movimentacoesPorCiclo = 0;

    int tamanhoColunaExibicao[tamanhoLinha][tamanhoColuna] = {};
    int tamanhoColunaColuna[tamanhoColuna] = {};
    int tamanhoCelulaUnitaria = 0;
    int maiorTamanhoColuna = 0;

    int tamanhoMatriz = sizeof(matriz)/sizeof(matriz[0][0]);

    for (int i = 0; i < tamanhoLinha; i++) {
        for (int ii = 0; ii < tamanhoColuna; ii++) {
            printf("(%d/%d) - Digite o valor para a posição %dx%d do vetor: ", ii + 1 + tamanhoColuna*i, tamanhoMatriz, i+1, ii+1);
            scanf("%d", &matriz[i][ii]);
        }
    }

    printf("\nMatriz digitada:\n\n");

    for (int tt = 0; tt < tamanhoColuna; tt++) {
        maiorTamanhoColuna = 0;
        for (int t = 0; t < tamanhoLinha; t++) {
            
            tamanhoCelulaUnitaria = log10(abs(matriz[t][tt]));
            if (tamanhoCelulaUnitaria < 0) {
                tamanhoCelulaUnitaria = 0;
            }            
            if (matriz[t][tt] < 0) {
                tamanhoCelulaUnitaria++;
            }            

            if (tamanhoCelulaUnitaria > maiorTamanhoColuna) {
                maiorTamanhoColuna = tamanhoCelulaUnitaria;                
            }
            tamanhoColunaExibicao[t][tt] = tamanhoCelulaUnitaria;
        }

        tamanhoColunaColuna[tt] = maiorTamanhoColuna;
    }

    for (int i = 0; i < tamanhoLinha; i++) {     
        
        for (int t = 0; t < tamanhoColuna; t++) {
            printf("---");
            for (int tt = 0; tt < (tamanhoColunaColuna[t] + 1); tt++){
                printf("-");
            }
        }
        printf("-\n");

        for (int ii = 0; ii < tamanhoColuna; ii++) {  
                
                printf("|");
                for (int t = 0; t < tamanhoColunaColuna[ii] - tamanhoColunaExibicao[i][ii]; t++) {
                    printf(" ");
                }
                   
                printf(" %d ", matriz[i][ii]);

                if (ii == tamanhoColuna - 1) {
                    printf("|");
                }
                
        }
        printf("\n");
        if (i == tamanhoLinha - 1) {
            for (int t = 0; t < tamanhoColuna; t++) {
                printf("---");
                for (int tt = 0; tt < (tamanhoColunaColuna[t] + 1); tt++){
                    printf("-");
                }
            }
            printf("-\n");  
        }
    }

    double somaColunaImpar = 0;

    for (int i = 0; i < tamanhoLinha; i++) {
        for (int ii  = 0; ii < tamanhoColuna; ii++) {
            if (ii % 2 == 1) {
            somaColunaImpar += matriz[i][ii];
            }
        }
    }

    printf("\nA soma dos elementos das colunas ímpares: %.2lf\n", somaColunaImpar);

    double somaSegundaEQuarta = 0;
    double quantidadeDeSomasSegundaQuarta = 0;

    for (int i = 0; i < 3; i++) {
        somaSegundaEQuarta += matriz[i][1]; // Segunda coluna
        somaSegundaEQuarta += matriz[i][3]; // Quarta coluna
        quantidadeDeSomasSegundaQuarta += 2;
    }

    double mediaSegundaEQuarta = somaSegundaEQuarta / quantidadeDeSomasSegundaQuarta;

    printf("Média aritmética dos elementos da segunda e quarta colunas: %.2lf\n", mediaSegundaEQuarta);

    for (int i = 0; i < tamanhoLinha; i++) {
        matriz[i][5] = matriz[i][0] + matriz[i][1];
    }

    printf("\nMatriz modificada:\n\n");

    for (int tt = 0; tt < tamanhoColuna; tt++) {
        maiorTamanhoColuna = 0;
        for (int t = 0; t < tamanhoLinha; t++) {
            
            tamanhoCelulaUnitaria = log10(abs(matriz[t][tt]));
            if (tamanhoCelulaUnitaria < 0) {
                tamanhoCelulaUnitaria = 0;
            }            
            if (matriz[t][tt] < 0) {
                tamanhoCelulaUnitaria++;
            }            

            if (tamanhoCelulaUnitaria > maiorTamanhoColuna) {
                maiorTamanhoColuna = tamanhoCelulaUnitaria;                
            }
            tamanhoColunaExibicao[t][tt] = tamanhoCelulaUnitaria;
        }

        tamanhoColunaColuna[tt] = maiorTamanhoColuna;
    }

    for (int i = 0; i < tamanhoLinha; i++) {     
        
        for (int t = 0; t < tamanhoColuna; t++) {
            printf("---");
            for (int tt = 0; tt < (tamanhoColunaColuna[t] + 1); tt++){
                printf("-");
            }
        }
        printf("-\n");

        for (int ii = 0; ii < tamanhoColuna; ii++) {  
                
                printf("|");
                for (int t = 0; t < tamanhoColunaColuna[ii] - tamanhoColunaExibicao[i][ii]; t++) {
                    printf(" ");
                }
                   
                printf(" %d ", matriz[i][ii]);

                if (ii == tamanhoColuna - 1) {
                    printf("|");
                }
                
        }
        printf("\n");
        if (i == tamanhoLinha - 1) {
            for (int t = 0; t < tamanhoColuna; t++) {
                printf("---");
                for (int tt = 0; tt < (tamanhoColunaColuna[t] + 1); tt++){
                    printf("-");
                }
            }
            printf("-\n");  
        }
    }

    return 0;

}