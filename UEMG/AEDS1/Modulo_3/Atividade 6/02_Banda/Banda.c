# include <stdio.h>
# include <math.h>
# include <stdlib.h>
# include <string.h>

typedef struct banda {
    char name[40];
    char generoMusical[40];
    int numeroIntegrantes;
    int ranking;
}banda;

void removerQuerbraLinha(char *frase) {

    int tamanho = strlen(frase);
    if (tamanho > 0 && *(frase+tamanho - 1) == '\n') {
        frase[tamanho - 1] = '\0';
    }
}

void inserirTexto (char *gardarEm) {

    char textTemp[40] = {};
    fflush(stdin);
    setbuf(stdin,NULL);
    fgets(textTemp, 40, stdin);

    removerQuerbraLinha(textTemp);

    strcpy(gardarEm, textTemp);
}

int main() {

    int quantidadeDeBandas = 5;
    banda listaDeBandas[quantidadeDeBandas] = {};
    fputs("========== Insira as Bandas ==========\n\n", stdout);
    for (int i = 0; i < quantidadeDeBandas; i++) {
        printf("========== [%d - %d] ==========\n", i, quantidadeDeBandas);
        fputs("Escreva o nome da banda: ", stdout);
        inserirTexto(listaDeBandas[i].name);
        fputs("Escreva o genero musical da banda: ", stdout);
        inserirTexto(listaDeBandas[i].generoMusical);
        fputs("Quantos integrantes tem a banda: ", stdout);
        scanf("%d", &listaDeBandas[i].numeroIntegrantes);
        fputs("Ranking a banda: ", stdout);
        scanf("%d", &listaDeBandas[i].ranking);
    }

    banda bandaAux;

    int movimentacoesPorCiclo = 0;
    do {
        movimentacoesPorCiclo = 0;
        for (int i = 0; i < quantidadeDeBandas - 1; i++) {

            if (listaDeBandas[i].ranking > listaDeBandas[i + 1].ranking) {

                bandaAux = listaDeBandas[i];
                listaDeBandas[i] = listaDeBandas[i + 1];
                listaDeBandas[i + 1] = bandaAux;
                movimentacoesPorCiclo++;
            }
            
        }
    } while (movimentacoesPorCiclo != 0);
    

    fputs("\n\n========== Ordem de Ranking ==========", stdout);
    for (int i = 0; i < quantidadeDeBandas; i++) {
        printf("\n============ Posição: #%d ============\n", listaDeBandas[i].ranking);
        printf("Nome da Banda: %s\n", listaDeBandas[i].name);
        printf("Genero Musical: %s\n", listaDeBandas[i].generoMusical);
        printf("Quantidade de Integrantes: %d\n", listaDeBandas[i].numeroIntegrantes);        
    }  
    

    return 0;
}