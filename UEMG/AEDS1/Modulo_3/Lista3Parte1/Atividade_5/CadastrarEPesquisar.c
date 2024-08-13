# include <stdio.h>
# include <math.h>
# include <stdlib.h>
# include <string.h>

#define QUANTCARACTER 40

typedef struct cadastroPessoa {
    char name[QUANTCARACTER+1];
    int idade;
    double salario;
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
    char procAluno[QUANTCARACTER + 2] = {};

    for (int i = 0; i < quantidadeDePessoas; i++) {
        printf("\n============== Pessoa [%d - %d] ==============\n", i+1, quantidadeDePessoas);
        fputs("Escreva o nome da Pessoa: ", stdout);
        inserirTexto(listaDeCadastro[i].name);
        fputs("Digite a idade: ", stdout);
        scanf("%d", &listaDeCadastro[i].idade);
        fputs("Digite a salário: ", stdout);
        scanf("%lf", &listaDeCadastro[i].salario);
    }

    for (int i = 0; i < quantidadeDePessoas; i++) {
        printf("\n=========== #%d Pessoa Cadastrada ===========\n", i+1);
        printf("Nome: %s\n", listaDeCadastro[i].name);
        printf("Idade: %d\n", listaDeCadastro[i].idade);
        printf("Salário: %.2lf\n", listaDeCadastro[i].salario);

    }

    fputs("\n\n", stdout);

    int pesquisarDenovo = 0;
    do {
        fputs("Procure por -> ", stdout);    
        inserirTexto(procAluno);
        fputs("\n", stdout);
        int foiEncontrado = 0;

        for (int i = 0; i < quantidadeDePessoas; i++) {

            int validarNome = 0;
            int tamAluno = strlen(listaDeCadastro[i].name);
            int tamProcAluno = strlen(procAluno);
            int tamanhoMin = 0;

            tamAluno < tamProcAluno ? tamanhoMin = tamAluno : (tamanhoMin = tamProcAluno);

            for (int p = 0; p < tamanhoMin; p++) {
                if (listaDeCadastro[i].name[p] == procAluno[p]) {
                    validarNome = 1;
                } else {
                    validarNome = 0;
                    break;
                }
            }

            if (validarNome == 1) {
                printf("Indice [%d] >> %s.\n", i, listaDeCadastro[i].name);

                int editar = 0;
                printf("Você deseja editar o salario de %s ? [Sim = 1 | Não = 0]: ", listaDeCadastro[i].name);
                scanf("%d", &editar);

                if (editar == 1) {
                    printf("Salário atual: R$ %.2lf\n", listaDeCadastro[i].salario);
                    fputs("Digite o novo salário: ", stdout);
                    scanf("%lf", &listaDeCadastro[i].salario);
                    fputs("++ Salário atualizado ++\n\n", stdout);
                } else {
                    fputs("## Salário mantido ##\n\n", stdout);
                }
                
            }
            foiEncontrado =+ validarNome;

        }
        
        (foiEncontrado == 0) ? fputs("!#!#! Não encontrado !#!#!\n", stdout) : fputs("", stdout) ;

        fputs(">> Você deseja pesquisar novamente ? [Sim = 1 | Não = 0]: ", stdout);
        scanf("%d", &pesquisarDenovo);
    } while (pesquisarDenovo == 1);
    


    for (int i = 0; i < quantidadeDePessoas; i++) {
        printf("\n========= #%d Pessoa Cadastrada Atual =====\n", i+1);
        printf("Nome: %s\n", listaDeCadastro[i].name);
        printf("Idade: %d\n", listaDeCadastro[i].idade);
        printf("Salário: %.2lf\n", listaDeCadastro[i].salario);

    }

    return 0;
}