# include <stdio.h>
# include <math.h>
# include <stdlib.h>
# include <string.h>

double calcular(double valor1, double valor2, char *operador) {
    switch (operador[0]) {
    case '+':
        return valor1 + valor2;
        break;
    case '-':
        return valor1 - valor2;
        break;
    case '*':
        return valor1 * valor2;
        break;
    case '/':
        return valor1 / valor2;
        break;
    default:
        break;
    }
}

int validarEntradaOperador(char *operador) {
    switch (operador[0]) {
    case '+':
        return 1;
        break;
    case '-':
        return 1;
        break;
    case '*':
        return 1;
        break;
    case '/':
        return 1;
        break;
    default:
        return 0;
        break;
    }
}

int main() {

    double valueA = 0;
    double valueB = 0;
    char operador[2] = {};

    do {
        fputs("Escolha uma das opções abaixo:\n",  stdout);
        fputs("[ + ] : Soma\n", stdout);
        fputs("[ - ] : Subtração\n", stdout);
        fputs("[ * ] : Multiplicação\n", stdout);
        fputs("[ / ] : Divisão\n", stdout);
        fputs("Escolha o tipo de Operação - >> ", stdout);
        fflush(stdin);
        setbuf(stdin,NULL);
        fgets(operador, 2, stdin);

    } while (validarEntradaOperador(operador) != 1);
    

    fputs("Escolha o primerio valor: ", stdout);
    scanf("%lf", &valueA);

    fputs("Escolha o segundo valor: ", stdout);
    scanf("%lf", &valueB);
    
    double resutlado = calcular(valueA, valueB, operador);

    printf("O resultado dessa operação eh: %lf.\n", resutlado);

    return 0;
}