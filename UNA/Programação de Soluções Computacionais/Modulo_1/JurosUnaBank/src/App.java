public class App {
    public static void main(String[] args) {
        // System.out.println("Hello, World!");

        double poupanca = 10000;
        double CDB = 2000;
        double jurosPoupanca = 0.03;
        double jurosCDB = 0.05;
        int mesesAplicado = 50;

        for (int i = 0; i < mesesAplicado; i += 1) {
            poupanca += poupanca*jurosPoupanca;
            CDB += CDB*jurosCDB;
        }

        System.out.println("Resultado ultilizando o 'for':\n");
        System.out.println(poupanca);
        System.out.println(CDB);

        poupanca = 10000;
        CDB = 2000;

        poupanca = poupanca * Math.pow(1+jurosPoupanca,mesesAplicado);
        CDB = CDB * Math.pow (1+jurosCDB, mesesAplicado);

        System.out.println("\n\nResultado ultilizando funções matemáticas:\n");
        System.out.println(poupanca);
        System.out.println(CDB);

    }
}
