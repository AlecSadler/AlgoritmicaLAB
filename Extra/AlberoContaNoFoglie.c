// contare nodi non foglia

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

int nonLeafCount(tree *t){
  if (t==NULL)
    return 0;
  if (t->left==NULL && t->right==NULL) return 0;
  return 1 + nonLeafCount(t->right) + nonLeafCount(t->left);
}

void inorderTrav(tree *t){
  if (t==NULL) return;
  inorderTrav(t->left);
  printf("%d - ",t->key);
  inorderTrav(t->right);
}

void main(){
  int n, i, el;
  tree *tr=NULL;
  scanf("%d",&n);
  for (i=0;i<n;i++){
    scanf("%d",&el);
    insert(&tr,el);
  }
  inorderTrav(tr);
  printf("\n");
  printf("%d\n",nonLeafCount(tr));
}
