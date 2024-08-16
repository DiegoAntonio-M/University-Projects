# include <stdio.h>
# include <math.h>
# include <stdlib.h>
# include <string.h>

void limparBuffer() {
    fflush(stdin);
    setbuf(stdin, NULL);
}

int main() {

    int **p = NULL;
    int quantLinha = 0;
    int quantColuna = 0;

    limparBuffer();
    fputs("Escolha a quantidade de Linha(s) >> ", stdout);
    scanf("%d", &quantLinha);

    limparBuffer();
    fputs("Escolha a quantidade de Coluna(s) >> ", stdout);
    scanf("%d", &quantColuna);

    p = (int **) malloc(quantLinha * sizeof(int));

    for (int i = 0; i < quantLinha; i++) {
        p[i] = (int *) malloc(quantColuna * sizeof(int));
        for (int ii = 0; ii < quantColuna; ii++) {
            printf("[%d - %d]", i*quantColuna + ii + 1, quantColuna*quantLinha);
            fputs("Insira um inteiro >>> ", stdout);
            limparBuffer();
            scanf("%d", &p[i][ii]);
        }
    }
    fputs("\n", stdout);

    for (int i = 0; i < quantLinha; i++) {
        for (int ii = 0; ii < quantColuna; ii++) {
            printf("| %d ", p[i][ii]);
        }
        printf("|\n");        
    }
    
    return 0;
}