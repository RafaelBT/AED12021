#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Fila {
	int capacidade;
	int tamanho; 
	int inicio;
	int fim;
	int *dados;
};

void imprimeFila(struct Fila *f) {
  printf("Capacidade %d\n", f->capacidade);
  printf("Tamanho %d\n", f->tamanho);
  printf("Inicio %d\n", f->inicio);
  printf("Fim %d\n", f->fim);

  return;
}

void imprimeFilaValores(struct Fila *f) {
	int aux = f->inicio;

  printf("INICIO\t");
	for (int i = 0; i < f->tamanho; i++){
		printf("%d\t", f->dados[aux]);

    aux++;
		if (aux == f->capacidade) aux = 0;
	}
  printf("FIM\n");
}

int criaFila(struct Fila *f, int cap) {
	f->capacidade = cap;
	f->tamanho = 0;
	f->inicio = 0;
	f->fim = -1;
	f->dados = (int*) malloc (f -> capacidade * sizeof(int));
}

int filaCheia(struct Fila *f) {
  return f->capacidade == f->tamanho;
}


int filaVazia(struct Fila *f) {
  return f->tamanho == 0;
}

int enfilera(struct Fila *f, int valor) {
  if(filaCheia(f)) return -1; // overflow
  
  // verifica se o ponteiro fim chegou no fim da fila e precisa recomeçar do -1
  if(f->fim == f->capacidade - 1) f->fim = -1;

  f->fim++;
  f->tamanho++;
  f->dados[f->fim] = valor;

  return 0;
}

int desinfilera(struct Fila *f) {
  if(filaVazia(f)) return -1; // underflow

  int valor = f->dados[f->inicio];
  f->inicio++;
  f->tamanho--;

  // verifica se o inicio passou do fim da fila e precisa recomeçar do 0
  if(f->inicio == f->capacidade) f->inicio = 0;

  return valor;
}

int operacao(struct Fila *f) {
  int teclado = 1000;
  int aux;
  int resultado;
  clock_t start, end;
  double cpu_time_used;
  

  while (teclado != 0) {
      printf ("\nQual operação realizar?\n");
      printf ("0 -- SAIR\n");
      printf ("1 -- Enfilera\n");
      printf ("2 -- Desinfilera\n");
      printf ("3 -- Imprimir status da fila\n");
      printf ("4 -- Imprimir valores da fila\n");
      scanf ("%d", &teclado);
      printf ("\n");

      switch (teclado) { 
        case 1:
          printf ("Qual número inserir?\n");
          scanf ("%d", &aux);
          printf ("\n");

          start = clock();

          resultado = enfilera(f, aux);

          end = clock();

          if(resultado == 0) printf("O número %d foi enfilerado.\n", aux);
          else if(resultado == -1) printf("Operação não executada pois causaria OVERFLOW!\n");
          break;
        
        case 2:
          start = clock();

          resultado = desinfilera(f);

          end = clock();

          if(resultado >= 0) printf("O número %d foi removido.\n", resultado);
          else if(resultado == -1) printf("Operação não realizada pois causaria UNDERFLOW!\n");
          break;

        case 3:
          start = clock();

          imprimeFila(f);

          end = clock();
          break;
        case 4:
          start = clock();

          imprimeFilaValores(f);

          end = clock();
          break;

        default:
          // default para evitar loop infinito em caso de inserir algo errado
          start = clock();

          printf("\n Fim da execução \n");
          teclado = 0;

          end = clock();
          break;
      }

    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Tempo de execução %lf segundos.\n\n", cpu_time_used);
  }
}

int main () {
  struct Fila f;
  int aux;

  printf("Qual o tamanho máximo da sua fila? ");
  scanf("%d", &aux);

  criaFila(&f, aux);

  printf ("Deseja gerar valores aleatórios?\n[1]SIM\n[0]NÃO\n");
  scanf ("%d", &aux);
  printf ("\n");

  if(aux == 1) {
    printf ("\n");
    srand((unsigned) time(NULL));
  
    for(int i = 0; i < f.capacidade; i++ ) {
      enfilera(&f, rand());
    }
  }

  operacao(&f);  
  
  return 0;
}