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

void printList (node *head){
  while (head!=NULL){
    printf("%d ",head->key);
    head=head->next;}
  printf("\n");
}

int sum_fw (node *head){
  if (head!=NULL)
    return head->key + sum_fw(head->next);
  else return 0;
}

void suffix_sum (node **head){
  if (*head!=NULL){
    (*head)->key=sum_fw((*head)->next);
    suffix_sum(&(*head)->next);}
  else return;
}

int main(){
  int n,i,el;
  node *list=NULL;
  scanf("%d",&n);
  for (i=0;i<n;i++){
    scanf("%d",&el);
    push_tail(&list,el);}
  printList(list);
  suffix_sum(&list);
  printList(list);
  return 0;
}
