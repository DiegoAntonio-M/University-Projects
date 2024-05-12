# include <stdio.h>

int main () {

    int dia = 0;
    int mes = 0;
    int ano = 0;
    int ano_atual = 2008; // constante
    int bissexto = 0;

    printf("Digite o dia de nascimento: ");
    scanf("%d", &dia);

    printf("Digite o mês de nascimento: ");
    scanf("%d", &mes);

    printf("Digite o ano de nascimento: ");
    scanf("%d", &ano);

    if (ano % 4 == 0) {
        if (ano % 100 != 0 || ano % 400 == 0) {
            bissexto = 1;
        }
    }

    if ((ano >= ano_atual) && (mes >= 1) && (mes <= 12) && (dia >= 1) && (dia <= 31)) {

        if (((mes == 4 || mes == 6 || mes == 9 || mes == 11)) && dia == 30) {
            printf("Data válida\n");
        } else if (((mes == 1) || (mes == 3) || (mes == 5) || (mes == 7) || (mes == 8) || (mes == 10) || (mes == 12)) && (dia == 30)) {
            printf("Data válida\n");
        } else if ((mes == 2) && (bissexto == 0) && dia <= 28) {
            printf("Data válida\n");
        } else if ((mes == 2) && (bissexto == 1) && dia <= 29) {
            printf("Data válida\n");
        } else {
            printf("Data inválida\n");
        }

    } else {
        printf("Data inválida\n");
    }

    return 0;
}