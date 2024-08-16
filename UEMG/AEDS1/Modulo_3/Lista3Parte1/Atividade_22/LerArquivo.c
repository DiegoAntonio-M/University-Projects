# include <stdio.h>
# include <math.h>
# include <stdlib.h>
# include <string.h>

int main() {

    FILE *arquivo = NULL;

    arquivo = fopen("Modulo_3\\Lista3Parte1\\Atividade_21\\CadastroNotas.txt","r");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    int contar = 0;
    char c = 0;
    do {
        c = fgetc(arquivo);
        switch (c)
        {
        case '\n':
            contar++;
            break;

        case ' ':
            contar++;
            break;        
        default:
            break;
        }        

    } while (c != EOF);

    printf("Esse documento possui %d palavras", contar);

    return 0;
}