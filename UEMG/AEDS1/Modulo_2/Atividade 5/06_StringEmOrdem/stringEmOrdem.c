# include <stdio.h>
# include <stdlib.h>
# include <string.h>

int main() {

    int tamanhoCampo = 20;
    char strings[4][tamanhoCampo + 1] = {};
    char auxString[tamanhoCampo + 1] = {};


    for (int k = 0; k < 4; k++) {

        fputs("Digite a sua string: ", stdout);
        fgets(strings[k], tamanhoCampo, stdin);

        for (int i = 0; i < strlen(strings[k]); i++) {
            if (strings[k][i] == '\n') {
                strings[k][i] = '\000';
            }        
        }
    }
    
    for (int i = 0; i < 3; i++) {
        for (int j = i + 1, comparacao = 0; j < 4; j++) {
            comparacao = strcmp(strings[i], strings[j]);
            if (comparacao > 0) {
                strcpy(auxString, strings[i]);
                strcpy(strings[i], strings[j]);
                strcpy(strings[j], auxString);
            }
        }
    }

    // Impressão das strings em ordem alfabética
    printf("\nStrings em ordem alfabética:\n");
    for (int i = 0; i < 4; i++) {
        printf("%s\n", strings[i]);
    }

    
    return 0;
}