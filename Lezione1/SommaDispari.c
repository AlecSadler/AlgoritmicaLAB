#include <stdio.h>

int sumDisp (int n){
  if (n==1)
    return 1;
  else
      return n*2-1 + sumDisp(n-1);
}

int main(){
  int n;
  scanf("%d",&n);
  printf("%d\n",sumDisp(n));
  return 0;
}
