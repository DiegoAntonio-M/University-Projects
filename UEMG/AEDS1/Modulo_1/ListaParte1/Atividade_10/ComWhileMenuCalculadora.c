# include <stdio.h>

int main () {

    double numeroA = 0;
    double numeroB = 0;
    int opcao = 0;

    double soma = 0;
    double subtracao = 0;
    double multiplicacao = 0;
    double divisao = 0;


    do {
        printf("\n...............................................................\nEscolha uma das opções abaixo para operação entre dois números:\n\n");
        printf("1 - Adição.\n");
        printf("2 - Subtração.\n");
        printf("3 - Multiplicação .\n");
        printf("4 - Divisão.\n");
        printf("5 - Saída.\n\n");
        printf(">> ");
        scanf("%d", &opcao);

        if ((opcao < 5) && (0 < opcao)) {

            printf("\nPrimeiro número: ");
            scanf("%lf", &numeroA);

            printf("Segundo número: ");
            scanf("%lf", &numeroB);
        }
        
        switch (opcao) {
        case 1:
            soma = numeroA + numeroB;
            printf("\nResultado (adição) >> %lf.\n", soma);
            break;

        case 2:
            subtracao = numeroA - numeroB;
            printf("\nResultado (subtração) >> %lf.\n", subtracao);
            break;

        case 3:
            multiplicacao = numeroA * numeroB;
            printf("\nResultado (multiplicação) >> %lf.\n", multiplicacao);
            break;
        case 4:
            divisao = numeroA / numeroB;
            printf("\nResultado (divisão) >> %lf.\n", divisao);
            break;

        case 5:
            printf("\n>>> Você escolheu sair <<<\n");
            break;

        default:
            printf("\n>>> Selecione outro número <<<\n\n");
            break;
        }



    } while (opcao != 5);
    
}