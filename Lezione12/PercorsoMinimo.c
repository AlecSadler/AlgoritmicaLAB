#include <stdio.h>
#include <stdlib.h>

struct edges {
  int grado;
  int *adiacenti;};

struct queue {
  int capacity;
  int head;
  int tail;
  int *valori;};

typedef struct edges edges;
typedef struct queue queue;

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

// inizializza la coda
void init(queue *q, int n){
    q->capacity=n;
    q->head=0;
    q->tail=0;
    q->valori=malloc(sizeof(int)*q->capacity);
}

void accoda(queue* q, int k){
    q->valori[q->tail++]=k;
}

int decoda(queue* q){
    return q->valori[q->head++];
}

void deinit(queue* q){
    free(q->valori);
    q->capacity=0;
    q->head=0;
    q->tail=0;
}

// controlla se una coda è vuota
int codavuota(queue* q){
    if(q->head==q->tail)
        return 1;
    else
        return 0;
}

int bfs (edges *E,int start,int end,int n){
  int *colori=malloc(n*sizeof(int));
  int *distance=malloc(n*sizeof(int));
  int i,u,v;
  queue q;
  for (i=0;i<n;i++){
    colori[i]=0;
    distance[i]=-1;}
  init(&q,n);
  accoda(&q,start);
  colori[start]=1;
  distance[start]=0;
  while (!codavuota(&q)){
    u=decoda(&q);
    for (i=0;i<E[u].grado;i++){
      v=E[u].adiacenti[i];
      if (colori[v]==0){
        distance[v]=distance[u]+1;
        if (v==end)
          return distance[v];
        colori[v]=1;
        accoda(&q,v);}}};
  deinit(&q);
  return distance[end];
}

int main(){
  int n,query,i,start,end;
  scanf("%d",&n);
  edges *E=readGraph(n);
  scanf("%d",&query);
  for (i=0;i<query;i++){
    scanf("%d %d",&start,&end);
    printf("%d\n",bfs(E,start,end,n));}
  return 0;
}
