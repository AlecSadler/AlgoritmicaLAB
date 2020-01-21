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

// sfrutto la inorder visit contando i nodi che visito
int mediana(tree *t,int count,int n,int *med){
  if (count > n/2 || n<0) return;

  if (t->left!=NULL)
    count= mediana(t->left,count,n,med);
  if (count== n/2){
    *med= t->key;
    return 1+count;
  }

  count++;
  if (t->right!=NULL)
    count= mediana(t->right,count,n,med);
  return count;
}

void main(){
  int elts, n, i=0, x, y, med;
  tree *myT=NULL;
  scanf("%d",&elts);
  while (i<elts) {
    scanf("%d",&n);
    insert(&(myT),n);
    i++;
  }
  int tmp=mediana(myT,0,elts,&med);
  printf("%d\n",med);
}
