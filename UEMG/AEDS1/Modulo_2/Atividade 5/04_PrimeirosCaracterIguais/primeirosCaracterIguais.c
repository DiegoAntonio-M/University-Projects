# include <stdio.h>
# include <stdlib.h>
# include <string.h>

int main() {

    int tamanhoFrase = 20;
    char string1[tamanhoFrase + 1] = {};
    char string2[tamanhoFrase + 1] = {};
    char auxString1[tamanhoFrase + 1] = {};
    char auxString2[tamanhoFrase + 1] = {};
    int numDeCorte = 0;

    fputs("Digite a sua primeira string: ", stdout);
    fgets(string1, tamanhoFrase, stdin);

    fputs("Digite a sua segunda string: ", stdout);
    fgets(string2, tamanhoFrase, stdin);


    fputs("Digite os primeiros números a serem comparados: ", stdout);
    scanf("%d", &numDeCorte);




    for (int i = 0; i < strlen(string1); i++) {
        if (string1[i] == '\n') {
            string1[i] = '\000';
        }        
    }
    
    for (int i = 0; i < strlen(string2); i++) {
        if (string2[i] == '\n') {
            string2[i] = '\000';
        }        
    }
        

    for (int i = 0; i < numDeCorte; i++) {

        auxString1[i] = string1[i];
        auxString2[i] = string2[i];        
    }

    if (strcmp(auxString1, auxString2) == 0) {
        printf("O intervalo das strings são iguais.\n");
    } else {
        printf("O intervalo das strings são diferentes.\n");
    }    

    return 0;
}