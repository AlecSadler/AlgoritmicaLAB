#include <stdio.h>
#include <stdlib.h>

#define MAX_LEN 1000

int myStrlen (char *s){
  if (*s !=0)
    return 1 + myStrlen(s+1);
  else
    return 0;
}

char* my_strcopy (char *dst,char *src){
  int i;
  for (i=0;i<myStrlen(src);i++){
    *(dst+i)=*(src+i);}
  return dst;
}

int main(){
  char source[MAX_LEN];
  char *src= source;
  scanf("%s",source);
  char *dst=malloc(sizeof(char)*myStrlen(src));
  printf("%s\n",my_strcopy(dst,src));
  return 0;
}
