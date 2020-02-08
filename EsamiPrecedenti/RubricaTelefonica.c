#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXNOME 101
#define MAXNUM 21

struct contatto{
	char* nome;
	char* numero;};
typedef struct contatto contatto;

struct node{
	contatto record;
	struct node* next;};
typedef struct node node;

int fHash (char* str, int n){
	int i, sum=0;
	for (i=0;i<strlen(str);i++){
		sum= (unsigned int)str[i] + sum;
	}
	return sum % (2*n);
}

void insert (node **tab, int n, char* name, char* num){
	contatto new;
	new.nome=name;
	new.numero=num;
	node *newNode= malloc(sizeof(node));
	newNode->record= new;
	int pos = fHash(name,n);
	node *cur= tab[pos];
	node *prev= NULL;
	if (tab[pos]==NULL){
		tab[pos]=newNode;
		tab[pos]->next=NULL;
		return;
	}
	while (cur!=NULL && strcmp(cur->record.nome,name)<0){
		prev= cur;
		cur= cur->next;
	}
	if (prev==NULL){
		newNode->next= tab[pos];
		tab[pos]=newNode;
		return;
	}
	prev->next=newNode;
	newNode->next=cur;
}

void printList(node *head){
	if (head==NULL) return;
	printf("%s %s\n",head->record.nome,head->record.numero);
	printList(head->next);
}

void main(){
	int n, i, k;
	scanf("%d",&n);
	node **tab= malloc(2*n*sizeof(node));
	for (i=0;i<(2*n);i++){
		tab[i]=NULL;
	}
	for (i=0;i<n;i++){
		char* nom= malloc(MAXNOME*sizeof(char));
		char* num= malloc(MAXNUM*sizeof(char));
		scanf("%s",nom);
		scanf("%s",num);
		insert(tab,n,nom,num);
	}
	scanf("%d",&k);
	printList(tab[k]);
}
