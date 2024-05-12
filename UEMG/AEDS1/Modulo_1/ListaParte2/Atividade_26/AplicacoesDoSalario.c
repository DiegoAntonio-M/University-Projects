# include <stdio.h>

int main () {

    double salarioCarlos = 0;
    double salarioJoao = 0;
    double poupancaCarlos = 0;
    double rendaFixaJoao = 0;
    int meses = 0;

    double taxaPoupancaCarlos = 0.02; // taxa de poupança de Carlos
    double taxaRendaFixaJoao = 0.05; // taxa de renda fixa de João

    printf("Digite o salário do Carlos: ");
    scanf("%lf", &salarioCarlos);

    salarioJoao = salarioCarlos / 3;
    poupancaCarlos = salarioCarlos;
    rendaFixaJoao = salarioJoao;

    while (rendaFixaJoao <= poupancaCarlos) {
        poupancaCarlos += poupancaCarlos * taxaPoupancaCarlos;
        rendaFixaJoao += rendaFixaJoao * taxaRendaFixaJoao;
        meses++;
    }

    printf("Serão necessários %d meses para que João tenha mais dinheiro que Carlos.\n", meses);

    return 0;
}
