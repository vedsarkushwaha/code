#include <cstdio>

#define ll long long
#define L 10000000

using namespace std;

int dp[L+1];

bool chk(ll num) {
  if(num==1) return false;
  if(num==89) return true;
  ll tmp=0;
  while(num!=0) {
    tmp+=(num%10)*(num%10);
    num/=10;
  }
  return chk(tmp);
}

int main() {
  ll i,j,k;
  int cnt=0;
  dp[89]=1;
  for(i=1;i<=L;i++) {
    if(chk(i)) {
      dp[i]=1;
      cnt++;
      // printf("%lld ",i);
    }
  }

  printf("%d\n",cnt);
  return 0;
}
