# include <stdio.h>
# include <math.h>
# include <stdlib.h>
# include <string.h>

int main() {

    int tamanhoFrase = 80;
    char fraseOrigem[tamanhoFrase + 2] = {};
    char fraseCriptografada[tamanhoFrase + 2] = {};

    int chaveDeCesar = 3;

    int verificar =0;
    int validar = 0;
    do {

        if (validar == 0) {
            fputs("######### Intervalo nao valido #########\n", stdout);
        }
        

        validar = 1;
        verificar = 0;
        fputs("<< [Digite apenas numeros ou letras] >>\n", stdout);
        fputs("Digite a string origem: ", stdout);
        fgets(fraseOrigem, tamanhoFrase, stdin);
        fraseOrigem[strlen(fraseOrigem) - 1] = '\000';

        for (int i = 0; i < strlen(fraseOrigem); i++) {
                        
            int numRef = fraseOrigem[i];

            if ((48 <= numRef && numRef <= 57)) {
                verificar = 1;
            } else if ((65 <= numRef && numRef <= 90)) {
                verificar = 1;
            } else if ((97 <= numRef && numRef <= 122)) {
                verificar = 1;
            }        
            
            if (verificar < validar) {
                validar = 0;
            }
            
        }

    } while (validar != 1);


    for (int i = 0; i < strlen(fraseOrigem); i++) {

        if (fraseOrigem[i] != ' ') {

            int numRef = fraseOrigem[i] + chaveDeCesar;

            if ((57 < numRef && numRef < 65)) {
                numRef += 7;
            } else if ((90 < numRef && numRef < 97)) {
                numRef += 6;
            } else if ((122 < numRef)) {
                numRef -= 75;
            }

            fraseCriptografada[i] = numRef; 

        } else {
            fraseCriptografada[i] = fraseOrigem[i];
        }  
    }

    fputs("Frase encriptografada: ", stdout);
    fputs(fraseCriptografada, stdout); 

    return 0;
}