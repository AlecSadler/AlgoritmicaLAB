#include <stdio.h>

int max_subsum(int a[],int len){
  int i=0;
  int sum=0;
  int max=0;
  while (i<len ){
    if (a[i]<0){
      sum=sum+a[i];
      if (sum<0)
        sum=0;}
    else{
      sum=sum+a[i];
      if (sum>max)
          max=sum;}
      i++;}
  return max;
}

int main(){
  int i;
  int dim;
  scanf("%d",&dim);
  int a[dim];
  for (i=0;i<dim;i++){
    scanf("%d",&a[i]);}
  printf("%d\n",max_subsum(a,dim));
  return 0;
}
