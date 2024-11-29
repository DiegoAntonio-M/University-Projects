/*
 * UNIVERSIDADE ESTADUAL DE CAMPINAS.
 * Universidade Estadual de Campinas.
 * Prova da Olimpíada Brasileira de Informática 2021.
 * Campinas: 2021.
 * Disponível em: https://olimpiada.ic.unicamp.br/static/extras/obi2021/provas/ProvaOBI2021_f3ps.pdf.
 * Acesso em: 31 out. 2024.
 */

/*NÍVEL SENIOR --> QUESTÃO - OGRO*/

//Atividade proposta: Realizar o Exercício da OBI e fazer um cálculo de complexidade.

# include <stdio.h>

int main() {

    int numero = 0;     // O(n) = 1

    do {
        printf("Digite um numero [0-10]: ");     // O(n) = 1
        scanf("%d", &numero);     // O(n) = 1
        if ((0 <= numero) && (numero <= 10)) {     // O(n) = 1 (+1 opção - indireta)
            break; // O(n) = 1 // OU
        } else {
            fputs("Tente novamente dentro do intervalo [0-10]\n\n", stdout); // O(n) = 1 //OU
        }
        
    } while (1); // O(n) = se fora do range -> ∞, else // O(n) = 1
    
    for (int i = 0; i < 2; i++) { // O(n) = 2(...)+1
        for (int ii = 0; ii < 5; ii++) { // O(n) = 5(...)+1
            if (0 < numero--) {     // O(n) = 1
                fputs("I ", stdout);     // O(n) = 1
            }            
        }
        (numero <= -5) ? printf("*") : 0 ;     // O(n) = 1
        printf("\n");     // O(n) = 1
    }    

    return 0;     // O(n) = 1
}

// ===== Considerando n = numero, sendo a entrada {0 <= n <= 10 =====>>>>>

// O(n) = 5 + 2( 5(2)+1 )+1 + If (5<n,0;n<5,1; n==0,2) + 1 + 1
// O(n) = 5 + 23 + [0~2] + 2
// O(n) = 30 + [0~2]
// O(n) = 30

//>> O(n) = c ---> constante