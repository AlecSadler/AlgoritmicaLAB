#include <stdio.h>
#define ARR_LEN 10

void resetArray (int a[]){
  int i;
  for (i=0;i<ARR_LEN;i++){
    a[i]=0;}
}

void add (int a[],int len,int val){
  if (a>=0 && val<len){
    a[val]++;}
}

int main(){
  int arr[ARR_LEN];
  int n;
  int end=0;
  int i;
  resetArray(arr);
  while (end==0){
    scanf("%d",&n);
    if (n!=-1){
      add(arr,ARR_LEN,n);}
    else
      end=1;}
  for (i=0;i<ARR_LEN;i++){
    printf("%d\n",arr[i]);}
}
