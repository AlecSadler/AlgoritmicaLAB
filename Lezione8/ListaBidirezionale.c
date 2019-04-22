#include <stdio.h>
#include <stdlib.h>

struct bi_node{
  int key;
  struct bi_node *prev;
  struct bi_node *next;};

typedef struct bi_node bi_node;

void push_tail(bi_node **head,int el){
  bi_node *new= malloc(sizeof(bi_node));
  new->key=el;
  if (*head==NULL){
    new->next=NULL;
    new->prev=NULL;
    *head=new;}
  else{
    bi_node *cur=*head;
    while (cur->next!=NULL){
      cur=cur->next;}
    new->prev=cur;
    new->next=NULL;
    cur->next=new;}
}

void read_rev(bi_node *head){
  bi_node *cur=head;
  while (cur->next!=NULL){
    cur=cur->next;}
  while (cur != NULL){
    printf("%d\n",cur->key);
    cur=cur->prev;}
}

int main(){
  bi_node *list=NULL;
  int len,n,i;
  scanf("%d",&len);
  for (i=0;i<len;i++){
    scanf("%d",&n);
    push_tail(&list,n);}
  read_rev(list);
  return 0;
}
