/* controllare se esiste un cammino radice-foglia uguale a k dato in input */

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

int existPathK(tree *t,int k){
  if (t==NULL)
    return 0;
  int sub= k - t->key;
  int b= 0;   // booleano da ritornare
  if (sub==0 && t->left==NULL && t->right==NULL)
    return 1;
  b= (b || existPathK(t->left,sub));
  b= (b || existPathK(t->right,sub));
  return b;

}

void inorderTrav(tree *t){
  if (t==NULL) return;
  inorderTrav(t->left);
  printf("%d - ",t->key);
  inorderTrav(t->right);
}

void main(){
  int n, i, el,k;
  tree *tr=NULL;
  scanf("%d",&n);
  for (i=0;i<n;i++){
    scanf("%d",&el);
    insert(&tr,el);
  }
  inorderTrav(tr);
  printf("\n");
  scanf("%d",&k);
  printf("%d\n",existPathK(tr,k));
}
