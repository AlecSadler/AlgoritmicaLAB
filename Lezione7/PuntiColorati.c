#include <stdio.h>
#include <stdlib.h>

struct point{
  int x;
  int y;
  int c;};
typedef struct point point;

int colCompare (const void* a,const void* b){
  point p1= *(point*)a;
  point p2= *(point*)b;
  return p1.c - p2.c;
}

int query(point*arr,int n,point inq1,point inq2){
  int i, last=-1, count=0;
  for (i=0;i<n;i++){
    if (arr[i].x >= inq1.x && arr[i].y >= inq1.y && arr[i].x <= inq2.x && arr[i].y <= inq2.y){
      if (arr[i].c != last){
        count++;
        last= arr[i].c;
      }
    }
  }
  return count;
}

void main(){
  int i, n, m, asc, ord, col, qx1, qy1, qx2, qy2;
  scanf("%d%d",&n,&m);
  point* points= malloc(n*sizeof(int));
  for (i=0;i<n;i++){
    scanf("%d%d%d",&asc,&ord,&col);
    points[i].x=asc;
    points[i].y=ord;
    points[i].c=col;
  }
  qsort(points,n,sizeof(point),colCompare);
  for (i=0;i<m;i++){
    scanf("%d%d%d%d",&qx1,&qy1,&qx2,&qy2);
    point p1,p2;
    p1.x=qx1;
    p1.y=qy1;
    p1.c=-1;
    p2.x=qx2;
    p2.y=qy2;
    p1.c=-1;
    printf("%d\n",query(points,n,p1,p2));
  }
}
