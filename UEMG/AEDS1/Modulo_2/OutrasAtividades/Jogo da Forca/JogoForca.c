# include <stdio.h>
# include <math.h>
# include <stdlib.h>
# include <time.h>
# include <string.h>

int main() {

    int tentativas = 5;
    int acertos = 0;
    char letraTentativa;

    char letras[27][2] = {
        {'A', 0}, {'B', 0}, {'C', 0}, {'D', 0}, {'E', 0}, {'F', 0},
        {'G', 0}, {'H', 0}, {'I', 0}, {'J', 0}, {'K', 0}, {'L', 0},
        {'M', 0}, {'N', 0}, {'O', 0}, {'P', 0}, {'Q', 0}, {'R', 0},
        {'S', 0}, {'T', 0}, {'U', 0}, {'V', 0}, {'W', 0}, {'X', 0},
        {'Y', 0}, {'Z', 0}, {'#', 0}};

    int linhaMostrar = 2;
    int colunaMostrar = 13;
    int tamanhoMaximoDasPalavras = 20;
    char palavraEscolhida[tamanhoMaximoDasPalavras] = {};

    int quantidadeDeCategorias = 6;
    char categorias[6][20] = {"Objeto", "Alimento", "Animal", "País", "Matéria de Estudo", "Time de Futebol"};

    int quantidadeDePalavras = 10;
    char palavraChave[6][10][20] = {
        {"COMPUTADOR", "CELULAR", "CARRO", "RELOGIO", "OCULOS", "CANETA", "CADEIRA", "MESA", "TELEVISAO", "LIVRO"},
        {"BANANA", "ARROZ", "FEIJAO", "MACARRAO", "ABACAXI", "CENOURA", "MELANCIA", "PAO", "QUEIJO", "CHOCOLATE"},
        {"GATO", "CACHORRO", "ELEFANTE", "LEAO", "TIGRE", "GIRAFA", "PANDA", "AGUIA", "BALEIA", "BORBOLETA"},
        {"BRASIL", "ESTADOS UNIDOS", "JAPAO", "FRANCA", "ITALIA", "INDIA", "AUSTRALIA", "CANADA", "ESPANHA", "ALEMANHA"},
        {"MATEMATICA", "FISICA", "QUIMICA", "BIOLOGIA", "HISTORIA", "GEOGRAFIA", "PROGRAMACAO", "PSICOLOGIA", "ECONOMIA", "FILOSOFIA"},
        {"CRUZEIRO", "FLAMENGO", "SANTOS", "PALMEIRAS", "GREMIO", "ATLETICO", "LIVERPOOL", "JUVENTUS", "CHELSEA", "BARCELONA"}
    };

    int categoriaEscolhida;
    char nomeDaCategoria[tamanhoMaximoDasPalavras] = {};

    int categoriaValida = 0;

    do {
        printf("Escolha uma categoria:\n");
        printf("1. Aleatória\n");
        int indiceCategoria;

        for (indiceCategoria = 0; indiceCategoria < quantidadeDeCategorias; indiceCategoria++) {
            printf("%d. %s\n", indiceCategoria+2, categorias[indiceCategoria]);
        }
        printf("%d. Escreva sua Palavra\n", indiceCategoria+2);

        printf("Digite a sua escolha: ");
        scanf("%d", &categoriaEscolhida);
        

        if (categoriaEscolhida == 1) {
            srand(time(NULL));
            categoriaEscolhida = rand() % quantidadeDeCategorias + 2; // Escolhe uma categoria aleatória
        };

        if (categoriaEscolhida >= 2 && categoriaEscolhida <= (quantidadeDeCategorias + 1)) {

            srand(time(NULL));
            int indicePalavra = rand() % quantidadeDePalavras;
            
            strcpy(palavraEscolhida, palavraChave[categoriaEscolhida - 2][indicePalavra]);
            printf("Palavra escolhida: %s\n", palavraEscolhida);

            strcpy(nomeDaCategoria, categorias[categoriaEscolhida-2]);

            if (strcmp(palavraEscolhida, "CRUZEIRO") == 0) {
                strcpy(nomeDaCategoria, "Maior de Minas");
            } 

            categoriaValida = 1;

        } else if (categoriaEscolhida == (quantidadeDeCategorias +  2)) {
            printf("Escreva uma PALAVRA [Max: 20 caracteres; TUDO EM LETRA BASTAO E SEM ACENTO]: ");
            scanf("%s", &palavraEscolhida);
            printf("Escreva o TEMA [Max: 20 caracteres; TUDO EM LETRA BASTAO E SEM ACENTO]: ");
            scanf("%s", &nomeDaCategoria);
            printf("Palavra escolhida: %s\n", palavraEscolhida);
            categoriaValida = 1;
        } else {
            printf("\n\n### Categoria inválida. Escolha um número entre 1 e 6 ###\n");
        }

        scanf("");

    } while (categoriaValida == 0);

    int tamanhoDaPalavraEscolhida = strlen(palavraEscolhida);
    while (tentativas >= 0 && acertos <= tamanhoDaPalavraEscolhida) {
        int indiceDeVerificação = 0;
        int caracterValido = 0;

        for (int i = 0; i < linhaMostrar; i++) {
            printf("\n");

            for (int ii = 0; (ii < colunaMostrar) && (letras[i*colunaMostrar+ii][0] != '#'); ii++) {
                printf("| %c ",letras[i*colunaMostrar+ii][0]);
            }
            printf("|\n");

        for (int ii = 0; (ii < colunaMostrar) && (letras[i*colunaMostrar+ii][0] != '#'); ii++) {
                (letras[i*colunaMostrar+ii][1] == 0) ? printf("| . ") : printf("| X ");
            }
            printf("|\n");
        }

        printf("\n\n +----+      TEMA: %s\n", nomeDaCategoria);
        printf(" |    |   \n");

        switch (tentativas) {
        case 5:
            printf(" |         \n");
            printf(" |         \n");
            printf(" |         \n");
            printf(" |           ");
            break;
        
        case 4:
            printf(" |    O    \n");
            printf(" |         \n");
            printf(" |         \n");
            printf(" |           ");
            break;

        case 3:
            printf(" |    O    \n");
            printf(" |    |    \n");
            printf(" |         \n");
            printf(" |           ");
            break;

        case 2:
            printf(" |   ;~;   \n");
            printf(" |   /|\\  \n");
            printf(" |         \n");
            printf(" |           ");
            break;

        case 1:
            printf(" |   ;~;   \n");
            printf(" |   /|\\  \n");
            printf(" |   /     \n");
            printf(" |           ");
            break;

        case 0:
            printf(" |   x-x   \n");
            printf(" |   /|\\  \n");
            printf(" |   / \\  \n");
            printf(" |           ");
            break;

        default:
            break;
        }
            // printf(" |   ;~;   \n");
            // printf(" |   /|\\  \n");
            // printf(" |   / \\  \n");
            // printf(" |           ");

                // printf("\nPalavra: ");
        for (int i = 0; i < tamanhoDaPalavraEscolhida; i++) {

            int controle = 0;
            for (int ii = 0; ii < 26; ii++) {
                
                if ((letras[ii][0] == palavraEscolhida[i]) && (letras[ii][1] == 1)) {
                    printf("%c ", palavraEscolhida[i]);
                    controle++;
                }
            }
            if (controle == 0) {
                    printf("_ ");
            }
        }
        printf("\n=============");

        for (int i = 0; i < tamanhoDaPalavraEscolhida; i++)
        {
            printf("==");
        }
        
        if ((tentativas != 0) && (acertos != tamanhoDaPalavraEscolhida)) {

            printf("\nTentativas restantes: %d\n", tentativas);
            printf("Digite uma letra: ");
            scanf(" %c", &letraTentativa);

            indiceDeVerificação = letraTentativa;

            if ((97 <= indiceDeVerificação) && (indiceDeVerificação <= 122)) {
                indiceDeVerificação = indiceDeVerificação - 32;
                letraTentativa = indiceDeVerificação;
                caracterValido = 1;

            } else if ((65 <= indiceDeVerificação) && (indiceDeVerificação <= 122)) {
                caracterValido = 1;
            } else {
                caracterValido = 0;
                printf("\n\n=============== Caracter incorreto!!! ===============");
            }
            
            if (caracterValido == 1) {

                for (int i = 0, sairFor = 0; (i < 26) && (sairFor == 0); i++) {

                    if (letras[i][0] == letraTentativa) {

                        if (letras[i][1] == '\000') {

                            letras[i][1] = 1;
                            sairFor = 1;

                            int controle = 0;
                            for (int ii = 0; ii < tamanhoDaPalavraEscolhida; ii++) {
                                
                                if ((letras[i][0] == palavraEscolhida[ii])) {
                                    acertos++;
                                    controle++;
                                }                            
                            }
                            if (controle == 0) {
                                tentativas--;
                            }                        

                        } else {
                            caracterValido = 0;
                            sairFor = 1;
                            printf("\n\n=========== Esse caracter já foi usado!!! ===========");
                            
                        }
                    }                
                }            
            }
        } else if (acertos == tamanhoDaPalavraEscolhida ) {
            printf("\nParabéns você ganhou!!!\n");
            acertos ++;
        } else if (tentativas == 0) {
            printf("\nVocê perdeu!!!\n");
            tentativas--;
        }

        printf(" ");

    }

    return 0;
}