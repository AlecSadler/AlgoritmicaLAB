#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRLEN 101

void insertion_sort (char **a,int dim){
  int j,i;
  char* tmp=malloc(MAX_STRLEN*sizeof(char));
  for (i=1;i<dim;i++){
    tmp=*(a+i);
    j=i-1;
    while (j>=0 && strcmp(*(a+j),tmp)>0){
      *(a+j+1)=*(a+j);
      j--;}
    *(a+j+1)=tmp;}
}

int main(){
  int size,i;
  scanf("%d",&size);
  char **str=malloc(size*sizeof(char*));
  for (i=0;i<size;i++){
    str[i]=malloc(MAX_STRLEN*sizeof(char));
    scanf("%s",str[i]);}
  insertion_sort(str,size);
  for (i=0;i<size;i++){
      printf("%s\n",*(str+i));}
  for (i=0;i<size;i++){
      free(*(str+i));}
  free(str);
  return 0;
}
