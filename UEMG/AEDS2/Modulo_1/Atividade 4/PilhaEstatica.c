// Turma: Engenharia da Computação - UEMG.
// Atividade 11 - TP 03 Pilha 

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

typedef struct pilha {
    int quantElementos; // Quantidade de elementos alocados no vetor
    aluno alunos[MAX];  // Ponteiro para os elementos do vetor
    int pointWR;        // Índice para a próxima posição de escrita
} pilha;

// Estrutura para armazenar o resultado de uma busca
typedef struct resultado {
    bool encontrado;    // Indica se o valor foi encontrado
    int position;       // Posição do valor, se encontrado
} resultado;

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

double imprimirNotaFinal(aluno *aluno) {
    return aluno->nota1 + aluno->nota2 + aluno->nota3;
}

void fgetsCleanedByStdin(char *out, int save, bool isTrim) {
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
void imprimirAluno(aluno *aluno) {
    printf("Nome: %s\n", aluno->nome);
    printf("Matricula: %d\n", aluno->matricula);
    printf("Nota 1: %.2lf\n", aluno->nota1);
    printf("Nota 2: %.2lf\n", aluno->nota2);
    printf("Nota 3: %.2lf\n", aluno->nota3);
    printf("Média: %.2lf\n\n", aluno->media);
}

// Função de Impressão Final
void imprimirAlunoNotaFinal(aluno *aluno) {
    printf("Nome: %s\n", aluno->nome);
    printf("Matricula: %d\n", aluno->matricula);
    printf("Nota 1: %.2lf\n", aluno->nota1);
    printf("Nota 2: %.2lf\n", aluno->nota2);
    printf("Nota 3: %.2lf\n", aluno->nota3);
    printf("Média: %.2lf\n", aluno->media);
    double notaFinal = imprimirNotaFinal(aluno);
    printf("Nota Final: %.2lf\n\n", notaFinal);
    printf("Situação: ");
    if(notaFinal <= 40) {
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
int compararOrdemAlfabetica(const char *str1, const char *str2) {
    for (int i = 0; str1[i] != '\0' && str2[i] != '\0'; i++) {
        if (str1[i] != str2[i]) {
            return str1[i] - str2[i];
        }
    }
    return str1[strlen(str1)] - str2[strlen(str2)];
}

// Faz a busca sequencial de alunos pela matrícula
resultado buscaSequencialAluno(pilha *CadAlunos, int valor) {
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

// Faz a busca sequencial de alunos pelo nome
resultado buscaSequencialAlunoNome(pilha *CadAlunos, char *nome) {
    resultado resultadoSeg = {};
    for (int i = 0; i < CadAlunos->pointWR; i++) {
        if (compararOrdemAlfabetica(CadAlunos->alunos[i].nome, nome) == 0) {
            resultadoSeg.encontrado = true;
            resultadoSeg.position = i + 1;
            return resultadoSeg;
        }
    }
    return resultadoSeg;
}

// Ordena o cadastro de alunos por matrícula usando bubble sort (Por Matrícula)
void ordenarAlunoByMatricula(pilha *CadAlunos) {
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

// Ordena o cadastro de alunos por matrícula usando bubble sort (Por Nome)
void ordenarAlunoByName(pilha *CadAlunos) {
    for (int i = 0; i < CadAlunos->pointWR - 1; i++) {
        for (int j = 0; j < CadAlunos->pointWR - i - 1; j++) {
            if (compararOrdemAlfabetica(CadAlunos->alunos[j].nome, CadAlunos->alunos[j + 1].nome) > 0) {
                aluno temp = CadAlunos->alunos[j];
                CadAlunos->alunos[j] = CadAlunos->alunos[j + 1];
                CadAlunos->alunos[j + 1] = temp;
            }
        }
    }
}

// Faz a busca Binária pelo valor da Matrícula
resultado buscaBinariaAluno(pilha *CadAlunos, int valor) {
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

// Faz a busca Binária pelo nome do aluno
resultado buscaBinariaAlunoNome(pilha *CadAlunos, char *nome) {
    resultado resultadoBin = {};
    int left = 0;
    int right = CadAlunos->pointWR - 1;
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
void addAluno(pilha *CadAlunos) {
    printf("Aluno %d:\n", CadAlunos->pointWR + 1);
    printf("Nome: ");
    fgetsCleanedByStdin(CadAlunos->alunos[CadAlunos->pointWR].nome, sizeof(CadAlunos->alunos[CadAlunos->pointWR].nome), true);
    // scanf("%s", &CadAlunos->alunos[CadAlunos->pointWR].nome);
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



int isCheio (pilha *p) {
    if (p->pointWR < p->quantElementos) {
        return 0;
    }
    printf("\n #### A pilha está cheia !!! ####\n");
    return 1;
}

int isVazio (pilha *p) {
    if (p->pointWR <= 0) {
        return 1;
    }
    return 0;
}

void empilhar (pilha *p) {
    if (isCheio(p) == 0) {
        addAluno(p);
        p->pointWR++;
    }
}

void desempilhar (pilha *p) {

    if (isVazio(p) == 0) {
        p->pointWR--;
        p->alunos[p->pointWR].matricula = 0;
        p->alunos[p->pointWR].media = 0;
        p->alunos[p->pointWR].nota1 = 0;
        p->alunos[p->pointWR].nota2 = 0;
        p->alunos[p->pointWR].nota3 = 0;
        for (int i = 0; i < 50; i++) {
            p->alunos[p->pointWR].nome[i] = 0;
        }
    }
}

int main() {

    pilha CadAlunos = {};
    CadAlunos.quantElementos = MAX;
    int indiceMenu = 0;

    // Executa a ação de acordo com a opção de reserva e adição de elementos.

    int continuarC1 = 1;  // Controla o loop de operações com alunos.
    do {
        indiceMenu++;
        fputs("\n================================================================", stdout);
        printf("[%d]", indiceMenu);
        printf("\n[%d] Total de Elementos\n[%d] Elementos preenchidos\n", CadAlunos.quantElementos, CadAlunos.pointWR);
        char *optionsC1[] = {
            "Adiconar Alunos", // (1)
            "Excluir último aluno", //(2)
            "Ordernar", // (3)
            "Busca Sequencial", // (4)
            "Busca Binária", // (5)
            "Imprimir Alunos", // (6)
            "Imprimir Nota Final", // (7)
            "Imprimir Nota da Sala", // (8)
            "Verificar se Pilha está vazia", // (9)
            "Verificar se Pilha está cheia", // (10)
        };
        int menuC1 = sizeof(optionsC1) / sizeof(optionsC1[0]);

        // Executa a ação de acordo com a opção do menu de alunos.
        switch (menu(optionsC1, menuC1, true)) {
            case 1: {  // Adiciona novos alunos na pilha.
                empilhar(&CadAlunos);
                break;
            }
            case 2: { // Adiciona novos alunos.
                desempilhar(&CadAlunos);
                break;
            }
            case 3: { // Ordena os alunos
                int continuarC3 = 1;
                do {
                    indiceMenu++;
                    fputs("\n================================================================", stdout);
                    printf("[%d]", indiceMenu);
                    printf("\n[%d] Total de Elementos\n[%d] Elementos preenchidos\n", CadAlunos.quantElementos, CadAlunos.pointWR);
                    char *optionsC2[] = {
                        "Ordernar Por Matrícula",
                        "Ordernar Por Nome"
                    };
                    int menuC2 = sizeof(optionsC2) / sizeof(optionsC2[0]);
                        // Executa a ação de acordo com a opção de ordenação.
                        switch (menu(optionsC2, menuC2, false)) {
                            case 1: { // Ordena por matrícula.
                                printf("=================\n");
                                for (int i = 0; i < CadAlunos.quantElementos; i++) {
                                    printf("Aluno %d:\nMatrícula: %d\nNome: %s\n=================\n", i + 1, CadAlunos.alunos[i].matricula, CadAlunos.alunos[i].nome);
                                }
                                ordenarAlunoByMatricula(&CadAlunos);
                                fputs("\nDepois de ordenado:\n", stdout);
                                for (int i = 0; i < CadAlunos.quantElementos; i++) {
                                    printf("Aluno %d:\nMatrícula: %d\nNome: %s\n=================\n", i + 1, CadAlunos.alunos[i].matricula, CadAlunos.alunos[i].nome);
                                }
                            break;
                        }
                        case 2: { // Ordena por nome.
                            printf("=================\n");
                            for (int i = 0; i < CadAlunos.quantElementos; i++) {
                                printf("Aluno %d:\nMatrícula: %d\nNome: %s\n=================\n", i + 1, CadAlunos.alunos[i].matricula, CadAlunos.alunos[i].nome);
                            }
                            ordenarAlunoByName(&CadAlunos);
                            fputs("\nDepois de ordenado:\n", stdout);
                            printf("=>=>=>=>=>=>=>=>=>=>\n");
                            for (int i = 0; i < CadAlunos.quantElementos; i++) {
                                printf("Aluno %d:\nMatrícula: %d\nNome: %s\n=================\n", i + 1, CadAlunos.alunos[i].matricula, CadAlunos.alunos[i].nome);
                            }
                            break;
                        }
                        case -1:
                            continuarC3 = 0; // Sai do loop de ordenação.
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
                    printf("[%d]", indiceMenu);
                    printf("\n[%d] Total de Elementos\n[%d] Elementos preenchidos\n", CadAlunos.quantElementos, CadAlunos.pointWR);
                    char *optionsBusca[] = {
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
                                printf("\nNome %s encontrado na posição %d.\n\n", nome, resultadoSeg.position);
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
                    printf("[%d]", indiceMenu);
                    printf("\n[%d] Total de Elementos\n[%d] Elementos preenchidos\n", CadAlunos.quantElementos, CadAlunos.pointWR);
                    char *optionsBusca[] = {
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
                                printf("\nNome %s encontrado na posição %d.\n\n", nome, resultadoBin.position);
                            } else {
                                printf("\n<#### Nome %s não encontrado ####>\n\n>", nome);
                            }
                            break;
                        }
                        case -1:
                            break;
                    }
                    indiceMenu--;
                } while (continuarC4 == 1);
                break;
            }
            case 6: { // Imprime informações dos alunos cadastrados.
                for (int i = 0; i < CadAlunos.quantElementos; i++) {
                    imprimirAluno(&CadAlunos.alunos[i]);
                }
                break;
            }
            case 7: { // Imprime todas as notas e informações dos alunos cadastrados.
                for (int i = 0; i < CadAlunos.quantElementos; i++) {
                    imprimirAlunoNotaFinal(&CadAlunos.alunos[i]);
                }
                break;
            }
            case 8: { // Imprime informações da sala cadastrada.
                double soma = 0;
                for (int i = 0; i < CadAlunos.quantElementos; i++) {
                    soma += imprimirNotaFinal(&CadAlunos.alunos[i]);
                }
                double mediaClass = soma / CadAlunos.pointWR;
                printf("Nota da Média da Sala: %.2lf\n", mediaClass);
                break;
            }
            case 9: {
                if (isVazio(&CadAlunos) == 1) {
                    fputs("<#### A pilha está vazia ####>\n\n", stdout);
                } else {
                    fputs("<#### A pilha contém item(s) ####>\n\n", stdout);
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