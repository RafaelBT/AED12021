// Exercício: Programa para fazer uma busca numa lista de números inteiros positivos aleatórios

#include <stdio.h>
#include "misc.h"

int main(void) {
    geralista(1000000);

    FILE * file = fopen("lista.txt", "r");

    int searchNum, readNum, i = 1;

    do {
        printf("Digite um numero: ");
        scanf("%d", &searchNum);
    } while (searchNum < 0);

    while (fscanf(file, "%d\n", &readNum) == 1) {
        if (readNum == searchNum) break;
        i++;
    }

    if (i > 1000000) printf("\nO numero nao foi encontrado.");
    else printf("\nO numero consultado foi encontrado na posicao %d!", i);
}