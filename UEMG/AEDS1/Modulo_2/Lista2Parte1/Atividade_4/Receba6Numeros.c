// Fazer uma lista para 6 números;
// Eles verão ser preenchidos pelo usuário;
// Mostre os números pares digitados;
// Mostre a soma dos números pares digitados;
// Os números ímpares digitados;
// A quantidade de números ímpares digitados.

# include <stdio.h>

int main() {

    int tamanhoLista = 6;
    int lista[tamanhoLista];
    double somarPares = 0;
    int quantidadeImpares = 0;

    for (int i = 0; i < tamanhoLista; i++) {

        printf("(%d/%d) - Digite o valor para a posição %d do vetor: ", i+1, tamanhoLista, i+1);
        scanf("%d", &lista[i]);   
    }

    printf("\n\nOs números pares digitados são:\n|");   
    for (int i = 0, contar = 0; i < tamanhoLista; i++) {
        if (lista[i] % 2 == 0) {
            printf(" %d |", lista[i]);
            contar++;
            somarPares += lista[i];
        }
        if (contar == 0 && i == tamanhoLista - 1) {
            printf(" # |");
        }        
    }

    printf("\n\nA soma dos números ímpares digitados são:\n| %d |", somarPares); 

    printf("\n\nOs números ímpares digitados são:\n|");  
    for (int i = 0, contar = 0; i < tamanhoLista; i++) {
        if (lista[i] % 2 == 1) {
            printf(" %d |", lista[i]);
            quantidadeImpares++;
            somarPares += lista[i];
        }
        if (contar == 0 && i == tamanhoLista - 1) {
            printf(" # |");
        }        
    }

    printf("\n\nA quantidade dos números ímpares digitados são:\n| %d |", quantidadeImpares);     

    return 0;
}