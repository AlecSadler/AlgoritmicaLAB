#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLEN 100

struct node {
    char* key;
    struct node* next;
};

typedef struct node node;

struct list {
    node* head;
    node* tail;
    int size;
};

typedef struct list list;

int compare (const void* a, const void* b){
  char* s1 = *(char**)a;
  char* s2 = *(char**)b;
  return strcmp(s1,s2);
}

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

void pushTail(list *lst,char* el){
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

void main(){
  int closed=0, op;
  list *ambulatorio=newList();
  while (!closed){
    scanf("%d",&op);
    if (op==1){
      char *new= malloc(MAXLEN*sizeof(char));
      scanf("%s",new);
      pushTail(ambulatorio,new);
    }
    else if (op==2)
      dropHead(ambulatorio);
    else if (op==0)
      closed++;
  }
  if (ambulatorio->head!=NULL){
    int i=0;
    int len=ambulatorio->size;
    char** arr= malloc(len*sizeof(char*));
    node *cur= ambulatorio->head;
    while (cur!=NULL){
      char* el= malloc(MAXLEN*sizeof(char));
      el= cur->key;
      arr[i]=el;
      i++;
      cur=cur->next;
    }
    free(cur);
    destroyList(ambulatorio);  // ora la lista non serve più, l'ho trasferita su array
    qsort(arr,len,sizeof(char*),compare);
    for (i=0;i<len;i++){
      printf("%s\n",arr[i]);
    }
    for (i=0;i<len;i++){    // libero l'array
      free(arr[i]);
    }
    free(arr);
  }
  printf("$\n");
}
