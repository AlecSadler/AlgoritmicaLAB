#include <stdio.h>

int main(){
  int sum=0;
  int end=0;
  int n;
  while (end==0){
    scanf("%d",&n);
    if (n!=0)
      sum=sum+n;
    else
      end=1;}
  printf("%d\n",sum);
  return 0;
}
