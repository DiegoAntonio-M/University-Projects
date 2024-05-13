import java.util.Scanner;

public class numerosPares {
    public static void main(String[] args) throws Exception {

        int numate = 0;
        int contar = 0;

        Scanner leitura = new Scanner(System.in);

        System.out.printf("Digite o número final do intervalo para calcular os números pares: ");
        numate = leitura.nextInt();

        for (int i = 0; i <= numate; i++) {
            // System.out.println(i);
                        
            if (i % 2 == 0) {
                contar = contar + 1;
                System.out.println(i);
            }                
            
        }
        System.out.printf("Fora ultilizadas %d movimetnações", contar);
        leitura.close();
    }

}