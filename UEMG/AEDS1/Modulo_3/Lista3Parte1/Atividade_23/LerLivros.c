# include <stdio.h>
# include <math.h>
# include <stdlib.h>
# include <string.h>

#define TAMANHO_STRING 50

typedef struct TLivros {
    char livroName[TAMANHO_STRING];
    char livroAuthor[TAMANHO_STRING];
} TLivros;

typedef struct Estante {
    int quantLivros;
    TLivros *livros;
    int endPoint;
} Estante;

int completarCriacao (Estante *livros, int tamanhoInicial) {
    (tamanhoInicial < 1) ? tamanhoInicial = 1 : tamanhoInicial;
    livros->quantLivros = tamanhoInicial;
    livros->livros = calloc(livros->quantLivros, sizeof(TLivros));
    if (livros->livros == NULL) {
        printf("Falha ao alocar memória.\n");
        return 1;
        exit(-1);
    } else {
        TLivros arrayNULL[livros->quantLivros] = {};
        for (int j = 0; j < livros->quantLivros; j++) {
            livros->livros[j] = arrayNULL[j];
        }
    }
}

int alocarLivros (Estante *livros, int adicao, int limite) {
    (adicao < 1) ? adicao = 1 : adicao;
    (limite < 1) ? limite = 1 : limite;
    int cleaner = livros->endPoint;
    while (livros->quantLivros - livros->endPoint < limite) {
        livros->quantLivros += adicao;
        livros->livros = realloc(livros->livros, livros->quantLivros * sizeof(TLivros));
        if (livros->livros == NULL) {
            printf("Falha ao alocar memória.\n");
            return -1;
            exit(-1);
        }
        TLivros arrayNULL[livros->quantLivros] = {};
        for (int i = cleaner; i < livros->quantLivros; i++, cleaner++) {
            livros->livros[i] = arrayNULL[i];
        }
    }
    return 0;
}

void removerQuerbraLinha(char *frase) {

    int tamanho = strlen(frase);
    if (tamanho > 0 && *(frase+tamanho - 1) == '\n') {
        frase[tamanho - 1] = '\0';
    }
    if (tamanho > 0 && *(frase+tamanho - 1) == ' ') {
        frase[tamanho - 1] = '\0';
    }
}


void preencherLivrosNome (Estante *livros, int *t, FILE *arq) {

    alocarLivros(livros, 1, 1);

    char textTemp[TAMANHO_STRING+2] = {};
    int i = 0;

        while (((*t = fgetc(arq)) != 64) && *t != EOF) {
            textTemp[i] = *t;
            i++;
        };
    removerQuerbraLinha(textTemp);

    strcpy(livros->livros[livros->endPoint].livroName, textTemp);
}

void preencherLivrosAuthor (Estante *livros, int *t, FILE *arq) {

    alocarLivros(livros, 1, 1);

    char textTemp[TAMANHO_STRING+2] = {};
    int i = 0;

        while (((*t = fgetc(arq)) != 35) && *t != EOF) {
            textTemp[i] = *t;
            i++;
        };
    removerQuerbraLinha(textTemp);

    strcpy(livros->livros[livros->endPoint].livroAuthor, textTemp);
}

void inserirTexto (char *gardarEm) {

    char textTemp[TAMANHO_STRING+1] = {};
    fflush(stdin);
    setbuf(stdin,NULL);
    fgets(textTemp, TAMANHO_STRING, stdin);

    removerQuerbraLinha(textTemp);

    strcpy(gardarEm, textTemp);
}

int main() {

    FILE *arquivo = NULL;
    arquivo = fopen("Modulo_3\\Lista3Parte1\\Atividade_23\\Livros.txt","r");

    Estante estante = {};
    completarCriacao(&estante, 1);

    int t = fgetc(arquivo);

    do {
        
        switch (t) {
            case (35):                
                preencherLivrosNome(&estante, &t, arquivo);
                break;
            case 64:
                preencherLivrosAuthor(&estante, &t, arquivo);
                break;
            default:
                t = fgetc(arquivo);
                break;
        }
        if (t == 35) {
            estante.endPoint++;
        }        
        
    } while (t != EOF);
    
    
    fputs("\n\n", stdout);
    int pesquisarDenovo = 0;
    do {
        char procNomeLivro[TAMANHO_STRING + 2] = {};
        fputs("Procure por -> ", stdout);    
        inserirTexto(procNomeLivro);
        fputs("\n", stdout);
        int foiEncontrado = 0;

        for (int i = 0; i < estante.quantLivros; i++) {

            int validarNome = 0;
            int tamNomeLivro = strlen(estante.livros[i].livroName);
            int tamProcNomeLivro = strlen(procNomeLivro);
            int tamanhoMin = 0;

            tamNomeLivro < tamProcNomeLivro ? tamanhoMin = tamNomeLivro : (tamanhoMin = tamProcNomeLivro);

            for (int p = 0; p < tamanhoMin; p++) {
                if (estante.livros[i].livroName[p] == procNomeLivro[p]) {
                    validarNome = 1;
                } else {
                    validarNome = 0;
                    break;
                }
            }

            if (validarNome == 1) {
                printf(">Indice [%d] >> %s;\n", i, estante.livros[i].livroName);

                printf(" >> Nome da Obra: %s;\n", estante.livros[i].livroName);
                printf(" >> Autor: %s.\n\n", estante.livros[i].livroAuthor);
            }
            foiEncontrado += validarNome;

        }
        
        (foiEncontrado == 0) ? fputs("!#!#! Não encontrado !#!#!\n", stdout) : fputs("", stdout) ;

        fputs(">> Você deseja pesquisar novamente ? [Sim = 1 | Não = 0]: ", stdout);
        scanf("%d", &pesquisarDenovo);
    } while (pesquisarDenovo == 1);

    return 0;
}