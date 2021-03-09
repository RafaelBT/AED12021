#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void geraLista(int size) {
    FILE * arq = fopen("lista.txt", "w");

    srand(time(NULL));

    for(int i = 0; i < size; i++) {
        fprintf(arq, "%d\n", rand() % 10000);
    }

    fclose(arq);
}

// A função busca por um número dentro de um vetor. Todas as funções aqui criadas assumem valores únicos para as chaves e, no caso de valores repetidos, é levado em consideração o primeiro caso
int buscar(int * v, int size, int num) {
    for(int i = 0; i < size; i++) {
        if(v[i] == num) return i;
    }

    return -1;
}

// A função adiciona um novo valor na parte da frente do vetor similar a uma pilha levando em consideração uma lista que não contenha valores repetidos, mesmo não sendo necessariamente o caso
int inserir(int * v, int * size, int sizeLimit, int num) {
    int index;
    
    if(*size < sizeLimit) {
        index = buscar(v, *size, num);

        if(index == -1) {
            v[*size] = num;
            *size = *size + 1; 

            return 0;
        } else {
            return index;
        }
    }
    
    return -2;
}

// A função procura por um elemento na lista para logo em seguida, caso ache o número, ele seja deletado e os índices alterados
int deletar(int * v, int * size, int num) {
    int indice;
    
    if(*size != 0) {
        indice = buscar(v, *size, num);

        if(indice != -1) {
            for(int i = indice; i < *size - 1; i++) {
                v[i] = v[i+1];
            }

            *size = *size - 1;

            return indice;
        } else {
            return -1;
        }
    }

    return -2;
}

int main(void) {
    geraLista(10000);

    FILE * listaTxt = fopen("lista.txt", "r");

    clock_t clk_i, clk_f;
    int size;
    int vSize = 0;
    int num;
    int numIndex;
    int * vector = (int *) malloc(sizeof(int) * 1000000);

// INÍCIO DA SEÇÃO DOS EXERCÍCIOS 1 E 2 //

    while(fscanf(listaTxt, "%d\n", &num) != -1) {
        vector[vSize] = num;
        vSize++;
    }

    printf("Qual o numero que voce deseja procurar na lista? ");
    scanf("%d", &num);
    printf("\n");

    numIndex = buscar(vector, vSize, num);
    if(numIndex != -1) {
        printf("O numero foi encontrado na posicao %d do vetor e na linha %d da lista", numIndex, numIndex + 1);
    } else {
        printf("O numero procurado nao se encontra na lista");
    }

    printf("\nTamanho do vetor: %d\n", vSize);
    printf("Qual o numero que voce deseja inserir no vetor? ");
    scanf("%d", &num);
    printf("\n");

    numIndex = inserir(vector, &vSize, 1000000, num);
    switch (numIndex) {
        case 0:
            printf("Numero adicionado no vetor!");
            break;
        
        case -2:
            printf("Overflow!!!");
            break;

        default:
            printf("Numero ja existe no vetor! Ele esta na posicao %d do vetor e na linha %d da lista.", numIndex, numIndex + 1);
            break;
    }

    printf("\nTamanho do vetor: %d\n", vSize);
    printf("vector[%d]: %d\n\n", vSize - 1, vector[vSize-1]);

    printf("Qual o numero que voce deseja retirar do vetor? ");
    scanf("%d", &num);
    printf("\n");

    numIndex = deletar(vector, &vSize, num);
    switch (numIndex) {
        case -1:
            printf("Numero nao existe no vetor!");
            break;
        
        case -2:
            printf("Underflow!!!");
            break;
        
        default:
            printf("Numero retirado do vetor! Ele estava na posicao %d do vetor e na linha %d da lista", numIndex, numIndex + 1);
            break;
    }

    printf("\nTamanho do vetor: %d\n", vSize);
    printf("vector[%d]: %d\n\n", numIndex, vector[numIndex]);

    free(vector);
    fclose(listaTxt);

// FIM DA SEÇÃO DOS EXERCÍCIOS 1 E 2 //

// EXERCÍCIO 3 //
    // LISTA COM 100 NÚMEROS

    size = 100;
    vSize = 0;

    geraLista(size);

    vector = (int *) malloc(sizeof(int) * size);
    listaTxt = fopen("lista.txt", "r");

    while(fscanf(listaTxt, "%d\n", &num) != -1) {
        vector[vSize] = num;
        vSize++;
    }

    printf("Qual o numero que voce deseja procurar na lista? ");
    scanf("%d", &num);
    printf("\n");

    clk_i = clock();
    numIndex = buscar(vector, vSize, num);
    clk_f = clock();

    if(numIndex != -1) {
        printf("O numero foi encontrado na posicao %d do vetor e na linha %d da lista", numIndex, numIndex + 1);
    } else {
        printf("O numero procurado nao se encontra na lista");
    }
    printf("\nA busca durou %lfs\n\n", (float) (clk_f - clk_i)/CLOCKS_PER_SEC);

    // LISTA COM 10K NÚMEROS

    size = 10000;
    vSize = 0;

    geraLista(size);

    vector = (int *) malloc(sizeof(int) * size);
    listaTxt = fopen("lista.txt", "r");

    while(fscanf(listaTxt, "%d\n", &num) != -1) {
        vector[vSize] = num;
        vSize++;
    }

    printf("Qual o numero que voce deseja procurar na lista? ");
    scanf("%d", &num);
    printf("\n");

    clk_i = clock();
    numIndex = buscar(vector, vSize, num);
    clk_f = clock();

    if(numIndex != -1) {
        printf("O numero foi encontrado na posicao %d do vetor e na linha %d da lista", numIndex, numIndex + 1);
    } else {
        printf("O numero procurado nao se encontra na lista");
    }
    printf("\nA busca durou %lfs\n\n", (float) (clk_f - clk_i)/CLOCKS_PER_SEC);

    // LISTA COM 1M NÚMEROS

    size = 1000000;
    vSize = 0;

    geraLista(size);

    vector = (int *) malloc(sizeof(int) * size);
    listaTxt = fopen("lista.txt", "r");

    while(fscanf(listaTxt, "%d\n", &num) != -1) {
        vector[vSize] = num;
        vSize++;
    }

    printf("Qual o numero que voce deseja procurar na lista? ");
    scanf("%d", &num);
    printf("\n");

    clk_i = clock();
    numIndex = buscar(vector, vSize, num);
    clk_f = clock();

    if(numIndex != -1) {
        printf("O numero foi encontrado na posicao %d do vetor e na linha %d da lista", numIndex, numIndex + 1);
    } else {
        printf("O numero procurado nao se encontra na lista");
    }
    printf("\nA busca durou %lfs\n", ((float)(clk_f - clk_i)/CLOCKS_PER_SEC));

// FIM DA SEÇÃO DOS EXERCICIO 3 //
}