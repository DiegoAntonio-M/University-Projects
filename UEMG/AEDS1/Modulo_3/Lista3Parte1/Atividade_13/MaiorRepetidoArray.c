# include <stdio.h>
# include <math.h>
# include <stdlib.h>
# include <string.h>

typedef struct arrayModulavel {
    int tamanhoArray;
    int *array;
    int endPoint;
    int maiorValor;
    int maiorValorepetido;
} arrayModulavel;


int alocarArray(arrayModulavel *array, int adicao, int limite) {
    (adicao < 1) ? adicao = 1 : adicao;
    (limite < 1) ? limite = 1 : limite;
    int cleaner = array->endPoint;
    while (array->tamanhoArray - array->endPoint < limite) {
        array->tamanhoArray += adicao;
        array->array = realloc(array->array, array->tamanhoArray * sizeof(int));
        if (array->array == NULL) {
            printf("Falha ao alocar memória.\n");
            return -1;
        }
        for (int i = cleaner; i < array->tamanhoArray; i++, cleaner++) {
            array->array[i] = 0;
        }
    }
    return 0;
}

void maiorRepetidoArray (arrayModulavel *array) {
    int maiorNum = array->array[0];
    int quantRepetido = 1;

    for (int i = 1; i < array->tamanhoArray; i++) {
        if (maiorNum == array->array[i]) {
            quantRepetido++;
        }
        if (maiorNum < array->array[i]) {
            maiorNum = array->array[i];
            quantRepetido = 1;
        }
    }
    array->maiorValor = maiorNum;
    array->maiorValorepetido = quantRepetido;
}

int main() {

    arrayModulavel array1;
    array1.tamanhoArray = 5;
    array1.array = malloc(array1.tamanhoArray * sizeof(int));
    if (array1.array == NULL) {
        printf("Falha ao alocar memória.\n");
        return 1;
    } else {
        int arrayNULL[array1.tamanhoArray] = {};
        for (int j = 0; j < array1.tamanhoArray; j++) {
            array1.array[j] = arrayNULL[j];
        }        
        array1.endPoint = 0;
    }
    
    int continuarAdicao = 1;
    do {
        alocarArray(&array1, 1, 1);
        fputs("\n", stdout);
        for (int k = 0; k < array1.tamanhoArray; k++) {
            printf("| %d ", array1.array[k]);
        }
        printf("|\n");

        fputs("Escreva um numero para adicionar: ", stdout);
        scanf("%d", &array1.array[array1.endPoint++]);

        for (int k = 0; k < array1.tamanhoArray; k++) {
            printf("| %d ", array1.array[k]);
        }
        printf("|\n");

        fputs("Deseja continuar inserindo números? [1: Sim | 0: Não] >> ", stdout);
        scanf("%d", &continuarAdicao);
        
    } while (continuarAdicao == 1);

    maiorRepetidoArray(&array1);
    printf(">>> O maior elemento [%d] teve %d ocorrencia(s).", array1.maiorValor, array1.maiorValorepetido);
    
    free(array1.array);
    return 0;
}