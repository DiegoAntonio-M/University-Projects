# include <stdio.h>

int main () {

    double trabalhoLab = 0;
    double avaliacaoSemestral = 0;
    double exameFinal = 0;
    double media = 0;

    printf("Digite a nota do trabalho de laboratório: ");
    scanf("%lf", &trabalhoLab);

    printf("Digite a nota da avaliação semestral: ");
    scanf("%lf", &avaliacaoSemestral);

    printf("Digite a nota do exame final: ");
    scanf("%lf", &exameFinal);

    if ((trabalhoLab < 0 || trabalhoLab > 10) || (avaliacaoSemestral < 0 || avaliacaoSemestral > 10) || (exameFinal < 0 || exameFinal > 10)) {
        printf("Notas inválidas\n");
    } else {
        media = (trabalhoLab * 2 + avaliacaoSemestral * 3 + exameFinal * 5) / 10;

        if ((media >= 0) && (media < 3)) {
            printf("Reprovado\n");
        } else if ((media >= 3) && (media < 5)) {
            printf("Recuperação\n");
        } else {
            printf("Aprovado\n");
        }
    }

    return 0;
}