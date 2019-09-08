#include <stdio.h>
#include <stdlib.h>

struct p{
  int x;
  int y;
  int c;};

typedef struct p punto;

int struct_compare (const void *a,const void *b){
  punto pa= *(punto*)a;
  punto pb= *(punto*)b;
  return pa.c-pb.c;
}

int main(){
  int m,n,i,j,x,y,c,x1,y1,x2,y2,last_col,count;
  scanf("%d%d",&n,&m);
  int *res=malloc(m*sizeof(int));  //uso un array per memorizzare i risultati delle interrogazioni
  punto* punti=malloc(n*sizeof(punto));
  for (i=0;i<n;i++){
    scanf("%d%d%d",&x,&y,&c);
    punti[i].x=x;
    punti[i].y=y;
    punti[i].c=c;}
  qsort(punti,n,sizeof(punto),struct_compare);
  for (i=0;i<m;i++){
    last_col=-1;
    count=0;
    scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
    for (j=0;j<n;j++){
      if (punti[j].x>=x1 && punti[j].y>=y1 && punti[j].x<=x2 && punti[j].y<=y2){
        if (punti[j].c != last_col){
          count++;
          last_col=punti[j].c;}}}
    res[i]=count;}
  for (i=0;i<m;i++){
    printf("%d\n",res[i]);}
  return 0;
}
