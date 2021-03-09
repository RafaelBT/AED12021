#include <time.h>
#include <stdio.h>

int main() {
    clock_t ct_i, ct_f;

    ct_i = clock();

    printf("Realizando Operação Qualquer!\n\n");

    ct_f = clock();

    printf("Tempo decorrido: %lfs. \n", ((float)(ct_f - ct_i) / CLOCKS_PER_SEC));

    return 0;
}

