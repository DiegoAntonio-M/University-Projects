# include <stdio.h>
# include <math.h>

int main() {

    int vetor[50] = {0};

    for (int i = 0; i < 50; i++) {
        vetor[i] = i + pow(i,2);
    }
    
    for (int i = 0; i < 50; i++) {
        if (vetor[i] % 2 == 1)
        {
            printf("A posição %d do vetor contém um número ímpar.\n", i);
        }
        
    }

    printf("\nO vetor contem os seguintes números:\n");

    for (int i = 0; i < 50; i++){
        printf("%d ", vetor[i]);
    }
    
    return 0;
}