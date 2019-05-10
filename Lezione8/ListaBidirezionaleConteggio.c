#include <stdio.h>
#include <stdlib.h>

struct Node{
  int key;
  int visits;
  struct Node *prev;
  struct Node *next;};

typedef struct Node node;

void push_tail(node **head,int el){
  node *new= malloc(sizeof(node));
  new->key=el;
  new->visits=0;
  if (*head==NULL){
    new->next=NULL;
    new->prev=NULL;
    *head=new;}
  else{
    node *cur=*head;
    while (cur->next!=NULL){
      cur=cur->next;}
    new->prev=cur;
    new->next=NULL;
    cur->next=new;}
}

void swap (int *a,int *b){
  int tmp=*a;
  *a=*b;
  *b=tmp;
}

int search_count(node **head,int val){
  int found=0;
  int pos=0;
  node *aux;
  if (*head!=NULL){
    node *cur=*head;
    while (cur!=NULL && !found){
      if (cur->key==val){
        found++;
        cur->visits++;}
      else{
        pos++;
        cur=cur->next;}}
    if (!found)
      return -1;
    aux=cur;
    // anziche scambiare i nodi,faccio arretrare i valori scambiandoli
    while (aux->prev!=NULL && aux->visits > aux->prev->visits){
      swap(&aux->visits,&aux->prev->visits);
      swap(&aux->key,&aux->prev->key);
      aux=aux->prev;}}
  return pos;
}

void printList(node *head){
  while (head!=NULL){
    printf("%d\n",head->key);
    head=head->next;}
}

int main(void){
  node *list=NULL;
  node *positions=NULL;
  int len,el;
  int src_key,aux;
  int i;
  int stop=0;
  scanf("%d",&len);
  for (i=0;i<len;i++){
    scanf("%d",&el);
    push_tail(&list,el);}
  while (!stop){
    scanf("%d",&src_key);
    aux=search_count(&list,src_key);
    if (aux==-1){
      push_tail(&positions,aux);
      stop++;}
    else{
      push_tail(&positions,aux);}}
  printList(positions);
  return 0;
}
