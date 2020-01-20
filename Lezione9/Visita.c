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

int maxDepth(tree *t){
  if (t==NULL) return 0;
  int rd= maxDepth(t->right);
  int ld= maxDepth(t->left);
  if (rd>ld) return 1+ rd;
  else return 1+ld;
}

void main(){
  int elts, n, i=0;
  tree *myT=NULL;
  scanf("%d",&elts);
  while (i<elts) {
    scanf("%d",&n);
    insert(&(myT),n);
    i++;
  }
  printf("%d\n",maxDepth(myT));
}
