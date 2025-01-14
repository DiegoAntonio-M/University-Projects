#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "rodadaIA.c"
#include "stdbool.h"

// Função para verificar vitória
void verificarVitoria(char tableJogoDaVelha[3][3][2], char *vitoria) {
    for (int i = 0; i < 3; i++) {
        if ((tableJogoDaVelha[i][0][0] == tableJogoDaVelha[i][1][0]) && (tableJogoDaVelha[i][1][0] == tableJogoDaVelha[i][2][0])) {
            if (tableJogoDaVelha[i][0][1] == 1 && tableJogoDaVelha[i][1][1] == 1 && tableJogoDaVelha[i][2][1] == 1) {
                vitoria[0] = 1;
                vitoria[1] = tableJogoDaVelha[i][2][0];
            }
        }
    }

    for (int i = 0; i < 3; i++) {
        if ((tableJogoDaVelha[0][i][0] == tableJogoDaVelha[1][i][0]) && (tableJogoDaVelha[1][i][0] == tableJogoDaVelha[2][i][0])) {
            if (tableJogoDaVelha[0][i][1] == 1 && tableJogoDaVelha[1][i][1] == 1 && tableJogoDaVelha[2][i][1] == 1) {
                vitoria[0] = 1;
                vitoria[1] = tableJogoDaVelha[2][i][0];
            }
        }
    }

    if (tableJogoDaVelha[0][0][0] == tableJogoDaVelha[1][1][0] && tableJogoDaVelha[1][1][0] == tableJogoDaVelha[2][2][0]) {
        if (tableJogoDaVelha[0][0][1] == 1 && tableJogoDaVelha[1][1][1] == 1 && tableJogoDaVelha[2][2][1] == 1) {
            vitoria[0] = 1;
            vitoria[1] = tableJogoDaVelha[2][2][0];
        }
    }
    if (tableJogoDaVelha[0][2][0] == tableJogoDaVelha[1][1][0] && tableJogoDaVelha[1][1][0] == tableJogoDaVelha[2][0][0]) {
        if (tableJogoDaVelha[0][2][1] == 1 && tableJogoDaVelha[1][1][1] == 1 && tableJogoDaVelha[2][0][1] == 1) {
            vitoria[0] = 1;
            vitoria[1] = tableJogoDaVelha[2][0][0];
        }
    }
}

void salvar_rede(RedeNeural *rn, const char *filename) {
    FILE *file = fopen(filename, "wb");
    if (file == NULL) {
        perror("Erro ao abrir o arquivo para salvar");
        return;
    }

    fwrite(&rn->epoca, sizeof(int), 1, file);
    fwrite(&rn->quantentradas, sizeof(int), 1, file);
    fwrite(&rn->quantsaida, sizeof(int), 1, file);
    fwrite(&rn->num_camadas_ocultas, sizeof(int), 1, file);

    for (int i = 0; i < rn->num_camadas_ocultas; i++) {
        fwrite(&rn->camadas_ocultas[i].tamanho, sizeof(int), 1, file);
        for (int j = 0; j < rn->camadas_ocultas[i].tamanho; j++) {
            fwrite(&rn->camadas_ocultas[i].neuronios[j].valor, sizeof(double), 1, file);
            fwrite(&rn->camadas_ocultas[i].neuronios[j].bias, sizeof(double), 1, file);
            fwrite(rn->camadas_ocultas[i].neuronios[j].pesos, sizeof(double), (i == 0 ? rn->quantentradas : rn->camadas_ocultas[i - 1].tamanho), file);
            printf("Salvando Camada %d, Neurônio %d, Peso: %lf\n", i, j, rn->camadas_ocultas[i].neuronios[j].pesos[0]);
        }
    }

    // fwrite(&rn->camada_saida.tamanho, sizeof(int), 1, file);
    for (int i = 0; i < rn->camada_saida.tamanho; i++) {
        fwrite(&rn->camada_saida.neuronios[i].valor, sizeof(double), 1, file);
        fwrite(&rn->camada_saida.neuronios[i].bias, sizeof(double), 1, file);
        fwrite(rn->camada_saida.neuronios[i].pesos, sizeof(double), rn->camadas_ocultas[rn->num_camadas_ocultas - 1].tamanho, file);
        printf("Salvando Camada de Saída, Neurônio %d, Peso: %lf\n", i, rn->camada_saida.neuronios[i].pesos[0]);
    }

    fclose(file);
}

