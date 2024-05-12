# include <stdio.h>

int main () {

    float salariotrabalhador = 0;
    float prestacaoImprestimo = 0;

    printf("Digite o salário do funcionário: ");
    scanf("%f", &salariotrabalhador);

    printf("Digite o valor da prestação do emprestimo: ");
    scanf("%f", &prestacaoImprestimo);

    if (prestacaoImprestimo > salariotrabalhador * 0.2) {
        printf("Imprestimo não concedido.\n\n");
    } else {
        printf("Imprestimo concedido.\n\n");
    }

}