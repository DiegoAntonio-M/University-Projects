# include <stdlib.h>
# include <math.h>
# include <stdio.h>
#include <time.h>
#include <sys/time.h>

#define TAXA_APRENDIZADO 0.001
typedef struct {
    double valor;
    double *pesos;
    double bias;
} Neuronio;

typedef struct {
    int tamanho;
    Neuronio *neuronios;
} Camada;

typedef struct {
    int epoca;
    int quantentradas;
    int quantsaida;
    int num_camadas_ocultas;
    Camada camada_entrada;
    Camada *camadas_ocultas;
    Camada camada_saida;
} RedeNeural;

// double sigmoid(double x) {
//     return 1 / (1 + exp(-x));
// }

double sigmoid(double x) {
    return fmax(0, x);
}

// double derivada_sigmoid(double x) {
//     return x * (1 - x);
// }

double derivada_sigmoid(double x) {
    if (x > 0) {
        return 1.0;
    } else if (x < 0) {
        return 0.0;
    } else {
        // Dependendo da implementação, pode ser 0 ou 1
        return 0.0; // ou return 1.0;
    }
}

void liberar_rede(RedeNeural *rn) {
    // Liberar memória da camada de entrada
    free(rn->camada_entrada.neuronios);

    // Liberar memória das camadas ocultas
    for (int i = 0; i < rn->num_camadas_ocultas; i++) {
        for (int j = 0; j < rn->camadas_ocultas[i].tamanho; j++) {
            free(rn->camadas_ocultas[i].neuronios[j].pesos);
        }
        free(rn->camadas_ocultas[i].neuronios);
    }
    free(rn->camadas_ocultas);

    // Liberar memória da camada de saída
    for (int i = 0; i < rn->camada_saida.tamanho; i++) {
        free(rn->camada_saida.neuronios[i].pesos);
    }
    free(rn->camada_saida.neuronios);
}

void propagacao_frente(RedeNeural *rn, double *entrada) {
    for (int i = 0; i < rn->quantentradas; i++) {
        rn->camada_entrada.neuronios[i].valor = entrada[i];
    }

    for (int i = 0; i < rn->num_camadas_ocultas; i++) {
        Camada *camada = &rn->camadas_ocultas[i];
        Camada *camada_anterior = (i == 0) ? &rn->camada_entrada : &rn->camadas_ocultas[i - 1];
        for (int j = 0; j < camada->tamanho; j++) {
            camada->neuronios[j].valor = camada->neuronios[j].bias;
            for (int k = 0; k < camada_anterior->tamanho; k++) {
                camada->neuronios[j].valor += camada_anterior->neuronios[k].valor * camada->neuronios[j].pesos[k];
                printf("Camada %d, Neurônio %d, Valor: [%lf] <- [%lf] * [%lf]\n", i, j, camada->neuronios[j].valor, camada_anterior->neuronios[k].valor, camada->neuronios[j].pesos[k]);
            }
            printf("Camada %d, Neurônio %d, Sigmoid(%lf)", i, j, camada->neuronios[j].valor);
            camada->neuronios[j].valor = sigmoid(camada->neuronios[j].valor);
            printf(" --> [%lf]\n", camada->neuronios[j].valor);
        }
    }

    Camada *ultima_camada_oculta = &rn->camadas_ocultas[rn->num_camadas_ocultas - 1];
    for (int i = 0; i < rn->quantsaida; i++) {
        rn->camada_saida.neuronios[i].valor = rn->camada_saida.neuronios[i].bias;
        for (int j = 0; j < ultima_camada_oculta->tamanho; j++) {
            rn->camada_saida.neuronios[i].valor += ultima_camada_oculta->neuronios[j].valor * rn->camada_saida.neuronios[i].pesos[j];
            printf("Camada de Saída, Neurônio %d, Valor: [%lf] <- [%lf] * [%lf]\n", i, rn->camada_saida.neuronios[i].valor, ultima_camada_oculta->neuronios[j].valor, rn->camada_saida.neuronios[i].pesos[j]);
        }
        printf("Camada de Saída, Neurônio %d, Sigmoid(%lf)", i, rn->camada_saida.neuronios[i].valor);
        rn->camada_saida.neuronios[i].valor = sigmoid(rn->camada_saida.neuronios[i].valor);
        printf(" -> [%lf]\n",rn->camada_saida.neuronios[i].valor);
    }
}

