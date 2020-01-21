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

int secondMax(tree *t){
  tree *cur=t;
  tree *prev=NULL;
  while (cur->right!=NULL){
    prev=cur;
    cur=cur->right;
  }
  if (cur->left==NULL) return prev->key;
  cur=cur->left;
  while (cur->right!=NULL) {
    cur=cur->right;
  }
  return cur->key;
}

/* VISITA DELL'ALBERO PER CONTROLLI
void inorderVisit(tree *t){
  if (t==NULL) return;
  inorderVisit(t->left);
  printf("%d - %s\n",t->key,t->name);
  inorderVisit(t->right);
}  */

void main(){
  int elts, n, i=0;
  tree *myT=NULL;
  scanf("%d",&elts);
  while (i<elts) {
    scanf("%d",&n);
    insert(&(myT),n);
    i++;
  }
  printf("%d\n",secondMax(myT));
}
