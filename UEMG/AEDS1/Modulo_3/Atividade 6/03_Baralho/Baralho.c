# include <stdio.h>
# include <math.h>
# include <stdlib.h>
# include <string.h>
#include <time.h>

typedef struct carta {
    char naipe[10];
    int valor;
} carta;

carta gerarCarta () {
    char naipePossibilidades[][10] = {"Copas", "Espadas", "Ouro", "Paus"};
    srand(time(0));
    carta cartaTemp;
    cartaTemp.valor = rand() % 13 + 1;
    strcpy(cartaTemp.naipe, naipePossibilidades[rand() % 4]);
    return cartaTemp;

}


int main() {

    carta cartasJogadores[2][5] = {};

    for (int i = 0; i < 2; i++) {
        for (int ii = 0; ii < 5; ii++) {
            cartasJogadores[i][ii] = gerarCarta();
        }        
    }

    for (int i = 0; i < 2; i++) {
        printf("Pessoa %d\n", i+1);
        for (int ii = 0; ii < 5; ii++) {
            printf("[%s , %d] ", cartasJogadores[i][ii].naipe, cartasJogadores[i][ii].valor);
             
        }
        printf("\n");
        
    }
    
    

    return 0;
}