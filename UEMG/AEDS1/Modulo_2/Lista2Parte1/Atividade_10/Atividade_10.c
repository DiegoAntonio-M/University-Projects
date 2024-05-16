# include <stdio.h>

int main() {

    int quantidadeDeAlunos = 3;
    int quantidadeDeColunas = 4;
    int somaDasNotasFinais = 0;
    double mediasDasNotasFinais = 0;

    int notas[quantidadeDeAlunos][quantidadeDeColunas];
    int alunoComMaiorNota[2];

    for (int m = 0; m < quantidadeDeAlunos; m++) {
        int validador = 1;
        do {
            validador = 1;
            printf("(%d/%d) - Digite o RA, Notas das Provas e Trabalhos: ", m+1, quantidadeDeAlunos);
            scanf("%d %d %d", &notas[m][0], &notas[m][1], &notas[m][2] );

            for (int i = 0; (i < m) && validador != 0; i++) {
                if ((notas[i][0] == notas[m][0])) {
                    validador = 0;
                    printf("## Digite outro RA não escrito já na Listagem ##  \n");
                }                
            }
            
        } while (validador == 0);
    }

    for (int i = 0; i < quantidadeDeAlunos; i++) {
        notas[i][3] = notas[i][1] + notas[i][2];
    }

    alunoComMaiorNota[0] = notas[0][0];
    alunoComMaiorNota[1] = notas[0][3];
    somaDasNotasFinais = alunoComMaiorNota[1];

    for (int i = 1; i < quantidadeDeAlunos; i++) {

        if (alunoComMaiorNota[1] < notas[i][3]) {
            alunoComMaiorNota[0] = notas[i][0];
            alunoComMaiorNota[1] = notas[i][3];
        }

        somaDasNotasFinais += notas[i][3];
               
    }

    mediasDasNotasFinais = (double)somaDasNotasFinais/quantidadeDeAlunos;

    printf("\n\nA Nota mais alta foi %d do Aluno %d",alunoComMaiorNota[1], alunoComMaiorNota[0]);

    printf("\n\nA média dos alunos foram: %.2lf", mediasDasNotasFinais);
    return 0;
}