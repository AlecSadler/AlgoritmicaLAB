//TESTO: acquisire un numero N di matricole e riempire una tabella Hash di dimensione 2N
//seconso la funzione h=(matricola*941)% 2N,successivamente si acquisiscono sue sequenze di
//matricole rispettivamente di lunghezza m1 e m2 che corrispondono ai bocciati di prima prova e
//seconda prova. Eliminare dalla tabella hash le matricole presenti in sia in m1 che in m2 e
//stampare il numero di studenti che possono sostenere la prova finale (che sono stati bocciati max 1 volta).

#include <stdio.h>
#include <stdlib.h>

#define HASH_CONS 941

struct node{
  char mat;
  int fail;
  struct node *next;};

typedef struct node node;

void push_head (node **head,int mat){
  node *new=malloc(sizeof(node));
  new->mat=mat;
  new->fail=0;
  if (*head==NULL){
    *head=new;
    (*head)->next=NULL;}
  else{
    new->next=*head;
    *head=new;}
}

void hash_insert (node **tab,int n,int mat){
  int i;
  int hx = (mat*HASH_CONS)%(2*n);
  push_head(&tab[hx],mat);
}

void hash_aggiorna (node **tab,int n,int mat,int *conta){
  int hx = (mat*HASH_CONS)%(2*n);
  node *cur=tab[hx];
  node *prev=NULL;
  while (cur!=NULL){
    if (cur->mat==mat){
      cur->fail++;
      if (cur->fail==2){
        *conta=*conta-1;
        if (prev==NULL){
          node *tmp=cur;
          tab[hx]=tab[hx]->next;
          cur=tab[hx];
          free(tmp);
          return;}
        else{
          node *tmp=cur;
          prev->next=cur->next;
          free(tmp);
          return;}}
      return;}
    else{
        prev=cur;
        cur=cur->next;}}
}


int main(){
  int n,i,m1,m2,mat,conta;
  scanf("%d",&n);
  conta=n;
  node **tab=malloc(2*n*sizeof(node));
  for (i=0;i<2*n;i++){
    tab[i]=NULL;}
  for (i=0;i<n;i++){
    scanf("%d",&mat);
    hash_insert(tab,n,mat);}
  scanf("%d",&m1);
  for (i=0;i<m1;i++){
    scanf("%d",&mat);
    hash_aggiorna(tab,n,mat,&conta);}
  scanf("%d",&m2);
  for (i=0;i<m2;i++){
    scanf("%d",&mat);
    hash_aggiorna(tab,n,mat,&conta);}
  printf("%d\n",conta);
  return 0;
}
