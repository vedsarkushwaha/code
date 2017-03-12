#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cassert>
#include <set>
#include <numeric>

#define ll long long

using namespace std;

ll sz;
int prm[10000001];

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

ll getVal(ll maxVal, ll p, ll q) {
  ll i,flag=1,tmp=maxVal;

  while(true) {
		tmp=maxVal;
		while(tmp%p==0) {
			tmp=tmp/p;
		}
		while(tmp%q==0) {
			tmp=tmp/q;
		}
		if(tmp==1) return maxVal;
    maxVal-=(p*q);
  }
}

int main() {
	sz=10000000;
  seive_fun();
	set<ll> st;
  ll i,j,tmp;
  ll sm=0;
  for(i=2;i<=sz;i++) {
    for(j=i+1;j<=sz;j++) {
      if((i*j)>sz) break;
      if(prm[i]==0 && prm[j]==0) {
        tmp=(sz/(i*j))*(i*j);
				tmp = getVal(tmp,i,j);
				// printf("%lld %lld %lld\n",i,j,tmp);
				sm+=tmp;
				if(!((st.insert(tmp)).second)) {
					assert(1==0);
				}
      }
    }
  }
  printf("%lld\n",sm);
  return 0;
}
