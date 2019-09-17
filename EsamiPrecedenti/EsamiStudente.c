#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLEN 101

struct esame{
  char* nome;
  int cfu;
  int diff;};

typedef struct esame esame;

int struct_compare (const void *a,const void *b){
  esame exa = *(esame*)a;
  esame exb = *(esame*)b;
  if (exa.cfu == exb.cfu){
    if (exa.diff == exb.diff)
      return strcmp(exa.nome,exb.nome);
    else
      return exa.diff - exb.diff;
  }
  return exb.cfu - exa.cfu;
}

int str_cmp (const void *a,const void *b){
  esame exa = *(esame*)a;
  esame exb = *(esame*)b;
  return strcmp(exa.nome,exb.nome);
}

int main(){
  int n, k, i, cfu, diff, cfutot=0, j=0;
  scanf ("%d%d",&k,&n);
  esame *arr=malloc(n*sizeof(esame));
  esame *arr2=malloc(n*sizeof(esame)); // array secondario suu cui metto gli esami da sostenere
  for (i=0;i<n;i++){
    char* ex=malloc(MAXLEN*sizeof(char));
    scanf("%s",ex);
    scanf("%d%d",&cfu,&diff);
    arr[i].cfu=cfu;
    arr[i].diff=diff;
    arr[i].nome=ex;
  }
  qsort(arr,n,sizeof(esame),struct_compare);
  for (i=0;i<n && cfutot!=k;i++){
    if ( (cfutot + arr[i].cfu) <= k){
      cfutot= cfutot + arr[i].cfu;
      arr2[j].nome=arr[i].nome;
      j++;
    }
  }
  qsort(arr2,j,sizeof(esame),str_cmp);
  for (i=0;i<j;i++){
    printf("%s\n",arr2[i].nome);
  }
  free(arr);
  free(arr2);
  return 0;
}
