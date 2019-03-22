#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_LEN 101

/*
  !!!!!!!!!!!! D A  F A R E !!!!!!!!!!!!
  sx e dx sono le posizioni del primo e dell'ultimo elemento dell'array mentre
  px è la posizione dell'elemento perno.
  La funzione deve restituire la posizione del perno dopo che gli elementi sono
  stati partizionati.
*/

void swap_str(char *a,char *b){
  char *tmp=malloc(MAX_LEN*sizeof(char));
  strcpy(tmp,a);
  strcpy(a,b);
  strcpy(b,tmp);
  free(tmp);
}

int distribuzione(char **a , int sx,int px, int dx) {
  int j;
  px=dx;
  swap_str(*(a+px),*(a+dx));
  int i=sx-1;
  for (j=sx;j<dx;j++){
    if (strcmp(*(a+j),*(a+dx))< 0){
      i++;
      swap_str(*(a+i),*(a+j));}}
  swap_str(*(a+i+1),*(a+dx));
  return i+1;
}

void quicksort( char **a, int sx, int dx ) {
  int perno, pivot;
  if( sx < dx ) {
    /* DA IMPLEMENTARE: scelta del pivot. Scegliere una posizione a caso tra sx e dx inclusi. */
    pivot = sx + rand()%(dx - sx +1);
    perno = distribuzione(a, sx, pivot, dx); /* separa gli elementi minori di a[pivot]
					        da quelli maggiori o uguali */
    /* Ordina ricorsivamente le due metà */
    quicksort(a, sx, perno-1);
    quicksort(a, perno+1, dx);}
}

char** legge(int *len) {
  int i;
  scanf("%d", len);
  char **a = malloc(*len * sizeof(char*));
  for( i = 0; i < *len; i++ ){
    *(a+i)=malloc(MAX_LEN*sizeof(char));
	  scanf("%s", *(a+i));}
  return a;

}

int main() {
  int i, n;
  char **A=legge(&n);
  srand(time(NULL));
  quicksort(A, 0, n-1);
  /* Stampa l'array ordinato */
  for( i = 0; i < n; i++ ){
    printf("%s\n", *(A+i));}
  return 0;
}
