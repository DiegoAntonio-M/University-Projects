# include <stdio.h>

int main() {

    int quantidadeAlunos = 10;
    // float coletarID = 0;
    // float coletarAltura =
    double alturaDeAlunos[quantidadeAlunos][2];
    double alturaMaisAlta[2];
    double alturaMaisBaixa[2];

    for (int i = 0; i < quantidadeAlunos; i++) {

        printf("(%d/%d) - Digite o ID e a altura em metros do Aluno [ID Altura]: ", i+1, quantidadeAlunos);
        scanf("%lf %lf", &alturaDeAlunos[i][0], &alturaDeAlunos[i][1]);
    }

    alturaMaisAlta[0] = alturaDeAlunos[0][0];
    alturaMaisAlta[1] = alturaDeAlunos[0][1];

    for (int i = 1; i < quantidadeAlunos; i++) {

        if (alturaMaisAlta[1] < alturaDeAlunos[i][1]) {
            alturaMaisAlta[0] = alturaDeAlunos[i][0];
            alturaMaisAlta[1] = alturaDeAlunos[i][1];
        }  
    }

    alturaMaisBaixa[0] = alturaDeAlunos[0][0];
    alturaMaisBaixa[1] = alturaDeAlunos[0][1];

    for (int i = 1; i < quantidadeAlunos; i++) {

        if (alturaMaisBaixa[1] > alturaDeAlunos[i][1]) {
            alturaMaisBaixa[0] = alturaDeAlunos[i][0];
            alturaMaisBaixa[1] = alturaDeAlunos[i][1];
        }  
    }

    printf("\n\nA altura mais alta eh %.1lfm do aluno com ID %.0lf", alturaMaisAlta[1], alturaMaisAlta[0]);
    printf("\n\nA altura mais baixa eh %.1lfm do aluno com ID %.0lf", alturaMaisBaixa[1], alturaMaisBaixa[0]);    

    return 0;
}