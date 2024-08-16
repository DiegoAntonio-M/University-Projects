#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAMANHO_STRING 50

typedef struct Funcionario {
    char nome[TAMANHO_STRING];
    int idade;
    float salario;
} Funcionario;

typedef struct BancoDeFuncionarios {
    int quantFuncionarios;
    Funcionario *funcionarios;
    int endPoint;
} BancoDeFuncionarios;

void limparBuffer() {
    fflush(stdin);
    setbuf(stdin, NULL);
}

int completarCriacaoBdFuncionario(BancoDeFuncionarios *bd, int tamanhoInicial) {
    (tamanhoInicial < 1) ? tamanhoInicial = 1 : tamanhoInicial;
    bd->quantFuncionarios = tamanhoInicial;
    bd->funcionarios = calloc(bd->quantFuncionarios, sizeof(Funcionario));
    if (bd->funcionarios == NULL) {
        printf("Falha ao alocar memória.\n");
        return 1;
        exit(-1);
    } else {
        Funcionario arrayNULL[bd->quantFuncionarios] = {};
        for (int j = 0; j < bd->quantFuncionarios; j++) {
            bd->funcionarios[j] = arrayNULL[j];
        }
    }    
    return 0;
}

int alocarFuncionarios(BancoDeFuncionarios *bd, int adicao, int limite) {
    (adicao < 1) ? adicao = 1 : adicao;
    (limite < 1) ? limite = 1 : limite;
    int cleaner = bd->endPoint;
    while (bd->quantFuncionarios - bd->endPoint < limite) {
        bd->quantFuncionarios += adicao;
        bd->funcionarios = realloc(bd->funcionarios, bd->quantFuncionarios * sizeof(Funcionario));
        if (bd->funcionarios == NULL) {
            printf("Falha ao alocar memória.\n");
            exit(-1);
        }
        Funcionario arrayNULL[bd->quantFuncionarios] = {};
        for (int i = cleaner; i < bd->quantFuncionarios; i++, cleaner++) {
            bd->funcionarios[i] = arrayNULL[i];
        }
        
    }
    return 0;
}

void removerQuebraLinha(char *frase) {

    int tamanho = strlen(frase);
    if (tamanho > 0 && *(frase+tamanho - 1) == '\n') {
        frase[tamanho - 1] = '\0';
    }
    if (tamanho > 0 && *(frase+tamanho - 1) == ' ') {
        frase[tamanho - 1] = '\0';
    }
}

void adicionarFuncionario(BancoDeFuncionarios *bd) {
    alocarFuncionarios(bd, 1, 1);
    Funcionario novoFunc = {};

    fputs("\n========== Adição Funcionario ==========\n", stdout);

    fputs("Nome do funcionário: ", stdout);
    limparBuffer();
    fgets(novoFunc.nome, TAMANHO_STRING, stdin);
    removerQuebraLinha(novoFunc.nome);

    fputs("Idade do funcionário: ", stdout);
    limparBuffer();
    scanf("%d", &novoFunc.idade);
    
    fputs("Salário do funcionário: ", stdout);
    limparBuffer();
    scanf("%f", &novoFunc.salario);

    bd->funcionarios[bd->endPoint++] = novoFunc;

    FILE *arquivo = fopen("Modulo_3\\Lista3Parte1\\Atividade_24\\dados.bin", "ab");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        exit(1);
    }
    fwrite(&novoFunc, sizeof(Funcionario), 1, arquivo);
    fclose(arquivo);
}

void listarFuncionarios() {
    FILE *arquivo = fopen("Modulo_3\\Lista3Parte1\\Atividade_24\\dados.bin", "rb");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        exit(1);
    }
    fputs("\n=========== Lista Funcionario ==========\n", stdout);
    Funcionario func = {};
    while (fread(&func, sizeof(Funcionario), 1, arquivo)) {
        printf("Nome: %s\n", func.nome);
        printf("Idade: %d\n", func.idade);
        printf("Salário: %.2f\n\n", func.salario);
    }

    fclose(arquivo);
}

void buscarFuncionario() {
    int pesquisarDenovo = 0;
    do {

        FILE *arquivo = fopen("Modulo_3\\Lista3Parte1\\Atividade_24\\dados.bin", "rb");
        if (arquivo == NULL) {
            printf("Erro ao abrir o arquivo.\n");
            exit(1);
        }

        char procNome[TAMANHO_STRING + 2] = {};
        fputs("Procure por -> ", stdout);    
        limparBuffer();
        fgets(procNome, TAMANHO_STRING, stdin);
        removerQuebraLinha(procNome);
        fputs("\n", stdout);

        Funcionario func = {};
        int foiEncontrado = 0;
        fputs("\n========== Buscar Funcionario ==========\n", stdout);
        while (fread(&func, sizeof(Funcionario), 1, arquivo)) {
            int validarNome = 0;
            int tamNomeFuncionario = strlen(func.nome);
            int tamProcNome = strlen(procNome);
            int tamanhoMin = (tamNomeFuncionario < tamProcNome) ? tamNomeFuncionario : tamProcNome;

            for (int p = 0; p < tamanhoMin; p++) {
                if (func.nome[p] == procNome[p]) {
                    validarNome = 1;
                } else {
                    validarNome = 0;
                    break;
                }
            }

            if (validarNome == 1) {
                printf(">Nome: %s\n", func.nome);
                printf(" >> Idade: %d\n", func.idade);
                printf(" >> Salário: %.2f\n\n", func.salario);
            }
            foiEncontrado += validarNome;
        }
        
        if (foiEncontrado == 0) {
            fputs("!#!#! Não encontrado !#!#!\n", stdout);
        }

        fclose(arquivo);

        fputs(">> Você deseja pesquisar novamente? [Sim = 1 | Não = 0]: ", stdout);
        limparBuffer();
        scanf("%d", &pesquisarDenovo);
    } while (pesquisarDenovo == 1);
}

int main() {
    BancoDeFuncionarios bd = {};
    completarCriacaoBdFuncionario(&bd, 1);

    int opcao;
    do {
        fputs("\n================= MENU =================\n", stdout);
        fputs("1. Adicionar funcionário\n", stdout);
        fputs("2. Listar funcionários\n", stdout);
        fputs("3. Buscar funcionário\n", stdout);
        fputs("4. Sair\n", stdout);
        fputs(">> Escolha uma opção: ", stdout);
        limparBuffer();
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                adicionarFuncionario(&bd);
                break;
            case 2:
                listarFuncionarios();
                break;
            case 3:
                buscarFuncionario();
                break;
            case 4:
                break;
            default:
                printf("Opção inválida.\n");
        }
    } while (opcao != 4);

    free(bd.funcionarios);
    return 0;
}