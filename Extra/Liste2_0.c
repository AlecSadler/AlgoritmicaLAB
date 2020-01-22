// un'implementazione delle liste più complessa ma risulta più efficiente in alcune operazioni

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

void pushTail(list *lst,int el){
  node *new=malloc(sizeof(node));
  new->next=NULL;
  new->key=el;
  if (lst->size==0){
    lst->head=new;
    new->next=NULL;
    lst->tail=lst->head;
    lst->size++;
    return;
  }
  lst->tail->next=new;
  lst->tail=new;
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
    printf("Elementi presenti: %d\n",lst->size);
    printf("Contenuto della lista:\n");
    while(curr != NULL) {
        printf("%d -> ", curr->key);
        curr = curr->next;
    }
    printf("NULL\n");
}

void main(){
  list *l1= newList();
  pushTail(l1,4);
  pushTail(l1,6);
  pushHead(l1,9);
  pushHead(l1,2);
  printList(l1);

  dropHead(l1);
  printList(l1);

  delNode(l1,4);
  printList(l1);

  printf("%d %d\n",member(l1,12),member(l1,6));

}
