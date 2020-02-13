#include <stdio.h>
#include <stdlib.h>

struct btree{
  int key;
  struct btree* left;
  struct btree* right;
};

typedef struct btree tree;

void insert (tree **t,int n){
    if (*t==NULL){
    tree *new= malloc(sizeof(tree));
    new->key= n;
    new->left=NULL;
    new->right=NULL;
    *t=new;
    return;
  }
  if (n < (*t)->key)
    insert(&(*t)->left,n);
  else
    insert (&(*t)->right,n);
}

void printLevel(tree *t,int k,int depth){
  if (t==NULL) return;
  printLevel(t->left,k,depth+1);
  if (depth==k){
    printf("%d\n",t->key);
    return;
  }
  printLevel(t->right,k,depth+1);
}

void main(){
  int n, k, i, el;
  tree *tr=NULL;
  scanf("%d",&n);
  for (i=0;i<n;i++){
    scanf("%d",&el);
    insert(&tr,el);
  }
  scanf("%d",&k);
  printLevel(tr,k,0);
}