void retropropagacao(RedeNeural *rn, double *entrada, double *alvo, double *seletorCorreçãoParcial) {
    double erros_saida[rn->quantsaida];
    double **erros_ocultos = (double **)calloc(rn->num_camadas_ocultas, sizeof(double *));
    for (int i = 0; i < rn->num_camadas_ocultas; i++) {
        erros_ocultos[i] = (double *)calloc(rn->camadas_ocultas[i].tamanho, sizeof(double));
    }

    // Calcular erro da camada de saída
    for (int i = 0; i < rn->quantsaida; i++) {
        erros_saida[i] = (rn->camada_saida.neuronios[i].valor - alvo[i]) * seletorCorreçãoParcial[i];
        printf("Erro de Saída %d: %lf\n", i, erros_saida[i]);
    }

    // Calcular erro das camadas ocultas
    for (int i = rn->num_camadas_ocultas - 1; i >= 0; i--) {
        Camada *camada = &rn->camadas_ocultas[i];
        for (int j = 0; j < camada->tamanho; j++) {
            erros_ocultos[i][j] = 0.0;
            if (i == rn->num_camadas_ocultas - 1) {
                for (int k = 0; k < rn->quantsaida; k++) {
                    erros_ocultos[i][j] += erros_saida[k] * rn->camada_saida.neuronios[k].pesos[j];
                }
            } else {
                for (int k = 0; k < rn->camadas_ocultas[i + 1].tamanho; k++) {
                    erros_ocultos[i][j] += erros_ocultos[i + 1][k] * rn->camadas_ocultas[i + 1].neuronios[k].pesos[j];
                }
            }
            erros_ocultos[i][j] *= derivada_sigmoid(camada->neuronios[j].valor);
            printf("Erro Oculto %d, Camada %d: %lf\n", j, i, erros_ocultos[i][j]);
        }
    }

    // Atualizar pesos e bias da camada de saída
    for (int i = 0; i < rn->quantsaida; i++) {
        for (int j = 0; j < rn->camadas_ocultas[rn->num_camadas_ocultas - 1].tamanho; j++) {
            printf("Atualizando Peso Saída %d, Peso %d: %lf -> ", i, j, rn->camada_saida.neuronios[i].pesos[j]);
            rn->camada_saida.neuronios[i].pesos[j] -= TAXA_APRENDIZADO * erros_saida[i] * rn->camadas_ocultas[rn->num_camadas_ocultas - 1].neuronios[j].valor;
            printf("[%lf]\n", rn->camada_saida.neuronios[i].pesos[j]);
        }
        printf("Atualizando Bias Saída %d: %lf -> ", i, rn->camada_saida.neuronios[i].bias);
        rn->camada_saida.neuronios[i].bias -= TAXA_APRENDIZADO * erros_saida[i];
        printf("[%lf]\n", rn->camada_saida.neuronios[i].bias);
    }

    // Atualizar pesos e bias das camadas ocultas
    for (int i = rn->num_camadas_ocultas - 1; i >= 0; i--) {
        Camada *camada = &rn->camadas_ocultas[i];
        for (int j = 0; j < camada->tamanho; j++) {
            for (int k = 0; k < (i == 0 ? rn->quantentradas : rn->camadas_ocultas[i - 1].tamanho); k++) {
                printf("Atualizando Peso Oculto %d, Camada %d, Peso %d: %lf ->", j, i, k, camada->neuronios[j].pesos[k]);
                camada->neuronios[j].pesos[k] -= TAXA_APRENDIZADO * erros_ocultos[i][j] * (i == 0 ? entrada[k] : rn->camadas_ocultas[i - 1].neuronios[k].valor);
                printf("[%lf]\n", camada->neuronios[j].pesos[k]);
            }
            printf("Atualizando Bias Oculto %d, Camada %d: %lf -> ", j, i, camada->neuronios[j].bias);
            camada->neuronios[j].bias -= TAXA_APRENDIZADO * erros_ocultos[i][j];
            printf("[%lf]\n", camada->neuronios[j].bias);
        }
    }

    for (int i = 0; i < rn->num_camadas_ocultas; i++) {
        free(erros_ocultos[i]);
    }
    free(erros_ocultos);
}

