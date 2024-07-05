# include <stdio.h>
#include <stdbool.h>

int main () {

    char tableSudoko[3][3][2] = {{{' ',0},{' ',0},{' ',0}},{{' ',0},{' ',0},{' ',0}},{{' ',0},{' ',0},{' ',0}}};
    int cordenadaLinha = 0;
    int cordenadaColuna = 0;
    char numeroASerGuardado = 'A';
    char vitoria[2] = {0,' '};
    int contarRodada = 0;
    bool configuração[3] = {0};
    char opcoesDosJogadores[2] = {'X','O'};
    char caractersAnterior[2] = { 0,0};

    printf("Configure:\nMultCaracter[0|1], Infinita[0|1]: ");
    scanf("%d %d", &configuração[0], &configuração[1]);

    do {
        if (configuração[0] == 1) {
            int auxiliar = 0;
            do {
                cordenadaLinha = -1;
                cordenadaColuna = -1;
                numeroASerGuardado = -1;
                auxiliar = 0;
                printf("Escreva a coordenada e o caracter para escrever: ");
                scanf("%d %d %c", &cordenadaLinha, &cordenadaColuna, &numeroASerGuardado);

                for (int i = 0; i < 2; i++) {
                    if ( numeroASerGuardado == caractersAnterior[i]) {
                        auxiliar = 1;
                        printf("\nUltilize outro caracter que não foi usado nas ultimas 2 rodadas. [");
                        for (int ii = 0; (ii < 2) && (ii < contarRodada); ii++) {
                            printf("%c", caractersAnterior[ii]);
                            if (ii == 0 && contarRodada != 1) {
                                printf(", ");
                            }                            
                        }
                        printf("].\n\n");                   
                    } 
                }

            } while (auxiliar == 1);

                
        } else {   
            numeroASerGuardado = opcoesDosJogadores[contarRodada % 2];     
            printf("\nEscreva a coordenada para escrever o jogador %c: ", numeroASerGuardado);
            scanf("%d %d", &cordenadaLinha, &cordenadaColuna);  
        }
        
        // printf("\n Escreva o valor a ser guradado: ");
        // scanf("%d", &numeroASerGuardado);

        printf("\n");

        if (((tableSudoko[cordenadaLinha-1][cordenadaColuna-1][1] == 0 || 9 <= contarRodada) && (tableSudoko[cordenadaLinha-1][cordenadaColuna-1][0] != numeroASerGuardado)) && ((0 < cordenadaLinha && cordenadaLinha <= 3 ) && ((0 < cordenadaColuna && cordenadaColuna <= 3 )))) {
            tableSudoko[cordenadaLinha-1][cordenadaColuna-1][0] = numeroASerGuardado;
            tableSudoko[cordenadaLinha-1][cordenadaColuna-1][1] = 1;
            contarRodada++;
            caractersAnterior[1] = caractersAnterior[0];
            caractersAnterior[0] = numeroASerGuardado;            
        } else {            
            (configuração[1] == 0) ? printf("Escolha outra posição!!!\n\n") : printf("Escolha outra posição!!!\nNo modo infinito espere que todas sejam ocupadas para poder sobrepor!!!\n\n");
        }

        for (int i = 0; i < 3; i++) {

            // if (i == 0 ) {
                printf("-------------\n");
            // }

            for (int ii = 0; ii < 3; ii++) {
                
                printf("|");    
                printf(" %c ", tableSudoko[i][ii][0]);

                if (ii == 2) {
                    printf("|");
                }
                
            }
            printf("\n");

            if (i == 2) {
                printf("-------------\n");
            }           
        }

        for (int i = 0; i < 3; i++) {

            if ((tableSudoko[i][0][0] == tableSudoko[i][1][0]) && (tableSudoko[i][1][0] == tableSudoko[i][2][0])) {
                if (tableSudoko[i][0][1] == 1 && tableSudoko[i][1][1] == 1 && tableSudoko[i][2][1] == 1) {
                    vitoria[0] = 1;
                    vitoria[1] = tableSudoko[i][2][0];
                }  
            }            
        }

        for (int i = 0; i < 3; i++) {

            if ((tableSudoko[0][i][0] == tableSudoko[1][i][0]) && (tableSudoko[1][i][0] == tableSudoko[2][i][0])) {
                if (tableSudoko[0][i][1] == 1 && tableSudoko[1][i][1] == 1 && tableSudoko[2][i][1] == 1) {
                    vitoria[0] = 1;
                    vitoria[1] = tableSudoko[2][i][0];
                }  
            }            
        }

        if (tableSudoko[0][0][0] == tableSudoko[1][1][0] && tableSudoko[1][1][0] == tableSudoko[2][2][0]) {
            if (tableSudoko[0][0][1] == 1 && tableSudoko[1][1][1] == 1 && tableSudoko[2][2][1] == 1) {
                    vitoria[0] = 1;
                    vitoria[1] = tableSudoko[2][2][0];
            }            
        }
        if (tableSudoko[0][2][0] == tableSudoko[1][1][0] && tableSudoko[1][1][0] == tableSudoko[2][0][0]) {
            if (tableSudoko[0][2][1] == 1 && tableSudoko[1][1][1] == 1 && tableSudoko[2][0][1] == 1) {
                    vitoria[0] = 1;
                    vitoria[1] = tableSudoko[2][0][0];
            }            
        }
        
        printf("\n");
        if ((configuração[1] == 0 && contarRodada == 9)) {
            break;
        }
            
    } while ((cordenadaLinha > 0 || cordenadaColuna > 0) && vitoria[0] == 0);

    if (vitoria[0] == 1) {
        printf("\nO jogador %c ganhou\n\n", vitoria[1]);
    } else if (contarRodada == 9) {
        printf("Deu Velha!!!\n\n");
    }
    if (cordenadaLinha <= 0 || cordenadaColuna <= 0) {
        printf("\nVocê escolheu sair!!!\n\n");
    }
    
    
}