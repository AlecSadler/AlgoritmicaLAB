/* BERTOSSI-MONTRESOR ES. 5.9 - Dato un ABR generare albero inverso */

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

void invertT(tree *t){
  if (t==NULL) return;
  if (t->left==NULL && t->right==NULL) return;
  tree *tmp= t->left;
  t->left=t->right;
  t->right=tmp;
  invertT(t->right);
  invertT(t->left);
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
  invertT(tr);
  inorderTrav(tr);
}
