#include <cstdio>
#include <set>
#include <cmath>
#define sz 100000

using namespace std;

int prm[sz+1];
set<int> primeSet;

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

bool chkGoldbach(int i) {
  int sqr=1;
  int tmp;
  for(sqr=1;sqr<=10000;sqr++) {
    tmp = sqr;
    if(tmp*tmp >=i) return false;
    if(primeSet.find(i-tmp*tmp*2)!=primeSet.end()) {
      // printf("%d %d\n",i,sqr);
      return true;
    }
  }
  return false;
}

int main() {
  seive_fun();
  primeSet.insert(1);
  for(int i=0;i<=sz;i++) {
    if(prm[i]==0) primeSet.insert(i);
  }

  int i=1,tmp;
  while(1) {
    i+=2;
    if(primeSet.find(i)!=primeSet.end()) continue;
    if(!chkGoldbach(i)) printf("%d\n",i);
  }

  return 0;
}
