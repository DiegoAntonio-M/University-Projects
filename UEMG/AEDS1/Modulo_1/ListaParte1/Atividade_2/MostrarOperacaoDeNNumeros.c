# include <stdio.h>

int main () {

    int numero = 0;
    int contar = 0;
    int contarPar = 0;
    double soma = 0;
    int maiorN = 0;
    int menorN = 0;
    double somarPar = 0;
    double mediaPar = 0;
    double mediaN = 0;
    int quantidadeDesejada = 0;

    for (int i = 0; i < 1; i++) {

        printf("Digite a quantidade de valores que deseja ser digitado: ");
        scanf("%d", &quantidadeDesejada);

        if (quantidadeDesejada < 0) {
            i--;
            printf("Digite novamente.\n");
        }
    }

    for (int i = 1; i <= quantidadeDesejada; i++) {
        
        printf("Digite o valor: ");
        scanf("%d", &numero);

        contar++;
        soma += numero;

        if (numero % 2 == 0) {

            somarPar += numero;
            contarPar++;
        }
        
        if ((numero > maiorN) || (i == 1)) {
            maiorN = numero;
        }

        if ((numero < menorN) || (i == 1)) {
            menorN = numero;
        }
    }
    
    printf("A soma dos itens digitados é: %lf.\n", soma);
    printf("Foram digitado(s): %d número(s).\n", contar);

    mediaN = soma/contar;
    printf("A média dos números é: %lf.\n", mediaN);

    printf("O maior valor digitado foi: %d.\n", maiorN);
    printf("O menor valor digitado foi: %d.\n", menorN);

    if (contarPar != 0) {
        mediaPar = somarPar/contarPar;
        printf("A média dos números pares digitados é: %lf.\n", mediaPar);
    } else {
        printf("Nenhum número par foi digitado para se calcular a média dos pares.\n");
    }
        
}