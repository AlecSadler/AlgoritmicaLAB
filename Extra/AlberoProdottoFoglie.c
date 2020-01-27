/* calcolare il prodotto di tutti i nodi foglia */

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

void leafProd(tree *t,int *prod){
  if (t==NULL)
    return;
  if (t->left==NULL && t->right==NULL)
    *prod= (*prod) * t->key;
  leafProd(t->right,prod);
  leafProd(t->left,prod);
}

void inorderTrav(tree *t){
  if (t==NULL) return;
  inorderTrav(t->left);
  printf("%d - ",t->key);
  inorderTrav(t->right);
}

void main(){
  int n, i, el, k, prod=1;
  tree *tr=NULL;
  scanf("%d",&n);
  for (i=0;i<n;i++){
    scanf("%d",&el);
    insert(&tr,el);
  }
  inorderTrav(tr);
  printf("\n");
  leafProd(tr,&prod);
  printf("%d\n",prod);
}
