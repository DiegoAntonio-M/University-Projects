# include <stdio.h>
# include <math.h>
# include <stdlib.h>
# include <string.h>

typedef struct memoriaModulavel {
    int quantEspaco;
    int *espaco;
    int posicao1;
    int posicao2;
    int posicao3;
} memoriaModulavel;

int completarCriacaoMemoria (memoriaModulavel *memory, int tamanhoInicial) {
    (tamanhoInicial < 1) ? tamanhoInicial = 1 : tamanhoInicial;
    memory->quantEspaco = tamanhoInicial;
    memory->espaco = (int *) calloc(memory->quantEspaco, sizeof(int));
    if (memory->espaco == NULL) {
        printf("Falha ao alocar memória.\n");
        return 1;
    } else {
        fputs(" >>> Memoria Criada !!! <<< \n", stdout);
    }
}

int read (memoriaModulavel *memory) {
    return (*memory).espaco[memory->posicao1-1];
}

int write (memoriaModulavel *memory) {
    fputs("Escreva um inteiro >>>> ", stdout);
    scanf("%d", &(*memory).espaco[memory->posicao3-1]);
}

int main() {

    memoriaModulavel memoria = {};
    int opcao = 0;
    fputs("Crie a sua memória - Escreva o tamanho desejado >> ", stdout);
    scanf("%d", &memoria.quantEspaco);
    completarCriacaoMemoria(&memoria, memoria.quantEspaco);

    for (int i = 0; i < memoria.quantEspaco; i++) {
        printf("| %d ", memoria.espaco[i]);
    }
    fputs("|\n", stdout);

    do {
        fputs("\nEscolha uma opção [0: Sair | 1: Ler | 2: Escrever] >> ", stdout);
        scanf("%d", &opcao);

        if (opcao != 0) {
            switch (opcao) {
            case 1:
                
                do {
                    fputs("[R] Escolha uma posição >>> ", stdout);
                    scanf("%d", &memoria.posicao1);
                    if (!(0 < memoria.posicao1 && memoria.posicao1 <= memoria.quantEspaco))  {
                        fputs("<#> Posição inválida <#>\n", stdout);
                    }   
                } while (!(0 < memoria.posicao1 && memoria.posicao1 <= memoria.quantEspaco));
                
                printf("\n>>> |[ %d ]|\n", read(&memoria));
                break;
            case 2:
                
                do {
                    fputs("[W] Escolha uma posição >>> ", stdout);
                    scanf("%d", &memoria.posicao3);
                    if (!(0 < memoria.posicao3 && memoria.posicao3 <= memoria.quantEspaco))  {
                        fputs("<#> Posição inválida <#>\n", stdout);
                    }    
                } while (!(0 < memoria.posicao3 && memoria.posicao3 <= memoria.quantEspaco));
                
                write(&memoria);
                for (int i = 0; i < memoria.quantEspaco; i++) {
                    printf("| %d ", memoria.espaco[i]);
                }
                fputs("|\n", stdout);
                
                break;

            default:
                break;
            }
        }

    } while (opcao != 0);

    return 0;
}