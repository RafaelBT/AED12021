#include <time.h>
#include <stdio.h>
#include <stdlib.h>

int search(int *l, int s, int x) {
   int position = -1;

    for (int i = 0; i < s; i++) {
        if (x == l[i]) {
            position = i;
            break;
        }
    }

    return position;
}

int insert(int *l, int s, int c, int x) {
    if (s < c) {
	    if(search(l, s, x) == -1) {
            l[s + 1] = x;
	        s += 1;
            FILE *file;
            file = fopen("lista.txt", "a");
            fprintf(file, "\n%d", x);
            fclose(file);
            return 0;               // Okay
	    }else {
	        return -1;              // Número j´pa está na lista
	    }
    }else {
        return -2;                  // Overflow
    }
}

int delete(int *l, int s, int v){
    int position = search(l, s, v);
    if(position != -1) {
        FILE *file;
        file = fopen("lista.txt", "w");
        for (int j = position; j < s; j++){
            l[j] = l[j + 1];
        }
        for (int i = 0; i < s - 1; i++){
            if (i != s - 2) fprintf(file, "%d\n", l[i]);
            else fprintf(file, "%d", l[i]);
        }
	}else{
        return -1;
    }
}

int main() {
    // Declaração de variáveis
    FILE *file;
    clock_t ct_i, ct_f; // Variáveis que medem o tempo
    int *list;
    int num, size, value, capacity = 105, operation, r_search, r_insert;

    list = malloc(1000000*sizeof(int));

    // Abertura do arquivo
    file = fopen("lista.txt", "r");

    // Leitura dos dados em disco para um vetor
    size = 0;
    while (fscanf(file, "%ld", &num) > 0) {
        list[size] = num;
	    size++;
    }

    printf("[1] Buscar\n[2] Inserir\n[3] Remover\n");
    printf("Numero da operacao: ");
    scanf("%d", &operation);

    switch (operation) {
    case 1:
        // Buscar um valor
        printf("Digite um numero para ser pesquisado: ");
        scanf("%d", &value);

        // Início do cronômetro
        ct_i = clock();

        r_search = search(list, size, value);
        // Resultado da busca
        if (r_search == -1) printf("Valor nao encontrado!\n");
        else printf("Valor encontrado em %d.\n", r_search + 1);
        break;
    case 2:
        // Inserir um valor
        printf("Digite um numero para ser inserido: ");
        scanf("%d", &value);
        
        // Início do cronômetro
        ct_i = clock();
        
        r_insert = insert(list, size, capacity, value);
        // Resultado da inserção
        if (r_insert == 0) printf("O valor foi inserido: %d\n", list[size + 1]);
        else if (r_insert == -1) printf("O numero ja estava na lista\n");
        else printf("A lista esta cheia\n");
        break;
    case 3:
        // Remover um valor
        printf("Digite um numero para ser excluido: ");
        scanf("%d", &value);
        
        // Início do cronômetro
        ct_i = clock();
        
        delete(list, size, value);
        break;
    }

    // Fim do cronômetro
    ct_f = clock();

    // Cálculo do tempo decorrido
    printf("Tempo decorrido: %lfs. \n", ((float)(ct_f - ct_i) / CLOCKS_PER_SEC));

    // Fecha o arquivo
    fclose(file);

    // Fim de execução sem problema
    return 0;
}