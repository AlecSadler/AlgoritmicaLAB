#include <stdio.h>
#include <stdlib.h>

#define HASH_CONST 999149

struct node{
  int key;
  struct node* next;};
typedef struct node node;

int fHash (int n, int x, int a, int b){
  return ((a*x + b) % HASH_CONST) % (2*n);
}

void insert (node **tab, int n, int a, int b, int x, int *conf, int *maxlen){
  int position= fHash(n,x,a,b);
  int len=0;
  if (tab[position]==NULL){
    node *new= malloc(sizeof(node));
    new->key=x;
    tab[position]=new;
    tab[position]->next=NULL;
    len++;
    if (len > *maxlen) *maxlen=len;
    return;
  }
  *conf=*conf + 1;
  len++;
  node *new=malloc(sizeof(node));
  new->key=x;
  new->next=NULL;
  node *cur=tab[position];
  while (cur->next!=NULL) {
    len++;
    cur=cur->next;
  }
  len++;  // incremento di nuovo perchè il while termina al penultimo elemento
  if (len > *maxlen) *maxlen=len;
  cur->next=new;
}

void main(){
  int n, i, a, b, x, conflicts, maxLength;
  scanf("%d",&n);
  node **tab=malloc((2*n)*sizeof(node));
  for (i=0;i<(2*n);i++){
    tab[i]=NULL;
  }
  conflicts=0;
  maxLength=0;
  scanf("%d%d",&a,&b);
  for (i=0;i<n;i++){
    scanf("%d",&x);
    insert(tab,n,a,b,x,&conflicts,&maxLength);
  }
  printf("%d\n%d\n",maxLength,conflicts);
}
