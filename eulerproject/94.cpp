#include <cstdio>
#include <cmath>
#include <cassert>
#include <set>

#define ll long long
// #define L 100
#define L 1000000000

using namespace std;

set<ll> sqr;

void init() {
  ll i;
  for(i=1;i<L;i++) {
    sqr.insert(i*i);
    if((i%(L/100))==0) printf("%lld\n",i);
  }
}

bool chkSqr(ll num) {
  ll tmp = sqrt(num);
  return (tmp*tmp==num || (tmp-1)*(tmp-1)==num || (tmp+1)*(tmp+1)==num);
}

bool chkArea(ll i,ll j,ll k) {
  // if area is integer return true else false
  assert(i==j);
  if(k%2) return false;
  ll tmp = i*i - (k/2)*(k/2);
  return chkSqr(tmp);
}

bool chkPerimeter(ll i,ll j, ll k) {
  // if perimeter is <= L, return true else false
  ll tmp = i+j+k;
  return tmp<=L;
}

int main() {
  ll i,j,k;
  ll ans=0;
  // init();
  for(i=2;i<=L/2;i++) {
    if(chkArea(i,i,i-1) && chkPerimeter(i,i,i-1)) {
      ans+=(i+i+i-1);
      printf("%lld %lld %lld\n",i,i,i-1);
    }
    if(chkArea(i,i,i+1) && chkPerimeter(i,i,i+1)) {
      ans+=(i+i+i+1);
      printf("%lld %lld %lld\n",i,i,i+1);
    }
  }
  printf("%lld\n",ans);
}
