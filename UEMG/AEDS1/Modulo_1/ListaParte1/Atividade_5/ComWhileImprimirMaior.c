# include <stdio.h>

int main(int argc, char const *argv[]) {
    
    int numero = 0;
    int quantidadeDesejada = 0;
    int i = 1;
    int maiorN = 0;
    int contarMaior = 0;

    printf("Digite quantos números deseja digitar: ");
    scanf("%d", &quantidadeDesejada);

    while (i <= quantidadeDesejada) {
        
        printf("Digite o valor a ser analizado: ");
        scanf("%d", &numero);

        if (numero > maiorN) {
            maiorN = numero;
            contarMaior = 0;
        }

        if (numero == maiorN) {
            contarMaior++;
        }

        i++;
    }

    printf("O maior numero foi %d e foi digitado %d vese(s)", maiorN, contarMaior);
    
    return 0;
}
