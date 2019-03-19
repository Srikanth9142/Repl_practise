#include <stdio.h>
int a,b,u,v,n,i,j,ne=1,x;
int visited[10]={0},min,mincost,cost[10][10];
int main(){
  printf("\n Enter no.of nodes");
  scanf("%d",&n);
  printf("\n Enter adjacency matrix");
  for(i=1;i<=n;i++){
    for(j=1;j<=n;j++){
      scanf("%d",&cost[i][j]);
    }
  }
  printf("Enter starting vertex");
  scanf("%d",&x);
  visited[x]=1;
  while(ne<n){
    min=999;
    for(i=1;i<=n;i++){
      for(j=1;j<=n;j++){
        if(cost[i][j]&&((visited[i]&&!visited[j])||(!visited[i]&&visited[j]))){
          if(cost[i][j]<min){
            min=cost[i][j];
            a=i;
            b=j;
          }
        }
      }
    }
    printf("\n Edge %d:(%d %d) cost:%d",ne++,a,b,min);
  mincost+=min;
  visited[b]=visited[a]=1;
  }
  printf("\n Minimum cost=%d",mincost);
  return 0;
  
}
