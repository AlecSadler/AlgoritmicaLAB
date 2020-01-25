#include <stdio.h>
#include <stdlib.h>

struct btree{
  int key;
  struct btree* left;
  struct btree* right;
};

struct solution{
  int min;
  int path;
};

typedef struct btree tree;
typedef struct solution solution;

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

solution minMaxPath (tree *t){
  if (t==NULL){
    solution res;
    res.min=0;
    res.path=0;
    return res;
  }
  if (t->left==NULL && t->right==NULL){
    solution leaf;
    leaf.min= t->key;
    leaf.path= t->key;
    return leaf;
  }
  solution sx= minMaxPath(t->left);
  solution dx= minMaxPath(t->right);
  // scelgo il cammino maggiore
  solution max;
  if (sx.path > dx.path)
    max=sx;
  else if (sx.path < dx.path)
    max=dx;
  else if (sx.min < dx.min)
    max=sx;
  else
    max=dx;
  max.path= max.path + t->key;
  if (t->key < max.min)
    max.min=t->key;
  return max;
}

void main(){
  int n, i, el;
  tree *tr=NULL;
  scanf("%d",&n);
  for (i=0;i<n;i++){
    scanf("%d",&el);
    insert(&tr,el);
  }
  printf("%d\n",minMaxPath(tr).min);
}
