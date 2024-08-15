# include <stdio.h>
# include <math.h>
# include <stdlib.h>
# include <string.h>

int main() {
    
    char sequenciaDeNumeros[] = {"7316717653133062491922511967442657474235534919493496983520312774506326239578318016984801869478851843858615607891129494954595017379583319528532088055111254069874715852386305071569329096329522744304355766896648950445244523161731856403098711121722383113622298934233803081353362766142828064444866452387493035890729629049156044077239071381051585930796086670172427121883998797908792274921901699720888093776657273330010533678812202354218097512545405947522435258490771167055601360483958644670632441572215539753697817977846174064955149290862569321978468622482839722413756570560574902614079729686524145351004748216637048440319989000889524345065854122758866688116427171479924442928230863465674813919123162824586178664583591245665294765456828489128831426076900422421902267105562632111110937054421750694165896040807198403850962455444362981230987879927244284909188845801561660979191338754992005240636899125607176060588611646710940507754100225698315520005593572972571636269561882670428252483600823257530420752963450"};
    int quantidadeDeNumeros = sizeof(sequenciaDeNumeros);

    int tamanhoDaSeguencia = 5;
    long long produto[3] = {};

    for (int i = 0; i < (quantidadeDeNumeros - tamanhoDaSeguencia + 1); i++) {

        long long parcela1 = 0;
        long long parcela2 = 0;

        for (int p1 = 0; p1 < tamanhoDaSeguencia; p1++) {
            parcela1 += (sequenciaDeNumeros[i + tamanhoDaSeguencia - (p1 + 1)] - 48)*pow(10, p1);
        }
        
        for (int ii = 0; ii < (quantidadeDeNumeros - tamanhoDaSeguencia + 1); ii++) {
            parcela2 = 0;
            if (i != ii) {
                for (int p2 = 0; p2 < tamanhoDaSeguencia; p2++) {
                    parcela2 += (sequenciaDeNumeros[ii + tamanhoDaSeguencia - (p2 + 1)] - 48)*pow(10, p2);
                }
            
                long long resultadoProduto = parcela1 * parcela2;

                if (produto[2] < resultadoProduto) {
                    produto[0] = parcela1;
                    produto[1] = parcela2;
                    produto[2] = resultadoProduto;
                }
            }
        }
  
    }

    printf("[%d] X [%d] = %lld\n", produto[0], produto[1], produto[2]);

    return 0;
}