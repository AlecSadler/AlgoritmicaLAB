#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int compare_strange(const void*a,const void *b){
  int v1= *((int*)a);
  int v2= *((int*)b);
  int mod1= abs(v1%2);
  int mod2= abs(v2%2);
  if (mod1!=mod2)
    return mod1-mod2;
  else if (mod1==0)
    return v1-v2;
  else
    return v2-v1;
}

void readArr(int **a,int len){
  int i;
  *a=malloc(len*sizeof(int));
  for(i=0;i<len;i++){
    scanf("%d",*(a)+i);}
}

int main(){
  int len,i;
  int *a;
  scanf("%d",&len);
  readArr(&a,len);
  qsort(a,len,sizeof(int),compare_strange);
  for(i=0;i<len;i++){
    printf("%d\n",*(a+i));}
  return 0;
}
