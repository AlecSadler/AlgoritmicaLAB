#include <stdio.h>
#include <stdlib.h>

struct node {
  int key;
  int freq;
  struct node* next;
};
typedef struct node node;

struct table {
    node** table; /* Tabella Hash (array di liste) */
    int m; /* Dimensione della tabella */
};
typedef struct table table;

int hashF(int x,int n){
  return x%(2*n);
}

table* newTable(int m) {
    int i;
    table* T = malloc(sizeof(table));
    T->table = malloc(m * sizeof(node*));
    T->m = m;
    for(i=0;i<m;i++) {
        T->table[i] = NULL;
    }
    return T;
}

void hash_destroy(table* T) {
    int i;
    int m = T->m;
    for(i=0;i<m;i++) {
        node* lista = T->table[i];
        while(lista != NULL) {
            node* tmp = lista;
            lista = lista->next;
            free(tmp);
        }
    }
    free(T->table);
    free(T);
}

void insert(table* T, int k, int fr) {
    /* Calcolo dell'hash */
    int posizione = hashF(k,T->m);
    node* new = malloc(sizeof(node));
    new->key = k;
    new->freq = fr;
    new->next = T->table[posizione]; // NULL se la lista era vuota
    T->table[posizione] = new; // Inserimento in testa
}

int search(table* T, int k, int* result) {
    node* lista = T->table[hashF(k, T->m)];
    while(lista != NULL && lista->key != k)
        lista = lista->next;
    if(lista == NULL) { // Non trovato
        result = NULL;
        return 0;
    }
    else {
        *result = lista->freq;
        return 1; // Esito positivo
    }
}

void delete(table* T, int k) {
    int pos = hashF(k, T->m);
    node* current = T->table[pos];
    node* previous = NULL;
    while(current != NULL && current->key != k) {
        previous = current;
        current = current->next;
    }
    /* Current punterà al blocco della lista che contiene la chiave k, se c'è */

    if(current != NULL) { // Se k è effettivamente presente nella tabella
        if(previous == NULL) { // Cancellazione in testa alla lista
            /* Avanziamo il puntatore alla testa della lista
             * e deallochiamo la "vecchia" testa (puntata da current)
             */
            T->table[pos] = current->next;
            free(current);
        }
        else { // Cancellazione in mezzo alla lista
            previous->next = current->next; // "Salta" il blocco da cancellare
            free(current);
        }
    }
}


void main(){
    int el, n, k, i;
    scanf("%d%d\n",&n,&k);
    int *arr= malloc(n*sizeof(int));
    table *tab=newTable(2*n);
    for (i=0;i<n;i++){
      int tmp;
      scanf("%d",&el);
      arr[i]=el;
      if ( !search(tab,el,&tmp) )
        insert(tab,el,1);
      else{
        delete(tab,el);
        insert(tab,el,tmp+1);
      }
    }
    for (i=0;i<n;i++){
      int tmp;
      search(tab,arr[i],&tmp);
      if (tmp>=k) printf("%d ",arr[i]);
    }
}
