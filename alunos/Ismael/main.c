#include <stdlib.h>
#include <stdio.h>
#include <time.h>


//Buscar n�mero na lista
int main (void){
    int tamanho_lista = 100;
    int procuraNum, leNum, cont = 0;

    if(fopen("lista.txt", "r") == NULL){
        geralista(tamanho_lista);
    }
    
    FILE *entrada = fopen("lista.txt", "r");

    printf("Digite o numero a ser procurado: ");
    scanf("%d", &procuraNum);


    while(fscanf(entrada, "%d\n", &leNum) == 1){
        if(procuraNum == leNum) {
            printf("N�mero encontrado na posi��o: %d", cont);
        }
        cont++;
    }

}
