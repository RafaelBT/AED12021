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
      printf("Node:%p com valor %d está apontado para %p\n", elemento, elemento->valor, elemento->proximo);
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
  if(lista->inicio != NULL) printf("O endereço do início é %p e armazena o valor %d\n", lista->inicio, lista->inicio->valor);
  if(lista->fim != NULL) printf("O endereço do fim é %p e armazena o valor %d\n", lista->fim, lista->fim->valor);
}

// insere um valor no início de uma lista retornando 0 em caso de sucesso
int inserirInicio(Lista *lista, int valor) {
  Node *elemento = (Node *) malloc(sizeof(Node));

  //inicializa o elemento
  elemento->valor = valor;
  elemento->proximo = NULL;

  // aumenta o tamanho da lista
  lista->tamanho++;

  // se lista está vazia o novo elemento será o inicio e fim
  if(lista->inicio == NULL) {
    lista->inicio = elemento;
    lista->fim = elemento;
    return 0;
  }

  // caso a lista tenha algum valor o ponteiro "proximo" recebe o início da lista
  elemento->proximo = lista->inicio;
  // e o inicio da lista vira o novo elemento
  lista->inicio = elemento;
  return 0;
}

// insere um valor no fim de uma lista retornando 0 em caso de sucesso
int inserirFim(Lista *lista, int valor) {
  Node *elemento = (Node *) malloc(sizeof(Node));

  // inicializa um elemento
  elemento->valor = valor;
  elemento->proximo = NULL;

  // aumenta o tamanho da lista
  lista->tamanho++;

  // se lista está vazia o novo elemento será o novo inicio e fim
  if(lista->inicio == NULL) {
    lista->inicio = elemento;
    lista->fim = elemento;
    return 0;
  }

  // caso a lista tenha elementos
  // o elemento será adicionado como o próximo do fim da lista atual
  lista->fim->proximo = elemento;
  // e o elemento será definido como novo fim da lista
  lista->fim = elemento;
  return 0;
}

// se achou retorna a pos do elemtno
// se não retorna -1
int busca(Lista *lista, int valor) { 
  Node *atual = lista->inicio;

  int i = 0;
  while (i < lista->tamanho) {
    if(atual == NULL) return -1;
    if(atual->valor == valor) return i;
    atual = atual->proximo;
    i++;
  }

  return -1;
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

  // procura pela primeira ocorrência de Node com o valor a ser removido
  while(aux != NULL && aux->proximo != NULL && aux->proximo->valor != valor) {
    aux = aux->proximo;
  }
  // a busca termina caso ele não encontre o valor (passou pela lista inteira e não achou)
  // ou se o aux->proximo->valor == valor

  // caso ele encontre um node com o valor a ser excluido
  if(aux != NULL && aux->proximo != NULL) {
    // para remover recebe o proximo do aux
    paraRemover = aux->proximo;

    // aux-proximo recebe o valor a frente do que será removido
    // isso basicamente remove da lista a referência de acessar o paraRemover
    aux->proximo = paraRemover->proximo;

    // mas pode ser que não exista um proximo então o aux vira o fim da lista
    if(aux->proximo == NULL) {
      lista->fim = aux;
    }
  }

  // se ele achou algum valor apra remover
  if(paraRemover != NULL) {
    // livra a memória
    free(paraRemover);
    // diminui o tamanho da lista
    lista->tamanho--;
    return 0;
  }

  // se nada for removido
  return -1;
}


Lista geraLista() {
  Lista lista;
  lista.inicio = NULL;
  lista.fim = NULL;
  lista.tamanho = 0;

  return lista;
}

int operacao(Lista *lista) {
  int teclado = 1000;
  int aux;
  int resultado;
  clock_t start, end;
  double cpu_time_used;
  

  while (teclado != 0) {
      printf ("\nQual operação realizar?\n");
      printf ("0 -- SAIR\n");
      printf ("1 -- Buscar na lista\n");
      printf ("2 -- Inserir no início da lista\n");
      printf ("3 -- Inserir no fim da lista\n");
      printf ("4 -- Remover da lista\n");
      printf ("5 -- Imprimir estado da lista\n");
      printf ("6 -- Imprimir os valroes da lista\n");

      scanf ("%d", &teclado);
      printf ("\n");

      switch (teclado) {
        case 1:
          printf ("Qual número procurar?\n");
          scanf ("%d", &aux);
          printf ("\n");

          start = clock();

          resultado = busca(lista, aux);

          end = clock();

          if(resultado > -1) printf("O número %d foi encontrado na posição %d.\n", aux, resultado);
          else printf("Número não encontrado.\n");

          break; 
        case 2:
          printf ("Qual número inserir?\n");
          scanf ("%d", &aux);
          printf ("\n");

          start = clock();

          resultado = inserirInicio(lista, aux);

          end = clock();

          if(resultado == 0) printf("O número %d foi inserido\n", aux);
          else if(resultado == -1) printf("O número não está na lista\n");
          break;
        case 3:
          printf ("Qual número inserir?\n");
          scanf ("%d", &aux);
          printf ("\n");

          start = clock();

          resultado = inserirFim(lista, aux);

          end = clock();

          if(resultado == 0) printf("O número %d foi inserido\n", aux);
          else if(resultado == -1) printf("Operação não executada pois causaria OVERFLOW!\n");
          else if (resultado == -2) printf("O núnero já está na lista\n");
          break;
        case 4:
          printf ("Qual número remover?\n");
          scanf ("%d", &aux);
          printf ("\n");

          start = clock();

          resultado = remover(lista, aux);

          end = clock();

          if(resultado >= 0) printf("O número %d foi removido.\n", aux);
          else if(resultado == -1) printf("Operação não realizada pois causaria UNDERFLOW!zn");
          else if (resultado == -2) printf("O núnero não está na lista\n");
          break;

        case 5:
          start = clock();

          imprimirLista(lista);

          end = clock();
          break;

        case 6:
          start = clock();

          imprimeValoresEnderecos(lista);

          end = clock();
          break;

        default:
          start = clock();

          printf("Fim da execução \n");
          teclado = 0;

          end = clock();
          break;
      }

    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Tempo de execução %lf segundos.\n\n", cpu_time_used);
  }
  
}

int main() {
  Lista l = geraLista();

  int aux;
  printf ("Deseja gerar valores aleatórios?\n[1]SIM\n[0]NÃO\n");
  scanf ("%d", &aux);
  printf ("\n");

  if(aux == 1) {
    printf ("Quantos elementos? ");
    scanf ("%d", &aux);
    printf ("\n");
    srand((unsigned) time(NULL));
  
    for(int i = 0; i < aux; i++ ) {
      inserirInicio(&l, rand());
    }
  }

  operacao(&l);

  return 0;
}