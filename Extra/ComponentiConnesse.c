// Dato un grafo,indicare il numero di componenti connesse

#include <stdio.h>
#include <stdlib.h>

struct vert{
  int degree;
  int *adj;};

typedef struct vert vertex;

// costruzione del grafo

vertex* readGraph (int n){
  int i,deg,j;
  vertex *g=malloc(n*sizeof(vertex));
  for (i=0;i<n;i++){
    scanf("%d",&deg);
    g[i].degree=deg;
    g[i].adj=malloc((g[i].degree)*sizeof(int));
    for (j=0;j<deg;j++){
      scanf("%d",g[i].adj+j);}}
  return g;
}

void dfs_visit (vertex *g,int src,int **colori){
  int i,cur;
  for (i=0;i<g[src].degree;i++){
    cur=g[src].adj[i];
    if ( (*colori)[cur] == 0){
      (*colori)[cur]=1;
      dfs_visit(g,cur,&(*colori));}}
}

int dfs_connesse (vertex *g,int n){
  int i;
  int *colori=malloc(n*sizeof(int));
  for (i=0;i<n;i++){
    colori[i]=0;}
  int count=0;
  for (i=0;i<n;i++){
    if (colori[i]==0){
      colori[i]=1;
      count++;
      dfs_visit(g,i,&colori);}}
  return count;
}

void main(){
  vertex *g;
  int n,i;
  scanf("%d",&n);
  g=readGraph(n);
  printf("%d\n",dfs_connesse(g,n));
}
