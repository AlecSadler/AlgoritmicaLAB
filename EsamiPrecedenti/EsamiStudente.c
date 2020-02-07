#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLEN 101

struct esame{
	char* sigla;
	int cfu;
	int diff;};
typedef struct esame esame;

int examCompare(const void* a,const void* b){
	esame s1 = *(esame*)a;
	esame s2 = *(esame*)b;
	if (s1.cfu!=s2.cfu)
		return -(s1.cfu - s2.cfu);
	else if (s1.diff!=s2.diff)
		return s1.diff - s2.diff;
	else
		return strcmp(s1.sigla,s2.sigla);
}

int strCompare (const void* a,const void* b){
	char* st1 = *(char**)a;
	char* st2 = *(char**)b;
	return strcmp(st1,st2);
}

void main(){
	int i, k, n, cr, d, acc=0;
	scanf("%d%d",&k,&n);
	esame *arr= malloc(n*sizeof(esame));
	char **scelti= malloc(n*sizeof(char*));
	for (i=0;i<n;i++){
		char* sig= malloc(MAXLEN*sizeof(char));
		scanf("%s%d%d",sig,&cr,&d);
		arr[i].sigla=sig;
		arr[i].cfu=cr;
		arr[i].diff=d;
	}
	qsort(arr,n,sizeof(esame),examCompare);
	i=0;
	int countScelti=0;
	while (i<n){
		if ( (arr[i].cfu + acc) > k )
 			i++;
		else if ( (arr[i].cfu + acc) == k ){
			char* esameScelto= malloc(strlen(arr[i].sigla)*sizeof(char));
			esameScelto=arr[i].sigla;
			scelti[countScelti]=esameScelto;
			countScelti++;
			i=n;
		}
		else {
			acc= acc + arr[i].cfu;
			char* esameScelto= malloc(strlen(arr[i].sigla)*sizeof(char));
			esameScelto=arr[i].sigla;
			scelti[countScelti]=esameScelto;
			countScelti++;
			i++;
		}
	}
	qsort(scelti,countScelti,sizeof(char*),strCompare);
	for (i=0;i<countScelti;i++){
		printf("%s\n",scelti[i]);
	}
}
