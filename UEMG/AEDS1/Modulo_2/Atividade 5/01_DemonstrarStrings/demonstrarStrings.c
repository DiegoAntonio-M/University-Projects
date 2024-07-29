# include <stdio.h>
# include <stdlib.h>
# include <string.h>

int main() {

    char string1[52] = {};
    char string2[52] = {};
    char stringCopia[52] = {};

    printf("Digite uma string: ");

    // ### Demonstração do Uso do "gets" ###

    gets(string1);    
    // | -> Lê uma linha inteira de entrada até encontrar um 
    // |    caractere de nova linha (\n). No entanto, "gets" 
    // |    não verifica o tamanho do buffer, o que pode causar 
    // |    problemas de segurança, como estouro de buffer.
    // |
    // | -> Paramentros: Somente a variável de destino.

    printf("Digite uma segunda string: ");


    // ### Demonstração do Uso do "fgets" ###

    fgets(string2, 25, stdin);
    // | -> Lê uma linha de entrada até um limite especificado
    // |    (número máximo de caracteres) ou até encontrar um   
    // |    caractere de nova linha (\n). fgets é mais seguro
    // |    porque permite especificar o tamanho do buffer,
    // |    evitando estouro de buffer.
    // |
    // | -> Paramentros:
    // |    | -> Variável de destino;
    // |    | -> Tamanho da Leitura;
    // |    | -> Origem da Leitura.


    // ### Demonstração do Uso do "fputs" ###

    fputs("As duas estrings usando o fputs: \n", stdout); // <-------
    fputs(string1, stdout); // <-------
    fputs(" ", stdout); // <-------
    fputs(string2, stdout); // <-------
    // | -> Escreve uma string em um arquivo ou local de destino.
    // |
    // | -> Paramentros:
    // |    | -> Variável de entrada;
    // |    | -> Local de destino ou arquivo, que no caso "stdout"
    // |    |    e a saida padrão que é no terminal/console.


    // ### Demonstração do Uso do "strlen" ###

    int tamanhoDaString1 = 0;
    int tamanhoDaString2 = 0;

    tamanhoDaString1 = strlen(string1); // <-------
    tamanhoDaString2 = strlen(string2); // <-------
    // | -> Recebe uma string e retorna seu comprimento. Ela
    // |    marca o comprimento contando a primeira char até
    // |    a posição que tenha um valor nulo, que é o \000.
    // |
    // | -> Paramentros:
    // |    | -> Variável ou string de entrada;

    printf("\nComprimento da primeria string eh: %d", tamanhoDaString1);
    printf("\nComprimento da segunda string eh: %d", tamanhoDaString2);


    // ### Demonstração do Uso do "strcpy" ###

    strcpy(stringCopia, string1); // <-------
    // | -> Copia uma string para outra variável de destino.
    // |
    // | -> Paramentros:
    // |    | -> String de destino aonde será a cópia;
    // |    | -> String de entrada, sendo a original.

    printf("\nA cópia da primeira string %s", stringCopia);


    // ### Demonstração do Uso do "strcmp" ###

    int saidaStrcmp = {};

    saidaStrcmp = strcmp(string1, string2); // <-------
    // | -> Compara duas strings por posição com posição entre
    // |    duas strings.
    // |
    // | -> Paramentros:
    // |    | -> String de comparação 1;
    // |    | -> String de comparação 2.

    printf("\nRetorno da função 'strcmp' eh: %d \n", saidaStrcmp);

    // Ultilidade:
    if (strcmp(string1, string2) == 0) {
        printf("As strings são iguais (strcmp).\n");
    } else {
        printf("As strings são diferentes (strcmp).\n");
    }


    // ### Demonstração do Uso do "strcat" ###

    strcat(string1, string2);
    // | -> Concatena duas strings, econvertendo em uma só.
    // |
    // | -> Paramentros:
    // |    | -> String 1 e string resultande da concatenação;
    // |    | -> String 2.

    // Se imprimimos a string1 
    printf("Concatenação das strings (strcat): %s\n", string1);

    return 0;
}