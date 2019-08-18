#include <stdio.h>
#include <stdlib.h>

struct node{
  int key;
  struct node* next;};

typedef struct node node;

void push_tail(node **head,int el){
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

int average (node *head){
  int sum=0, count=0;
  if (head!=NULL){
    node *cur=head;
    while (cur!=NULL){
      sum=sum+cur->key;
      count++;
      cur=cur->next;}
    return (int)sum/count;}
  else{
    return 0;}
}

void del_avg (node **head,int avg){
  if (*head!=NULL){
    if ((*head)->key<=avg){
      node *tmp=*head;
      *head=(*head)->next;
      free(tmp);
      del_avg(&(*head),avg);}
    else
      del_avg(&(*head)->next,avg);}
  else return;
}

void printList (node *head){
  while (head!=NULL){
    printf("%d ",head->key);
    head=head->next;}
  printf("\n");
}

int main(){
  int n,i,el,avg;
  node *list=NULL;
  scanf("%d",&n);
  for (i=0;i<n;i++){
    scanf("%d",&el);
    push_tail(&list,el);}
  avg=average(list);
  printf("%d\n",avg);
  printList(list);
  del_avg(&list,avg);
  printList(list);
  return 0;
}