void inicializar_rede(RedeNeural *rn, int quantentradas, int quantsaida, int num_camadas_ocultas, int *layerconfig, const char *filename) {

    rn->epoca = 0;
    rn->quantentradas = quantentradas;
    rn->quantsaida = quantsaida;
    rn->num_camadas_ocultas = num_camadas_ocultas;

    rn->camada_entrada.tamanho = quantentradas;
    rn->camada_entrada.neuronios = (Neuronio *)calloc(quantentradas, sizeof(Neuronio));

    rn->camadas_ocultas = (Camada *)calloc(num_camadas_ocultas, sizeof(Camada));

    for (int i = 0; i < num_camadas_ocultas; i++) {
        rn->camadas_ocultas[i].tamanho = layerconfig[i];
        rn->camadas_ocultas[i].neuronios = (Neuronio *)calloc(layerconfig[i], sizeof(Neuronio));
        for (int j = 0; j < layerconfig[i]; j++) {
            rn->camadas_ocultas[i].neuronios[j].pesos = (double *)calloc((i == 0 ? quantentradas : layerconfig[i - 1]), sizeof(double));
            rn->camadas_ocultas[i].neuronios[j].bias = ((double)rand() / (RAND_MAX)) * 2 - 1;
            for (int k = 0; k < (i == 0 ? quantentradas : layerconfig[i - 1]); k++) {
                rn->camadas_ocultas[i].neuronios[j].pesos[k] = (((double)rand() / (RAND_MAX)) * 2 - 1)/1000000;
                printf("Inicializando Camada %d, Neurônio %d, Peso %d: %lf\n", i, j, k, rn->camadas_ocultas[i].neuronios[j].pesos[k]);
            }
        }
    }

    rn->camada_saida.tamanho = quantsaida;
    rn->camada_saida.neuronios = (Neuronio *)calloc(quantsaida, sizeof(Neuronio));
    for (int i = 0; i < quantsaida; i++) {
        rn->camada_saida.neuronios[i].pesos = (double *)calloc(layerconfig[num_camadas_ocultas - 1], sizeof(double));
        rn->camada_saida.neuronios[i].bias = ((double)rand() / (RAND_MAX)) * 2 - 1;
        for (int j = 0; j < layerconfig[num_camadas_ocultas - 1]; j++) {
            rn->camada_saida.neuronios[i].pesos[j] = (((double)rand() / (RAND_MAX)) * 2 - 1)/1000000;
            printf("Inicializando Camada de Saída, Neurônio %d, Peso %d: %lf\n", i, j, rn->camada_saida.neuronios[i].pesos[j]);
        }
    }

    // Save the initial state of the neural network
    salvar_rede(rn, filename);
}

void adicionar_exemplo(double ***entradas, double ***alvos, double ***selectParcial, int *num_exemplos, double *nova_entrada, double *novo_alvo, double *novo_selectParcial) {
    *entradas = (double **)realloc(*entradas, (*num_exemplos + 1) * sizeof(double *));
    *alvos = (double **)realloc(*alvos, (*num_exemplos + 1) * sizeof(double *));
    *selectParcial = (double **)realloc(*selectParcial, (*num_exemplos + 1) * sizeof(double *));
    (*entradas)[*num_exemplos] = (double *)calloc(9, sizeof(double));
    (*alvos)[*num_exemplos] = (double *)calloc(9, sizeof(double));
    (*selectParcial)[*num_exemplos] = (double *)calloc(9, sizeof(double));
    for (int i = 0; i < 9; i++) {
        (*entradas)[*num_exemplos][i] = nova_entrada[i];
        (*alvos)[*num_exemplos][i] = novo_alvo[i];
        (*selectParcial)[*num_exemplos][i] = novo_selectParcial[i];
    }
    (*num_exemplos)++;
}

double calcularMSE(double *alvo, Neuronio *saida, int tamanho) {
    double soma_erro = 0.0;
    for (int i = 0; i < tamanho; i++) {
        double erro = saida[i].valor - alvo[i];
        soma_erro += erro * erro;
    }
    return soma_erro / tamanho;
}

void registrarLogCusto(const char *filename, int epocaRN, int epoca, int exemplo, double custo, int numRN, double threshold) {
    FILE *log_file = fopen(filename, "a");
    if (log_file == NULL) {
        perror("Erro ao abrir o arquivo de log");
        return;
    }

    fprintf(log_file, "%d\t%d\t%d\t%d\t%lf\t%.10lf\n",numRN, epocaRN, epoca, exemplo, threshold, custo);
    fclose(log_file);
}

void treinar_rede(RedeNeural *rn, double **entradas, double **alvos, int num_exemplos, int epocas, double **selectParcial, int numRN, double threshold) {
    const char *log_filename = "./Jogo da Velha Inteligente/log/log_funcao_custo.txt";
    for (int epoca = 0; epoca < epocas; epoca++) {
        for (int i = 0; i < num_exemplos; i++) {
            propagacao_frente(rn, entradas[i]);
            double custo = calcularMSE(alvos[i], rn->camada_saida.neuronios, rn->quantsaida);
            registrarLogCusto(log_filename, rn->epoca, epoca, i, custo, numRN, threshold);
            retropropagacao(rn, entradas[i], alvos[i], selectParcial[i]);
        }
    }
}

