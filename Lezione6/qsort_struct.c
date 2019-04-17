#include <stdio.h>
#include <stdlib.h>

struct point{
  int x;
  int y;};

typedef struct point point;

int struct_compare(const void *a,const void *b){
  point pa= *(point*)a;
  point pb= *(point*)b;
  if (pa.x != pb.x){
    return pa.x-pb.x;}
  else{
    return -(pa.y-pb.y);}
}

int main(){
  point *points;
  int i,n;
  scanf("%d",&n);
  points=malloc(n*sizeof(point));
  for (i=0;i<n;i++){
    scanf("%d%d",&points[i].x,&points[i].y);}
  qsort(points,n,sizeof(point),struct_compare);
  for (i=0;i<n;i++){
    printf("%d %d\n",points[i].x,points[i].y);}
  return 0;
}
