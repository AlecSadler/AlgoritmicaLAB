// Dato un grafo e due vertici, il programma verifica se la coppia in input fa parte della
// stessa componente connessa

#include <stdio.h>
#include <stdlib.h>

struct grafo{
  int grado;
  int *adj;};

struct queue{
  int capacity;
  int head;
  int tail;
  int *valori;};

typedef struct grafo grafo;
typedef struct queue queue;

void init (queue *q,int n){
  q->capacity=n;
  q->head=0;
  q->tail=0;
  q->valori=malloc(q->capacity*sizeof(int));
}

void enqueue (queue *q,int k){
  q->valori[q->tail++]=k;
}

int dequeue (queue *q){
  return q->valori[q->head++];
}

void deinit(queue *q){
  free(q->valori);
  q->capacity=0;
  q->head=0;
  q->tail=0;
}

int isEmpty (queue *q){
  if (q->head==q->tail)
    return 1;
  else
    return 0;
}

grafo* readGraph (int n){
  int i,deg,j;
  grafo* g=malloc(n*sizeof(grafo));
  for (i=0;i<n;i++){
    scanf("%d",&deg);
    g[i].grado=deg;
    g[i].adj=malloc(g[i].grado*sizeof(int));
    for (j=0;j<deg;j++){
      scanf("%d",g[i].adj+j);}}
  return g;
}

void bfs (grafo* g,int start,int n,int colore,int *colori){
  int i,u,v;
  queue q;
  init (&q,n);
  enqueue(&q,start);
  while (!isEmpty(&q)){
    u=dequeue(&q);
    for (i=0;i<g[u].grado;i++){
      v=g[u].adj[i];
      if (colori[v] == 0){
        colori[v]=colore;
        enqueue(&q,v);}}}
  deinit(&q);
}

// l'idea è di far partire una bfs da un nodo,poi verificare i nodi rimasti "bianchi"
// e da questi lanciare un'altra bfs ma colorando di un diverso colore creando dei "quartieri"
// presi i nodi in input basta verificare se appartengono allo stesso "quartiere".
void main(){
  int i,n,a,b;
  int colore=1, end=0;
  int *colori=malloc(n*sizeof(int));
  scanf("%d",&n);
  grafo *g=readGraph(n);
  for (i=0;i<n;i++){
    colori[i]=0;}
  for (i=0;i<n;i++){
    if (colori[i]==0){
      bfs(g,i,n,colore,colori);
      colore++;}}
  // il loop si interompe dando uno dei due nodi negativo.
  while (!end){
    scanf("%d%d",&a,&b);
    if (a==-1 || b==-1)
      end++;
    else{
      if (colori[a]==colori[b])
        printf("Connessi\n");
      else
        printf("Non Connessi\n");}}
}
