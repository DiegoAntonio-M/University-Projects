#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


typedef struct ponto {
    char ID[3];
    double x;
    double y;
} ponto;

typedef struct planoCartesiano {
    int pointCreate;
    int quantDePontos;
    ponto *pontos;
    int entropyLevel[3];
} planoCartesiano;


int completarCriacao(planoCartesiano *plano, int quantPonto) {
    if (quantPonto < 1) quantPonto = 1;
    plano->pontos = calloc(quantPonto, sizeof(ponto));
    if (plano->pontos == NULL) {
        printf("Erro ao alocar memória!\n");
        exit(1);
    }
    return quantPonto;
}

int aclocarPonto(planoCartesiano *plano, int quantAdd) {
    (quantAdd < 1) ? quantAdd : (quantAdd = 1);
    int memoriaOriTemp = plano->quantDePontos;
    plano->quantDePontos += quantAdd;
    plano->pontos = realloc(plano->pontos, sizeof(ponto)*plano->quantDePontos);
    if (plano->pontos == NULL) {
        printf("Falha ao alocar memória.\n");
        plano->quantDePontos = memoriaOriTemp;  // Restaurar a quantidade original de pontos
        return -1;  
    }
    for (int i = 0; i < (plano->quantDePontos) - memoriaOriTemp; i++){
        plano->pontos[memoriaOriTemp + i].ID[0] = 0;
        plano->pontos[memoriaOriTemp + i].ID[1] = 0;
        plano->pontos[memoriaOriTemp + i].x = 0;
        plano->pontos[memoriaOriTemp + i].y = 0;
    }
    return 0;
}

void desfragmentar(planoCartesiano *plano) {
    int writing = 0;

    for (int reading  = 1; reading < plano->quantDePontos; reading++) {
        printf("W(%d): [%s]\n", writing, plano->pontos[writing].ID);  //Debug
        if (plano->pontos[writing].ID[0] == 0 && plano->pontos[writing].ID[1] == 0) {
            printf("W(%d): [%s]\n", writing, plano->pontos[writing].ID); //Debug
            printf("R(%d): [%s]\n", reading, plano->pontos[reading].ID); //Debug
            if (plano->pontos[reading].ID[0] != 0 && plano->pontos[reading].ID[1] != 0) {
                printf("R(%d): [%s]\n", reading, plano->pontos[reading].ID); //Debug
                printf("W(%d) <- R(%d): [%s] <- [%s]\n",writing, reading, plano->pontos[writing], plano->pontos[reading].ID); //Debug
                plano->pontos[writing] = plano->pontos[reading];
                printf("W(%d) <- R(%d): [%s] <- [%s]\n",writing, reading, plano->pontos[writing], plano->pontos[reading].ID); //Debug
                writing++;

                plano->pontos[reading].ID[0] = 0;
                plano->pontos[reading].ID[1] = 0;
                plano->pontos[reading].x = 0;
                plano->pontos[reading].y = 0;
            }
        } else {
            writing++;
        }
        printf("\n");
    }

    plano->quantDePontos = writing;

    aclocarPonto(plano, 0);

    plano->entropyLevel[0] = 0;
    plano->entropyLevel[1] = 0;
    plano->entropyLevel[2] = 0;
    
}

int calculoEntropy(planoCartesiano *plano, int limite, int firstCreatPoint) {

    if(firstCreatPoint == -1) firstCreatPoint = plano->pointCreate;

    if (plano->pontos[plano->pointCreate].ID[0] == 0 && plano->pontos[plano->pointCreate].ID[1] == 0) {
        plano->entropyLevel[0]++;

        if (0 < plano->pointCreate) {
            if (plano->pontos[plano->pointCreate-1].ID[0] != 0 && plano->pontos[plano->pointCreate-1].ID[1] != 0) {
                plano->entropyLevel[1]++;
            }
        }
        if (plano->pointCreate < plano->quantDePontos-1) {
            if (plano->pontos[plano->pointCreate+1].ID[0] != 0 && plano->pontos[plano->pointCreate+1].ID[1] != 0) {
                plano->entropyLevel[1]++;
            }
        }
    } else {
        if (plano->entropyLevel[0] > 0) plano->entropyLevel[0]--;
        if (0 < plano->pointCreate) {
            if (plano->pontos[plano->pointCreate-1].ID[0] != 0 && plano->pontos[plano->pointCreate-1].ID[1] != 0) {
                if (plano->entropyLevel[1] > 0) plano->entropyLevel[1]--;
            }
        }
        if (plano->pointCreate < plano->quantDePontos-1) {
            if (plano->pontos[plano->pointCreate+1].ID[0] != 0 && plano->pontos[plano->pointCreate+1].ID[1] != 0) {
                if (plano->entropyLevel[1] > 0) plano->entropyLevel[1]--;
            }
        }
    }

    int resultCalculo = plano->entropyLevel[0] * plano->entropyLevel[1];
    if (resultCalculo == 0 && plano->entropyLevel[2] > 0) resultCalculo = -1;
    plano->entropyLevel[2] += resultCalculo;

    if (limite <= plano->entropyLevel[2]) {
        desfragmentar(plano);
    }
    plano->pointCreate = firstCreatPoint;
}

