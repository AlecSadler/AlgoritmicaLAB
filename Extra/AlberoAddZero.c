/* BERTOSSI-MONTRESOR ES. 5.7 - Dato un ABR aggiungere ad ogni nodo foglia, un figlio sinistro con chiave 0 */

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

// basata su post-order
void add0Leaf(tree *t){
  if (t==NULL) return;
  add0Leaf(t->right);
  add0Leaf(t->left);
  if ( t->left==NULL && t->right==NULL){
    tree *zero= malloc(sizeof(tree));
    zero->key=0;
    zero->left=NULL;
    zero->right=NULL;
    t->left=zero;
  }
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
  add0Leaf(tr);
  inorderTrav(tr);
}
