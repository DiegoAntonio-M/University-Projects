# include <stdio.h>
# include <math.h>
# include <stdlib.h>
# include <string.h>

int organizarVariavel (int *var1, int *var2, int *var3) {
    int movimentacoes = 0;
    do {
        movimentacoes = 0;
        if (*var1 > *var2) {
            int varAux = *var1;
            *var1 = *var2;
            *var2 = varAux;
            movimentacoes++;
        }
        if (*var2 > *var3) {
            int varAux = *var2;
            *var2 = *var3;
            *var3 = varAux;
            movimentacoes++;
        }
    } while (movimentacoes != 0);

    if ((*var1 == *var2) && (*var2 == *var3)) {
        return 1;
    } else {
        return 0;
    }
    
}

int main() {

    int valor1 = 0;
    int valor2 = 0;
    int valor3 = 0;

    fputs("Escreva 3 valores inteiros: ", stdout);
    scanf("%d %d %d", &valor1, &valor2, &valor3);
    int seIguais = organizarVariavel(&valor1, &valor2, &valor3);

    printf("| %d | %d | %d |\n", valor1, valor2, valor3);
    seIguais ? fputs(">> Todos são iguais\n", stdout) : fputs(">> Algum número eh diferente\n", stdout);;
    return 0;
}