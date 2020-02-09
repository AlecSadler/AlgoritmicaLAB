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

int samePath (tree *t1, tree *t2, int k){
	if (t1->key==k && t2->key==k)
		return 1;
	if (k < t1->key && k < t2->key && t1->key == t2->key)
		return samePath(t1->left,t2->left,k);
	else if (k > t1->key && k > t2->key && t1->key == t2->key)
		return samePath(t1->right,t2->right,k);
	else return 0;
}

void main(){
	int i, n, k, el;
	tree *t1=NULL, *t2=NULL;
	scanf("%d%d\n",&n,&k);
	for (i=0;i<n;i++){
		scanf("%d",&el);
		insert(&t1,el);
	}
	for (i=0;i<n;i++){
		scanf("%d",&el);
		insert(&t2,el);
	}
	printf("%d\n",samePath(t1,t2,k));
}
