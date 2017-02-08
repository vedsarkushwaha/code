#include <cstdio>
#define ll long long
using namespace std;

ll md=1000000007;

ll power(ll n,ll m) {
  if(m==0) return 1;
  ll tmp = (n*n)%md;
  if(m%2) return power(tmp,m/2) * n;
  else return power(tmp,m/2);
}

int main() {
  ll N,M,T;
  scanf("%lld",&T);
  while(T--) {
    scanf("%lld %lld",&N,&M);
    if(N==1) printf("%lld\n",M);
    else printf("%lld\n",(power(M,N)+md-M)%md);
  }
  return 0;
}
