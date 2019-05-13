#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRLEN 101

struct node{
  char* str;
  int freq;};

typedef struct node node;

// confronta due stringhe in ordine lessicografico
int str_compare (const void *a,const void *b){
  char* st1=*(char**)a;
  char* st2=*(char**)b;
  return strcmp(st1,st2);
}

// confronta due interi e li mette in ordine decrescente
int struct_compare_freq(const void *a,const void *b){
  node stfa=*(node*)a;
  node stfb=*(node*)b;
  return -(stfa.freq-stfb.freq);
}

// confronta due stringhe in ordine lessicografico
int struct_compare_str(const void *a,const void *b){
  node stsa=*(node*)a;
  node stsb=*(node*)b;
  return strcmp(stsa.str,stsb.str);
}

int main(void){
  int n,k,i,j;
  scanf("%d%d",&n,&k);
  char** words=malloc(n*sizeof(char*));
  node *w_freq= malloc(n*sizeof(node));
  for (i=0;i<n;i++){
    words[i]=malloc(MAX_STRLEN*sizeof(char));
    scanf("%s",words[i]);}
  qsort(words,n,sizeof(char*),str_compare);
  j=-1;                                       // -1 perchè la prima deve essere sempre inserita
  for(i=0;i<n;i++){
    if(j>=0 && !strcmp(words[i],w_freq[j].str)){
      w_freq[j].freq++;}
    else{
      j++;
      w_freq[j].str=words[i];
      w_freq[j].freq=1;}}
  qsort(w_freq,j+1,sizeof(node),struct_compare_freq);  // j+1 perche sono partito da -1
  qsort(w_freq,k,sizeof(node),struct_compare_str);
  for (i=0;i<k;i++){
    printf("%s\n",w_freq[i].str);}
  return 0;
}
