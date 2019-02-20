#include <stdio.h>
#include <stdlib.h>
#define MAX_STRLEN 256

// calcola la lunghezza di una stringa

int strLen (char *s){
  int len=0;
  while (*(s+len) != 0 && len < MAX_STRLEN){
    len++;}
  return len;
}

char *myStrCat1 (char *s1, char *s2){
  int i=strLen(s1);
  int j=0;
  while (*(s2+j)!=0 && i+j<MAX_STRLEN){
    *(s1+i)= *(s2+j);
    j++;
    i++;}
  return s1;
}

int main(){
  char string1[MAX_STRLEN];
  char string2[MAX_STRLEN];
  char *s1=string1;
  char *s2=string2;
  scanf("%s",string1);
  scanf("%s",string2);
  printf("%s\n",myStrCat(string1,string2));
  return 0;
}
