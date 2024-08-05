// Crie uma matriz que contenha duas palavras;
// Teste os caracteres na mesma posição de ambas e retorne as ocorrências dos que sejam iguais na mesma posição;
// Verifique se alguns deles são palíndramos;
// Ordene os caracteres de cada string em ordem alfabética.

# include <stdio.h>
# include <math.h>
# include <stdlib.h>
# include <string.h>

int main() {

    char listaDePalavras[][20] = {"falar", "radar"};
    int quantCaracteres = sizeof(listaDePalavras[0])/sizeof(listaDePalavras[0][0]);
    int quantPalavras = sizeof(listaDePalavras)/sizeof(listaDePalavras[0])/sizeof(listaDePalavras[0][0]);

    int ocorrenciaDeCaracter = 0;

    for (int i = 0; i < quantPalavras; i++) {
        for (int ii = i + 1; ii < quantPalavras; ii++) {
            ocorrenciaDeCaracter = 0;
            if (i != ii) {
                for (int k = 0; k < quantCaracteres; k++) {
                    if ((listaDePalavras[i][k] == listaDePalavras[ii][k])) {
                        if ((listaDePalavras[i][k] != 0 && listaDePalavras[i][k] != 0)) {
                            ocorrenciaDeCaracter++;
                        }
                    }                    
                }
                printf("[%s]:[%s] teve %d letra(s) igual(is)\n", listaDePalavras[i], listaDePalavras[ii], ocorrenciaDeCaracter);
            }
        }        
    }

    fputs("\n", stdout);

    for (int i = 0; i < quantPalavras; i++) {

        int tamanhoPalvra = strlen(listaDePalavras[i]);
        char palavraAuxiliar[tamanhoPalvra] = {};

        for (int ii = 0; ii < tamanhoPalvra; ii++) {
            palavraAuxiliar[tamanhoPalvra - ii - 1] = listaDePalavras[i][ii];
        }
        
        fputs(listaDePalavras[i], stdout);
        fputs(" -> ", stdout);

        if (strcmp(listaDePalavras[i], palavraAuxiliar) == 0) {
            fputs("Eh palindramo!!!\n", stdout);

        } else {
            fputs("Nao eh palindramo!!!\n", stdout);
        }
    }

    fputs("\n", stdout);

    for (int i = 0; i < quantPalavras; i++) {

        printf("[%s] -> ", listaDePalavras[i]);

        int movimentacoesPorCiclo = 0;
        int contarCiclos = 0;
        char letraAux = 0;
        do {
            movimentacoesPorCiclo = 0;        
            for (int ii = 0; ii < strlen(listaDePalavras[i]) - (1 + contarCiclos); ii++) {

                if (listaDePalavras[i][ii] > listaDePalavras[i][ii + 1]) {

                    letraAux = listaDePalavras[i][ii];
                    listaDePalavras[i][ii] = listaDePalavras[i][ii + 1];
                    listaDePalavras[i][ii + 1] = letraAux;
                    movimentacoesPorCiclo++;
                }
            }
            contarCiclos++;

        } while (movimentacoesPorCiclo != 0);

        fputs(listaDePalavras[i], stdout);
        fputs("\n", stdout);

    }
    
    return 0;
}