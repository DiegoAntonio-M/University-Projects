// Declare uma matriz quadrada 5x5;
// Faça uma matriz identidade, sendo a diagonal principal com os valores 1 e os demais 0.

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main() {

    int tamanhoMatrizQuadrada = 5;
    int matriz[tamanhoMatrizQuadrada][tamanhoMatrizQuadrada];

    int tamanhoColunaExibicao[tamanhoMatrizQuadrada][tamanhoMatrizQuadrada] = {};
    int tamanhoColunaColuna[tamanhoMatrizQuadrada] = {};
    int tamanhoCelulaUnitaria = 0;
    int maiorTamanhoColuna = 0;

    for (int i = 0; i < tamanhoMatrizQuadrada; i++) {
        for (int ii = 0; ii < tamanhoMatrizQuadrada; ii++) {
            if (i == ii) {
                matriz[i][ii] = 1;
            } else {
                matriz[i][ii] = 0;
            }            
        }        
    }

    printf("\nMatriz Identidade:\n\n");

    for (int tt = 0; tt < tamanhoMatrizQuadrada; tt++) {
        maiorTamanhoColuna = 0;
        for (int t = 0; t < tamanhoMatrizQuadrada; t++) {
            
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

    for (int i = 0; i < tamanhoMatrizQuadrada; i++) {     
        
        for (int t = 0; t < tamanhoMatrizQuadrada; t++) {
            printf("---");
            for (int tt = 0; tt < (tamanhoColunaColuna[t] + 1); tt++){
                printf("-");
            }
        }
        printf("-\n");

        for (int ii = 0; ii < tamanhoMatrizQuadrada; ii++) {  
                
                printf("|");
                for (int t = 0; t < tamanhoColunaColuna[ii] - tamanhoColunaExibicao[i][ii]; t++) {
                    printf(" ");
                }
                   
                printf(" %d ", matriz[i][ii]);

                if (ii == tamanhoMatrizQuadrada - 1) {
                    printf("|");
                }
                
        }
        printf("\n");
        if (i == tamanhoMatrizQuadrada - 1) {
            for (int t = 0; t < tamanhoMatrizQuadrada; t++) {
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