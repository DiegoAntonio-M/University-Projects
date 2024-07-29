# include <stdio.h>
# include <stdlib.h>
# include <string.h>

int main() {

    int tamanhoCampo = 20;
    char nome[tamanhoCampo + 1] = {};
    char sobreNome[tamanhoCampo + 1] = {};
    char nomeCompleto[tamanhoCampo * 2 + 1] = {};
    int tamanhoNomeCompleto = 0;

    fputs("Digite a sua primeira string: ", stdout);
    fgets(nome, tamanhoCampo, stdin);

    fputs("Digite a sua segunda string: ", stdout);
    fgets(sobreNome, tamanhoCampo, stdin);

    for (int i = 0; i < strlen(nome); i++) {
        if (nome[i] == '\n') {
            nome[i] = '\000';
        }        
    }
    
    for (int i = 0; i < strlen(sobreNome); i++) {
        if (sobreNome[i] == '\n') {
            sobreNome[i] = '\000';
        }        
    }

    strcpy(nomeCompleto, nome);
    strcat(nomeCompleto, " ");
    strcat(nomeCompleto, sobreNome);

    tamanhoNomeCompleto = strlen(nomeCompleto);

    printf("\nNome completo: %s\n", nomeCompleto);
    printf("Número de caracteres: %d\n", tamanhoNomeCompleto);
    printf("Primeira letra: %c\n", nomeCompleto[0]);
    printf("Última letra: %c\n\n", nomeCompleto[tamanhoNomeCompleto - 1]);

    return 0;
}