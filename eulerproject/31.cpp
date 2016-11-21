#include <cstdio>
#include <set>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n,i,j;
  scanf("%d",&n);

  vector<int> coints;

  long long dp[n+1];
  dp[0]=1;
  for(i=1;i<=n;i++) dp[i]=0;

  coints.push_back(1);
  coints.push_back(2);
  coints.push_back(5);
  coints.push_back(10);
  coints.push_back(20);
  coints.push_back(50);
  coints.push_back(100);
  coints.push_back(200);

  // 1
  for(i=0;i<coints.size();i++) {
    printf("coin = %d\n", coints[i]);
    for(j=1;j<=n;j++) {
      if(j-coints[i]>=0) {
        dp[j]+=dp[j-coints[i]];
        printf("j=%d dp[j]=%lld\n",j,dp[j]);
      }
    }
    printf("\n");
  }

  printf("%lld\n",dp[n]);

  return 0;
}
