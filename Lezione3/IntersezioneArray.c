#include <stdio.h>
#include <stdlib.h>

#define MAX_LEN 100000

int main(){
  int arr_a[MAX_LEN];
  int arr_b[MAX_LEN];
  int arr_inters[MAX_LEN];
  int dim_a, dim_b;
  int *a=malloc(dim_a*sizeof(int));
  int *b=malloc(dim_b*sizeof(int));
  int n, i,j;
  int k=0;
  a=arr_a;
  b=arr_b;
  scanf("%d",&dim_a);
  for (i=0;i<dim_a;i++){
    scanf("%d",&n);
    *(a+i)=n;}
  scanf("%d",&dim_b);
  for (i=0;i<dim_b;i++){
    scanf("%d",&n);
    *(b+i)=n;}
  for (i=0;i<dim_a;i++){
    for (j=0;j<dim_b;j++){
      if (arr_a[i]==arr_b[j]){
        arr_inters[k]=a[i];
        k++;}}}
  printf("%d",k);
  return 0;
}
