# include <stdio.h>
# include <math.h>
# include <stdlib.h>
# include <string.h>

typedef struct arrayModulavel {
    int tamanhoArray;
    char *array;
    int endPoint;
} arrayModulavel;


void removerQuerbraLinha(char *frase) {

    int tamanho = strlen(frase);
    if (tamanho > 0 && *(frase+tamanho - 1) == '\n') {
        frase[tamanho - 1] = '\0';
    }
    if (tamanho > 0 && *(frase+tamanho - 1) == ' ') {
        frase[tamanho - 1] = '\0';
    }
}

int alocarArray(arrayModulavel *array, int adicao, int limite) {
    (adicao < 1) ? adicao = 1 : adicao;
    (limite < 0) ? limite = 0 : limite;
    int cleaner = array->endPoint;
    while (array->tamanhoArray - array->endPoint < limite) {
        array->tamanhoArray += adicao;
        array->array = realloc(array->array, array->tamanhoArray * sizeof(char));
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
    array1->array = calloc(array1->tamanhoArray, sizeof(char));
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

int preencherArray (arrayModulavel *array1, FILE *arquivo) {
    
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        exit(1);
    }
    arrayModulavel textTemp = {};
    completarCriacaoArray(&textTemp, 2);
    int i = 0;
    char t = 0;

        while (((t = fgetc(arquivo)) != '\n') && t != EOF) {
            alocarArray(&textTemp, 1, 2);
            textTemp.array[textTemp.endPoint++] = t;
            i++;
        } 

    removerQuerbraLinha(textTemp.array);
    alocarArray(array1, 1, i);
    strcpy(array1->array, textTemp.array);
    array1->endPoint = (textTemp.endPoint - 1);

    if (t == EOF) return EOF;
    return 0;
}

int mesclarTextos (char *array1, char *array2, FILE *arquivoResultado) {

    if (arquivoResultado == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        exit(1);
    }
    fprintf(arquivoResultado, "%s\n", array1);
    fprintf(arquivoResultado, "%s\n", array2);
}


int main() {

    FILE *arquivo1 = fopen("Modulo_3\\Lista3Parte1\\Atividade_25\\arquivo1.txt", "r");

    FILE *arquivo2 = fopen("Modulo_3\\Lista3Parte1\\Atividade_25\\arquivo2.txt", "r");

    FILE *arquivoMesclado = fopen("Modulo_3\\Lista3Parte1\\Atividade_25\\arquivoMesclado.txt", "w");

    arrayModulavel arrayA = {};
    arrayModulavel arrayB = {};

    do {
        completarCriacaoArray(&arrayA, 1);
        completarCriacaoArray(&arrayB, 1);

        int c1 = preencherArray(&arrayA, arquivo1);
        int c2 = preencherArray(&arrayB, arquivo2);

        if ( c1 == EOF || c2 == EOF) {
            mesclarTextos(arrayA.array, arrayB.array, arquivoMesclado);
            fputs("\n## A Mesclagem Terminou ##\n", stdout);
            break;
        } else {
            mesclarTextos(arrayA.array, arrayB.array, arquivoMesclado);
        }

    } while (1);

    fclose(arquivoMesclado);
    fclose(arquivo1);
    fclose(arquivo2);

    return 0;
}