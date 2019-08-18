#include <stdio.h>
#include <stdlib.h>

struct btree{
  int key;
  struct btree* left;
  struct btree* right;};

typedef struct btree btree;

void insert (btree** t,int el){
  btree *new=malloc(sizeof(btree));
  new->left=NULL;
  new->right=NULL;
  new->key=el;
  if (*t==NULL){
    *t=new;}
  else{
    btree *cur=*t;
    btree *par;
    while (cur!=NULL){
      par=cur;
      if (cur->key < el)
        cur=cur->right;
      else
        cur=cur->left;}
    if (par->key < el)
      par->right=new;
    else
      par->left=new;}
}

int key_prec (btree *t1,btree *t2,int el){
  if (t1==NULL || t2==NULL)
      return 0;
  else if (t1->key==el && t2->key==el)
    return 1;
  else if (t1->key != t2->key)
    return 0;
  else if (t1->key < el)
    return key_prec(t1->right,t2->right,el);
  else
    return key_prec(t1->left,t2->left,el);
}

int main(){
  int k,el,n,i;
  btree *t1=NULL;
  btree *t2=NULL;
  scanf("%d %d",&n,&k);
  for (i=0;i<n;i++){
    scanf("%d",&el);
    insert(&t1,el);}
  for (i=0;i<n;i++){
    scanf("%d",&el);
    insert(&t2,el);}
  printf("%d\n",key_prec(t1,t2,k));
  return 0;
}
