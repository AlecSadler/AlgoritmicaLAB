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

void insert (node **tab, int n, int a, int b, int x, int *conf, int *maxlen, int *unique){
  int position= fHash(n,x,a,b);
  int len=0;
  if (tab[position]==NULL){
    node *new= malloc(sizeof(node));
    new->key=x;
    tab[position]=new;
    tab[position]->next=NULL;
    *unique= *unique + 1;
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
  while (cur->next!=NULL && x!=cur->key) {
    len++;
    cur=cur->next;
  }
  len++;
  if (cur->key==x){                // controllo se mi sono fermato perchè arrivato alla fine
    *conf = *conf - 1;             //   oppure perchè sono incappato in un doppione 
    return;
  }
  if (len > *maxlen) *maxlen=len;
  cur->next=new;
  *unique= *unique + 1;
}

void main(){
  int n, i, a, b, x, conflicts, maxLength, uniques;
  scanf("%d",&n);
  node **tab=malloc((2*n)*sizeof(node));
  for (i=0;i<(2*n);i++){
    tab[i]=NULL;
  }
  conflicts=0;
  maxLength=0;
  uniques=0;
  scanf("%d%d",&a,&b);
  for (i=0;i<n;i++){
    scanf("%d",&x);
    insert(tab,n,a,b,x,&conflicts,&maxLength,&uniques);
  }
  printf("%d\n%d\n%d\n",conflicts,maxLength,uniques);
}
