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


    FILE *arquivo;

    arquivo = fopen("Modulo_3\\Lista3Parte1\\Atividade_21\\CadastroNotas.txt","w");
    if (arquivo == NULL) {
        printf("Erro na abertura do arquivo.\n");
        system("pause");
        exit(1);
    }    

    int quantidadeDePessoas = 5;
    cadastroPessoa listaDeCadastro[quantidadeDePessoas] = {};

    for (int i = 0; i < quantidadeDePessoas; i++) {
        printf("\n============== Aluno [%d - %d] ==============\n", i+1, quantidadeDePessoas);
        fputs("Escreva o nome da Aluno: ", stdout);
        inserirTexto(listaDeCadastro[i].name);
        fputs("Digite a nota: ", stdout);
        scanf("%d", &listaDeCadastro[i].nota);
    }


    for (int i = 0; i < quantidadeDePessoas; i++) {
        fprintf(arquivo, "=========== #%d Aluno Cadastrado ===========\n", i+1);
        fprintf(arquivo, "Nome: %s\n", listaDeCadastro[i].name);
        fprintf(arquivo, "Nota: %d\n", listaDeCadastro[i].nota);
        fprintf(arquivo, "\n");
    } 
    
    for (int i = 0; i < quantidadeDePessoas; i++) {
        printf("\n=========== #%d Aluno Cadastrado ===========\n", i+1);
        printf("Nome: %s\n", listaDeCadastro[i].name);
        printf("Nota: %d\n", listaDeCadastro[i].nota);
    } 

    fclose(arquivo);

    return 0;
}