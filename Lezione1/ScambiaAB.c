#include <stdio.h>

void swap (int *a,int *b){
  int tmp;
  tmp=*a;
  *a=*b;
  *b=tmp;
}

int main(){
  int x,y;
  scanf("%d%d",&x,&y);
  swap(&x,&y);
  printf("%d\n%d\n",x,y);
}
