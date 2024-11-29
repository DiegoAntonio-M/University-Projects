#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Estrutura para um vetor dinâmico de inteiros
typedef struct vetorDinamico {
    int quantElementos; // Quantidade de elementos alocados no vetor
    int *array;         // Ponteiro para os elementos do vetor
    int pointWR;        // Índice para a próxima posição de escrita
} vetorDinamico;

// Estrutura para armazenar o resultado de uma busca
typedef struct resultado {
    bool encontrado;    // Indica se o valor foi encontrado
    int position;       // Posição do valor, se encontrado
} resultado;

// Estrutura para armazenar informações de um aluno
typedef struct aluno {
    char nome[50];      // Nome do aluno
    int matricula;      // Matrícula do aluno
    double nota1;       // Notas do aluno
    double nota2;       // Notas do aluno
    double nota3;       // Notas do aluno
    double media;       // Média das notas
} aluno;

// Estrutura para armazenar um cadastro de alunos
typedef struct cadastroAlunos {
    int quantElementos; // Quantidade de elementos alocados no cadastro
    aluno *alunos;      // Ponteiro para os alunos
    int pointWR;        // Índice para a próxima posição de escrita
} cadastroAlunos;

// Inicializa um vetor de inteiros com o tamanho especificado
int completarCriacao(int **vetor, int tamanhoInicial) {
    if (tamanhoInicial < 1) tamanhoInicial = 1;
    *vetor = (int *)calloc(tamanhoInicial, sizeof(int));
    if (*vetor == NULL) {
        fputs("### Não foi possível alocar o vetor ###", stdout);
        exit(1);
    }
    return tamanhoInicial;
}

// Inicializa um vetor de alunos com o tamanho especificado
int completarCriacaoAluno(aluno **vetor, int tamanhoInicial) {
    if (tamanhoInicial < 1) tamanhoInicial = 1;
    *vetor = (aluno *)calloc(tamanhoInicial, sizeof(aluno));
    if (*vetor == NULL) {
        fputs("### Não foi possível alocar o vetor ###", stdout);
        exit(1);
    }
    return tamanhoInicial;
}

// Função para exibir e processar o menu de opções
int menu(char *options[], int quantOptions, bool isMain) {
    int option = 0;
    do {
        setbuf(stdin, NULL);
        fputs("\nSelecione: \n", stdout);
        for (int i = 0; i < quantOptions; i++) {
            printf("%d - %s;\n", (i + 1), options[i]);
        }
        printf("%d - %s.\n", (quantOptions + 1), (isMain ? "Sair" : "Voltar (<--)"));
        fputs(">>> ", stdout);
        
        char c[3];
        fgets(c, sizeof(c), stdin);
        option = atoi(c);

        if (option == quantOptions + 1) {
            option = -1;
        }

    } while (!((1 <= option && option <= quantOptions) || (option == -1)));

    return option;
}

// Realoca o vetor dinâmico para suportar uma nova quantidade de elementos
int alocarElementos(vetorDinamico *vetor, int quantDeElementos) {
    if (vetor->quantElementos < quantDeElementos) {
        vetor->array = (int *)realloc(vetor->array, sizeof(int) * quantDeElementos);
        if (vetor->array == NULL) {
            fputs("### Não foi possível alocar o vetor ###", stdout);
            exit(1);
        } else {
            vetor->quantElementos = quantDeElementos;
        }
    } else {
        fputs("\n\n<#### Número de Elementos igual ou menor do que o já existente ####>\n", stdout);
        return 0;
    }
    return 1;
}

// Realoca o cadastro de alunos para suportar uma nova quantidade de alunos
int alocarElementosAluno(cadastroAlunos *vetor, int quantDeElementos) {
    if (vetor->quantElementos < quantDeElementos) {
        vetor->alunos = (aluno *)realloc(vetor->alunos, sizeof(aluno) * quantDeElementos);
        if (vetor->alunos == NULL) {
            fputs("### Não foi possível alocar o vetor ###", stdout);
            exit(1);
        } else {
            vetor->quantElementos = quantDeElementos;
        }
    } else {
        fputs("\n\n<#### Número de Elementos igual ou menor do que o já existente ####>\n", stdout);
        return 0;
    }
    return 1;
}

