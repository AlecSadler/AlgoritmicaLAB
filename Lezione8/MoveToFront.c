#include <stdio.h>
#include <stdlib.h>

struct node{
  int key;
  struct node* next;};
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

int moveToFront(list *lst,int n){
  node *cur= lst->head;
  node *prev= NULL;
  int count=0;
  while (cur->next!=NULL) {
    if (cur->key==n){
      if (prev==NULL)
        return 0;
      int aux= cur->key;
      prev->next=cur->next;
      free(cur);
      pushHead(lst,aux);
      lst->size--;
      return count;
    }
    count++;
    prev=cur;
    cur=cur->next;
  }
  if (cur->key==n){
    int aux= cur->key;
    lst->tail=prev;
    pushHead(lst,aux);
    free(cur);
    return count++;
  }
  return -1;
}

void main(){
  int n, query, i, el;
  list *lst=newList();
  scanf("%d",&n);
  for (i=0;i<n;i++){
    scanf("%d",&el);
    pushTail(lst,el);
  }
  int end=0;
  while (!end){
    scanf("%d",&query);
    int tmp=moveToFront(lst,query);
    if (tmp==-1){
      printf("%d\n",tmp);
      end++;
    }
    else
      printf("%d\n",tmp);
  }
}
