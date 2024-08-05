# include <stdio.h>
# include <string.h>

int main() {

    int tamanhoString = 20;
    char string[tamanhoString + 2] = {};
    char stringProc[2] = {};
    int contar = 0;

    fputs("Digite uma string: ", stdout);
    fgets(string, tamanhoString, stdin);

    fputs("Digite um caracter para procurar: ", stdout);
    fgets(stringProc, 2, stdin);

    for (int i = 0; i < tamanhoString; i++) {
        if (string[i] == stringProc[0]) {
            contar++;
        }
        
    }

    printf("Pra [%c] foram encontrados: %d ocorrencia(s)", stringProc[0], contar);

    return 0;
}