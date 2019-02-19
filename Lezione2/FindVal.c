#include <stdio.h>
#define ARR_LEN 10

int* FindVal (int a[],int len, int val){
  int i=0;
  int found=0;
  int *p;
  while (i<len && !found){
    if (a[i]==val){
      p=&i;
      found=1;}
    else
      i++;}
  if (!found)
    p=NULL;
  return p;
}

int main(){
  int v[ARR_LEN];
  int i;
  int val;
  for (i=0;i<ARR_LEN;i++){
    scanf("%d",&v[i]);}
  scanf("%d",&val);
  if (FindVal(v,ARR_LEN,val)!=NULL){
    printf("trovato\n");}
  else
    printf("non trovato\n");
  return 0;
}
