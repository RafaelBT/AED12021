#include <stdio.h>
#include <stdlib.h>
#include <time.h>
 
#define TAMANHO 1000000

#define MAXLISTA 1000000
int geralista(int tam) {

	FILE *file;
	int i, num;

	if (tam > MAXLISTA) tam = MAXLISTA;

	file = fopen("lista.txt", "w");

	// muda a semente dos números aleatórios
	srand((unsigned) time(NULL)/2);

	for (i = 0; i < tam; i = i + 1) {
		num = rand();
		fprintf(file, "%d\n", num);
	}

	fclose(file);
	return 0;
}


int buscaLista(int procurado, int *vetor, int tamanho) {
  int i;

  for(i = 0; i < tamanho; i = i + 1) {
    if(vetor[i] == procurado) break;
  }

  if(i == tamanho) return -1; // se não achou retorna 0
  return i;
}

int insereLista(int numero, int *vetor, int *tamanho) {
  if(*tamanho + 1 > TAMANHO) return -1; // se overflow retorna -1;

  if(buscaLista(numero, vetor, *tamanho) != -1) return -2; // se já está na lista retorna -2

  vetor[*tamanho] = numero; //vetor começa em 0, então precisa somar depois
  *tamanho = *tamanho + 1;

  return 0; // se sucesso retorna 0;
}

int removeLista(int numero, int *vetor, int *tamanho) {
  if(*tamanho - 1 < 0) return -1; // se underflow retorna -1;

  int posicao = buscaLista(numero, vetor, *tamanho);

  if(posicao == -1) return -2; // se não está na lista retorna -2

  for(int i = posicao + 1; i < *tamanho; i = i + 1) {
    vetor[i - 1] = vetor[i];
  }

  *tamanho = *tamanho - 1;

  return posicao; // se sucesso retorna a posição que o número estava;
}

int imprimeLista(int *vetor, int tamanho) {
  for(int i = 0; i < tamanho; i = i + 1) {
    printf("%d está na posição %d.\n", vetor[i], i);
  }
}

int iniciarlizarLista(int *vetor, FILE *arq) {
  int num, i = 0;

  while (fscanf(arq, "%d", &num) > 0) {
    vetor[i] = num;
    if(i > TAMANHO) {
      printf("Lista inicial é maior que o tamanho máximo");
      exit(0);
    }
	  i++;
  }

  return i;
} 

int operacao(int *vetor, int *tamanho) {
  int teclado = 1000;
  int aux;
  int resultado;
  clock_t start, end;
  double cpu_time_used;
  

  while (teclado != 0) {
      printf ("\nQual operação realizar?\n");
      printf ("0 -- SAIR\n");
      printf ("1 -- Buscar na lista\n");
      printf ("2 -- Inserir na lista\n");
      printf ("3 -- Remover da lista\n");
      printf ("4 -- Imprimir lista\n");
      scanf ("%d", &teclado);
      printf ("\n");

      switch (teclado) {
        case 1:
          printf ("Qual número procurar?\n");
          scanf ("%d", &aux);
          printf ("\n");

          start = clock();

          resultado = buscaLista(aux, vetor, *tamanho);

          end = clock();

          if(resultado > -1) printf("O número %d foi encontrado na posição %d.\n", aux, resultado);
          else printf("Número não encontrado.\n");

          break; 
        case 2:
          printf ("Qual número inserir?\n");
          scanf ("%d", &aux);
          printf ("\n");

          start = clock();

          resultado = insereLista(aux, vetor, tamanho);

          end = clock();

          if(resultado == 0) printf("O número %d foi inserido\n", aux);
          else if(resultado == -1) printf("Operação não executada pois causaria OVERFLOW!\n");
          else if (resultado == -2) printf("O núnero já está na lista\n");
          break;
        
        case 3:
          printf ("Qual número remover?\n");
          scanf ("%d", &aux);
          printf ("\n");

          start = clock();

          resultado = removeLista(aux, vetor, tamanho);

          end = clock();

          if(resultado >= 0) printf("O número %d foi removido, ele estava na posição %d.\n", aux, resultado);
          else if(resultado == -1) printf("Operação não realizada pois causaria UNDERFLOW!zn");
          else if (resultado == -2) printf("O núnero não está na lista\n");
          break;

        case 4:
          start = clock();

          imprimeLista(vetor, *tamanho);

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

int main () {
  int aux;
  printf ("Deseja gerar uma lista nova?\n[1]SIM\n[0]NÃO\n");
  scanf ("%d", &aux);
  printf ("\n");

  if(aux == 1) {
    printf ("Qual o tamanho da lista? MAX %d\n", TAMANHO);
    scanf ("%d", &aux);
    printf ("\n");
    geralista(aux);
  }

  int *lista = malloc(TAMANHO * sizeof(int));
  FILE * entrada = fopen("lista.txt", "r");

  int tamanho = iniciarlizarLista(lista, entrada);

  printf("Lista carregada com %d elementos.\n", tamanho);

  operacao(lista, &tamanho);  
  
  return 0;
}