#include <cstdio>

using namespace std;

int main() {
  int i,j,k;
  long md=1000000000;
  int dp[1010][1010]={0};
  for(i=1;i<=1000;i++) {
    for(j=0;j<=i;j++) {
      if(i==1) dp[i][j]=1;
      else if(j==0) dp[i][j]=1;
      else dp[i][j]=((dp[i-1][j-1]%md)+(dp[i-1][j]%md))%md;
    }
  }

  for(i=990;i<=1000;i++) {
    for(j=0;j<10;j++) {
      printf("%d ",dp[i][j]);
    }
    printf("\n");
  }


  int T,N;
  scanf("%d",&T);
  while(T--) {
    scanf("%d",&N);
    for(i=0;i<=N;i++) printf("%d ",dp[N][i]);
    printf("\n");
  }
  return 0;
}
