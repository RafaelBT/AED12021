/* Este programa gera uma lista de números inteiros aleatória
 * e armazena esta lista em um arquivo de texto simples. Ele deverá
 * ser usado como entrada para os vários algoritmos de estrutura
 * de dados que serão estudadas e também servem como base para
 * versão mais especializados que poderão ser mais convenientes */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "misc.h"

/* int compara(int *a, int *b) {
	if (*a < *b) return -1;
	else if (*a==*b) return 0;
	else return 1;
}

int ordenalista(int tam) {
	FILE *entrada, *saida;
	int i;
	int a[MAXLISTA];

	if (tam > MAXLISTA) tam = MAXLISTA;

	entrada = fopen("lista.txt", "r");
	saida = fopen("listaordenada.txt", "w");

	for (i = 0; i< tam; i++) {
		fscanf(entrada, "%d", &a[i]);
	}

	qsort(a, tam, sizeof(int), compara);

	for (i = 0; i< tam; i++) {
		fprintf(saida, "%d\n", a[i]);
	}

	fclose(entrada);
	fclose(saida);
	return 0;
}*/



int geralista(int tam) {

	FILE *file;
	int i, num;

	if (tam > MAXLISTA) tam = MAXLISTA;

	file = fopen("lista.txt", "w");

	// muda a semente dos números aleatórios
	srand((unsigned) time(NULL)/2);

	for (i = 0; i< tam; i++) {
		num = rand();
		fprintf(file, "%d\n", num);
	}

	fclose(file);
	return 0;
}
