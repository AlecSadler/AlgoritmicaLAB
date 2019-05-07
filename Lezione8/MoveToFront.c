#include <stdio.h>
#include <stdlib.h>

struct Node{
  int key;
  struct Node *next;};

typedef struct Node Node;

void push_tail(Node **head,int el){
  Node *new=malloc(sizeof(Node));
  new->key=el;
  new->next=NULL;
  if (*head==NULL){
    *head=new;}
  else{
    Node *cur=*head;
    while (cur->next!=NULL){
      cur=cur->next;}
    cur->next=new;}
}

int member(Node *head,int el){
  if (head!=NULL){
    if (head->key==el)
      return 1;
    else
      member(head->next,el);}
  else
    return 0;
}

// search the "i" value in the list,moves it to head and return its initial position
int MoveToFront(Node **head,int i){
  int pos=0;
  if (*head!=NULL){
    Node *cur=*head;
    Node *prev=NULL;
    Node *tmp;
    while (cur!=NULL){
      if (cur->key == i){
        if (prev==NULL){
          return pos;}
        else{
          tmp=cur;
          prev->next=cur->next;
          if (prev->next!=NULL)
            cur=cur->next->next;
          else
            cur=NULL;
          tmp->next=*head;
          *head=tmp;
          return pos;}}
      else{
       pos++;
       prev=cur;
       cur=cur->next;}}}
  return -1;
}

void printList(Node *head){
  while (head!=NULL){
    printf("%d\n",head->key);
    head=head->next;}
}

int main(void){
  int end=0;
  Node *list=NULL;
  Node *positions=NULL;
  int i,n,len;
  scanf("%d",&len);
  for (i=0;i<len;i++){
    scanf("%d",&n);
    push_tail(&list,n);}
  while (end==0){
    scanf("%d",&i);
    if (!member(list,i)){
      end=1;
      push_tail(&positions,-1);}
    else
      push_tail(&positions,MoveToFront(&list,i));}
  printList(positions);
  return 0;
}
