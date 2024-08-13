# include <stdio.h>
# include <math.h>
# include <stdlib.h>
# include <string.h>

#define QUANTCARACTER 40

typedef struct cadastroPessoa {
    char name[QUANTCARACTER+1];
    char corEyes;
    char corHair;
    char sexo;
    int idade;
}cadastroPessoa;

void removerQuerbraLinha(char *frase) {

    int tamanho = strlen(frase);
    if (tamanho > 0 && *(frase+tamanho - 1) == '\n') {
        frase[tamanho - 1] = '\0';
    }
}

void limparBuffer() {
    fflush(stdin);
    setbuf(stdin,NULL);
}

void inserirTexto (char *gardarEm) {

    char textTemp[QUANTCARACTER+1] = {};
    limparBuffer();
    fgets(textTemp, QUANTCARACTER, stdin);

    removerQuerbraLinha(textTemp);

    strcpy(gardarEm, textTemp);
}



void cadastrarPessoa (cadastroPessoa *pessoa, int pessoaAtual, int quantidadeDePessoas) {
    printf("\n============== Pessoa [%d - %d] ==============\n", pessoaAtual+1, quantidadeDePessoas);
    fputs("Escreva o nome da Pessoa: ", stdout);
    inserirTexto(pessoa->name);
    fputs("Digite a idade: ", stdout);
    scanf("%d", &pessoa->idade);
    fputs("Digite o sexo [F|M]: ", stdout);
    limparBuffer();
    scanf("%c", &pessoa->sexo);
    fputs("Digite a cor dos olhos [A: Azul | C: Castanho]: ", stdout);
    limparBuffer();
    scanf("%c", &pessoa->corEyes);
    fputs("Digite a cor dos olhos [L: Louro | P: Preto | C: Castanho]: ", stdout);
    limparBuffer();
    scanf("%c", &pessoa->corHair);
}

double fazerMediaDasIdades(cadastroPessoa *listaDePessoas, int quantidadeDePessoas) {
    double soma = 0;
    double quantidade = quantidadeDePessoas;
    for (int i = 0; i < quantidadeDePessoas; i++) {
        soma += listaDePessoas[i].idade;
    }
    return soma / quantidade;
}

double procurarMaiorIdade (cadastroPessoa *listaDePessoas, int quantidadeDePessoas) {
    double maiorIdade = 0;
    for (int i = 0; i < quantidadeDePessoas; i++) {
        if(listaDePessoas[i].idade > maiorIdade) {
            maiorIdade = listaDePessoas[i].idade;
        }
    }
    return maiorIdade;
}


# define IGNORE -1
int pesquisarQuantidade(cadastroPessoa *listaDePessoas, int quantidadeDePessoas, int idadeMin, int idadeMax, char procSexo, char procEyes, char procHair) {
    int contar = 0;
    for (int i = 0; i < quantidadeDePessoas; i++) {
        if((idadeMin <= listaDePessoas[i].idade) && (listaDePessoas[i].idade <= idadeMax)) {
            if ((listaDePessoas[i].sexo == procSexo) || procSexo == IGNORE) {
                if ((listaDePessoas[i].corEyes == procEyes) || procEyes == IGNORE) {
                    if ((listaDePessoas[i].corHair == procHair) || procHair == IGNORE) {
                        contar++;
                    }                
                }  
            }
        }
    }
    return contar;
}

int main() {

    int quantidadeDePessoas = 5;

    cadastroPessoa *listaDeCadastro = malloc(quantidadeDePessoas * sizeof(cadastroPessoa));
    if (listaDeCadastro == NULL) {
        printf("Falha ao alocar memória.\n");
        return 1;
    } else {
        for (int i = 0; i < quantidadeDePessoas; i++) {
            cadastroPessoa cadastroNULL = {};
            listaDeCadastro[i] = cadastroNULL;
        }
    }
    

    for (int i = 0; i < quantidadeDePessoas; i++) {
        cadastrarPessoa(&listaDeCadastro[i], i, quantidadeDePessoas);
    }

    printf("\nA media das idades sao: %.1lf\n", fazerMediaDasIdades(listaDeCadastro, quantidadeDePessoas));
    printf("\nA maior idades eh: %.1lf\n", procurarMaiorIdade(listaDeCadastro, quantidadeDePessoas));
    printf("\nA correspondência foi de: %d\n", pesquisarQuantidade(listaDeCadastro, quantidadeDePessoas, 18, 35, 'F', 'A', 'L'));

    for (int i = 0; i < quantidadeDePessoas; i++) {
        printf("\n=========== #%d Pessoa Cadastrada ===========\n", i+1);
        printf("Nome: %s\n", listaDeCadastro[i].name);
        printf("Idade: %d\n", listaDeCadastro[i].idade);
        printf("Sexo: %c\n", listaDeCadastro[i].sexo);
        printf("Cor dos Olhos: %c\n", listaDeCadastro[i].corEyes);
        printf("Cor do Cabelo: %c", listaDeCadastro[i].corHair);
    }
    
    return 0;
}