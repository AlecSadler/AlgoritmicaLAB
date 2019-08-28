#include <stdlib.h>
#include <stdio.h>

void swap (int *a,int *b){
  int tmp= *a;
  *a=*b;
  *b=tmp;
}

void partition3 (int a[],int sx,int dx,int *i,int *j){
  int s=sx;
  int pivot= a[dx]; // prendo l'ultimo elemento per pivot
  while (s<=dx){
    if (a[s]<pivot){
      swap(&a[s++],&a[sx++]);}
    else if (a[s]==pivot)
      s++;
    else if (a[s]>pivot){
      swap(&a[s],&a[dx--]);}}
  *i=sx-1;
  *j=s;
}

// tra i e j si trovano gli elementi uguali al pivot
void quicksort3 (int a[],int sx,int dx){
  if (sx>=dx)
    return;
  else{
    int i,j;
    partition3(a,sx,dx,&i,&j);
    quicksort3(a,sx,i);
    quicksort3(a,j,dx);}
}

int main(){
  int n,i;
  scanf("%d",&n);
  int *a=malloc(n*sizeof(int));
  for (i=0;i<n;i++){
    scanf("%d",&a[i]);}
  quicksort3(a,0,n-1);
  for (i=0;i<n;i++){
    printf("%d ",a[i]);}
  printf("\n");
  return 0;
}
