# include <stdio.h>
# include <math.h>
# include <stdlib.h>
# include <string.h>

# define MARCFINAL -1

void preencherArray (int *array, int value) {

    while (*array != MARCFINAL) {
        *array = value;
        array++;
    }
    *array = value;    
}

int main() {
    int tamanhoArray = 10;
    int array[tamanhoArray] = {};
    array[tamanhoArray-1] = MARCFINAL;

    int preenchimento = 0;
    fputs("Escolha um numero para preencher o Array: ", stdout);
    scanf("%d", &preenchimento);

    preencherArray(array, preenchimento);

    for (int i = 0; i < tamanhoArray; i++) {
        printf("| %d ", *(array+i));
    }
    fputs("|\n", stdout);

    return 0;
}