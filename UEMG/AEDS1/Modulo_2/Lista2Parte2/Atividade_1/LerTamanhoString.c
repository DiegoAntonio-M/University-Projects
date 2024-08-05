// Calcule o comprimento de uma string;
// Não usar a função "strlen";
// Imprima o valor do comprimento;

# include <stdio.h>
# include <string.h>

int main() {

        int tamanhoFrase = 40;
        char string[tamanhoFrase + 1] = {};
        int tamanhoDaString = 0;

        fputs("Digite a string -> ", stdout);
        fgets(string, tamanhoFrase, stdin);

        for (int i = 0; i < tamanhoFrase; i++) {
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
        
        fputs("A string -> ''", stdout);
        fputs(string, stdout);
        fputs("'' possui o tamanho:", stdout);
        printf(" %d\n", tamanhoDaString);

    return 0;
}