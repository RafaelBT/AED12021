// Programa para fazer uma busca numa lista de números inteiros positivos aleatórios
import java.io.File;
import java.io.FileWriter;

import java.util.Scanner;
import java.util.Random;

public class ProcuraNumero {
    public static void main(String[] args) {
        try {
            Scanner teclado = new Scanner(System.in);
            Random rand = new Random();

            // iterator comum
            int i = 0;
            boolean achei = false;

            System.out.println("Qual o tamanho da lista? ");
            final int TAMANHO = teclado.nextInt();

            // gerando arquivo da lista
            File lista = new File("lista.txt");
            // cria o arquivo se ele já não existir
            lista.createNewFile();

            // escrevendo números aleatórios
            FileWriter writer = new FileWriter(lista);
            for (i = 0; i < TAMANHO; i++) {
                writer.write(String.valueOf(rand.nextInt(TAMANHO)) + "\n");
            }
            writer.close();


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
            System.out.printf("Deu Erro!!");
        }
	}
}