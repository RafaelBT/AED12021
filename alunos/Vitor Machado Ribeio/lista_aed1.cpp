// Exercício: Programa que calcula seu tempo de execução para encontrar um determinado número no arquivo lista.txt

#include <time.h>
#include <stdio.h>

int main(void) {

    clock_t ct_i, ct_f;

    ct_i = clock();

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
    printf("\no valor de i %d",i);

    if (i > 1000000) printf("\nO numero nao foi encontrado.\n");
    else printf("\nO numero consultado foi encontrado na posicao %d.\n", i);

    ct_f = clock();

    printf("Tempo decorrido: %lfs. \n", ((float)(ct_f - ct_i) / CLOCKS_PER_SEC));

}