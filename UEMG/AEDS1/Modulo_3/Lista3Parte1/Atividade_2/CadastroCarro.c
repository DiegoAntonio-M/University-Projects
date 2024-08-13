# include <stdio.h>
# include <math.h>
# include <stdlib.h>
# include <string.h>

#define QUANTCARACTER 40

typedef struct cadastroPessoa {
    char marca[QUANTCARACTER+1];
    int ano;
}cadastroPessoa;

void removerQuerbraLinha(char *frase) {

    int tamanho = strlen(frase);
    if (tamanho > 0 && *(frase+tamanho - 1) == '\n') {
        frase[tamanho - 1] = '\0';
    }
}

void inserirTexto (char *gardarEm) {

    char textTemp[QUANTCARACTER+1] = {};
    fflush(stdin);
    setbuf(stdin,NULL);
    fgets(textTemp, QUANTCARACTER, stdin);

    removerQuerbraLinha(textTemp);

    strcpy(gardarEm, textTemp);
}

int main() {

    int quantidadeDeCarros = 2;
    cadastroPessoa listaDeCarros[quantidadeDeCarros] = {};

    for (int i = 0; i < quantidadeDeCarros; i++) {
        printf("\n============== Carro [%d - %d] ==============\n", i+1, quantidadeDeCarros);
        fputs("Escreva a MARCA do carro: ", stdout);
        inserirTexto(listaDeCarros[i].marca);
        fputs("ANO: ", stdout);
        scanf("%d", &listaDeCarros[i].ano);
    }

    fputs("\n+++++++++++++++++++++++++++++++++++++++++++\n", stdout);
    
    for (int i = 0; i < quantidadeDeCarros; i++) {
        printf("\n=========== #%d Carro Cadastrado ===========\n", i+1);
        printf("Marca: %s\n", listaDeCarros[i].marca);
        printf("Ano: %d\n", listaDeCarros[i].ano);

    }    

    return 0;
}