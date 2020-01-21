#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLEN 101

struct btree{
  int key;
  char* name;
  struct btree* left;
  struct btree* right;
};

typedef struct btree tree;

void insert (tree **t,int n,char *nome){
    if (*t==NULL){
    tree *new= malloc(sizeof(tree));
    new->key= n;
    new->name= nome;
    new->left=NULL;
    new->right=NULL;
    *t=new;
    return;
  }
  if (n < (*t)->key)
    insert(&(*t)->left,n,nome);
  else
    insert (&(*t)->right,n,nome);
}

int srcMaxSub (tree *t,char* s){
  if (t==NULL) return -1;
  tree *cur= t;
  int found=0;
  while (cur->left!=NULL || cur->right!=NULL && !found) {
    if ( !strcmp(cur->name,s)) found++;
    else{
      if ( strcmp(cur->name,s) > 0 && cur->left!=NULL)
        cur= cur->left;
      else if (cur->right!=NULL)
        cur=cur->right;
    }
  }
  int dir;    // uso una variabile per capire la direzione del cammino
  if (cur->right!=NULL && cur->right->key > cur->key){
    cur= cur->right;
    dir=0;
  }
  else if (cur->left!=NULL){
    cur= cur->left;
    dir=1;
  }
  if (!dir) {
    while (cur->right!=NULL){
      cur=cur->right;
    }
  }
  else{
    while (cur->left!=NULL) {
      cur=cur->left;
    }
  }
  return cur->key;
}

/* VISITA DELL'ALBERO PER CONTROLLI
void inorderVisit(tree *t){
  if (t==NULL) return;
  printf("madonna\n" );
  inorderVisit(t->left);
  printf("%d - %s\n",t->key,t->name);
  inorderVisit(t->right);
}  */

void main(){
  int elts, n, i=0;
  tree *myT=NULL;
  char *s = malloc(MAXLEN*sizeof(char));
  scanf("%d",&elts);
  while (i<elts) {
    char *name = malloc(MAXLEN*sizeof(char));
    scanf("%s",name);
    scanf("%d",&n);
    insert(&(myT),n,name);
    i++;
  }
  scanf("%s",s);
  printf("%d\n",srcMaxSub(myT,s));
}
