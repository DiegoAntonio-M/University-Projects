# include <stdio.h>

int main () {

    int chegada_h = 0;
    int chegada_m = 0;
    int saida_h = 0;
    int saida_m = 0;
    int total_h = 0;
    int total_m = 0;
    int total = 0;
    double preco = 0;

    printf("Digite a hora e o minuto de chegada (hh mm): ");
    scanf("%d %d", &chegada_h, &chegada_m);

    printf("Digite a hora e o minuto de saida (hh mm): ");
    scanf("%d %d", &saida_h, &saida_m);

    if(saida_h < chegada_h) {
        saida_h += 24;
    }

    total = (saida_h*60 + saida_m) - (chegada_h*60 + chegada_m);


    total = (total + 59) / 60; // Arredondar para cima

    if(total <= 2) {
        preco = total * 1.00;
    } else if(total <= 4) {
        preco = total * 1.40;
    } else {
        preco = total * 2.00;
    }

    printf("O preço do estacionamento é: R$ %.2f\n", preco);

    return 0;
}