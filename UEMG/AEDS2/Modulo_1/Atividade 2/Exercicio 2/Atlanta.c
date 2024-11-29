/*
 * UNIVERSIDADE ESTADUAL DE CAMPINAS.
 * Universidade Estadual de Campinas.
 * Prova da Olimpíada Brasileira de Informática 2020.
 * Campinas: 2020.
 * Disponível em: https://olimpiada.ic.unicamp.br/static/extras/obi2020/provas/ProvaOBI2020_f3p2.pdf.
 * Acesso em: 31 out. 2024.
 */

/*NÍVEL 2 NÍVEL --> QUESTÃO - ATLANTA*/

//Atividade proposta: Realizar o Exercício da OBI e fazer um cálculo de complexidade.

#include <stdio.h>
#include <math.h>

int main() {

    int infoSala[2] = {};     // O(n) = 1
    int finded = 0;     // O(n) = 1

    printf("Escreva 2 numeros [azul branco]: ");     // O(n) = 1
    scanf("%d %d", &infoSala[0], &infoSala[1]);     // O(n) = 1

    for (int i = 1; (i <= ((infoSala[1]) + (-(infoSala[1]/2) + (-((infoSala[1] > 4) ? (infoSala[1]/4) : (0)))))) && (i <= pow(10,6)/4); i++) {     // O(n) = n (1/4)(...) + 1 (aprox.)
        if (infoSala[1] % i == 0) {     // O(n) = 1
            if ((i * 2 + (infoSala[1]/i) * 2 + 4) == infoSala[0]) {     // O(n) = 1
                printf("%d %d\n", i+2, infoSala[1]/i+2);     // O(n) = 1
                finded = 1;     // O(n) = 1
            }
        }
    }
    (finded == 0) ? printf("-1 -1") : 0;     // O(n) = 1

    return 0;      // O(n) = 1
}

// ===== Considerando n = infoSala[1], sendo a entrada {1 <= n <= (10^(6))/4 =====>>>>>

// O(n) = 4 + arred.up(n (1/4))(4) + 1 + 2
// O(n) = arred.up(n (1/4))(4) + 7

// O(n) = arred.up(n (1/2))(4) + 7    --{ se, 1 <= n < 4
// O(n) = arred.up(n (1/4))(4) + 7    --{ se, 4 <= n <= (10^(6))/4

//>> O(n) = n^1 ---> linear