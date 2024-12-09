# include <stdio.h>
# include <math.h>
# include <stdlib.h>
# include <string.h>
# include <stdbool.h>

// Estrutura para armazenar informações de um aluno
typedef struct aluno {
    char nome[50];      // Nome do aluno
    int matricula;      // Matrícula do aluno
    double nota1;       // Notas do aluno
    double nota2;       // Notas do aluno
    double nota3;       // Notas do aluno
    double media;       // Média das notas
    struct aluno* alunoAnterior;
} aluno;

// Estrutura de pilha
typedef struct pilha {
    int quantElementos; // Quantidade de elementos alocados no vetor
    aluno* alunoTop;  // Ponteiro para os elementos do vetor
    int quantMax;        // Índice para a próxima posição de escrita
} pilha;

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

// Cadatra uma unidade de aluno
void addAluno(pilha* CadAlunos) {
    printf("Aluno %d:\n", CadAlunos->quantElementos);
    printf("Nome: ");
    fgetsCleanedByStdin(CadAlunos->alunoTop->nome, sizeof(CadAlunos->alunoTop->nome), true);
    // scanf("%s", &CadAlunos->alunos[CadAlunos->pointWR].nome);
    printf("Matricula: ");
    scanf("%d", &CadAlunos->alunoTop->matricula);
    printf("Nota 1: ");
    scanf("%lf", &CadAlunos->alunoTop->nota1);
    printf("Nota 2: ");
    scanf("%lf", &CadAlunos->alunoTop->nota2);
    printf("Nota 3: ");
    scanf("%lf", &CadAlunos->alunoTop->nota3);
    CadAlunos->alunoTop->media = (CadAlunos->alunoTop->nota1 + CadAlunos->alunoTop->nota2 + CadAlunos->alunoTop->nota3) / 3;
    printf("Média: %.2lf\n\n", CadAlunos->alunoTop->media);
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

pilha* criarPilha(int max) {
    pilha* PilhaCriada = calloc(1, sizeof(pilha));
    PilhaCriada->quantMax = max;
    return PilhaCriada;
}

int isCheio(pilha* p) {

    if (p->quantMax == 0) {
        printf("\n #### A pilha é 'Infinita' !!! ####\n");
        return 0;
    } else if (p->quantElementos < p->quantMax) {
        return 0;
    }
    printf("\n #### A pilha está cheia !!! ####\n");
    return 1;
}

int isVazio (pilha *p) {
    if (p->alunoTop == NULL) {
        return 1;
    }
    return 0;
}

void criarNode(pilha* p) {
    aluno* alunoNewTop = (aluno*)calloc(1, sizeof(aluno));
    alunoNewTop->alunoAnterior = p->alunoTop;
    p->alunoTop = alunoNewTop;
    p->quantElementos++;
}

void empilhar(pilha* p) {
    if (isCheio(p) == 0) {
        criarNode(p);
        addAluno(p);
    }
}

aluno desempilhar(pilha* pilhaAtual) {
    aluno alunoNewTop = {};
    aluno* addressTemp = NULL;
    if (isVazio(pilhaAtual) == 0) {
        alunoNewTop = *(pilhaAtual->alunoTop);
        pilhaAtual->alunoTop->matricula = 0;
        pilhaAtual->alunoTop->media = 0;
        pilhaAtual->alunoTop->nota1 = 0;
        pilhaAtual->alunoTop->nota2 = 0;
        pilhaAtual->alunoTop->nota3 = 0;
        for (int i = 0; i < 50; i++) {
            pilhaAtual->alunoTop->nome[i] = 0;
        }
        addressTemp = pilhaAtual->alunoTop->alunoAnterior;
        pilhaAtual->alunoTop->alunoAnterior = NULL;
        free(pilhaAtual->alunoTop);
        pilhaAtual->alunoTop = addressTemp;
    }
    pilhaAtual->quantElementos--;
    return alunoNewTop;
}

int compararOrdemAlfabetica(const char *str1, const char *str2) {
    for (int i = 0; str1[i] != '\0' && str2[i] != '\0'; i++) {
        if (str1[i] != str2[i]) {
            return str1[i] - str2[i];
        }
    }
    return str1[strlen(str1)] - str2[strlen(str2)];
}

void ordenarAlunoByMatricula(pilha *CadAlunos) {
    if (CadAlunos->alunoTop == NULL) {
        return;
    }
    bool trocado;
    aluno *current;
    aluno temp = {};
    aluno *lastOrdenado = NULL;
    do {
        trocado = false;
        current = CadAlunos->alunoTop;
        while (current->alunoAnterior != NULL) {
            if (current->matricula > current->alunoAnterior->matricula) {
                temp = *current;
                aluno* addressTemp1 = current->alunoAnterior;
                *current = *current->alunoAnterior;
                aluno* addressTemp2 = current->alunoAnterior;
                current->alunoAnterior = addressTemp1;
                temp.alunoAnterior = addressTemp2;
                *current->alunoAnterior = temp;
                trocado = true;
            }
            current = current->alunoAnterior;
        }
        lastOrdenado = current;
    } while (trocado);
}

void ordenarAlunoByNota(pilha *CadAlunos) {
    if (CadAlunos->alunoTop == NULL) {
        return;
    }
    bool trocado;
    aluno *current;
    aluno temp = {};
    aluno *lastOrdenado = NULL;
    do {
        trocado = false;
        current = CadAlunos->alunoTop;
        while (current->alunoAnterior != NULL) {
            if (imprimirNotaFinal(current) > imprimirNotaFinal(current->alunoAnterior)) {
                temp = *current;
                aluno* addressTemp1 = current->alunoAnterior;
                *current = *current->alunoAnterior;
                aluno* addressTemp2 = current->alunoAnterior;
                current->alunoAnterior = addressTemp1;
                temp.alunoAnterior = addressTemp2;
                *current->alunoAnterior = temp;
                trocado = true;
            }
            current = current->alunoAnterior;
        }
        lastOrdenado = current;
    } while (trocado);
}

void ordenarAlunoByName(pilha *CadAlunos) {
    if (CadAlunos->alunoTop == NULL) {
        return;
    }
    bool trocado;
    aluno *current;
    aluno temp = {};
    aluno *lastOrdenado = NULL;
    do {
        trocado = false;
        current = CadAlunos->alunoTop;
        while (current->alunoAnterior != lastOrdenado) {
            if (compararOrdemAlfabetica(current->nome, current->alunoAnterior->nome) > 0) {
                temp = *current;
                aluno* addressTemp1 = current->alunoAnterior;
                *current = *current->alunoAnterior;
                aluno* addressTemp2 = current->alunoAnterior;
                current->alunoAnterior = addressTemp1;
                temp.alunoAnterior = addressTemp2;
                *current->alunoAnterior = temp;
                trocado = true;
            }
            current = current->alunoAnterior;
        }
        lastOrdenado = current;
    } while (trocado);
}

resultado buscaSequencialAluno(pilha *CadAlunos, int valor) {
    resultado resultadoSeg = {};
    aluno *current = CadAlunos->alunoTop;
    int pos = 0;

    while (current != NULL) {
        if (current->matricula == valor) {
            resultadoSeg.encontrado = true;
            resultadoSeg.position = pos;
            return resultadoSeg;
        }
        current = current->alunoAnterior;
        pos++;
    }
    return resultadoSeg;
}

resultado buscaSequencialAlunoNome(pilha *CadAlunos, char *nome) {
    resultado resultadoSeg = {};
    aluno *current = CadAlunos->alunoTop;
    int pos = 0;

    while (current != NULL) {
        if (compararOrdemAlfabetica(current->nome, nome) == 0) {
            resultadoSeg.encontrado = true;
            resultadoSeg.position = pos;
            return resultadoSeg;
        }
        current = current->alunoAnterior;
        pos++;
    }
    return resultadoSeg;
}

resultado buscaBinariaAluno(pilha *CadAlunos, int valor) {
    resultado resultadoBin = {};
    aluno *current = CadAlunos->alunoTop;
    int left = 0;
    int right = CadAlunos->quantElementos - 1;
    int meio;

    while (left <= right) {
        meio = left + (right - left) / 2;
        current = CadAlunos->alunoTop;
        for (int i = 0; i < meio; i++) {
            current = current->alunoAnterior;
        }
        if (current->matricula == valor) {
            resultadoBin.encontrado = true;
            resultadoBin.position = meio;
            return resultadoBin;
        }
        if (current->matricula < valor) {
            left = meio + 1;
        } else {
            right = meio - 1;
        }
    }
    return resultadoBin;
}

resultado buscaBinariaAlunoNome(pilha *CadAlunos, char *nome) {
    resultado resultadoBin = {};
    aluno *current = CadAlunos->alunoTop;
    int left = 0;
    int right = CadAlunos->quantElementos - 1;
    int meio;

    while (left <= right) {
        meio = left + (right - left) / 2;
        current = CadAlunos->alunoTop;
        for (int i = 0; i < meio; i++) {
            current = current->alunoAnterior;
        }
        int cmp = compararOrdemAlfabetica(current->nome, nome);
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

int verificarAlunosRecuperacao(pilha *turma) {
    int count = 0;
    aluno *current = turma->alunoTop;

    while (current != NULL) {
        double notaFinal = imprimirNotaFinal(current);
        if (notaFinal > 40 && notaFinal < 60) {
            count++;
        }
        current = current->alunoAnterior;
    }
    return count;
}

void empilharPronto(pilha* p, aluno a) {
    criarNode(p);
    aluno* addressTemp = p->alunoTop->alunoAnterior;
    *p->alunoTop = a;
    p->alunoTop->alunoAnterior = addressTemp;
    p->quantElementos++;
}

void moverAlunoRepetente(pilha *turmaOriginal, pilha *turmaRepetentes) {
    if (turmaOriginal->alunoTop == NULL) {
        printf("A turma original está vazia.\n");
        return;
    }

    aluno *current = turmaOriginal->alunoTop;
    aluno *prev = NULL;

    while (current != NULL) {
        double notaFinal = imprimirNotaFinal(current);
        if (notaFinal < 40) {
            if (prev == NULL) {
                turmaOriginal->alunoTop = current->alunoAnterior;
            } else {
                prev->alunoAnterior = current->alunoAnterior;
            }
            empilharPronto(turmaRepetentes, *current);
            free(current);
            turmaOriginal->quantElementos--;
            turmaRepetentes->quantElementos++;
            printf("Aluno %s (Matrícula %d) movido para a turma de repetentes.\n", turmaRepetentes->alunoTop->nome, turmaRepetentes->alunoTop->matricula);
            if (prev == NULL) {
                current = turmaOriginal->alunoTop;
            } else {
                current = prev->alunoAnterior;
            }
        } else {
            prev = current;
            current = current->alunoAnterior;
        }
    }
}


int main() {

    pilha* CadAlunos = NULL;
    pilha* CadAlunosRepetentes = NULL;
    int indiceMenu = 0;

    while (CadAlunos == NULL) {
        int habilitarCriacao = 0;
        printf("Digite 1 para criar a Pilha >>> ");
        scanf("%d", &habilitarCriacao);
        int maximoDeItens = 50;
        if (habilitarCriacao == 1) {
            CadAlunos = criarPilha(maximoDeItens);
            CadAlunosRepetentes = criarPilha(maximoDeItens);
        }
    }

    // Executa a ação de acordo com a opção de reserva e adição de elementos.

    int continuarC1 = 1;  // Controla o loop de operações com alunos.
    do {
        indiceMenu++;
        fputs("\n================================================================", stdout);
        printf("[%d]", indiceMenu);
        printf("\n[%d] Total de Elementos\n[%d] Máximo de Elemetos para Empilhar\n", (*CadAlunos).quantElementos, (*CadAlunos).quantMax);
        char* optionsC1[] = {
            "Adiconar Alunos", // (1)
            "Desmpilhar último aluno", //(2)
            "Ordernar", // (3)
            "Busca Sequencial", // (4)
            "Busca Binária", // (5)
            "Imprimir Alunos", // (6)
            "Imprimir Nota Final", // (7)
            "Imprimir Nota da Sala", // (8)
            "Verificar se Pilha está vazia", // (9)
            "Verificar se Pilha está cheia", // (10)
            "Contar Alunos para Exame Especial", //(11)
            "Gerar Turma Regular e Repetentes", //(12)
            "Imprimir Turma Regular // Repetentes" //(13)
        };
        int menuC1 = sizeof(optionsC1) / sizeof(optionsC1[0]);

        // Executa a ação de acordo com a opção do menu de alunos.
        switch (menu(optionsC1, menuC1, true)) {
        case 1: {  // Adiciona novos alunos na pilha.
            empilhar(CadAlunos);
            break;
        }
        case 2: { // Reomver último alunos.
            aluno alunoDesempilhado = desempilhar(CadAlunos);
            printf("\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-\nO aluno desempilhado foi:\nNome: %s;\nMatrícula: %d.\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n", alunoDesempilhado.nome, alunoDesempilhado.matricula);
            break;
        }
        case 3: { // Ordena os alunos
            int continuarC3 = 1;
            do {
                indiceMenu++;
                fputs("\n================================================================", stdout);
                printf("[%d]\n", indiceMenu);
                printf("\n[%d] Total de Elementos\n[%d] Máximo de Elemetos para Empilhar\n", (*CadAlunos).quantElementos, (*CadAlunos).quantMax);
                char *optionsC2[] = {
                    "Ordenar Por Matrícula",
                    "Ordenar Por Nome"
                };
                int menuC2 = sizeof(optionsC2) / sizeof(optionsC2[0]);

                switch (menu(optionsC2, menuC2, false)) {
                    case 1:
                        printf("Antes da ordenação por matrícula:\n=================\n");
                        aluno *current = CadAlunos->alunoTop;
                        for (int i = 0; current != NULL; i++) {
                            printf("Aluno %d:\nMatrícula: %d\nNome: %s\n=================\n", CadAlunos->quantElementos - i, current->matricula, current->nome);
                            current = current->alunoAnterior;
                        }
                        ordenarAlunoByMatricula(CadAlunos);
                        printf("\nDepois da ordenação por matrícula:\n");
                        current = CadAlunos->alunoTop;
                        for (int i = 0; current != NULL; i++) {
                            printf("Aluno %d:\nMatrícula: %d\nNome: %s\n=================\n", CadAlunos->quantElementos - i, current->matricula, current->nome);
                            current = current->alunoAnterior;
                        }
                        break;
                    case 2:
                        printf("Antes da ordenação por nome:\n=================\n");
                        current = CadAlunos->alunoTop;
                        for (int i = 0; current != NULL; i++) {
                            printf("Aluno %d:\nMatrícula: %d\nNome: %s\n=================\n", CadAlunos->quantElementos - i, current->matricula, current->nome);
                            current = current->alunoAnterior;
                        }
                        ordenarAlunoByName(CadAlunos);
                        printf("\nDepois da ordenação por nome:\n");
                        current = CadAlunos->alunoTop;
                        for (int i = 0; current != NULL; i++) {
                            printf("Aluno %d:\nMatrícula: %d\nNome: %s\n=================\n", CadAlunos->quantElementos - i, current->matricula, current->nome);
                            current = current->alunoAnterior;
                        }
                        break;
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
                printf("\n[%d] Total de Elementos\n", CadAlunos->quantElementos);
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
                    resultado resultadoSeg = buscaSequencialAluno(CadAlunos, valor);
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
                    resultado resultadoSeg = buscaSequencialAlunoNome(CadAlunos, nome);
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
                printf("[%d]", indiceMenu);
                printf("\n[%d] Total de Elementos\n", CadAlunos->quantElementos);
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
                    ordenarAlunoByMatricula(CadAlunos);
                    resultado resultadoBin = buscaBinariaAluno(CadAlunos, valor);
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
                    ordenarAlunoByName(CadAlunos);
                    resultado resultadoBin = buscaBinariaAlunoNome(CadAlunos, nome);
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
            aluno *current = CadAlunos->alunoTop;
            while (current != NULL) {
                imprimirAluno(current);
                current = current->alunoAnterior;
            }
            break;
        }
        case 7: { // Imprime todas as notas e informações dos alunos cadastrados.
            aluno *current = CadAlunos->alunoTop;
            while (current != NULL) {
                imprimirAlunoNotaFinal(current);
                current = current->alunoAnterior;
            }
            break;
        }
        case 8: { // Imprime informações da sala cadastrada.
            double soma = 0;
            aluno *current = CadAlunos->alunoTop;
            while (current != NULL) {
                soma += imprimirNotaFinal(current);
                current = current->alunoAnterior;
            }
            double mediaClass = soma / CadAlunos->quantElementos;
            printf("Nota da Média da Sala: %.2lf\n", mediaClass);
            break;
        }
        case 9: {
            if (isVazio(CadAlunos) == 1) {
                fputs("<#### A pilha está vazia ####>\n\n", stdout);
            } else {
                fputs("<#### A pilha contém item(s) ####>\n\n", stdout);
            }
            break;
        }
        case 10: {
            if (isCheio(CadAlunos) == 1) {
                fputs("<#### A pilha está cheia ####>\n\n", stdout);
            } else {
                fputs("<#### A pilha não está cheia ####>\n\n", stdout);
            }
            break;
        }
        case 11: {
            printf("Existem %d aluno(s) para o Exame Especial", verificarAlunosRecuperacao(CadAlunos));
            break;
        }
        case 12: {
            moverAlunoRepetente(CadAlunos, CadAlunosRepetentes);
            break;
        }
        case 13: {
            aluno* current = CadAlunos->alunoTop;
            if (current != NULL) {
                printf("\n============================\nTurma Rematriculada:\n");
                ordenarAlunoByNota(CadAlunos);
                while (current != NULL) {
                    imprimirAluno(current);
                    current = current->alunoAnterior;
                }
            } else {
                printf("Turma Regular Vazia!!!\n");
            }

            current = CadAlunosRepetentes->alunoTop;
            if (current != NULL) {
                printf("\n============================\nTurma Turma de Repetentes:\n");

                while (current != NULL) {
                    imprimirAluno(current);
                    current = current->alunoAnterior;
                }
            } else {
                printf("Turma Reprententes Vazia!!!\n");
            }
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