int menu() {
    int option = 0;
    int quantOptions = 0;
    do {
        setbuf(stdin, NULL);
        option = 0;

        fputs("\nSelecione: \n", stdout);
        char options[][40] = {
            "Inserir Ponto",
            "Excluir Ponto",
            "Calcular distancia entre 2 pontos",
            "Sair"
        };
        int i = 0;
        quantOptions = sizeof(options) / sizeof(options[0]);
        for (i = 0; i < quantOptions; i++) {
            char pontuacao = ' ';
            printf("%d - %s%c\n", (i + 1), options[i], (i + 1 == quantOptions) ? (pontuacao = '.') : (pontuacao = ';'));
        }
        fputs(">>> ", stdout);
        char c[2];
        fgets(c, sizeof(c), stdin);
        option = atoi(c);
        if (option == quantOptions) {
            option = -1;
        }

    } while (!((1 <= option && option <= quantOptions) || (option == -1)));

    return option;
}

int isInputEmpty(char *input) {
    return input[0] == '\n' || input[0] == '\0';
}

void clearBuffer() {
    setbuf(stdin, NULL);
}

void fgetsCleanedByStdin(char *out, int save, bool isTrim) {
    char c;
    if (isTrim == true) save--;
    for (int i = 0; ((c = fgetchar()) != '\n') && (c != EOF || c != '\000'); i++) {
        if (i < save) {
            out[i] = c;
        }
    }
    if (isTrim == true) out[save] = 0;
}

ponto createPoint () {
    clearBuffer();
    ponto newPoint = {};
    char x[11] = {};
    char y[11] = {};
    bool canOut = false;

 do {
        
        fputs("Escreva um nome para o ponto [Max.2 Caract]: ", stdout);
        fgetsCleanedByStdin(newPoint.ID, sizeof(newPoint.ID), true);
        if ((canOut = isInputEmpty(newPoint.ID))) {
            printf("Nome inválido, tente novamente.\n");
        }
    } while (canOut);

    do {
        fputs("Defina o valor para o eixo X: ", stdout);
        fgetsCleanedByStdin(x, sizeof(x), true);
        clearBuffer();
        if ((canOut = isInputEmpty(x))) {
            printf("Valor de X inválido, tente novamente.\n");
        }
    } while (canOut);
    newPoint.x = atof(x);

    do {
        fputs("Defina o valor para o eixo Y: ", stdout);
        fgetsCleanedByStdin(y, sizeof(y), true);
        clearBuffer();
        if ((canOut = isInputEmpty(y))) {
            printf("Valor de Y inválido, tente novamente.\n");
        }
    } while (canOut);
    newPoint.y = atof(y);

    return newPoint;
}

int addPoint (planoCartesiano *plano) {

    int test1 = plano->pontos[plano->pointCreate].ID[0];
    int test2 = plano->pontos[plano->pointCreate].ID[1];
    
    navegarProximo:
    if (plano->pointCreate < plano->quantDePontos) {
        printf("%d%d ", (plano->pontos + plano->pointCreate)->ID[0], (plano->pontos + plano->pointCreate)->ID[1]);
        if ((plano->pontos[plano->pointCreate].ID[0] == 0) && plano->pontos[plano->pointCreate].ID[1] == 0) {
                plano->pontos[plano->pointCreate] = createPoint();
        } else {

            plano->pointCreate++;
            goto navegarProximo;
        }
    } else {
        aclocarPonto(plano, 1);
        goto navegarProximo;
    }
    calculoEntropy(plano, 100, -1);
}

int resultPositionSearch (planoCartesiano *plano, char search[2]) {

    for (int i = 0; i < plano->quantDePontos; i++) {
        if (strcmp(plano->pontos[i].ID, search) == 0) {
            return i;
        }
    }
    return -1;
}

int deletePoint (planoCartesiano * plano) {
    clearBuffer();
    char idName[3] = {};
    int positionSearch = -1;

    fputs("Escolha o nome do Ponto para Excluir: ", stdout);
    fgetsCleanedByStdin(idName, sizeof(idName), true);

    positionSearch = resultPositionSearch(plano, idName);
    if (positionSearch != -1) {
        plano->pontos[positionSearch].ID[0] = 0;
        plano->pontos[positionSearch].ID[1] = 0;

    } else {
        fputs("### Não foi possível encontrar correspondencia para esse ponto ###\n\n", stdout);
    }
    int minPointCreat = (positionSearch < plano->pointCreate) ? positionSearch : plano->pointCreate;
    plano->pointCreate = positionSearch;
    calculoEntropy(plano, 100, minPointCreat);

}

int main() {

    planoCartesiano planoA = {};

    printf("\n\n");

    planoA.quantDePontos = completarCriacao(&planoA, 2);

    for (int i = 0; i < planoA.quantDePontos; i++) {
        printf("[%d%d] ^ [%d%d]  ", (planoA.pontos + i)->ID[0], (planoA.pontos + i)->ID[1], (planoA.pontos + planoA.pointCreate)->ID[0], (planoA.pontos + planoA.pointCreate)->ID[1]);
    }
    int sair = 0;
    do {
        switch (menu()) {
        case 1:
            addPoint(&planoA);
        for (int i = 0; i < planoA.quantDePontos; i++) {
            printf("[%s] ", (planoA.pontos + i)->ID);
        }
        fputs("\n\nA entropia eh: ", stdout);
        for (int i = 0; i < 3; i++) {
            printf("[%d] ", *(planoA.entropyLevel + i));

        }
            break;
        case 2:
            deletePoint(&planoA);
        for (int i = 0; i < planoA.quantDePontos; i++) {
            printf("[%s] ", (planoA.pontos + i)->ID);
        }
        fputs("\n\nA entropia eh: ", stdout);
        for (int i = 0; i < 3; i++){
            printf("[%d] ",*(planoA.entropyLevel + i));
        }
            break;
        case 3:
            /* code */
            break;
        case -1:
            sair = 1;
            break;
        default:
            break;
        }
        fputs("\n\n",stdout);
    } while (sair == 0);
    


    return 0;
}
