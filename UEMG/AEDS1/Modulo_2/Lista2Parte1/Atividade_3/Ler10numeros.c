// Ler 10 números do usuário;
// Todos terão que ser diferentes;
// Mostre o vetor com a posição e o número guardado.

# include <stdio.h>

int main() {

    int tamanhoDaLista = 10;
    int lista[tamanhoDaLista];

    printf("Digite valores para a lista:\n\n");
    for (int marcardor = 0; marcardor < tamanhoDaLista; marcardor++) {
        int validador = 1;
        do {
            validador = 1;
            printf("lista[%d] = ", marcardor);
            scanf("%d", &lista[marcardor]);

            for (int i = 0; (i < marcardor) && validador != 0; i++) {
                if ((lista[i] == lista[marcardor])) {
                    validador = 0;
                    printf("## Digite outro valor não escrito já na Lista ##  ");
                }                
            }
            
        } while (validador == 0);
    }

    printf("\n\nOs números digitados são:\n|");    
    for (int i = 0; i < tamanhoDaLista; i++) {
        printf(" %d |", lista[i]);
    }

    return 0;
}