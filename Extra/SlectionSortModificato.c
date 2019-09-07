// Algoritmo Selection Sort modificato in modo che oltre a trovare il minimo del sottoarray
// trova anche il massimo mettendolo alla fine

#include <stdio.h>

void swap (int *a,int *b){
  int tmp=*a;
  *a=*b;
  *b=tmp;
}

void selectSortEDIT (int a[],int dim){
  int i,j,k,min,max;
  i=0;
  j=dim-1;
  while (i<j){
    max=i;
    min=i;
    for (k=i+1;k<=j;k++){
      if (a[k]<a[min])
        min=k;}
    swap(&a[min],&a[i]);
    for (k=i+1;k<=j;k++){
      if (a[k]>a[max])
        max=k;}
    swap(&a[max],&a[j]);
    i++;
    j--;}
}

void main(){
  int a[5]= {32,41,16,64,11};
  int i;
  for (i=0;i<5;i++){
    printf("%d ",a[i]);}
  printf("\n");
  selectSortEDIT(a,5);
  for (i=0;i<5;i++){
    printf("%d ",a[i]);}
  printf("\n");
}
