// Ler uma quantidade de números inderminada;
// Os números devem ser interios;
// Quando for informado o "0", encerrará a solicitação dos números;
// E depois disso mostre no final os itens referente aos números inseridos:
// 1. Soma;
// 2. Media;
// 3. Maior número;
// 4. Menor número;
// 5. Segundo memor número;
// 6. Segundo maior número;

# include <stdio.h>

int main () {

    int n = -1;
    int contar = 0;
    double soma = 0;
    double media = 0;
    int maiorN = 0;
    int menorN = 0;
    int segundoMaiorN = 0;
    int segundoMenorN = 0;

    int contAtributMaiorESegundo = 0;
    int contAtributMenorESegundo = 0;

    while (n != 0)  {

        printf("Digite um número: ");
        scanf("%d", &n);

        if (n != 0) {

            soma += n;
            contar ++;

            if ((n > maiorN) || (contar == 1)) {

                segundoMaiorN = maiorN;
                maiorN = n;
                contAtributMaiorESegundo ++;
            }

            if ((n < menorN) || (contar == 1)) {

                segundoMenorN = menorN;
                menorN = n; 
                contAtributMenorESegundo ++;
            }

            if ((n > segundoMaiorN) || (contAtributMenorESegundo == 2)) {

                if (n < maiorN) {
                    segundoMaiorN = n;
                    contAtributMenorESegundo += 2;
                }

            }
                        
            if ((n < segundoMenorN) || (contAtributMaiorESegundo == 2)) {

                if (n > menorN) {
                    segundoMenorN = n;
                    contAtributMaiorESegundo += 2; 
                }

            } 
        }        
    }

    if (contar != 0) {

        printf("A soma eh: %lf.\n", soma);

        media = soma / contar;
        
        printf("A media eh: %lf.\n", media);

        printf("O maior numero digitado foi: %d.\n", maiorN);
        printf("O menor numero digitado foi: %d.\n", menorN);

        (segundoMaiorN != 0) ? printf("O segundo maior numero digitado foi: %d.\n", segundoMaiorN) : printf("O segundo maior numero digitado foi: ##.\n");
        (segundoMenorN != 0) ? printf("O segundo menor numero digitado foi: %d.\n", segundoMenorN) : printf("O segundo menor numero digitado foi: ##.\n");
    }
    
    return 0;    
}