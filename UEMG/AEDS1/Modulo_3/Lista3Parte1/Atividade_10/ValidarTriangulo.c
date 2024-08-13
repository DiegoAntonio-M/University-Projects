# include <stdio.h>
# include <math.h>
# include <stdlib.h>
# include <string.h>

typedef struct tipoTriangulo {
    double ladoA;
    double ladoB;
    double ladoC;
}tipoTriangulo;

int ehTriangulo (tipoTriangulo possivelT) {

    if (possivelT.ladoA < possivelT.ladoB + possivelT.ladoC) {
        if (possivelT.ladoB < possivelT.ladoC + possivelT.ladoA) {
            if (possivelT.ladoC < possivelT.ladoA + possivelT.ladoB) {
                return 1;
            }
        }
    }
    return 0;
}

int verificarTipoTri (tipoTriangulo possivelT) {
    if ((possivelT.ladoA == possivelT.ladoB) && (possivelT.ladoB == possivelT.ladoC)) {
        return 1;
    } else if ((possivelT.ladoA == possivelT.ladoB) || (possivelT.ladoA == possivelT.ladoC) || (possivelT.ladoB == possivelT.ladoC)) {
        return 2;
    } else {
        return 3;
    }    
    return 0;
}

int main() {

    tipoTriangulo triangulo = {};

    fputs("Escreva 3 numero para comprimentos para um triangulo: ", stdout);
    scanf("%lf %lf %lf", &triangulo.ladoA, &triangulo.ladoB, &triangulo.ladoC);

    if (ehTriangulo(triangulo)) {
        fputs("Isso eh um triangulo! - ", stdout);

        switch (verificarTipoTri(triangulo)) {
        case 1:
            fputs("Tipo equilatero!!!\n", stdout);
            break;
        case 2:
            fputs("Tipo isósceles!!!\n", stdout);
            break;
        case 3:
            fputs("Tipo escaleno!!!\n", stdout);
            break;
        default:
            fputs("#!#! Não foi possível definir !#!#\n", stdout);
            break;
        }
    } else {
        fputs("Isso não eh um triangulo :(\n\n", stdout);
    }  

    return 0;
}