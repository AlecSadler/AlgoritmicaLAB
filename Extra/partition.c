#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *a,int *b){
  int tmp= *a;
  *a=*b;
  *b=tmp;
}

void partition(int a[],int sx,int px,int dx){
  int i=sx-1;
  int j;
  swap(&a[px],&a[dx]);
  for (j=sx;j<dx;j++){
    if (a[j]<=a[dx]){
      i++;
      swap(&a[j],&a[i]);}}
  i++;
  swap(&a[i],&a[dx]);
}

void readArr(int **a,int size){
  int i;
  *a=malloc(size*sizeof(int));
  for (i=0;i<size;i++){
    scanf("%d",*(a)+i);}
}

void main(){
  int *a;
  int size,i;
  scanf("%d",&size);
  int pivot=3;
  readArr(&a,size);
  printf("Array iniziale: ");
  for (i=0;i<size;i++){
    printf("%d - ",*(a+i));}
  printf("\n");
  partition(a,0,pivot,size-1);
  printf("Array partizionato: ");
  for (i=0;i<size;i++){
    printf("%d - ",*(a+i));}
  printf("\n");
}
