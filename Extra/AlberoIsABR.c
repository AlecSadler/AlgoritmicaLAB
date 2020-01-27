// controllo se un albero è un ABR

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

void isABR(tree *t,int *ans){
  if (t==NULL) {
    return;
  }
  int tmp= t->key;
  isABR(t->left,ans);
  if (t->key < tmp){
    *ans=0;
    return;
  }
  isABR(t->right,ans);
}


void inorderTrav(tree *t){
  if (t==NULL) return;
  inorderTrav(t->left);
  printf("%d - ",t->key);
  inorderTrav(t->right);
}

void main(){
  int n, i, el,b=1;
  tree *tr=NULL;
  scanf("%d",&n);
  for (i=0;i<n;i++){
    scanf("%d",&el);
    insert(&tr,el);
  }
  inorderTrav(tr);
  printf("\n");
  isABR(tr,&b);
  printf("%d\n",b);
}
