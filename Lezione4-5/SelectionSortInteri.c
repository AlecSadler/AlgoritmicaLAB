#include <stdio.h>
#include <stdlib.h>

void selection_sort (int *a,int dim){
  int i;
  int j;
  int tmp;
  for (i=0;i<dim-1;i++){
    for (j=i+1;j<dim;j++){
      if (*(a+j) < *(a+i)){
        tmp=*(a+i);
        *(a+i)=*(a+j);
        *(a+j)=tmp;}}}
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
  selection_sort(v,size);
  for (i=0;i<size;i++){
    printf("%d\n",*(v+i));}

}
