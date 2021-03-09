#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


typedef struct
{
	long *i;

	long cap;
	long tam;
} vetor_t;


vetor_t *vetor_ler_arquivo(char *nome_de_arquivo);
long vetor_busca_linear(long *vetor, long tam, long i);
long vetor_busca_binaria(long *vetor, long tam, long i);
long vetor_insere(long *vetor, long *tam, long cap, long i);
void vetor_remove(long *vetor, long tam, long i);

void vetor_imprime(long *vetor, long tam);

int qsort_cmp(long *a, long *b);

vetor_t *vetor_ler_arquivo(char *nome_de_arquivo)
{
	long i;
	long tam;
	vetor_t *vetor;
	long *d;
	FILE *arquivo;

	char linha[128];

	arquivo = fopen(nome_de_arquivo, "r");
	if (arquivo == NULL)
	{
		fprintf(stderr, "Não foi possível abrir o arquivo %s. Abortando...\n", nome_de_arquivo);
		exit(-1);
	}

	// Pegamos número de linhas do arquivo de entrada, e inicializamos a memória do vetor
	fseek(arquivo, 0L,SEEK_END);
	tam = ftell(arquivo);
	fseek(arquivo, 0L, SEEK_SET);

	vetor = malloc(sizeof(vetor_t));

	d = malloc(sizeof(long) * (size_t) tam);
	if (d == NULL)
	{
		fprintf(stderr, "Erro malloc. Abortando...\n");
		fclose(arquivo);
		exit(-1);
	}

	for (i = 0; i < tam; i++)
	{
		memset(linha, 0, sizeof(linha));
		fgets(linha, sizeof(linha), arquivo);

		*(d + i) = strtol(linha, NULL, 10);
	}

	vetor->i = d;
	vetor->cap = i;
	vetor->tam = i;

	return vetor;
}

long vetor_busca_linear(long *vetor, long tam, long i)
{
	if (vetor == NULL) return -1; // Vetor não inicializado

	long res = -1;
	long k = 0;
	for (; k < tam; k++)
	{
		if (*(vetor + k) == i) return k;
	}

	return res; // Se número não for encontrado, retornamos -1
}

long vetor_busca_binaria(long *vetor, long tam, long i)
{
	if (vetor == NULL) return -1;

	long p = 0;
	long j = tam;
	long k;

	while (p != j)
	{
		k = (long) (p + j) / 2;
		if (*(vetor + k) == i)
		{
			// Achamos
			return k;
		}
		else if (i > *(vetor + k))
		{
			p = k;
		}
		else
		{
			j = k;
		}
	}

	return -1; // Número não encontrado!
}

// Retorna a posição no vetor que o elemento foi inserido (ou encontado), ou valores negativos em caso de erro
long vetor_insere(long *vetor, long *tam, long cap, long i)
{
	if (vetor == NULL)
	{
		return -1;
	}
	else if (*tam >= cap) return -2;

	long p;

	if ((p = vetor_busca_linear(vetor, *tam, i)) == -1)
	{
		*(vetor + ++(*tam)) = i;
		return *tam;
	}
	else
	{
		fprintf(stderr, "Elemento %ld já existe na lista, posição %ld!\n", i, p);
		return p;
	}
}

void vetor_remove(long *vetor, long tam, long i)
{
	if (vetor == NULL) return;

	long k = vetor_busca_linear(vetor, tam, i);
	if (k >= 0)
	{
		while (k < tam)
		{
			*(vetor + k) = *(vetor + k + 1);

			k++;
		}
	}
	else
	{
		fprintf(stderr, "Elemento %ld não encontrado na lista!\n", i);
	}
}

void vetor_imprime(long *vetor, long tam)
{
	if (vetor == NULL) return;

	long k = 0;
	for (; k < tam; k++)
	{
		fprintf(stdout, "%ld\n", (*(vetor + k)));
	}
}

int qsort_cmp(long *a, long *b)
{
	return (*a - *b);
}

int main(int argc, char *argv[])
{
	// Perguntamos para o usuário o nome do arquivo e o número que se deseja encontrar.
	if (argc < 3)
	{
		fprintf(stderr, "Uso: %s <nome do arquivo> <número>\n", argv[0]);
		return -1;
	}

	// 
	clock_t inicio, fim;
	
	// Convertemos a sequência de caracteres da entrada em um inteiro long. (base 10)
	long numero = strtol(argv[2], NULL, 10);
	
	// Posição do elemento a ser encontrado
	long i;

	// Nosso vetor para os números a serem lidos a partir do arquivo
	vetor_t *vetor;

	// Lemos os números a partir do arquivo
	vetor = vetor_ler_arquivo(argv[1]);

	inicio = clock();
	i = vetor_busca_linear(vetor->i, vetor->tam, numero);
	fim = clock();

	if (i >= 0)
	{
		// Número encontrado!
		fprintf(stdout, "[busca linear] Elemento %ld encontrado na posição %ld\n", numero, i);
	}
	else
	{
		fprintf(stdout, "[busca linear] Elemento %ld não encontrado na lista!\n", numero);
	}

	fprintf(stdout, "[busca linear] Tempo de execução: %lfs\n\n", ((float) (fim - inicio) / CLOCKS_PER_SEC));

	
	// Para usar a busca binária, vamos ordenar a lista
	qsort(vetor->i, vetor->tam, sizeof(long), qsort_cmp);

	// Os primeiros vetor->tam eleemntos do vetor vetor->i agora estão ordenados, vamos tentar achar o mesmo número usando busca binária

	inicio = clock();
	i = vetor_busca_binaria(vetor->i, vetor->tam, numero);
	fim = clock();

	if (i >= 0)
	{
		// Número encontrado!
		fprintf(stdout, "[busca binária] Elemento %ld encontrado na posição %ld\n", numero, i);
	}
	else
	{
		fprintf(stdout, "[busca binária] Elemento %ld não encontrado na lista!\n", numero);
	}

	fprintf(stdout, "[busca binária] Tempo de execução: %lfs\n\n", ((float) (fim - inicio) / CLOCKS_PER_SEC));

	// Agora para utiliar a remoção, vamos forçar para retirar o primeiro elemento, obtendo assim o pior caso possível para o algoritmo

	inicio = clock();
	vetor_remove(vetor->i, vetor->tam, *(vetor->i));
	fim = clock();

	fprintf(stdout, "[remoção] Tempo de execução: %lfs\n\n", ((float) (fim - inicio) / CLOCKS_PER_SEC));

	// Agora que removemos um elemento, podemos adicionar outro sem problemas

	srand(time(NULL));

	long numero_aleatorio = rand() % 1000000; 

	inicio = clock();
	i = vetor_insere(vetor->i, &(vetor->tam), vetor->cap, numero_aleatorio);
	fim = clock();

	fprintf(stdout, "[inserção] Tempo de execução: %lfs\n", ((float) (fim - inicio) / CLOCKS_PER_SEC));

	// Liberamos memória
	free(vetor->i);
	free(vetor);
	return 0;
}
