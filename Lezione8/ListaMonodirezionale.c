#include <stdio.h>
#include <stdlib.h>

struct Node{
  int key;
  struct Node* next;};

typedef struct Node Node;

void pushTail(Node **head,int el){
  Node *new=malloc(sizeof(Node));
  new->key=el;
  new->next=NULL;
  if (*head==NULL){
    *head=new;
    (*head)->next=NULL;}
  else{
    Node *cur= *head;
    while (cur->next != NULL){
      cur=cur->next;}
    cur->next=new;}
}

void readList(Node **head){
  int len;
  scanf("%d",&len);
  int i;
  int n;
  for (i=0;i<len;i++){
    scanf("%d",&n);
    pushTail(&(*head),n);}
}

// sfrutta il funzionamento bottom-up della ricorsione per stampare la lista dalla fine
void readRev(Node *head){
  if (head==NULL)
    return;
  else{
    readRev(head->next);
    printf("%d\n",head->key);}
}

int main(){
  Node *list=NULL;
  readList(&list);
  readRev(list);
  return 0;
}
