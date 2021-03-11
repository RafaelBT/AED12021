#include <stdio.h>

#define CAP 1000

struct pilha {
	int a[CAP];
	int topo;
};

int iniciaPilha(struct pilha *p) {
	p->topo = -1;
}

int pilhaVazia(struct pilha p) {
	if (p.topo == -1) return 1;
	else return 0;
}

int topoPilha(struct pilha p) {
	return p.a[p.topo];
}

int empilha(struct pilha *p, int x) {
	if (p->topo != (CAP - 1)) {
		p->topo++;
		p->a[p->topo] = x;
		return 0;
	} else {
		printf("Overlhow!");
		return -1;
	}
}

int desempilha(struct pilha *p) {
	int valor;
	if (p->topo != -1) {
		valor = p->a[p->topo];
		p->topo--;
		return valor;
	} else {
		printf("Underflow!");
		return 0;
	}
}

int main() {
	struct pilha stack;

	iniciaPilha(&stack);

	empilha(&stack, 100);
	empilha(&stack, 20);

	desempilha(&stack);

	printf("O topo é %d\n", topoPilha(stack));

	printf("%d\n", (-2) % CAP);

	return 0;
}

