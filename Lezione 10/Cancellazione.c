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

void filterAvg(list *lst,int avg){
  node *cur=lst->head;
  node *prev=NULL;
  while (cur!=NULL){
    if (cur->key <= avg){
      if (prev==NULL){
        dropHead(lst);
        cur=lst->head;
      }
      else if (cur!=NULL && cur->next==NULL){
        dropTail(lst);
        return;
      }
      else if (cur!=NULL){
        node *tmp=cur;
        prev->next= cur->next;
        cur=prev->next;
        free(tmp);
      }
    }
    else{
      prev=cur;
      if (cur!=NULL)
        cur=cur->next;
    }
  }
}

void printList(list *lst){
    node* curr = lst->head;
    while(curr != NULL) {
        printf("%d ", curr->key);
        curr = curr->next;
    }
    printf("\n");
}

void main(){
  int avg, sum=0, n, i, el;
  list *l = newList();
  scanf("%d",&n);
  for (i=0;i<n;i++){
    scanf("%d",&el);
    pushTail(l,el);
    sum= sum + el;
  }
  avg= sum/n;
  printf("%d\n",avg);
  printList(l);
  filterAvg(l,avg);
  printList(l);
}