void carregar_rede(RedeNeural *rn, const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        perror("Erro ao abrir o arquivo para carregar");
        return;
    }

    fread(&rn->epoca, sizeof(int), 1, file);
    fread(&rn->quantentradas, sizeof(int), 1, file);
    fread(&rn->quantsaida, sizeof(int), 1, file);
    fread(&rn->num_camadas_ocultas, sizeof(int), 1, file);

    rn->camada_entrada.tamanho = rn->quantentradas;
    rn->camada_entrada.neuronios = (Neuronio *)calloc(rn->quantentradas, sizeof(Neuronio));

    rn->camadas_ocultas = (Camada *)calloc(rn->num_camadas_ocultas, sizeof(Camada));

    for (int i = 0; i < rn->num_camadas_ocultas; i++) {
        fread(&rn->camadas_ocultas[i].tamanho, sizeof(int), 1, file);
        rn->camadas_ocultas[i].neuronios = (Neuronio *)calloc(rn->camadas_ocultas[i].tamanho, sizeof(Neuronio));
        for (int j = 0; j < rn->camadas_ocultas[i].tamanho; j++) {
            fread(&rn->camadas_ocultas[i].neuronios[j].valor, sizeof(double), 1, file);
            fread(&rn->camadas_ocultas[i].neuronios[j].bias, sizeof(double), 1, file);
            rn->camadas_ocultas[i].neuronios[j].pesos = (double *)calloc((i == 0 ? rn->quantentradas : rn->camadas_ocultas[i - 1].tamanho), sizeof(double));
            fread(rn->camadas_ocultas[i].neuronios[j].pesos, sizeof(double), (i == 0 ? rn->quantentradas : rn->camadas_ocultas[i - 1].tamanho), file);
            for (int k = 0; k < (i == 0 ? rn->quantentradas : rn->camadas_ocultas[i - 1].tamanho); k++) {
                printf("Camada %d, Neurônio %d, Valor: %lf, Peso: %lf\n", i, j, rn->camadas_ocultas[i].neuronios[j].valor, rn->camadas_ocultas[i].neuronios[j].pesos[k]);
            }
        }
    }

    rn->camada_saida.tamanho = rn->quantsaida;
    rn->camada_saida.neuronios = (Neuronio *)calloc(rn->quantsaida, sizeof(Neuronio));
    for (int i = 0; i < rn->quantsaida; i++) {
        fread(&rn->camada_saida.neuronios[i].valor, sizeof(double), 1, file);
        fread(&rn->camada_saida.neuronios[i].bias, sizeof(double), 1, file);
        rn->camada_saida.neuronios[i].pesos = (double *)calloc(rn->camadas_ocultas[rn->num_camadas_ocultas - 1].tamanho, sizeof(double));
        fread(rn->camada_saida.neuronios[i].pesos, sizeof(double), rn->camadas_ocultas[rn->num_camadas_ocultas - 1].tamanho, file);
        for (int j = 0; j < rn->camadas_ocultas[rn->num_camadas_ocultas - 1].tamanho; j++) {
            printf("Camada de Saída, Neurônio %d, Valor: %lf, Peso: %lf\n", i, rn->camada_saida.neuronios[i].valor, rn->camada_saida.neuronios[i].pesos[j]);
        }
    }

    fclose(file);
}

void rodadaIA(int *coordL, int * coordC, char numeroASerGuardado, char tableJogoDaVelha[3][3][2], int opRN, double threshold) {
    double tableEntrada[9] = {};
    double tableSaida[9] = {};

    for (int i = 0; i < 9; i++) {
        if (tableJogoDaVelha[i/3][i%3][1] == 0) {
            tableEntrada[i] = 0;
        } else if (tableJogoDaVelha[i/3][i%3][0] == numeroASerGuardado) {
            tableEntrada[i] = 1;
        } else {
            tableEntrada[i] = -1;
        }
    }

    if (opRN == 0) {

        RedeNeural rn;
        carregar_rede(&rn, "./Jogo da Velha Inteligente/Models/rede_neural1.bin");
        propagacao_frente(&rn, tableEntrada);

        for (int i = 0; i < 9; i++) {
            printf("%f ", rn.camada_saida.neuronios[i].valor);
            tableSaida[i] = rn.camada_saida.neuronios[i].valor;
        }

        liberar_rede(&rn);
    } else {

        RedeNeural rn2;
        carregar_rede(&rn2, "./Jogo da Velha Inteligente/Models/rede_neural2.bin");
        propagacao_frente(&rn2, tableEntrada);

        for (int i = 0; i < 9; i++) {
            printf("%f ", rn2.camada_saida.neuronios[i].valor);
            tableSaida[i] = rn2.camada_saida.neuronios[i].valor;
        }
        liberar_rede(&rn2);
    }

    int maiorIndex = -1;
    int indices[9];
    int count = 0;
    double contraste = 1.00;
    double media = 0.00;
    double contar = 0.00;

    double sum = 0.0;

    for (int i = 0; i < 9; i++) {
        if (tableEntrada[i] == 0 && tableSaida[i] > threshold) {
            sum += tableSaida[i];
            contar++;
        }
    }
    media = sum / contar;
    if (sum > 0.0) {
        struct timeval tv;
        gettimeofday(&tv, NULL);
        srand(tv.tv_sec * 1000 + tv.tv_usec / 1000);
        double randomValue = ((double)rand() / RAND_MAX) * sum;
        double desvio = 0.0;

        for (int i = 0; i < 9; i++) {
            if (tableEntrada[i] == 0 && tableSaida[i] > threshold) {
                desvio = (tableSaida[i] - media) * contraste;
                randomValue -= (media + desvio);
                if (randomValue <= 0.0) {
                    maiorIndex = i;
                    break;
                }
            }
        }
    } else {
        double maior = -1;
        for (int i = 0; i < 9; i++) {
            if (tableEntrada[i] == 0 && tableSaida[i] > maior) {
                maior = tableSaida[i];
                maiorIndex = i;
            }
        }
    }

    *coordL = (int)(maiorIndex / 3) + 1;
    *coordC = (int)(maiorIndex % 3) + 1;
}