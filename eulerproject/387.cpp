#include <cstdio>
#include <vector>
#include <utility>
#include <vector>
#include <cmath>

#define ll long long
#define range 100000000000000
#define sz 100000000

using namespace std;

vector<pair<ll,ll> > vec;

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

bool chkPrime(ll num) {
	ll itr,tmp;
	tmp=sqrt(num)+1;
	if(num<sz) return !prm[num];
	else {
		if((num%6)!=1 && (num%6)!=5) {
			return false;
		}
		if((num%2)==0 || (num%3)==0 || (num%5)==0) return false;
		for(itr=2;itr<=tmp;itr++) {
			if(!prm[itr]) {
				if((num%itr)==0) return false;
			}
		}
		return true;
	}
}

int main() {
  ll i,sm=0,j;
  ll tmpNum,numDigSum;
  vector<pair<ll,ll> >::iterator it;
  seive_fun();
  for(i=1;i<=9;i++) {
    vec.push_back(make_pair(i,i));
  }
  j=0;
  bool flag=0;
  while(!flag) {
    for(i=0;i<10;i++) {
      tmpNum = vec[j].first*10 + i;
      numDigSum = vec[j].second + i;
      if(tmpNum>range) {
        flag=1;
        break;
      }
      // printf("%lld %lld\n",tmpNum,numDigSum);
			// if((tmpNum%1000000000)==0) printf("%lld\n",tmpNum);
      if(chkPrime(tmpNum) && chkPrime((tmpNum/10)/(numDigSum-i))) {
        // printf("%lld\n",tmpNum);
        sm+=tmpNum;
      }
      if((tmpNum % numDigSum) == 0) {
        // printf("%lld %lld\n",tmpNum,numDigSum);
        vec.push_back(make_pair(tmpNum,numDigSum));
      }
    }
    j++;
  }
  printf("%lld\n",sm);
  return 0;
}
