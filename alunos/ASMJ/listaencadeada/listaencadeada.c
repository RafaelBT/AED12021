#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Node {
  int valor;
  struct Node *proximo;
} Node;

typedef struct {
  Node *inicio;
  Node *fim;
  int tamanho;
} Lista;

void imprimeValoresEnderecos(Lista *lista) {
  Node *elemento = lista->inicio;
  printf("Tamanho da lista: %d\n", lista->tamanho);

  while(elemento != NULL) {
      printf("Node:%p com valor %d está apontado para %p\n\n", elemento, elemento->valor, elemento->proximo);
      elemento = elemento->proximo;
  }
  printf("\n");
}

void imprimirValores(Lista *lista) {
  Node *elemento = lista->inicio;

  while(elemento != NULL) {
      printf("%d\t", elemento->valor);
      elemento = elemento->proximo;
  }
  printf("\n");
}

void imprimirLista(Lista *lista) {
  printf("O tamanho da lista atual é %d\n", lista->tamanho);
  printf("O endereço do início é %p e armazena o valor %d\n", lista->inicio, lista->inicio->valor);
  printf("O endereço do fim é %p e armazena o valor %d\n", lista->fim, lista->fim->valor);
}

int inserirInicio(Lista *lista, int valor) {
  Node *elemento = (Node *) malloc(sizeof(Node));

  elemento->valor = valor;
  elemento->proximo = NULL;

  lista->tamanho++;

  // a lista está vazia
  if(lista->inicio == NULL) {
    lista->inicio = elemento;
    lista->fim = elemento;
    return 0;
  }

  elemento->proximo = lista->inicio;
  lista->inicio = elemento;
  return 0;
}

int inserirFim(Lista *lista, int valor) {
  Node *elemento = (Node *) malloc(sizeof(Node));

  elemento->valor = valor;
  elemento->proximo = NULL;

  lista->tamanho++;

  // a lista está vazia
  if(lista->inicio == NULL) {
    lista->inicio = elemento;
    lista->fim = elemento;
    return 0;
  }

  lista->fim->proximo = elemento;
  lista->fim = elemento;
  return 0;
}

int remover(Lista *lista, int valor) {
  if(lista->inicio == NULL) {
    return -1;
  }

  Node *aux = lista->inicio;
  Node *paraRemover = NULL;

  // se lista está vazia

  // se o valor a ser removido for o primeiro
  if(aux->valor == valor) {
    paraRemover = aux;
    lista->inicio = paraRemover->proximo;

    // se a lista ficar vazia após a remoção
    if(aux == NULL) lista->fim = NULL;

    free(paraRemover);
    lista->tamanho--;
    return 0;
  }

  // procura pelo node com o valor a ser removido
  while(aux != NULL && aux->proximo != NULL && aux->proximo->valor != valor) {
    aux = aux->proximo;
  }

  if(aux != NULL && aux->proximo != NULL) {
    paraRemover = aux->proximo;
    aux->proximo = paraRemover->proximo;

    if(aux->proximo == NULL) {
      lista->fim = aux;
    }
  }

  if(paraRemover != NULL) {
    free(paraRemover);
    lista->tamanho--;
    return 0;
  }

  // se nada for removido
  return -1;
}

int main() {
  Lista lista;

  lista.inicio = NULL;
  lista.fim = NULL;
  lista.tamanho = 0;

  // printf("sizeof (celula) = %lu\n", sizeof (elemento));
  inserirInicio(&lista, 5);
  inserirInicio(&lista, 4);
  inserirInicio(&lista, 13);
  inserirInicio(&lista, 8);
  inserirInicio(&lista, 2);
  inserirFim(&lista, 9);
  
  imprimeValoresEnderecos(&lista);

  // remover(&lista, 5);

  imprimirLista(&lista);

  return 0;
}