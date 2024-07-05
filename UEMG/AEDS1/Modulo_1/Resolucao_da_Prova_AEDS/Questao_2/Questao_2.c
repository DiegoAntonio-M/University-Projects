// Somar todos os números abaixo de 2000;
// Todos esses números serão multiplos de 3 ou 5;

# include <stdio.h>

int main() {

    int numeroAte = 2000;
    int resultado = 0;

    for (int i = 1; i <= numeroAte; i++) {
        if (i % 3 == 0 || i % 5 == 0) {
            resultado += i;
        }        
    }
    
    printf("Os numeros somados abaixo de %d eh: %d", numeroAte, resultado);

    return 0;
}