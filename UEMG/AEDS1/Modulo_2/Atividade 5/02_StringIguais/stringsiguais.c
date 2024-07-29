# include <stdio.h>
# include <stdlib.h>
# include <string.h>

int main() {

    char string1[20] = {};
    char string2[20] = {};

    fputs("Digite a sua primeira string: ", stdout);
    fgets(string1, 20, stdin);

    fputs("Digite a sua segunda string: ", stdout);
    fgets(string2, 20, stdin);

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

    if (strcmp(string1, string2) == 0) {

        fputs("As strings são iguais", stdout);
    } else {

        if (strlen(string1) > strlen(string2)) {

            fputs("A maior string: ", stdout);
            fputs(string1, stdout);
            fputs("\n", stdout);
        } else {

            fputs("A maior string: ", stdout);
            fputs(string2, stdout);
            fputs("\n", stdout);
        }

        strcat(string1, string2);

        fputs("String concatenada: ", stdout);
        fputs(string1, stdout);
        
    }
    
    return 0;
}