#include<cstdio>
#include<iostream>
#include<vector>
#include<stack>
#include<map>
#include<set>
#include<cstring>
#include<cmath>
#include<string>
#include<cstdlib>
#include<queue>
#include<algorithm>
#include<cassert>
#define fr(i,m,n) for(i=m;i<n;i++)
#define ll long long
#define sc scanf
#define pf printf
#define var(x) x i=0,j=0,k=0,tmp1,tmp2,tmp3,tmp=0
using namespace std;

vector<ll> phiArr;
vector<ll> phiArrSum;

int phi(int n) {
  if(n==1) return 2;
  int result = n;
  for(int i = 2; i * i <= n; ++i) {
      if(n % i == 0) {
          while(n % i == 0) n /= i;
          result -= result / i;
      }
  }
  if(n > 1) {
    result -= result / n;
  }
  return result;
}

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

pair<int,int> calc(ll k) {
  if(k==1) return make_pair(0,1);
  vector<ll>::iterator it;
  int i;
  it = lower_bound(phiArrSum.begin(), phiArrSum.end(),k);
  int lIndex = it-phiArrSum.begin();
  // pf("lIndex=%d\n",lIndex);
  ll cnt = phiArrSum[lIndex-1];
  // pf("cnt=%lld\n",cnt);
  fr(i,1,lIndex) {
    if(gcd(lIndex,i)==1) {
      // pf("co-prime=%d\n",i);
      cnt++;
    }
    if(cnt==k) break;
  }
  return make_pair(i,lIndex);
}

int main() {
  long long k;
  pair<int,int> ans;
  // scanf("%d",&n);

  // initialize
  phiArr.push_back(0);
  phiArrSum.push_back(0);

  for(int i=1;i<1000001;i++) {
    phiArr.push_back(phi(i));
    phiArrSum.push_back(phiArrSum[i-1]+phiArr[i]);
  }

  // while(1) {
  //   scanf("%lld",&k);
  //   printf("%lld %lld\n",phiArr[k], phiArrSum[k]);
  // }

  scanf("%lld",&k);
  while(k!=0) {
    ans = calc(k);
    printf("%d/%d\n",ans.first, ans.second);
    scanf("%lld",&k);
  }
  return 0;
}
