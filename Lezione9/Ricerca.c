#include <stdio.h>
#include <stdlib.h>

struct btree{
  int key;
  struct btree* left;
  struct btree* right;};

struct src_results{
  int val;                     // uso una lista per memorizzare gli esiti delle ricerche
  struct src_results* next;};

typedef struct btree btree;
typedef struct src_results src_results;

void push_tail(src_results **head,int el){
  src_results *new=malloc(sizeof(src_results));
  new->val=el;
  new->next=NULL;
  if (*head==NULL){
    *head=new;}
  else{
    src_results *cur=*head;
    while (cur->next!=NULL){
      cur=cur->next;}
    cur->next=new;}
}

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

int search_key (btree *t,int el){
  int depth=0;
  btree *cur=t;
  while (cur!=NULL){
    if (cur->key==el)
      return depth;
    else if (cur->key < el)
      cur=cur->right;
    else
      cur=cur->left;
    depth++;}
  return -1;
}

void printList (src_results *head){
  while (head!=NULL){
    if (head->val!=-1)
      printf("%d\n",head->val);
    else
      printf("NO\n");
    head=head->next;}
}

int main(){
  int end=0;
  int el,n,i,src;
  src_results *res=NULL;
  btree *t=NULL;
  scanf("%d",&n);
  for (i=0;i<n;i++){
    scanf("%d",&el);
    insert(&t,el);}
  while (!end){
    scanf("%d",&el);
    if (el>=0){
      src=search_key(t,el);
      push_tail(&res,src);}
    else
      end++;}
  printList(res);
  return 0;
}