int main() {
    #define TX_DOPAMINA 0.95
    # define QUANTHIDELAYER 3
    int layerconfig[QUANTHIDELAYER] = {21, 12, 12};
    RedeNeural rn1 = {};
    RedeNeural rn2 = {};

    // Check if the file exists
    FILE *file1 = fopen("./Jogo da Velha Inteligente/Models/rede_neural1.bin", "rb");
    FILE *file2 = fopen("./Jogo da Velha Inteligente/Models/rede_neural2.bin", "rb");
    if (file1) {
        fclose(file1);
        char choice1;
        printf("Arquivo de rede neural 1 existente encontrado. Deseja carregar (C) ou inicializar novo (N)? ");
        scanf(" %c", &choice1);
        if (choice1 == 'C' || choice1 == 'c') {
            carregar_rede(&rn1, "./Jogo da Velha Inteligente/Models/rede_neural1.bin");
        } else {
            inicializar_rede(&rn1, 9, 9, QUANTHIDELAYER, layerconfig, "./Jogo da Velha Inteligente/Models/rede_neural1.bin");
        }
    } else {
        inicializar_rede(&rn1, 9, 9, QUANTHIDELAYER, layerconfig, "./Jogo da Velha Inteligente/Models/rede_neural1.bin");
    }

    if (file2) {
        fclose(file2);
        char choice2;
        printf("Arquivo de rede neural 2 existente encontrado. Deseja carregar (C) ou inicializar novo (N)? ");
        scanf(" %c", &choice2);
        if (choice2 == 'C' || choice2 == 'c') {
            carregar_rede(&rn2, "./Jogo da Velha Inteligente/Models/rede_neural2.bin");
        } else {
            inicializar_rede(&rn2, 9, 9, QUANTHIDELAYER, layerconfig, "./Jogo da Velha Inteligente/Models/rede_neural2.bin");
        }
    } else {
        inicializar_rede(&rn2, 9, 9, QUANTHIDELAYER, layerconfig, "./Jogo da Velha Inteligente/Models/rede_neural2.bin");
    }

    // Treine a rede neural

    double threshold = 0.5;

    for (int epoca = fmin(rn1.epoca, rn2.epoca); epoca < 600; epoca++) {
        for (int rounds = 0; rounds < 6; rounds++) {
            printf("Época >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> %d\n", epoca);
            // Inicialize o array dinâmico para armazenar os exemplos de treinamento

            double **entradas = NULL;
            double **alvos = NULL;
            double **selectParcial = NULL;
            int num_exemplos = 0;

            double **historicoRN1_entradas = NULL;
            double **historicoRN1_alvos = NULL;
            double **historicoRN1_selectParcial = NULL;
            int num_historicoRN1 = 0;

            double **historicoRN2_entradas = NULL;
            double **historicoRN2_alvos = NULL;
            double **historicoRN2_selectParcial = NULL;
            int num_historicoRN2 = 0;
            
            char tableJogoDaVelha[3][3][2] = {{{' ',0},{' ',0},{' ',0}},{{' ',0},{' ',0},{' ',0}},{{' ',0},{' ',0},{' ',0}}};
            int cordenadaLinha = 0;
            int cordenadaColuna = 0;
            char numeroASerGuardado = 'A';
            char vitoria[2] = {0,' '};
            int contarRodada = 0;
            bool infinita = false;
            char opcoesDosJogadores[2] = {'X','O'};
            char caractersAnterior[2] = { 0,0};

            srand(time(NULL));
            int setRodada = rand() % 2;

            double dataSetEntrada[83][9] = {
                {0, 0, 0, 0, 0, 0, 0, 0, 0},
                {0, 0, 0, 0, -1, 0, 0, 0, 0},
                {-1, 0, 0, 0, 0, 0, 0, 0, 0},
                {0, 0, 0, 0, -1, 0, 0, 0, 0},
                {0, -1, 0, 0, 0, 0, 0, 0, 0},
                {0, 0, 0, 0, -1, 0, 0, 0, 0},
                {0, 0, -1, 0, 0, 0, 0, 0, 0},
                {0, 0, 0, 0, -1, 0, 0, 0, 0},
                {0, 0, 0, -1, 0, 0, 0, 0, 0},
                {0, 0, 0, 0, -1, 0, 0, 0, 0},
                {0, 0, 0, 0, 0, -1, 0, 0, 0},
                {0, 0, 0, 0, -1, 0, 0, 0, 0},
                {0, 0, 0, 0, 0, 0, -1, 0, 0},
                {0, 0, 0, 0, -1, 0, 0, 0, 0},
                {0, 0, 0, 0, 0, 0, 0, -1, 0},
                {0, 0, 0, 0, -1, 0, 0, 0, 0},
                {0, 0, 0, 0, 0, 0, 0, 0, -1},

                {-1, -1, 0, 0, 0, 0, 0, 0, 0},
                {0, 0, 0, -1, -1, 0, 0, 0, 0},
                {0, 0, 0, 0, 0, 0, -1, -1, 0},

                {-1, 0, -1, 0, 0, 0, 0, 0, 0},
                {0, 0, 0, -1, 0, -1, 0, 0, 0},
                {0, 0, 0, 0, 0, 0, -1, 0, -1},

                {0, -1, -1, 0, 0, 0, 0, 0, 0},
                {0, 0, 0, 0, -1, -1, 0, 0, 0},
                {0, 0, 0, 0, 0, 0, 0, -1, -1},

                {-1, 0, 0, -1, 0, 0, 0, 0, 0},
                {0, -1, 0, 0, -1, 0, 0, 0, 0},
                {0, 0, -1, 0, 0, -1, 0, 0, 0},

                {-1, 0, 0, 0, 0, 0, -1, 0, 0},
                {0, -1, 0, 0, 0, 0, 0, -1, 0},
                {0, 0, -1, 0, 0, 0, 0, 0, -1},

                {0, 0, 0, -1, 0, 0, -1, 0, 0},
                {0, 0, 0, 0, -1, 0, 0, -1, 0},
                {0, 0, 0, 0, 0, -1, 0, 0, -1},

                {1, 0, 0, 0, 1, 0, 0, 0, 0},
                {0, 0, 1, 0, 1, 0, 0, 0, 0},

                {1, 0, 0, 0, 0, 0, 0, 0, 1},
                {0, 0, 1, 0, 0, 0, 1, 0, 0},

                {0, 0, 0, 0, 1, 0, 0, 0, 1},
                {0, 0, 0, 0, 1, 0, 1, 0, 0},


                {1, -1, 0, 0, 0, 0, 0, 0, 0},
                {0, 0, 0, -1, -1, 0, 0, 0, 0},
                {0, 0, 0, 0, 0, 0, -1, -1, 0},

                {-1, 0, -1, 0, 0, 0, 0, 0, 0},
                {0, 0, 0, -1, 0, -1, 0, 0, 0},
                {0, 0, 0, 0, 0, 0, -1, 0, -1},

                {0, -1, -1, 0, 0, 0, 0, 0, 0},
                {0, 0, 0, 0, -1, -1, 0, 0, 0},
                {0, 0, 0, 0, 0, 0, 0, -1, -1},

                {-1, 0, 0, -1, 0, 0, 0, 0, 0},
                {0, -1, 0, 0, -1, 0, 0, 0, 0},
                {0, 0, -1, 0, 0, -1, 0, 0, 0},

                {-1, 0, 0, 0, 0, 0, -1, 0, 0},
                {0, -1, 0, 0, 0, 0, 0, -1, 0},
                {0, 0, -1, 0, 0, 0, 0, 0, -1},

                {0, 0, 0, -1, 0, 0, -1, 0, 0},
                {0, 0, 0, 0, -1, 0, 0, -1, 0},
                {0, 0, 0, 0, 0, -1, 0, 0, -1},

                {1, 0, 0, 0, 1, 0, 0, 0, 0},
                {0, 0, 1, 0, 1, 0, 0, 0, 0},

                {1, 0, 0, 0, 0, 0, 0, 0, 1},
                {0, 0, 1, 0, 0, 0, 1, 0, 0},

                {0, 0, 0, 0, 1, 0, 0, 0, 1},
                {0, 0, 0, 0, 1, 0, 1, 0, 0},
            };

            double dataSetSaida[83][9] = {
                {0, 0, 0, 0, 1, 0, 0, 0, 0},
                {1, 0, 1, 0, 0, 0, 1, 0, 1},
                {0, 0, 0, 0, 1, 0, 0, 0, 0},
                {1, 0, 1, 0, 0, 0, 1, 0, 1},
                {0, 0, 0, 0, 1, 0, 0, 0, 0},
                {1, 0, 1, 0, 0, 0, 1, 0, 1},
                {0, 0, 0, 0, 1, 0, 0, 0, 0},
                {1, 0, 1, 0, 0, 0, 1, 0, 1},
                {0, 0, 0, 0, 1, 0, 0, 0, 0},
                {1, 0, 1, 0, 0, 0, 1, 0, 1},
                {0, 0, 0, 0, 1, 0, 0, 0, 0},
                {1, 0, 1, 0, 0, 0, 1, 0, 1},
                {0, 0, 0, 0, 1, 0, 0, 0, 0},
                {1, 0, 1, 0, 0, 0, 1, 0, 1},
                {0, 0, 0, 0, 1, 0, 0, 0, 0},
                {1, 0, 1, 0, 0, 0, 1, 0, 1},
                {0, 0, 0, 0, 1, 0, 0, 0, 0},

                {0, 0, 1, 0, 0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0, 1, 0, 0, 0},
                {0, 0, 0, 0, 0, 0, 0, 0, 1},

                {0, 1, 0, 0, 0, 0, 0, 0, 0},
                {0, 0, 0, 0, 1, 0, 0, 0, 0},
                {0, 0, 0, 0, 0, 0, 0, 1, 0},

                {1, 0, 0, 0, 0, 0, 0, 0, 0},
                {0, 0, 0, 1, 0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0, 0, 1, 0, 0},

                {0, 0, 0, 0, 0, 0, 1, 0, 0},
                {0, 0, 0, 0, 0, 0, 0, 1, 0},
                {0, 0, 0, 0, 0, 0, 0, 0, 1},

                {0, 0, 0, 1, 0, 0, 0, 0, 0},
                {0, 0, 0, 0, 1, 0, 0, 0, 0},
                {0, 0, 0, 0, 0, 1, 0, 0, 0},

                {1, 0, 0, 0, 0, 0, 0, 0, 0},
                {0, 1, 0, 0, 0, 0, 0, 0, 0},
                {0, 0, 1, 0, 0, 0, 0, 0, 0},

                {0, 0, 0, 0, 0, 0, 0, 0, 1},
                {0, 0, 0, 0, 0, 0, 1, 0, 0},

                {0, 0, 0, 0, 1, 0, 0, 0, 0},
                {0, 0, 0, 0, 1, 0, 0, 0, 0},

                {1, 0, 0, 0, 0, 0, 0, 0, 0},
                {0, 0, 1, 0, 0, 0, 0, 0, 0},

                {0, 0, 1, 0, 0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0, 1, 0, 0, 0},
                {0, 0, 0, 0, 0, 0, 0, 0, 1},

                {0, 1, 0, 0, 0, 0, 0, 0, 0},
                {0, 0, 0, 0, 1, 0, 0, 0, 0},
                {0, 0, 0, 0, 0, 0, 0, 1, 0},

                {1, 0, 0, 0, 0, 0, 0, 0, 0},
                {0, 0, 0, 1, 0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0, 0, 1, 0, 0},

                {0, 0, 0, 0, 0, 0, 1, 0, 0},
                {0, 0, 0, 0, 0, 0, 0, 1, 0},
                {0, 0, 0, 0, 0, 0, 0, 0, 1},

                {0, 0, 0, 1, 0, 0, 0, 0, 0},
                {0, 0, 0, 0, 1, 0, 0, 0, 0},
                {0, 0, 0, 0, 0, 1, 0, 0, 0},

                {1, 0, 0, 0, 0, 0, 0, 0, 0},
                {0, 1, 0, 0, 0, 0, 0, 0, 0},
                {0, 0, 1, 0, 0, 0, 0, 0, 0},

                {0, 0, 0, 0, 0, 0, 0, 0, 1},
                {0, 0, 0, 0, 0, 0, 1, 0, 0},

                {0, 0, 0, 0, 1, 0, 0, 0, 0},
                {0, 0, 0, 0, 1, 0, 0, 0, 0},

                {1, 0, 0, 0, 0, 0, 0, 0, 0},
                {0, 0, 1, 0, 0, 0, 0, 0, 0}
            };
            double activeParcial[83][9] = {
                {1, 1, 1, 1, 1, 1, 1, 1, 1},
                {1,0.1, 1, 0.1, 1, 0.1, 1, 0.1, 1},
                {1, 1, 1, 1, 1, 1, 1, 1, 1},
                {1,0.1, 1, 0.1, 1, 0.1, 1, 0.1, 1},
                {1, 1, 1, 1, 1, 1, 1, 1, 1},
                {1,0.1, 1, 0.1, 1, 0.1, 1, 0.1, 1},
                {1, 1, 1, 1, 1, 1, 1, 1, 1},
                {1,0.1, 1, 0.1, 1, 0.1, 1, 0.1, 1},
                {1, 1, 1, 1, 1, 1, 1, 1, 1},
                {1,0.1, 1, 0.1, 1, 0.1, 1, 0.1, 1},
                {1, 1, 1, 1, 1, 1, 1, 1, 1},
                {1,0.1, 1, 0.1, 1, 0.1, 1, 0.1, 1},
                {1, 1, 1, 1, 1, 1, 1, 1, 1},
                {1,0.1, 1, 0.1, 1, 0.1, 1, 0.1, 1},
                {1, 1, 1, 1, 1, 1, 1, 1, 1},
                {1,0.1, 1, 0.1, 1, 0.1, 1, 0.1, 1},
                {1, 1, 1, 1, 1, 1, 1, 1, 1},

                {1, 1, 1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1},
                {0.1, 0.1, 0.1, 1, 1, 1, 0.1, 0.1, 0.1},
                {0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 1, 1, 1},

                {1, 1, 1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1},
                {0.1, 0.1, 0.1, 1, 1, 1, 0.1, 0.1, 0.1},
                {0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 1, 1, 1},

                {1, 1, 1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1},
                {0.1, 0.1, 0.1, 1, 1, 1, 0.1, 0.1, 0.1},
                {0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 1, 1, 1},

                {1, 0.1, 0.1, 1, 0.1, 0.1, 1, 0.1, 0.1},
                {0.1, 1, 0.1, 0.1, 1, 0.1, 0.1, 1, 0.1},
                {0.1, 0.1, 1, 0.1, 0.1, 1, 0.1, 0.1, 1},

                {1, 0.1, 0.1, 1, 0.1, 0.1, 1, 0.1, 0.1},
                {0.1, 1, 0.1, 0.1, 1, 0.1, 0.1, 1, 0.1},
                {0.1, 0.1, 1, 0.1, 0.1, 1, 0.1, 0.1, 1},

                {1, 0.1, 0.1, 1, 0.1, 0.1, 1, 0.1, 0.1},
                {0.1, 1, 0.1, 0.1, 1, 0.1, 0.1, 1, 0.1},
                {0.1, 0.1, 1, 0.1, 0.1, 1, 0.1, 0.1, 1},

                {1, 0.1, 0.1, 0.1, 1, 0.1, 0.1, 0.1, 1},
                {0.1, 0.1, 1, 0.1, 1, 0.1, 1, 0.1, 0.1},

                {1, 0.1, 0.1, 0.1, 1, 0.1, 0.1, 0.1, 1},
                {0.1, 0.1, 1, 0.1, 1, 0.1, 1, 0.1, 0.1},

                {1, 0.1, 0.1, 0.1, 1, 0.1, 0.1, 0.1, 1},
                {0.1, 0.1, 1, 0.1, 1, 0.1, 1, 0.1, 0.1},


                {1, 1, 1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1},
                {0.1, 0.1, 0.1, 1, 1, 1, 0.1, 0.1, 0.1},
                {0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 1, 1, 1},

                {1, 1, 1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1},
                {0.1, 0.1, 0.1, 1, 1, 1, 0.1, 0.1, 0.1},
                {0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 1, 1, 1},

                {1, 1, 1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1},
                {0.1, 0.1, 0.1, 1, 1, 1, 0.1, 0.1, 0.1},
                {0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 1, 1, 1},

                {1, 0.1, 0.1, 1, 0.1, 0.1, 1, 0.1, 0.1},
                {0.1, 1, 0.1, 0.1, 1, 0.1, 0.1, 1, 0.1},
                {0.1, 0.1, 1, 0.1, 0.1, 1, 0.1, 0.1, 1},

                {1, 0.1, 0.1, 1, 0.1, 0.1, 1, 0.1, 0.1},
                {0.1, 1, 0.1, 0.1, 1, 0.1, 0.1, 1, 0.1},
                {0.1, 0.1, 1, 0.1, 0.1, 1, 0.1, 0.1, 1},

                {1, 0.1, 0.1, 1, 0.1, 0.1, 1, 0.1, 0.1},
                {0.1, 1, 0.1, 0.1, 1, 0.1, 0.1, 1, 0.1},
                {0.1, 0.1, 1, 0.1, 0.1, 1, 0.1, 0.1, 1},

                {1, 0.1, 0.1, 0.1, 1, 0.1, 0.1, 0.1, 1},
                {0.1, 0.1, 1, 0.1, 1, 0.1, 1, 0.1, 0.1},

                {1, 0.1, 0.1, 0.1, 1, 0.1, 0.1, 0.1, 1},
                {0.1, 0.1, 1, 0.1, 1, 0.1, 1, 0.1, 0.1},

                {1, 0.1, 0.1, 0.1, 1, 0.1, 0.1, 0.1, 1},
                {0.1, 0.1, 1, 0.1, 1, 0.1, 1, 0.1, 0.1}
            };
            const int quanttreinamento = 50; 
            int tamanhodataSet = 0;
            for (int i = 0; i < 83 && quanttreinamento != 0; i++) {
                adicionar_exemplo(&entradas, &alvos, &selectParcial, &tamanhodataSet, dataSetEntrada[i], dataSetSaida[i], activeParcial[i]);
            }
            
            
            treinar_rede(&rn1, entradas, alvos, 1, quanttreinamento, selectParcial, 0, threshold);
            treinar_rede(&rn2, entradas, alvos, 1, quanttreinamento, selectParcial, 1, threshold);

            do {
                numeroASerGuardado = opcoesDosJogadores[(contarRodada + setRodada) % 2];
                double estadoTableEntrada[9] = {};
                double estadoTableSaida[9] = {};
                double selectParcialActive[9] = {};

                for (int i = 0; i < 9; i++) {
                    if (tableJogoDaVelha[i/3][i%3][1] == 0) {
                        estadoTableEntrada[i] = 0;
                        selectParcialActive[i] = (contarRodada == 2) ? 0.8 : 1;
                    } else if (tableJogoDaVelha[i/3][i%3][0] == numeroASerGuardado) {
                        estadoTableEntrada[i] = 1;
                        selectParcialActive[i] = 1;
                    } else {
                        estadoTableEntrada[i] = -1;
                        selectParcialActive[i] = 1;
                    }
                }

                // 20% chance for the first move to be random
                if (contarRodada == 0 && ((rand() % 100) < (5 + 50/((epoca+1) * 2.0)))) {
                    do {
                        cordenadaLinha = rand() % 3 + 1;
                        cordenadaColuna = rand() % 3 + 1;
                    } while (tableJogoDaVelha[cordenadaLinha-1][cordenadaColuna-1][1] != 0);
                } else {
                    // 5% chance for a random move during the game
                    if (rand() % 100 < (2 + 30/((epoca+1) * 2.0))) {
                        do {
                            cordenadaLinha = rand() % 3 + 1;
                            cordenadaColuna = rand() % 3 + 1;
                        } while (tableJogoDaVelha[cordenadaLinha-1][cordenadaColuna-1][1] != 0);
                    } else {
                        rodadaIA(&cordenadaLinha, &cordenadaColuna, numeroASerGuardado, tableJogoDaVelha, (numeroASerGuardado == 'X') ? 0 : 1, threshold);
                    }
                }

                if (((tableJogoDaVelha[cordenadaLinha-1][cordenadaColuna-1][1] == 0 || 9 <= contarRodada) && (tableJogoDaVelha[cordenadaLinha-1][cordenadaColuna-1][0] != numeroASerGuardado)) && ((0 < cordenadaLinha && cordenadaLinha <= 3 ) && ((0 < cordenadaColuna && cordenadaColuna <= 3 )))) {
                    tableJogoDaVelha[cordenadaLinha-1][cordenadaColuna-1][0] = numeroASerGuardado;
                    tableJogoDaVelha[cordenadaLinha-1][cordenadaColuna-1][1] = 1;
                    contarRodada++;
                    caractersAnterior[1] = caractersAnterior[0];
                    caractersAnterior[0] = numeroASerGuardado;
                } else {            
                    (infinita == 0) ? printf("Escolha outra posição!!!\n\n") : printf("Escolha outra posição!!!\nNo modo infinito espere que todas sejam ocupadas para poder sobrepor!!!\n\n");
                }

                for (int i = 0; i < 9; i++) {
                    if (i == (cordenadaLinha - 1) * 3 + (cordenadaColuna - 1)) {
                        estadoTableSaida[i] = 1;
                        selectParcialActive[i] = 1;
                    } else {
                        estadoTableSaida[i] = 0;
                    }
                }

                if (numeroASerGuardado == 'X') {
                    adicionar_exemplo(&historicoRN1_entradas, &historicoRN1_alvos, &historicoRN1_selectParcial, &num_historicoRN1, estadoTableEntrada, estadoTableSaida, selectParcialActive);
                } else {
                    adicionar_exemplo(&historicoRN2_entradas, &historicoRN2_alvos, &historicoRN2_selectParcial, &num_historicoRN2, estadoTableEntrada, estadoTableSaida, selectParcialActive);
                }

                verificarVitoria(tableJogoDaVelha, vitoria);

                if ((infinita == 0 && contarRodada == 9)) {
                    break;
                }
                    
            } while ((cordenadaLinha > 0 || cordenadaColuna > 0) && vitoria[0] == 0);

            #define TX_EXPLORER 0.05
            #define TX_PENALTY 0.25

            if (vitoria[0] == 1) {
                printf("\nO jogador %c ganhou\n\n", vitoria[1]);
                if (vitoria[1] == 'X') {
                    for (int i = 0; i < num_historicoRN1; i++) {
                        for (int d = 0; d < 9; d++) {
                            if (historicoRN1_alvos[i][d] == 1) {
                                historicoRN1_alvos[i][d] = (num_historicoRN1 <= 3) ? 1.00 : 0.93; // Reward based on rounds
                            }
                        }
                        printf("Entrada:         Alvo:\n");
                        printf("------------- || +++++++++++++++++++++++++\n");
                        for (int k = 0; k < 18; k++) {
                            if ((k/3) % 2 == 0) {
                                int dd = k % 3 + ((k + 3) / 6) * 3;
                                printf("| %c ", historicoRN1_entradas[i][dd] == 1 ? '+' : (historicoRN1_entradas[i][dd] == -1 ? '-' : ' '));
                            }
                            if (((k + 3) % 6) == 0) {
                                printf("| || ");
                            }
                            if ((k/3) % 2 == 1) {
                                int dd = k % 3 + (k / 6) * 3;
                                printf("| %.2lf # %.1lf", historicoRN1_alvos[i][dd], historicoRN1_selectParcial[i][dd]);
                            }
                            if ((historicoRN1_alvos[i][k] >= 0) && ((k/3) % 2 == 1)) {
                                printf(" ");
                            }
                            if (((k + 1) % 6) == 0) {
                                printf("|\n");
                            }
                        }
                        printf("------------- || +++++++++++++++++++++++++\n");
                        printf("\n");
                        // adicionar_exemplo(&entradas, &alvos, &num_exemplos, historicoRN1_entradas[i], historicoRN1_alvos[i]);
                    }
                    printf("//////////////////////////////////////////\n");
                    for (int i = 0; i < num_historicoRN2; i++) {
                        for (int j = 0; j < 9; j++) {
                            if (historicoRN2_entradas[i][j] == 0) {
                                if (historicoRN2_alvos[i][j] == 1) {
                                    historicoRN2_alvos[i][j] = 0.00; // Encourage empty spaces
                                    historicoRN2_selectParcial[i][j] = TX_PENALTY;
                                } else {
                                    historicoRN2_alvos[i][j] = 0.85; // Encourage empty spaces
                                    historicoRN2_selectParcial[i][j] = TX_EXPLORER;
                                }
                            }
                            // if (historicoRN2_alvos[i][j] > 0) {
                            //     printf("Entrada: [%lf] Alvo: [%lf]\n", historicoRN2_entradas[i][j], historicoRN2_alvos[i][j]);
                            //     historicoRN2_alvos[i][j] = 1.0 - log(i + 1);
                            // }
                            if (i <= num_historicoRN2 - 1 && historicoRN1_entradas[i][j] >= 0) {
                                if (historicoRN1_alvos[i + (abs(num_historicoRN1-num_historicoRN2))][j] > 0) {
                                    historicoRN2_alvos[i][j] = threshold/2 + 0.5;
                                    historicoRN2_selectParcial[i][j] = 1;
                                } else {
                                    historicoRN2_alvos[i][j] += 0.05;
                                }
                            }
                        }
                        printf("Entrada:         Alvo:\n");
                        printf("------------- || +++++++++++++++++++++++++\n");
                        for (int k = 0; k < 18; k++) {
                            if ((k/3) % 2 == 0) {
                                int dd = k % 3 + ((k + 3) / 6) * 3;
                                printf("| %c ", historicoRN2_entradas[i][dd] == 1 ? '+' : (historicoRN2_entradas[i][dd] == -1 ? '-' : ' '));
                            }
                            if (((k + 3) % 6) == 0) {
                                printf("| || ");
                            }
                            if ((k/3) % 2 == 1) {
                                int dd = k % 3 + (k / 6) * 3;
                                printf("| %.2lf # %.1lf", historicoRN2_alvos[i][dd], historicoRN2_selectParcial[i][dd]);
                            }
                            if ((historicoRN2_alvos[i][k] >= 0) && ((k/3) % 2 == 1)) {
                                printf(" ");
                            }
                            if (((k + 1) % 6) == 0) {
                                printf("|\n");
                            }
                        }
                        printf("------------- || +++++++++++++++++++++++++\n");
                        // adicionar_exemplo(&entradas, &alvos, &num_exemplos, historicoRN2_entradas[i], historicoRN2_alvos[i]);
                    }
                    if (rn1.epoca <= epoca) treinar_rede(&rn1, historicoRN1_entradas, historicoRN1_alvos, num_historicoRN1, 7, historicoRN1_selectParcial, 0, threshold);
                    if (rn2.epoca <= epoca) treinar_rede(&rn2, historicoRN1_entradas, historicoRN1_alvos, num_historicoRN1, 3, historicoRN1_selectParcial, 1, threshold);
                    if (rn2.epoca <= epoca) treinar_rede(&rn2, historicoRN2_entradas, historicoRN2_alvos, num_historicoRN2, 5, historicoRN2_selectParcial, 1, threshold);
                    if (rn1.epoca <= epoca) treinar_rede(&rn1, historicoRN2_entradas, historicoRN2_alvos, num_historicoRN2, 2, historicoRN2_selectParcial, 0, threshold);
                } else {
                    for (int i = 0; i < num_historicoRN2; i++) {
                        for (int d = 0; d < 9; d++) {
                            if (historicoRN2_alvos[i][d] == 1) {
                                historicoRN2_alvos[i][d] = (num_historicoRN2 <= 3) ? 1.00 : 0.93; // Reward based on rounds
                                printf("%lf\n", historicoRN2_alvos[i][d]);
                            }
                        }
                        printf("Entrada:         Alvo:\n");
                        printf("------------- || ++++++++++++++++++++++++++++++\n");
                        for (int k = 0; k < 18; k++) {
                            if ((k/3) % 2 == 0) {
                                int dd = k % 3 + ((k + 3) / 6) * 3;
                                printf("| %c ", historicoRN2_entradas[i][dd] == 1 ? '+' : (historicoRN2_entradas[i][dd] == -1 ? '-' : ' '));
                            }
                            if (((k + 3) % 6) == 0) {
                                printf("| || ");
                            }
                            if ((k/3) % 2 == 1) {
                                int dd = k % 3 + (k / 6) * 3;
                                printf("| %.2lf # %.1lf ", historicoRN2_alvos[i][dd], historicoRN2_selectParcial[i][dd]);
                            }
                            if ((historicoRN2_alvos[i][k % 3 + ((k + 3) / 6) * 3] >= 0) && ((k/3) % 2 == 1)) {
                                printf(" ");
                            }
                            if (((k + 1) % 6) == 0) {
                                printf("|\n");
                            }
                        }
                        printf("------------- || ++++++++++++++++++++++++++++++\n");
                        
                        // adicionar_exemplo(&entradas, &alvos, &num_exemplos, historicoRN2_entradas[i], historicoRN2_alvos[i]);
                    }
                    printf("//////////////////////////////////////////\n");
                    for (int i = 0; i < num_historicoRN1; i++) {
                        for (int j = 0; j < 9; j++) {
                            if (historicoRN1_entradas[i][j] == 0) {
                                if (historicoRN1_alvos[i][j] == 1) {
                                    historicoRN1_alvos[i][j] = 0.0; // Encourage empty spaces
                                    historicoRN1_selectParcial[i][j] = TX_EXPLORER;
                                } else {
                                    historicoRN1_alvos[i][j] = threshold/2 + 0.5; // Encourage empty spaces
                                    historicoRN1_selectParcial[i][j] = TX_EXPLORER;
                                }
                            }
                            // if (historicoRN1_alvos[i][j] = 0) {
                            //     historicoRN1_alvos[i][j] = 1.0 - log(i + 1);
                            // }
                            if (i <= (num_historicoRN1 - 1) && historicoRN2_entradas[i][j] >= 0) {
                                if (historicoRN2_alvos[i + (abs(num_historicoRN1-num_historicoRN2))][j] > 0) {
                                    historicoRN1_alvos[i][j] = 0.95;
                                    historicoRN1_selectParcial[i][j] = 1;
                                } else if (historicoRN2_alvos[i + abs(num_historicoRN1-num_historicoRN2)][j] != 1) {
                                    historicoRN1_alvos[i][j] += 0.05;
                                }
                            }
                            printf("Entrada: [%lf] Alvo: [%lf]\n", historicoRN1_entradas[i][j], historicoRN1_alvos[i][j]);
                        }
                        printf("Entrada:         Alvo:\n");
                        printf("------------- || +++++++++++++++++++++++++\n");
                        for (int k = 0; k < 18; k++) {
                            if ((k/3) % 2 == 0) {
                                int dd = k % 3 + ((k + 3) / 6) * 3;
                                printf("| %c ", historicoRN1_entradas[i][dd] == 1 ? '+' : (historicoRN1_entradas[i][dd] == -1 ? '-' : ' '));
                            }
                            if (((k + 3) % 6) == 0) {
                                printf("| || ");
                            }
                            if ((k/3) % 2 == 1) {
                                int dd = k % 3 + (k / 6) * 3;
                                printf("| %.2lf # %.1lf ", historicoRN1_alvos[i][dd], historicoRN1_selectParcial[i][dd]);
                            }
                            if ((historicoRN1_alvos[i][k % 3 + ((k + 3) / 6) * 3] >= 0) && ((k/3) % 2 == 1)) {
                                printf("#");
                            }
                            if (((k + 1) % 6) == 0) {
                                printf("|\n");
                            }
                        }
                        printf("------------- || +++++++++++++++++++++++++\n");
                        printf("\n");
                        // adicionar_exemplo(&entradas, &alvos, &num_exemplos, historicoRN1_entradas[i], historicoRN1_alvos[i]);
                    }
                    if (rn1.epoca <= epoca) treinar_rede(&rn1, historicoRN1_entradas, historicoRN1_alvos, num_historicoRN1, 7, historicoRN1_selectParcial, 0, threshold);
                    if (rn2.epoca <= epoca) treinar_rede(&rn2, historicoRN1_entradas, historicoRN1_alvos, num_historicoRN1, 3, historicoRN1_selectParcial, 1, threshold);
                    if (rn2.epoca <= epoca) treinar_rede(&rn2, historicoRN2_entradas, historicoRN2_alvos, num_historicoRN2, 5, historicoRN2_selectParcial, 1, threshold);
                    if (rn1.epoca <= epoca) treinar_rede(&rn1, historicoRN2_entradas, historicoRN2_alvos, num_historicoRN2, 5, historicoRN2_selectParcial, 0, threshold);
                }

                if (threshold < 0.9) {
                    threshold += 0.1;
                }

            } else if (contarRodada == 9) {
                printf("Deu Velha!!!\n\n");

                if (threshold > 0.1) {
                    threshold -= 0.025;
                }
            }
            if (cordenadaLinha <= 0 || cordenadaColuna <= 0) {
                printf("\nVocê escolheu sair!!!\n\n");
            }

            // Treinar a rede neural após cada jogo
            // treinar_rede(&rn1, entradas, alvos, num_exemplos, 1);
            // treinar_rede(&rn2, entradas, alvos, num_exemplos, 1);

            // Libere a memória alocada para os exemplos de treinamento
            for (int i = 0; i < num_exemplos; i++) {
                free(entradas[i]);
                free(alvos[i]);
            }
            free(entradas);
            free(alvos);

            // Libere a memória alocada para os históricos
            for (int i = 0; i < num_historicoRN1; i++) {
                free(historicoRN1_entradas[i]);
                free(historicoRN1_alvos[i]);
            }
            free(historicoRN1_entradas);
            free(historicoRN1_alvos);

            for (int i = 0; i < num_historicoRN2; i++) {
                free(historicoRN2_entradas[i]);
                free(historicoRN2_alvos[i]);
            }
            free(historicoRN2_entradas);
            free(historicoRN2_alvos);
        }

        // Salve o estado das redes neurais
        if (rn1.epoca <= epoca) {
            salvar_rede(&rn1, "./Jogo da Velha Inteligente/Models/rede_neural1.bin");
            rn1.epoca++;
        }
        if (rn2.epoca <= epoca) {
            salvar_rede(&rn2, "./Jogo da Velha Inteligente/Models/rede_neural2.bin");
            rn2.epoca++;
        }
        printf("Round salvo!!!\n");
    }

    // // Teste a rede neural
    // double entrada_teste[9] = {0, 0, 0, 0, -1, 0, 0, -1, 0};
    // propagacao_frente(&rn1, entrada_teste);

    printf("Saídas da rede neural 1 após treinamento:\n");
    for (int i = 0; i < 9; i++) {
        printf("%f ", rn1.camada_saida.neuronios[i].valor);
    }
    printf("\n");

    printf("Saídas da rede neural 2 após treinamento:\n");
    for (int i = 0; i < 9; i++) {
        printf("%f ", rn2.camada_saida.neuronios[i].valor);
    }
    printf("\n");

    return 0;
}