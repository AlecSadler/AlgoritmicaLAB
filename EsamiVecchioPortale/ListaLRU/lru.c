#include <stdio.h>
#include <stdlib.h>

struct node {
    int key;
    struct node* next;
};

typedef struct node node;

struct list {
    node* head;
    node* tail;
    int size;
};

typedef struct list list;

list* newList() {
    list* lst = malloc(sizeof(list));
    lst->head = NULL;
    lst->tail = NULL;
    lst->size = 0;
    return lst;
}

void destroyList(list* lst) {
    while(lst->head != NULL) {
        node* tmp = lst->head; // Salva l'elemento corrente
        lst->head = lst->head->next; // Avanza nella lista
        free(tmp); // Dealloca l'elemento
    }
    free(lst); // Free della struct che conteneva la lista
}

void pushHead (list *lst,int el){
  node *new= malloc(sizeof(node));
  new->key=el;
  if (lst->size==0) {
    lst->head=new;
    new->next=NULL;
    lst->tail=lst->head;
    lst->size++;
    return;
  }
  new->next=lst->head;
  lst->head=new;
  lst->size++;
}

void dropHead(list *lst){
  if (lst->size==1){
    free(lst->head);
    lst->head=NULL;
    lst->tail=NULL;
    lst->size--;
    return;
  }
  if (lst->size>1){
    node *tmp= lst->head;
    lst->head=lst->head->next;
    free(tmp);
    lst->size--;
  }
}

void dropTail(list *lst){
  if (lst->size==1){
    free(lst->tail);
    lst->head=NULL;
    lst->tail=NULL;
    lst->size--;
    return;
  }
  if (lst->size>1){
    node* cur=lst->head;
    node* prev=NULL;
    while (cur->next!=NULL) {
      prev=cur;
      cur=cur->next;
    }
    free(cur);
    prev->next=NULL;
    lst->tail=prev;
    lst->size--;
  }
}

void delNode(list *lst,int el){
  node *cur=lst->head;
  node *prev=NULL;
  while (cur!=NULL && cur->key!=el){
    prev=cur;
    cur=cur->next;
  }
  if (prev==NULL){
    dropHead(lst);
    return;
  }
  if (cur!=NULL && cur->next==NULL){
    dropTail(lst);
    return;
  }
  if (cur!=NULL){
    prev->next=cur->next;
    lst->size--;
    free(cur);
  }
}

int member(list *lst,int el){
  node *cur=lst->head;
  while (cur!=NULL && cur->key!=el){
    cur=cur->next;
  }
  if (cur!=NULL) return 1;
  return 0;
}

void printList(list *lst){
    node* curr = lst->head;
    while(curr != NULL) {
        printf("%d ", curr->key);
        curr = curr->next;
    }
    printf("$\n");
}

void main(){
  list *lru= newList();
  int c, x, end=0, n;
  scanf("%d\n",&n);
  while (!end){
    scanf("%d",&c);
    if (c==0) end++;
    else if (c==1){
      scanf("%d",&x);
      if (member(lru,x)){
        delNode(lru,x);
        pushHead(lru,x);
      }
      else {
        if (lru->size==n){
          dropTail(lru);
          pushHead(lru,x);
        }
        else
          pushHead(lru,x);
      }
    }
    else if (c==2)
      printList(lru);
  }
}
