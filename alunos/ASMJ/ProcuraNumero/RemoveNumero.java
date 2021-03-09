// Programa para fazer uma busca numa lista de números inteiros positivos aleatórios
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.BufferedReader;
import java.io.BufferedWriter;

import java.util.Scanner;

public class RemoveNumero {
    public static void main(String[] args) {
        try {
            Scanner teclado = new Scanner(System.in);

            System.out.println("Qual o tamanho da lista? ");
            final int TAMANHO = teclado.nextInt();

            File lista = Misc.GeraLista(TAMANHO);
            File tempLista = new File("tempLista.txt");

            BufferedReader reader = new BufferedReader(new FileReader(lista));
            BufferedWriter writer = new BufferedWriter(new FileWriter(tempLista));

            System.out.println("Qual número remover? ");
            String numberToRemove = String.valueOf(teclado.nextInt());
            String currentLine;

            int posicao = 0, i = 0;
            long start = System.currentTimeMillis();
            while((currentLine = reader.readLine()) != null) {
                i++;
                if(currentLine.trim().equals(numberToRemove))  {
                    posicao = i;  
                    continue;
                }
                writer.write(currentLine + System.getProperty("line.separator"));
            }
            writer.close(); 
            reader.close(); 

            lista.delete();
            tempLista.renameTo(lista);

            long end = System.currentTimeMillis();

            if(posicao > 0) {
                System.out.printf("Removi o %s na posição %d\n", numberToRemove, posicao);
            } else {
                System.out.println("Não removi");
            }

            System.out.println("A procura levou: " + (end - start) + " ms");
    
        } catch (Exception e) {
            e.printStackTrace();    
        }
	}
}