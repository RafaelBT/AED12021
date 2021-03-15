public class Pilha {
    private final int CAPACIDADE = 1000;
	private int [] vetor = new int[CAPACIDADE];
	private int topo;
	
	public Pilha () {
		this.topo = -1;
	}
	
	//Retorna se a pilha está vazia ou não
	public boolean estaVazia() {
		if(topo == -1) return true;
		else return false;
	}
	
	//Retorna o topo da pilha
	public int topoPilha() {
		return this.topo;
	}
	
	//Método de inserção na pilha
	public int empilha(int x){
		if(this.topo != (CAPACIDADE -1)) {
			this.topo++;
			this.vetor[this.topo] = x;
			return 0;
		} else {
			System.out.println("Overflow!");
			return -1;
		}
	}
	
	//Método de remoção da pilha
	public int desempilha() {
		int valor;
		if(this.topo != -1) {
			valor = this.vetor[this.topo];
			this.topo--;
			return valor;
		} else {
			System.out.println("Underflow!");
			return 0;
		}
	}
	//Imprime a pilha
		public void mostraPilha() {
			String elementos = "";
			for(int i = 0; i <= this.topo;i++) {
				elementos += this.vetor[i] +  "\n";
			}
			
			System.out.print(elementos);
		}
}
