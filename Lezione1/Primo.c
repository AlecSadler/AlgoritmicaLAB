#include <stdio.h>

int main(){
  int n;
  int i=2;
  int ok=1;
  scanf("%d",&n);
  while (i<n && ok){
    if (n%i==0)
      ok=0;
    else
      i++;}
  printf("%d\n",ok);
  return 0;
}