// Adiciona um valor ao vetor dinâmico, se houver espaço
int addPoint(vetorDinamico *vetor, int value) {
    if (vetor->pointWR < vetor->quantElementos) {
        vetor->array[vetor->pointWR] = value;
        vetor->pointWR++;
    } else {
        fputs("\n\n<#### Não há espaço para adicionar, aumente a quantidade de elementos ####>\n", stdout);
    }
    return 1;
}

// Ordena o vetor dinâmico usando o método de bubble sort
void ordenar(vetorDinamico *vetor) {
    for (int i = 0; i < vetor->pointWR - 1; i++) {
        for (int j = 0; j < vetor->pointWR - i - 1; j++) {
            if (vetor->array[j] > vetor->array[j + 1]) {
                int temp = vetor->array[j];
                vetor->array[j] = vetor->array[j + 1];
                vetor->array[j + 1] = temp;
            }
        }
    }
}

// Ordena o cadastro de alunos por matrícula usando bubble sort
void ordenarAluno(cadastroAlunos *CadAlunos) {
    for (int i = 0; i < CadAlunos->pointWR - 1; i++) {
        for (int j = 0; j < CadAlunos->pointWR - i - 1; j++) {
            if (CadAlunos->alunos[j].matricula > CadAlunos->alunos[j + 1].matricula) {
                aluno temp = CadAlunos->alunos[j];
                CadAlunos->alunos[j] = CadAlunos->alunos[j + 1];
                CadAlunos->alunos[j + 1] = temp;
            }
        }
    }
}

// Realiza uma busca sequencial em um vetor dinâmico de inteiros
resultado buscaSequencial(vetorDinamico *vetor, int valor) {
    resultado resultadoSeg = {};
    for (int i = 0; i < vetor->pointWR; i++) {
        if (vetor->array[i] == valor) {
            resultadoSeg.encontrado = true;
            resultadoSeg.position = i;
            return resultadoSeg;
        }
    }
    return resultadoSeg;
}

// Faz a usca sequencial de alunos pela matrícula 
resultado buscaSequencialAluno(cadastroAlunos *CadAlunos, int valor) {
    resultado resultadoSeg = {};
    for (int i = 0; i < CadAlunos->pointWR; i++) {
        if (CadAlunos->alunos[i].matricula == valor) {
            resultadoSeg.encontrado = true;
            resultadoSeg.position = i+1;
            return resultadoSeg;
        }
    }
    return resultadoSeg;
}

// Busca Binária em vetores
resultado buscaBinaria(vetorDinamico *vetor, int valor) {
    resultado resultadoBin = {};
    int left = 0;
    int right = vetor->pointWR - 1;

    while (left <= right) {
        int meio = left + (right - left) / 2;
        if (vetor->array[meio] == valor) {
            resultadoBin.encontrado = true;
            resultadoBin.position = meio;
            return resultadoBin;
        }
        if (vetor->array[meio] < valor) {
            left = meio + 1;
        } else {
            right = meio - 1;
        }
    }

    return resultadoBin;
}

// Faz a busca Binária pelo valor da Matatrícula
resultado buscaBinariaAluno(cadastroAlunos *CadAlunos, int valor) {
    resultado resultadoBin = {};
    int left = 0;
    int right = CadAlunos->pointWR - 1;

    while (left <= right) {
        int meio = left + (right - left) / 2;
        if (CadAlunos->alunos[meio].matricula == valor) {
            resultadoBin.encontrado = true;
            resultadoBin.position = meio;
            return resultadoBin;
        }
        if (CadAlunos->alunos[meio].matricula < valor) {
            left = meio + 1;
        } else {
            right = meio - 1;
        }
    }

    return resultadoBin;
}

// Cadatra uma unidade de aluno
void addAluno(cadastroAlunos *CadAlunos) {
    for (; CadAlunos->pointWR < CadAlunos->quantElementos; CadAlunos->pointWR++) {
        printf("Aluno %d:\n", CadAlunos->pointWR + 1);
        printf("Nome: ");
        scanf("%s", &CadAlunos->alunos[CadAlunos->pointWR].nome);
        printf("Matricula: ");
        scanf("%d", &CadAlunos->alunos[CadAlunos->pointWR].matricula);
        printf("Nota 1: ");
        scanf("%lf", &CadAlunos->alunos[CadAlunos->pointWR].nota1);
        printf("Nota 2: ");
        scanf("%lf", &CadAlunos->alunos[CadAlunos->pointWR].nota2);
        printf("Nota 3: ");
        scanf("%lf", &CadAlunos->alunos[CadAlunos->pointWR].nota3);
        CadAlunos->alunos[CadAlunos->pointWR].media = (CadAlunos->alunos[CadAlunos->pointWR].nota1 + CadAlunos->alunos[CadAlunos->pointWR].nota2 + CadAlunos->alunos[CadAlunos->pointWR].nota3) / 3;
        printf("Média: %.2lf\n\n", CadAlunos->alunos[CadAlunos->pointWR].media);
    }
}

