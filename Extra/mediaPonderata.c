#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLEN 50

struct exam{
  char* name;
  int grade;
  int cfu;
  int fact;
  struct exam *next;};
typedef struct exam exam;

struct aver{
  float pond;
  int arit;};
typedef struct aver aver;

void insert(exam **head,char *n,int g,int c){
  exam *new=malloc(sizeof(exam));
  new->name=n;
  new->grade=g;
  new->cfu=c;
  new->fact= g*c;
  if (*head==NULL){
    *head=new;
    (*head)->next=NULL;
    return;
  }
  new->next=*head;
  *head=new;
}

aver average(exam *head,int n){
  if (head==NULL){
    aver out;
    out.pond=0;
    out.arit=0;
    return out;
  }
  exam* cur=head;
  int sumCfu=0;
  int sumFact=0;
  int sumGr=0;
  while (cur!=NULL){
    sumCfu = sumCfu + cur->cfu;
    sumFact = sumFact + cur->fact;
    sumGr = sumGr + cur->grade;
    cur=cur->next;
  }
  aver out;
  out.pond= (float)sumFact/(float)sumCfu;
  out.arit= sumGr/n;
  return out;
}

void printExams(exam *head){
  if (head==NULL) return;
  printf("Materia: %s (%d) Voto: %d\n",head->name,head->cfu,head->grade);
  printExams(head->next);
}

void main(){
  int n, i, cfu, voto;
  exam *list=NULL;
  printf("Inserisci il numero degli esami suprati: ");
  scanf("%d",&n);
  for (i=0;i<n;i++){
    printf("Inserisci il nome dell'insegnamento: ");
    char *name=malloc(MAXLEN*sizeof(char));
    scanf("%s",name);
    printf("Inserisci il valore in CFU: ");
    scanf("%d",&cfu);
    printf("Inserisci il voto: ");
    scanf("%d",&voto);
    insert(&list,name,voto,cfu);
  }
  printExams(list);
  aver media= average(list,n);
  printf("Media Aritmetica: %d\nMedia Ponderata: %.2f\n",media.arit,media.pond);
}
