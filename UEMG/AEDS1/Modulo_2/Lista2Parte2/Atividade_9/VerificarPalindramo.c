# include <stdio.h>
# include <string.h>

int main() {

    int tamanhoFrase = 50;
    char string[2][tamanhoFrase + 2] = {};
    
    fputs("<< [Verifcador de Palindramo] >>\n", stdout);
    fputs("Digite uma string: ", stdout);
    fgets(string[0], tamanhoFrase, stdin);

    string[0][strlen(string[0]) - 1] = '\000';
    int tamanhoDaString = strlen(string[0]);
    
    for (int i = 0; i < tamanhoDaString; i++) {
        string[1][i] = string[0][tamanhoDaString - i - 1];
    }

    if (strcmp(string[0], string[1]) == 0) {
        fputs("Eh palindramo!!!", stdout);

    } else {
        fputs("Nao eh palindramo!!!", stdout);
    }

    return 0;
}