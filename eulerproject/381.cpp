#include <cstdio>
#include <cmath>
#include <algorithm>

#define ll long long
#define sz 100000000
using namespace std;

int prm[sz+1];

void seive_fun() {
	int i,j,k,limit;
	prm[0]=1;
	prm[1]=1;
	limit=sqrt(sz);
	for(i=2;i<=limit;i++) {
		if(prm[i]==0) {
			k=sz/i;
			for(j=2;j<=k;j++)
				prm[i*j]=1;
		}
	}
}

ll powMod(ll a, ll b, ll m) {
  if(b==0) return 1;
  ll tmp = powMod(a,b/2,m);
  if(b%2==0) {
    return (tmp*tmp)%m;
  }
  else {
    return (((tmp*tmp)%m)*a)%m;
  }
}

ll S(ll i) {
  ll tmp = powMod(i-2,i-2,i);
  ll tmp1 = (powMod(i-3,i-2,i)*tmp)%i;
  ll tmp2 = (powMod(i-4,i-2,i)*tmp1)%i;
  return (tmp+tmp1+tmp2)%i;
}

int main() {
  ll i,tmp=0;
  seive_fun();
  for(i=5;i<100000000;i++) {
    if(prm[i]==0) tmp+=S(i);
  }
  printf("%lld",tmp);
}
