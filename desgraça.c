#include <time.h>
#include <stdio.h>
#include <stdlib.h>

int insere(int *l, int *tam, int cap, int x) {
    if (tam < cap) {
    if (busca(l, tam, x) == 0) {
            l[*tam + 1] = x;
        *tam = *tam + 1;
    } else {
        return -1;
    }
    } else {
    return -2;
    }
    return 0;
}

int busca(int *l, int tam, int x) {
   int i, ivalor;

   for (i = 0; i < tam; i++) {
        if (x == l[i]) {
        ivalor = i;
        break;
    }
   }

   if (i == tam) {
        return -1;
   } else {
    return ivalor;
   }
}




int main() {
    //Declaração de variáveis
    FILE *arq;
    clock_t ct_i, ct_f; // variáveis que medem
    //int lista[1000000];
    int *lista;
    int l, num, i, valor, k, ivalor,valor_inserir, r;

    lista = malloc(1000000*sizeof(int));

    // Abertura do arquivo
    arq = fopen("lista.txt", "r");

    // Leitura dos dados em disco para um vetor
    i = 0;
    while (fscanf(arq, "%ld", &num) > 0) {
        lista[i] = num;
    i++;
    }

    printf("Digite um numero: ");
    scanf("%d", &valor);


    // Leitura do tempo inicial
    ct_i = clock();

    // Apenas aqui começamos e medir o tempo de processamento

    // A rotina de busca
    /*for (k=0; k < i; k++) {
        if (x == lista[k]) {
        ivalor = k;
        break;
    }
    }*/
    r = busca(lista, i, valor);




    // Fim da medida do tempo de execução
    

    // Se k for o tamanho da lista signfica que o valor não foi encontrado
    if (r == -1) printf("Valor não encontrado!\n");
    else printf("Valor encontrado em %d.\n", r + 1);

    // Fim da medida do tempo de execução
    ct_f = clock();
    
    // Cálculo do tempo decorrido
    printf("Tempo decorrido: %lfs. \n", ((float)(ct_f - ct_i) / CLOCKS_PER_SEC));

    // Fecha o arquivo
    fclose(arq);

    // Fim de execução sem problema
    return 0;
}