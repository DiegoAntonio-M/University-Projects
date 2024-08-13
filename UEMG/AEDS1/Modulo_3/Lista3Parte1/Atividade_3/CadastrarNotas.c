# include <stdio.h>
# include <math.h>
# include <stdlib.h>
# include <string.h>

#define QUANTCARACTER 40

typedef struct cadastroPessoa {
    char name[QUANTCARACTER+1];
    int nota;
}cadastroPessoa;

void removerQuerbraLinha(char *frase) {

    int tamanho = strlen(frase);
    if (tamanho > 0 && *(frase+tamanho - 1) == '\n') {
        frase[tamanho - 1] = '\0';
    }
}

void inserirTexto (char *gardarEm) {

    char textTemp[QUANTCARACTER+1] = {};
    fflush(stdin);
    setbuf(stdin,NULL);
    fgets(textTemp, QUANTCARACTER, stdin);

    removerQuerbraLinha(textTemp);

    strcpy(gardarEm, textTemp);
}

int main() {

    int quantidadeDePessoas = 5;
    cadastroPessoa listaDeCadastro[quantidadeDePessoas] = {};
    double soma = 0;
    double media = 0;
    double contar = 0;

    for (int i = 0; i < quantidadeDePessoas; i++) {
        printf("\n============== Pessoa [%d - %d] ==============\n", i+1, quantidadeDePessoas);
        fputs("Escreva o NOME da Pessoa: ", stdout);
        inserirTexto(listaDeCadastro[i].name);
        fputs("Digite a NOTA: ", stdout);
        scanf("%d", &listaDeCadastro[i].nota);
        soma = soma + listaDeCadastro[i].nota;
        contar++;
    }

    for (int i = 0; i < quantidadeDePessoas; i++) {
        printf("\n=========== #%d Pessoa Cadastrada ===========\n", i+1);
        printf("Nome: %s\n", listaDeCadastro[i].name);
        printf("Nota: %d\n", listaDeCadastro[i].nota);

    }    

    media = soma/contar;

    printf("\nA médias dos alunos são: %.4lf", media);
    return 0;
}