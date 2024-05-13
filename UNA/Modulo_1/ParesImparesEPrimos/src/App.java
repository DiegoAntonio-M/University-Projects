import java.util.Scanner;

public class App {
    public static void main(String[] args) throws Exception {

        int numate;
        int contar;

        Scanner leitura = new Scanner(System.in);

        System.out.printf("Digite o número final do intervalo para calcular os números primos: ");
        numate = leitura.nextInt();

        for (int i = 1; i < numate; i++) {
            // System.out.println(i);
            contar = 0;
            for (int ii = 1; ii <= i; ii++) {
                if (i % ii == 0) {
                    contar = contar + 1;
                }
            }
            if (contar == 2) {
                System.out.println(i);
            }
        }

        leitura.close();
    }
}
