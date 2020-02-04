#include <stdio.h>
#include <stdlib.h>

struct node {
    int key;
    struct node* next;
};

typedef struct node node;

void push(node **head,int el){
  node *new=malloc(sizeof(node));
  new->key=el;
  new->next=NULL;
  if (*head==NULL){
    *head=new;
    return;
  }
  node *cur= *head;
  while (cur->next!=NULL) {
    cur=cur->next;
  }
  cur->next=new;
}

void suffixSum(node *head, int* s){
  int f;
  if(head==NULL) return;
  *s= *s + head->key;
  f= *s - head->key;
  suffixSum(head->next, s);
  head->key= *s - f - head->key;
}

void printList(node *head){
  if (head==NULL) return;
  printf("%d ",head->key);
  printList(head->next);
}

void main(){
  int el, n, i, sum=0;
  node *lst=NULL;
  scanf("%d",&n);
  for (i=0;i<n;i++){
    scanf("%d",&el);
    push(&lst,el);
  }
  printList(lst);
  printf("\n");
  suffixSum(lst,&sum);
  printList(lst);
  printf("\n");
}
