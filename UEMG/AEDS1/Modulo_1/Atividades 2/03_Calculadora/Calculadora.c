#include <stdio.h>

int main() {

    int opcao;
    float num1 = 0;
    float num2 = 0;
    float resultado = 0;

    do {
        printf("Escolha a opção:\n\n");
        printf("1 - Soma de 2 números.\n");
        printf("2 - Diferença entre 2 números (maior pelo menor).\n");
        printf("3 - Produto entre 2 números.\n");
        printf("4 - Divisão entre 2 números (o denominador não pode ser zero).\n");

        printf("\nEscreva a opção: ");
        
        scanf("%d", &opcao);

        printf("\nDigite o primeiro número: ");
        scanf("%f", &num1);
        printf("Digite o segundo número: ");
        scanf("%f", &num2);

        switch(opcao) {
            case 1:
                resultado = num1 + num2;
                printf("Resultado: %.2f\n", resultado);
                break;

            case 2:
                if(num1 > num2) {
                    resultado = num1 - num2;
                } else {
                    resultado = num2 - num1;
                }
                printf("Resultado: %.2f\n", resultado);
                break;

            case 3:
                resultado = num1 * num2;
                printf("Resultado: %.2f\n", resultado);
                break;

            case 4:
                if(num2 != 0) {
                    resultado = num1 / num2;
                    printf("Resultado: %.2f\n", resultado);
                } else {
                    printf("\n\n\n======================================\nErro: O denominador não pode ser zero.\n======================================\n\n");
                    opcao = 0;
                }

                break;
            default:
                printf("\n\n\n===============\nOpção inválida.\n===============\n\n");

        } 
        
    } while(opcao < 1 || opcao > 4);

}