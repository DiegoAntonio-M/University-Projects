// Compare duas strings;
// Não usar a função "strcmp";
// Imprima o resultado;

# include <stdio.h>
# include <string.h>

int main() {

        int tamanhoFrase = 40;
        int quantidadeString = 2;
        char strings[quantidadeString][tamanhoFrase + 2] = {};
        int resultado[quantidadeString*(quantidadeString - 1)][4] = {};
        
        for (int i = 0; i < quantidadeString; i++) {
            printf("(%d/%d) - ", i + 1, quantidadeString);
            fputs("Digite a string [", stdout);
            printf("%d", i + 1);
            fputs("] -> ", stdout);
            fgets(strings[i], tamanhoFrase, stdin);
        }

        for (int ii = 0; ii < quantidadeString; ii++) {
            for (int i = 0; i < tamanhoFrase; i++) {
                if (strings[ii][i] == '\n') {
                    strings[ii][i] = '\000';
                break;               
                }            
            }
        }        

        for (int i = 0, continuidade = 0; i < quantidadeString; i++) {
            for (int ii = 0; ii < quantidadeString; ii++) {
                if (i != ii) {
                    
                    resultado[continuidade][0] = i;
                    resultado[continuidade][1] = ii;

                    for (int p = 0, definidoIMaior = 0, letrasDiferentes = 0, block = 0; p < tamanhoFrase; p++) {
                        if (strings[i][p] != strings[ii][p]) {
                            (definidoIMaior == 0) ? letrasDiferentes++ : letrasDiferentes--;
                            if ((strings[i][p] > strings[ii][p]) && definidoIMaior != 1 && block == 0) {
                                letrasDiferentes = letrasDiferentes * (-1);
                                definidoIMaior = 1;
                                block = 1;
                            } else if ((strings[i][p] < strings[ii][p]) && definidoIMaior != 1 && block == 0) {
                                block = 1;
                            }                    
                        }

                        resultado[continuidade][2] = letrasDiferentes;

                        if(strings[i][p] == 0 && strings[ii][p] == 0) {
                            break;
                        }
                    }

                    int diferencaTamanho = 0;
                    int tamanhoDaStringi = 0;
                    int tamanhoDaStringii = 0;

                    for (int k = 0; k < tamanhoFrase; k++) {
                        if (strings[i][k] == '\000') {
                            if (strings[i][k - 1] == '\n') {
                                strings[i][k - 1] = '\000';
                                tamanhoDaStringi = k - 1;
                            } else {
                                tamanhoDaStringi = k;
                            } 
                            break;               
                        }            
                    } 
                    for (int k = 0; k < tamanhoFrase; k++) {
                        if (strings[ii][k] == '\000') {
                            if (strings[ii][k - 1] == '\n') {
                                strings[ii][k - 1] = '\000';
                                tamanhoDaStringii = k - 1;
                            } else {
                                tamanhoDaStringii = k;
                            } 
                            break;               
                        }            
                    }

                    diferencaTamanho = tamanhoDaStringii - tamanhoDaStringi;
                    resultado[continuidade][3] = diferencaTamanho;
                    continuidade++;

                }
            }
        }

        fputs("\n", stdout);

        for (int i = 0; i < quantidadeString*(quantidadeString - 1); i++) {
            printf("[%d]>>[%d] : Comp = %d, Tam = %d\n", resultado[i][0] + 1, resultado[i][1] + 1, resultado[i][2],resultado[i][3]);
        }

    return 0;
}