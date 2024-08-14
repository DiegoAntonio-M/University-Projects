# include <stdio.h>
# include <math.h>
# include <stdlib.h>
# include <string.h>

typedef struct arrayModulavel {
    int tamanhoArray;
    float *array;
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

int comletarCriacaoArray(arrayModulavel *array1, int tamanhoInicial) {
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

void preencherArray(arrayModulavel *array1, char name) {
    printf("\n================> %c <================\n", name);
    int continuarAdicao = 1;
    do {
        alocarArray(array1, 1, 1);
        fputs("\n", stdout);
        for (int k = 0; k < array1->tamanhoArray; k++) {
            printf("| %f ", array1->array[k]);
        }
        printf("|\n");

        fputs("Escreva algum numero racional para adicionar: ", stdout);
        scanf("%f", &array1->array[array1->endPoint++]);

        for (int k = 0; k < array1->tamanhoArray; k++) {
            printf("| %f ", array1->array[k]);
        }
        printf("|\n");

        fputs("Deseja continuar inserindo números? [1: Sim | 0: Não] >> ", stdout);
        scanf("%d", &continuarAdicao);
        
    } while (continuarAdicao == 1);
}

int negativos(float *vet, int N) {
    int contarNegativos = 0;
    for (int i = 0; i < N; i++) {
        if (vet[i] < 0) {
            contarNegativos++;
        }
    }
    return contarNegativos;
}

int main() {

    arrayModulavel numerosN = {};
    comletarCriacaoArray(&numerosN, 1);

    preencherArray(&numerosN, 'N');

    int quantidadeNegativos = negativos(numerosN.array, numerosN.tamanhoArray);

    printf("\nA lista de numeros racionais contem %d numero(s) negativo(s)!\n", quantidadeNegativos);
    return 0;
}