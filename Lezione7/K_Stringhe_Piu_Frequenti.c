#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLEN 101

struct str_occ{   // struct con stringa e occorenze
  char *s;
  int occ;};
typedef struct str_occ str_occ;

// compare per stringhe
int strCompare (const void* a,const void* b){
  char *st1 = *(char**)a;
  char *st2 = *(char**)b;
  return strcmp(st1,st2);
}

// compare per struct rispetto alle occorenze
int occCompare (const void* a, const void* b){
  str_occ s1 = *(str_occ*)a;
  str_occ s2 = *(str_occ*)b;
  return -(s1.occ - s2.occ);
}

// compare per struct rispetto alla stringa
int nameCompare (const void* a, const void* b){
  str_occ s1 = *(str_occ*)a;
  str_occ s2 = *(str_occ*)b;
  return strcmp(s1.s,s2.s);
}

str_occ* contaOcc (char** arr,int n,int *unique){  // lavora su array ordinato
  int i=1, count, j=0;
  str_occ *stringhe_occorrenze = malloc(n*sizeof(str_occ));
  while (i<n){
    count=1;
    while (i<n && !(strcmp(arr[i],arr[i-1]))){
      count++;
      i++;
    }
    str_occ coppia;
    coppia.s= arr[i-1];
    coppia.occ= count;
    stringhe_occorrenze[j]=coppia;
    j++;
    i++;
  }
    *unique= j;   // ritorno la lunghezza effettiva dell'array di struct
    return stringhe_occorrenze;

}

void main(){
  int n, k, i, unique;
  scanf("%d%d",&n,&k);
  str_occ* coppie;
  char** stringhe= malloc(n*sizeof(char*));
  for (i=0;i<n;i++){
    char* str= malloc(MAXLEN*sizeof(char));
    scanf("%s",str);
    stringhe[i]=str;
  }
  qsort(stringhe,n,sizeof(char*),strCompare); // ordino l'array di stringhe da passare alla funzione
  coppie=contaOcc(stringhe,n,&unique);
  qsort(coppie,unique,sizeof(str_occ),occCompare); //ordino per occorrenze decrescenti
  qsort(coppie,k,sizeof(str_occ),nameCompare);  // prendo le prime k e le ordino lessicograficamente
  for (i=0;i<k;i++){
    printf("%s\n",coppie[i].s);
  }
}
