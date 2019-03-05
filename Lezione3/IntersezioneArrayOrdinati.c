#include <stdio.h>
#include <stdlib.h>

int inters_ord(int a[],int len_a,int b[],int len_b){
  int i=0;
  int j=0;
  int count=0;
  while (i<len_a && j<len_b){
    if (a[i] < b[j])
      i++;
    else if (a[i]>b[j])
      j++;
    else{
      i++;
      j++;
      count++;}}
  return count;
}

int main(){
  int i;
  int dim_a;
  scanf("%d",&dim_a);
  int a[dim_a];
  for (i=0;i<dim_a;i++){
    scanf("%d",&a[i]);}
  int dim_b;
  scanf("%d",&dim_b);
  int b[dim_b];
  for (i=0;i<dim_b;i++){
    scanf("%d",&b[i]);}
  printf("%d\n",inters_ord(a,dim_a,b,dim_b));
  return 0;
}
