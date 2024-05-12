#include <stdio.h>

int main () {

    int quantidadePessoasTotais = 1;
    int pessoaAnalizada = 0;
    int quant1a15 = 0;
    int quant16a30 = 0;
    int quant31a45 = 0;
    int quant46a60 = 0;
    int quant61mais = 0;
    int pessoasParaContabilizar = 0;
    double calcularPorcentagem = 0;

    printf("Quantas pessoas deseja digitar? ");
    scanf("%d", &pessoasParaContabilizar);

    while (quantidadePessoasTotais <= pessoasParaContabilizar) {
        printf("\nDigite a idade da pessoa %d: ",quantidadePessoasTotais);
        scanf("%d", &pessoaAnalizada);

        if (1 <= pessoaAnalizada && pessoaAnalizada <= 15) {
            quant1a15 += 1;
        } else if (16 <= pessoaAnalizada && pessoaAnalizada <= 30) {
            quant16a30 += 1;
        } else if (31 <= pessoaAnalizada && pessoaAnalizada <= 45) {
            quant31a45 += 1;
        } else if (46 <= pessoaAnalizada && pessoaAnalizada <= 60) {
            quant46a60 += 1;
        } else if (61 <= pessoaAnalizada) {
            quant61mais += 1;
        } else {
            printf("Este não é um numero válido, tente novamente.\n");
            quantidadePessoasTotais = quantidadePessoasTotais - 1;
        }
        quantidadePessoasTotais = quantidadePessoasTotais + 1;
    }
    
        printf("\nResultado Final da Faixa Etária:\n");

        calcularPorcentagem = quant1a15*100 / (quantidadePessoasTotais - 1);
        printf("1 a 15 anos - %.1f%%\n", calcularPorcentagem);

        calcularPorcentagem = quant16a30*100 / (quantidadePessoasTotais - 1);
        printf("16 a 30 anos - %.1f%%\n", calcularPorcentagem);

        calcularPorcentagem = quant31a45*100 / (quantidadePessoasTotais - 1);
        printf("31 a 45 anos - %.1f%%\n", calcularPorcentagem);

        calcularPorcentagem = quant46a60*100 / (quantidadePessoasTotais - 1);
        printf("46 a 60 anos - %.1f%%\n", calcularPorcentagem);

        calcularPorcentagem = quant61mais*100 / (quantidadePessoasTotais - 1);
        printf("Maiores 61 anos - %.1f%%\n", calcularPorcentagem);

}


