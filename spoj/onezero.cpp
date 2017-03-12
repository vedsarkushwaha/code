#include <cstdio>
#define sc scanf
#define pf printf
#define ll long long
using namespace std;

bool chk(ll n) {
  while(n!=0) {
    if(n%10>1) return false;
    n=n/10;
  }
  return true;
}

int main() {
  int T;
  ll n,i;
  sc("%d",&T);
  while(T--) {
    i=1;
    sc("%lld",&n);
    while(!chk(n*i)) {
      i++;
    }
    pf("%lld\n",n*i);
  }
  return 0;
}
