# include <stdio.h>
# include <math.h>
# include <stdlib.h>
# include <string.h>

int main() {

    int quantidadadeAlunos = 5;
    int tamanhoNomesAlunos = 40;
    char alunos[quantidadadeAlunos][tamanhoNomesAlunos + 2] = {};
    char procAluno[tamanhoNomesAlunos + 2] = {};

    int alunoAdionado = 0;
    int interromper = 0;

    do {
            int continuar = 1;
            char contchar[3] = {};

            if (alunoAdionado > 0) {
                fputs("Deseja continuar inserindo os nomes? [0 - Nao | 1 - Sim]: ", stdout);            
                fgets(contchar, 2, stdin);
                continuar = contchar[0] - 48;
            }

            fflush(stdin);
            setbuf(stdin,NULL);

            if (continuar == 1) {
                printf("(%d/%d) - ", alunoAdionado + 1, quantidadadeAlunos);
                fputs("Digite o nome do aluno [", stdout);
                printf("%d", alunoAdionado + 1);
                fputs("] (1 caracter 0 para sair) -> ", stdout);
                fgets(alunos[alunoAdionado], tamanhoNomesAlunos, stdin);

                for (int i = 0; i < tamanhoNomesAlunos; i++) {
                    if (alunos[alunoAdionado][i] == '\n') {
                        alunos[alunoAdionado][i] = '\000';
                        break;               
                    }            
                }

                if (alunos[alunoAdionado][0] == '0') {
                    interromper = 1;

                    for (int i = 0; i < tamanhoNomesAlunos; i++) {
                        if (alunos[alunoAdionado][i] != '\000') {
                            alunos[alunoAdionado][i] = '\000';
                                    
                        }
                    }

                }  else  {
                    interromper = 0;
                }
                alunoAdionado++;

            } else {

                interromper = 1;
            }   

    } while ((alunoAdionado < quantidadadeAlunos) && (interromper != 1));

        fputs("Procure por -> ", stdout);
        fgets(procAluno, tamanhoNomesAlunos, stdin);

        for (int i = 0; i < tamanhoNomesAlunos; i++) {
            if (procAluno[i] == '\n') {
                procAluno[i] = '\000';
                break;               
            }            
        }    

        for (int i = 0; i < quantidadadeAlunos; i++) {

            int validarNome = 0;
            int tamAluno = strlen(alunos[i]);
            int tamProcAluno = strlen(procAluno);
            int tamanhoMin = 0;

            tamAluno < tamProcAluno ? tamanhoMin = tamAluno : (tamanhoMin = tamProcAluno);

            for (int p = 0; p < tamanhoMin; p++) {
                if (alunos[i][p] == procAluno[p]) {
                    validarNome = 1;
                } else {
                    validarNome = 0;
                    break;
                }
            }

            if (validarNome == 1) {
                printf("Indice [%d] >> %s.\n", i, alunos[i]);
            }           
            
        }        

    return 0;
}