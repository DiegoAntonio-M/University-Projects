// Ler um valor X e guardar num vetor "vetorX", terá 5 elementos, não pode ter valores repetidos;
// Ler um valor Y e guardar num vetor "vetorY", terá 5 elementos, não pode ter valores repetidos;
// [1] Calcular a soma dos itens das respecitvas posições do 'vetorX' e 'vetorY';
// [2] Calcular o produto dos itens das respecitvas posições do 'vetorX' e 'vetorY';
// [3] Calcular a diferença dos itens das respecitvas listas do 'vetorX' e 'vetorY';
// [4] Calcular a interseção das posições do 'vetorX' e 'vetorY' aonde os itens tem o mesmo valor;
// [5] Criar a união dos dois valores;
// Mostre os resultados das operações acima: [1] ... [5].

# include <stdio.h>
# include <math.h>

int main() {

    int tamanhoDoVetorX = 5;
    int tamanhoDoVetorY = 5;
    int maiorTamanho = tamanhoDoVetorX;
    int menorTamanho = tamanhoDoVetorX;

    if (tamanhoDoVetorX < tamanhoDoVetorY) {
        maiorTamanho = tamanhoDoVetorY;
    }

    if (tamanhoDoVetorX > tamanhoDoVetorY) {
        menorTamanho = tamanhoDoVetorY;
    }
    
    int vetorX[tamanhoDoVetorX];
    int vetorY[tamanhoDoVetorY];
    
    int somaXeY[maiorTamanho];
    int produtoXeY[maiorTamanho];
    int diferencaXeY[tamanhoDoVetorX][2];
    int intersecao[menorTamanho][2];
    int uniaoEntreXeY[tamanhoDoVetorX+tamanhoDoVetorY];

    int marcardor = 0;

    printf("Digite valores para o vetorX:\n\n");

    for (marcardor = 0; marcardor < tamanhoDoVetorX; marcardor++) {
        int validador = 1;
        do {
            validador = 1;
            printf("vetorX[%d] = ", marcardor);
            scanf("%d", &vetorX[marcardor]);

            uniaoEntreXeY[marcardor] = vetorX[marcardor];

            for (int i = 0; (i < marcardor) && validador != 0; i++) {
                if ((vetorX[i] == vetorX[marcardor])) {
                    validador = 0;
                    printf("## Digite outro valor não escrito já no vetor X ##  ");
                }                
            }
            
        } while (validador == 0);
    }

    printf("Digite valores para o vetorY:\n\n");

    for (marcardor; marcardor < (tamanhoDoVetorX + tamanhoDoVetorY); marcardor++) {
        
        int validador = 1;
        do {
            validador = 1;
            printf("vetorY[%d] = ", marcardor - tamanhoDoVetorX);
            scanf("%d", &vetorY[marcardor - tamanhoDoVetorX]);

            uniaoEntreXeY[marcardor] = vetorY[marcardor - tamanhoDoVetorX];

            for (int i = 0; (i < marcardor - tamanhoDoVetorX) && validador != 0; i++) {
                if ((vetorY[i] == vetorY[marcardor - tamanhoDoVetorX])) {
                    validador = 0;
                    printf("## Digite outro valor não escrito já no vetor Y ##  ");
                }                
            }
            
        } while (validador == 0);
    }

    for (int i = 0; i < maiorTamanho; i++) {

        int valorDoX = 0;
        int valorDoY = 0;

        if (i < tamanhoDoVetorX) {
            valorDoX = vetorX[i];
        }

        if (i < tamanhoDoVetorY) {
            valorDoY = vetorY[i];
        }

        somaXeY[i] = valorDoX + valorDoY;
        produtoXeY[i] = valorDoX * valorDoY;

    }

    for (int i = 0, verificador = 0; i < tamanhoDoVetorX; i++) {
        verificador = 0;

        intersecao[i][0] = 0;
        intersecao[i][1] = 0;

        for (int ii = 0; ii < tamanhoDoVetorY && verificador == 0; ii++) {


            if (vetorX[i] == vetorY[ii]) {
                intersecao[i][0] = vetorX[i];
                intersecao[i][1] = 1;
                verificador++;
            }
            
        }

        if (verificador == 0) {
            diferencaXeY[i][0] = vetorX[i];
            diferencaXeY[i][1] = 1;
        } else {
            diferencaXeY[i][0] = 0;
            diferencaXeY[i][1] = 0;
        }
    }
    
    printf("\n\nA soma dos números é:\n|");    
    for (int i = 0; i < maiorTamanho; i++) {
        printf(" %d |", somaXeY[i]);
    }

    printf("\n\nO produto dos números é:\n|");    
    for (int i = 0; i < maiorTamanho; i++) {
        printf(" %d |", produtoXeY[i]);
    }

    printf("\n\nA diferenca da lista de vetores é:\n|");    
    for (int i = 0; i < maiorTamanho; i++) {
        if (diferencaXeY[i][1] == 1) {
            printf(" %d |", diferencaXeY[i][0]);
        } else {
            printf(" # |");
        }
    }
    
    printf("\n\nA interseção da lista de vetores é:\n|");    
    for (int i = 0; i < menorTamanho; i++) {
        if (intersecao[i][1] == 1) {
            printf(" %d |", intersecao[i][0]);
        } else {
            printf(" # |");
        }
    }

    printf("\n\nA diferenca da lista de vetores é:\n|");    
    for (int i = 0; i < (tamanhoDoVetorX + tamanhoDoVetorY); i++) {
        printf(" %d |", uniaoEntreXeY[i]);
    }

    return 0;
}