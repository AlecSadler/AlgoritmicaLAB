#include <stdio.h>
#define ARR_LEN 10

void MinMax (int a[],int dim,int *mn, int *mx){
  int i;
  *mx=0;
  for (i=1;i<dim;i++){
    if (a[i] > a[*mx])
      *mx=i;}
  *mn=0;
  for (i=1;i<dim;i++){
    if (a[i] < a[*mn])
      *mn=i;}
}

int main(){
  int a[ARR_LEN];
  int i, min, max;
  for (i=0;i<ARR_LEN;i++){
    scanf("%d",&a[i]);}
  MinMax(a,ARR_LEN,&min,&max);
  printf("%d\n%d\n%d\n%d\n",min,a[min],max,a[max]);
  return 0;
}
