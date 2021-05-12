#define MAXLISTA 1000000

int geralista(int tam) {

	FILE *file;
	int i, num;

	if (tam > MAXLISTA) tam = MAXLISTA;

	file = fopen("lista.txt", "w");

	// muda a semente dos números aleatórios
	srand((unsigned) time(NULL)/2);

	for (i = 0; i< tam; i++) {
		num = rand();
		fprintf(file, "%d\n", num);
	}

	fclose(file);
	return 0;
}