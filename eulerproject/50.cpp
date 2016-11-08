#include <cstdio>
#include <set>
#include <cmath>
#include <vector>
#define sz 100000010
#define ll long long
using namespace std;

ll prm[sz+1];
set<ll> primeSet;
ll arr[sz+1];

void seive_fun() {
	ll i,j,k,limit;
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

int main() {
  seive_fun();
  ll i,j,k;
  ll tmp1=0,tmp2,tmp3,tmp4=0,tmp5,tmp6,tmp;
  ll cnt,gCnt,lp,hp;
  vector<ll> forPrime;
  for(i=0;i<=100000000;i++) {
    if(prm[i]==0) {
      primeSet.insert(i);
      forPrime.push_back(i);
      if(i>=31 && i<=954491) tmp4+=i;
    }
  }
  // printf("%d\n",tmp4);
  // printf("%d\n",primeSet.size());
  ll gTmp;
  for(i=0;i<forPrime.size();i++) {
    tmp=0;
    for(j=i;j>=0;j--) {
      tmp+=forPrime[j];
      if(tmp>1000000) break;
      if(primeSet.find(tmp)!=primeSet.end()) {
        if(i-j+1>gCnt) {
          gCnt = i-j+1;
          gTmp = tmp;
          lp = forPrime[j];
          hp = forPrime[i];
        }
      }
    }
    if(i%10000==0) printf("%lld\n",i);
  }

  printf("%lld %lld %lld %lld\n",gCnt,gTmp,lp,hp);
  return 0;
}
