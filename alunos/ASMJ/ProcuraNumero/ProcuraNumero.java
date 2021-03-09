// Programa para fazer uma busca numa lista de números inteiros positivos aleatórios
import java.io.File;
import java.util.Scanner;

public class ProcuraNumero {
    public static void main(String[] args) {
        try {
            Scanner teclado = new Scanner(System.in);
            // iterator comum
            int i = 0;
            boolean achei = false;

            System.out.println("Qual o tamanho da lista? ");
            final int TAMANHO = teclado.nextInt();

            File lista = Misc.GeraLista(TAMANHO);

            System.out.println("Qual número procurar? ");
            int x = teclado.nextInt();

            Scanner reader = new Scanner(lista);
            long start = System.currentTimeMillis();
            i = 0;
            while (reader.hasNextLine()) {
                i++;
                int number = Integer.parseInt(reader.nextLine());
                if(number == x) {
                    achei = true;
                    break;
                }
            }

            long end = System.currentTimeMillis();

            if(achei) {
                System.out.printf("Achei o %d na posição %d\n", x, i);
            } else {
                System.out.println("Não achei");
            }

            System.out.println("A procura levou: " + (end - start) + " ms");
    
        } catch (Exception e) {
            e.printStackTrace();    
        }
	}
}