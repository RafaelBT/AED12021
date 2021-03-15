import java.util.Random;
public class TestePilha {
    public static void main(String[] args) {
		//Testa Pilha
		Pilha p = new Pilha();
	 
		Random gerador = new Random();
		
		for(int i = 0; i < 10; i++) {
			p.empilha(gerador.nextInt(100));
			p.mostraPilha();
			System.out.println("-------------------");
		}
		
		for(int j = 0; j < 10; j++) {
			System.out.printf("Valor removido: %d \n",p.desempilha());
			System.out.println("-------------------");
		}
    }	
}
