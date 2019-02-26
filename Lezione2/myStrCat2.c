#include <stdio.h>
#include <stdlib.h>

char* myStrCat2 (int len1,char *str1,int len2,char *str2){
  char *strconc=malloc(sizeof(char)*(len1+len2));
  int i=0;
  int j=0;
  while (*(str1+i) != 0){
    *(strconc+i)=*(str1+i);
    i++;}
  while (*(str2+j) != 0){
    *(strconc+i)= *(str2+j);
    i++;
    j++;}
  return strconc;
}

int main(){
  int len1,len2;
  scanf("%d",&len1);
  char str1[len1];
  scanf("%s",str1);
  scanf("%d",&len2);
  char str2[len2];
  scanf("%s",str2);
  char *s1=str1;
  char *s2=str2;
  printf("%s\n",myStrCat2(len1,s1,len2,s2));
  return 0;
}
