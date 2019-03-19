#include<stdio.h>
#include<stdlib.h>
int find(int);
int uni(int,int);
int parent[10];
int main() {
  int a,b,n,i,j,ne=1,u,v;
  int min,mincost=0,cost[10][10];
  int  parent[10];
  printf("\nEnter no.of vertices: ");
  scanf("%d",&n);
  printf("\nEnter adjacency matrix\n");
  for(i=1;i<=n;i++){
    for(j=1;j<=n;j++){
      scanf("%d",&cost[i][j]);
      if(cost[i][j]==0)
        cost[i][j]=999;
    }
  }
  printf("\n The edges of MST are:\n");
  while(ne<n){
    min=999;
    for(i=1;i<=n;i++){
      for(j=1;j<=n;j++){
        if(cost[i][j]<min){
          min=cost[i][j];
          a=u=i;
          b=v=j;
        }
      }
    }
    u=find(u);
    v=find(v);
    if(uni(u,v)){
      printf("\n%d edge (%d %d) = %d\n",ne++,a,b,min);
      mincost+=min;
    }
    cost[a][b]=cost[b][a]=999;
  }
  printf("\n Minimun cost = %d\n",mincost);
  return 0;

}
int find(int i){
  while(parent[i]){
    i = parent[i];
  }
  return i;
}
int uni(int i,int j){
  if(i!=j){
    parent[j]=i;
    return 1;
  }
  return 0;
}
