public class Fila {
	private final int CAPACIDADE = 1000;
	
	private int [] vetor = new int [CAPACIDADE];
	private int inicio;
	private int fim;
	
	public Fila() {
		//Por convenção a fila vazia tem o inicio e fim como sendo iguais a -1
		this.inicio = -1;
		this.fim = -1;
	}
	
	//Verifica se a fila está vazia e retorna um valor booleano
	public boolean estaVazia(){
		if (this.inicio == -1) {
			return true;
		} else {
			return false;
		}
	}
	
	//Retorna o inicio da fila
	public int inicioFila() {
		return this.inicio;
	}
	
	//Retorna o fim da fila
	public int fimFila(){
		return this.fim;
	}
	
	//Imprime a fila
	 public void mostraFila(){
		 String elementos = "";
		 for (int i = inicio; i<=fim; i++) {
			 elementos += this.vetor[i]+ " / ";
		 }
	     System.out.println(elementos);      
	 }
	
	//Função de inserção na fila
	public int enfileira(int x) {
		int prov = (this.fim + 1) % CAPACIDADE;
		if (prov != this.inicio) { // Verifica se a lista não está cheia
			this.fim = prov; //Atualiza o fim da lista
			this.vetor[this.fim] = x; //Insere o novo elemento no fim
			if(this.inicio == -1) { //Ajuste caso a lista esteja inicialmente vazia
				this.inicio = 0;
			}
			
			return 0;
		} else { // Capacidade esgotada
			System.out.println("Overflow!");
			return -1;
			
		}
	}
	
	//Função de remoção
	public int desenfileira() {
		int valor; //Valor a ser removido
		if(this.inicio != -1) { //Verifica se a fila já não está vazia
			valor = this.vetor[this.fim];
			if(this.inicio == this.fim){ //Ajuste caso o removido seja o último
				this.inicio = -1;
				this.fim = -1;
				
			} else { //Ajusta levando em consideração a circularidade, caso contrário
				this.inicio = (this.inicio + 1) % CAPACIDADE;
			}
			
			return valor;
		} else { //Fila está vazia
			System.out.println("Underflow!");
			return 0;
		}
	}
	
}