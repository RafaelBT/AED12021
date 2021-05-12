#include <time.h>
#include <stdio.h>
#include <stdlib.h>

int insere(int *l, int tam, int cap, int x) {
    if (tam < cap) {
	    if(busca(l, tam, x) == -1) {
            l[tam + 1] = x;
	        tam = tam + 1;
            FILE *arq;
            arq = fopen("lista.txt", "a");
            fprintf(arq,"%d\n",x);
            fclose(arq);
            return 0;               //inseriu o valor
	    }else {
	        return -1;              //não inseriu pq a lista já tem o numero
	    }
    }else {
        return -2;                  //não inseriu pq a lista tá na capacidade max
    }
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
    }else {
	return ivalor;
   }
}

int excluir(int *l, int tam, int valor_excluir){
    int indice = busca(l, tam, valor_excluir);
    
    if(indice != -1) {
        FILE *arq;
        arq = fopen("lista.txt", "w");
        for (int y = indice; y < tam; y++){
            if(y != tam){
                l[y] = l[y+1];
            }
        }
        for (int i = 0; i < tam -1; i++){
            fprintf(arq,"%d\n",l[i]);
        }
        fclose(arq);
        return 0;
	}else{
        return -1;
    }
}




int main() {
    //Declaração de variáveis
    FILE *arq;
    clock_t ct_i, ct_f; // variáveis que medem
    //int lista[1000000];
    int *lista;
    int num, i, valor, k, ivalor, r, inserir, valor_inserir, capacidade = 105, valor_excluir,exclui,operacao;

    lista = malloc(1000000*sizeof(int));

    // Abertura do arquivo
    arq = fopen("lista.txt", "r");

    // Leitura dos dados em disco para um vetor
    i = 0;
    while (fscanf(arq, "%ld", &num) > 0) {
        lista[i] = num;
	    i++;
    }

    
    printf("tecle 1-Para buscar\n2-para inserir\n3-para excluir\n");
    scanf("%d", &operacao);
    
    if(operacao == 1){      //buscar
        printf("Digite um numero para ser pesquisado: ");
        scanf("%d", &valor);
        // Leitura do tempo inicial
        ct_i = clock();
        r = busca(lista, i, valor);
        if (r == -1) printf("Valor nao encontrado!\n");
        else printf("Valor encontrado em %d.\n", r + 1);
    }else if(operacao == 2){    //inserir
        printf("Digite um numero para ser inserido: ");
        scanf("%d", &valor_inserir);
        // Leitura do tempo inicial
        ct_i = clock();
        inserir = insere(lista,i,capacidade,valor_inserir);
        if(inserir == -1){
            printf("O numero ja estava na lista\n");
        }else if(inserir == -2){
            printf("lista esta cheia\n");
        }else{
            printf("O valor foi inserido: %d\n",lista[i+1]);
        }
    }else if(operacao == 3){
        printf("Digite um numero para ser excluido: ");
        scanf("%d", &valor_excluir);
        // Leitura do tempo inicial
        ct_i = clock();
        exclui = excluir(lista,i,valor_excluir);
        if (exclui == 0){
            printf("O valor foi excluido\n");
        }else{
            printf("O valor nao existe\n");
        }
   
    }else{
        printf("Operacao invalida\n");
    }


    // Fim da medida do tempo de execução
    ct_f = clock();

    // Cálculo do tempo decorrido
    printf("Tempo decorrido: %lfs. \n", ((float)(ct_f - ct_i) / CLOCKS_PER_SEC));

    // Fecha o arquivo
    fclose(arq);

    // Fim de execução sem problema
    return 0;
}

