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
  if (n <= (*t)->key)
    insert(&(*t)->left,n);
  else
    insert (&(*t)->right,n);
}

// visito dalla radice, il primo nodo che incontro compreso tra n1 e n2 è il LCA
int lca(tree *t,int n1,int n2){
  if (t->key > n1 && t->key > n2)
    return lca(t->left,n1,n2);    // se n1 e n2 sono più piccoli della radice vado a sinistra
  if (t->key < n1 && t->key < n2)
    return lca(t->right,n1,n2);   // se n1 e n2 sono più grandi della radice vado a destra
  return t->key;
}

/* VISITA DELL'ALBERO PER CONTROLLI
void inorderVisit(tree *t){
  if (t==NULL) return;
  inorderVisit(t->left);
  printf("%d - %s\n",t->key,t->name);
  inorderVisit(t->right);
}  */

void main(){
  int elts, n, i=0, x, y;
  tree *myT=NULL;
  scanf("%d",&elts);
  while (i<elts) {
    scanf("%d",&n);
    insert(&(myT),n);
    i++;
  }
  scanf("%d%d",&x,&y);
  printf("%d\n",lca(myT,x,y));
}
