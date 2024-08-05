# include <stdio.h>
# include <string.h>

int main() {

    int tamanhoFrase = 50;
    char string[2][tamanhoFrase + 2] = {};
    int tamanhoDaString = 0;

    fputs("Digite uma string: ", stdout);
    fgets(string[0], tamanhoFrase, stdin);

    for (int i = 0; i < tamanhoFrase; i++) {
        if (string[0][i] == '\000') {
            if (string[0][i - 1] == '\n') {
                string[0][i - 1] = '\000';
                tamanhoDaString = i - 1;
            } else {
                tamanhoDaString = i;
            } 
            break;               
        }            
    }

    for (int i = 0; i < tamanhoDaString; i++) {
        string[1][i] = string[0][i] + 1;
    }

    fputs("A nova string -> ''", stdout);
    fputs(string[1], stdout);
    

    return 0;
}