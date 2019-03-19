#include <stdio.h>
int tsize;
int hasht(int key){
  int i = key%tsize;
  return i;
}
int rehas(int key){
  int i = (key+1)%tsize;
  return i;
}
int main() {
  int key,arr[3],hash[20],i,n,j,k;
  printf("Enter size of hash table: ");
  scanf("%d",&tsize);
  printf("Enter no.of elements :");
  scanf("%d",&n);
  for(int i=0;i<tsize;i++){
    hash[i]=-1;
  }
  printf("Enter your Elements :");
  for(j=0;j<n;j++)
  {
    scanf("%d",&arr[j]);
  }
  for(k=0;k<n;k++)
  {
    key = arr[k];
    i=hasht(key);
    while(hash[i]!=-1)
    {
      i=rehas(i);
    }
    hash[i]=key;
  }
  printf("The Elements in the array are : ");
  for(i=0;i<tsize;i++){
    printf("Element at position %d:%d",i,hash[i]);
  }
  return 0;

}
