#include <stdio.h>

#define CAP 1000

// Apenas a definição da estrutura
struct fila {
	int a[CAP];
	int inicio;
	int fim;
};

//Função necessária para criar uma fila vazia consistente
int iniciaFila(struct fila *f) {
	f->inicio = -1; // Por convenção fila vazia tem o início e fim
	f->fim = -1;    // como sendo iguais a -1
}

//Função que verifica se uma fila está vazia
int filaVazia(struct fila f) {
	if (f.inicio == -1) return 1;
	else return 0;
}

//Função que retorna o elemento inicio da fila sem removê-lo
int inicioFila(struct fila f) {
	return f.a[f.inicio];
}

//Função que retorno o elemento no fim da fila sem removê-lo
int fimFila(struct fila f) {
	return f.a[f.fim];
}

//Função de inserção na fila
int enfileira(struct fila *f, int x) {
	// Posição onde o novo elemento será inserido
	// levando em consideração a circularidade da fila
	// e se a fila está vazia
	int prov = (f->fim + 1) % CAP;
	if (prov != f->inicio) { // Verifica se a fila não está cheia
		f->fim = prov; // Atualiza o fim da fila
		f->a[f->fim] = x; // Insere o novo elemento no nobo fim
		if (f->inicio == -1) { // Ajuste caso a fila esteja inicialmente vazia
			f->inicio = 0;
		}
		return 0;
	} else { // Capacidade da fila esgotada
		printf("Overflow!");
		return -1;
	}
}

//Função de remoção
int desenfileira(struct fila *f) {
	int valor; // Valor a ser recuperado e removido
	if (f->inicio != -1) { // Verifica se a fila já não está vazia
		valor = f->a[f->inicio]; // Recupera o valor do início da fila
		if (f->inicio == f->fim) { // Ajuste caso a elemento removido for o último
			f->inicio = -1;
			f->fim = -1;
		} else { // Ajusta levando em consideração a circularidade, caso contrário
			f->inicio = (f->inicio + 1) % CAP;
		}
		return valor; // Valor recuperado como retorno
	} else { // Fila está vazia
		printf("Underflow!");
		return 0;
	}
}

int main() {
	struct fila queue;

	iniciaFila(&queue);

	enfileira(&queue, 100);
	enfileira(&queue, 20);

	desenfileira(&queue);

	printf("O inicio é %d\n", inicioFila(queue));

	return 0;
}

