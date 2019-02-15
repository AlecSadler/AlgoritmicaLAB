#include <stdio.h>
#define MAX_LEN 10000

int main(){
  int i, n, dim, tmp;
  int a[MAX_LEN];
    scanf("%d",&dim);
    if (dim<=10000){
      i=0;
      while (i<dim){
        scanf("%d",&n);
        a[i]=n;
        i++;}}
    for (i=0;i<dim/2;i++){
      tmp=a[i];
      a[i]=a[dim-i-1];
      a[dim-i-1]=tmp;}
    for (i=0;i<dim;i++){
      printf("%d\n",a[i]);}
  return 0;
}
