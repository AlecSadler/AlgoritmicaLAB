// controllare se un grafo contiene cicli

#include <stdio.h>
#include <stdlib.h>

struct grafo{
  int grado;  //grado nodo
  int *adj;}; // nodi raggiungibili
typedef struct grafo grafo;

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

/* sfrutto la regola che in un grafo aciclico la il numero degli archi
  deve essere MINORE del numero dei nodi -1 ( sommatoria gradi < (n-1) ) */
int isAcyclic (grafo *g,int n){
  int i, sum=0;
  for (i=0;i<n;i++){
    sum= sum + g[i].grado;
  }
  if (sum> (n-1)) return 0;    // 0 ciclico, 1 aciclico
  return 1;
}


void main(){
  int n;
  scanf("%d",&n);
  grafo *graph= readGraph(n);
  if (isAcyclic(graph,n)) printf("Aciclico\n");
  else printf("Ciclico\n");
}
