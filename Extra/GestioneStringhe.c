/* in c per gestire le stringhe utilizziamo un puntatore che punta all'inizio di un array di caratteri
per muoverci lungo la stringa utilizziamo un indice sommato al puntatore. Quando l'indice è 0 abbiamo
*(p+0) che sta a indicare il primo elemento,incrementando la i ci spostiamo lungo la stringa */

#include <stdio.h>
#include <stdlib.h>
#define MAX_STRLEN 1000

// stampa una stringa inserita

void printStr (char *s){
  int i=0;
  while (*(s+i) != 0 && i<MAX_STRLEN){
    printf("%c",*(s+i));
    i++;}
  printf("\n");
}

// calcola la lunghezza di una stringa

int strLen (char *s){
  int len=0;
  while (*(s+len) != 0 && len < MAX_STRLEN){
    len++;}
  return len;
}

void main(){
  char str[MAX_STRLEN];
  printf("Inserire stringa: \n");
  scanf ("%s",str);
  char *pointer = str;
  printStr(pointer);
  printf ("caratteri stringa: %d\n",strLen(pointer));
  }
