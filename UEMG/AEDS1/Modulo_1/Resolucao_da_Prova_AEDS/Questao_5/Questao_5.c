// Ler dois números inseridos pelo usuário A e B;
// Faça uma conta, f(a, b) = (b)^3 + a*b - 2b + (a % b);
// Exemplo de saída:
// 1. Digite o valor A: 5
// 2. Digite o valor B: 7
// 3. (x) = 369;
// Imprima o resultado

# include <stdio.h>

int main() {

    int numA = 0;
    int numB = 0;
    int resultado = 0;

    printf("Digite o valor de A: ");
    scanf("%d", &numA);

    printf("Digite o valor de B: ");
    scanf("%d", &numB);

    resultado = ((numB * numB * numB) + (numA*numB)) - 2 * numB + (numA % numB);

    printf("(x) = %d.\n", resultado);

    return 0;
}