# include <stdio.h>
# include <math.h>
# include <stdlib.h>

int main() {

    int tamanhoMatriz1Quadrada = 5;
    int tamanhoLinha = tamanhoMatriz1Quadrada;
    int tamanhoColuna = tamanhoMatriz1Quadrada;
    int quantidadeElemtosMatriz1 = tamanhoLinha*tamanhoColuna;

    int matriz1 [tamanhoLinha][tamanhoColuna] = {};

    int tamanhoColunaExibicao[tamanhoLinha][tamanhoColuna] = {};
    int tamanhoColunaColuna[tamanhoColuna] = {};
    int tamanhoCelulaUnitaria = 0;
    int maiorTamanhoColuna = 0;


    for (int i = 0; i < tamanhoLinha; i++) {
        for (int ii = 0; ii < tamanhoColuna; ii++) {
            printf("(%d/%d) - Digite o valor para a posição %dx%d do vetor: ", ii + 1 + tamanhoColuna*i, quantidadeElemtosMatriz1, i+1, ii+1);
            scanf("%d", &matriz1[i][ii]);
        }
    }

    printf("\nMatriz digitada:\n\n");

    for (int tt = 0; tt < tamanhoColuna; tt++) {
        maiorTamanhoColuna = 0;
        for (int t = 0; t < tamanhoLinha; t++) {
            
            tamanhoCelulaUnitaria = log10(abs(matriz1[t][tt]));
            if (tamanhoCelulaUnitaria < 0) {
                tamanhoCelulaUnitaria = 0;
            }            
            if (matriz1[t][tt] < 0) {
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
                   
                printf(" %d ", matriz1[i][ii]);

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

    printf("\nProcurar item na matriz digitada:\n\n"); 

    int procurarValor = 0;
    int valorEncontrado = 0;

    printf("Digite o valor X: ");
    scanf("%d", &procurarValor);

    for (int z = 0; z < tamanhoLinha; z++) {
        for (int y = 0; y < tamanhoColuna; y++) {
            if (matriz1[z][y] == procurarValor) {
                printf("\nFoi encontrado um valor na posição %dx%d\n\n", z + 1, y +1);
                valorEncontrado++;


                for (int tt = 0; tt < tamanhoColuna; tt++) {
                    maiorTamanhoColuna = 0;
                    for (int t = 0; t < tamanhoLinha; t++) {
                        
                        tamanhoCelulaUnitaria = log10(abs(matriz1[t][tt]));
                        if (tamanhoCelulaUnitaria < 0) {
                            tamanhoCelulaUnitaria = 0;
                        }            
                        if (matriz1[t][tt] < 0) {
                            tamanhoCelulaUnitaria++;
                        }            

                        if (tamanhoCelulaUnitaria > maiorTamanhoColuna) {
                            maiorTamanhoColuna = tamanhoCelulaUnitaria;                
                        }
                        tamanhoColunaExibicao[t][tt] = tamanhoCelulaUnitaria;
                    }

                    tamanhoColunaColuna[tt] = maiorTamanhoColuna;
                }
                
                int ateChegar = 0;
                for (int i = 0; i < tamanhoLinha; i++) {  
                    
                    for (int t = 0; t < tamanhoColuna && i == 0; t++) {
                        if (t == y) {
                            printf("  V");
                        } else {
                            printf("   ");
                        }
                        
                        for (int tt = 0; tt < (tamanhoColunaColuna[t] + 1); tt++){
                            printf(" ");
                        }
                    }
                    if (i == 0)
                    {
                        printf(" \n");
                    }

                    for (int t = 0; t < tamanhoColuna; t++) {
                        if (t == y && i <= z) {
                            printf("--V");
                        } else {
                            printf("---");
                        }
                        
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
                            
                            printf(" %d ", matriz1[i][ii]);

                            if (ii == tamanhoColuna - 1) {
                                printf("|");
                            }

                    }
                        if (z == i) {
                            printf("<<<--");
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
            }
        }
        
    }

    if (valorEncontrado == 0 ) {
        printf("Não foi encontrado nenhum valor correspondete!!!");
    }

    printf("\n\n");

    int tamanhoMatriz2Quadrada = 10;
    tamanhoLinha = tamanhoMatriz2Quadrada;
    tamanhoColuna = tamanhoMatriz2Quadrada;
    int quantidadeElemtosMatriz2 = tamanhoLinha*tamanhoColuna;

    int matriz2 [tamanhoLinha][tamanhoColuna] = {};

    int tamanhoColunaExibicao2[tamanhoLinha][tamanhoColuna] = {};
    int tamanhoColunaColuna2[tamanhoColuna] = {};
    tamanhoCelulaUnitaria = 0;
    maiorTamanhoColuna = 0;

    for (int i = 0; i < tamanhoLinha; i++) {
        for (int ii = 0; ii < tamanhoColuna; ii++) {
            if (i < ii) {
                matriz2[i][ii] = 2*i + 7*ii - 2;
            } else if (i == ii) {
                matriz2[i][ii] = 3*pow(i,2) - 1;
            } else if (i > ii) {
                matriz2[i][ii] = 4*pow(i,3) - 5*pow(ii,2) + 1;
            }
            
        }
    }

    printf("\nMatriz digitada:\n\n");

    for (int tt = 0; tt < tamanhoColuna; tt++) {
        maiorTamanhoColuna = 0;
        for (int t = 0; t < tamanhoLinha; t++) {
            
            tamanhoCelulaUnitaria = log10(abs(matriz2[t][tt]));
            if (tamanhoCelulaUnitaria < 0) {
                tamanhoCelulaUnitaria = 0;
            }            
            if (matriz2[t][tt] < 0) {
                tamanhoCelulaUnitaria++;
            }            

            if (tamanhoCelulaUnitaria > maiorTamanhoColuna) {
                maiorTamanhoColuna = tamanhoCelulaUnitaria;                
            }
            tamanhoColunaExibicao2[t][tt] = tamanhoCelulaUnitaria;
        }

        tamanhoColunaColuna2[tt] = maiorTamanhoColuna;
    }

    for (int i = 0; i < tamanhoLinha; i++) {     
        
        for (int t = 0; t < tamanhoColuna; t++) {
            printf("---");
            for (int tt = 0; tt < (tamanhoColunaColuna2[t] + 1); tt++){
                printf("-");
            }
        }
        printf("-\n");

        for (int ii = 0; ii < tamanhoColuna; ii++) {  
                
                printf("|");
                for (int t = 0; t < tamanhoColunaColuna2[ii] - tamanhoColunaExibicao2[i][ii]; t++) {
                    printf(" ");
                }
                   
                printf(" %d ", matriz2[i][ii]);

                if (ii == tamanhoColuna - 1) {
                    printf("|");
                }
                
        }
        printf("\n");
        if (i == tamanhoLinha - 1) {
            for (int t = 0; t < tamanhoColuna; t++) {
                printf("---");
                for (int tt = 0; tt < (tamanhoColunaColuna2[t] + 1); tt++){
                    printf("-");
                }
            }
            printf("-\n");  
        }
    }

    return 0;
}