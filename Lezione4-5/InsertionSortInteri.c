#include <stdio.h>
#include <stdlib.h>

void insertion_sort (int *a,int dim){
  int i;
  int j;
  int tmp;
  for (i=1;i<dim;i++){
    tmp=*(a+i);
    j=i-1;
    while (*(a+j) > tmp && j>=0){
      *(a+j+1)=*(a+j);
      j--;}
    *(a+j+1)=tmp;
    }
}

int main(){
  int size;
  scanf("%d",&size);
  int *v;
  v=malloc(size*sizeof(int));
  int i,n;
  for (i=0;i<size;i++){
    scanf("%d",&n);
    *(v+i)=n;}
  insertion_sort(v,size);
  for (i=0;i<size;i++){
    printf("%d\n",*(v+i));}

}
