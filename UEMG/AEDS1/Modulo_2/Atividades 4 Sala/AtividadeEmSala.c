# include <stdio.h>
# include <string.h>

int main() {

    char nameAlunos[3][25] = {};
        int nota[3] = {};

    for (int i = 0; i < 3; i++) {

        printf("Digite o nome do aluno: ");
        fflush(stdin);
        setbuf(stdin,NULL);
        fgets(nameAlunos[i], 25, stdin);
        nameAlunos[i][strlen(nameAlunos[i]) - 1] = '\000';

        printf("Digite a nota do aluno: ");
        fflush(stdin);
        setbuf(stdin,NULL);
        scanf("%d", &nota[i]);
    }

    for (int i = 0; i < 3; i++) {

        fputs(nameAlunos[i], stdout);
        printf(" -> %d\n",nota[i]);
    } 

    return 0;
}