#include <time.h>
#include <stdio.h>
#include <stdlib.h>

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

int insere(int *l, int tam, int cap, int x) {
    if (tam < cap) {
	    if(busca(l, tam, x) == -1) {
            l[tam + 1] = x;
	        tam = tam + 1;
            FILE *arq;
            arq = fopen("lista.txt", "a");
            fprintf(arq,"\n%d",x);
            fclose(arq);
            return 0;
	    }else {
	        return -1;
	    }
    }else {
        return -2;
    }
}


int deletar(int *l, int tam, int x){
    int aux = busca(l, tam, x);
    if(aux != -1) {
        FILE *arq;
        arq = fopen("lista.txt", "w");
        for (int j = aux; j < tam; j++){
            if(j != tam){
                l[j] = l[j+1];
            }
        }
        for (int i = 0; i < tam -1; i++){
            fprintf(arq,"%d\n",l[i]);
        }
        fclose(arq);      
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
    int num, i, valor, k, ivalor, r, inserir, vinserir, capacidade = 120, vremover, remover,num2;

    lista = malloc(1000000*sizeof(int));

    // Abertura do arquivo
    arq = fopen("lista.txt", "r");

    // Leitura dos dados em disco para um vetor
    i = 0;
    while (fscanf(arq, "%ld", &num) > 0) {
        lista[i] = num;
	    i++;
    }
    

    printf("Digite 1-Buscar, 2-Remover ou 3-Inserir: ");
    scanf("%d",&num2);

    // Leitura do tempo inicial
    ct_i = clock();

    // Apenas aqui começamos e medir o tempo de processamento

    if(num2 == 1){
        //buscar
        printf("Digite um numero a ser buscado: ");
        scanf("%d", &valor);
        r = busca(lista, i, valor);
        // Se k for o tamanho da lista signfica que o valor não foi encontrado
        if (r == -1) printf("Valor nao encontrado!\n");
        else printf("Valor encontrado em %d.\n", r + 1);
    }else if(num2==2){
        //remover
        printf("Digite um numero a ser removido: ");
        scanf("%d", &vremover);
        remover = deletar(lista,i,vremover);
        //Remoção
        if(remover == -1){
            printf("Valor nao esta na lista para ser excluido\n");
        }else{
            printf("O valor foi excluido: %d\n",vremover);
    }
    }else if(num2==3){
        //inserir
        printf("Digite um numero a ser inserido: ");
        scanf("%d", &vinserir);
        inserir = insere(lista,i,capacidade,vinserir);
        //Comando de inserção
        if(inserir == -1){
            printf("O numero ja estava na lista\n");
        }else if(inserir == -2){
            printf("lista esta cheia\n");
        }else{
            printf("O valor foi inserido: %d\n",lista[i+1]);
        }
    }else{
        printf("Operacao nao existe\n");
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

