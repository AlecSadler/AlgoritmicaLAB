#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRLEN 100

int compare_string(const void*a,const void *b){
  char* st1=*(char**)a;
  char* st2=*(char**)b;
  return -strcmp(st1,st2);

}

int main(){
  int words,i;
  scanf("%d",&words);
  char **str=malloc(words*sizeof(char*));
  for(i=0;i<words;i++){
    *(str+i)=malloc(MAX_STRLEN*sizeof(char));
    scanf("%s",*(str+i));}
  qsort(str,words,sizeof(char*),compare_string);
  for(i=0;i<words;i++){
    printf("%s\n",*(str+i));}
  return 0;
}
