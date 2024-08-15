# include <stdio.h>
# include <math.h>
# include <stdlib.h>
# include <string.h>

typedef struct arrayModulavel {
    int tamanhoArray;
    char *array;
    int endPoint;
} arrayModulavel;

void limparBuffer() {
    fflush(stdin);
    setbuf(stdin,NULL);
}

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
    array1->array = malloc(array1->tamanhoArray * sizeof(char));
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

void removerQuerbraLinha(char *frase) {

    int tamanho = strlen(frase);
    if (tamanho > 0 && *(frase+tamanho - 1) == '\n') {
        frase[tamanho - 1] = '\0';
    }
}

void inserirTexto (char *gardarEm, int tamanho) {

    char textTemp[tamanho+2] = {};
    limparBuffer();
    fgets(textTemp, tamanho, stdin);

    removerQuerbraLinha(textTemp);

    strcpy(gardarEm, textTemp);
}


int main() {

    arrayModulavel frase = {};
    fputs("Digite a quantidade maxina de caracteres para sua frase: ", stdout);
    int quantCaracteres = 0;
    scanf("%d", &quantCaracteres);
    completarCriacaoArray(&frase, quantCaracteres + 2);

    fputs("Digite a sua frase: ", stdout);
    inserirTexto(frase.array, quantCaracteres);

    fputs("A sua frase sem vogais eh: ", stdout);
    for (int i = 0; i < strlen(frase.array); i++) {
        switch (frase.array[i]) {
        case 'a':
            printf("_ ");
            break;
        case 'e':
            printf("_ ");
            break;
        case 'i':
            printf("_ ");
            break;
        case 'o':
            printf("_ ");
            break;
        case 'u':
            printf("_ ");
            break;
        default:
            printf("%c ", frase.array[i]);
            break;
        }        
    }
    
    return 0;
}