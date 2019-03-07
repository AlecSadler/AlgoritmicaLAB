#include <stdio.h>
#include <stdlib.h>

int* union_ord (int a[],int dim_a,int b[],int dim_b){
  int *u=malloc((dim_a+dim_b)*sizeof(int));
  int i=0;
  int j=0;
  int k=0;
  while (i<dim_a && j<dim_b){
    if (a[i]>b[j]){
      *(u+k)=b[j];
      j++;
      k++;}
    else{
      *(u+k)=a[i];
      i++;
      k++;}}
    if (i<dim_a){
      while (i<dim_a){
        *(u+k)=a[i];
        i++;
        k++;}}
    else if (j<dim_b){
        while (j<dim_b){
          *(u+k)=b[j];
          j++;
          k++;}}
  return u;
}

int main(){
  int dim_a, dim_b;
  int i;
  int *unione;
  scanf("%d",&dim_a);
  int a[dim_a];
  for (i=0;i<dim_a;i++){
    scanf("%d",&a[i]);}
  scanf("%d",&dim_b);
  int b[dim_b];
  for (i=0;i<dim_b;i++){
    scanf("%d",&b[i]);}
  unione=union_ord(a,dim_a,b,dim_b);
  for (i=0;i < dim_a+dim_b;i++){
    printf("%d\n",*(unione+i));}
  return 0;
}
