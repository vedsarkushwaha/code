#include <cstdio>
#include <cmath>
#define ll long long
using namespace std;

bool penNum(ll n) {
  ll i=(sqrt(24*n+1)+1)/6;
  ll ans = (i*(3*i-1))/2;
  // printf("%lld %lld %lld\n", i,ans,n);
  return ans==n;
}

int main() {
  int i,j;
  ll pi,pj;
  for(i=2;i<=10000;i++) {
    pi = (i*(3*i-1))/2;
    for(j=1;j<i;j++) {
      pj = (j*(3*j-1))/2;
      if(penNum(pi-pj) && penNum(pi+pj)) {
        printf("%lld %lld %lld %d %d\n",pi-pj,pi,pj,i,j);
      }
    }
  }
  return 0;
}
