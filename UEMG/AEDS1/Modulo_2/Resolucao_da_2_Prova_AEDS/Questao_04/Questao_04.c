// Crie um sudoko 9x9;
// Verifique o sudoko se ele é válido, teste:
// -- As linhas horizontais;
// -- As linhas verticais;
// -- Os quadrantes 3x3.
// Imprima se ele é válido ou não.

# include <stdio.h>
# include <math.h>
# include <stdlib.h>
# include <string.h>

int main() {

    int tableVerificadora[9][2] = {{1}, {2}, {3}, {4}, {5}, {6}, {7}, {8}, {9}};
    int sudoko[9][9] = {
        {5, 3, 4, 6, 7, 8, 9, 1, 2},
        {6, 7, 2, 1, 9, 5, 3, 4, 8},
        {1, 9, 8, 3, 4, 2, 5, 6, 7},
        {8, 5, 9, 7, 6, 1, 4, 2, 3},
        {4, 2, 6, 8, 5, 3, 7, 9, 1},
        {7, 1, 3, 9, 2, 4, 8, 5, 6},
        {9, 6, 1, 5, 3, 7, 2, 8, 4},
        {2, 8, 7, 4, 1, 9, 6, 3, 5},
        {3, 4, 5, 2, 8, 6, 1, 7, 9}
    };

    int valido = 1;

    for (int i = 0; i < 9; i++) {
        for (int ii = 0; ii < 9; ii++) {
            for (int p = 0; p < 9; p++) {
                if (sudoko[i][ii] == tableVerificadora[p][0]) {
                    tableVerificadora[p][1]++;
                }
            }
        }
        for (int l = 0; l < 9; l++) {
            if (tableVerificadora[l][1] != 1) {
                valido = 0;
            }                
            tableVerificadora[l][1] = 0;
        }  
    }
    

    for (int i = 0; i < 9; i++) {
        for (int ii = 0; ii < 9; ii++) {
            for (int p = 0; p < 9; p++) {
                if (sudoko[ii][i] == tableVerificadora[p][0]) {
                    tableVerificadora[p][1]++;
                }
            }
        }
        for (int l = 0; l < 9; l++) {
            if (tableVerificadora[l][1] != 1) {
                valido = 0;
            }                
            tableVerificadora[l][1] = 0;
        } 
    }

    for (int i = 0; i < 3; i++) {
        for (int ii = 0; ii < 3; ii++) {
            for (int k = 0; k < 3; k++) {
                for (int kk = 0; kk < 3; kk++) {
                    for (int p = 0; p < 9; p++) {
                        if (sudoko[i*3+k][ii*3+kk] == tableVerificadora[p][0]) {
                            tableVerificadora[p][1]++;
                        }
                    }   
                }
            }
            for (int l = 0; l < 9; l++) {
                if (tableVerificadora[l][1] != 1) {
                    valido = 0;
                }                
                tableVerificadora[l][1] = 0;
            } 
        }       
    }

    if (valido == 1) {
        fputs("Esse sudoko eh valido!!!", stdout);
    } else {
        fputs("Esse sudoko nao eh valido!!!", stdout);
    }   

    return 0;
}