// Es 9.9 Bertossi-Montresor - stampare numero nodi a distanza max da src

#include <stdio.h>
#include <stdlib.h>

struct grafo{
  int grado;  //grado nodo
  int *adj;}; // nodi raggiungibili
typedef struct grafo grafo;

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
    E[i].grado=g;
    E[i].adj=malloc(E[i].grado*sizeof(int));
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

int maxDistanceVertex(grafo *g,int src,int n){
  int i, u, v, max, count=0;
  queue q;
  int *colore=malloc(n*sizeof(int));
  int *distanza=malloc(n*sizeof(int));
  for (i=0;i<n;i++){
    colore[i]=0;
  }
  init(&q,n);
  accoda(&q,src);
  colore[src]=1;
  distanza[src]=0;
  max=distanza[src];
  while (!codavuota(&q)) {
    u=decoda(&q);
    for (i=0;i<g[u].grado;i++){
      v=g[u].adj[i];;
      if (colore[v]==0){
        colore[v]=1;
        distanza[v]=distanza[u]+1;
        max=distanza[v];
        accoda(&q,v);
      }
    }
  }
  for (i=0;i<n;i++){
    if (distanza[i]==max) count++;;
  }
  deinit(&q);
  return count;
}

void main(){
  int n;
  scanf("%d",&n);
  grafo *graph= readGraph(n);
  printf("I nodi a distanza massima dalla sorgente sono: %d\n",maxDistanceVertex(graph,0,n));
}
