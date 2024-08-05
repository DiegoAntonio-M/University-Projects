#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main () {

    // int tamanhoLinha = 4;
    // int tamanhoColuna = 5;

    int tamanhoLinha = 0;
    int tamanhoColuna = 0;
    do {
        tamanhoLinha = 0;
        tamanhoColuna = 0;
        printf("\nDigite o tamnho da matriz (LINHAxCOLUNA): ");          
        scanf("%dx%d", &tamanhoLinha, &tamanhoColuna);
    } while (tamanhoLinha < 1 || tamanhoColuna < 1); 

    printf("\n");   

    int matriz [tamanhoLinha][tamanhoColuna] = {};
    // int matriz [4][5] = {{-10, 5, 8, -798, 6}, {5, 4, 3, -20, 1}, {1, 9, 8184, 7, 6}, {5, 7, 3, 2, 1}};
    // int matriz [4][5] = {{1, 2, 3, 4, 5}, {6, 7, 8, 9, 10}, {9, 8, -7, 500000, 5}, {4, 2, 1, 3, 0}};

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

    do {
        movimentacoesPorCiclo = 0;
        for (int i = 0; i < tamanhoMatriz - (1 + contarCiclos); i++) {

            int posicaoLinha1 = (i)/tamanhoColuna;
            int posicaoLinha2 = (i+1)/tamanhoColuna;
            int posicaoColuna1 = (i) % tamanhoColuna;
            int posicaoColuna2 = (i+1) % tamanhoColuna;

            if (matriz[posicaoLinha1][posicaoColuna1] > matriz[posicaoLinha2][posicaoColuna2]) {

                numeroAuxiliar = matriz[posicaoLinha1][posicaoColuna1];
                matriz[posicaoLinha1][posicaoColuna1] = matriz[posicaoLinha2][posicaoColuna2];
                matriz[posicaoLinha2][posicaoColuna2] = numeroAuxiliar;
                contarMovimentacoes++;
                movimentacoesPorCiclo++;
            }
        }
        contarCiclos++;

    } while (movimentacoesPorCiclo != 0);

    printf("\nMatriz organizada:\n\n");

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
    printf("\n\n");
    printf("Foram realizadas %d movimetnações.\n\n", contarMovimentacoes);

    int c;
    while ((c = getchar()) != '\n' && c != EOF) { }

    getchar();     

    return 0;
}