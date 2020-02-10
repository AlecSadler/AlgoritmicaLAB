#include <stdio.h>
#include <stdlib.h>

struct grafo{
  int degree;
  int *adj;};

typedef struct grafo grafo;

// costruzione del grafo

struct queue {
  int capacity;
  int head;
  int tail;
  int *valori;};
typedef struct queue queue;

//costruzione grafo
grafo* readGraph (int n){
  int i,g,j;
  grafo* E=malloc(n*sizeof(grafo));
  for (i=0;i<n;i++){
    scanf("%d",&g);
    E[i].degree=g;
    E[i].adj=malloc(E[i].degree*sizeof(int));
    for (j=0;j<g;j++){
      scanf("%d",E[i].adj+j);}}
  return E;
}

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

int codavuota(queue* q){
    if(q->head==q->tail)
        return 1;
    else
        return 0;
}

int Acyclic(grafo *g,int src,int n){
  int i, u, v;
  queue q;
  int *colore=malloc(n*sizeof(int));
  for (i=0;i<n;i++){
    colore[i]=0;
  }
  init(&q,n);
  accoda(&q,src);
  colore[src]=1;
  while (!codavuota(&q)) {
    u=decoda(&q);
    for (i=0;i<g[u].degree;i++){
      v=g[u].adj[i];;
      if (colore[v]==0){
        colore[v]=1;
        accoda(&q,v);
      }
      else return 0;
    }
  }
  deinit(&q);
  return 1;
}

void main(){
  int n;
  grafo *g;
  scanf("%d",&n);
  g=readGraph(n);
  printf("%d\n",Acyclic(g,0,n));
}
