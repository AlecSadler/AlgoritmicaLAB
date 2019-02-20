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

int member (char *s, char ch){
  int i=0;
  int found=0;
  while (*(s+i) != 0 && i<MAX_STRLEN && !found){
    if (*(s+i)==ch)
      found=1;
    else i++;}
  return found;
}

int anagramma (unsigned char *s1,unsigned char *s2){
  int ok=1;
  int i=0;
  if (strLen(s1)==strLen(s2)){      //se la lunghezza delle stringhe è diversa torna subito FALSE
    while (*(s1+i) != 0 && i<MAX_STRLEN && ok){
      if (member(s2,*(s1+i)))
        i++;
      else
        ok=0;}}
  else
    return 0;
  return ok;
}

int main(){
  char string1[MAX_STRLEN];
  char string2[MAX_STRLEN];
  unsigned char *s1=string1;
  unsigned char *s2=string2;
  scanf("%s",string1);
  scanf("%s",string2);
  printf("%d\n",anagramma(s1,s2));
  return 0;
}
