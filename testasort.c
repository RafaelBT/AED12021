#include <time.h>
#include <stdio.h>
#include <stdlib.h>

#define QTD 1000000

int compara(const void* e1, const void* e2) {
    int v1 = *(int *)(e1);
    int v2 = *(int *)(e2);

    if (v1 < v2) return -1;
    else if (v1 == v2) return 0;
    else return 1;
}

int main() {
    //Declaração de variáveis
    FILE *arq, *sai;
    clock_t ct_i, ct_f; // variáveis que medem
    int lista[1000000];
    int num, i, j;




    for (j = 10; j <= 1000000; j*=2) {
    // Abertura do arquivo
    arq = fopen("lista.txt", "r");
    // Leitura dos dados em disco para um vetor
    i = 0;
    while (fscanf(arq, "%d", &num) > 0) {
        lista[i] = num;
	i++;
    }

    fclose(arq);
    // Leitura do tempo inicial
    ct_i = clock();

    // Apenas aqui começamos e medir o tempo de processamento

    // Ordenação
    qsort(lista, j, sizeof(int), compara);

    // Fim da medida do tempo de execução
    ct_f = clock();

    // Cálculo do tempo decorrido
    printf("Tamanho: %d \tTempo decorrido: %lfs. \n", j, ((float)(ct_f - ct_i) / CLOCKS_PER_SEC));

    }

    //Escrever listaordenada
    sai = fopen("listaordenada.txt", "w");
    for (i=0; i < QTD; i++) {
	fprintf(sai, "%d\n", lista[i]);
    }


    // Fecha o arquivo
    fclose(sai);

    // Fim de execução sem problema
    return 0;
}

