# include <stdio.h>
# include <string.h>

int main() {

        int tamanhoString = 20;
        char string[tamanhoString + 2] = {};
        int tamanhoDaString = 0;

        fputs("Digite uma string: ", stdout);
        fgets(string, tamanhoString, stdin);

        for (int i = 0; i < tamanhoString; i++) {
            if (string[i] == '\000') {
                if (string[i - 1] == '\n') {
                    string[i - 1] = '\000';
                    tamanhoDaString = i - 1;
                } else {
                    tamanhoDaString = i;
                } 
                break;               
            }            
        }

        fputs("Frase de tras-para-frente: ", stdout);
        for (int i = 0; i < tamanhoDaString; i++) {
            printf("%c", string[tamanhoDaString - i - 1]);
        }
        

    return 0;
}