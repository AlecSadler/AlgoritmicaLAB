#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct ris {
	int sx;
	int dx;
}ris;

typedef struct lista {
	int info;
	struct lista *next;
} lista;



typedef struct nodo {
	int info;
	int ok;
	struct nodo *right;
	struct nodo *left;
} nodo ;

void stampalista(lista *list){
	if(list!=NULL){
		printf("%d\n",list->info);
		stampalista(list->next);
	}
}

void visita_simm(nodo *radice){
	if(radice!=NULL){
		visita_simm(radice->left);
		if(radice->ok ==1) printf("%d\n",radice->info);
		visita_simm(radice->right);
	}
}


nodo *inserisci (nodo **radice, int valore ) {
	nodo *new=malloc(sizeof(nodo));
	new->info = valore;
	new->ok=0;
	new->left=NULL;
	new->right=NULL;
	if(*radice==NULL) return new;
	if(valore <= (*radice)->info) (*radice)->left=inserisci (&((*radice)->left),valore);
	else (*radice)->right=inserisci(&((*radice)->right),valore);
	return *radice;
}

ris * stampanodi ( nodo *albero ) {
	if(albero==NULL) {
		ris *risultato=malloc(sizeof(ris));
		risultato->sx=0;
		risultato->dx=0;
		return risultato;
	}
	else {
		ris *left=stampanodi(albero->left);
		ris *right=stampanodi(albero->right);
		ris *risultato=malloc(sizeof(ris));
		if(left->sx > right->dx) {
			albero->ok=1;
		}
		risultato->sx=left->sx+1;
		risultato->dx=right->dx+1;
		return risultato;
	}
}


int main() {
	nodo *albero=NULL;
	int numel;
	scanf("%d",&numel);
	for(int i=0;i<numel;i++) {
		int valore;
		scanf("%d",&valore);
		albero=inserisci(&albero,valore);
	}
	stampanodi(albero);
	visita_simm(albero);
	return 0;
}

