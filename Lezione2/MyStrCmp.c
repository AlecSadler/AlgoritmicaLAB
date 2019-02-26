#include <stdio.h>
#define MAX_STRLEN 1000

int mystrlen (char *s){
  if (*s != 0)
    return 1 + mystrlen (s+1);
  else
    return 0;
}

int my_strcmp(char *s1, char*s2){
    if(mystrlen(s1)==mystrlen(s2)){
        int n=0;
        int stop=0;
        while(n<=mystrlen(s1) && !stop){
            if(*(s1+n)>*(s2+n)){
                stop=1;
                return 1;}
            else{
                if(*(s1+n)<*(s2+n)){
                    stop=1;
                    return (-1);}}
            n++;}
        if(!stop)
            return 0;}
    else{
        if(mystrlen(s1)>mystrlen(s2)){
            return 1;}
        else
            return -1;}
}

int main(){
  char string1[MAX_STRLEN];
  char string2[MAX_STRLEN];
  char *s1=string1;
  char *s2=string2;
  scanf("%s",string1);
  scanf("%s",string2);
  if (my_strcmp(s1,s2)==1)
    printf("+1");
  else if (my_strcmp(s1,s2)==-1)
    printf("-1");
  else
    printf("0");
}
