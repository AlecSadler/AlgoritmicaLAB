#include <stdio.h>

#define MAX_LEN 1000

int main(){
  char str[MAX_LEN];
  char *s=str;
  int k;
  scanf("%s",str);
  scanf("%d",&k);
  while (k>0){
    printf("%s",s);
    k--;}
  return 0;
}
