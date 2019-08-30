#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLEN 101

struct paziente{
  char* nome;
  struct paziente* next;};

typedef struct paziente paziente;

int str_compare (const void *a,const void *b){
  char* st1= *(char**)a;
  char* st2= *(char**)b;
  return strcmp (st1,st2);
}

void pushTail (paziente **head){
  char *nome=malloc(MAXLEN*sizeof(char));
  scanf("%s",nome);
  paziente *new= malloc(sizeof(paziente));
  new->next=NULL;
  new->nome=nome;
  if (*head==NULL)
    *head=new;
  else{
    paziente *cur=*head;
    while (cur->next != NULL){
      cur=cur->next;}
    cur->next=new;}
}

void delete_head (paziente **head){
  if (*head!=NULL){
    paziente *tmp=*head;
    *head=(*head)->next;
    free(tmp);}
  else return;
}

int lengthList(paziente *head){
  if (head!=NULL)
    return 1+ lengthList(head->next);
  else return 0;
}

int main(){
  int i,action,len,end=0;
  paziente *list=NULL;
  char **closing;
  while (!end){
    scanf("%d",&action);
    if (action==1)
      pushTail(&list);
    else if (action==2)
      delete_head(&list);
    else if (action==0)
      end++;}
  //da qui in poi trasferisco la lista su un array per poterlo ordinare
  len=lengthList(list);
  closing=malloc(len*sizeof(char*));
  i=0;
  while (list!=NULL){
    closing[i]=malloc(MAXLEN*sizeof(char));
    closing[i]=list->nome;
    list=list->next;
    i++;}
  free(list); //a questo punto la lista non mi serve più
  qsort(closing,len,sizeof(char*),str_compare);
  for (i=0;i<len;i++){
    printf("%s\n",closing[i]);}
  printf("$\n");
  return 0;
}
