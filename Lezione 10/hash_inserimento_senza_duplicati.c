// le parti commentate servono a stampare la tavola come nel'esempio sulla piattaforma

#include <stdio.h>
#include <stdlib.h>

#define P 999149

struct node{
  int key;
  struct node *next;};

// serve per restiruire il numero dei conflitti,la lunghezza massima del chaining e il numero di elementi
struct info_tab{
  int conflitti;
  int maxLength;
  int distinti;};

typedef struct node node;
typedef struct info_tab infotab;

void push_tail (node **head,int el){
  node *new=malloc(sizeof(node));
  new->key=el;
  new->next=NULL;
  if (*head==NULL){
    *head=new;}
  else{
    node *cur=*head;
    while (cur->next!=NULL){
      cur=cur->next;}
    cur->next=new;}
}

int member(node *head,int el){
  if (head!=NULL){
    if (head->key==el)
      return 1;
    else
      return member(head->next,el);}
  else return 0;
}

// calcola la funzione hash e inserisce il valore nella posizione giusta
void hash_insert (node **tab,int a,int b,int x,int n){
  int hx = (int)(((a*x) + b) % P) % (2*n);
  if (!member(tab[hx],x)){
    push_tail(&tab[hx],x);}
  else return;
}

/*
void printList (node *head){
  if (head != NULL){
    node *cur=head;
    while (cur != NULL){
      printf("%d ",cur->key);
      cur=cur->next;}
    printf("\n");}
  else
    printf("NULL\n");
} */

// conta i nodi di una lista
int countNodes (node *head){
  if (head!=NULL){
    return 1 + countNodes(head->next);}
  else return 0;
}

// calcola numero conflitti,lunghezza massima del chaining e il numero di elementi
infotab tab_info (node **tab,int n){
  int i;
  infotab hsh;
  int max=0;
  int conf=0;
  int key_num=0;
  for (i=0;i < 2*n;i++){
    int tmp=countNodes(tab[i]);
    if (tmp > 1)
      conf=conf+tmp-1;
    if (tmp>max)
      max=tmp;
    if (tab[i]!=NULL)
      key_num=key_num+tmp;}
  hsh.conflitti=conf;
  hsh.maxLength=max;
  hsh.distinti=key_num;
  return hsh;
}

/*  stampa l'intera tavola
void print_tab (node **tab,int n){
  int i;
  for (i=0;i< 2*n;i++){
    printf("%d -> ",i);
    printList(tab[i]);}
}*/

int main(){
  int n,i,el,a,b;
  scanf("%d%d%d",&n,&a,&b);
  node** tab=malloc(2*n*sizeof(node));
  for (i=0;i< 2*n;i++){
    tab[i]=NULL;}
  for (i=0;i<n;i++){
    scanf("%d",&el);
    hash_insert(tab,a,b,el,n);}
  //print_tab(tab,n);
  printf("%d\n%d\n%d\n",tab_info(tab,n).conflitti,tab_info(tab,n).maxLength,tab_info(tab,n).distinti);
  return 0;
}
