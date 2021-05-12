// Programa para fazer uma busca numa lista de números inteiros positivos aleatórios

#include <stdio.h>
#include "../../../misc.h"
#include "misc.c"

#define NUMEROS_GERADOS 1000000

int main(void) {
    geralista(NUMEROS_GERADOS);

    FILE * ent = fopen("lista.txt", "r");

    int searchNum, readNum, i = 1;

    do {
        printf("Digite um numero inteiro positivo para saber se ele esta na lista: ");
        scanf("%d", &searchNum);
    } while(searchNum < 0);
    
    printf("\n");

    while(fscanf(ent, "%d\n", &readNum) == 1) {
        if(readNum == searchNum) break;
        i++;
    }

    if(i > NUMEROS_GERADOS) printf("Desculpe, o seu numero nao esta na lista.");
    else printf("O numero %d esta na posicao de numero %d.", searchNum, i);    
}