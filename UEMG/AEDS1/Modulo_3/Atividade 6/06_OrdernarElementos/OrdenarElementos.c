# include <stdio.h>
# include <math.h>
# include <stdlib.h>
# include <string.h>


void organizar (int *matriz, int tamanho){

    int maior[2];
    int menor[2];

    maior[0] = matriz[0];
    menor[0] = matriz[0];

    for(int j = 1; j < tamanho; j++){
        if ( maior[0] < matriz[j]){
            maior[0] = matriz[j];
            maior[1] = j;
        }
        if (menor[0] > matriz[j] && j != 0){
            menor[0] = matriz[j];
            menor[1] = j;
        }
    
    }

    matriz[menor[1]] = maior[0];
    matriz[maior[1]] = menor[0];
}
int main() {

    int matriz[5];
    for(int i = 0; i < 5; i++){
        printf("Digite o valor %d: ", i+1);
        scanf("%d", &matriz[i]);
    }

    for(int i = 0; i < 5; i++){
        printf("%d\n", matriz[i]);
    }

    organizar(matriz, 5);

    for(int i = 0; i < 5; i++){
        printf("| %d ", matriz[i]);
        
    }
    printf("|");

    return 0;
}