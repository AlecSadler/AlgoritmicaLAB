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

void inorder_walk (btree *t){
  if (t!=NULL){
    inorder_walk(t->left);
    printf("%d\n",t->key);
    inorder_walk(t->right);}
  else return;
}

int main(){
  int end=0;
  int el,n,i;
  btree *t=NULL;
  scanf("%d",&n);
  for (i=0;i<n;i++){
    scanf("%d",&el);
    insert(&t,el);}
  inorder_walk(t);
  return 0;
}
