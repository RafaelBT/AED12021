#include <time.h>
#include <stdio.h>
#include <stdlib.h>

struct lista_encadeada {
	int valor;
	struct lista_encadeada *prox;
};

int insere(struct lista_encadeada **l, int x) {
	struct lista_encadeada *novo;
	novo = (struct lista_encadeada *)malloc(sizeof(struct lista_encadeada));
	novo->valor = x;
	novo->prox = *l;
	*l = novo; //Nova cabeça da lista
	return 0;
}

int lista(struct lista_encadeada *l) {
	struct lista_encadeada *aux;

	aux = l;

	while(aux != NULL) {
		printf("%d\n", aux->valor);
		aux = aux->prox;
	}
	return 0;
}

int main() {
    //Declaração de variáveis
    struct lista_encadeada *lenc;
    lenc = NULL;

    insere(&lenc, 1);
    insere(&lenc, 2);
    insere(&lenc, 3);
    insere(&lenc, 4);
    insere(&lenc, 5);
    insere(&lenc, 6);
    insere(&lenc, 7);
    insere(&lenc, 8);
    insere(&lenc, 9);
    insere(&lenc, 10);
    lista(lenc);

    // Fim de execução sem problema
    return 0;
}

