#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRLEN 101

int binary_search (char **a,int start,int end,char *s){
  if (start>end)
    return -1;
  else{
      if (strcmp(s,a[(start+end)/2]) == 0 )
        return (start+end)/2;
      else if (strcmp(s,a[(start+end)/2]) < 0 )
        return binary_search(a,start,((start+end)/2)-1,s);
      else
        return binary_search(a,((start+end)/2)+1,end,s);}
}

int main(){
  int size,i;
  int repeat=1;
  scanf("%d",&size);
  char **str=malloc(size*sizeof(char*));
  for (i=0;i<size;i++){
    str[i]=malloc(MAX_STRLEN*sizeof(char));
    scanf("%s",str[i]);}
  while (repeat==1){
    scanf("%d",&repeat);
    if (repeat == 1){
      char *key=malloc(MAX_STRLEN*sizeof(char));
      scanf("%s",key);
      printf("%d\n",binary_search(str,0,size-1,key));}}
  return 0;
}
