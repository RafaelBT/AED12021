#include <time.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    //Declaração de variáveis
    FILE *arq;
    clock_t ct_i, ct_f; // variáveis que medem
    //int lista[1000000];
    int *lista;
    int num, i, x, k, ivalor;

    lista = malloc(1000000*sizeof(int));

    // Abertura do arquivo
    arq = fopen("lista.txt", "r");

    // Leitura dos dados em disco para um vetor
    i = 0;
    while (fscanf(arq, "%ld", &num) > 0) {
        lista[i] = num;
	i++;
    }

    printf("Digite um número: ");
    scanf("%d", &x);


    // Leitura do tempo inicial
    ct_i = clock();

    // Apenas aqui começamos e medir o tempo de processamento

    // A rotina de busca
    for (k=0; k < i; k++) {
        if (x == lista[k]) {
	    ivalor = k;
	    break;
	}
    }

    // Fim da medida do tempo de execução
    ct_f = clock();

    // Se k for o tamanho da lista signfica que o valor não foi encontrado
    if (k == i) printf("Valor não encontrado!\n");
    else printf("Valor encontrado em %d.\n", ivalor);

    // Cálculo do tempo decorrido
    printf("Tempo decorrido: %lfs. \n", ((float)(ct_f - ct_i) / CLOCKS_PER_SEC));

    // Fecha o arquivo
    fclose(arq);

    // Fim de execução sem problema
    return 0;
}

