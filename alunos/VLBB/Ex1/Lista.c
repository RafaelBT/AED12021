 #include <stdio.h>
 #include <stdlib.h>
 
 #define tam 1000000
 
 int main () {
     int Nleitura, P = 1; int i;
     int Nbusca /*= -1*/;

    FILE * ent = fopen("lista.txt", "r");

    //while(Nbusca<0)
      //  do{
         printf ("Qual numero (positivo) deseja buscar?\n");
         scanf ("%d", &Nbusca);
       // }

    for(i=0; i<tam; i++){
        fscanf(ent, "%d\n", &Nleitura); 
        if(Nleitura == Nbusca) break;
        P++;
    }
    if(i < tam) printf("A busca encontrou o numero %d, ele se encontra na posicao %d.", Nbusca, P);
    else printf ("O valor buscado nao se encontra na lista");
 }