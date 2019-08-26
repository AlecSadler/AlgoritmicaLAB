#include <stdio.h>
#include <stdlib.h>

struct ter_tree{
  int key;
  struct ter_tree* left;
  struct ter_tree* cx;
  struct ter_tree* right;};

typedef struct ter_tree ter_tree;

/* versione ricorsiva dell'inserimento di un nodo
void insertRec (ter_tree** t,int el){
  if (*t==NULL){
    *t=malloc(sizeof(ter_tree));
    (*t)->left=NULL;
    (*t)->cx=NULL;
    (*t)->right=NULL;
    (*t)->key=el;}
  else{
    if (el % ((*t)->key) == 0)
      insertRec(&(*t)->cx,el);
    else{
      if (el <= (*t)->key)
        insertRec(&(*t)->left,el);
      else
        insertRec(&(*t)->right,el);}}
}  */

void insert (ter_tree** t,int el){
  ter_tree *new=malloc(sizeof(ter_tree));
  new->left=NULL;
  new->cx=NULL;
  new->right=NULL;
  new->key=el;
  if (*t==NULL){
    *t=new;}
  else{
    ter_tree *cur=*t;
    ter_tree *par;
    while (cur!=NULL){
      par=cur;
      if (el%(cur->key) == 0)
        cur=cur->cx;
      else{
        if (el <= cur->key)
          cur=cur->left;
        else
          cur=cur->right;}}
    if ((new->key % par->key) == 0)
      par->cx=new;
    else{
      if (new->key < par->key)
        par->left=new;
      else
        par->right=new;}}
}


// conta i nodi che hanno tutti e 3 i figli
int complete (ter_tree *t){
  if (t!=NULL){
    if (t->left!=NULL && t->cx!=NULL && t->right!=NULL)
      return 1 + complete(t->left) + complete(t->cx) + complete(t->right);
    else
      return complete(t->left) + complete(t->cx) + complete(t->right);}
  else return 0;
}

int main(){
  int el,n,i;
  ter_tree *t1=NULL;
  scanf("%d",&n);
  for (i=0;i<n;i++){
    scanf("%d",&el);
    insert(&t1,el);}
  printf("%d\n",complete(t1));
  return 0;
}
