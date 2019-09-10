#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLEN 101
#define MAXNUM 21

struct node{
  char* nome;
  char* numero;
  struct node *next;};

typedef struct node node;

// inserisce in ordine crescente,per stringhe
void push_order (node **head,char *nome,char *numero){
  node *new=malloc(sizeof(node));
  new->nome=nome;
  new->numero=numero;
  if (*head==NULL){
    *head=new;}
  else{
    node *cur=*head;
    node *prev=NULL;
    while (cur!=NULL && strcmp(new->nome,cur->nome)>0 ){
      prev=cur;
      cur=cur->next;}
    if (prev==NULL){
      new->next=*head;
      *head=new;}
    else{
      prev->next=new;
      new->next=cur;}}
}

void hash_insert (node **tab,int n,char *nome,char *numero){
  int i,sum=0;
  for (i=0;i<strlen(nome);i++){
    sum= sum + (unsigned int)nome[i];}
  int hx = sum % (2*n);
  push_order(&tab[hx],nome,numero);
}

void printList (node *head){
  if (head!=NULL){
    printf("%s %s\n",head->nome,head->numero);
    printList(head->next);}
  else return;
}

int main(){
  int n,i,k;
  scanf("%d",&n);
  node **tab=malloc(2*n*sizeof(node));
  for (i=0;i<(2*n);i++){
    tab[i]=NULL;}
  for (i=0;i<n;i++){
    char *nome=malloc(MAXLEN*sizeof(char));
    char *numero=malloc(MAXNUM*sizeof(char));
    scanf("%s",nome);
    scanf("%s",numero);
    hash_insert(tab,n,nome,numero);}
  scanf("%d",&k);
  printList(tab[k]);
  return 0;
}
