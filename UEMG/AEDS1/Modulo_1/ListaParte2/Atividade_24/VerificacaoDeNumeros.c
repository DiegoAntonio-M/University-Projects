# include <stdio.h>

int main () {

    int baixa = 0; 
    int alta = 0; 
    int soma = 0;

    for (int i = 1000; i <= 9999; i++) {
        baixa = i % 100;
        alta = i / 100;
        soma = baixa + alta;
        if (soma * soma == i) {
            printf("%d possui a propriedade desejada\n", i);
        }
    }

    return 0;
}