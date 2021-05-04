#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct node
{
  int num;
  struct node* direita;
  struct node* esquerda;
} Node;

// Função que verifica se um node é vazio
int isVazio(Node *elemento) {
  return elemento == NULL;
}

// A função auxiliar imprimeNo imprime o numero
// precedido de 3b espaços e seguido de uma mudança
// de linha.
void imprimeNo(int n, int b) {
    int i;
    for (i = 0; i < b; i++) printf("   ");
    printf("%d\n", n);
}

void imprimeNull(char *str, int b) {
    int i;
    for (i = 0; i < b; i++) printf("   ");
    printf("%s\n", str);
}

void mostraArvore(Node* node, int b) {
  if (node == NULL) {
      imprimeNull("--", b);
      return;
  }
  mostraArvore(node->direita, b + 1);
  imprimeNo(node->num, b);
  mostraArvore(node->esquerda, b + 1);
}


/* Função que insere um dado na árvore; 0 = inseriu; -1 não inseriu*/
int inserir(Node **Raiz, int num) {
  // *Raiz é a Raiz da subarvore atual;

  // Se o elemento atual for vazio, insere nele;
  if(*Raiz == NULL) {
    *Raiz = (Node*)malloc(sizeof(Node)); /* Aloca memória para a estrutura */
    (*Raiz)->esquerda = NULL; /* Subárvore à esquerda é NULL */
    (*Raiz)->direita = NULL; /* Subárvore à direita é NULL */
    (*Raiz)->num = num; /* Armazena a informação */
    return 0;
  }
  
  /* Se o número for menor então vai pra esquerda */
  if(num < (*Raiz)->num) {
    /* Percorre pela subárvore à esquerda */
    inserir(&(*Raiz)->esquerda, num);
    return 0;
  }

  /* Se o número for maior então vai pra direita */
  if(num > (*Raiz)->num) {
    /* Percorre pela subárvore à direita */
    inserir(&(*Raiz)->direita, num);
    return 0;
  }

  return -1;
}


Node* minimo(Node *Raiz) {
    Node *current = Raiz;
 
    while (current && current->esquerda != NULL)
        current = current->esquerda;
 
    return current;
}


Node* maximo(Node *Raiz) {
    Node *current = Raiz;

    while (current && current->direita != NULL)
        current = current->direita;
 
    return current;
}


int altura(Node *Raiz) {
    int alturaEsquerda, alturaDireita;

    if (Raiz == NULL) return -1;

    alturaEsquerda = altura(Raiz->esquerda);
    alturaDireita = altura(Raiz->esquerda);

    if (alturaEsquerda > alturaDireita) return alturaEsquerda + 1;
    else return alturaDireita + 1;
}

Node* remover(Node *Raiz, int num) {
  if (isVazio(Raiz)) return NULL;

  if (num < Raiz->num) {  // está a esquerda
      Raiz->esquerda = remover(Raiz->esquerda, num);
  } else if (num > Raiz->num) { // está na direita
      Raiz->direita = remover(Raiz->direita, num);
  } else {
    // num a Raiz atual
    if (Raiz->esquerda == NULL && Raiz->direita == NULL) { // se não tiver filhos
      Raiz = NULL;
    }
    else if (Raiz->esquerda == NULL) { // se tiver filho a esquerda
      Raiz = Raiz->direita;;
    }
    else if (Raiz->direita == NULL) { // se tiver filho a direita
      Raiz = Raiz->esquerda;
    }
    else { // tem 2 filhos
      Node *min = minimo(Raiz->direita); // preciso do minimo da sub arvore a direita
      Raiz->num = min->num; // passa o valor numérico do min para para a Raiz atual
      Raiz->direita = remover(Raiz->direita, min->num); // deleta o min na sub arvore a direita
      free(min); // libera a memória do min
    }
  }
  return Raiz; // precisa retornar para terminar a recursividade
}

Node *busca(Node *Raiz, int valor) {
  if(isVazio(Raiz)) return NULL;

  if(Raiz->num == valor) 
    return Raiz;
  else if(Raiz->num < valor) 
    busca(Raiz->direita, valor);
  else if(Raiz->num > valor) 
    busca(Raiz->esquerda, valor);
}
int operacao(Node *Raiz) {
  int teclado = 1000;
  int aux;
  int resultado;
  clock_t start, end;
  double cpu_time_used;
  

  while (teclado != 0) {
      printf ("\nQual operação realizar?\n");
      printf ("0 -- SAIR\n");
      printf ("1 -- Buscar na Arvore\n");
      printf ("2 -- Inserir na Arvore\n");
      printf ("3 -- Remover da Arvore\n");
      printf ("4 -- Ordenar arvore -- Não implementado\n");
      printf ("5 -- Calcular mínimo\n");
      printf ("6 -- Calcular máximo\n");
      printf ("7 -- Calcular altura\n");
      printf ("8 -- Imprimir arvore (NÃO USAR SE A ARVORE TIVER MTO VALORES)\n");

      scanf ("%d", &teclado);
      printf ("\n");

      switch (teclado) {
        case 1:
          printf ("Qual número procurar?\n");
          scanf ("%d", &aux);
          printf ("\n");

          start = clock();

          if(busca(Raiz, aux)) printf("O número %d foi encontrado", aux);
          else printf("Número não encontrado.\n");

          end = clock();

          break; 
        case 2:
          printf ("Qual número inserir?\n");
          scanf ("%d", &aux);
          printf ("\n");

          start = clock();

          resultado = inserir(&Raiz, aux);

          end = clock();

          if(resultado == 0) printf("O número %d foi inserido\n", aux);
          else if(resultado == -1) printf("O número não foi inserido pois já está na arvore\n");
          break;
        case 3:
          printf ("Qual número remover?\n");
          scanf ("%d", &aux);
          printf ("\n");

          start = clock();

          Raiz = remover(Raiz, aux);

          end = clock();

          printf("O número %d foi removido\n", aux);
          break;
        case 4:
        //   printf ("Qual número remover?\n");
        //   scanf ("%d", &aux);
        //   printf ("\n");

        //   start = clock();

        //   resultado = ordenar(%Raiz);

        //   end = clock();

        //   if(resultado >= 0) printf("O número %d foi removido.\n", aux);
        //   else if(resultado == -1) printf("Operação não realizada pois causaria UNDERFLOW!zn");
        //   else if (resultado == -2) printf("O núnero não está na lista\n");
          break;

        case 5:
          start = clock();

          printf("O mínimo é %d\n", minimo(Raiz)->num);

          end = clock();

          break;

        case 6:
          start = clock();

          printf("O mínimo é %d\n", maximo(Raiz)->num);

          end = clock();

          break;

        case 7: 
          start = clock();

          printf("O altura é %d\n", altura(Raiz));

          end = clock();
          break;

        case 8:
          start = clock();

          mostraArvore(Raiz, 0);

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
  Node *Raiz = NULL; /* Raiz da arvore primária */
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
      inserir(&Raiz, rand());
      if(i % aux / 2 == 0) inserir(&Raiz, 55555);
    }
  }

  operacao(Raiz);
  
  return 0;
}