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

int bfs (grafo* g,int start,int end,int n){
  int *colori=malloc(n*sizeof(int));
  int *distanza=malloc(n*sizeof(int));
  int i,u,v;
  queue q;

  for (i=0;i<n;i++){
    colori[i]=0;
    distanza[i]=-1;
  }
  init(&q,n);
  accoda(&q,start);
  colori[start]=1;
  distanza[start]=0;
  // estraggo dalla coda
  while (!codavuota(&q)) {  // finche ho elementi in coda
    u=decoda(&q);
    for (i=0;i<g[u].grado;i++){ //esamino la lista id adiacenza del nodo
      v= g[u].adj[i];
      if (colori[v]==0){
        colori[v]=1;
        distanza[v]=distanza[u]+1;
        if (v==end) return distanza[v]; // se è il nodo finale posso terminare
        accoda(&q,v);                   // metto il nodo in coda
      }
    }
  }
  deinit(&q);
  return distanza[end];
}

void main(){
  int n, i, start, end, nQuerys;
  scanf("%d",&n);
  grafo *graph= readGraph(n);
  scanf("%d",&nQuerys);
  for(i=0;i<nQuerys;i++){
    scanf("%d%d",&start,&end);
    printf("%d\n",bfs(graph,start,end,n));
  }
}
