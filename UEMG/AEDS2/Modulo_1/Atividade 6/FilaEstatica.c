// Turma: Engenharia da Computação - UEMG.
// Atividade 12 - TP 03.5 Fila Estática

# include <stdio.h>
# include <math.h>
# include <stdlib.h>
# include <string.h>
# include <stdbool.h>

# define MAX 5

// Estrutura para armazenar informações de um aluno
typedef struct aluno {
    char nome[50];      // Nome do aluno
    int matricula;      // Matrícula do aluno
    double nota1;       // Notas do aluno
    double nota2;       // Notas do aluno
    double nota3;       // Notas do aluno
    double media;       // Média das notas
} aluno;

typedef struct fila {
    int quantElementos; // Quantidade de elementos alocados no vetor
    aluno alunos[MAX];  // Ponteiro para os elementos do vetor
    int front;          // Índice para a próxima posição de leitura
    int rear;           // Índice para a próxima posição de escrita
} fila;

// Estrutura para armazenar o resultado de uma busca
typedef struct resultado {
    bool encontrado;    // Indica se o valor foi encontrado
    int position;       // Posição do valor, se encontrado
} resultado;

// Função para exibir e processar o menu de opções
int menu(char* options[], int quantOptions, bool isMain) {
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

double imprimirNotaFinal(aluno* aluno) {
    return aluno->nota1 + aluno->nota2 + aluno->nota3;
}

void fgetsCleanedByStdin(char* out, int save, bool isTrim) {
    char c;
    if (isTrim == true) save--;
    for (int i = 0; ((c = fgetchar()) != '\n') && (c != EOF || c != '\000'); i++) {
        if (i < save) {
            out[i] = c;
        }
    }
    if (isTrim == true) out[save] = 0;
}

// Função de Impressão
void imprimirAluno(aluno* aluno) {
    printf("Nome: %s\n", aluno->nome);
    printf("Matricula: %d\n", aluno->matricula);
    printf("Nota 1: %.2lf\n", aluno->nota1);
    printf("Nota 2: %.2lf\n", aluno->nota2);
    printf("Nota 3: %.2lf\n", aluno->nota3);
    printf("Média: %.2lf\n\n", aluno->media);
}

// Função de Impressão Final
void imprimirAlunoNotaFinal(aluno* aluno) {
    printf("Nome: %s\n", aluno->nome);
    printf("Matricula: %d\n", aluno->matricula);
    printf("Nota 1: %.2lf\n", aluno->nota1);
    printf("Nota 2: %.2lf\n", aluno->nota2);
    printf("Nota 3: %.2lf\n", aluno->nota3);
    printf("Média: %.2lf\n", aluno->media);
    double notaFinal = imprimirNotaFinal(aluno);
    printf("Nota Final: %.2lf\n\n", notaFinal);
    printf("Situação: ");
    if (notaFinal <= 40) {
        printf("Reprovado!!!\n\n");
    }
    if ((40 < notaFinal) && (notaFinal < 60)) {
        printf("Exame Especial !!!\n\n");
    }

    if (60 <= notaFinal) {
        printf("Aprovado!!!\n\n");
    }
}

// Compara a string em ordem alfabética (Tipo "strcmp")
int compararOrdemAlfabetica(const char* str1, const char* str2) {
    for (int i = 0; str1[i] != '\0' && str2[i] != '\0'; i++) {
        if (str1[i] != str2[i]) {
            return str1[i] - str2[i];
        }
    }
    return str1[strlen(str1)] - str2[strlen(str2)];
}

// Faz a busca sequencial de alunos pela matrícula
resultado buscaSequencialAluno(fila* CadAlunos, int valor) {
    resultado resultadoSeg = {};
    for (int i = CadAlunos->front; i < CadAlunos->rear; i++) {
        if (CadAlunos->alunos[i].matricula == valor) {
            resultadoSeg.encontrado = true;
            resultadoSeg.position = i;
            return resultadoSeg;
        }
    }
    return resultadoSeg;
}

// Faz a busca sequencial de alunos pelo nome
resultado buscaSequencialAlunoNome(fila* CadAlunos, char* nome) {
    resultado resultadoSeg = {};
    for (int i = CadAlunos->front; i < CadAlunos->rear; i++) {
        if (compararOrdemAlfabetica(CadAlunos->alunos[i].nome, nome) == 0) {
            resultadoSeg.encontrado = true;
            resultadoSeg.position = i;
            return resultadoSeg;
        }
    }
    return resultadoSeg;
}

// Ordena o cadastro de alunos por matrícula usando bubble sort (Por Matrícula)
void ordenarAlunoByMatricula(fila* CadAlunos) {
    for (int i = CadAlunos->front; i < CadAlunos->rear - 1; i++) {
        for (int j = CadAlunos->front; j < CadAlunos->rear - i - 1; j++) {
            if (CadAlunos->alunos[j].matricula > CadAlunos->alunos[j + 1].matricula) {
                aluno temp = CadAlunos->alunos[j];
                CadAlunos->alunos[j] = CadAlunos->alunos[j + 1];
                CadAlunos->alunos[j + 1] = temp;
            }
        }
    }
}

// Ordena o cadastro de alunos por matrícula usando bubble sort (Por Nome)
void ordenarAlunoByName(fila* CadAlunos) {
    for (int i = CadAlunos->front; i < CadAlunos->rear - 1; i++) {
        for (int j = CadAlunos->front; j < CadAlunos->rear - i - 1; j++) {
            if (compararOrdemAlfabetica(CadAlunos->alunos[j].nome, CadAlunos->alunos[j + 1].nome) > 0) {
                aluno temp = CadAlunos->alunos[j];
                CadAlunos->alunos[j] = CadAlunos->alunos[j + 1];
                CadAlunos->alunos[j + 1] = temp;
            }
        }
    }
}

// Faz a busca Binária pelo valor da Matrícula
resultado buscaBinariaAluno(fila* CadAlunos, int valor) {
    resultado resultadoBin = {};
    int left = CadAlunos->front;
    int right = CadAlunos->rear - 1;

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

// Faz a busca Binária pelo nome do aluno
resultado buscaBinariaAlunoNome(fila* CadAlunos, char* nome) {
    resultado resultadoBin = {};
    int left = CadAlunos->front;
    int right = CadAlunos->rear - 1;
    while (left <= right) {
        int meio = left + (right - left) / 2;
        int cmp = compararOrdemAlfabetica(CadAlunos->alunos[meio].nome, nome);
        if (cmp == 0) {
            resultadoBin.encontrado = true;
            resultadoBin.position = meio;
            return resultadoBin;
        }
        if (cmp < 0) {
            left = meio + 1;
        } else {
            right = meio - 1;
        }
    }
    return resultadoBin;
}

// Cadatra uma unidade de aluno
void addAluno(fila* CadAlunos) {
    printf("Aluno %d:\n", CadAlunos->quantElementos + 1);
    printf("Nome: ");
    fgetsCleanedByStdin(CadAlunos->alunos[CadAlunos->rear].nome, sizeof(CadAlunos->alunos[CadAlunos->rear].nome), true);
    printf("Matricula: ");
    scanf("%d", &CadAlunos->alunos[CadAlunos->rear].matricula);
    printf("Nota 1: ");
    scanf("%lf", &CadAlunos->alunos[CadAlunos->rear].nota1);
    printf("Nota 2: ");
    scanf("%lf", &CadAlunos->alunos[CadAlunos->rear].nota2);
    printf("Nota 3: ");
    scanf("%lf", &CadAlunos->alunos[CadAlunos->rear].nota3);
    CadAlunos->alunos[CadAlunos->rear].media = (CadAlunos->alunos[CadAlunos->rear].nota1 + CadAlunos->alunos[CadAlunos->rear].nota2 + CadAlunos->alunos[CadAlunos->rear].nota3) / 3;
    printf("Média: %.2lf\n\n", CadAlunos->alunos[CadAlunos->rear].media);
}

int isCheio(fila* f) {
    return f->rear == MAX;
}

int isVazio(fila* f) {
    return f->front == f->rear;
}

void enfileirar(fila* f) {
    if (!isCheio(f)) {
        addAluno(f);
        f->rear++;
        f->quantElementos++;
    } else {
        printf("\n#### A fila está cheia !!! ####\n");
    }
}

void desenfileirar(fila* f) {
    if (!isVazio(f)) {
        for (int i = f->front; i < f->rear - 1; i++) {
            f->alunos[i] = f->alunos[i + 1];
        }
        f->rear--;
        f->quantElementos--;
    } else {
        printf("\n#### A fila está vazia !!! ####\n");
    }
}

int main() {
    fila CadAlunos = {};
    CadAlunos.quantElementos = 0;
    CadAlunos.front = 0;
    CadAlunos.rear = 0;

    int indiceMenu = 0;

    int continuarC1 = 1;
    do {
        indiceMenu++;
        fputs("\n================================================================", stdout);
        printf("[%d]\n", indiceMenu);
        printf("[%d] Total de Elementos\n[%d] Elementos preenchidos\n", MAX, CadAlunos.quantElementos);
        char* optionsC1[] = {
            "Adicionar Alunos", // (1)
            "Excluir Primeiro Aluno", // (2)
            "Ordenar", // (3)
            "Busca Sequencial", // (4)
            "Busca Binária", // (5)
            "Imprimir Alunos", // (6)
            "Imprimir Nota Final", // (7)
            "Imprimir Nota da Sala", // (8)
            "Verificar se Fila está vazia", // (9)
            "Verificar se Fila está cheia", // (10)
        };
        int menuC1 = sizeof(optionsC1) / sizeof(optionsC1[0]);

        switch (menu(optionsC1, menuC1, true)) {
        case 1: {  // Adiciona novos alunos na pilha.
            enfileirar(&CadAlunos);
            break;
        }
        case 2: { // Adiciona novos alunos.
            desenfileirar(&CadAlunos);
            break;
        }
        case 3: { // Ordena os alunos
            int continuarC3 = 1;
            do {
                indiceMenu++;
                fputs("\n================================================================", stdout);
                printf("[%d]\n", indiceMenu);
                printf("[%d] Total de Elementos\n[%d] Elementos preenchidos\n", MAX, CadAlunos.quantElementos);
                char* optionsC2[] = {
                    "Ordenar Por Matrícula",
                    "Ordenar Por Nome"
                };
                int menuC2 = sizeof(optionsC2) / sizeof(optionsC2[0]);

                switch (menu(optionsC2, menuC2, false)) {
                case 1: { // Ordena por matrícula.
                    printf("Antes da ordenação por matrícula:\n==============================\n");
                    for (int i = CadAlunos.front; i < CadAlunos.rear; i++) {
                        printf("Aluno %d:\nMatrícula: %d\nNome: %s\n==============================\n", i + 1, CadAlunos.alunos[i].matricula, CadAlunos.alunos[i].nome);
                    }
                    ordenarAlunoByMatricula(&CadAlunos);
                    printf("Depois da ordenação por matrícula:\n==============================\n");
                    for (int i = CadAlunos.front; i < CadAlunos.rear; i++) {
                        printf("Aluno %d:\nMatrícula: %d\nNome: %s\n==============================\n", i + 1, CadAlunos.alunos[i].matricula, CadAlunos.alunos[i].nome);
                    }
                    break;
                }
                case 2: { // Ordena por nome.
                    printf("Antes da ordenação por nome:\n==============================\n");
                    for (int i = CadAlunos.front; i < CadAlunos.rear; i++) {
                        printf("Aluno %d:\nMatrícula: %d\nNome: %s\n==============================\n", i + 1, CadAlunos.alunos[i].matricula, CadAlunos.alunos[i].nome);
                    }
                    ordenarAlunoByName(&CadAlunos);
                    printf("Depois da ordenação por nome:\n==============================\n");
                    printf("=>=>=>=>=>=>=>=>=>=>\n");
                    for (int i = CadAlunos.front; i < CadAlunos.rear; i++) {
                        printf("Aluno %d:\nMatrícula: %d\nNome: %s\n==============================\n", i + 1, CadAlunos.alunos[i].matricula, CadAlunos.alunos[i].nome);
                    }
                    break;
                }
                case -1:
                    continuarC3 = 0;
                    break;
                default:
                    break;
                }
                indiceMenu--;
            } while (continuarC3 == 1);
            break;
        }

        case 4: { // Realiza busca sequencial no cadastro de alunos.
            int continuarC4 = 1;
            do {
                indiceMenu++;
                fputs("\n================================================================", stdout);
                printf("[%d]\n", indiceMenu);
                printf("[%d] Total de Elementos\n[%d] Elementos preenchidos\n", MAX, CadAlunos.quantElementos);
                char* optionsBusca[] = {
                    "Por Matrícula",
                    "Por Nome"
                };
                int menuBusca = sizeof(optionsBusca) / sizeof(optionsBusca[0]);

                switch (menu(optionsBusca, menuBusca, false)) {
                case 1: { // Busca por matrícula.
                    int valor = 0;
                    printf("Digite a matrícula para buscar [Primeira Correspondencia] >>> ");
                    scanf("%d", &valor);
                    resultado resultadoSeg = buscaSequencialAluno(&CadAlunos, valor);
                    if (resultadoSeg.encontrado) {
                        printf("\nMatrícula %d encontrada na posição %d.\n\n", valor, resultadoSeg.position + 1);
                    } else {
                        printf("\n<#### Matrícula %d não encontrada ####>\n\n", valor);
                    }
                    break;
                }
                case 2: { // Busca por nome.
                    char nome[50];
                    printf("Digite o nome para buscar >>> ");
                    scanf("%s", nome);
                    resultado resultadoSeg = buscaSequencialAlunoNome(&CadAlunos, nome);
                    if (resultadoSeg.encontrado) {
                        printf("\nNome %s encontrado na posição %d.\n\n", nome, resultadoSeg.position + 1);
                    } else {
                        printf("\n<#### Nome %s não encontrado ####>\n\n", nome);
                    }
                    break;
                }
                case -1:
                    continuarC4 = 0;
                    break;
                }
                indiceMenu--;
            } while (continuarC4 == 1);
            break;
        }
        case 5: { // Realiza busca binária no cadastro de alunos.
            int continuarC4 = 1;
            do {
                indiceMenu++;
                fputs("\n================================================================", stdout);
                printf("[%d]\n", indiceMenu);
                printf("[%d] Total de Elementos\n[%d] Elementos preenchidos\n", MAX, CadAlunos.quantElementos);
                char* optionsBusca[] = {
                    "Por Matrícula",
                    "Por Nome"
                };
                int menuBusca = sizeof(optionsBusca) / sizeof(optionsBusca[0]);

                switch (menu(optionsBusca, menuBusca, false)) {
                case 1: { // Busca por matrícula.
                    int valor = 0;
                    printf("Digite a matrícula para buscar [Ordenação automática][Primeira Correspondencia] >>> ");
                    scanf("%d", &valor);
                    ordenarAlunoByMatricula(&CadAlunos);
                    resultado resultadoBin = buscaBinariaAluno(&CadAlunos, valor);
                    if (resultadoBin.encontrado) {
                        printf("\nMatrícula %d encontrada na posição %d.\n\n", valor, resultadoBin.position + 1);
                    } else {
                        printf("\n<#### Matrícula %d não encontrada ####>\n\n", valor);
                    }
                    break;
                }
                case 2: { // Busca por nome.
                    char nome[50];
                    printf("Digite o nome para buscar [Ordenação automática] >>> ");
                    scanf("%s", nome);
                    ordenarAlunoByName(&CadAlunos);
                    resultado resultadoBin = buscaBinariaAlunoNome(&CadAlunos, nome);
                    if (resultadoBin.encontrado) {
                        printf("\nNome %s encontrado na posição %d.\n\n", nome, resultadoBin.position + 1);
                    } else {
                        printf("\n<#### Nome %s não encontrado ####>\n\n", nome);
                    }
                    break;
                }
                case -1:
                    continuarC4 = 0;
                    break;
                }
                indiceMenu--;
            } while (continuarC4 == 1);
            break;
        }
        case 6: { // Imprime informações dos alunos cadastrados.
            for (int i = CadAlunos.front; i < CadAlunos.rear; i++) {
                printf("----------------------------\n");
                imprimirAluno(&CadAlunos.alunos[i]);
            }
            printf("----------------------------\n");
            break;
        }
        case 7: {
            for (int i = CadAlunos.front; i < CadAlunos.rear; i++) {
                imprimirAlunoNotaFinal(&CadAlunos.alunos[i]);
            }
            break;
        }
        case 8: {
            double soma = 0;
            for (int i = CadAlunos.front; i < CadAlunos.rear; i++) {
                soma += imprimirNotaFinal(&CadAlunos.alunos[i]);
            }
            double mediaClass = soma / CadAlunos.quantElementos;
            printf("Nota da Média da Sala: %.2lf\n", mediaClass);
            break;
        }
        case 9: {
            if (isVazio(&CadAlunos)) {
                fputs("<#### A fila está vazia ####>\n\n", stdout);
            } else {
                fputs("<#### A fila contém item(s) ####>\n\n", stdout);
            }
            break;
        }
        case 10: {
            if (isCheio(&CadAlunos) == 1) {
                fputs("<#### A pilha está cheia ####>\n\n", stdout);
            } else {
                fputs("<#### A pilha não está cheia ####>\n\n", stdout);
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

    return 0;
}