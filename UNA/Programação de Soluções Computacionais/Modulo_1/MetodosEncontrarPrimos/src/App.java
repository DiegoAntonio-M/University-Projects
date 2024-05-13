import java.util.Scanner;

public class App {
    public static void main(String[] args) {

        int numate;
        int numini;
        int contar;
        double horaInicioM1;
        double horaTerminoM1;
        double horaInicioM2;
        double horaTerminoM2;
        double ajusteTaxa = 1.5;

        Scanner leitura = new Scanner(System.in);

        System.out.printf("Digite o número inicial: ");
        numini = leitura.nextInt();

        System.out.printf("Digite a quantidade do(s) próximo(s) número(s) a ser(em) verificado(s): ");
        numate = numini + leitura.nextInt();

        leitura.close();

        if (numini < 1) {
            numini = 1;
        }
        if ((numini % 2 == 0 && numini != 2) || numini == 1) {
            numini = numini + 1;
        }
        if (numini <= numate) {
            numate += 1;
        }

        /// Método 1

        System.out.println("Método 1\n");

        horaInicioM1 = System.currentTimeMillis();
        for (int i = numini; i < numate; i++) {
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
        horaTerminoM1 = System.currentTimeMillis();
        
        /// Método 2

        System.out.println("\nMétodo 2:\n");

        horaInicioM2 = System.currentTimeMillis();
        for (int i = numini; (i < numate) && (i <= 3); i++) {
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
            if (i == 3) {
                numini = i + 2;
            }
        }
        int i;
        for (i = numini; (i < numate) && (i > 3); i += 2) {
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
        horaTerminoM2 = System.currentTimeMillis();

        System.out.println(
                "\nA pontuação do M1 é: " + (Math.pow(numate - numini, ajusteTaxa) / (horaTerminoM1 - horaInicioM1)));
        System.out.println(
                "A pontuação do M2 é: " + (Math.pow(numate - numini, ajusteTaxa) / (horaTerminoM2 - horaInicioM2)));

        
    }
}