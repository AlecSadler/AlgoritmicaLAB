// Es. 6.4 Bertossi-Montresor stampa dell'intervallo A-B in un ABR

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

void intervallo(tree *t,int a,int b){
  if (t==NULL) {
    return;
  }
  intervallo(t->left,a,b);
  if (t->key <= b && t->key >=a) printf("%d\n",t->key);
  intervallo(t->right,a,b);
}

void inorderTrav(tree *t){
  if (t==NULL) return;
  inorderTrav(t->left);
  printf("%d - ",t->key);
  inorderTrav(t->right);
}

void main(){
  int n, i, el, a, b;
  tree *tr=NULL;
  scanf("%d",&n);
  for (i=0;i<n;i++){
    scanf("%d",&el);
    insert(&tr,el);
  }
  inorderTrav(tr);
  printf("\n");
  scanf("%d%d",&a,&b);
  intervallo(tr,a,b);
}
