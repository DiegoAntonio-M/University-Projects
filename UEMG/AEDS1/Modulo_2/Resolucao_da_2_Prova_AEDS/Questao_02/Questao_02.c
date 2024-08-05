// Faça uma matriz que contenha 5 strings;
// Imprima em ordem Alfabética;

# include <stdio.h>
# include <math.h>
# include <stdlib.h>
# include <string.h>

int main() {

    char litaDePalavras[][20] = {"Casa", "Terra", "Caminhao", "Teto", "Ameixa"};
    int quantPalavra = sizeof(litaDePalavras)/sizeof(litaDePalavras[0])/sizeof(litaDePalavras[0][0]);
    int tamanhoPalvra = sizeof(litaDePalavras[0]);

    char palavraAux[tamanhoPalvra] = {};

    int movimentacoesPorCiclo = 0;
    do {
        movimentacoesPorCiclo = 0;
        for (int i = 0; i < quantPalavra - 1; i++) {

            if (strcmp(litaDePalavras[i], litaDePalavras[i + 1]) > 0) {

                strcpy(palavraAux, litaDePalavras[i]);
                strcpy(litaDePalavras[i], litaDePalavras[i+1]);
                strcpy(litaDePalavras[i+1], palavraAux);
                movimentacoesPorCiclo++;

            }
            
        }
    } while (movimentacoesPorCiclo != 0);

    for (int i = 0; i < quantPalavra; i++) {
        fputs("| ", stdout);
        fputs(litaDePalavras[i], stdout);
        (i+1 < quantPalavra) ? fputs(" | < ", stdout) : fputs(" |\n", stdout);
    }
    
    

    return 0;
}