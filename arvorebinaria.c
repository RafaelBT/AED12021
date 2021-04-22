/* Este programa lê os dados de um arquivo texto para um vetor,
 * gera uma árvore AVL com os elementos desse vetor e mostra a altura da árvore.
 * Além disso ele mede o tempo que o algoritmo levou para executar. */

#include <stdio.h> //Biblioteca padrão de E/S
#include <time.h> //Biblioteca para rotinas de tempo
#include <math.h>
#include <stdlib.h>

#define MAXLISTA 1000000 // Define uma constante com o tamanho da lista

struct node {
	int chave;
	int altura;
	struct node *esq;
	struct node *dir;
};

typedef struct node nodo;

void visita(nodo *pt) {
	printf("%d\n", pt->chave);
}

void simet(nodo *pt) {
	if (pt->esq != NULL) simet(pt->esq);
	visita(pt);
	if (pt->dir != NULL) simet(pt->dir);
}

int buscabinaria(int x, nodo **pt) {
	int res;

	if (*pt == NULL) {
		// Retorna 0 se a árvore está vazia
		res = 0;
	} else {
		if (x == (*pt)->chave) {
			// Retorna 1 se a chave é encontrada
			res = 1;
		} else if (x < (*pt)->chave) {
			if ((*pt)->esq == NULL) {
				// Retorna 2 se a chave não é encontrada
				// mas deve ser inserido com um filho esquerdo
				res = 2;
			} else {
				*pt = (*pt)->esq;
				res = buscabinaria(x, pt);
			}
		} else {
			if ((*pt)->dir == NULL) {
				// Retorna 3 se a chave não é encontrada
				// mas deve ser inserida com um filho direito
				res = 3;
			} else {
				*pt = (*pt)->dir;
				res = buscabinaria(x, pt);
			}
		}
	}
	return res;
}

void altura(nodo *pt) {
	int alt1, alt2;
	if (pt->esq != NULL) {
		alt1 = (pt->esq)->altura;
	} else alt1 = 0;
	if (pt->dir != NULL) {
		alt2 = (pt->dir)->altura;
	} else alt2 = 0;
	if (alt1>alt2) pt->altura = alt1 + 1;
	else pt->altura = alt2 + 1;
}

void calculaalturas(nodo *pt) {
	if (pt->esq != NULL) calculaalturas(pt->esq);
	if (pt->dir != NULL) calculaalturas(pt->dir);
	altura(pt);
}

int inserenodo(int x, nodo **ptraiz) {
	nodo *pt;
	nodo *ptnovo;

	pt = *ptraiz;

	int res;

	res = buscabinaria(x, &pt);

	if (res == 1) {
		return 0;
	} else {
		(ptnovo) = (nodo *) malloc(sizeof(nodo));
		(ptnovo)->chave = x;
		(ptnovo)->esq = NULL;
		(ptnovo)->dir = NULL;
		if (res == 0) {
			printf("Cria raiz\n");
			*ptraiz = ptnovo;
		} else if (res == 2) {
			pt->esq = ptnovo;
		} else pt->dir = ptnovo;
	}

	return 1;
}

void iniciano(int x, nodo **pt) {
	nodo *ptnovo;

	ptnovo = (nodo *) malloc(sizeof(nodo));
	ptnovo->chave = x;
	ptnovo->esq = NULL;
	ptnovo->dir = NULL;
	ptnovo->altura = 0;
	*pt = ptnovo;
}

int main() {

	FILE *file, *ordem; // Declara dois arquivos
	unsigned int a[MAXLISTA], i, n = 0;
	clock_t ct_i, ct_f;

	nodo *ptaux;
	nodo *arvore = NULL;
	int alterado=0;
	//nodo *pt;

	// Abre os arquivos, um para a leitura e outra para a escrita
	//file = fopen("lista.txt", "r");
	file = fopen("listaordenada.txt", "r");
	//file = fopen("listabaguncada.txt", "r");

	// Leitura do arquivo no vetor
	for (i =0; i<MAXLISTA;  i++) {
		fscanf(file, "%d", &a[i]); // Note a semelhança com scanf()
	}

	printf("Começando a criar...\n");

	// Tempo antes da operação
	ct_i = clock();

	ptaux = arvore;

	for (i=0; i<MAXLISTA; i++) {
		if (inserenodo(a[i], &arvore) != 0) n++;
	}

	// Tempo depois da operação
	ct_f = clock();

	printf("Árvore binária construída!\n");

	calculaalturas(arvore);

	printf("A altura da árvore é %d \n", arvore->altura);

	// Escreve a diferença da tela
	printf("Levou %lf segundos para operar a árvore com %d elementos.\n", ((float)(ct_f - ct_i) / CLOCKS_PER_SEC), n);

	// Fecha os arquivos
	fclose(file);

	/* Note que mesmo com MAXLISTA = 100000 os procedimentos de
	 * leitura e escrita são quase imperceptíveis */

	return 0;
}

