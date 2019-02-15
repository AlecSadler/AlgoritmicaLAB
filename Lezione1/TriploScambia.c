#include <stdio.h>
#define ARR_LEN 3

// x=z y=x z=y

void tSwap (int *x, int *y, int *z){
  int tmp1;
  tmp1=*x;
  *x=*z;
  *z=*y;
  *y=tmp1;
  }

int main(){
  int a[ARR_LEN];
  int i;
  for (i=0;i<ARR_LEN;i++){
    scanf("%d",&a[i]);}
  tSwap(&a[0],&a[1],&a[2]);
  for(i=0;i<ARR_LEN;i++){
    printf("%d\n",a[i]);}
  return 0;
}
