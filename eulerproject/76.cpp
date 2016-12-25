#include <cstdio>
#include <vector>
#define limit 100
using namespace std;

int dp[limit+1][limit+1];

int main() {
  int i,j,k;
  for(i=1;i<=limit;i++) {
    for(j=0;j<=limit;j++) {
      if((j==0)||(i==1)||(j==1)) {
        dp[i][j]=1;
        continue;
      }
      if((j-i)<0) {
        dp[i][j]=dp[i-1][j];
      }
      else {
        dp[i][j]=dp[i-1][j]+dp[i][j-i];
      }
    }
  }
  // for(i=1;i<=10;i++) {
  //   for(j=1;j<=10;j++) {
  //     printf("%d\t",dp[i][j]);
  //   }
  //   printf("\n");
  // }
  // printf("\n");

  printf("%d\n",dp[limit][limit]);
  return 0;
}
