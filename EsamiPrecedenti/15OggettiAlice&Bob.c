#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#define MAXLEN 101

// oggetto formato da nome e valore
struct item {
  char* nome;
  int val;};

typedef struct item item;

// lista di oggetti
struct node {
  item key;
  struct node* next;};

typedef struct node node;

void push (node **head,char *nome,int val){
  node *new=malloc(sizeof(node));
  new->key.nome=nome;
  new->key.val=val;
  if ( *head==NULL){
    new->next=NULL;
    *head=new;
  }
  else{
    new->next=*head;
    *head=new;
  }
}

// calcola la funzione hash e inserisce
void hash_insert (node **tab,int n,char *nome,int val){
  int hx, str_val=0, i;
  for (i=0;i< strlen(nome);i++){
    str_val=str_val + (unsigned int)nome[i];
  }
  hx= str_val % (2*n);
  node *cur=tab[hx];
  while (cur!=NULL){
    if (!strcmp(cur->key.nome,nome)){
      if ( cur->key.val < val){
        cur->key.val=val;
        return;
      }
      else
        return;
    }
    else{
      cur=cur->next;
    }
  }
  push(&(tab[hx]),nome,val);
}

// trasforma la tabella in un array per poter ordinare
void tableToArr (node **tab,int n,item *arr,int *len){
  int i, j=0;
  for (i=0;i< 2*n;i++){
    node *cur=tab[i];
    while (cur!=NULL){
      arr[j]=cur->key;
      j++;
      cur=cur->next;
    }
  }
  *len=j;
}

// funzione ausiliaria per qsort
int struct_compare (const void *a,const void *b){
  item it_a= *(item*)a;
  item it_b= *(item*)b;
  if ( it_a.val == it_b.val)
    return strcmp(it_a.nome,it_b.nome);
  return it_b.val - it_a.val;
}

int main(){
  int i, n, valore, len;
  scanf("%d",&n);
  item *arr=malloc(n*sizeof(item));
  node **tab=malloc(2*n*sizeof(node));
  for (i=0;i< 2*n;i++){
    tab[i]=NULL;
  }
  for(i=0;i<n;i++){
    char *name=malloc(MAXLEN*sizeof(char));
    scanf("%s",name);
    scanf("%d",&valore);
    hash_insert(tab,n,name,valore);
  }
  tableToArr(tab,n,arr,&len);
  qsort(arr,len,sizeof(item),struct_compare);
  if (len > 15){
    for (i=0;i<15;i++){
      printf("%s\n",arr[i].nome);
    }
  }
  else{
    for (i=0;i<len;i++){
      printf("%s\n",arr[i].nome);
    }
  }
  return 0;
}
