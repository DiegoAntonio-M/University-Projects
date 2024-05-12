# include <stdio.h>

int main () {

    int numero = 0;
    double media = 0;
    double contar = 0;
    int soma = 0;

    do {
        printf("Digite a idade: ");
        scanf("%d", &numero);

        if (numero != 0) {

            soma += numero;
            contar++;
            media = soma / contar;
        }


    } while (numero != 0);

    printf("A média dos numeros digitados é: %lf", media);
    
}