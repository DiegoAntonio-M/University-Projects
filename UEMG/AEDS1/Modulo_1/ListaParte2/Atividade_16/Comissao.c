# include <stdio.h>

int main () {

    float valorDeVenda = 0;
    float valorComissao = 0;

    printf("Digite de venda: ");
    scanf("%f", &valorDeVenda);

    if (valorDeVenda >= 100000) {
        valorComissao = 700 + valorDeVenda*0.16;
    } else if ((valorDeVenda < 100000)||(valorDeVenda >= 80000)) {
        valorComissao = 650 + valorDeVenda*0.14;
    } else if ((valorDeVenda < 80000)||(valorDeVenda >= 60000)) {
        valorComissao = 600 + valorDeVenda*0.14;
    } else if ((valorDeVenda < 600000)||(valorDeVenda >= 40000)) {
        valorComissao = 550 + valorDeVenda*0.14;
    } else if ((valorDeVenda < 40000)||(valorDeVenda >= 20000)) {
        valorComissao = 500 + valorDeVenda*0.14;
    } else if (valorDeVenda < 200000) {
        valorComissao = 400 + valorDeVenda*0.14;
    }

    printf("Valor Comissão >>> %.2lf", valorComissao);

}
