#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRLEN 100

struct string_el{
  char* str;
  int len;};

typedef struct string_el string_el;

int compare(const void *a,const void *b){
  string_el aa= *(string_el*)a;
  string_el bb= *(string_el*)b;
  if (aa.len != bb.len){
    return aa.len-bb.len;}
  else{
    return strcmp(aa.str,bb.str);}
}

int main(){
  int i,len;
  scanf("%d",&len);
  string_el *strings=malloc(len*sizeof(string_el));
  for (i=0;i<len;i++){
    char *st= malloc(MAX_STRLEN*sizeof(char));
    scanf("%s",st);
    (strings[i]).str=st;
    (strings[i]).len=strlen(st);}
  qsort(strings,len,sizeof(string_el),compare);
  for (i=0;i<len;i++){
    printf("%s\n",strings[i]);}
  return 0;
}
