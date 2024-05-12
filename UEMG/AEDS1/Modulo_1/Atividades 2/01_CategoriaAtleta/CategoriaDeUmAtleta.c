#include <stdio.h>

int main() {
    int idade = 0;
    
    printf("Digite a idade do Atleta: ");
    scanf("%d", &idade);

    if (5 <= idade && idade <= 7) {
        printf("Este é um atleta Infantil A\n");
    } else if (8 <= idade && idade <= 10) {
        printf("Este é um atleta Infantil B\n");
    } else if (11 <= idade && idade <= 13) {
        printf("Este é um atleta Juvenil A\n");
    } else if (14 <= idade && idade <= 17) {
        printf("Este é um atleta Juvenil B\n");
    } else if (18 <= idade && idade <= 25) {
        printf("Este é um atleta Senior\n");
    } else {
        printf("Este é um atleta sem categoria\n");
    }
   
    return 0;
}