// Função de Impressão
void imprimirAluno(aluno *aluno) {
    printf("Nome: %s\n", aluno->nome);
    printf("Matricula: %d\n", aluno->matricula);
    printf("Nota 1: %.2lf\n", aluno->nota1);
    printf("Nota 2: %.2lf\n", aluno->nota2);
    printf("Nota 3: %.2lf\n", aluno->nota3);
    printf("Média: %.2lf\n\n", aluno->media);
}

int main() {

    // Declara e inicializa estruturas para armazenar os vetores e cadastro de alunos.
    vetorDinamico vetor = {};
    cadastroAlunos CadAlunos = {};

    // Inicializa vetor de inteiros com tamanho mínimo de 1.
    vetor.quantElementos = completarCriacao(&vetor.array, 1);
    // Inicializa vetor de alunos com tamanho mínimo de 1.
    CadAlunos.quantElementos = completarCriacaoAluno(&CadAlunos.alunos, 1);

    // Define as opções do menu principal para facilitar a manipulação de vetores e cadastro de alunos.
    char *optionsMain[] = {
        "Manipular Vetores",
        "Cadastro Alunos"
    };
    int menuMainQuant = sizeof(optionsMain) / sizeof(optionsMain[0]);

    bool continuar = true;  // Controla a execução do loop principal.
    int indiceMenu = 0;     // Conta o número de seleções no menu para controle.

    // Loop principal do programa.
    do {
        indiceMenu++;
        fputs("\n================================================================", stdout);
        printf("[%d]", indiceMenu);

        // Chama o menu principal e executa a ação com base na opção selecionada.
        switch (menu(optionsMain, menuMainQuant, true)) {
        case 1: // Opção para manipulação de vetores.

            // Define as opções do menu para operações com vetores.
            char *options[] = {
                "Inserir Número",
                "Busca Sequencial",
                "Busca Binária",
            };
            int menuVetorQuant = sizeof(options) / sizeof(options[0]);

            int continuarVetor = 1;  // Controla o loop de operações com vetores.
            do {
                indiceMenu++; // Cabeçalho do Menu
                fputs("\n================================================================", stdout);
                printf("[%d]", indiceMenu);

                // Executa a ação de acordo com a opção do menu de vetores.
                switch (menu(options, menuVetorQuant, false)) {
                    case 1: { // Opção para inserir número no vetor.
                        int continuarC1 = 1;
                        do {
                            indiceMenu++;
                            fputs("\n================================================================", stdout);
                            printf("[%d]", indiceMenu);
                            printf("\n[%d] Total de Elementos\n[%d] Elementos preenchidos\n", vetor.quantElementos, vetor.pointWR);
                            char *optionsC1[] = {
                                "Reservar quantidade de Elementos",
                                "Adicionar Valor a um elemento",
                            };
                            int menuC1 = sizeof(optionsC1) / sizeof(optionsC1[0]);

                            // Executa a ação de acordo com a opção de reserva e adição de elementos.
                            switch (menu(optionsC1, menuC1, false)) {
                                case 1: { // Reserva espaço para novos elementos no vetor.
                                    int quantidadeAddReservar = 0;
                                    printf("Escolha a quantidade de Aluno >>> ");
                                    scanf("%d", &quantidadeAddReservar);
                                    alocarElementos(&vetor, quantidadeAddReservar);
                                    break;
                                }
                                case 2: { // Adiciona valor a um elemento do vetor.
                                    int num = 0;
                                    printf("Escreva o Valor[int] para Adicionar >>> ");
                                    scanf("%d", &num);
                                    addPoint(&vetor, num);
                                    break;
                                }
                                case -1:
                                    continuarC1 = 0;  // Sai do loop de adição de valores.
                                    break;
                                default:
                                    break;
                            }
                            indiceMenu--;
                        } while (continuarC1 == 1);
                        break;
                    }
                    case 2: { // Busca sequencial no vetor.
                        int valor = 0;
                        printf("Digite o valor para buscar >>> ");
                        scanf("%d", &valor);
                        resultado resultadoSeg = buscaSequencial(&vetor, valor);
                        if (resultadoSeg.encontrado) {
                            printf("Valor %d encontrado na posição %d.\n", valor, resultadoSeg.position);
                        } else {
                            printf("Valor %d não encontrado.\n", valor);
                        }
                        break;
                    }
                    case 3: { // Busca binária no vetor após ordenação.
                        int valor = 0;
                        printf("Digite o valor para buscar [Ordenação automática] >>> ");
                        scanf("%d", &valor);

                        ordenar(&vetor);

                        resultado resultadoBin = buscaBinaria(&vetor, valor);
                        if (resultadoBin.encontrado) {
                            printf("Valor %d encontrado na posição %d.\n", valor, resultadoBin.position);
                        } else {
                            printf("Valor %d não encontrado.\n", valor);
                        }
                        break;
                    }
                    case -1:
                        continuarVetor = 0; // Sai do loop de operações de vetor.
                        break;
                    default:
                        break;
                }
                indiceMenu--;
            } while (continuarVetor == 1);
            break;

        case 2: // Opção para manipulação do cadastro de alunos.

            int continuarC1 = 1;  // Controla o loop de operações com alunos.
            do {
                indiceMenu++;
                fputs("\n================================================================", stdout);
                printf("[%d]", indiceMenu);
                printf("\n[%d] Total de Elementos\n[%d] Elementos preenchidos\n", CadAlunos.quantElementos, CadAlunos.pointWR);
                char *optionsC1[] = {
                    "Escolher quantitade de Aluno",
                    "Adiconar Alunos",
                    "Busca Sequencial",
                    "Busca Binária",
                    "Imprimir Alunos"
                };
                int menuC1 = sizeof(optionsC1) / sizeof(optionsC1[0]);

                // Executa a ação de acordo com a opção do menu de alunos.
                switch (menu(optionsC1, menuC1, false)) {
                    case 1: { // Define a quantidade de alunos.
                        int quantidadeAddReservar = 0;
                        printf("Escolha a quantidade de Elementos >>> ");
                        scanf("%d", &quantidadeAddReservar);
                        alocarElementosAluno(&CadAlunos, quantidadeAddReservar);
                        break;
                    }
                    case 2: { // Adiciona novos alunos.
                        addAluno(&CadAlunos);
                        break;
                    }
                    case 3: { // Realiza busca sequencial no cadastro de alunos.
                        int valor = 0;
                        printf("Digite o valor para buscar [Primeira Correspondencia] >>> ");
                        scanf("%d", &valor);
                        resultado resultadoSeg = buscaSequencialAluno(&CadAlunos, valor);
                        if (resultadoSeg.encontrado) {
                            printf("\nValor %d encontrado na posição %d.\n\n", valor, resultadoSeg.position + 1);
                        } else {
                            printf("\nValor %d não encontrado.\n\n", valor);
                        }
                        break;
                    }
                    case 4: { // Realiza busca binária no cadastro de alunos após ordenação.
                        int valor = 0;
                        printf("Digite o valor para buscar [Ordenação automática][Primeira Correspondencia] >>> ");
                        scanf("%d", &valor);

                        ordenarAluno(&CadAlunos);

                        resultado resultadoBin = buscaBinariaAluno(&CadAlunos, valor);
                        if (resultadoBin.encontrado) {
                            printf("\nAluno %d encontrado na posição %d.\n\n", valor, resultadoBin.position + 1);
                        } else {
                            printf("\nAluno %d não encontrado.\n\n", valor);
                        }
                        break;
                    }
                    case 5: { // Imprime informações dos alunos cadastrados.
                        for (int i = 0; i < CadAlunos.quantElementos; i++) {
                            imprimirAluno(&CadAlunos.alunos[i]);
                        }
                        break;
                    }
                    case -1:
                        continuarC1 = 0; // Sai do loop de operações com alunos.
                        break;
                    default:
                        break;
                }
                indiceMenu--;
            } while (continuarC1 == 1);
        
        default:
            break;
        }
        indiceMenu--;
    } while (continuar == true);

    // Libera a memória alocada para os vetores ao finalizar o programa.
    free(vetor.array);
    free(CadAlunos.alunos);

    return 0;
}