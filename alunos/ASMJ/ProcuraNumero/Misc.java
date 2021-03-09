import java.io.FileWriter;
import java.io.File;

import java.util.Random;
import java.util.Scanner;

class Misc {
    public static File GeraLista(int TAMANHO) throws Exception  {
        try {
            Random rand = new Random();
            // gerando arquivo da lista
            File lista = new File("lista.txt");
            // cria o arquivo se ele já não existir
            lista.createNewFile();

            // escrevendo números aleatórios
            FileWriter writer = new FileWriter(lista);

            long start = System.currentTimeMillis();

            for (int i = 0; i < TAMANHO; i++) {
                writer.write(String.valueOf(rand.nextInt(TAMANHO)) + System.getProperty("line.separator"));
            }
            writer.close();

            long end = System.currentTimeMillis();
            System.out.println("A geração da lista levou: " + (end - start) + " ms");

            return lista;
        } catch (Exception e) {
            e.printStackTrace();
            throw new Exception(e.toString());
        }
    }
}