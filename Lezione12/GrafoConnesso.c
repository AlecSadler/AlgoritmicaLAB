#include <stdio.h>
#include <stdlib.h>

struct edges {
  int grado;
  int *adiacenti;};

typedef struct edges edges;

//costruzione grafo
edges* readGraph (int n){
  int i,g,j;
  edges* E=malloc(n*sizeof(edges));
  for (i=0;i<n;i++){
    scanf("%d",&g);
    E[i].grado=g;
    E[i].adiacenti=malloc(E[i].grado*sizeof(int));
    for (j=0;j<g;j++){
      scanf("%d",E[i].adiacenti+j);}}
  return E;
}

void dfs (edges *E,int src,int** colore){
  int i,cur;
  for (i=0;i<E[src].grado;i++){
    cur=E[src].adiacenti[i];
    if ((*colore)[cur]==0){
      (*colore)[cur]=1;
      dfs(E,cur,&(*colore));}}
}

int connesso (edges *E,int n){
  int i,src;
  int *colore=malloc(n*sizeof(int));
  for (i=0;i<n;i++){
    colore[i]=0;}
  src=0;
  dfs(E,src,&colore);
  i=0;
  while (i<n){
    if (colore[i]==0)
      return 0;
    else
      i++;}
  return 1;
}

int main(){
  edges* E;
  int n,i;
  scanf("%d",&n);
  E=readGraph(n);
  printf("%d\n",connesso(E,n));
  return 0;
}
