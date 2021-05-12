#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Pilha {
	int capacidade;
	int tamanho; 
	int posicao;
	int *dados;
};

void imprimePilha(struct Pilha *p) {
  printf("Capacidade %d\n", p->capacidade);
  printf("Tamanho %d\n", p->tamanho);
  printf("Posicao %d\n", p->posicao);

  return;
}

void imprimePilhaValores(struct Pilha *p) {

  printf("TOPO\t");
	for (int i = p->posicao; i > 0; i = i - 1){
		printf("%d\t", p->dados[i]);
  }
	printf("FIM\n");
}

int criaPilha(struct Pilha *p, int cap) {
	p->capacidade = cap;
	p->posicao = 0;
	p->dados = (int*) malloc (p -> capacidade * sizeof(int));
}

int pilhaCheia(struct Pilha *p) {
  return p->capacidade == p->posicao;
}

int pilhaVazia(struct Pilha *p) {
  return p->posicao == 0;
}

int empilha(struct Pilha *p, int valor) {
  if(pilhaCheia(p)) return -1; // overflow

  p->posicao++;
  p->dados[p->posicao] = valor;

  return 0;
}

int desempilha(struct Pilha *p) {
  if(pilhaVazia(p)) return -1; // underflow

  int valor = p->dados[p->posicao];
  p->posicao--;

  return valor;
}

int operacao(struct Pilha *p) {
  int teclado = 1000;
  int aux;
  int resultado;
  clock_t start, end;
  double cpu_time_used;
  

  while (teclado != 0) {
      printf ("\nQual operação realizar?\n");
      printf ("0 -- SAIR\n");
      printf ("1 -- Empilha\n");
      printf ("2 -- Desempilha\n");
      printf ("3 -- Imprimir status da pilha\n");
      printf ("4 -- Imprimir valores da pilha\n");
      scanf ("%d", &teclado);
      printf ("\n");

      switch (teclado) { 
        case 1:
          printf ("Qual número inserir?\n");
          scanf ("%d", &aux);
          printf ("\n");

          start = clock();

          resultado = empilha(p, aux);

          end = clock();

          if(resultado == 0) printf("O número %d foi empilhado.\n", aux);
          else if(resultado == -1) printf("Operação não executada pois causaria OVERFLOW!\n");
          break;
        
        case 2:
          start = clock();

          resultado = desempilha(p);

          end = clock();

          if(resultado >= 0) printf("O número %d foi removido.\n", resultado);
          else if(resultado == -1) printf("Operação não realizada pois causaria UNDERFLOW!\n");
          break;

        case 3:
          start = clock();

          imprimePilha(p);

          end = clock();
          break;
        case 4:
          start = clock();

          imprimePilhaValores(p);

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
  struct Pilha p;
  int aux;

  printf("Qual o tamanho máximo da sua pilha? ");
  scanf("%d", &aux);

  criaPilha(&p, aux);
  printf ("Deseja gerar valores aleatórios?\n[1]SIM\n[0]NÃO\n");
  scanf ("%d", &aux);
  printf ("\n");

  if(aux == 1) {
    printf ("Quantos elementos? ");
    scanf ("%d", &aux);
    printf ("\n");

    srand((unsigned) time(NULL));
  
    for(int i = 0; i < aux; i++ ) {
      empilha(&p, rand());
    }
  }

  operacao(&p);  
  
  return 0;
}