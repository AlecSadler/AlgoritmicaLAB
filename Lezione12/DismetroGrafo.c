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

int bfs (edges *E,int start,int n){
  int *colori=malloc(n*sizeof(int));
  int *distance=malloc(n*sizeof(int));
  int i,u,v,max_d=0;
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
        colori[v]=1;
        accoda(&q,v);}}};
  deinit(&q);
  for (i=0;i<n;i++){
    if (!colori[i])
      return -1;
    if (distance[i]> max_d)
      max_d=distance[i];}
  return max_d;
}

// lancio la bfs da ogni nodo per vedere qual è il cammino minimo piu lungo
int diametro(edges *E,int n){
  int i,diametro=-1;
  for (i=0;i<n;i++){
    int tmp=bfs(E,i,n);
    if (tmp == -1)
      return -1;
    if (tmp > diametro)
      diametro=tmp;}
  return diametro;
}

int main(){
  int n,i,start,max;
  scanf("%d",&n);
  edges *E=readGraph(n);
  printf("%d\n",diametro(E,n));
  return 0;
}
