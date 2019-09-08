#include <stdlib.h>
#include <stdio.h>

struct btree{
  int key;
  struct btree* left;
  struct btree* right;};

typedef struct btree btree;

void insert (btree** t,int el){
  btree *new=malloc(sizeof(btree));
  new->left=NULL;
  new->right=NULL;
  new->key=el;
  if (*t==NULL){
    *t=new;}
  else{
    btree *cur=*t;
    btree *par;
    while (cur!=NULL){
      par=cur;
      if (cur->key < el)
        cur=cur->right;
      else
        cur=cur->left;}
    if (par->key < el)
      par->right=new;
    else
      par->left=new;}
}

int conta_nodiL (btree* t){
  if (t==NULL)
    return 0;
  return 1+conta_nodiL(t->left);
}

int conta_nodiR (btree* t){
  if (t==NULL)
    return 0;
  return 1+conta_nodiR(t->right);
}

void checkLR (btree *t){
  if (t==NULL) return;
  if (conta_nodiL(t->left) > conta_nodiR(t->right)){
    checkLR(t->left);
    printf("%d\n",t->key);
    checkLR(t->right);}
  else{
    checkLR(t->left);
    checkLR(t->right);}
}

int main(){
  int el,n,i;
  btree *t=NULL;
  scanf("%d",&n);
  for (i=0;i<n;i++){
    scanf("%d",&el);
    insert(&t,el);}
  checkLR(t);
  return 0;
}
