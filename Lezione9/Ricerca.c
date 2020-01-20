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

int binarySearch (tree *t,int x){
  int depth=0;
  tree *cur=t;
  while (cur!=NULL) {
    if (cur->key==x)
      return depth;
    else if (x <= cur->key)
      cur=cur->left;
    else
      cur= cur->right;
    depth++;
  }
  return -1;
}

void main(){
  int elts, n, i=0, end=0;
  tree *myT=NULL;
  scanf("%d",&elts);
  while (i<elts) {
    scanf("%d",&n);
    insert(&(myT),n);
    i++;
  }
  while (!end) {
    scanf("%d",&n);
    if (n<0)
      end++;
    else{
      int res = binarySearch(myT,n);
      if (res==-1) printf("NO\n");
      else printf("%d\n",res);
    }
  }
}

