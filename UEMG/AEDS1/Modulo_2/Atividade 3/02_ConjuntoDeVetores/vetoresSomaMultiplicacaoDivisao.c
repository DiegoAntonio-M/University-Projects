#include <stdio.h>

int main () {

    double vetor1[10] = {};
    double vetor2[10] = {};
    int tamanhoDosVetores = 1;

    int tamanhoVetor1 = sizeof(vetor1)/sizeof(vetor1[0]);
    int tamanhoVetor2 = sizeof(vetor2)/sizeof(vetor2[0]);

    if (tamanhoVetor1 >= tamanhoVetor2) {
        tamanhoDosVetores = tamanhoVetor1;
    } else {
        tamanhoDosVetores = tamanhoVetor2;
    }   

    int vetor3[tamanhoDosVetores] = {};
    int vetor4[tamanhoDosVetores] = {};
    double vetor5[tamanhoDosVetores] = {};

    double auxiliar1 = 0;
    double auxiliar2 = 0;

    for (int i = 0; i < tamanhoVetor1; i++) {

        printf("\n(%d/%d) - Digite o valor inteiro para a posição %d do primeiro vetor: ", i+1, tamanhoVetor1, i+1);
        scanf("%lf", &vetor1[i]);        
    }
    for (int i = 0; i < tamanhoVetor2; i++) {

        printf("\n(%d/%d) - Digite o valor inteiro para a posição %d do segundo vetor: ", i+1, tamanhoVetor2, i+1);
        scanf("%lf", &vetor2[i]);        
    }

    for (int i = 0; i < tamanhoDosVetores; i++) {
        
        if(i < tamanhoVetor1) {auxiliar1 = vetor1[i];} else {auxiliar1 = 0;}
        if(i < tamanhoVetor2) {auxiliar2 = vetor2[i];} else {auxiliar2 = 0;}

        vetor3[i] = auxiliar1 + auxiliar2;       
    }

    for (int i = 0; i < tamanhoDosVetores; i++) {
        
        if(i < tamanhoVetor1) {auxiliar1 = vetor1[i];} else {auxiliar1 = 0;}
        if(i < tamanhoVetor2) {auxiliar2 = vetor2[i];} else {auxiliar2 = 0;}

        vetor4[i] = auxiliar1 * auxiliar2;       
    }

    for (int i = 0; i < tamanhoDosVetores; i++) {
        
        if(i < tamanhoVetor1) {auxiliar1 = vetor1[i];} else {auxiliar1 = 0;}
        if(i < tamanhoVetor2) {auxiliar2 = vetor2[i];} else {auxiliar2 = 0;}

        vetor5[i] = auxiliar1 / auxiliar2;       
    }

    printf("\nEsses são os números somados de cada posição corespondente:\n");
    for (int i = 0; i < tamanhoDosVetores; i++) {
        printf("[%d] ", vetor3[i]);
    }
    printf("\n");

    printf("\nEsses são os números multiplicados de cada posição corespondente:\n");
    for (int i = 0; i < tamanhoDosVetores; i++) {
        printf("[%d] ", vetor4[i]);
    }
    printf("\n");

    printf("\nEsses são os números multiplicados de cada posição corespondente:\n");
    for (int i = 0; i < tamanhoDosVetores; i++) {
        printf("[%.4lf] ", vetor5[i]);
    }
    
    printf("\n\n");

    return 0;
}