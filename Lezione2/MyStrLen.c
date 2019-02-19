#include <stdio.h>
#define MAX_LEN 1000

int myStrlen (char *s){
  int count=0;
  while (*(s+count) != 0 && count < MAX_LEN){
    count++;}
  return count;
}

int main(){
  char str[MAX_LEN];
  scanf("%s",str);
  char *s = str;
  printf("%d\n",myStrlen(s));
  return 0;
}
