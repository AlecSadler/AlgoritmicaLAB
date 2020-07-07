#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLEN 101

struct node{
  int key;
  char *str;
  struct node* next;};
typedef struct node node;

int fHash(x,n){
  return (x%109) % (2*n);
}

int compare_string(const void*a,const void *b){
  char* st1=*(char**)a;
  char* st2=*(char**)b;
  return strcmp(st1,st2);
}

int insert (node **tab,int n, int x, char* val){
  int pos= fHash(x,n);
  //printf("posizione %d\n",pos ); DEBUG
  if (tab[pos]==NULL){
    node* new=malloc(sizeof(node));
    new->key=x;
    new->str=val;
    new->next=NULL;
    tab[pos]=new;
    return;
  }
  node *cur= tab[pos];
  while (cur->next!=NULL){
    if (cur->key==x){
      cur->str=val;
      return;
    }
    cur=cur->next;
  }
  if (cur->key==x){
    cur->str=val;
    return;
  }
  node* new=malloc(sizeof(node));
  new->key=x;
  new->str=val;
  cur->next=new;
}

void search (node **tab, int k, int n){
  int pos= fHash(k,n);
  char** strings= malloc(n*sizeof(char*));
  node *cur= tab[pos];
  int i=0,len;
  if (tab[pos]==NULL) {
    printf("NESSUN VALORE SU QUESTO INDIRIZZO!\n");
    return;
  }
  while (cur!=NULL){
    strings[i]=malloc(MAXLEN*sizeof(char));
    strings[i] = cur->str;
    cur=cur->next;
    i++;
  }
  len=i;
  qsort(strings,len,sizeof(char*),compare_string);
  for (i=0;i<len;i++){
    printf("%s\n",strings[i]);
  }
  for (i=0;i<len;i++){
    free(strings[i]);
  }
  free(strings);
}

void main(){
    int n, x, k, i;
    char* valore;
    scanf("%d",&n);
    node **tab=malloc(2*n*sizeof(node));
    for (i=0;i< 2*n;i++){
      tab[i]=NULL;
    }
    for (i=0; i<n; i++){
      valore=malloc(MAXLEN*sizeof(char));
      scanf("%d",&x);
      scanf("%s",valore);
      insert(tab,n,x,valore);
    }
    scanf("%d",&k);
    search(tab,k,n);
}
