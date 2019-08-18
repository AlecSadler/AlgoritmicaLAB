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

int max_depth (btree *t){
  if (t!=NULL){
    int rd=max_depth(t->right);
    int ld=max_depth(t->left);
    if (rd>ld)
      return 1+rd;
    else
      return 1+ld;}
  else
    return 0;
}

int main(){
  int end=0;
  int el,n,i;
  btree *t=NULL;
  scanf("%d",&n);
  for (i=0;i<n;i++){
    scanf("%d",&el);
    insert(&t,el);}
  printf("%d\n",max_depth(t));
  return 0;
}
