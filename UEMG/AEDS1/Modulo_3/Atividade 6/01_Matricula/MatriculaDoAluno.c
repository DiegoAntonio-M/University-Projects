# include <stdio.h>
# include <math.h>
# include <stdlib.h>
# include <string.h>

typedef struct matriculaDoAluno {

    int numeroMatricula;
    double notas[3];    
    double mediaGeral;
    char nomeAluno[40];
    char nomeCurso[40];

} matriculaDoAluno;

typedef struct guardarMaior {
    int idAlunoMaiorDasNota;
    int idAlunoMaiorDasMedia;
}guardarMaior;

// matriculaAluno registrarMatricula(int matr, char name[40], char curso[40], int notas, int idNota, int selectors[4]) {

// };

void removerQuerbraLinha(char *frase) {

    int tamanho = strlen(frase);
    if (tamanho > 0 && *(frase+tamanho - 1) == '\n') {
        frase[tamanho - 1] = '\0';
    }
}

void inserirTexto (char *gardarEm) {

    char textTemp[40] = {};
    fflush(stdin);
    setbuf(stdin,NULL);
    fgets(textTemp, 40, stdin);

    removerQuerbraLinha(textTemp);

    strcpy(gardarEm, textTemp);
}

guardarMaior cadastrarNota(matriculaDoAluno *alunoEscolhido, int *maiorNota, int idAluno, guardarMaior idMaiorAtual, double *maiorMedia) {
    
    div_t quantidadeNotas = div(sizeof(alunoEscolhido->notas), sizeof(alunoEscolhido->notas[0]));

    double soma = 0;
    double contar = 0;

    int maiorNotaInical = *maiorNota;
    double maiorMediaInicial = *maiorMedia;
    
    for (int i = 0; i < quantidadeNotas.quot; i++) {
        printf("Digite a %da no do Aluno: ", i+1);
        scanf("%lf", &alunoEscolhido->notas[i]);
        soma = soma + alunoEscolhido->notas[i];
        contar++;

        if ((alunoEscolhido->notas[i]) > *maiorNota) {
            *maiorNota = alunoEscolhido->notas[i];
        }        
    }

    double mediaTemp = soma/contar;
    alunoEscolhido->mediaGeral = mediaTemp;

    if (*maiorMedia < mediaTemp) {
        *maiorMedia = mediaTemp;
    }

    guardarMaior idAlunoMaior;

    if (maiorNotaInical < *maiorNota) {
        idAlunoMaior.idAlunoMaiorDasNota = idAluno;
    } else {
        idAlunoMaior.idAlunoMaiorDasNota = idMaiorAtual.idAlunoMaiorDasNota;
    }

    if (maiorMediaInicial < *maiorMedia) {
        idAlunoMaior.idAlunoMaiorDasMedia = idAluno;
    } else {
        idAlunoMaior.idAlunoMaiorDasMedia = idMaiorAtual.idAlunoMaiorDasMedia;
    }
    

    return idAlunoMaior;
}

int main() {

    guardarMaior idAlunoMaiorNota;
    int quantAluno = 5;

    int maiorNota = 0;
    double maiorMedia = 0;

    matriculaDoAluno aluno[quantAluno] = {};

    for (int i = 0; i < quantAluno; i++) {
        printf("\n\nAluno[%d/%d]\n", i+1, quantAluno);
        fputs("Digite o número da matrícula: ", stdout);
        scanf("%d", &aluno[i].numeroMatricula);

        fputs("Digite o seu nome: ", stdout);
        inserirTexto(aluno[i].nomeAluno);

        fputs("Digite o nome do curso: ", stdout);
        inserirTexto(aluno[i].nomeCurso);

        idAlunoMaiorNota = cadastrarNota(&aluno[i], &maiorNota, i, idAlunoMaiorNota, &maiorMedia);
    }
    
    printf("%d", idAlunoMaiorNota.idAlunoMaiorDasNota);
    printf("%d", idAlunoMaiorNota.idAlunoMaiorDasMedia);
    
    fputs("\n\nO aluno que obteve a Maior MEDIA foi:\n", stdout);
    printf("Matrícula: %d\n", aluno[idAlunoMaiorNota.idAlunoMaiorDasMedia].numeroMatricula);
    printf("Nome: %s\n", aluno[idAlunoMaiorNota.idAlunoMaiorDasMedia].nomeAluno);
    printf("Curso: %s\n", aluno[idAlunoMaiorNota.idAlunoMaiorDasMedia].nomeCurso);
    printf("As notas foram:");
    
    for (int i = 0, quantidadeNotas = sizeof(aluno[0].notas)/sizeof(aluno[0].notas[0]); i < quantidadeNotas; i++) {
        printf(" [%.2lf]", aluno[idAlunoMaiorNota.idAlunoMaiorDasMedia].notas[i]);
    }
    printf("\nMedia das Notas: [%lf]",  aluno[idAlunoMaiorNota.idAlunoMaiorDasMedia].mediaGeral);

    fputs("\n\nO aluno que obteve a Maior NOTA foi:\n", stdout);
    printf("Matrícula: %d\n", aluno[idAlunoMaiorNota.idAlunoMaiorDasNota].numeroMatricula);
    printf("Nome: %s\n", aluno[idAlunoMaiorNota.idAlunoMaiorDasNota].nomeAluno);
    printf("Curso: %s\n", aluno[idAlunoMaiorNota.idAlunoMaiorDasNota].nomeCurso);
    printf("As notas foram:");
    
    for (int i = 0, quantidadeNotas = sizeof(aluno[0].notas)/sizeof(aluno[0].notas[0]); i < quantidadeNotas; i++) {
        printf(" [%.2lf]", aluno[idAlunoMaiorNota.idAlunoMaiorDasNota].notas[i]);
    }
    printf("\nMedia das Notas: [%lf]",  aluno[idAlunoMaiorNota.idAlunoMaiorDasNota].mediaGeral);

    printf("\n====================================\n");
    matriculaDoAluno alunoAux;

    int movimentacoesPorCiclo = 0;
    do {
        movimentacoesPorCiclo = 0;
        for (int i = 0; i < quantAluno - 1; i++) {

            if (strcmp(aluno[i].nomeAluno, aluno[i + 1].nomeAluno) > 0) {

                alunoAux = aluno[i];
                aluno[i] = aluno[i + 1];
                aluno[i + 1] = alunoAux;
                movimentacoesPorCiclo++;
            }
            
        }
    } while (movimentacoesPorCiclo != 0);
        fputs("\n\n============ Os alunos ============\n", stdout);

    for (int i = 0; i < quantAluno; i++) {
        printf("Matrícula: %d\n", aluno[i].numeroMatricula);
        printf("Nome: %s\n", aluno[i].nomeAluno);
        printf("Curso: %s\n", aluno[i].nomeCurso);
        printf("As notas foram:");
        
        for (int ii = 0, quantidadeNotas = sizeof(aluno[0].notas)/sizeof(aluno[0].notas[0]); ii < quantidadeNotas; ii++) {
            printf(" [%.2lf]", aluno[i].notas[ii]);
        }
        printf("\nMedia das Notas: [%lf]\n",  aluno[i].mediaGeral);
        printf("\n")
    }


    return 0;
}