# include <stdio.h>
# include <math.h>
# include <stdlib.h>
# include <string.h>

typedef struct arrayModulavel {
    int tamanhoArray;
    int *array;
    int endPoint;
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

int completarCriacaoArray (arrayModulavel *array1, int tamanhoInicial) {
    (tamanhoInicial < 1) ? tamanhoInicial = 1 : tamanhoInicial;
    array1->tamanhoArray = tamanhoInicial;
    array1->array = malloc(array1->tamanhoArray * sizeof(int));
    if (array1->array == NULL) {
        printf("Falha ao alocar memória.\n");
        return 1;
    } else {
        int arrayNULL[array1->tamanhoArray] = {};
        for (int j = 0; j < array1->tamanhoArray; j++) {
            array1->array[j] = arrayNULL[j];
        }        
        array1->endPoint = 0;
    }
}

void preencherArray (arrayModulavel *array1, char name) {
    printf("\n================> %c <================\n", name);
    int continuarAdicao = 1;
    do {
        alocarArray(array1, 1, 1);
        fputs("\n", stdout);
        for (int k = 0; k < array1->tamanhoArray; k++) {
            printf("| %d ", array1->array[k]);
        }
        printf("|\n");

        fputs("Escreva um numero para adicionar: ", stdout);
        scanf("%d", &array1->array[array1->endPoint++]);

        for (int k = 0; k < array1->tamanhoArray; k++) {
            printf("| %d ", array1->array[k]);
        }
        printf("|\n");

        fputs("Deseja continuar inserindo números? [1: Sim | 0: Não] >> ", stdout);
        scanf("%d", &continuarAdicao);
        
    } while (continuarAdicao == 1);
}

int somarArrays (arrayModulavel *array1, arrayModulavel *array2, arrayModulavel *arrayResultado) {
    if (array1->tamanhoArray == array2->tamanhoArray) {
        int marcadorDePossicao = 0;
        while (marcadorDePossicao < array1->tamanhoArray) {
            *arrayResultado->array = *array1->array + *array2->array;
            *arrayResultado->array++;
            *array1->array++;
            *array2->array++;
            marcadorDePossicao++;
        }
        array1->array -= marcadorDePossicao;
        array2->array -= marcadorDePossicao;
        arrayResultado->array -= marcadorDePossicao;

        return 1;        
    } else {
        return 0;
    }
    
}

int main() {

    arrayModulavel arrayA = {};
    completarCriacaoArray(&arrayA, 3);
    preencherArray(&arrayA, 'A');

    arrayModulavel arrayB = {};
    completarCriacaoArray(&arrayB, 3);
    preencherArray(&arrayB, 'B');

    arrayModulavel arrayC = {};
    completarCriacaoArray(&arrayC, arrayA.tamanhoArray);

    if (somarArrays(&arrayA, &arrayB, &arrayC)) {
        for (int i = 0; i < arrayC.tamanhoArray; i++) {
            printf("| %d ", *(arrayC.array++));
        }
        fputs("|\n", stdout);

    } else {
        fputs("\n#!#! Os arrays não tem o mesmo tamanho !#!#\n", stdout);
    }  

    return 0;
}