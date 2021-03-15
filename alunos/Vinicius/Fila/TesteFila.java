import java.util.Random;
public class TesteFila {
    public static void main(String[] args) {
		//Teste Fila
		Fila f = new Fila();
		Random gerador = new Random();
        
		for (int i = 0; i < 10; i++) {
			f.enfileira(gerador.nextInt(100));
			f.mostraFila();
			System.out.println("-------------------");
			
		}
		
		System.out.println("---------Exemplo de remoção---------");
		
		f.desenfileira();
		f.mostraFila();
	
		
	}
}
