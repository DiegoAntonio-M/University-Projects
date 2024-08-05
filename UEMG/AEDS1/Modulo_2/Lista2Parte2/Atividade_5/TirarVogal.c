# include <stdio.h>
# include <string.h>

int main() {

    int tamanhoFrase = 20;
    char string[tamanhoFrase + 2] = {};
    char vogais[10] = {'A','a', 'E', 'e', 'I', 'i', 'O', 'o', 'U', 'u'};
    int tamanhoDaString = 0;


    fputs("Digite uma string: ", stdout);
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

    for (int i = 0; i < tamanhoDaString; i++) {
        int imprimir = 1;
        for (int ii = 0; ii < 10; ii++) {
            if (string[i] == vogais[ii]) {
                imprimir = 0;
                break;
            }
            
        } 
        (imprimir == 1) ? printf("%c",string[i]) : fputs("", stdout);       
    }
    
    return 0;
}